# Obtaining Device Location Information (ArkTS)

## When to Use

You can call location APIs in OpenHarmony to obtain the real-time location or last known location and keep track of location changes of a device.

Real-time location of the device is recommended for location-sensitive services. If you want to lower power consumption when the real-time location of the device is not needed, you may consider obtaining the last known location of the device.

## Available APIs

The following table lists the APIs used to obtain the device location information. For details, see (../../reference/apis-location-kit/js-apis-geoLocationManager.md).

This module supports only the WGS-84 coordinate system.

| API| Description| 
| -------- | -------- |
| [on(type: 'locationChange', request: LocationRequest &#124; ContinuousLocationRequest, callback: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageronlocationchange) | Registers a listener for location changes with a location request initiated.| 
| [off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerofflocationchange) | Unregisters the listener for location changes with the corresponding location request deleted.| 
| [getCurrentLocation(request: CurrentLocationRequest &#124; SingleLocationRequest, callback: AsyncCallback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation) | Obtains the current location. This API uses an asynchronous callback to return the result. | 
| [getCurrentLocation(request?: CurrentLocationRequest &#124; SingleLocationRequest): Promise&lt;Location&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation-2) | Obtains the current location. This API uses a promise to return the result. | 
| [getLastLocation(): Location](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetlastlocation) | Obtains the last known device location.| 
| [isLocationEnabled(): boolean](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerislocationenabled) | Checks whether the location switch is enabled.| 

## How to Develop

1. Before using system basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application first needs to apply for the required permission. For details, see [Applying for Location Permissions](location-permission-guidelines.md).

2. Import the **geoLocationManager** module by which you can implement all APIs related to the basic location capabilities.
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   ```
3. Call **isLocationEnabled** to check whether the location switch is enabled. 
   The return result is a Boolean value. The value **true** indicates that the location switch is enabled, and the value **false** indicates the opposite.

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   try {
       let locationEnabled = geoLocationManager.isLocationEnabled();
   } catch (err) {
       console.error("errCode:" + err.code + ", message:"  + err.message);
   }
   ```
   If the location switch is not enabled, launch a dialog box asking the user to enable the switch. For details, see [Setting the Global Switch](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestglobalswitch12).

4. Obtain the current location of the device. It is mainly used in scenarios such as viewing of the current location, signing in/out, and service recommendation.
   - Method 1: Obtain the latest location in the system cache.<br>
      If the system does not have a cached location, an error code is returned.<br>
      Using this API to obtain the device location can reduce the system power consumption.<br>
      If a fresh location is expected, your application can first obtain the cached location and then compare the timestamp in it with the current time. If the location is not fresh, try method 2.<br>

      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      import { BusinessError } from '@kit.BasicServicesKit'
      try {
          let location = geoLocationManager.getLastLocation();
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

   - Method 2: Obtain the current location.<br>
      Instantiate a [SingleLocationRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#singlelocationrequest12) object to notify the system of the type of location service to be provided for applications and the timeout interval for a single location.<br>
      - Set the location priority by using **LocatingPriority**.<br>
         If a precise location is required, set **LocatingPriority** to **PRIORITY_ACCURACY**. The most accurate location result within the specified period of time will be provided for the application.<br>
         If fast location is expected, you are advised to set **LocatingPriority** to **PRIORITY_LOCATING_SPEED**. The first obtained location result will be provided for the application.<br>
         Both the GNSS positioning and the network positioning technologies are used in the two location policies. This can lead to significant hardware resource consumption and power consumption.<br>
      - Set the location timeout interval by using **locatingTimeoutMs**.<br>
         Due to the impact of the ambient environment, device status, and system power consumption control policy, the location response delay may fluctuate greatly. You are advised to set the timeout interval for a single location to 10 seconds.<br>
         
      The following code snippet uses **PRIORITY_LOCATING_SPEED** as an example.<br>

      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      import { BusinessError } from '@kit.BasicServicesKit'
      let request: geoLocationManager.SingleLocationRequest = {
         'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_LOCATING_SPEED,
         'locatingTimeoutMs': 10000
      }
      try {
         geoLocationManager.getCurrentLocation(request).then((result) => { // Call getCurrentLocation to obtain the current device location by using a promise.
            console.info('current location: ' + JSON.stringify(result));
         })
         .catch((error:BusinessError) => { // Receive the reported error code.
            console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
         });
       } catch (err) {
         console.error("errCode:" + JSON.stringify(err));
       }
      ```
   The coordinates obtained by this module are in the WGS-84 coordinate system. If you need to use coordinates in other coordinate systems, perform a coordinate system conversion.

   <!--RP1-->   You can use the SDK capabilities provided by a third-party map to implement coordinate system conversion.<!--RP1End-->
   
5. Obtain the device location continuously. It is mainly used in scenarios such as navigation, movement track, and travel.<br>
   Instantiate a [ContinuousLocationRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#continuouslocationrequest12) object to notify the system of the type of location service to be provided for applications and the interval for reporting location information.<br>
   - Set the location scenario by using **locationScenario**.<br>
      You are advised to set **locationScenario** based on the application scenario. For details about the enum values of this parameter, see [UserActivityScenario](../../reference/apis-location-kit/js-apis-geoLocationManager.md#useractivityscenario12). For example, if **locationScenario** is set to **NAVIGATION**, the application will obtain the device location in both the indoor and outdoor scenarios for navigation.<br>
   - Set the interval for reporting location information by using **interval**.<br>
      The interval for reporting location information is in unit of seconds. The default value is **1**. Leave this parameter unspecified if there is no special requirement for the location reporting interval.
   
   The following code snippet uses the map navigation scenario as an example.

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   let request: geoLocationManager.ContinuousLocationRequest= {
      'interval': 1,
      'locationScenario': geoLocationManager.UserActivityScenario.NAVIGATION
   }
   let locationCallback = (location:geoLocationManager.Location):void => {
      console.info('locationCallback: data: ' + JSON.stringify(location));
   };
   try {
      geoLocationManager.on('locationChange', request, locationCallback);
   } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
   }
   ```
   If your application no longer needs the device location, stop obtaining the device location to avoid high power consumption.
   ```ts
   // The callback must be the same as that passed by the **on** API.
   geoLocationManager.off('locationChange', locationCallback);
   ```
