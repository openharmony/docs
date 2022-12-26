# Battery Info

This module allows you to query the charging status and remaining power of a device.

>  **NOTE**
>  - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.batteryInfo`](js-apis-battery-info.md) instead.
>  - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import battery from '@system.battery';
```


## battery.getStatus

getStatus(options?: GetStatusOptions): void;

Obtains the current charging state and battery level.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetStatusOptions](#getstatusoptions) | No| Object that contains the API calling result.|

**Example**

```js
battery.getStatus({
    success: function(data) {
        console.log('success get battery level:' + data.level);
    },
    fail: function(data, code) {
        console.error('fail to get battery level code:' + code + ', data: ' + data);
    }
});
```

## GetStatusOptions

Object that contains the API calling result.

| Name  | Type                                               | Mandatory| Description                                                        |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| success  | (data: [BatteryResponse](#batteryresponse)) => void | No  | Called when API call is successful. **data** is a return value of the [BatteryResponse](#batteryresponse) type.|
| fail     | (data: string, code: number) => void                | No  | Called when API call has failed. **data** indicates the error information, and **code** indicates the error code.      |
| complete | () => void                                          | No  | Called when API call is complete.                                    |

## BatteryResponse

Defines a response that returns the charging status and remaining power of the device.

| Name| Type| Description|
| -------- | -------- | -------- |
| charging | boolean | Whether the battery is being charged.|
| level | number | Current battery level, which ranges from **0.00** to **1.00**.|
