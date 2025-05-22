# @ohos.stationary (Device Status Awareness Framework)

The **stationary** module provides APIs to report the device status, including absolute still and relative still.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module does not support x86 emulators.

## Modules to Import

```ts
import { stationary } from '@kit.MultimodalAwarenessKit';
```

## ActivityResponse

Defines the response interface to receive the device status.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| state | [ActivityState](#activitystate) | Yes| No| New device status.|

## ActivityType

type ActivityType = 'still' | 'relativeStill'

Enumerates the device status types.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

| Type| Description|
| -------- | -------- |
| 'still' | Absolutely still.|
| 'relativeStill' | Relatively still.|

## ActivityEvent

Enumerates the device status events.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Event indicating entering device status.  |
| EXIT | 2   | Event indicating exiting device status.|
| ENTER_EXIT | 3   | Event indicating entering and exiting device status.|

## ActivityState

Enumerates the device statuses.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | Event indicating entering device status.  |
| EXIT | 2   | Event indicating exiting device status.|

## stationary.on('still' | 'relativeStill')

on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback&lt;ActivityResponse&gt;): void

Subscribes to the device status.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | Yes  | Device status type.             |
| event  | [ActivityEvent](#activityevent)  | Yes  | Event type.             |
| reportLatencyNs  | number  | Yes  | Report delay, in ns. The value ranges from **1000000000** to **3000000000**.             |
| callback             | Callback<[ActivityResponse](#activityresponse)\>  | Yes  | Callback used to receive reported data.   |

**Example**

```ts
let reportLatencyNs = 1000000000;
stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {
    console.log('data='+ JSON.stringify(data));
})
```

## stationary.once('still' | 'relativeStill')

once(activity: ActivityType, callback: Callback&lt;ActivityResponse&gt;): void

Obtains the device status.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | Yes  | Device status type.             |
| callback             | Callback<[ActivityResponse](#activityresponse)\>  | Yes  | Callback used to receive reported data.   |

**Example**

```ts
stationary.once('still', (data) => {
    console.log("data="+ JSON.stringify(data));
})
```

## stationary.off('still' | 'relativeStill')

off(activity: ActivityType, event: ActivityEvent, callback?: Callback&lt;ActivityResponse&gt;): void

Unsubscribes from the device status.

**System capability**: SystemCapability.Msdp.DeviceStatus.Stationary

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | Yes  | Device status type.             |
| event  | [ActivityEvent](#activityevent)  | Yes  | Event type.             |
| callback | Callback<[ActivityResponse](#activityresponse)\>  | No  | Callback used to receive reported data. If no value or **undefined** is passed, all callbacks associated with the specified event in the process will be unregistered. |

**Example**

```ts
stationary.off('still', stationary.ActivityEvent.ENTER);
```
