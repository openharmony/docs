# Network State

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 7. It is recommended that you use [`@ohos.telephony.observer`](js-apis-observer.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import network from '@system.network';
```


## Required Permissions

ohos.permission.GET_WIFI_INFO

ohos.permission.GET_NETWORK_INFO


## network.getType

getType(Object): void

Obtains the network type.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following value will be returned when the multimedia volume is obtained.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| metered | boolean | Whether&nbsp;the&nbsp;billing&nbsp;is&nbsp;based&nbsp;on&nbsp;the&nbsp;data&nbsp;volume. |
| type | string | Network&nbsp;type.&nbsp;The&nbsp;value&nbsp;can&nbsp;be&nbsp;**2G**,&nbsp;**3G**,&nbsp;**4G**,&nbsp;**5G**,&nbsp;**WiFi**,&nbsp;or&nbsp;**none**. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 602 | The&nbsp;current&nbsp;permission&nbsp;is&nbsp;not&nbsp;declared. |

**Example**

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

Listens to the network connection state. If this method is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;network&nbsp;connection&nbsp;state&nbsp;changes |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;multimedia&nbsp;volume&nbsp;fails&nbsp;to&nbsp;be&nbsp;obtained. |

The following value will be returned when the multimedia volume is obtained.

| Parameter | Type | Description |
| -------- | -------- | -------- |
| metered | boolean | Whether&nbsp;the&nbsp;billing&nbsp;is&nbsp;based&nbsp;on&nbsp;the&nbsp;data&nbsp;volume. |
| type | string | Network&nbsp;type.&nbsp;The&nbsp;value&nbsp;can&nbsp;be&nbsp;**2G**,&nbsp;**3G**,&nbsp;**4G**,&nbsp;**5G**,&nbsp;**WiFi**,&nbsp;or&nbsp;**none**. |

One of the following error codes will be returned if the listening fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 602 | The&nbsp;current&nbsp;permission&nbsp;is&nbsp;not&nbsp;declared. |
| 200 | The&nbsp;subscription&nbsp;fails. |

**Example**

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

Cancels listening to the network connection state.

**System capability**: SystemCapability.Communication.NetManager.Core

**Example**

```
export default {    
  unsubscribe() {        
    network.unsubscribe();    
  },
}
```