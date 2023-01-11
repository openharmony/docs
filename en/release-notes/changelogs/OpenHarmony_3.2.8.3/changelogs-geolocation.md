# Location Subsystem ChangeLog

## cl.location.1 Migration of System APIs and APIs in API Version 9 to the New @ohos.geoLocationManager.d.ts

APIs in **@ohos.geolocation.d.ts** do not support throwing error codes. However, APIs in API version 9 and system APIs all need to support throwing error codes. To support this function, all system APIs and APIs in API version 9 in **@ohos.geolocation.d.ts** are migrated to the newly added **@ohos.geoLocationManager.d.ts** file, and corresponding error code description is added.

To use system APIs and APIs in API version 9 of the location subsystem, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';


**Change Impacts**

System APIs and APIs in API version 9 are affected. To ensure normal use of these APIs, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';

Other APIs are not affected.

**Key API/Component Changes**

| Class| Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
|geolocation| namespace | declare namespacegeolocation| Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation | interface | export interface ReverseGeocodingMockInfo  | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation | interface | export interface LocationMockConfig  | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation | interface | export interface CountryCode   | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation | enum | export enum CountryCodeType   | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation.GeoAddress | field | isFromMock?: Boolean; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation.Location  | field | isFromMock?: Boolean; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation.GeoLocationErrorCode  | field | NOT_SUPPORTED = 100 | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation.GeoLocationErrorCode  | field | QUERY_COUNTRY_CODE_ERROR | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getCountryCode(): Promise&lt;CountryCode&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function enableLocationMock(scenario: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;): void; | Deleted this API in API version 9.| 
|geolocation| method | function enableLocationMock(callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function enableLocationMock(scenario: LocationRequestScenario): Promise&lt;void&gt;; | Deleted this API in API version 9.| 
|geolocation| method | function enableLocationMock(): Promise&lt;void&gt;; |  Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function disableLocationMock(scenario: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;): void; | Deleted this API in API version 9.| 
|geolocation| method | function disableLocationMock(callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function disableLocationMock(scenario: LocationRequestScenario): Promise&lt;void&gt;; | Deleted this API in API version 9.| 
|geolocation| method | function disableLocationMock(): Promise&lt;void&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function setMockedLocations(config: LocationMockConfig, callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function setMockedLocations(config: LocationMockConfig): Promise&lt;void&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function enableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function enableReverseGeocodingMock(): Promise&lt;void&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function disableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. | 
|geolocation| method | function disableReverseGeocodingMock(): Promise&lt;void&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. |
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;, callback: AsyncCallback&lt;void&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. |
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): Promise&lt;void&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. |
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. |
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType): Promise&lt;boolean&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts**. |
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback&lt;boolean&gt;): void; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts** and changed the return value in the callback to **void**. |
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): Promise&lt;boolean&gt;; | Migrated this API in API version 9 to **@ohos.geoLocationManager.d.ts** and changed the return value in the promise to **void**. |

**(Optional) Adaptation Guide**

The following uses **enableLocation** as an example to show how it is called in the new version:

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

## cl.location.2 Location Service Permission Change

From API version 9, the **ohos.permission.APPROXIMATELY_LOCATION** permission is added for obtaining the approximate location.

If you use API version 9 or later, you need to apply for both the **ohos.permission.LOCATION** and **ohos.permission.APPROXIMATELY_LOCATION** permissions. Applying for only the **ohos.permission.LOCATION** permission will fail.

**Change Impacts**

Applications using API versions earlier than 9 are not affected. For an application using API version 9 or later, the method for applying for the location permission is changed. The details are as follows:

Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.

The system provides the following location permissions:

- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:

API versions earlier than 9: Apply for **ohos.permission.LOCATION**.

API version 9 and later: Apply for **ohos.permission.APPROXIMATELY_LOCATION**, or apply for **ohos.permission.APPROXIMATELY_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.

| API Version| Location Permission| Permission Application Result| Location Accuracy|
| -------- | -------- | -------- | -------- |
| Earlier than 9| ohos.permission.LOCATION | Success| Location accurate to meters|
| 9 and later| ohos.permission.LOCATION | Failure| No location obtained|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION | Success| Location accurate to 5 kilometers|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success| Location accurate to meters|

If your application needs to access the device location information when running in the background, it must be configured to be able to run in the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

You can declare the required permission in your application's configuration file. For details, see the [permission application guide](../../../application-dev/security/accesstoken-guidelines.md).

**Key API/Component Changes**

Applications using API versions earlier than 9 are not affected.

If your application uses API version 9 or later and needs to call APIs requiring the **ohos.permission.LOCATION** permission in **@ohos.geolocation** and **@ohos.geoLocationManager**, you need to apply for the corresponding permission as described previously.
