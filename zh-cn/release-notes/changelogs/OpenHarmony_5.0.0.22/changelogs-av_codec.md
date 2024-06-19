# 音视频编解码组件 AVCodec 变更说明

## OH_VideoDecoder_Configure、OH_VideoEncoder_Configure 接口行为变更

**访问级别**

公开接口

**变更原因**

编码器传入 `Configure` 接口的参数未进行校验，较多场景下设置无效值不生效、不报错，导致较多效果问题发生，需要添加参数校验进行拦截，确保编解码过程中使用的参数符合编解码器的能力和要求。

**变更影响**

该变更为兼容性变更，影响仅为在 `Configure` 接口中传入错误的参数时，接口报错。
解码器参数校验逻辑可参考此[链接](../../../application-dev/reference/apis-avcodec-kit/_video_decoder.md#oh_videodecoder_configure)；
编码器参数校验逻辑可参考此[链接](../../../application-dev/reference/apis-avcodec-kit/_video_encoder.md#oh_videoencoder_configure)。

**起始 API Level**

API9

**变更发生版本**

API12

**变更的接口/组件**

| 名称                      | 描述                        |
| ------------------------- | --------------------------- |
| OH_VideoDecoder_Configure | 传入无效的参数时，接口将报错 |
| OH_VideoEncoder_Configure | 传入无效的参数时，接口将报错 |

**适配指导**

编码器相关参数范围可通过编解码器能力查询接口获取，链接如下：
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/avcodec/obtain-supported-codecs.md
