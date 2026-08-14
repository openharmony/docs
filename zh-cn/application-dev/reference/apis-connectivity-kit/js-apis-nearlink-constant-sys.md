# @ohos.nearlink.constant (星闪公共常量定义)(系统接口)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->



本模块提供了星闪（NearLink）通信中共用的一些常量定义，包括设备配对状态、设备连接状态、设备类型以及逻辑链路连接状态等枚举值。


**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。


## 导入模块

```typescript
import { nearlinkConstant } from '@kit.ConnectivityKit';
```

## ConnectionInterval

连接间隔的枚举值。连接间隔决定星闪设备间通信的同步频率：间隔越小，时延越低、吞吐越高但功耗越大；间隔越大功耗越低但时延越高。高速档适用于高吞吐低时延场景，低速档适用于对功耗敏感场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| HIGH_SPEED_INTERVAL_4_5 | 0 | 表示连接间隔为4.5毫秒。 |
| HIGH_SPEED_INTERVAL_4_875 | 1 | 表示连接间隔为4.875毫秒。 |
| MID_SPEED_INTERVAL_11_25 | 2 | 表示连接间隔为11.25毫秒。 |
| MID_SPEED_INTERVAL_15 | 3 | 表示连接间隔为15毫秒。 |
| MID_SPEED_INTERVAL_50 | 4 | 表示连接间隔为50毫秒。 |
| LOW_SPEED_INTERVAL_100 | 5 | 表示连接间隔为100毫秒。 |
| LOW_SPEED_INTERVAL_150 | 6 | 表示连接间隔为150毫秒。 |
| LOW_SPEED_INTERVAL_200 | 7 | 表示连接间隔为200毫秒。 |
| LOW_SPEED_INTERVAL_300 | 8 | 表示连接间隔为300毫秒。 |
| LOW_SPEED_INTERVAL_500 | 9 | 表示连接间隔为500毫秒。 |

