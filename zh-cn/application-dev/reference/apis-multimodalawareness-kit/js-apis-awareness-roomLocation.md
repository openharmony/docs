# @ohos.multimodalawareness.roomLocation (房间级定位)

本模块，提供对房间级定位能力。

> **说明：**
>
> 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { roomLocation } from '@kit.MultimodalAwarenessKit';
```

## RoomLocateResponse

房间级定位结果。

**系统能力**：SystemCapability.MultimodalAwareness.RoomLocation

| 名称                | 类型   | 说明                   |
| ------------------- | ----   | ---------------------- |
| roomId              | string | 房间ID.|
| errorCode           | int    | 错误码.|




## roomLocationon('roomLocation')

 on(type: 'roomLocation', callback: Callback&lt;RoomLocateResponse&gt;): void;

订阅房间级定位事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.RoomLocation

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为"roomLocation"表示房间级定位。 |
| callback | Callback&lt;[RoomLocateResponse](#roomlocateresponse)&gt; | 是   | 回调函数，返回定位结果。                                   |

**错误码**：

以下错误码的详细介绍请参见[房间级定位错误码](errorcode-roomLocation.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800001 | Service exception.                                           |
| 33800002 | Subscription failed.                                            |

**示例**：

```ts
roomLocation.on('roomLocation', (data:roomLocation.RoomLocateResponse) => {
    console.info('on success' + data);
})
```



## roomLocation.off('roomLocation')

off(type: 'roomLocation', callback?: Callback&lt;RoomLocateResponse&gt;): void;

取消订阅房间级定位事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.RoomLocation

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为"roomLocation"表示房间级定位。 |
| callback | Callback&lt;[RoomLocateResponse](#roomlocateresponse)&gt; | 否  | 回调函数，返回定位结果。                                   |

**错误码**：

以下错误码的详细介绍请参见[房间级定位错误码](errorcode-roomLocation.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission check denied. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800001 | Service exception.                                           |
| 33800003 | UnSubscription failed.                                          |

**示例**：

```ts
roomLocation.off('roomLocation', (data:roomLocation.RoomLocateResponse) => {
    console.info('off success' + data);
})
```



## roomLocation.setDevicesInfos()

setDevicesInfos(devicesInfos: string): Promise<boolean>;

设置设备信息。

**系统能力**：SystemCapability.MultimodalAwareness.RoomLocation

**参数**：

| 参数名  | 类型                            | 必填| 说明                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| devicesInfos| string                           | Yes  | 设备信息。 |

**错误码**：

以下错误码的详细介绍请参见[房间级定位感知错误码](errorcode-roomLocation.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission check denied. A non-system application uses the system API.                       |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33800004 | Failed to set device information.                                           |

**示例**：

```ts
const jsonstr: string = '[{"mac":"11:11:11:11:11:11","roomId":"1","prodId":"1","devId":"1","power":"","type":"1"}]';
roomLocation.setDevicesInfos(jsonstr);
```



## roomLocation.getRoomLocationResult()

getRoomLocationResult(): RoomLocateResponse;

获取房间级定位结果。

**系统能力**：SystemCapability.MultimodalAwareness.RoomLocation

**错误码**：

以下错误码的详细介绍请参见[房间级定位感知错误码](errorcode-roomLocation.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500005 | Failed to obtain room-level location information.                                           |

**示例**：

```ts
@state roomResult: roomLocation.RoomLocateResponse = { roomId: "-1", errorCode: -1 };
this.roomResult = roomLocation.getRoomLocationResult();
console.info('get success' + this.roomResult);
```
