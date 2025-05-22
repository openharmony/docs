# @system.geolocation (Geolocation)

The **geolocation** module provides only basic functions such as GNSS positioning and network positioning.

> **NOTE**
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are no longer maintained since API version 9. You are advised to use [geoLocationManager](js-apis-geoLocationManager.md) instead.


## Modules to Import

```
import geolocation from '@system.geolocation';
```


## Required Permissions

ohos.permission.LOCATION


## geolocation.getLocation<sup>(deprecated)</sup>

getLocation(options?: GetLocationOption): void

Obtains the geographic location.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.getCurrentLocation](js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation).

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetLocationOption](#getlocationoptiondeprecated) | No| Options of a single location request.|

**Example**

```
export default {    
  getLocation() {        
    geolocation.getLocation({            
      success: function(data) {                
        console.info('success get location data. latitude:' + data.latitude);            
      },            
      fail: function(data, code) {                
        console.info('fail to get location. code:' + code + ', data:' + data);            
      }
    });    
  }
}
```


## geolocation.getLocationType<sup>(deprecated)</sup>

getLocationType(options?: GetLocationTypeOption): void

Obtains the supported location types.

> **NOTE**<br>
> This API is deprecated since API version 9. The location subsystem supports only two location types: GNSS positioning and network positioning. No APIs will be provided to query the supported location types.

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetLocationTypeOption](#getlocationtypeoptiondeprecated) | No| Callback used to return the result.|

**Example**

```
export default {    
  getLocationType() {        
    geolocation.getLocationType({            
      success: function(data) {                
        console.info('success get location type:' + data.types[0]);            
      },            
      fail: function(data, code) {                
        console.info('fail to get location. code:' + code + ', data:' + data);            
       },        
     });    
  },
}
```


## geolocation.subscribe<sup>(deprecated)</sup>

subscribe(options: SubscribeLocationOption): void

Listens to the geographic location. If this method is called multiple times, the last call takes effect.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.on('locationChange')](js-apis-geoLocationManager.md#geolocationmanageronlocationchange).

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SubscribeLocationOption](#subscribelocationoptiondeprecated) | Yes| Options for continuous location.|

**Example**

```
export default {    
  subscribe() {        
    geolocation.subscribe({            
      success: function(data) {                
        console.info('get location. latitude:' + data.latitude);            
      },            
      fail: function(data, code) {                
        console.info('fail to get location. code:' + code + ', data:' + data);            
      },        
    });    
  },
}
```


## geolocation.unsubscribe<sup>(deprecated)</sup>

unsubscribe(): void

Cancels listening to the geographic location.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.off('locationChange')](js-apis-geoLocationManager.md#geolocationmanagerofflocationchange).

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Lite

**Example**

```
export default {    
  unsubscribe() {        
    geolocation.unsubscribe();    
  }
}
```


## geolocation.getSupportedCoordTypes<sup>(deprecated)</sup>

getSupportedCoordTypes(): Array&lt;string&gt;

Obtains coordinate system types supported by the device.

> **NOTE**<br>
> This API is deprecated since API version 9. The location subsystem supports only the WGS-84 coordinate system. No APIs will be provided to query the supported coordinate system types.

**System capability**: SystemCapability.Location.Location.Lite

**Return value**

| Type| Not empty| Description|
| -------- | -------- | -------- |
| Array&lt;string&gt; | Yes| Coordinate system types, for example, **[wgs84, gcj02]**.|

**Example**

```
export default {    
  getSupportedCoordTypes() {       
    var types = geolocation.getSupportedCoordTypes();    
  },
}
```

## GetLocationOption<sup>(deprecated)</sup>

Options of a single location request.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.CurrentLocationRequest](js-apis-geoLocationManager.md#CurrentLocationRequest).

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Lite

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeout | number | No| Timeout duration, in ms. The default value is **30000**.<br>The timeout duration is necessary in case the request to obtain the geographic location is rejected for the lack of the required permission, weak positioning signal, or incorrect location settings. After the timeout duration expires, the fail function will be called.<br>The value is a 32-digit positive integer. If the specified value is less than or equal to **0**, the default value will be used.|
| coordType | string | No| Coordinate system type. Available types can be obtained by **getSupportedCoordTypes**. The default type is **wgs84**.|
| success | (data: [GeolocationResponse](#geolocationresponsedeprecated)) => void | No| Called when API call is successful.|
| fail |  (data: string, code: number) => void | No| Called when API call has failed. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void | No| Called when API call is complete.|

**Return value of fail()**

| Error Code| Description|
| -------- | -------- |
| 601 | Failed to obtain the required permission because the user rejected the request.|
| 602 | Permission not declared.|
| 800 | Operation times out due to a poor network condition or GNSS unavailability.|
| 801 | System location disabled.|
| 802 | API called again while the previous execution result is not returned yet.|

## GeolocationResponse<sup>(deprecated)</sup>

Defines the location information, including the longitude, latitude, and location precision.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.Location](js-apis-geoLocationManager.md#location).

**System capability**: SystemCapability.Location.Location.Lite

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| longitude | number | No| No| Longitude.|
| latitude | number | No| No| Latitude.|
| altitude | number | No| No| Altitude.|
| accuracy | number | No| No| Location accuracy.|
| time | number | No| No| Time when the location is obtained.|

## GetLocationTypeOption<sup>(deprecated)</sup>

Defines the location type option, which holds the callback function used to return the query result.

> **NOTE**<br>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Location.Location.Lite

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | (data: [GetLocationTypeResponse](#getlocationtyperesponsedeprecated)) => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

## GetLocationTypeResponse<sup>(deprecated)</sup>

Defines the list of location types supported by the current device

> **NOTE**<br>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Location.Location.Lite

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| types | Array&lt;string&gt; | No| No| Available location types, ['gps', 'network']|

## SubscribeLocationOption<sup>(deprecated)</sup>

Defines the options for continuous location.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.CurrentLocationRequest](js-apis-geoLocationManager.md#locationrequest).

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Lite

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| coordType | string | No| Coordinate system type. Available types can be obtained by **getSupportedCoordTypes**. The default type is **wgs84**.|
| success | (data: [GeolocationResponse](#geolocationresponsedeprecated)) => void | Yes| Called when the geographic location changes.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|

**Return value of fail()**

| Error Code| Description|
| -------- | -------- |
| 601 | Failed to obtain the required permission because the user rejected the request.|
| 602 | Permission not declared.|
| 801 | System location disabled.|
