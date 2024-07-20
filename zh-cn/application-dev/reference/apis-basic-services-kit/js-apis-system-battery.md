# @system.battery (电量信息)

该模块提供充电状态及剩余电量的查询功能。

>  **说明：**
>  - 从API Version 6开始不再维护，建议使用[`@ohos.batteryInfo`](js-apis-battery-info.md)替代。
>  - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import {Battery, BatteryResponse } from '@kit.BasicServicesKit';
```


## Battery.getStatus

getStatus(options?: GetStatusOptions): void;

获取设备当前的充电状态及剩余电量。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetStatusOptions](#getstatusoptions) | 否 | 包含接口调用结果的对象。可选，默认为空。 |

**示例：**

```js
Battery.getStatus({
    success: (data: BatteryResponse) => {
        console.log('success get battery level:' + data.level);
    },
    fail: (data: string, code: number) => {
        console.error('fail to get battery level code:' + code + ', data: ' + data);
    }
});
```

## GetStatusOptions

包含接口调用结果的对象。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Lite

| 参数名   | 类型                                                | 必填 | 说明                                                         |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| success  | (data: [BatteryResponse](#batteryresponse)) => void | 否   | 接口调用成功的回调函数，data为[BatteryResponse](#batteryresponse)类型的返回值。 |
| fail     | (data: string, code: number) => void                | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。       |
| complete | () => void                                          | 否   | 接口调用结束的回调函数。                                     |

## BatteryResponse

包含充电状态及剩余电量的对象。

**系统能力：** SystemCapability.PowerManager.BatteryManager.Lite

| 参数名 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| charging | boolean | 是 | 否 | 当前电池是否在充电中。 |
| level | number | 是 | 否 | 当前电池的电量，取值范围：0.00&nbsp;-&nbsp;1.00&nbsp;。 |
