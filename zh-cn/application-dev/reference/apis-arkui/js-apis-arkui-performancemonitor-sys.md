# @ohos.arkui.performanceMonitor (性能监测)(系统接口)

提供用户操作场景性能相关指标监测能力，在场景开始和结束时分别调用begin和end接口，即可获得该场景相关性能指标，目前仅包含响应时延、完成时延、丢帧。

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

用户场景（通常为具有动效的场景）触发模式枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -- | -- | -- |
| LAST_DOWN | 0 | 用户按压事件触发。  |
| LAST_UP | 1 | 用户离手事件触发。 |
| FIRST_MOVE | 2 | 用户首次滑动事件触发。 |


## SourceType<sup>12+</sup>

用户场景触发源类型枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -- | -- | -- |
| PERF_TOUCH_EVENT | 0 | 触摸屏事件。 |
| PERF_MOUSE_EVENT | 1 | 鼠标事件。 |
| PERF_TOUCHPAD_EVENT | 2 | 触摸板事件。 |
| PERF_JOYSTICK_EVENT | 3 | 摇杆事件。 |
| PERF_KEY_EVENT | 4 | 键盘事件。 |


## performanceMonitor.begin

begin(scene: string, startInputType: ActionType, note?: string): void

用于标记用户场景开始，用户场景开始时调用此接口。


**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| scene | string | 是 | 用户场景id。 |
| startInputType | [ActionType](#actiontype)| 是 | 用户场景触发模式。 |
| note | string| 否 | 用户场景重要信息。 |

**示例：** 

用户点击图标启动应用场景动效开始点，由离手事件LAST_UP触发。
  ```ts
performanceMonitor.begin("LAUNCHER_APP_LAUNCH_FROM_ICON", performanceMonitor.ActionType.LAST_UP, "APP_START_BEGIN");
  ```


## performanceMonitor.end

end(scene: string): void

用于标记用户场景结束，用户场景结束时调用此接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 
| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| scene | string | 是 | 用户场景id，与begin配对。 |

**示例：** 

用户点击图标应用场景动效结束点
  ```ts
performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");
  ```

## performanceMonitor.recordInputEventTime<sup>12+</sup>

recordInputEventTime(type: ActionType, sourceType: sourceType, time: number): void

记录动效场景开始前，用户输入触发事件类型与时间。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| type | [ActionType](#actiontype)| 是 | 用户场景触发模式。 |
| sourceType | [SourceType](#sourcetype12) | 是 | 用户场景触发源。 |
| time | number | 是 | 场景触发时间（ms）。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | not system application. |

**示例：**

```ts
import { systemDateTime, BusinessError } from '@kit.BasicServicesKit';
import { performanceMonitor } from '@kit.ArkUI';

// 获取当前系统时间
let time = systemDateTime.getTime(false);
try {
  // 更新用户触发事件类型与时间
  performanceMonitor.recordInputEventTime(performanceMonitor.ActionType.LAST_UP, performanceMonitor.SourceType.PERF_MOUSE_EVENT, time);
} catch (paramError) {
  // 异常处理
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```