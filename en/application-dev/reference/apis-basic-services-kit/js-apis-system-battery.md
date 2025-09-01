# @system.battery (Battery Information)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

The **battery** module allows you to query the charging status and remaining power of a device.

>  **NOTE**
>  - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.batteryInfo`](js-apis-battery-info.md).
>  - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import {Battery, BatteryResponse } from '@kit.BasicServicesKit';
```


## Battery.getStatus<sup>(deprecated)</sup>

getStatus(options?: GetStatusOptions): void;

Obtains the current charging state and battery level.

**System capability**: SystemCapability.PowerManager.BatteryManager.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetStatusOptions](#getstatusoptionsdeprecated) | No| Object that contains the API calling result. This parameter is optional and is left blank by default.|

**Example**

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

## GetStatusOptions<sup>(deprecated)</sup>

Object that contains the API calling result.

**System capability**: SystemCapability.PowerManager.BatteryManager.Lite

| Name  | Type                                               | Mandatory| Description                                                        |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| success  | (data: [BatteryResponse](#batteryresponsedeprecated)) => void | No  | Called when an API call is successful. **data** is a return value of the [BatteryResponse](#batteryresponsedeprecated) type.|
| fail     | (data: string, code: number) => void                | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.      |
| complete | () => void                                          | No  | Called when an API call is complete.                                    |

## BatteryResponse<sup>(deprecated)</sup>

Defines a response that returns the charging status and remaining power of the device.

**System capability**: SystemCapability.PowerManager.BatteryManager.Lite

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| charging | boolean | Yes| No| Whether the battery is being charged. The value **true** indicates that the battery is being changed; **false** indicates the opposite. The default value is **false**.|
| level | number | Yes| No| Current battery level, which ranges from **0.00** to **1.00**.|
