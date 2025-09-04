# B帧视频编码

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @jiangfan56-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

从API 20开始，支持B帧视频编码。

**双向预测帧**，又叫B帧（B frame），是视频编码标准中定义的主要帧类型之一。B帧与P帧的主要差别在于P帧仅支持前向预测，而B帧支持双向预测。

B帧编码预测过程同时利用前后帧的信息，可以显著降低信号的时域冗余，具有更高的压缩效率。

使能B帧的影响：
- 使能B帧，会导致P帧编码时域参考帧的距离增加，可能影响P帧的压缩率和画质；一般在时域较复杂的场景要联合考虑P帧和B帧的综合影响；
- 使能B帧，也会增加编码和解码的端到端时延。

## 适用场景

- 录像场景
- 编辑导出场景
- 视频转码场景
- 非低时延直播场景

## 约束和限制

- **支持的平台**：该能力与平台能力有关，可以通过[OH_AVCapability_IsFeatureSupported](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported)接口查询系统支持情况。
- **支持的API版本**：API20及以后。
- **支持的编码器**：该能力与编码器能力有关，可以通过[OH_AVCodec_GetCapabilityByCategory](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcodec_getcapabilitybycategory)接口查询支持情况。
- **支持的码控模式**：VBR、CBR、SQR、CQ。
- 不支持与时域可分层视频编码共同使能。
- 不支持与长期参考帧共同使能。

## 接口介绍

支持B帧编码特性需要在初始阶段配置，全程生效，不支持动态修改。

开发配置参数如下：

|配置参数 |语义 |格式 |
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME |视频编码使能B帧参数。<br>在配置阶段配置，仅特性支持才会真正使能成功。 |int |
|OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES |视频编码支持最大B帧数量。<br>该接口仅供查询。 |int |

## 开发指导

基础编码功能请参考[视频编码](video-encoding.md)开发指南，下面仅针对B帧编码做具体说明。

1. 在初始阶段创建编码实例时，校验当前视频编码器是否支持B帧编码特性。

    ```c++
    // 1.1 获取对应视频编码器能力实例，此处以H.265为例。
    OH_AVCapability *cap = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true, HARDWARE);
    if (cap != nullptr) {
        OH_LOG_INFO("Get codec Capability sucess!");
        // 1.2 通过特性能力查询接口校验是否支持B帧编码特性。
        bool isSupported = OH_AVCapability_IsFeatureSupported(cap, VIDEO_ENCODER_B_FRAME);
        int32_t supportedMaxBFrameCount = 0;
        if (isSupported) {
            OH_LOG_INFO("Feature VIDEO_ENCODER_B_FRAME is Supported!");
            // 1.3 确定支持的最大B帧数量。
            OH_AVFormat *property = OH_AVCapability_GetFeatureProperties(cap, VIDEO_ENCODER_B_FRAME);
            OH_AVFormat_GetIntValue(property, OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES, &supportedMaxBFrameCount);
            OH_LOG_INFO("Get supportedMaxBFrameCount,value is %{public}d!", supportedMaxBFrameCount);
            // 1.4 销毁临时AVFormat。
            OH_AVFormat_Destroy(property);
        } else {
            OH_LOG_ERROR("Feature VIDEO_ENCODER_B_FRAME is not Supported!");
        }
    } else {
        OH_LOG_ERROR("codec Capability is null!");
    }
    ```

    若支持，则可以使能B帧编码特性。

2. 在配置阶段，配置使能B帧编码特性的参数。

    ```c++
    // 2.1 创建配置用临时AVFormat。
    OH_AVFormat *format = OH_AVFormat_Create();
    // 2.2 填充使能参数键值对。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME, 1);
    // 2.3 参数配置。
    int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    // 2.4 配置完成后销毁临时AVFormat。
    OH_AVFormat_Destroy(format);
    ```

    >**注意：**
    > - 使能B帧编码功能在configure环节是弱校验，如果参数配置有误或者编码器不支持特性仍会返回AV_ERR_OK，但会打印Warning信息。请结合码流产物和运行日志判断是否真实使能。
    > - 在使能B帧编码时，实际编码码流中的B帧结构和B帧数量依赖平台能力。
    >