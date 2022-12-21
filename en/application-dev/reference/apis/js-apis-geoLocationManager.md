# Geolocation Manager

The Geolocation Manager module provides location service management functions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Applying for Permissions

Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.

The system provides the following location permissions:
- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:

- API versions earlier than 9: Apply for **ohos.permission.LOCATION**.

- API version 9 and later: Apply for **ohos.permission.APPROXIMATELY\_LOCATION**, or apply for **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.

| API Version| Location Permission                                                | Permission Application Result| Location Accuracy                    |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------------- |
| Earlier than 9        | ohos.permission.LOCATION                                     | Success    | Location accurate to meters|
| 9 and later    | ohos.permission.LOCATION                                     | Failure    | No location obtained                  |
| 9 and later    | ohos.permission.APPROXIMATELY_LOCATION                       | Success    | Location accurate to 5 kilometers |
| 9 and later    | ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success    | Location accurate to meters|

If your application needs to access the device location information when running in the background, it must be configured to be able to run in the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../../security/accesstoken-guidelines.md).


## Modules to Import

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## geoLocationManager.on('countryCodeChange')

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void;

Subscribes to the country code change event.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type    | string                                     | Yes  | Event type. The value **countryCodeChange** indicates to subscribe to the country code change event.|
| callback | Callback&lt;[CountryCode](#countrycode)&gt; | Yes  | Callback used to return the country code change event.                                        |

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                             |
| -------- | ------------------------------------- |
| 3301000  | Location service is unavailable.      |
| 3301100  | The location switch is off.           |
| 3301500  | Failed to query the area information. |


**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('countryCodeChange')

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void;

Unsubscribes from the country code change event.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type    | string                                     | Yes  | Event type. The value **countryCodeChange** indicates to unsubscribe from the country code change event.|
| callback | Callback&lt;[CountryCode](#countrycode)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified event type are unsubscribed from.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                             |
| -------- | ------------------------------------- |
| 3301000  | Location service is unavailable.      |
| 3301100  | The location switch is off.           |
| 3301500  | Failed to query the area information. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }
  try {
      geoLocationManager.on('countryCodeChange', callback);
      geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocation

enableLocation(callback: AsyncCallback&lt;void&gt;): void;

Enables the location service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback| AsyncCallback&lt;void&gt; | Yes  | Callback used to return the error message.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocation((err, data) => {
      if (err) {
          console.log('enableLocation: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

Enables the location service. This API uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

| Name             | Type| Mandatory| Description            |
| ------------------- | ---- | ---- | ---------------- |
| Promise&lt;void&gt; | void | No  | Promise used to return the error message.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocation().then((result) => {
      console.log('promise, enableLocation succeed');
  })
  .catch((error) => {
      console.log('promise, enableLocation: error=' + JSON.stringify(error));
  });
  ```

## geoLocationManager.disableLocation

disableLocation(callback: AsyncCallback&lt;void&gt;): void;

Disables the location service. This function uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the error code.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableLocation((err, data) => {
          if (err) {
              console.log('disableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.disableLocation

disableLocation(): Promise&lt;void&gt;

Disables the location service. This function uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

| Name             | Type| Mandatory| Description        |
| ------------------- | ---- | ---- | ------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the error code.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableLocation().then((result) => {
      console.log('promise, disableLocation succeed');
  })
  .catch((error) => {
      console.log('promise, disableLocation: error=' + JSON.stringify(error));
  });
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [LocationPrivacyType](#locationprivacytype) | Yes  | Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled. |
| callback | AsyncCallback&lt;boolean&gt;                | Yes  | Callback used to return the result, which indicates whether the user agrees with the privacy statement.                          |

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.isLocationPrivacyConfirmed(1, (err, result) => {
      if (err) {
          console.log('isLocationPrivacyConfirmed: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('isLocationPrivacyConfirmed: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type : LocationPrivacyType,): Promise&lt;boolean&gt;;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type   | [LocationPrivacyType](#locationprivacytype) | Yes  | Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled. |

**Return value**

| Name                | Type   | Mandatory| Description                              |
| ---------------------- | ------- | ---- | ---------------------------------- |
| Promise&lt;boolean&gt; | boolean | No  | Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.isLocationPrivacyConfirmed(1).then((result) => {
      console.log('promise, isLocationPrivacyConfirmed: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name     | Type                                       | Mandatory| Description                                                        |
| ----------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type        | [LocationPrivacyType](#locationprivacytype) | Yes  | Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled. |
| isConfirmed | boolean                                     | Yes  | Callback used to return the result, which indicates whether the user agrees with the privacy statement.                          |
| callback    | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the error message.                                            |

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.setLocationPrivacyConfirmStatus(1, true, (err, result) => {
      if (err) {
          console.log('setLocationPrivacyConfirmStatus: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean): Promise&lt;void&gt;;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name     | Type                                       | Mandatory| Description                                                        |
| ----------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type        | [LocationPrivacyType](#locationprivacytype) | Yes  | Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled. |
| isConfirmed | boolean                                     | Yes  | Callback used to return the result, which indicates whether the user agrees with the privacy statement.                          |

**Return value**

| Name             | Type| Mandatory| Description        |
| ------------------- | ---- | ---- | ------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the error code.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.setLocationPrivacyConfirmStatus(1, true).then((result) => {
      console.log('promise, setLocationPrivacyConfirmStatus succeed');
  })
  .catch((error) => {
      console.log('promise, disableLocation: error=' + JSON.stringify(error));
  });
  ```


## geoLocationManager.getCountryCode

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void;

Obtains the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description            |
| -------- | ------------------------------------------------ | ---- | ---------------- |
| callback | AsyncCallback&lt;[CountryCode](#countrycode)&gt; | Yes  | Callback used to return the country code.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                             |
| -------- | ------------------------------------- |
| 3301000  | Location service is unavailable.      |
| 3301500  | Failed to query the area information. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCountryCode((err, result) => {
      if (err) {
          console.log('getCountryCode: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('getCountryCode: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;;

Obtains the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

| Name                                    | Type                       | Mandatory| Description            |
| ------------------------------------------ | --------------------------- | ---- | ---------------- |
| Promise&lt;[CountryCode](#countrycode)&gt; | [CountryCode](#countrycode) | No  | Promise used to return the country code.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                             |
| -------- | ------------------------------------- |
| 3301000  | Location service is unavailable.      |
| 3301500  | Failed to query the area information. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCountryCode()
  .then((result) => {
      console.log('promise, getCountryCode: result=' + JSON.stringify(result));
  })
  .catch((error) => {
      console.log('promise, getCountryCode: error=' + JSON.stringify(error));
  });
  ```


## geoLocationManager.enableLocationMock

enableLocationMock(callback: AsyncCallback&lt;void&gt;): void;

Enables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result indicating whether it is successful to enable the function. If so, **nullptr** is returned. Otherwise, an error message is returned.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocationMock((err, result) => {
      if (err) {
          console.log('enableLocationMock: err=' + JSON.stringify(err));
      }
  });
  ```

## geoLocationManager.enableLocationMock

enableLocationMock(): Promise&lt;void&gt;;

Enables the mock location function 

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to enable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocationMock()
  .then((result) => {
      console.log('promise, enableLocationMock: succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, enableLocationMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(callback: AsyncCallback&lt;void&gt;): void;

Disables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result indicating whether it is successful to disable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableLocationMock((err, result) => {
      if (err) {
          console.log('disableLocationMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(): Promise&lt;void&gt;;

Disables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to disable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableLocationMock()
  .then((result) => {
        console.log('promise, disableLocationMock succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, disableLocationMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig, callback: AsyncCallback&lt;void&gt;): void;

Sets the mock location information. The mock locations will be reported at the interval specified in this API.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| config   | [LocationMockConfig](#locationmockconfig) | Yes  | Mock location information, including the interval for reporting the mock locations and the array of the mock locations.|
| callback | AsyncCallback&lt;void&gt;                 | Yes  | Callback used to return the result indicating whether it is successful to set the information. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations": locations};
  geoLocationManager.setMockedLocations(config, (err, data) => {
      if (err) {
          console.log('setMockedLocations: err=' + JSON.stringify(err));
      }
  });
  ```

## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig): Promise&lt;void&gt;;

Sets the mock location information. The mock locations will be reported at the interval specified in this API.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type                                     | Mandatory| Description                                                        |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [LocationMockConfig](#locationmockconfig) | Yes  | Mock location information, including the interval for reporting the mock locations and the array of the mock locations.|

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to set the information. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |
| 3301100  | The location switch is off.      |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations":locations};
  geoLocationManager.setMockedLocations(config)
  .then((result) => {
      console.log('promise, setMockedLocations succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, setMockedLocations: error=' + JSON.stringify(error));
      }
  });
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void;

Enables the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result indicating whether it is successful to enable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableReverseGeocodingMock((err, data) => {
      if (err) {
          console.log('enableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(): Promise&lt;void&gt;;

Enables the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to enable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableReverseGeocodingMock()
  .then((result) => {
      console.log('promise, enableReverseGeocodingMock succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, enableReverseGeocodingMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void;

Disables the mock geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result indicating whether it is successful to disable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableReverseGeocodingMock((err, result) => {
      if (err) {
          console.log('disableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(): Promise&lt;void&gt;;

Disables the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to disable the function. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableReverseGeocodingMock()
  .then((result) => {
      console.log('promise, disableReverseGeocodingMock succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, disableReverseGeocodingMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;, callback: AsyncCallback&lt;void&gt;): void;

Sets information of the mock reverse geocoding function, including the mapping between a location and geographical name. If the location is contained in the configurations during reverse geocoding query, the corresponding geographical name will be returned.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | Yes  | Array of information of the mock reverse geocoding function, including a location and a geographical name.|
| callback  | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result indicating whether it is successful to set the information. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  geoLocationManager.setReverseGeocodingMockInfo(mockInfos, (err, data) => {
      if (err) {
          console.log('promise, setReverseGeocodingMockInfo, err:' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): Promise&lt;void&gt;;

Sets information of the mock reverse geocoding function, including the mapping between a location and geographical name. If the location is contained in the configurations during reverse geocoding query, the corresponding geographical name will be returned.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | Yes  | Array of information of the mock reverse geocoding function, including a location and a geographical name.|

**Return value**

| Name             | Type| Mandatory| Description                                                        |
| ------------------- | ---- | ---- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | void | No  | Promise used to return the result indicating whether it is successful to set the information. If so, **nullptr** is returned; an error message otherwise.|

**Error codes**

For details about the following error codes, see [error codes of the location service](../errorcodes/errorcode-geoLocationManager.md).

| Code| Error Message                        |
| -------- | -------------------------------- |
| 3301000  | Location service is unavailable. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  geoLocationManager.setReverseGeocodingMockInfo(mockInfos)
  .then((result) => {
      console.log('promise, setReverseGeocodingMockInfo succeed');
  })
  .catch((error) => {
      if (error) {
        console.log('promise, setReverseGeocodingMockInfo: error=' + JSON.stringify(error));
      }
  });
  ```


## LocationRequestPriority

Sets the priority of the location request.

**System capability**: SystemCapability.Location.Location.Core

| Name     | Value   | Description                                                        |
| --------- | ----- | ------------------------------------------------------------ |
| UNSET     | 0x200 | Priority unspecified.                                          |
| ACCURACY  | 0x201 | Location accuracy.                                              |
| LOW_POWER | 0x202 | Power efficiency.                                            |
| FIRST_FIX | 0x203 | Fast location. Use this option if you want to obtain a location as fast as possible.|


## LocationRequestScenario

  Sets the scenario of the location request.

**System capability**: SystemCapability.Location.Location.Core

| Name               | Value   | Description                                                        |
| ------------------- | ----- | ------------------------------------------------------------ |
| UNSET               | 0x300 | Scenario unspecified.                                        |
| NAVIGATION          | 0x301 | Navigation.                                              |
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.                                      |
| CAR_HAILING         | 0x303 | Ride hailing.                                              |
| DAILY_LIFE_SERVICE  | 0x304 | Daily life services.                                      |
| NO_POWER            | 0x305 | Power efficiency. Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.|


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name     | Type  | Readable| Writable| Description                                                |
| --------- | ------ | ---- | ---- | ---------------------------------------------------- |
| locale    | string | Yes  | Yes  | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| latitude  | number | Yes  | Yes  | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.          |
| longitude | number | Yes  | Yes  | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .          |
| maxItems  | number | Yes  | Yes  | Maximum number of location records to be returned.                        |


## GeoCodeRequest

Defines a geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name        | Type  | Readable| Writable| Description                                                      |
| ------------ | ------ | ---- | ---- | ---------------------------------------------------------- |
| locale       | string | Yes  | Yes  | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.      |
| description  | string | Yes  | Yes  | Location description, for example, **No. xx, xx Road, Pudong New District, Shanghai**.            |
| maxItems     | number | Yes  | Yes  | Maximum number of location records to be returned.                              |
| minLatitude  | number | Yes  | Yes  | Minimum latitude. This parameter is used with **minLongitude**, **maxLatitude**, and **maxLongitude** to specify the latitude and longitude ranges.|
| minLongitude | number | Yes  | Yes  | Minimum longitude.                                        |
| maxLatitude  | number | Yes  | Yes  | Maximum latitude.                                        |
| maxLongitude | number | Yes  | Yes  | Maximum longitude.                                        |


## GeoAddress

Defines a geographic location.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name                 | Type               | Readable| Writable| Description                                                |
| --------------------- | ------------------- | ---- | ---- | ---------------------------------------------------- |
| latitude              | number              | Yes  | No  | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.          |
| longitude             | number              | Yes  | No  | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .          |
| locale                | string              | Yes  | No  | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName             | string              | Yes  | No  | Landmark of the location.                                      |
| countryCode           | string              | Yes  | No  | Country code.                                    |
| countryName           | string              | Yes  | No  | Country name.                                      |
| administrativeArea    | string              | Yes  | No  | Administrative region name.                                  |
| subAdministrativeArea | string              | Yes  | No  | Sub-administrative region name.                                |
| locality              | string              | Yes  | No  | Locality information.                                      |
| subLocality           | string              | Yes  | No  | Sub-locality information.                                    |
| roadName              | string              | Yes  | No  | Road name.                                      |
| subRoadName           | string              | Yes  | No  | Auxiliary road information.                                    |
| premises              | string              | Yes  | No  | House information.                                    |
| postalCode            | string              | Yes  | No  | Postal code.                                  |
| phoneNumber           | string              | Yes  | No  | Phone number.                                  |
| addressUrl            | string              | Yes  | No  | Website URL.                        |
| descriptions          | Array&lt;string&gt; | Yes  | No  | Additional descriptions.                                |
| descriptionsSize      | number              | Yes  | No  | Total number of additional descriptions.                            |
| isFromMock            | Boolean             | Yes  | No  | Whether the geographical name is from the mock reverse geocoding function.          |


## LocationRequest

Defines a location request.

**System capability**: SystemCapability.Location.Location.Core

| Name            | Type                                               | Readable| Writable| Description                                                        |
| ---------------- | --------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| priority         | [LocationRequestPriority](#locationrequestpriority) | Yes  | Yes  | Priority of the location request.                                            |
| scenario         | [LocationRequestScenario](#locationrequestscenario) | Yes  | Yes  | Scenario of the location request.                                              |
| timeInterval     | number                                              | Yes  | Yes  | Time interval at which location information is reported.                                |
| distanceInterval | number                                              | Yes  | Yes  | Distance interval at which location information is reported.                                |
| maxAccuracy      | number                                              | Yes  | Yes  | Location accuracy. This parameter is valid only when the precise location function is enabled, and is invalid when the approximate location function is enabled.|


## CurrentLocationRequest

Defines the current location request.

**System capability**: SystemCapability.Location.Location.Core

| Name       | Type                                               | Readable| Writable| Description                                                        |
| ----------- | --------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| priority    | [LocationRequestPriority](#locationrequestpriority) | Yes  | Yes  | Priority of the location request.                                            |
| scenario    | [LocationRequestScenario](#locationrequestscenario) | Yes  | Yes  | Scenario of the location request.                                              |
| maxAccuracy | number                                              | Yes  | Yes  | Location accuracy, in meters. This parameter is valid only when the precise location function is enabled, and is invalid when the approximate location function is enabled.|
| timeoutMs   | number                                              | Yes  | Yes  | Timeout duration, in milliseconds. The minimum value is **1000**.                  |


## SatelliteStatusInfo

Defines the satellite status information.

**System capability**: SystemCapability.Location.Location.Gnss

| Name                  | Type               | Readable| Writable| Description                             |
| ---------------------- | ------------------- | ---- | ---- | --------------------------------- |
| satellitesNumber       | number              | Yes  | No  | Number of satellites.                   |
| satelliteIds           | Array&lt;number&gt; | Yes  | No  | Array of satellite IDs.     |
| carrierToNoiseDensitys | Array&lt;number&gt; | Yes  | No  | Carrier-to-noise density ratio, that is, **cn0**.|
| altitudes              | Array&lt;number&gt; | Yes  | No  | Altitude information.                   |
| azimuths               | Array&lt;number&gt; | Yes  | No  | Azimuth information.                     |
| carrierFrequencies     | Array&lt;number&gt; | Yes  | No  | Carrier frequency.                   |


## CachedGnssLocationsRequest

Represents a request for reporting cached GNSS locations.

**System capability**: SystemCapability.Location.Location.Gnss

| Name                | Type   | Readable| Writable| Description                                                        |
| -------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| reportingPeriodSec   | number  | Yes  | Yes  | Interval for reporting the cached GNSS locations, in milliseconds.                    |
| wakeUpCacheQueueFull | boolean | Yes  | Yes  | **true**: reports the cached GNSS locations to the application when the cache queue is full.<br />**false**: discards the cached GNSS locations when the cache queue is full. |


## Geofence

Defines a GNSS geofence. Currently, only circular geofences are supported.

**System capability**: SystemCapability.Location.Location.Geofence

| Name      | Type  | Readable| Writable| Description                        |
| ---------- | ------ | ---- | ---- | ---------------------------- |
| latitude   | number | Yes  | Yes  | Latitude information.                  |
| longitude  | number | Yes  | Yes  | Longitude information.                  |
| radius     | number | Yes  | Yes  | Radius of a circular geofence.        |
| expiration | number | Yes  | Yes  | Expiration period of a geofence, in milliseconds.|


## GeofenceRequest

Represents a GNSS geofencing request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name    | Type                                               | Readable| Writable| Description                |
| -------- | --------------------------------------------------- | ---- | ---- | -------------------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | Yes  | Yes  | Priority of the location information.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes  | Yes  | Location scenario.      |
| geofence | [Geofence](#geofence)                               | Yes  | Yes  | Geofence information.      |


## LocationPrivacyType

Defines the privacy statement type.

**System capability**: SystemCapability.Location.Location.Core

| Name         | Value  | Description                          |
| ------------- | ---- | ------------------------------ |
| OTHERS        | 0    | Other scenarios.                    |
| STARTUP       | 1    | Privacy statement displayed in the startup wizard.    |
| CORE_LOCATION | 2    | Privacy statement displayed when enabling the location service.|


## LocationCommand

Defines an extended command.

**System capability**: SystemCapability.Location.Location.Core

| Name    | Type                                               | Readable| Writable| Description            |
| -------- | --------------------------------------------------- | ---- | ---- | ---------------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes  | Yes  | Location scenario.  |
| command  | string                                              | Yes  | Yes  | Extended command, in the string format.|


## Location

Defines a location.

**System capability**: SystemCapability.Location.Location.Core

| Name         | Type               | Readable| Writable| Description                                      |
| ------------- | ------------------- | ---- | ---- | ------------------------------------------ |
| latitude      | number              | Yes  | No  | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude     | number              | Yes  | No  | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| altitude      | number              | Yes  | No  | Location altitude, in meters.                    |
| accuracy      | number              | Yes  | No  | Location accuracy, in meters.                    |
| speed         | number              | Yes  | No  | Speed, in m/s.                |
| timeStamp     | number              | Yes  | No  | Location timestamp in the UTC format.                 |
| direction     | number              | Yes  | No  | Direction information.                            |
| timeSinceBoot | number              | Yes  | No  | Location timestamp since boot.            |
| additions     | Array&lt;string&gt; | Yes  | No  | Additional description.                                |
| additionSize  | number              | Yes  | No  | Number of additional descriptions.                            |
| isFromMock    | Boolean             | Yes  | No  | Whether the location information is from the mock location function.      |


## ReverseGeocodingMockInfo

Represents information of the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name      | Type                                           | Readable| Writable| Description            |
| ---------- | ----------------------------------------------- | ---- | ---- | ---------------- |
| location   | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes  | Yes  | Latitude and longitude information.|
| geoAddress | [GeoAddress](#geoaddress)                       | Yes  | Yes  | Geographical name.  |


## LocationMockConfig

Represents the information of the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name        | Type                 | Readable| Writable| Description                                  |
| ------------ | --------------------- | ---- | ---- | -------------------------------------- |
| timeInterval | number                | Yes  | Yes  | Interval at which mock locations are reported, in seconds.|
| locations    | Array&lt;Location&gt; | Yes  | Yes  | Array of mocked locations.                    |


## CountryCode

Represents country code information.

**System capability**: SystemCapability.Location.Location.Core

| Name   | Type                               | Readable| Writable| Description                |
| ------- | ----------------------------------- | ---- | ---- | -------------------- |
| country | string                              | Yes  | No  | Country code.  |
| type    | [CountryCodeType](#countrycodetype) | Yes  | No  | Country code source.|


## CountryCodeType

Represents the country code source type.

**System capability**: SystemCapability.Location.Location.Core

| Name                      | Value  | Description                                              |
| -------------------------- | ---- | -------------------------------------------------- |
| COUNTRY_CODE_FROM_LOCALE   | 1    | Country code obtained from the language configuration of the globalization module.      |
| COUNTRY_CODE_FROM_SIM      | 2    | Country code obtained from the SIM card.                         |
| COUNTRY_CODE_FROM_LOCATION | 3    | Country code obtained using the reverse geocoding function based on the user's location information.|
| COUNTRY_CODE_FROM_NETWORK  | 4    | Country code obtained from the cellular network registration information.              |
