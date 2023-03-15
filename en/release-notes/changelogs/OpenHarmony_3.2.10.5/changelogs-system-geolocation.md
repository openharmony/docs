# Location Subsystem ChangeLog

## cl.location.1 API Migration from @system.geolocation.d.ts to @ohos.geoLocationManager.d.ts

APIs in **@system.geolocation.d.ts** do not support throwing error codes. To support this function, all APIs in **@system.geolocation.d.ts** are migrated to the newly added **@ohos.geoLocationManager.d.ts** file, and corresponding error code description is added.

To use APIs of the location subsystem, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';


**Change Impacts**

All APIs of the location subsystem are affected. To ensure normal use of these APIs, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';

**Key API/Component Changes**

| Class       | API Type | Declaration                                                    | Change Type                                                    |
| ----------- | --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Geolocation | class     | Geolocation                                                  | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager**.|
| Geolocation | interface | static getLocation(options?: GetLocationOption): void;       | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.getCurrentLocation**.|
| Geolocation | interface | static getLocationType(options?: GetLocationTypeOption): void; | Deprecated.                                                    |
| Geolocation | interface | static subscribe(options: SubscribeLocationOption): void;    | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.on#event:locationChange**.|
| Geolocation | interface | static unsubscribe(): void;                                  | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.off#event:locationChange**.|
| Geolocation | interface | static getSupportedCoordTypes(): Array<string>;              | Deprecated.                                                    |
|             | interface | GeolocationResponse                                          | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.Location**.|
|             | interface | GetLocationOption                                            | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest**.|
|             | interface | GetLocationTypeResponse                                      | Deprecated.                                                    |
|             | interface | GetLocationTypeOption                                        | Deprecated.                                                    |
|             | interface | SubscribeLocationOption                                      | Migrated to **@ohos.geoLocationManager.d.ts** and replaced by **ohos.geoLocationManager/geoLocationManager.LocationRequest**.|


**(Optional) Adaptation Guide**

The following sample code shows how to call **enableLocation** in the new version:

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocation((err, data) => {
          if (err) {
              console.log('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
