# 编码支持前处理

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

从API版本26.0.0开始，支持编码前处理功能，包含降采样、裁剪和丢帧能力。

## 功能简介

编码前处理是视频编码器在输入帧进入编码管线之前执行的预处理能力，通过[OH_VideoEncoder_CreatePrimaryWithPreproc](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc)创建的主编码器支持以下三种前处理功能：

| 功能 | 说明 | 典型场景 |
|------|------|----------|
| 降采样（Downsampling） | 将高分辨率帧缩放到低分辨率后送入编码器。 | 低分辨率编码输出。 |
| 裁剪（Crop） | 从原始画面中提取指定矩形区域进行编码。 | ROI区域关注、局部特写。 |
| 丢帧（Drop Frame） | 按目标帧率选择性丢弃输入帧。 | 降低带宽占用、自适应码率。 |

**互斥规则**：降采样参数与裁剪参数**不能同时使用**。丢帧可与降采样或裁剪**组合使用**。


### 使用场景

**场景一：低分辨率编码输出**

通过降采样缩放到低分辨率编码输出。

**场景二：ROI区域关注编码**

- 对大尺寸摄像头画面使用**裁剪**功能，仅提取感兴趣区域进行编码。

**场景三：自适应码率（ABR）**

- 网络正常时：不丢帧或轻度丢帧，保证画质。
- 网络拥堵时：通过`SetParameter`动态加大丢帧力度，降低输出帧率以节省带宽。
- 网络恢复后：将丢帧目标设为`0.00`取消丢帧。

### 约束与限制

**基本约束**

| 约束项 | 说明 |
|--------|------|
| 支持的MIME类型 | 和普通视频编码器支持范围一致，可通过`OH_AVCodec_GetCapability`查询是否支持指定MIME类型编码器。 |
| 创建方式 | 必须通过`OH_VideoEncoder_CreatePrimaryWithPreproc`创建，不支持普通创建方式。 |
| 数据通路 | **仅支持Surface异步模式**，Buffer模式和同步模式均不支持（返回`AV_ERR_OPERATE_NOT_PERMIT`）。 |
| 随帧参数 | 不支持`RegisterParameterCallback`接口（返回`AV_ERR_OPERATE_NOT_PERMIT`）。 |

**降采样（Downsampling）约束**

| 序号 | 约束规则 |
|------|----------|
| 1 | 必须成对配置：降采样目标宽度和降采样目标高度必须同时配置或同时设置。若仅配置其中一个，Configure/SetParameter将返回`AV_ERR_INVALID_VAL`。 |
| 2 | 关闭条件：当降采样目标宽度与降采样目标高度均配置为合法的零值时，降采样功能被关闭。 |
| 3 | 有效范围：当降采样目标宽度与降采样目标高度在支持的范围内时，降采样功能被启用。建议通过`OH_AVCapability_IsVideoSizeSupported`接口查询支持的降采样范围。 |
| 4 | 越界处理：当降采样目标宽度或降采样目标高度不在支持范围内时，Configure/SetParameter返回`AV_ERR_INVALID_VAL`。 |
| 5 | 与裁剪互斥：不能与裁剪参数（`CROP_LEFT/TOP/RIGHT/BOTTOM`）同时使用。若同时设置了降采样和裁剪参数，返回`AV_ERR_INVALID_VAL`。 |

**裁剪（Crop）约束**

坐标系统说明：
- `(left, top)`为裁剪矩形的左上角坐标。
- `(right, bottom)`为裁剪矩形的右下角坐标。
- 行/列索引从**0**开始。
- **裁剪区域宽度 = right - left + 1**。
- **裁剪区域高度 = bottom - top + 1**。

| 序号 | 约束规则 |
|------|----------|
| 1 | 必须完整配置：left、top、right、bottom四个参数必须同时配置。若仅配置其中部分参数，返回`AV_ERR_INVALID_VAL`。 |
| 2 | 关闭条件：当 left、top、right、bottom**全部为0**时，裁剪功能被关闭。 |
| 3 | 有效范围：当裁剪区域宽度、高度在支持的范围内时，裁剪功能被启用。建议通过`OH_AVCapability_IsVideoSizeSupported`查询支持的裁剪范围。 |
| 4 | 越界处理：当裁剪区域宽度、高度不在支持范围内时，返回`AV_ERR_INVALID_VAL`。 |
| 5 | 与降采样互斥：不能与降采样参数（`DOWNSAMPLING_WIDTH/HEIGHT`）同时使用。若同时设置，返回`AV_ERR_INVALID_VAL`。 |
| 6 | 行为效果：裁剪启用时，编码器仅对输入帧的裁剪区域进行编码，裁剪矩形之外的内容将被丢弃。 |

**丢帧（Drop Frame）约束**

| 序号 | 约束规则 |
|------|----------|
| 1 | 前置条件：调用方必须已设置原始帧率（`OH_MD_KEY_FRAME_RATE`）。 |
| 2 | 精度要求：数值精度保留到小数点后**2位**（采用**四舍五入**方式）。 |
| 3 | 值为0.00：丢帧功能被关闭。 |
| 4 | 合法正值：设置为大于0且小于原始帧率的正数时，将按设定帧率进行丢帧。 |
| 5 | 非法值：设置为负数或大于等于原始帧率的值时，返回`AV_ERR_INVALID_VAL`。 |
| 6 | 可组合性：可与降采样参数**同时使用**。 |
| 7 | 可组合性：可与裁剪参数**同时使用**。|

**接口可用性约束**

对于通过OH_VideoEncoder_CreatePrimaryWithPreproc创建的编码器，以下接口的可用性如下：

| 接口 | 是否可用 | 备注 |
|------|:--------:|------|
| [OH_VideoEncoder_RegisterCallback](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_registercallback) | √ | 支持。 |
| [OH_VideoEncoder_RegisterParameterCallback](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_registerparametercallback) | × | 不支持随帧参数配置，返回AV_ERR_OPERATE_NOT_PERMIT。 |
| [OH_VideoEncoder_PushInputParameter](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputparameter) | × | 不支持随帧参数配置，返回AV_ERR_OPERATE_NOT_PERMIT。 |
| [OH_VideoEncoder_Configure](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure) | √ | 支持，可配置含前处理参数。 |
| [OH_VideoEncoder_GetSurface](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getsurface) | √ | 支持。 |
| [OH_VideoEncoder_Prepare](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_prepare) | √ | 支持，准备内部资源。 |
| [OH_VideoEncoder_Start](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_start) | √ | 支持。 |
| [OH_VideoEncoder_Stop](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_stop) | √ | 支持。 |
| [OH_VideoEncoder_Flush](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_flush) | √ | 支持。 |
| [OH_VideoEncoder_Reset](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_reset) | √ | 支持，重置到 Initialized状态。 |
| [OH_VideoEncoder_SetParameter](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_setparameter) | √ | 支持，运行时动态调整前处理等参数。 |
| [OH_VideoEncoder_NotifyEndOfStream](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_notifyendofstream) | √ | 支持，通知编码器EOS信息。 |
| [OH_VideoEncoder_FreeOutputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_freeoutputbuffer) | √ | 支持。 |
| [OH_VideoEncoder_GetInputDescription](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) | √ | 支持，包含前处理元数据。 |
| [OH_VideoEncoder_GetOutputDescription](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputdescription) | √ | 支持。 |
| [OH_VideoEncoder_IsValid](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_isvalid) | √ | 支持。 |
| [OH_VideoEncoder_Destroy](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_destroy) | √ | 支持，销毁编码器实例。 |
| [OH_VideoEncoder_PushInputData](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputdata)  | × | Buffer模式不支持。 |
| [OH_VideoEncoder_PushInputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputbuffer) | × | Buffer模式不支持。 |
| [OH_VideoEncoder_QueryInputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_queryinputbuffer) | × | 同步模式不支持。 |
| [OH_VideoEncoder_QueryOutputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_queryoutputbuffer) | × | 同步模式不支持。 |

## 开发步骤

支持前处理编码和普通编码器的使用流程一致，主要差异点在于创建方式、支持前处理参数配置以及动态更新。本文主要对差异点进行详细说明。完整编码器开发流程参考视频编码[Surface模式](video-encoding.md#surface模式)。

### 创建支持前处理的编码器

在创建前处理编码器之前，建议先通过能力查询接口确认当前编码器是否支持所需的前处理特性：
```c++
const char *mime = OH_AVCODEC_MIMETYPE_VIDEO_AVC;

OH_AVCapability *capability = OH_AVCodec_GetCapability(mime, true);
if (capability == nullptr) {
    return -1; // 获取能力失败，可能是不支持的MIME类型。
}

// 查询是否支持降采样前处理特性。
bool supportDownsampling = OH_AVCapability_IsFeatureSupported(capability,
    VIDEO_ENCODER_PREPROC_DOWNSAMPLING);

// 查询是否支持裁剪前处理特性。
bool supportCrop = OH_AVCapability_IsFeatureSupported(capability,
    VIDEO_ENCODER_PREPROC_CROP);

OH_AVCodec *encoder = nullptr;
OH_AVErrCode ret = OH_VideoEncoder_CreatePrimaryWithPreproc(mime, &encoder);
if (ret != AV_ERR_OK || encoder == nullptr) {
    // 异常处理。
    return -1;
}
```

### 注册回调

参考视频编码[Surface模式](video-encoding.md#surface模式)的“步骤3-调用OH_VideoEncoder_RegisterCallback()设置回调函数”。

### 配置编码参数与前处理参数

编码器参数配置参考视频编码[Surface模式](video-encoding.md#surface模式)的“步骤5-调用OH_VideoEncoder_Configure()配置编码器”。以下内容重点说明基础参数与前处理参数的配置。

```c++
OH_AVFormat *format = OH_AVFormat_Create();

// 基础编码参数（必填）。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920);         // 输入图像的宽度。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080);        // 输入图像的高度。
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // 原始帧率（丢帧功能的前置依赖）。

// 前处理参数（按需选用，先通过IsFeatureSupported确认特性支持后再配置）。
// 方案A：降采样示例。
// 以下示例为将1920x1080缩放到640x360后编码。
// 注意：width和height必须成对出现。
if (supportDownsampling) {
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, 640); // 降采样目标宽度。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT, 360); // 降采样目标高度。
}

// 方案B：裁剪示例。
// 以下示例为从1920x1080中裁剪中心1280x720区域。
// 注意：left/top/right/bottom 必须全部同时出现。
// 降采样与裁剪互斥，不能同时使用。
// 举例：left = 320, top = 180, right = 1599, bottom = 899; 对应：宽=1599-320+1=1280, 高=899-180+1=720。
// if (supportCrop) {
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT, 320);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP, 180);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT, 1599);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM, 899);
// }

// 方案C：丢帧示例。
// 以下示例为从30fps降到15fps（可单独使用或与降采样/裁剪组合）。
// OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, 15.0);

// 执行配置。
OH_AVErrCode ret = OH_VideoEncoder_Configure(encoder, format);
if (ret != AV_ERR_OK) {
    // 错误处理。
    OH_AVFormat_Destroy(format);
    return -1;
}
OH_AVFormat_Destroy(format);
```

### 获取 Surface

```c++
// 关键：只能通过主编码器句柄获取Surface。
OHNativeWindow *window = nullptr;
OH_AVErrCode ret = OH_VideoEncoder_GetSurface(encoder, &window);
if (ret != AV_ERR_OK || window == nullptr) {
    // 异常处理
    return -1;
}

// 将window绑定到Camera/XComponent等数据源。
// 例如：cameraManager->SetPreviewSurface(window)。
//       nativeXComponent->SetSurface(window)。
```

> **重要规则**：
> - **仅主编码器**可以调用`GetSurface`，副编码器调用将返回`AV_ERR_OPERATE_NOT_PERMIT`。
> - 对于一入二出场景，只需获取一次Surface即可（主/副共享同一输入源）。

### 准备、启动、写入编码图像
参考视频编码[Surface模式](video-encoding.md#surface模式)的步骤7、8、10。

### 运行时动态调整（可选）

可通过`SetParameter`在运行时动态修改前处理参数：

```c++
// 动态调整丢帧目标帧率（例如响应网络状态变化）。
// 网络拥堵可以选择大幅丢帧，如：AdjustDropFrameRate(encoder, 10.0);
// 网络恢复可取消丢帧：AdjustDropFrameRate(encoder, 0.0);
void AdjustDropFrameRate(OH_AVCodec *enc, double targetFps)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    if (targetFps > 0) {
        OH_AVFormat_SetDoubleValue(param,
            OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, targetFps);
    } else {
        // 设置为0.00关闭丢帧功能。
        OH_AVFormat_SetDoubleValue(param,
            OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, 0.0);
    }
    OH_VideoEncoder_SetParameter(enc, param);
    OH_AVFormat_Destroy(param);
}

// 动态调整降采样目标尺寸。
void AdjustDownsampling(OH_AVCodec *enc, int newWidth, int newHeight)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, newWidth);
    OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT, newHeight);
    OH_VideoEncoder_SetParameter(enc, param);
    OH_AVFormat_Destroy(param);
}
```
其他编码器仍可动态配置，参考视频编码[Surface模式](video-encoding.md#surface模式)的步骤9。

### 通知编码结束、释放编码帧、销毁编码器
和普通编码器一致，参考视频编码[Surface模式](video-encoding.md#surface模式)的步骤12、13、17。

## GetInputDescription查询

启用前处理后，可通过`GetInputDescription`查询预处理后的实际输入信息及配置参数：

```c++
OH_AVFormat *inputDesc = OH_VideoEncoder_GetInputDescription(encoder);
if (inputDesc != nullptr) {
    int32_t originWidth = 0, originHeight = 0;
    OH_AVFormat_GetIntValue(inputDesc, OH_MD_KEY_WIDTH, &originWidth);
    OH_AVFormat_GetIntValue(inputDesc, OH_MD_KEY_HEIGHT, &originHeight);

    // 可查询当前生效的前处理配置参数。
    int32_t dsWidth = 0;
    if (OH_AVFormat_GetIntValue(inputDesc,
        OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, &dsWidth)) {
    }
}
```



