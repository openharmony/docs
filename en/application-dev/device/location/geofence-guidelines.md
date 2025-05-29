# Geofencing (ArkTS)

## Scenario

A geofence is a group of virtual bounds defining an area on the map. When a user device enters or leaves a geofence, or stays in a geofence, your app on the user device can automatically receive notifications and alarms.

Currently, only circular fences are supported. In addition, the geo-fencing function of the GNSS chip is required. Events of entering or leaving the fence can be accurately identified only in open outdoor areas.

A typical application of geofencing is to create a geofence around an enterprise for targeted advertising. In different areas, you can provide differentiated promotions for mobile devices.

## Available APIs

The following table lists the APIs used in geofencing. For details, see [Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md).

| API| Description| 
| -------- | -------- |
| [addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise&lt;number&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageraddgnssgeofence12) | Adds a GNSS geofence and subscribes to geofence transition events. This API uses a promise to return the result.| 
| [removeGnssGeofence(geofenceId: number): Promise&lt;void&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerremovegnssgeofence12) | Removes a GNSS geofence and unsubscribes from geofence transition events. This API uses a promise to return the result.| 

## How to Develop

1. Declare the **ohos.permission.APPROXIMATELY_LOCATION** permission. For details, see [Applying for Location Permissions](#location-permission-guidelines.md).

2. Import the **geoLocationManager**, **wantAgent**, and **BusinessError** modules.

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { notificationManager } from '@kit.NotificationKit';
   ```

3. Create a geofence.

   ```ts
   // Set the action type through operationType of WantAgentInfo.
   let geofence: geoLocationManager.Geofence = {
       "latitude": 34.12, "longitude": 124.11, "radius": 10000.0, "expiration": 10000.0
   }
   ```

4. Specify the types of geofence transition events to listen for. Geofence entry and exit events are used as an example.

   ```ts
   let transitionStatusList: Array<geoLocationManager.GeofenceTransitionEvent> = [
       geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_ENTER,
       geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_EXIT,
   ];
   ```

4. Create a notification object for **GEOFENCE_TRANSITION_EVENT_ENTER** and **GEOFENCE_TRANSITION_EVENT_EXIT**.

   ```ts
   // GEOFENCE_TRANSITION_EVENT_ENTER event
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
   ```

5. Add a geofence.

   ```ts
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
     // Specify the callback used to receive geofence transition events.
     geofenceTransitionCallback: (err : BusinessError, transition : geoLocationManager.GeofenceTransition) => {
       if (err) {
         console.error('geofenceTransitionCallback: err=' + JSON.stringify(err));
       }
       if (transition) {
         console.info("GeofenceTransition: %{public}s", JSON.stringify(transition));
     }
     }
   }
   try {
     // Add a geofence.
     geoLocationManager.addGnssGeofence(gnssGeofenceRequest).then((id) => {
       // Obtain the geofence ID after the geofence is successfully added.
       console.info("addGnssGeofence success, fence id: " + id);
       let fenceId = id;
     }).catch((err: BusinessError) => {
       console.error("addGnssGeofence failed, promise errCode:" + (err as BusinessError).code + 
         ",errMessage:" + (err as BusinessError).message);
     });
   } catch(error) {
       console.error("addGnssGeofence failed, err:" + JSON.stringify(error));
   }
   ```

6. Delete a geofence.

   ```ts
   // fenceId is obtained after geoLocationManager.addGnssGeofence is successfully executed.
   let fenceId = 1;
   try {
     geoLocationManager.removeGnssGeofence(fenceId).then(() => {
       console.info("removeGnssGeofence success fenceId:" + fenceId);
     }).catch((error : BusinessError) => {
       console.error("removeGnssGeofence: error=" + JSON.stringify(error));
     });
   } catch(error) {
     console.error("removeGnssGeofence: error=" + JSON.stringify(error));
   }
   ```
