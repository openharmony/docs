# 转码常见问题

## 应用发送视频进行转码，音频编码格式为什么变化

在转码过程中，若未指定音频轨道格式，系统默认将其转换为AAC编码格式。

<!--RP2--><!--RP2End-->

## 调用系统提供的转码能力失败后如何处理

1. 需要确认视频与设置的目标视频格式当前转码系统能力是否支持。

   当前转码能力支持情况：[AVTranscoder支持规格](media-kit-intro.md#avtranscoder)、[AVCodec支持规格](../avcodec/avcodec-support-formats.md)<!--RP1--><!--RP1End-->

2. 应用在收到error事件后，建议发送原视频；应用在收到complete事件后，建议先调用release再对转码后的视频做发送、上云等操作。
