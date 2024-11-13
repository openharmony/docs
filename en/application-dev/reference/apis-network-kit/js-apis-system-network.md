# @system.network (Network State)

> **NOTE**
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are no longer maintained since API version 8. You are advised to use ['@ohos.net.connection'](js-apis-net-connection.md).

## Modules to Import


```
import network from '@system.network';
```


## Required Permissions

ohos.permission.GET_WIFI_INFO

ohos.permission.GET_NETWORK_INFO


## network.getType<sup>3+</sup>

getType(options?: {<br>
&nbsp;&nbsp;success?: (data: NetworkResponse) => void;<br>
&nbsp;&nbsp;fail?: (data: any, code: number) => void;<br>
&nbsp;&nbsp;complete?: () => void;<br>
}): void

Obtains the network type of this device.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the API call is successful. The return value is defined by [NetworkResponse](#networkresponse3).|
| fail | Function | No| Called when an API call fails.|
| complete | Function | No| Called when an API call is complete.|

Error codes:

| Error Code| Description|
| -------- | -------- |
| 602 | The current permission is not declared.|

**Example**

```
export default class Network {
  getType() {
    network.getType({
      success: (data) => {
        console.log('success get network type:' + data.type);
      }
    });
  }
}
```


## network.subscribe<sup>3+</sup>

subscribe(options?:{<br>
&nbsp;&nbsp;success?: (data: NetworkResponse) => void;<br>
&nbsp;&nbsp;fail?: (data: any, code: number) => void;<br>
  }): void

Listens to the network connection state of this device. If this API is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the network state changes. The return value is defined by [NetworkResponse](#networkresponse3).|
| fail | Function | No| Called when an API call fails.|

Error codes:

| Error Code| Description|
| -------- | -------- |
| 602 | The current permission is not declared.|
| 200 | Subscription failed.|

**Example**

```
export default class Network {
  subscribe() {
    network.subscribe({
      success: (data) => {
        console.log('success get network type:' + data.type);
      }
    });
  }
}
```


## network.unsubscribe<sup>3+</sup>

unsubscribe(): void

Cancels listening to the network connection state of this device.

**System capability**: SystemCapability.Communication.NetManager.Core

**Example**

```
import network from '@system.network';

network.unsubscribe();
```


## NetworkResponse<sup>3+</sup>

**System capability**: SystemCapability.Communication.NetManager.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| metered | boolean | No|Whether to charge by traffic.|
| type | string | Yes|Network type. The value can be **2G**, **3G**, **4G**, **5G**, **WiFi**, or **none**.|
