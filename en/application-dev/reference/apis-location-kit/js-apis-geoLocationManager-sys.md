# @ohos.geoLocationManager (Geolocation Manager) (System API)

The **geoLocationManager** module provides location services such as Global Navigation Satellite System (GNSS)-based positioning, network positioning, geofencing, as well as geocoding and reverse geocoding.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.geoLocationManager (Geolocation Manager)](js-apis-geoLocationManager.md).
> This module supports only the WGS-84 coordinate system.

## Applying for Permissions

Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.

The system provides the following location permissions:
- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:

API versions earlier than 9: Apply for **ohos.permission.LOCATION**.

API version 9 and later: Apply for **ohos.permission.APPROXIMATELY\_LOCATION**, or apply for **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.

| API Version| Location Permission| Permission Application Result| Location Accuracy|
| -------- | -------- | -------- | -------- |
| Earlier than 9| ohos.permission.LOCATION | Success| Location accurate to meters|
| 9 and later| ohos.permission.LOCATION | Failure| No location obtained|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION | Success| Location accurate to 5 kilometers|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success| Location accurate to meters|

To access the device location information when running in the background, an application needs to request for a continuous task of the LOCATION type. In this way, the system continues to report device location information after your application moves to the background. For details about how to request for a continuous task, see [Continuous Task](../../task-management/continuous-task.md).

A user can grant the **ohos.permission.LOCATION_IN_BACKGROUND** permission for an application on the setting page. For details, see [ohos.permission.LOCATION_IN_BACKGROUND](../../security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background).

You can declare the required permission in your application's configuration file. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).


## Modules to Import

```ts
import { geoLocationManager } from '@kit.LocationKit';
```

## GeoAddress

Geocoding address information.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | No| Yes| **true**: The geographic address is obtained from the mock reverse geocoding function.<br>**false**: The geographic address is not obtained from the mock reverse geocoding function.<br>**System API**: This is a system API.|


## Location

Location information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | No| Yes| **true**: The location information is obtained from the mock location function.<br>**false**: The location information is not obtained from the location simulation function.<br>**System API**: This is a system API.|


## ReverseGeocodingMockInfo

Defines the configuration of the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](js-apis-geoLocationManager.md#reversegeocoderequest) | No| No| Latitude and longitude information.|
| geoAddress |  [GeoAddress](#geoaddress) | No| No|Geographical name.|


## LocationMockConfig

Defines the configuration of the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| timeInterval | number | No| No| Time interval at which mock locations are reported, in seconds.|
| locations | Array&lt;[Location](#location)&gt; | No| No| Array of mocked locations.|

## LocatingRequiredDataConfig<sup>10+</sup>

Defines the configuration for obtaining the required data of the location service.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| type | [LocatingRequiredDataType](#locatingrequireddatatype10) | No| No| Type of the required data.|
| needStartScan |  boolean | No| No| **true**: Scanning needs to be initiated.<br>**false**: Scanning does not need to be initiated.|
| scanInterval |  number | No| Yes| Scanning interval, in milliseconds. The specified value must be greater than **0**. The default value is **10000**.|
| scanTimeout |  number | No| Yes| Scanning timeout interval, in milliseconds. The value ranges from **0** to **600000**. The default value is **10000**.|


## LocatingRequiredData<sup>10+</sup>

Defines the required data of the location service, including the Wi-Fi or Bluetooth scanning result. After obtaining the data, an application can use the data for services such as network positioning.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| wifiData | [WifiScanInfo](#wifiscaninfo10) | No| Yes| Wi-Fi scanning result.|
| bluetoothData |  [BluetoothScanInfo](#bluetoothscaninfo10) | No| Yes| Bluetooth scanning result.|


## WifiScanInfo<sup>10+</sup>

Defines the Wi-Fi scanning information, including the SSID, BSSID, and RSSI of the scanned Wi-Fi hotspot.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | No| No| Service set identifier (SSID) of a Wi-Fi hotspot, in UTF-8 format.|
| bssid | string | No| No| Base station subsystem identifier (BSSID) of a Wi-Fi hotspot.|
| rssi | number | No| No| Received signal strength indicator (RSSI) of a Wi-Fi hotspot, in dBm.|
| frequency | number | No| No| Frequency of a Wi-Fi hotspot.|
| timestamp | number | No| No| Scanning timestamp.|


## BluetoothScanInfo<sup>10+</sup>

Defines the Bluetooth scanning information.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | No| No| Name of a Bluetooth device.|
| macAddress | string | No| No| MAC address of a Bluetooth device.|
| rssi | number | No| No| Signal strength of a Bluetooth device, in dBm.|
| timestamp | number | No| No| Scanning timestamp.|

## LocationPrivacyType

Defines the privacy statement type.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| OTHERS | 0 | Other scenarios. Reserved field.|
| STARTUP | 1 | Privacy statement displayed in the startup wizard. The user needs to choose whether to agree with the statement.|
| CORE_LOCATION | 2 | Privacy statement displayed when enabling the location service.|

## LocatingRequiredDataType<sup>10+</sup>

Defines the type of the required data of the location service.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| WIFI  | 1 | Wi-Fi scanning information.|
| BLUETOOTH | 2 | Bluetooth scanning information.|


## LocationIconStatus<sup>12+</sup>

Defines the location icon status.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| LOCATING_NOT_STARTED  | 0 | No location services are available and the location icon does not need to be displayed.|
| LOCATING_STARTED | 1 | Common location is in progress, and the common location icon needs to be displayed.|
| HD_LOCATING_STARTED | 2 | High-precision location is in progress, and the high-precision location icon needs to be displayed.|


## geoLocationManager.on('locatingRequiredDataChange')<sup>10+</sup>

on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void;

Subscribes to changes in the required data of the location service, including Wi-Fi and Bluetooth scanning information. An application can then determine whether to enable Wi-Fi and Bluetooth scanning based on the return result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locatingRequiredDataChange** indicates a change in the required data of the location service.|
  | config | [LocatingRequiredDataConfig](#locatingrequireddataconfig10) | Yes| Configuration for obtaining the required data of the location service.|
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | Yes| Callback used to return the data required by the location service.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locatingRequiredDataChange')} due to limited device capabilities.          |
|3301800 | Failed to start WiFi or Bluetooth scanning.                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit'
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.log('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.off('locatingRequiredDataChange')<sup>10+</sup>

off(type: 'locatingRequiredDataChange', callback?: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void;

Unsubscribes from changes in the required data of the location service and stops Wi-Fi and Bluetooth scanning.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locatingRequiredDataChange** indicates a change in the required data of the location service.|
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locatingRequiredDataChange')} due to limited device capabilities.          |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit'
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.log('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
      geoLocationManager.off('locatingRequiredDataChange', callback);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```

## geoLocationManager.enableLocation

enableLocation(callback: AsyncCallback&lt;void&gt;): void;

Enables the location service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the location service is successfully enabled, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                              |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit'
  try {
      geoLocationManager.enableLocation((err) => {
          if (err) {
              console.error('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

Enables the location service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit'
  try {
      geoLocationManager.enableLocation().then(() => {
          console.log('promise, enableLocation succeed');
      })
      .catch((error:BusinessError) => {
          console.error('promise, enableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```

## geoLocationManager.disableLocation

disableLocation(): void;

Disables the location service.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableLocation();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```

## geoLocationManager.enableLocationMock

enableLocationMock(): void;

Enables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocationMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.enableLocationMock();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(): void;

Disables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableLocationMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableLocationMock();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig): void;

Sets the mock location information. The mock locations will be reported at the interval specified in this API.

This API can be invoked only after [geoLocationManager.enableLocationMock](#geolocationmanagerenablelocationmock) is called.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | config |  [LocationMockConfig](#locationmockconfig) | Yes| Mock location information, including the interval for reporting the mock locations and the array of the mock locations.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setMockedLocations} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let locations:Array<geoLocationManager.Location> = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  let config:geoLocationManager.LocationMockConfig = {"timeInterval": 5, "locations": locations};
  try {
      geoLocationManager.enableLocationMock();
      geoLocationManager.setMockedLocations(config);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(): void;

Enables the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableReverseGeocodingMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.enableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(): void;

Disables the mock geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableReverseGeocodingMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): void;

Sets information of the mock reverse geocoding function, including the mapping between a location and geographical name. If the location is contained in the configurations during reverse geocoding query, the corresponding geographical name will be returned.

This API can be invoked only after [geoLocationManager.enableReverseGeocodingMock](#geolocationmanagerenablereversegeocodingmock) is called.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | Yes| Array of information of the mock reverse geocoding function, including a location and a geographical name.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setReverseGeocodingMockInfo} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let mockInfos:Array<geoLocationManager.ReverseGeocodingMockInfo> = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "isFromMock": true}},
  ];
  try {
      geoLocationManager.enableReverseGeocodingMock();
      geoLocationManager.setReverseGeocodingMockInfo(mockInfos);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type |  [LocationPrivacyType](#locationprivacytype)| Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The user agrees to the privacy statement of the location service.<br>**false**: The user does not agree to the privacy statement of the location service.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.isLocationPrivacyConfirmed} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [LocationPrivacyType](#locationprivacytype) | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled.|
  | isConfirmed | boolean | Yes| **true**: The user agrees to the privacy statement of the location service.<br>**false**: The user does not agree to the privacy statement of the location service.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setLocationPrivacyConfirmStatus} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.setLocationPrivacyConfirmStatus(1, true);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.getLocatingRequiredData<sup>10+</sup>

getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise&lt;Array&lt;LocatingRequiredData&gt;&gt;;

Obtains the required data of the location service. This API uses a promise to return the result.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | config | [LocatingRequiredDataConfig](#locatingrequireddataconfig10) | Yes| Configuration for obtaining the required data of the location service.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | Promise used to return the required data for the location service, such as the Wi-Fi and Bluetooth scanning information.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getLocatingRequiredData} due to limited device capabilities.          |
|3301800  | Failed to start WiFi or Bluetooth scanning.                    |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit'
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.getLocatingRequiredData(config).then((result) => {
          console.log('getLocatingRequiredData return: ' + JSON.stringify(result));
      })  
      .catch((error:BusinessError) => {
          console.error('promise, getLocatingRequiredData: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.on('locationIconStatusChange')<sup>12+</sup>

on(type: 'locationIconStatusChange', callback: Callback&lt;LocationIconStatus&gt;): void;

Subscribes to status changes of the location icon. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. Event type. The value **locationIconStatusChange** indicates status changes of the location icon.|
  | callback | Callback&lt;[LocationIconStatus](#locationiconstatus12)&gt; | Yes| Callback used to return the location icon status.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationIconStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                        |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code: geoLocationManager.LocationIconStatus):void => {
      console.log('LocationIconStatus: ' + JSON.stringify(code));
  }
  try {
      geoLocationManager.on('locationIconStatusChange', callback);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.off('locationIconStatusChange')<sup>12+</sup>

off(type: 'locationIconStatusChange', callback?: Callback&lt;LocationIconStatus&gt;): void;

Unsubscribes from status changes of the location icon.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. Event type. The value **locationIconStatusChange** indicates status changes of the location icon.|
  | callback | Callback&lt;[LocationIconStatus](#locationiconstatus12)&gt;  | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationIconStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.        |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code: geoLocationManager.LocationIconStatus):void => {
      console.log('LocationIconStatus: ' + JSON.stringify(code));
  }
  try {
      geoLocationManager.on('locationIconStatusChange', callback);
	  geoLocationManager.off('locationIconStatusChange', callback);
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```


## geoLocationManager.getLocationIconStatus<sup>12+</sup>

getLocationIconStatus(): LocationIconStatus;

Obtains the current location icon status.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [LocationIconStatus](#locationiconstatus12) | Location icon status.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.getLocationIconStatus} due to limited device capabilities.          |
|3301000  | The location service is unavailable.                  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let iconStatus = geoLocationManager.getLocationIconStatus();
  } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
  }
  ```
