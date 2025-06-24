# @ohos.multimodalawareness.roomLocation (Room Location)

The **roomLocation** module provides the capability of room-level location.

> **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { roomLocation } from '@kit.MultimodalAwarenessKit';
```

## RoomLocateResponse

Defines the room result.

**System capability**: SystemCapability.MultimodalAwareness.RoomLocation

| Name               | Type   | Description                  |
| ------------------- | ----   | ---------------------- |
| roomId              | string |  room id.|
| errorCode           | int    | error code.|




## roomLocation.on('roomLocation')

 on(type: 'roomLocation', callback: Callback&lt;RoomLocateResponse&gt;): void;

Subscribe to room location events.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.MultimodalAwareness.RoomLocation

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. |
| callback | Callback&lt;[RoomLocateResponse](#roomlocateresponse)&gt; | Yes  | Callback used to return the room location result.                                  |

**Error codes**

For details about the error codes, see [Room Location Error Codes](errorcode-roomLocation.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800001 | Service exception.                                           |
| 33800002 | Subscription failed.                                            |

**Example**

```ts
roomLocation.on('roomLocation', (data:roomLocation.RoomLocateResponse) => {
    console.info('on success' + data);
})
```



## roomLocation.off('roomLocation')

off(type: 'roomLocation', callback?: Callback&lt;RoomLocateResponse&gt;): void;

Unsubscribes from room location events.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.MultimodalAwareness.RoomLocation

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. |
| callback | Callback&lt;[RoomLocateResponse](#roomlocateresponse)&gt; | No  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Room Location Error Codes](errorcode-roomLocation.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission check denied. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800001 | Service exception.                                           |
| 33800003 | UnSubscription failed.                                          |

**Example**

```ts
roomLocation.off('roomLocation', (data:roomLocation.RoomLocateResponse) => {
    console.info('off success' + data);
})
```



## roomLocation.setDevicesInfos()

setDevicesInfos(devicesInfos: string): Promise<boolean>;

Set devices informations.

**System capability**: SystemCapability.MultimodalAwareness.RoomLocation

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| devicesInfos| string                           | Yes  | devices informations. |

**Error codes**

For details about the error codes, see [Room Location Error Codes](errorcode-roomLocation.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission check denied. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800004 | Failed to set device information.                                           |

**Example**

```ts
const jsonstr: string = '[{"mac":"11:11:11:11:11:11","roomId":"1","prodId":"1","devId":"1","power":"","type":"1"}]';
roomLocation.setDevicesInfos(jsonstr);
```



## roomLocation.getRoomLocationResult()

getRoomLocationResult(): RoomLocateResponse;

Obtains the room location result.

**System capability**: SystemCapability.MultimodalAwareness.RoomLocation

**Error codes**

For details about the error codes, see [Room Location Error Codes](errorcode-roomLocation.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500005 | Failed to obtain room-level location information.                                           |

**Example**

```ts
@state roomResult: roomLocation.RoomLocateResponse = { roomId: "-1", errorCode: -1 };
this.roomResult = roomLocation.getRoomLocationResult();
console.info('get success' + this.roomResult);
```
