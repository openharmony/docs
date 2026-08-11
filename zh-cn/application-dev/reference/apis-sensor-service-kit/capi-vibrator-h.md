# vibrator.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

## 概述

为您提供标准的开放API，用于控制马达振动的启停。支持简单持续振动和自定义振动序列两种模式。其中，简单持续振动适用于固定时长的单一振动场景，如闹钟、计时提醒等，只需指定振动时长即可实现；自定义振动序列适用于需要复杂振动模式的场景，如通知提醒、游戏反馈等，通过定义振动序列文件可实现丰富的触觉效果。帮助开发者实现精准的振动控制，提升用户交互体验。

**引用文件：** <sensors/vibrator.h>

**库：** libohvibrator.z.so

**系统能力：** SystemCapability.Sensors.MiscDevice

**起始版本：** 11

**相关模块：** [Vibrator](capi-vibrator.md)

## 汇总

### 函数

| 名称    | 描述 |
|------| -- |
| [int32_t OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute)](#oh_vibrator_playvibration)                                        | 控制马达在指定时间内持续振动。适用于需要固定时长振动的场景，如闹钟、计时提醒、游戏反馈、消息提醒等。 |
| [int32_t OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute)](#oh_vibrator_playvibrationcustom) | 播放自定义振动序列。适用于通知提醒、游戏、触觉反馈等需要复杂振动模式的场景，帮助实现个性化振动体验，增强用户沉浸感。 |
| [int32_t OH_Vibrator_Cancel()](#oh_vibrator_cancel)                    | 停止马达振动。适用于需要立即结束振动的场景，如用户取消操作、应用切换或系统通知消除，帮助优化用户体验和设备功耗。 |

## 函数说明

### OH_Vibrator_PlayVibration()

```c
int32_t OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute)
```

**描述**

控制马达在指定时间内持续振动。调用成功后，马达立即开始振动，持续指定时间后自动停止。适用于需要固定时长振动的场景，如闹钟、计时提醒、游戏反馈、消息提醒等。

**相关方法：**
- OH_Vibrator_Cancel()：停止当前正在进行的振动
- OH_Vibrator_PlayVibrationCustom()：播放自定义振动序列

**需要权限：** ohos.permission.VIBRATE

**起始版本：** 11

**参数：**

| 参数项 | 类型 | 必填 | 描述 |
| -- | -- | -- | -- |
| duration | int32_t | 是 | 振动时长，单位：ms（毫秒）。用于控制马达振动的持续时间。取值范围[1, 60000]。 |
| attribute | [Vibrator_Attribute](capi-vibrator-vibrator-attribute.md) | 是 | 振动属性，用于配置振动的强度、模式等特性。请参考[Vibrator_Attribute](capi-vibrator-vibrator-attribute.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回0；否则返回 [Vibrator_ErrorCode](capi-vibrator-type-h.md#vibrator_errorcode) 中的错误码。常见错误码：PERMISSION_DENIED（201，权限校验失败）、PARAMETER_ERROR（401，参数检查失败）、UNSUPPORTED（801，设备不支持）。 |

### OH_Vibrator_PlayVibrationCustom()

```c
int32_t OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute)
```

**描述**

播放自定义振动序列。调用成功后，系统按照自定义振动序列的配置播放振动效果。适用于通知提醒、游戏、触觉反馈等需要复杂振动模式的场景，帮助实现个性化振动体验，增强用户沉浸感。

**相关方法：**
- OH_Vibrator_Cancel()：停止当前正在进行的振动

**需要权限：** ohos.permission.VIBRATE

**起始版本：** 11

**参数：**

| 参数项 | 类型 | 必填 | 描述 |
| -- | -- | -- | -- |
| fileDescription | [Vibrator_FileDescription](capi-vibrator-vibrator-filedescription.md) | 是 | 自定义振动效果文件描述符，用于指定包含振动序列数据的文件位置和范围。通过设置文件句柄、偏移地址和长度，可以播放自定义的振动效果。详细信息请参阅 [Vibrator_FileDescription](capi-vibrator-vibrator-filedescription.md)。 |
| vibrateAttribute | [Vibrator_Attribute](capi-vibrator-vibrator-attribute.md) | 是 | 振动属性，用于控制自定义振动效果的强度、频率等特性。请参阅 [Vibrator_Attribute](capi-vibrator-vibrator-attribute.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回0；否则返回 [Vibrator_ErrorCode](capi-vibrator-type-h.md#vibrator_errorcode) 中的错误码。常见错误码包括：参数错误时请检查fileDescription和vibrateAttribute参数是否合法；设备不支持振动功能时请检查设备能力。详细错误码说明请参考 [Vibrator_ErrorCode](capi-vibrator-type-h.md#vibrator_errorcode)。 |

### OH_Vibrator_Cancel()

```c
int32_t OH_Vibrator_Cancel()
```

**描述**

停止马达振动。调用成功后，立即停止当前正在进行的持续振动或自定义振动序列播放。适用于需要立即结束振动的场景，如用户取消操作、应用切换或系统通知消除，帮助优化用户体验和设备功耗。

**需要权限：** ohos.permission.VIBRATE

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回0；否则返回 [Vibrator_ErrorCode](capi-vibrator-type-h.md#vibrator_errorcode) 中的错误码。有关错误码的可能原因和解决措施，请参考下方错误码表。 |

| 错误码ID | 错误信息 | 说明 |
| --- | --- | --- |
| 201 | 权限校验失败 | 请检查是否已申请ohos.permission.VIBRATE权限。 |
| 801 | 设备不支持此API | 请检查设备是否支持振动功能。 |
| 14600101 | 设备操作失败 | 请检查设备状态。 |