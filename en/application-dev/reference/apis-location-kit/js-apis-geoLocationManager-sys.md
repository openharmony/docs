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

To access the device location information when running in the background, an application needs to request for the **ohos.permission.LOCATION_IN_BACKGROUND** permission or a continuous task of the background mode. In this way, the system continues to report device location information after your application moves to the background.

A user can grant the **ohos.permission.LOCATION_IN_BACKGROUND** permission for an application on the setting page. For details, see [ohos.permission.LOCATION_IN_BACKGROUND](../../security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background).

For details about how to request for a continuous task, see [Continuous Task](../../task-management/continuous-task.md).

You can declare the required permission in your application's configuration file. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).


## Modules to Import

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```

## GeoAddress

Geocoding address information.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | Yes| No| Whether the geographical name is from the mock reverse geocoding function.<br>**System API**: This is a system API.|


## Location

Location information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | Yes| No| Whether the location information is from the mock location function.<br>**System API**: This is a system API.|


## ReverseGeocodingMockInfo

Defines the configuration of the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](js-apis-geoLocationManager.md#reversegeocoderequest) | Yes| Yes| Latitude and longitude information.|
| geoAddress |  [GeoAddress](#geoaddress) | Yes| Yes|Geographical name.|


## LocationMockConfig

Defines the configuration of the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| timeInterval | number | Yes| Yes| Time interval at which mock locations are reported, in seconds.|
| locations | Array&lt;[Location](#location)&gt; | Yes| Yes| Array of mocked locations.|

## LocatingRequiredDataConfig<sup>10+</sup>

Defines the configuration for obtaining the required data of the location service.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| type | [LocatingRequiredDataType](#locatingrequireddatatype10) | Yes| Yes| Type of the required data.|
| needStartScan |  boolean | Yes| Yes| Whether to initiate scanning.|
| scanInterval |  number | Yes| Yes| Scanning interval, in milliseconds. The specified value must be greater than **0**. The default value is **10000**.|
| scanTimeout |  number | Yes| Yes| Scanning timeout interval, in milliseconds. The value ranges from **0** to **600000**. The default value is **10000**.|


## LocatingRequiredData<sup>10+</sup>

Defines the required data of the location service, including the Wi-Fi or Bluetooth scanning result. After obtaining the data, an application can use the data for services such as network positioning.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| wifiData | [WifiScanInfo](#wifiscaninfo10) | Yes| No| Wi-Fi scanning result.|
| bluetoothData |  [BluetoothScanInfo](#bluetoothscaninfo10) | Yes| No| Bluetooth scanning result.|


## WifiScanInfo<sup>10+</sup>

Defines the Wi-Fi scanning information, including the SSID, BSSID, and RSSI of the scanned Wi-Fi hotspot.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| Service set identifier (SSID) of a Wi-Fi hotspot, in UTF-8 format.|
| bssid | string | Yes| No| Base station subsystem identifier (BSSID) of a Wi-Fi hotspot.|
| rssi | number | Yes| No| Received signal strength indicator (RSSI) of a Wi-Fi hotspot, in dBm.|
| frequency | number | Yes| No| Frequency of a Wi-Fi hotspot.|
| timestamp | number | Yes| No| Scanning timestamp.|


## BluetoothScanInfo<sup>10+</sup>

Defines the Bluetooth scanning information.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | Yes| No| Name of a Bluetooth device.|
| macAddress | string | Yes| No| MAC address of a Bluetooth device.|
| rssi | number | Yes| No| Signal strength of a Bluetooth device, in dBm.|
| timestamp | number | Yes| No| Scanning timestamp.|

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

## geoLocationManager.on('locatingRequiredDataChange')<sup>10+</sup>

on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void;

Subscribes to changes in the required data of the location service, including Wi-Fi and Bluetooth scanning information. An application can then determine whether to enable Wi-Fi and Bluetooth scanning based on the return result.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locatingRequiredDataChange** indicates a change in the required data of the location service.|
  | config | [LocatingRequiredDataConfig](#locatingrequireddataconfig10) | Yes| Configuration for obtaining the required data of the location service.|
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | Yes| Callback used to receive the required data of the location service.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301800 | Failed to start WiFi or Bluetooth scanning.                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.log('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.log('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
      geoLocationManager.off('locatingRequiredDataChange', callback);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to receive the error message.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.enableLocation((err) => {
          if (err) {
              console.error('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.enableLocation().then(() => {
          console.log('promise, enableLocation succeed');
      })
      .catch((error:number) => {
          console.error('promise, enableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.disableLocation();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.enableLocationMock();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.disableLocationMock();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
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
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.enableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.disableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
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
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  | boolean | Whether the user agrees with the privacy statement.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      let isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  | isConfirmed | boolean | Yes| Whether the user agrees with the privacy statement.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.setLocationPrivacyConfirmStatus(1, true);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
|3301800  | Failed to start WiFi or Bluetooth scanning.                    |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.getLocatingRequiredData(config).then((result) => {
          console.log('getLocatingRequiredData return: ' + JSON.stringify(result));
      })  
      .catch((error:number) => {
          console.error('promise, getLocatingRequiredData: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```
