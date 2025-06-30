# @system.geolocation (地理位置)

本模块仅提供GNSS定位、网络定位等基本功能。

> **说明：**
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 从API Version 9开始，该接口不再维护，推荐使用新接口[geoLocationManager](js-apis-geoLocationManager.md)。


## 导入模块

```
import geolocation from '@system.geolocation';
```


## 权限列表

ohos.permission.LOCATION


## geolocation.getLocation<sup>(deprecated)</sup>

getLocation(options?: GetLocationOption): void

获取设备的地理位置。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getCurrentLocation](js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力：** SystemCapability.Location.Location.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetLocationOption](#getlocationoptiondeprecated) | 否 | 单次定位请求的配置参数。 |

**示例：**

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

获取当前设备支持的定位类型。

> **说明：**<br/>
> 从API version 9开始废弃。位置服务子系统仅支持gnss和network两种定位类型，后续不再提供接口查询支持的定位类型。

**系统能力：** SystemCapability.Location.Location.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetLocationTypeOption](#getlocationtypeoptiondeprecated) | 否 | 回调函数，用于接收查询结果，或者接收查询失败的结果。 |

**示例：**

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

订阅设备的地理位置信息。多次调用的话，只有最后一次的调用生效。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on('locationChange')](js-apis-geoLocationManager.md#geolocationmanageronlocationchange)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力：** SystemCapability.Location.Location.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SubscribeLocationOption](#subscribelocationoptiondeprecated) | 是 | 持续定位的配置参数。 |

**示例：**

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

取消订阅设备的地理位置信息。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off('locationChange')](js-apis-geoLocationManager.md#geolocationmanagerofflocationchange)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力：** SystemCapability.Location.Location.Lite

**示例：**

```
export default {    
  unsubscribe() {        
    geolocation.unsubscribe();    
  }
}
```


## geolocation.getSupportedCoordTypes<sup>(deprecated)</sup>

getSupportedCoordTypes(): Array&lt;string&gt;

获取设备支持的坐标系类型。

> **说明：**<br/>
> 从API version 9开始废弃。位置服务子系统仅支持WGS-84坐标系，后续不再提供接口查询支持的坐标系类型。

**系统能力：** SystemCapability.Location.Location.Lite

**返回值：**

| 类型 | 非空 | 说明 |
| -------- | -------- | -------- |
| Array&lt;string&gt; | 是 | 表示坐标系类型，如[wgs84,&nbsp;gcj02]。 |

**示例：**

```
export default {    
  getSupportedCoordTypes() {       
    var types = geolocation.getSupportedCoordTypes();    
  },
}
```

## GetLocationOption<sup>(deprecated)</sup>

单次定位请求的配置参数。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.CurrentLocationRequest](js-apis-geoLocationManager.md#currentlocationrequest)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Lite

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeout | number | 否 | 超时时间，单位为ms，默认值为30000。<br/>设置超时，是为了防止出现权限被系统拒绝、定位信号弱或者定位设置不当，导致请求阻塞的情况。超时后会使用fail回调函数。<br/>取值范围为32位正整数。如果设置值小于等于0，系统按默认值处理。 |
| coordType | string | 否 | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，缺省值为wgs84。 |
| success | (data: [GeolocationResponse](#geolocationresponsedeprecated)) => void | 否 | 接口调用成功的回调函数。 |
| fail |  (data: string, code: number) => void | 否 | 接口调用失败的回调函数。data为错误信息，code为错误码。 |
| complete | () => void | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 601 | 获取定位权限失败，失败原因：用户拒绝。 |
| 602 | 权限未声明。 |
| 800 | 超时，失败原因：网络状况不佳或GNSS不可用。 |
| 801 | 系统位置开关未打开。 |
| 802 | 该次调用结果未返回前接口又被重新调用，该次调用失败返回错误码。 |

## GeolocationResponse<sup>(deprecated)</sup>

位置信息，包含经度、纬度、定位精度等信息。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.Location](js-apis-geoLocationManager.md#location)替代。

**系统能力**：SystemCapability.Location.Location.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| longitude | number | 否 | 否 | 设备位置信息：经度。 |
| latitude | number | 否 | 否 | 设备位置信息：纬度。 |
| altitude | number | 否 | 否 | 设备位置信息：海拔。 |
| accuracy | number | 否 | 否 | 设备位置信息：精确度。 |
| time | number | 否 | 否 | 设备位置信息：时间。 |

## GetLocationTypeOption<sup>(deprecated)</sup>

查询定位类型接口的入参，用于存放回调函数，在查询成功或者失败时接收查询结果。

> **说明：**<br/>
> 从API version 9开始废弃。

**系统能力**：SystemCapability.Location.Location.Lite

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | (data: [GetLocationTypeResponse](#getlocationtyperesponsedeprecated)) => void | 否 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 接口调用失败的回调函数。 |
| complete | () => void | 否 | 接口调用结束的回调函数。 |

## GetLocationTypeResponse<sup>(deprecated)</sup>

当前设备支持的定位类型列表

> **说明：**<br/>
> 从API version 9开始废弃。

**系统能力**：SystemCapability.Location.Location.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| types | Array&lt;string&gt; | 否 | 否 | 可选的定位类型['gps',&nbsp;'network']。 |

## SubscribeLocationOption<sup>(deprecated)</sup>

持续定位请求的配置参数。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.CurrentLocationRequest](js-apis-geoLocationManager.md#currentlocationrequest)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Lite

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| coordType | string | 否 | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，默认值为wgs84。 |
| success | (data: [GeolocationResponse](#geolocationresponsedeprecated)) => void | 是 | 位置信息发生变化的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 接口调用失败的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 601 | 获取定位权限失败，失败原因：用户拒绝。 |
| 602 | 权限未声明。 |
| 801 | 系统位置开关未打开。 |
