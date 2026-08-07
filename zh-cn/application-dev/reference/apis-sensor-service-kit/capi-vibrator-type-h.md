# vibrator_type.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供标准的开放API，用于控制马达振动。该API支持多种振动场景（如报警、铃声、通知、通信、触摸、媒体、物理反馈、模拟现实等），通过设置振动优先级，能够满足不同场景下的振动需求，提升用户交互体验和设备使用体验。

**引用文件：** <sensors/vibrator_type.h>

**库：** libohvibrator.z.so

**系统能力：** SystemCapability.Sensors.MiscDevice

**起始版本：** 11

**相关模块：** [Vibrator](capi-vibrator.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Vibrator_Attribute](capi-vibrator-vibrator-attribute.md) | Vibrator_Attribute | 马达属性，参考 [Vibrator_Attribute](capi-vibrator-vibrator-attribute.md)。 |
| [Vibrator_FileDescription](capi-vibrator-vibrator-filedescription.md) | Vibrator_FileDescription | 振动文件描述，参考 [Vibrator_FileDescription](capi-vibrator-vibrator-filedescription.md)。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Vibrator_ErrorCode](#vibrator_errorcode) | Vibrator_ErrorCode | 定义错误码。 |
| [Vibrator_Usage](#vibrator_usage) | Vibrator_Usage | 振动优先级，用于定义不同场景下振动的优先级，高优先级振动会中断低优先级的振动。使用时建议根据应用场景选择合适的优先级。 |

## 枚举类型说明

### Vibrator_ErrorCode

```c
enum Vibrator_ErrorCode
```

**描述**

定义错误码，在使用振动相关API时，若发生异常情况会返回相应的错误码。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| PERMISSION_DENIED = 201 | 权限校验失败，请检查是否已申请所需权限（如ohos.permission.VIBRATE）。 |
| PARAMETER_ERROR = 401 | 参数检查失败，包括必选参数未传入、参数类型错误等。 |
| UNSUPPORTED = 801 | 设备不支持此API。通常在设备已支持该SysCap时，用于处理少量不支持的情况。 |
| DEVICE_OPERATION_FAILED = 14600101 | 设备操作失败，请检查设备状态和参数配置。 |

### Vibrator_Usage

```c
enum Vibrator_Usage
```

**描述**

振动优先级，用于定义不同场景下振动的优先级，高优先级的振动会打断低优先级的振动。使用时建议：根据应用场景选择合适的优先级；在需要连续振动的场景中保持一致优先级，避免频繁切换导致性能损耗；物理反馈和触摸类振动建议使用较高优先级以确保及时响应。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| VIBRATOR_USAGE_UNKNOWN = 0 | 未知场景，最低优先级。用于无法确定具体使用场景时，系统按默认策略处理。 |
| VIBRATOR_USAGE_ALARM = 1 | 报警。用于闹钟、倒计时等提醒场景，振动强度较高，持续时间长。 |
| VIBRATOR_USAGE_RING = 2 | 铃声。用于电话呼入场景，振动模式为循环振动，便于用户及时接听。 |
| VIBRATOR_USAGE_NOTIFICATION = 3 | 通知。用于系统通知、应用消息等提醒场景，振动较短，提醒用户查看。 |
| VIBRATOR_USAGE_COMMUNICATION = 4 | 通信。用于通话、即时通讯消息、短信等通信场景的振动反馈，振动模式为短促单次振动。 |
| VIBRATOR_USAGE_TOUCH = 5 | 触摸。用于屏幕触摸、按键操作等反馈场景，振动极短，提供操作确认感。 |
| VIBRATOR_USAGE_MEDIA = 6 | 媒体。用于音乐、视频等媒体应用场景，振动与媒体内容同步，增强沉浸体验。 |
| VIBRATOR_USAGE_PHYSICAL_FEEDBACK = 7 | 物理反馈。用于游戏、模拟等需要物理反馈的场景，提供物理按键反馈、触觉力反馈等物理交互体验，振动模式可自定义，模拟真实触感。 |
| VIBRATOR_USAGE_SIMULATED_REALITY = 8 | 模拟现实。用于VR/AR等沉浸式场景的触觉反馈，振动强度和模式精确可控，提供逼真的环境反馈。 |


