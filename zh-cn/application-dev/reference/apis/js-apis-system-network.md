# @system.network (网络状态)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口[`@ohos.telephony.observer`](js-apis-observer.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import network from '@system.network';
```


## 权限列表

ohos.permission.GET_WIFI_INFO

ohos.permission.GET_NETWORK_INFO


## network.getType

getType(Object): void

获取当前设备的网络类型。

**系统能力：** SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| metered | boolean | 是否按照流量计费。 |
| type | string | 网络类型，可能的值有2g，3g，4g，5g，wifi，none等。 |

fail返回值：

| 错误码 | 说明 |
| -------- | -------- |
| 602 | 当前权限未声明。 |

**示例：**

```
export default {    
  getType() {        
    network.getType({            
      success: function(data) {                
        console.log('success get network type:' + data.type);            
      },            
      fail: function(data, code) {                
        console.log('fail to get network type code:' + code + ', data:' + data);            
      },
    });    
  },
}
```


## network.subscribe

subscribe(Object): void

订阅当前设备的网络连接状态。如果多次调用，会覆盖前一次调用。

**系统能力：** SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 网络发生变化的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| metered | boolean | 是否按照流量计费。 |
| type | string | 网络类型，可能的值为2g，3g，4g，5g，wifi，none。 |

fail返回值：

| 错误码 | 说明 |
| -------- | -------- |
| 602 | 当前权限未声明。 |
| 200 | 订阅失败。 |

**示例：**

```
export default {    
  subscribe() {        
    network.subscribe({            
      success: function(data) {                
        console.log('network type change type:' + data.type);            
      },            
      fail: function(data, code) {                
        console.log('fail to subscribe network, code:' + code + ', data:' + data);            
      },
    });    
  },
}
```


## network.unsubscribe

unsubscribe(): void

取消订阅设备的网络连接状态。

**系统能力：** SystemCapability.Communication.NetManager.Core

**示例：**

```
export default {    
  unsubscribe() {        
    network.unsubscribe();    
  },
}
```