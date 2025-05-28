# ROI编码

## 基础概念

### ROI区域
ROI(Region of Interest)，指的是图像或视频中引人注目的区域，比如直播中的人脸区域等。

### ROI编码
ROI编码是一种视频/图像编码技术，允许对画面中特定区域分配更多码率，从而提高这些区域的画质。在下发ROI编码参数成功后，编码器会根据用户指定的deltaQp，来调整ROI区域内的块级QP，从而实现ROI编码。ROI区域叠加的QP受其他码控和deltaQp的综合影响。

## 适用场景
具备明显ROI区域的视频编码场景都可以使用，例如：
- **直播场景**：例如人脸或商品一般是受关注的重点区域，通过ROI编码能够有效提升该区域的主观清晰度。
- **监控场景**：例如车牌或人脸一般是受关注的重点区域，通过ROI编码能够保留更清晰的有效信息。

## 约束和限制
- **支持的平台**：Kirin9000及以后。
- **支持的系统**：OpenHarmony6.0及以后。
- **支持的编码器**：H264 8bit硬编、H265 8bit硬编、H265 10bit硬编。
- **支持的码控模式**：VBR、CBR、SQR。
- **支持的编码模式**：Surface模式、Buffer模式。
- 同一帧最多支持配置6个ROI区域，并且总ROI面积不能超过图片面积的1/5。
- 同一个ROI区域仅支持指定一个deltaQp。
- 本模块仅提供底层ROI编码能力，不包括ROI区域检测功能，ROI信息需要用户主动下发。

## 开发指南

### 接口介绍
考虑到视频中的ROI区域位置经常会发生变化，ROI参数仅支持随帧下发，并且随帧生效。同时为了方便开发者使用，省略能力查询接口或全局开关配置，用户通过随帧参数下发正确ROI信息即可实时生效。如若底层硬件不支持，则会主动忽略ROI配置，不会影响正常编码。相关接口如下：

|配置参数 |语义 |格式 |
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS |配置ROI参数 |String|

**注意**
1. ROI参数需满足"Top1,Left1-Bottom1,Right1=Offset1;Top2,Left2-Bottom2,Right2=Offset2;..."格式；
2. Top,Left,Bottom,Right指定ROI区域，Offset指定deltaQp（范围[-51,51]），所有参数均为整数，请确保传入信息有效，并避免区域交叠；
3. Offset指定的deltaQp为相对QP，"=Offset1"可以省略，省略时使用默认参数（deltaQp=-3）进行ROI编码；
4. 不通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS下发参数时，该帧会复用历史ROI信息进行编码；
5. 通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS传入空字符串，可以主动关闭ROI编码并清空历史ROI信息，进行普通编码；
6. 通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS传入的字符串无法解析出任何有效ROI信息时，ROI编码不生效并清空历史ROI信息，转为普通编码；
7. 如果设置的ROI总面积超过1/5图片大小，ROI编码不生效并清空历史ROI信息，转为普通编码；
8. 叠加deltaQp之后得到的最终QP将会被Clip到[minQp,maxQp]范围内；

### 开发指导
基础编码功能请参考[视频编码开发指南](video-encoding.md)，下面仅针对ROI编码做具体说明。
#### Surface模式
Step1.编码器配置阶段，调用 **OH_VideoEncoder_RegisterParameterCallback()** 在Configure接口之前注册随帧通路回调
```cpp
int32_t VideoEncoderAPI11::SetCallback(uintptr_t *const sampleContext)
{
    CHECK_AND_RETURN_RET_LOG(codec_ != nullptr, AVCODEC_SAMPLE_ERR_ERROR, "Encoder is null");

    int32_t ret = OH_VideoEncoder_RegisterCallback(codec_.get(), AVCodecCallback, sampleContext);
    CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, AVCODEC_SAMPLE_ERR_ERROR, "Set callback failed, ret: %{public}d", ret);

    SampleContext *context = reinterpret_cast<SampleContext *>(sampleContext);
    if (context != nullptr && context->sampleInfo->codecRunMode == API11_SURFACE) {
        ret = OH_VideoEncoder_RegisterParameterCallback(codec_.get(), CodecCallback::OnNeedInputParameter, sampleContext);
        CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, AVCODEC_SAMPLE_ERR_ERROR, "Set parameter callback failed, ret: %{public}d", ret);
    }
    return AVCODEC_SAMPLE_ERR_OK;
}
```
Step2.在回调函数中的随帧ROI信息可以通过userData结构体从外部传入，这里仅展示如何下发给编码器
```cpp
void CodecCallback::OnNeedInputParameter(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
{
    SampleContext *context = static_cast<SampleContext *>(userData);
    /**
    * 配置两个ROI区域，并指定对应的deltaQp；
    * ROI1左上角坐标(0,0)，右下角坐标(64,128)，调节QP-4
    * ROI2左上角坐标(200,100)，右下角坐标(400,300)，调节QP+3
    **/
    const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
    OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
    OH_VideoEncoder_PushInputParameter(codec, index);
}
```

#### Buffer模式
```cpp
void CodecCallback::OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVFormat *buffer,  void *userData)
{
    SampleContext *context = static_cast<SampleContext *>(userData);
    /**
    * 配置两个ROI区域，并指定对应的deltaQp；
    * ROI1左上角坐标(0,0)，右下角坐标(64,128)，调节QP-4
    * ROI2左上角坐标(200,100)，右下角坐标(400,300)，调节QP+3
    **/
    const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
    OH_AVFormat *parameter = OH_AVBuffer_GetParameter(buffer);
    OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
    OH_AVBuffer_SetParameter(buffer, parameter) == AV_ERR_OK ? (0) : (errCount++);
    OH_AVFormat_Destroy(parameter);

    CodecBufferInfo bufferInfo = CodecBufferInfo(index, buffer);
    context->inputBufferQueue.QueueBuffer(bufferInfo);
}
```