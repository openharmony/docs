# Network State

> **NOTE**<br>
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
| success | Function | No | Called when the execution is successful. The return value is [FetchResponse](#fetchresponse). |
| fail | Function | No | Called when the operation fails. |
| complete | Function | No | Called when the execution is complete. |

One of the following error codes will be returned if the operation fails.

| Error Code | Description |
| -------- | -------- |
| 602 | The current permission is not declared. |

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
| success | Function | No | Called when the network connection state changes. The return value is [FetchResponse](#fetchresponse). |
| fail | Function | No | Called when the multimedia volume fails to be obtained. |

One of the following error codes will be returned if the listening fails.

| Error Code | Description |
| -------- | -------- |
| 602 | The current permission is not declared. |
| 200 | The subscription fails. |

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


## NetworkResponse

| Name | Type | Description |
| -------- | -------- | -------- |
| metered | boolean | Whether the billing is based on the data volume. |
| type | string | Network type. The value can be **2G**, **3G**, **4G**, **5G**, **WiFi**, or **none**. |