# Geofencing

## Scenario

A geofence is a group of virtual bounds defining an area on the map. When a user device enters or leaves a geofence, or stays in a geofence, your app on the user device can automatically receive notifications and alarms.

Currently, only circular fences are supported. In addition, the geo-fencing function of the GNSS chip is required. Events of entering or leaving the fence can be accurately identified only in open outdoor areas.

A typical application of geofencing is to create a geofence around an enterprise for targeted advertising. In different areas, you can provide differentiated promotions for mobile devices.

## Available APIs

Geo-fencing uses the following interfaces. For details, see [Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md).

| API| Description| 
| -------- | -------- |
| [on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerongnssfencestatuschange) | Registers a listener for status change events of the specified geofence.| 
| [off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageroffgnssfencestatuschange) | Unregisters the listener for status change events of the specified geofence.| 

## How to Develop

1. Declare the **ohos.permission.APPROXIMATELY_LOCATION** permission. For details, see [Applying for Location Permissions](#location-permission-guidelines.md).

2. Import the **geoLocationManager**, **wantAgent**, and **BusinessError** modules.
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { wantAgent } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   ```

3. Create a **WantAgentInfo** object.

   Scenario 1: Create a **WantAgentInfo** object for starting an ability. 

   ```ts
   // Set the action type through operationType of WantAgentInfo.
   let wantAgentInfo:wantAgent.WantAgentInfo = {
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

   Scenario 2: Create a **WantAgentInfo** object for releasing a public event.

   ```ts
   // Set the action type through operationType of WantAgentInfo.
   let wantAgentInfo:wantAgent.WantAgentInfo = {
       wants: [
           {
               action: 'event_name', // Set the action name.
               parameters: {},
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
   }
   ```

4. Call **getWantAgent()** to create a **WantAgent** object.

   Call the geofencing API to add a geofence after obtaining the **WantAgent** object, and have the system automatically trigger the action defined for the **WantAgent** object when a device enters or exits the geofence.

   ```ts
   let wantAgentObj : object | undefined = undefined;
   // Create a WantAgent object.
   wantAgent.getWantAgent(wantAgentInfo, (err, data) => {
       if (err) {
         console.error('getWantAgent err=' + JSON.stringify(err));
         return;
       }
       console.info('getWantAgent success');
       wantAgentObj = data;
       let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000}};
       try {
           geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
       } catch (err) {
           console.error("errCode:" + JSON.stringify(err));
       }
   });
   ```
