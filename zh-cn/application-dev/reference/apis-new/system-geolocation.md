# @system.geolocation    
本模块仅提供GNSS定位、网络定位等基本功能。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import geolocation from '@system.geolocation';  
    
```  
    
## GeolocationResponse<sup>(deprecated)</sup>    
位置信息，包含经度、纬度、定位精度等信息。    
建议使用ohos.geoLocationManager/geoLocationManager.Location替代。  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| longitude<sup>(3+)</sup> | number | false | true | 设备位置信息：经度。 |  
| latitude<sup>(3+)</sup> | number | false | true | 设备位置信息：纬度。 |  
| altitude<sup>(3+)</sup> | number | false | true | 设备位置信息：海拔。 |  
| accuracy<sup>(3+)</sup> | number | false | true | 设备位置信息：精确度。 |  
| time<sup>(3+)</sup> | number | false | true | 设备位置信息：时间。 |  
    
## GetLocationOption<sup>(deprecated)</sup>    
单次定位请求的配置参数。    
建议使用ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| timeout<sup>(3+)</sup> | number | false | false | 超时时间，单位为ms，默认值为30000。<br/>设置超时，是为了防止出现权限被系统拒绝、定位信号弱或者定位设置不当，导致请求阻塞的情况。超时后会使用fail回调函数。<br/>取值范围为32位正整数。如果设置值小于等于0，系统按默认值处理。 |  
| coordType<sup>(3+)</sup> | string | false | false | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，缺省值为wgs84。 |  
| success<sup>(3+)</sup> | (data: GeolocationResponse) => void | false | false | 接口调用成功的回调函数。 |  
| fail<sup>(3+)</sup> | (data: string, code: number) => void | false | false | 接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(3+)</sup> | () => void | false | false | 接口调用结束的回调函数。 |  
    
## GetLocationTypeResponse<sup>(deprecated)</sup>    
当前设备支持的定位类型列表  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| types<sup>(3+)</sup> | Array<string> | false | true | 可选的定位类型['gps','network']。 |  
    
## GetLocationTypeOption<sup>(deprecated)</sup>    
查询定位类型接口的入参，用于存放回调函数，在查询成功或者失败时接收查询结果。  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(3+)</sup> | (data: GetLocationTypeResponse) => void | false | false | 接口调用成功的回调函数。 |  
| fail<sup>(3+)</sup> | (data: string, code: number) => void | false | false | 接口调用失败的回调函数。 |  
| complete<sup>(3+)</sup> | () => void | false | false | 接口调用结束的回调函数。 |  
    
## SubscribeLocationOption<sup>(deprecated)</sup>    
持续定位请求的配置参数。    
建议使用ohos.geoLocationManager/geoLocationManager.LocationRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| coordType<sup>(3+)</sup> | string | false | false | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，默认值为wgs84。 |  
| success<sup>(3+)</sup> | (data: GeolocationResponse) => void | false | true | 位置信息发生变化的回调函数。 |  
| fail<sup>(3+)</sup> | (data: string, code: number) => void | false | false | 接口调用失败的回调函数。 |  
    
## Geolocation<sup>(deprecated)</sup>    
建议使用ohos.geoLocationManager/geoLocationManager替代。  
 **系统能力:**  SystemCapability.Location.Location.Lite    
### getLocation<sup>(deprecated)</sup>    
单次定位请求的配置参数。  
 **调用形式：**     
- static getLocation(options?: GetLocationOption): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCurrentLocation。  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetLocationOption | false | 单次定位请求的配置参数。 |  
    
 **示例代码：**   
```js    
export default {      
  getLocation() {          
    geolocation.getLocation({              
      success: function(data) {                  
        console.log('success get location data. latitude:' + data.latitude);              
      },              
      fail: function(data, code) {                  
        console.log('fail to get location. code:' + code + ', data:' + data);              
      }  
    });      
  }  
}  
    
```    
  
    
### getLocationType<sup>(deprecated)</sup>    
获取当前设备支持的定位类型。  
 **调用形式：**     
- static getLocationType(options?: GetLocationTypeOption): void  
  
 **废弃说明：** 从API version 9 开始废弃。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetLocationTypeOption | false | 回调函数，用于接收查询结果，或者接收查询失败的结果。 |  
    
 **示例代码：**   
```js    
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
  
    
### subscribe<sup>(deprecated)</sup>    
  
订阅设备的地理位置信息。多次调用的话，只有最后一次的调用生效。  
 **调用形式：**     
- static subscribe(options: SubscribeLocationOption): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:locationChange。  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SubscribeLocationOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### unsubscribe<sup>(deprecated)</sup>    
取消订阅设备的地理位置信息。  
 **调用形式：**     
- static unsubscribe(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:locationChange。  
 **需要权限：** ohos.permission.LOCATION    
 **示例代码：**   
```js    
export default {      
  unsubscribe() {          
    geolocation.unsubscribe();      
  }  
}  
    
```    
  
    
### getSupportedCoordTypes<sup>(deprecated)</sup>    
获取设备支持的坐标系类型。  
 **调用形式：**     
- static getSupportedCoordTypes(): Array\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 表示坐标系类型，如[wgs84,gcj02]。 |  
    
 **示例代码：**   
```js    
export default {      
  getSupportedCoordTypes() {         
    var types = geolocation.getSupportedCoordTypes();      
  },  
}  
    
```    
  
