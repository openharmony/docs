# multimedia子系统变更说明

## cl.multimedia.1 	OH_AVCodecOnStreamChanged在音频解码场景的默认行为变更

**访问级别**

公开接口

**变更原因**

音频解码存在采样率等参数发生变化的场景，需要回调通知调用者。

**变更影响**

此变更不涉及应用适配。

变更前：应用通过OH_AudioCodec_RegisterCallback注册了OH_AVCodecOnStreamChanged回调，音频解码发生采样率、声道数等格式变化时，未触发该回调。

变更后：应用通过OH_AudioCodec_RegisterCallback注册了OH_AVCodecOnStreamChanged回调，音频解码发生采样率、声道数等格式变化时，会触发该回调。

**起始 API Level**

9

**变更发生的版本**

从OpenHarmony SDK 5.1.0.50 版本开始。

**变更的接口/组件**

native_avcodec_audiocodec.h 下的接口OH_AudioCodec_RegisterCallback注册的native_avcodec_base.h 下的OH_AVCodecOnStreamChanged。

**适配指导**

默认行为变更，无需适配。