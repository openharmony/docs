# @ohos.charger (充电类型)(系统接口)

提供充电类型。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增，采用上角标单独标记接口的起始版本。
>
>本模块为系统接口。


## 导入模块

```js
import {charger} from '@kit.BasicServicesKit';
```

## ChargeType

表示充电类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.PowerManager.BatteryManager.Core

| 名称       | 值  | 说明              |
| -------- | ---- | ----------------- |
| NONE                 | 0    | 表示未知类型。      |
| WIRED_NORMAL         | 1    | 表示有线正常充电类型。 |
| WIRED_QUICK          | 2    | 表示有线快速充电类型。   |
| WIRED_SUPER_QUICK    | 3    | 表示有线超级快速充电类型。 |
| WIRELESS_NORMAL      | 4    | 表示无线正常充电类型。 |
| WIRELESS_QUICK       | 5    | 表示无线快速充电类型。 |
| WIRELESS_SUPER_QUICK | 6    | 表示无线超级快速充电类型。 |
