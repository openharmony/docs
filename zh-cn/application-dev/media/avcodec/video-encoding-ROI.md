# ROI视频编码

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xhjgc-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 基础概念

ROI视频编码是在现有的硬件编码基础上开放的高级能力，允许开发者自主指定ROI区域，并通过调整ROI区域码率分配优化编码效果。
- ROI区域：ROI（Region of Interest）一般是指视频中引人注目的区域，比如直播中的人脸区域等。
- ROI编码：允许对画面中的ROI区域分配更高的码率，同时适当降低背景等非ROI区域码率，从而在有限带宽条件下提升整体视觉体验。

## 适用场景

具备明显ROI区域的视频编码场景，例如：
- **直播场景**：人脸或商品一般是受关注的重点区域，通过ROI编码能够有效提升该区域的主观清晰度。
- **监控场景**：车牌或人脸一般是受关注的重点区域，通过ROI编码能够保留更清晰的有效信息。

## 约束和限制

- **支持的平台**：Kirin9000及以后。
- **支持的系统**：OpenHarmony6.0及以后。
- **支持的编码器**：H264 8bit硬件编码、H265 8bit硬件编码、H265 10bit硬件编码。
- **支持的码控模式**：VBR、CBR、SQR。
- **支持的编码模式**：Surface模式、Buffer模式。
- 同一帧最多支持配置6个ROI区域，并且总ROI面积不能超过图片面积的1/5。
- 本模块仅提供底层ROI编码能力，不包括ROI区域检测功能。

## 接口介绍

ROI编码接口支持开发者通过字符串形式下发配置参数，参数需满足"Top1,Left1-Bottom1,Right1=Offset1;Top2,Left2-Bottom2,Right2=Offset2;"的格式。<br>
- Top、Left、Bottom、Right分别指定对应ROI区域上、左、下、右边界。
- Offset指定deltaQp并且"=Offset"可以省略，省略时使用默认参数（deltaQp=-3）。
- 多个ROI参数之间通过";"连接，所有参数均为整数。
- 使用前请确保传入参数有效，并尽量避免多个ROI区域之间产生交叠。

|配置参数 |语义 |格式 |
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS |ROI参数 |String|

**注意**
1. 为了便于使用，ROI参数支持随帧下发并实时生效，开发者无需进行能力查询或配置全局开关。
2. 如果底层硬编不支持ROI编码能力，编码器会忽略ROI参数，进行普通编码。
3. deltaQp有效范围[-51，51]，编码器会在块级QP的基础上叠加deltaQp，然后Clip到[minQp，maxQp]范围内得到最终QP。
4. 不通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS下发参数时，该帧会复用历史ROI信息进行编码。
5. 通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS传入空字符串，可以主动关闭ROI编码并清空历史ROI信息，进行普通编码。
6. 通过OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS传入的字符串无法解析出任何有效ROI信息时，ROI编码不生效并清空历史ROI信息，转为普通编码。
7. 如果设置的ROI总面积超过1/5图片大小，ROI编码不生效并清空历史ROI信息，转为普通编码。
8. 如果输入的有效ROI参数超过6个，超过的ROI参数将被忽略。
9. 如果多个ROI区域产生交叠，仅第一个ROI参数会在交叠区域生效。

## 开发指导

基础编码功能请参考[视频编码](video-encoding.md)开发指南，下面仅针对ROI编码做具体说明。

### Surface模式


1. 调用OH_VideoEncoder_RegisterParameterCallback()接口注册随帧通路回调。

    ```c++
    // 1. 编码输入参数回调OH_VideoEncoder_OnNeedInputParameter实现。
    static void OnNeedInputParameter(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
    {
        /**
        * 配置两个ROI区域，并指定对应的deltaQp。
        * ROI1左上角坐标(0, 0)，右下角坐标(64, 128)，调节QP-4。
        * ROI2左上角坐标(200, 100)，右下角坐标(400, 300)，调节QP+3。
        **/
        const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
        OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
        OH_VideoEncoder_PushInputParameter(codec, index);
    }
    // 2. 注册随帧参数回调。
    OH_VideoEncoder_OnNeedInputParameter inParaCb = OnNeedInputParameter;
    OH_VideoEncoder_RegisterParameterCallback(videoEnc, inParaCb, nullptr); // nullptr：用户特定数据userData为空。
    ```

### Buffer模式
   
1. 调用OH_AVBuffer_SetParameter()接口配置随帧参数。

    ```c++
    void OnNeedInputBuffer(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
    {
        /**
        * 配置两个ROI区域，并指定对应的deltaQp。
        * ROI1左上角坐标(0, 0)，右下角坐标(64, 128)，调节QP-4。
        * ROI2左上角坐标(200, 100)，右下角坐标(400, 300)，调节QP+3。
        **/
        const char *roiInfo = "0,0-128,64=-4;100,200-300,400=3";
        OH_AVFormat *parameter = OH_AVBuffer_GetParameter(buffer);
        OH_AVFormat_SetStringValue(parameter, OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS, roiInfo);
        OH_AVBuffer_SetParameter(buffer, parameter);
        OH_AVFormat_Destroy(parameter);

        inQueue.Enqueue(std::make_shared<CodecBufferInfo>(index, buffer));
    }
    ```