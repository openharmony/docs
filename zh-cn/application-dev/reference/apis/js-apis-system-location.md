# @system.geolocation (地理位置)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口[`@ohos.geolocation`](js-apis-geolocation.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import geolocation from '@system.geolocation';
```


## 权限列表

ohos.permission.LOCATION


## geolocation.getLocation

getLocation(Object): void

获取设备的地理位置。

**系统能力：** SystemCapability.Location.Location.Lite

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeout | number | 否 | 超时时间，单位为ms，默认值为30000。<br/>设置超时，是为了防止出现权限被系统拒绝、定位信号弱或者定位设置不当，导致请求阻塞的情况。超时后会使用fail回调函数。<br/>取值范围为32位正整数。如果设置值小于等于0，系统按默认值处理。 |
| coordType | string | 否 | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，缺省值为wgs84。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| longitude | number | 设备位置信息：经度。 |
| latitude | number | 设备位置信息：纬度。 |
| altitude | number | 设备位置信息：海拔。 |
| accuracy | number | 设备位置信息：精确度。 |
| time | number | 设备位置信息：时间。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 601 | 获取定位权限失败，失败原因：用户拒绝。 |
| 602 | 权限未声明。 |
| 800 | 超时，失败原因：网络状况不佳或GPS不可用。 |
| 801 | 系统位置开关未打开。 |
| 802 | 该次调用结果未返回前接口又被重新调用，该次调用失败返回错误码。 |

**示例：**

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

获取当前设备支持的定位类型。

**系统能力：** SystemCapability.Location.Location.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| types | Array&lt;string&gt; | 可选的定位类型['gps',&nbsp;'network']。 |

**示例：**

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

订阅设备的地理位置信息。多次调用的话，只有最后一次的调用生效。

**系统能力：** SystemCapability.Location.Location.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| coordType | string | 否 | 坐标系的类型，可通过getSupportedCoordTypes获取可选值，默认值为wgs84。 |
| success | Function | 是 | 位置信息发生变化的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| longitude | number | 设备位置信息：经度。 |
| latitude | number | 设备位置信息：纬度。 |
| altitude | number | 设备位置信息：海拔。 |
| accuracy | number | 设备位置信息：精确度。 |
| time | number | 设备位置信息：时间。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 601 | 获取定位权限失败，失败原因：用户拒绝。 |
| 602 | 权限未声明。 |
| 801 | 系统位置开关未打开。 |

**示例：**

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

取消订阅设备的地理位置信息。

**系统能力：** SystemCapability.Location.Location.Lite

**示例：**

```
export default {    
  unsubscribe() {        
    geolocation.unsubscribe();    
  },
}
```


## geolocation.getSupportedCoordTypes

getSupportedCoordTypes(): Array&lt;string&gt;

获取设备支持的坐标系类型。

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