# Enums
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

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
| NORMAL_PHOTO               | 1       | 普通拍照模式。详情见[PhotoSession](arkts-apis-camera-PhotoSession.md)。   |
| NORMAL_VIDEO               | 2       | 普通录像模式。详情见[VideoSession](arkts-apis-camera-VideoSession.md)。  |
| SECURE_PHOTO<sup>12+</sup> | 12      | 安全相机模式。详情见[SecureSession](arkts-apis-camera-SecureSession.md)。 |

## CameraErrorCode

相机错误码。

接口使用不正确以及on接口监听error状态返回。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值          | 说明            |
| -------------------------  | ----       | ------------    |
| INVALID_ARGUMENT           | 7400101    | 参数缺失或者参数类型不对。<br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| OPERATION_NOT_ALLOWED      | 7400102    | 操作流程不对，不允许。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| SESSION_NOT_CONFIG         | 7400103    | session 未配置返回。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。  |
| SESSION_NOT_RUNNING        | 7400104    | session 未运行返回。<br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| SESSION_CONFIG_LOCKED      | 7400105    | session 配置已锁定返回。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| DEVICE_SETTING_LOCKED      | 7400106    | 设备设置已锁定返回。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。|
| CONFLICT_CAMERA            | 7400107    | 设备重复打开返回。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| DEVICE_DISABLED            | 7400108    | 安全原因相机被禁用。<br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| DEVICE_PREEMPTED           | 7400109    | 相机被抢占导致无法使用。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。  |
| UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS<sup>12+</sup> | 7400110   | 与当前配置存在冲突。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| SERVICE_FATAL_ERROR        | 7400201    | 相机服务异常返回。 <br> **原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。    |

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

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGBA_8888格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。        |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV_420_SP格式的图片，对应为NV21格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。      |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。            |
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。      |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。      |
| CAMERA_FORMAT_HEIC<sup>13+</sup>       |   2003    | HEIF格式的图片。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。            |
| CAMERA_FORMAT_DNG<sup>24+</sup>        |   4    |  DNG（数字负片）格式的图片。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。|
| CAMERA_FORMAT_DNG_XDRAW | 5     | 增强型DNG格式的图片。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。     |

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

枚举，metadata元数据检测类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | 元数据的对象类型，用于人脸检测。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| HUMAN_BODY<sup>23+</sup>     | 1    | 元数据的对象类型，用于人体检测。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。 |
| CAT_FACE               | 2    | 用于检测猫脸的metadata类型。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。|
| CAT_BODY                   | 3    | 用于检测猫的身体的metadata类型。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。|
| DOG_FACE                   | 4    | 用于检测狗脸的metadata类型。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| DOG_BODY                   | 5    | 用于检测狗的身体的metadata类型。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| SALIENT_DETECTION          | 6    | 用于显著性检测。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| BAR_CODE_DETECTION         | 7    | 用于二维码检测。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| BASIC_FACE_DETECTION       | 8    | 用于基础人脸检测。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |

## Emotion

枚举，人脸检测信息中的情绪类型。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| -------------------------- | ---- | ----------------- |
| NEUTRAL                    | 0    | 平静。 |
| SADNESS                    | 1    | 悲伤。 |
| SMILE                      | 2    | 微笑。 |
| SURPRISE                   | 3    | 惊讶。 |

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

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_UNSPECIFIED<sup>24+</sup>      | -1    | 曝光模式未指定。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。|
| EXPOSURE_MODE_LOCKED          | 0    | 锁定曝光模式。不支持曝光区域中心点设置。<br>设置该模式后，每次拍照时曝光都会默认锁定。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。|
| EXPOSURE_MODE_AUTO            | 1    | 自动曝光模式。支持曝光区域中心点设置，可以使用[AutoExposure.setMeteringPoint](arkts-apis-camera-AutoExposure.md#setmeteringpoint11)接口设置曝光区域中心点。<br>设置该模式后，仅设置后的首次拍照生效。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | 连续自动曝光。不支持曝光区域中心点设置。<br>设置该模式后，拍照系统会根据每次的环境变化自动调整曝光。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| EXPOSURE_MODE_MANUAL<sup>24+</sup> | 3    | 手动曝光。支持设置曝光时长。<br>设置该模式后，用户可通过[ManualExposure.setExposureDuration](arkts-apis-camera-ManualExposure.md#setexposureduration24)设置曝光时长。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。 |

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

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                      | 值 | 说明         |
|-------------------------|---|------------|
| PRECONFIG_720P          | 0 | 720P预配置。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。  |
| PRECONFIG_1080P         | 1 | 1080P预配置。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。  |
| PRECONFIG_4K            | 2 | 4K预配置。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。     |
| PRECONFIG_HIGH_QUALITY  | 3 | 高质量预配置。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。    |
| PRECONFIG_HIGH_QUALITY_PHOTOSESSION_BT2020<sup>23+</sup>  | 4 | 预配置支持预览高动态范围显示和HDR动图拍摄。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。 |

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

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 值 | 说明    |
|-----------|---|---------|
| BEAUTY    | 0 | 美颜。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。   |
| PORTRAIT  | 1 | 人像虚化。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| AUTO_FRAMING<sup>24+</sup> | 2 | 自动对焦。<br> **原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。 |
| COLOR_EFFECT | 3 | 色彩效果。<br>**起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。<br> **原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |

## PhotoQualityPrioritization<sup>21+</sup>

枚举，拍照画质优先策略。

**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 值     | 说明    |
|--------------|-------|---------|
| HIGH_QUALITY | 0     | 画质优先，拍照需要较长的时间，以输出高画质的图片。 |
| SPEED        | 1     | 性能优先，会降低画质来提升拍照的速度。 |

## SensorColorFilterArrangement<sup>24+</sup>

枚举，传感器颜色滤镜排列方式。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值   | 说明                                                              |
| --------------------------- | ---- |-----------------------------------------------------------------|
| BGGR                        | 0    | 蓝绿绿红（Blue-Green-Green-Red）滤镜排列方式。                                                        |
| GBRG                        | 1    | 绿蓝红绿（Green-Blue-Red-Green）滤镜排列方式。                                                           |
| GRBG                        | 2    | 绿红蓝绿（Green-Red-Blue-Green）滤镜排列方式。                                                           |
| RGGB                        | 3    | 红绿绿蓝（Red-Green-Green-Blue）滤镜排列方式。                                                           |

## FlashState<sup>24+</sup>

枚举，闪光灯状态。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| FLASH_STATE_UNAVAILABLE      | 0    | 闪光灯为不可用状态，为默认值。   |
| FLASH_STATE_READY   | 1    | 闪光灯为可用状态。 |
| FLASH_STATE_FLASHING   | 2    | 闪光灯已经被打开。       |

## ExposureMeteringMode<sup>24+</sup>

枚举，曝光测光模式。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| MATRIX      | 0    | 矩阵测光模式。对画面广泛区域进行测光，适合拍摄自然风光。   |
| CENTER   | 1    | 中心测光模式。对整个画面进行测光，但最大比重分配给中央区域，适合拍摄人像。 |
| SPOT   | 2    | 点测光模式。对画面测光点周围约2.5%进行测光，专注于特定微小区域的光线，如被摄主体的眼睛。       |

## OISMode<sup>24+</sup>

枚举，光学防抖（Optical Image Stabilization）模式。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| OFF      | 0    | 光学防抖关闭。   |
| AUTO   | 1    | 光学防抖自动控制。 |
| CUSTOM   | 2    | 光学防抖由应用控制。       |

## OISAxes<sup>24+</sup>

枚举，光学防抖（OIS）轴向。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| PITCH      | 0    | 俯仰轴。控制相机机身上下旋转，即机身围绕与镜头水平方向的轴旋转。   |
| YAW   | 1    | 偏航轴。控制相机机身左右旋转，即机身围绕与镜头垂直方向的轴旋转。 |

## ExposureState

枚举，曝光状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| EXPOSURE_STATE_SCAN       | 0    | 曝光处于扫描状态。     |
| EXPOSURE_STATE_CONVERGED  | 1    | 曝光已经收敛。     |

## AutomotiveCameraPosition

表示Car设备摄像头位置的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_OTHER       | 0    | Car设备外部其他位置摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_FRONT  | 1    | Car设备外部前侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_REAR  | 2    | Car设备外部后侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_LEFT  | 3    | Car设备外部左侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_RIGHT  | 4    | Car设备外部右侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_OTHER  | 5    | Car设备内部其他位置摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_LEFT  | 6    | Car设备内部第一排左侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_CENTER  | 7    | Car设备内部第一排中央摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_RIGHT  | 8    | Car设备内部第一排右侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_LEFT  | 9    | Car设备内部第二排左侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_CENTER  | 10    | Car设备内部第二排中央摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_RIGHT  | 11    | Car设备内部第二排右侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_LEFT  | 12    | Car设备内部第三排左侧摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_CENTER  | 13    | Car设备内部第三排中央摄像头。     |
| AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_RIGHT  | 14    | Car设备内部第三排右侧摄像头。     |