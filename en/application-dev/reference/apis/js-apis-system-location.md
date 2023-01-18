# Geographic Location

> **NOTE**
> - The APIs of this module are no longer maintained since API version 7. You are advised to use [`@ohos.geolocation`](js-apis-geolocation.md).
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import geolocation from '@system.geolocation';
```


## Required Permissions

ohos.permission.LOCATION


## geolocation.getLocation

getLocation(Object): void

Obtains the geographic location.

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Parameter | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| timeout | number | No | Timeout&nbsp;duration,&nbsp;in&nbsp;milliseconds.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**30000**.<br>The&nbsp;timeout&nbsp;duration&nbsp;is&nbsp;necessary&nbsp;in&nbsp;case&nbsp;the&nbsp;request&nbsp;to&nbsp;obtain&nbsp;the&nbsp;geographic&nbsp;location&nbsp;is&nbsp;rejected&nbsp;for&nbsp;the&nbsp;lack&nbsp;of&nbsp;the&nbsp;required&nbsp;permission,&nbsp;weak&nbsp;positioning&nbsp;signal,&nbsp;or&nbsp;incorrect&nbsp;location&nbsp;settings.&nbsp;After&nbsp;the&nbsp;timeout&nbsp;duration&nbsp;expires,&nbsp;the&nbsp;fail&nbsp;function&nbsp;will&nbsp;be&nbsp;called.<br>The&nbsp;value&nbsp;is&nbsp;a&nbsp;32-digit&nbsp;positive&nbsp;integer.&nbsp;If&nbsp;the&nbsp;value&nbsp;set&nbsp;is&nbsp;less&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;**0**,&nbsp;the&nbsp;default&nbsp;value&nbsp;will&nbsp;be&nbsp;used. |
| coordType | string | No | Coordinate&nbsp;system&nbsp;type.&nbsp;Available&nbsp;types&nbsp;can&nbsp;be&nbsp;obtained&nbsp;by&nbsp;**getSupportedCoordTypes**.&nbsp;The&nbsp;default&nbsp;type&nbsp;is&nbsp;**wgs84**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following values will be returned when the operation is successful.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| longitude | number | Longitude |
| latitude | number | Latitude |
| altitude | number | Altitude |
| accuracy | number | Location&nbsp;accuracy |
| time | number | Time&nbsp;when&nbsp;the&nbsp;location&nbsp;is&nbsp;obtained |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 601 | Failed&nbsp;to&nbsp;obtain&nbsp;the&nbsp;required&nbsp;permission&nbsp;because&nbsp;the&nbsp;user&nbsp;rejected&nbsp;the&nbsp;request. |
| 602 | Permission&nbsp;not&nbsp;declared. |
| 800 | Operation&nbsp;times&nbsp;out&nbsp;due&nbsp;to&nbsp;a&nbsp;poor&nbsp;network&nbsp;condition&nbsp;or&nbsp;unavailable&nbsp;GPS. |
| 801 | System&nbsp;location&nbsp;disabled. |
| 802 | The&nbsp;method&nbsp;is&nbsp;called&nbsp;again&nbsp;while&nbsp;the&nbsp;previous&nbsp;execution&nbsp;result&nbsp;is&nbsp;not&nbsp;returned&nbsp;yet. |

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


## geolocation.getLocationType

getLocationType(Object): void

Obtains the supported location types.

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Parameter | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following values will be returned when the operation is successful.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| types | Array&lt;string&gt; | Available&nbsp;location&nbsp;types,&nbsp;['gps',&nbsp;'network'] |

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


## geolocation.subscribe

subscribe(Object): void

Listens to the geographical location. If this method is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Location.Location.Lite

**Parameters**

| Parameter | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| coordType | string | No | Coordinate&nbsp;system&nbsp;type.&nbsp;Available&nbsp;types&nbsp;can&nbsp;be&nbsp;obtained&nbsp;by&nbsp;**getSupportedCoordTypes**.&nbsp;The&nbsp;default&nbsp;type&nbsp;is&nbsp;**wgs84**. |
| success | Function | Yes | Called&nbsp;when&nbsp;the&nbsp;geographical&nbsp;location&nbsp;changes |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;listening&nbsp;fails |

The following values will be returned when the network type is obtained.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| longitude | number | Longitude |
| latitude | number | Latitude |
| altitude | number | Altitude |
| accuracy | number | Location&nbsp;accuracy |
| time | number | Time&nbsp;when&nbsp;the&nbsp;location&nbsp;is&nbsp;obtained |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 601 | Failed&nbsp;to&nbsp;obtain&nbsp;the&nbsp;required&nbsp;permission&nbsp;because&nbsp;the&nbsp;user&nbsp;rejected&nbsp;the&nbsp;request. |
| 602 | Permission&nbsp;not&nbsp;declared. |
| 801 | System&nbsp;location&nbsp;disabled. |

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


## geolocation.unsubscribe

unsubscribe(): void

Cancels listening to the geographical location.

**System capability**: SystemCapability.Location.Location.Lite

**Example**

```
export default {    
  unsubscribe() {        
    geolocation.unsubscribe();    
  },
}
```


## geolocation.getSupportedCoordTypes

getSupportedCoordTypes(): Array&lt;string&gt;

Obtains coordinate system types supported by the device.

**System capability**: SystemCapability.Location.Location.Lite

**Return Value**

| Type | Non-Null | Description |
| -------- | -------- | -------- |
| Array&lt;string&gt; | Yes | Coordinate&nbsp;system&nbsp;types,&nbsp;for&nbsp;example,&nbsp;**[wgs84,&nbsp;gcj02]**. |

**Example**

```
export default {    
  getSupportedCoordTypes() {       
    var types = geolocation.getSupportedCoordTypes();    
  },
}
```
