# B帧视频编码

## 基础概念

**双向预测帧**，又叫B帧（B frame），是视频编码标准中定义的三种主要帧类型之一。B帧与P帧的主要差别在于P帧仅支持前向预测，而B帧支持双向预测。

通过双向预测，B帧同时利用前后帧信息，显著降低时域冗余信号，具有极高的压缩效率。在码率充足且运动平缓、光照稳定的场景中，B帧的精确预测能减少残差数据，从而提升视频压缩效率，降低因量化导致的块效应（Blocking Artifacts），提升运动连续性；但若码率过低，双向预测可能放大Artifacts。

## 适用场景

除对时延要求极高的场景外，其他场景均可使用，但需考虑时延增加、内存开销和功耗上升对业务场景的影响。

## 约束和限制

- **支持的平台**：该能力与平台能力有关，可以通过[OH_AVCapability_IsFeatureSupported](../../reference/apis-avcodec-kit/_a_v_capability.md#oh_avcapability_isfeaturesupported)接口查询系统支持情况。
- **支持的系统**：OpenHarmony6.0及以后。
- **支持的编码器**：该能力与编码器能力有关，可以通过[OH_AVCodec_GetCapabilityByCategory](../../reference/apis-avcodec-kit/_a_v_capability.md#oh_avcodec_getcapabilitybycategory)接口查询支持情况。
- **支持的码控模式**：VBR、CBR、SQR、CQ。
- 不支持与时域可分层视频编码共同使能。
- 不支持与长期参考帧共同使能。

## 接口介绍

支持B帧编码特性、初始配置、全局生效，不支持动态修改。

开发配置参数如下：

|配置参数 |语义 |格式 |
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME |视频编码使能B帧参数。<br>在配置阶段配置，仅特性支持才会真正使能成功。 |Int |
|OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES |视频编码支持最大B帧数量。<br>该接口仅供查询。 |Int |

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
    // 2.4 参数配置。
    int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    // 2.5 配置完成后销毁临时AVFormat。
    OH_AVFormat_Destroy(format);
    ```

    >**注意：**
    > - 使能B帧编码功能在configure环节是弱校验，如果参数配置有误或者编码器不支持特性仍会返回AV_ERR_OK，但会打印Warning信息。请结合码流产物和运行日志判断是否真实使能。
    > - 在使能B帧编码时，GOP会呈现帧结构：编码器自适应的对每4帧选择使用PBBB或者PPPP结构。
    >