# @system.network (Network State)

> **NOTE**
> - The APIs of this module are no longer maintained since API version 7. You are advised to use [`@ohos.telephony.observer`](js-apis-observer.md).
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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the API call is successful. The return value is defined by [NetworkResponse](#networkresponse).|
| fail | Function | No| Called when API call has failed.|
| complete | Function | No| Called when the API call is complete.|

One of the following error codes will be returned if the API call has failed.

| Error Code| Description|
| -------- | -------- |
| 602 | The current permission is not declared.|

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the network state changes. The return value is defined by [NetworkResponse](#networkresponse).|
| fail | Function | No| Called when API call has failed.|

One of the following error codes will be returned if the API call has failed.

| Error Code| Description|
| -------- | -------- |
| 602 | The current permission is not declared.|
| 200 | Subscription failed.|

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

**System capability**: SystemCapability.Communication.NetManager.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| metered | boolean | No|Whether to charge by traffic.|
| type | string | Yes|Network type. The value can be **2G**, **3G**, **4G**, **5G**, **WiFi**, or **none**.|
