# Enums
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CameraPosition

枚举，相机位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值   | 说明                                                              |
| --------------------------- | ---- |-----------------------------------------------------------------|
| CAMERA_POSITION_UNSPECIFIED | 0    | 相对于设备屏幕没有固定的朝向的相机。                                                        |
| CAMERA_POSITION_BACK        | 1    | 后置相机。                                                           |
| CAMERA_POSITION_FRONT       | 2    | 前置相机。                                                           |
| CAMERA_POSITION_FOLD_INNER<sup>(deprecated)</sup>  | 3    | 折叠态相机。<br/> 从API version 11开始支持，从API version 12开始废弃。 |

## CameraType

枚举，相机类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值   | 说明            |
| ----------------------- | ---- | -------------- |
| CAMERA_TYPE_DEFAULT     | 0    | 默认相机类型。  |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | 广角相机。       |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | 超广角相机。     |
| CAMERA_TYPE_TELEPHOTO   | 3    | 长焦相机。       |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | 带景深信息的相机。 |

## ConnectionType

枚举，相机连接类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值   | 说明           |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | 内置相机。      |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | USB连接的相机。 |
| CAMERA_CONNECTION_REMOTE     | 2    | 远程连接的相机。 |

## HostDeviceType<sup>15+</sup>

枚举，远端相机设备类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值       | 说明      |
| ---------------------------- | ----     |---------|
| UNKNOWN_TYPE                 | 0        | 未知设备类型。 |
| PHONE                        | 0x0E     | 手机设备。   |
| TABLET                       | 0x11     | 平板设备。   |

## CameraStatus

枚举，相机状态。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | 新的相机出现。   |
| CAMERA_STATUS_DISAPPEAR   | 1    | 相机被移除。     |
| CAMERA_STATUS_AVAILABLE   | 2    | 相机可用。       |
| CAMERA_STATUS_UNAVAILABLE | 3    | 相机不可用。     |

## FoldStatus<sup>12+</sup>

枚举，折叠机折叠状态。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| NON_FOLDABLE      | 0    | 表示当前设备不可折叠。   |
| EXPANDED   | 1    | 表示当前设备折叠状态为完全展开。 |
| FOLDED   | 2    | 表示当前设备折叠状态为折叠。       |

## SceneMode<sup>11+</sup>

枚举，相机模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值       | 说明                                          |
|----------------------------|---------|---------------------------------------------|
| NORMAL_PHOTO               | 1       | 普通拍照模式。详情见[PhotoSession](arkts-apis-camera-PhotoSession.md)   |
| NORMAL_VIDEO               | 2       | 普通录像模式。详情见[VideoSession](arkts-apis-camera-VideoSession.md)   |
| SECURE_PHOTO<sup>12+</sup> | 12      | 安全相机模式。详情见[SecureSession](arkts-apis-camera-SecureSession.md) |

## CameraErrorCode

相机错误码。

接口使用不正确以及on接口监听error状态返回。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值          | 说明            |
| -------------------------  | ----       | ------------    |
| INVALID_ARGUMENT           | 7400101    | 参数缺失或者参数类型不对。   |
| OPERATION_NOT_ALLOWED      | 7400102    | 操作流程不对，不允许。     |
| SESSION_NOT_CONFIG         | 7400103    | session 未配置返回。       |
| SESSION_NOT_RUNNING        | 7400104    | session 未运行返回。    |
| SESSION_CONFIG_LOCKED      | 7400105    | session 配置已锁定返回。     |
| DEVICE_SETTING_LOCKED      | 7400106    | 设备设置已锁定返回。     |
| CONFLICT_CAMERA            | 7400107    | 设备重复打开返回。     |
| DEVICE_DISABLED            | 7400108    | 安全原因相机被禁用。     |
| DEVICE_PREEMPTED           | 7400109    | 相机被抢占导致无法使用。     |
| UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS<sup>12+</sup> | 7400110   | 与当前配置存在冲突。     |
| SERVICE_FATAL_ERROR        | 7400201    | 相机服务错误返回。     |

## TorchMode<sup>11+</sup>

枚举，手电筒模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值   | 说明           |
| ---------------------------- | ---- | ------------- |
| OFF    | 0    | 常关模式。      |
| ON  | 1    | 常开模式。 |
| AUTO      | 2    | 自动模式，系统根据环境自动调节手电筒亮度。|

## CameraFormat

枚举，输出格式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGBA_8888格式的图片。        |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV_420_SP格式的图片，对应为NV21格式的图片。      |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG格式的图片。            |
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010格式的图片。      |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010格式的图片。      |
| CAMERA_FORMAT_HEIC<sup>13+</sup>       |   2003    | HEIF格式的图片。            |

## VideoCodecType<sup>13+</sup>

枚举，视频编码类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 值    | 说明          |
|------|------|-------------|
| AVC  | 0    | 视频编码类型AVC。|
| HEVC | 1 | 视频编码类型HEVC。|

## CameraConcurrentType<sup>18+</sup>

枚举，镜头并发类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 值    | 说明          |
|------|------|-------------|
| CAMERA_LIMITED_CAPABILITY  | 0 | 镜头受限能力并发。  |
| CAMERA_FULL_CAPABILITY     | 1 | 镜头全量能力并发。 |

## ImageRotation

枚举，图片旋转角度。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明           |
| ------------ | ---- | ------------- |
| ROTATION_0   | 0    | 图片旋转0度。   |
| ROTATION_90  | 90   | 图片旋转90度。  |
| ROTATION_180 | 180  | 图片旋转180度。 |
| ROTATION_270 | 270  | 图片旋转270度。 |

## QualityLevel

枚举，图片质量。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                  | 值   | 说明         |
| -------------------- | ---- | ------------ |
| QUALITY_LEVEL_HIGH   | 0    | 图片质量高。   |
| QUALITY_LEVEL_MEDIUM | 1    | 图片质量中等。 |
| QUALITY_LEVEL_LOW    | 2    | 图片质量差。   |

## MetadataObjectType

枚举，metadata流。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | metadata对象类型，用于人脸检测。 |

## FlashMode

枚举，闪光灯模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                    | 值   | 说明        |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | 闪光灯关闭。 |
| FLASH_MODE_OPEN        | 1    | 闪光灯打开。 |
| FLASH_MODE_AUTO        | 2    | 自动闪光灯。 |
| FLASH_MODE_ALWAYS_OPEN | 3    | 闪光灯常亮。 |

## ExposureMode

枚举，曝光模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | 锁定曝光模式。不支持曝光区域中心点设置。 |
| EXPOSURE_MODE_AUTO            | 1    | 自动曝光模式。支持曝光区域中心点设置，可以使用[AutoExposure.setMeteringPoint](arkts-apis-camera-AutoExposure.md#setmeteringpoint11)接口设置曝光区域中心点。 |
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | 连续自动曝光。不支持曝光区域中心点设置。 |

## FocusMode

枚举，焦距模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                        | 值   | 说明          |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | 手动对焦。通过手动修改相机焦距来改变对焦位置，不支持对焦点设置。     |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | 连续自动对焦。不支持对焦点设置。 |
| FOCUS_MODE_AUTO            | 2    | 自动对焦。支持对焦点设置，可以使用[Focus.setFocusPoint](arkts-apis-camera-Focus.md#setfocuspoint11)设置对焦点，根据对焦点执行一次自动对焦。    |
| FOCUS_MODE_LOCKED          | 3    | 对焦锁定。不支持对焦点设置。     |

## FocusState

枚举，焦距状态。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                   | 值   | 说明       |
| --------------------- | ---- | --------- |
| FOCUS_STATE_SCAN      | 0    | 触发对焦。  |
| FOCUS_STATE_FOCUSED   | 1    | 对焦成功。  |
| FOCUS_STATE_UNFOCUSED | 2    | 未完成对焦。 |

## VideoStabilizationMode

枚举，视频防抖模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 值   | 说明         |
| --------- | ---- | ------------ |
| OFF       | 0    | 关闭视频防抖功能。   |
| LOW       | 1    | 使用基础防抖算法。   |
| MIDDLE    | 2    | 使用防抖效果一般的防抖算法，防抖效果优于LOW类型。   |
| HIGH      | 3    | 使用防抖效果最好的防抖算法，防抖效果优于MIDDLE类型。   |
| AUTO      | 4    | 自动进行选择防抖算法。   |

## SmoothZoomMode<sup>11+</sup>

平滑变焦模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 值   | 说明            |
| ------------ | ---- | -------------- |
| NORMAL       | 0    | 贝塞尔曲线模式。  |

## PreconfigType<sup>12+</sup>

枚举，提供预配置的类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                      | 值 | 说明         |
|-------------------------|---|------------|
| PRECONFIG_720P          | 0 | 720P预配置。   |
| PRECONFIG_1080P         | 1 | 1080P预配置。  |
| PRECONFIG_4K            | 2 | 4K预配置。     |
| PRECONFIG_HIGH_QUALITY  | 3 | 高质量预配置。    |

## PreconfigRatio<sup>12+</sup>

枚举，提供预配置的分辨率比例。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值 | 说明      |
|--------------------------|---|---------|
| PRECONFIG_RATIO_1_1      | 0 | 1:1画幅。  |
| PRECONFIG_RATIO_4_3      | 1 | 4:3画幅。  |
| PRECONFIG_RATIO_16_9     | 2 | 16:9画幅。 |

## QualityPrioritization<sup>14+</sup>

枚举，录像质量优先级。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值  | 说明       |
| ------------- | --- | ---------- |
| HIGH_QUALITY  | 0   | 高录像质量。   |
| POWER_BALANCE | 1   | 功耗平衡的录像质量。 |

## WhiteBalanceMode<sup>20+</sup>

枚举，白平衡模式。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 值 | 说明         |
|----------------|---| ----------- |
| AUTO           | 0 | 自动 |
| CLOUDY         | 1 | 阴天 |
| INCANDESCENT   | 2 | 白炽光 |
| FLUORESCENT    | 3 | 荧光 |
| DAYLIGHT       | 4 | 日光 |
| MANUAL         | 5 | 手动 |
| LOCKED         | 6 | 锁定  |

## SystemPressureLevel<sup>20+</sup>

枚举，系统压力等级。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值 | 说明       | 
|--------------------------|---|------------|
| SYSTEM_PRESSURE_NORMAL   | 0 | 系统压力正常。 |
| SYSTEM_PRESSURE_MILD     | 1 | 系统压力升高，但是系统不会主动管控。 |
| SYSTEM_PRESSURE_SEVERE   | 2 | 系统压力可能对图像总质量、性能产生影响。 |
| SYSTEM_PRESSURE_CRITICAL | 3 | 系统压力对图像质量、性能产生显著影响。 |
| SYSTEM_PRESSURE_SHUTDOWN | 4 | 系统压力过高，停止工作。 |

## ControlCenterEffectType<sup>20+</sup>

枚举，相机控制器支持的效果类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 值 | 说明    |
|-----------|---|---------|
| BEAUTY    | 0 | 美颜。   |
| PORTRAIT  | 1 | 人像虚化。|