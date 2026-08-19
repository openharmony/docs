# @ohos.stationary (设备状态感知框架)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

设备状态感知框架提供设备状态感知能力，包括绝对静止和相对静止，适用于需要根据设备静止状态优化应用性能、智能省电、场景识别等场景。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块不支持在x86平台上运行。

## 导入模块

```ts
import { stationary } from '@kit.MultimodalAwarenessKit';
```

## ActivityResponse

服务响应抽象接口。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| state | [ActivityState](#activitystate) | 否 | 否 | 设备状态变化返回值。 |

## ActivityType

type ActivityType = 'still' | 'relativeStill'

设备状态类型。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

| 类型 | 说明 |
| -------- | -------- |
| 'still' | 绝对静止。 |
| 'relativeStill' | 相对静止。 |

## ActivityEvent

设备状态事件。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

| 名称                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | 进入事件，表示设备进入静止状态时触发。   |
| EXIT | 2   | 退出事件，表示设备退出静止状态时触发。 |
| ENTER_EXIT | 3   | 进入和退出事件，表示设备进入和退出静止状态时均会触发。 |

## ActivityState

设备状态返回值。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

| 名称                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| ENTER         | 1    | 进入状态，表示设备当前处于静止状态。   |
| EXIT | 2   | 退出状态，表示设备当前未处于静止状态。 |

## stationary.on

on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback&lt;ActivityResponse&gt;): void

订阅设备状态变化事件。当设备满足指定状态条件时，系统会触发回调函数上报状态变化事件。调用on()后，必须在不使用时调用off()取消订阅，避免多余的性能功耗开销。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | 是   | 设备状态类型。              |
| event  | [ActivityEvent](#activityevent)  | 是   | 事件类型。              |
| reportLatencyNs  | number  | 是   | 报告延时，单位：纳秒（ns），取值范围[1000000000, 3000000000]。超出范围时返回错误。建议根据业务场景选择合适的值，较小值可提高实时性但会增加功耗，较大值可降低功耗但会降低响应速度。              |
| callback             | Callback<[ActivityResponse](#activityresponse)\>  | 是   | 回调函数，用于接收设备状态变化结果。    |

**示例：**

```ts
let reportLatencyNs = 1000000000; // 单位：纳秒
stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {
    console.info('data=' + JSON.stringify(data));
});
```

## stationary.once

once(activity: ActivityType, callback: Callback&lt;ActivityResponse&gt;): void

查询设备状态。通过callback回调返回查询结果，仅执行一次。使用callback异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | 是   | 设备状态类型。              |
| callback             | Callback<[ActivityResponse](#activityresponse)\>  | 是   | 回调函数，用于接收设备状态查询结果。    |

**示例：**

```ts
stationary.once('still', (data) => {
    console.info('data=' + JSON.stringify(data));
});
```

## stationary.off

off(activity: ActivityType, event: ActivityEvent, callback?: Callback&lt;ActivityResponse&gt;): void

取消订阅设备状态服务。取消订阅后，将停止接收该状态相关的回调函数调用。调用off()时需要使用与on()相同的activity和event参数。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Stationary

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | ---- | ---------------------------- |
| activity  | [ActivityType](#activitytype)  | 是   | 设备状态类型。              |
| event  | [ActivityEvent](#activityevent)  | 是   | 事件类型。              |
| callback | Callback<[ActivityResponse](#activityresponse)\>  | 否   | 要移除的回调函数。未传递callback参数或传递undefined时，移除该进程下订阅该类型的所有callback。  |

**示例：**

```ts
stationary.off('still', stationary.ActivityEvent.ENTER);
```
