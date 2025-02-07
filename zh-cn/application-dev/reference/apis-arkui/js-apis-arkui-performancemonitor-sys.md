# @ohos.arkui.performanceMonitor (性能监测)(系统接口)

用户操作场景提供性能相关指标监测能力，目前仅包含响应时延、完成时延、丢帧。

> **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块接口为系统接口。


## 导入模块

```ts
import { performanceMonitor } from '@kit.ArkUI';
```


## ActionType

用户场景触发模式枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -- | -- | -- |
| LAST_DOWN | 0 | 用户按压事件触发。  |
| LAST_UP | 1 | 用户离手事件触发。 |
| FIRST_MOVE | 2 | 用户首次滑动事件触发。 |


## performanceMonitor.begin

begin(scene: string, startInputType: ActionType, note?: string): void

用户场景开始。


**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| scene | string | 是 | 用户场景id。 |
| startInputType | [ActionType](#actiontype)| 是 | 用户场景触发模式。 |
| note | string| 否 | 用户场景重要信息。 |

**示例：** 
  ```ts
performanceMonitor.begin("LAUNCHER_APP_LAUNCH_FROM_ICON", performanceMonitor.ActionType.LAST_UP, "APP_START_BEGIN");
  ```


## performanceMonitor.end

end(scene: string): void

用户场景结束

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 
| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| scene | string | 是 | 用户场景id，与begin配对。 |

**示例：** 
  ```ts
performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");
  ```