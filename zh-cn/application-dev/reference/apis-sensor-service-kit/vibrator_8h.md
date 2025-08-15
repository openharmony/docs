# vibrator.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @butterls-->
<!--Tester: @murphy84-->
<!--Adviser: @hu-zhiqiong-->

## 概述

为您提供标准的开放api，用于控制马达振动的启停。

**库**：libohvibrator.z.so

**系统能力**：SystemCapability.Sensors.MiscDevice

**起始版本**：11

**相关模块**：[Vibrator](_vibrator.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OHOS::Sensors::OH_Vibrator_PlayVibration](#oh_vibrator_playvibration)(int32_t duration, Vibrator_Attribute attribute) | 控制马达在指定时间内持续振动。 |
| [OHOS::Sensors::OH_Vibrator_PlayVibrationCustom](#oh_vibrator_playvibrationcustom)(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute) | 播放自定义振动序列。           |
| [OHOS::Sensors::OH_Vibrator_Cancel](#oh_vibrator_cancel)() | 停止马达振动。  |


## 函数说明


### OH_Vibrator_Cancel()

```
int32_t OHOS::Sensors::OH_Vibrator_Cancel()
```
**描述**：

停止马达振动。

**起始版本**：11

**返回**：

如果操作成功，则返回0；否则返回非零值。请参阅 [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode)。

**Permission**:

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibration()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute)
```
**描述**：

控制马达在指定时间内持续振动。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| duration | 振动时长，单位：毫秒。  |
| attribute | 振动属性，请参考 [Vibrator_Attribute](_vibrator.md#vibrator_attribute)。 |

**返回**：

如果操作成功，则返回0；否则返回非零值。请参阅 [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode)。

**Permission**:

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibrationCustom()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute)
```
**描述**：

播放自定义振动序列。

**起始版本**：11

**参数**：

| 名称 | 描述 |
| -------- | -------- |
| fileDescription | 自定义振动效果文件描述符，请参阅 [Vibrator_FileDescription](_vibrator.md#vibrator_filedescription)。 |
| vibrateAttribute | 振动属性，请参阅 [Vibrator_Attribute](_vibrator.md#vibrator_attribute)。 |

**返回**：

如果操作成功，则返回0；否则返回非零值。请参阅 [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode)。

**Permission**:

ohos.permission.VIBRATE
