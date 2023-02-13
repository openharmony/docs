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

getLocation(Object): void

Obtains the geographic location.

> **NOTE**
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.getCurrentLocation](js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation).

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeout | number | No| Timeout duration, in ms. The default value is **30000**.<br>The timeout duration is necessary in case the request to obtain the geographic location is rejected for the lack of the required permission, weak positioning signal, or incorrect location settings. After the timeout duration expires, the fail function will be called.<br>The value is a 32-digit positive integer. If the specified value is less than or equal to **0**, the default value will be used.|
| coordType | string | No| Coordinate system type. Available types can be obtained by **getSupportedCoordTypes**. The default type is **wgs84**.|
| success | Function | No| Called when API call is successful.|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when API call is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| longitude | number | Longitude.|
| latitude | number | Latitude.|
| altitude | number | Altitude.|
| accuracy | number | Location accuracy.|
| time | number | Time when the location is obtained.|

**Return value of fail()**

| Error Code| Description|
| -------- | -------- |
| 601 | Failed to obtain the required permission because the user rejected the request.|
| 602 | Permission not declared.|
| 800 | Operation times out due to a poor network condition or GNSS unavailability.|
| 801 | System location disabled.|
| 802 | API called again while the previous execution result is not returned yet.|

**Example**

```
export default {    
  getLocation() {        
    geolocation.getLocation({            
      success: function(data) {                
        console.log('success get location data. latitude:' + data.latitude);            
      },            
      fail: function(data, code) {                
        console.log('fail to get location. code:' + code + ', data:' + data);            
      },
    });    
  },
}
```


## geolocation.getLocationType<sup>(deprecated)</sup>

getLocationType(Object): void

Obtains the supported location types.

> **NOTE**
> This API is deprecated since API version 9. The location subsystem supports only two location types: GPS positioning and network positioning. No APIs will be provided to query the supported location types.

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when API call is successful.|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when API call is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| types | Array&lt;string&gt; | Available location types, ['gps', 'network']|

**Example**

```
export default {    
  getLocationType() {        
    geolocation.getLocationType({            
      success: function(data) {                
        console.log('success get location type:' + data.types[0]);            
      },            
      fail: function(data, code) {                
        console.log('fail to get location. code:' + code + ', data:' + data);            
       },        
     });    
  },
}
```


## geolocation.subscribe<sup>(deprecated)</sup>

subscribe(Object): void

Listens to the geographic location. If this method is called multiple times, the last call takes effect.

> **NOTE**
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.on('locationChange')](js-apis-geoLocationManager.md#geolocationmanageronlocationchange).

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| coordType | string | No| Coordinate system type. Available types can be obtained by **getSupportedCoordTypes**. The default type is **wgs84**.|
| success | Function | Yes| Called when the geographic location changes.|
| fail | Function | No| Called when API call has failed.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| longitude | number | Longitude.|
| latitude | number | Latitude.|
| altitude | number | Altitude.|
| accuracy | number | Location accuracy.|
| time | number | Time when the location is obtained.|

**Return value of fail()**

| Error Code| Description|
| -------- | -------- |
| 601 | Failed to obtain the required permission because the user rejected the request.|
| 602 | Permission not declared.|
| 801 | System location disabled.|

**Example**

```
export default {    
  subscribe() {        
    geolocation.subscribe({            
      success: function(data) {                
        console.log('get location. latitude:' + data.latitude);            
      },            
      fail: function(data, code) {                
        console.log('fail to get location. code:' + code + ', data:' + data);            
      },        
    });    
  },
}
```


## geolocation.unsubscribe<sup>(deprecated)</sup>

unsubscribe(): void

Cancels listening to the geographic location.

> **NOTE**
> This API is deprecated since API version 9. You are advised to use [geoLocationManager.off('locationChange')](js-apis-geoLocationManager.md#geolocationmanagerofflocationchange).

**System capability**: SystemCapability.Location.Location.Lite

**Example**

```
export default {    
  unsubscribe() {        
    geolocation.unsubscribe();    
  },
}
```


## geolocation.getSupportedCoordTypes<sup>(deprecated)</sup>

getSupportedCoordTypes(): Array&lt;string&gt;

Obtains coordinate system types supported by the device.

> **NOTE**
> This API is deprecated since API version 9. The location subsystem supports only the wgs84 coordinate system. No APIs will be provided to query the supported coordinate system types.

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
