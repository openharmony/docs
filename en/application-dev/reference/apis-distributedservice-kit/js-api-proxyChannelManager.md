# @ohos.distributedsched.proxyChannelManager (Proxy Channel Management)

DSoftBus provides stable and reliable underlying channels for cross-device communication. This module is developed based on DSoftBus. It supports efficient data exchange between phones and wearables, providing users with a seamless device interconnection experience. The core functions of this module include proxy channel management, data route management, application state awareness and wakeup, and link state monitoring.

- Proxy channel management: Manages bidirectional data channels established between phones and wearables via the Bluetooth Basic Rate (BR) protocol.

- Data route management: Accurately forwards data of wearables based on the specified service UUID.

- Application state awareness and wakeup: After a proxy channel is enabled, dynamically analyzes and wakes up the corresponding application process on the phone after receiving data sent by the wearable.

- Link state monitoring: Monitors the channel connection state in real time through callback.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs are currently in the beta phase and not available for application.

## Modules to Import

```js
import { proxyChannelManager } from '@kit.DistributedServiceKit';
```

## How to Use

Before calling the APIs of this module, complete the following configurations:

1. Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

2. For application processes that need to be started by proxy, set the **action** field to **action.ohos.pull.listener** in the **module.json5** file.

## proxyChannelManager.openProxyChannel

openProxyChannel(channelInfo:&nbsp;ChannelInfo):&nbsp;Promise&lt;number&gt;

Opens a proxy channel. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| channelInfo | [ChannelInfo](#channelinfo) | Yes   | Channel information, including the MAC address and service UUID of the peer device. |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| &nbsp;Promise&lt;number&gt; | Channel ID of the proxy channel. The value range is [1, 2147483647]. The lifecycle of **channelId** is the same as that of the proxy channel. If the proxy is not closed, the returned **channelId** is the same as that passed in the API.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390001      | BR is disabled.|
| 32390002 | Device not paired.  |
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|
| 32390102 | Operation failed or Connection timed out.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          let channelInfo: proxyChannelManager.ChannelInfo = {
            linkType: proxyChannelManager.LinkType.LINK_BR,
            peerDevAddr: "xx:xx:xx:xx:xx:xx", // Bluetooth MAC address of the wearable
            peerUuid: "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx", // Service UUID of the peer device
          };
          // The following sample code uses try/catch as an example.
          try {
            proxyChannelManager.openProxyChannel(channelInfo)
              .then((channelId: number) => {
                // Obtain the channel ID.
              })
              .catch((error: BusinessError) => {
                console.error(`getErr: ${error.code} ${error.message}`);
              });
          } catch (err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
            // If code:undefined message:"Cannot read property openProxyChannel of undefined" is displayed, this API is not supported in the current image.
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.closeProxyChannel

closeProxyChannel(channelId:&nbsp;number):&nbsp;void

Closes a proxy channel that has been opened.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          // The following sample code uses try/catch as an example.
          try {
            proxyChannelManager.closeProxyChannel(1); // Assume that the channel ID is 1.
          } catch (err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
            // If code:undefined message:"Cannot read property closeProxyChannel of undefined" is displayed, this API is not supported in the current image.
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.sendData

sendData(channelId:number, data:ArrayBuffer):Promise&lt;void&gt;

Sends data to the peer end. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|
| data      | ArrayBuffer | Yes| Byte message sent to the peer end. The maximum length is 4096 bytes.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| &nbsp;Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|
| 32390103 | Data too long.|
| 32390104 | Send failed.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          const data = new ArrayBuffer(10); // Create an ArrayBuffer with a length of 10.
          try {
            proxyChannelManager.sendData(1, data) // Assume that the channel ID is 1.
              .then(() => {
              })
              .catch((error: BusinessError) => {
                console.error(`getErr: ${error.code} ${error.message}`);
              });
          }catch (err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.on('receiveData')

on(type:&nbsp;'receiveData', channelId:&nbsp;number, callback:&nbsp;Callback&lt;DataInfo&gt;):&nbsp;void

Subscribes to data receiving events. This API returns the result asynchronously through a callback.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type      | string | Yes| Event type. The value **receiveData** indicates the data receiving event.|
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|
| callback  | Callback&lt;[DataInfo](#datainfo)&gt; | Yes| Callback used to return the received data. If the callback function is registered multiple times, only the last registered one takes effect.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          const receiveDataCallback = (dataInfo: proxyChannelManager.DataInfo) => {
          };
          try{
            proxyChannelManager.on('receiveData', 1, receiveDataCallback); // Assume that the channel ID is 1.
          } catch(err) {
            let error = err as BusinessError;
            console.error(`register receiveData error: ${error.code} ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.off('receiveData')

off(type:&nbsp;'receiveData', channelId:&nbsp;number, callback?:&nbsp;Callback&lt;DataInfo&gt;):&nbsp;void

Unsubscribes from data receiving events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type      | string | Yes| Event type. The value **receiveData** indicates the data receiving event.|
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|
| callback  | Callback&lt;[DataInfo](#datainfo)&gt; | No| Registered callback.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          try{
            proxyChannelManager.off('receiveData', 1); // Assume that the channel ID is 1.
          } catch(err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.on('channelStateChange')

on(type:&nbsp;'channelStateChange', channelId:&nbsp;number, callback:&nbsp;Callback&lt;ChannelStateInfo&gt;):&nbsp;void

Subscribes to channel state change events. This API returns the result asynchronously through a callback.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type      | string | Yes| Event type. The value **channelStateChange** indicates the channel state change event.|
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|
| callback  | Callback&lt;[ChannelStateInfo](#channelstateinfo)&gt; | Yes| Callback used to return the received channel state. If the callback function is registered multiple times, only the last registered one takes effect.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          const receiveStatusCallback = (channelStateInfo: proxyChannelManager.ChannelStateInfo) => {
          };
          try{
            proxyChannelManager.on ('channelStateChange', 1, receiveStatusCallback); // Assume that the channel ID is 1.
          } catch(err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## proxyChannelManager.off('channelStateChange')

off(type:&nbsp;'channelStateChange', channelId:&nbsp;number, callback?:&nbsp;Callback&lt;ChannelStateInfo&gt;):&nbsp;void

Unsubscribes from channel state change events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type      | string | Yes| Event type. The value **channelStateChange** indicates the channel state change event.|
| channelId | number | Yes   | Channel ID obtained when the proxy channel is opened.|
| callback  | Callback&lt;[ChannelStateInfo](#channelstateinfo)&gt; | No| Registered callback.|

**Error codes**

For details about the following error codes, see [Proxy Channel Management Error Codes](errorcode_proxyChannelManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 32390004 | ChannelId is invalid or unavailable.|
| 32390006 | Parameter error.|
| 32390100 | Internal error.|
| 32390101 | Call is restricted.|

**Example**

```ts
import proxyChannelManager from '@ohos.distributedsched.proxyChannelManager';
import { BusinessError } from '@ohos.base';
@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Button ('Test')
        .onClick(() => {
          try{
            proxyChannelManager.off('channelStateChange', 1); // Assume that the channel ID is 1.
          } catch(err) {
            let error = err as BusinessError;
            console.error(`getErr: ${error.code} ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## DataInfo

Represents the received data, including the channel ID and data.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type                                      | Read-Only  | Optional  | Description      |
| --------- | ---------------------------------------- | ---- | ---- | -------- |
| channelId | number | No| No   | Channel ID of the proxy channel.|
| data | ArrayBuffer | No| No| Received byte array.|

## ChannelInfo

Represents the proxy channel information, including the MAC address and service UUID of the peer device.

| Name      | Type                                      | Read-Only  | Optional  | Description      |
| --------- | ---------------------------------------- | ---- | ---- | -------- |
| linkType | [LinkType](#linktype) | No| No   | Link type of the proxy channel.|
| peerDevAddr | string | No| No| MAC address of the peer device.|
| peerUuid | string | No| No| Service UUID of the peer device.|

## ChannelStateInfo

Represents the connection state information of the proxy channel.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type                                      | Read-Only  | Optional  | Description      |
| --------- | ---------------------------------------- | ---- | ---- | -------- |
| channelId | number | No| No   | Channel ID of the proxy channel.|
| state | [ChannelState](#channelstate) | No| No| Connection state of the proxy channel.|

## ChannelState

Enumerates the connection states of the proxy channel.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Value                                      | Description      |
| --------- | ---------------------------------------- |  -------- |
| CHANNEL_WAIT_RESUME | 0 | The connection is disconnected, and the channel is unavailable.|
| CHANNEL_RESUME | 1 | The connection is restored, and the channel is available.|
| CHANNEL_EXCEPTION_SOFTWARE_FAILED | 2 | The channel is unavailable due to other software errors.|
| CHANNEL_BR_NO_PAIRED | 3 | The Bluetooth pairing relationship is deleted, and the channel is unavailable.|

## LinkType

Enumerates the link types.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Value                                      | Description      |
| --------- | ---------------------------------------- |  -------- |
| LINK_BR | 0 | Bluetooth.|
