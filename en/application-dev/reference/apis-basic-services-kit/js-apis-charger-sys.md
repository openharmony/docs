# @ohos.charger (Charger) (System API)

The **charger** module enumerates charging types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>The APIs provided by this module are system APIs.


## Modules to Import

```js
import charger from '@ohos.charger';
```

## ChargeType

Enumerates charging types.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name      | Value | Description             |
| -------- | ---- | ----------------- |
| NONE                 | 0    | Unknown charging type.     |
| WIRED_NORMAL         | 1    | Wired normal charging.|
| WIRED_QUICK          | 2    | Wired fast charging.  |
| WIRED_SUPER_QUICK    | 3    | Wired super fast charging.|
| WIRELESS_NORMAL      | 4    | Wireless normal charging.|
| WIRELESS_QUICK       | 5    | Wireless fast charging.|
| WIRELESS_SUPER_QUICK | 6    | Wireless super fast charging.|
