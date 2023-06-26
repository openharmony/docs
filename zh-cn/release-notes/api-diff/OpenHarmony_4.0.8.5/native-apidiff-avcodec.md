# Native API 差异报告

OpenHarmony 4.0.8.5 版本相较于OpenHarmony 之前的版本的API变更如下:
 *
## 标准系统接口变更

| 模块名称 | 接口名称                                                     | 变更类型 | 变更说明             |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| avmuxer  | OH_AVMuxer \*OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format); | 新增     | 创建OH_AVMuxer       |
| avmuxer  | OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer \*muxer, int32_t rotation); | 新增     | 设置视频旋转角度     |
| avmuxer  | OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat); | 新增     | 添加媒体轨           |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer \*muxer);           | 新增     | 开始封装             |
| avmuxer  | OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info); | 新增     | 将数据写入封装器     |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer \*muxer);            | 新增     | 停止封装             |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer \*muxer);         | 新增     | 销毁OH_AVMuxer       |
| avsource  | OH_AVSource *OH_AVSource_CreateWithURI(char *uri);         | 新增     | 根据 URI 创建 OH_AVSource       |
| avsource  | OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size);         | 新增     | 根据 FD 创建OH_AVSource       |
| avsource  | OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source);         | 新增     | 销毁 OH_AVSource       |
| avsource  | OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source);         | 新增     | 获取 source 信息       |
| avsource  | OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackCount);         | 新增     | 获取 track 信息       |
| avdemuxer  | OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source);         | 新增     | 根据 source 创建 OH_AVDemuxer       |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer);         | 新增     | 销毁 OH_AVDemuxer       |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex);         | 新增     | 选择需要解封装的轨道      |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex);         | 新增     | 取消选择需要解封装的轨道       |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info);         | 新增     | 读取 trackIndex 对应轨道的帧     |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode);         | 新增     | 跳转到指定时间       |
|avcapability|OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder);|新增|获取系统推荐的能力句柄|
|avcapability|OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category);|新增|获取系统指定软硬件的能力句柄|
|avcapability|bool OH_AVCapability_IsHardware(OH_AVCapability *capability);|新增|确认是否是硬件编解码器|
|avcapability|const char *OH_AVCapability_GetName(OH_AVCapability *capability);|新增|获取codec名字|
|avcapability|int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability);|新增|获取最大支持的实例数|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange);|新增|获取编码支持的码率范围|
|avcapability|bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode);|新增|确认码控模式是否支持|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange);|新增|获取编码质量范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange);|新增|获取编码复杂度范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum);|新增|获取支持的音频采样率|
|avcapability|OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange);|新增|获取音频通道数范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment);|新增|获取视频宽对齐|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment);|新增|获取视频高对齐|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange);|新增|获取特定高情况下视频宽范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange);|新增|获取特定宽情况下视频高范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange);|新增|获取视频宽范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange);|新增|获取视频高范围|
|avcapability|bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height);|新增|确认当前视频尺寸是否支持|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange);|新增|获取视频帧率范围|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange);|新增|获取特定尺寸下视频帧率范围|
|avcapability|bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate);|新增|确认当前视频尺寸和帧率是否支持|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixFormats, uint32_t *pixFormatNum);|新增|获取支持的视频像素格式|
|avcapability|OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum);|新增|获取支持的模板|
|avcapability|OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels,uint32_t *levelNum);|新增|获取特定模板情况下的等级范围|
|avcapability|bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level);|新增|确认当前模板和等级是否支持|
|avformat|struct OH_AVFormat \*OH_AVFormat_CreateAudioFormat(const char \*mimeType, int32_t sampleRate, int32_t channelCount);|新增|创建音频轨的OH_AVFormat（用于avmuxer）|
|avformat|struct OH_AVFormat \*OH_AVFormat_CreateVideoFormat(const char \*mimeType, int32_t width, int32_t height);|新增|创建视频轨的OH_AVFormat（用于avmuxer）|
|avmemory|OH_AVMemory \*OH_AVMemory_Create(int32_t size);|新增|创建OH_AVMemory|
|avmemory|OH_AVErrCode OH_AVMemory_Destroy(struct OH_AVMemory \*mem);|新增|销毁OH_AVMemory|
| avcodec | OH_AVErrCode OH_AudioDecoder_IsValid(OH_AVCodec \*codec, bool \*isValid); | 新增 | 查询当前codec实例是否有效, 可用于故障恢复 |
| avcodec | OH_AVErrCode OH_AudioEncoder_IsValid(OH_AVCodec \*codec, bool \*isValid); | 新增 | 查询当前codec实例是否有效, 可用于故障恢复 |
| avcodec  | OH_AVErrCode OH_VideoDecoder_IsValid(OH_AVCodec \*codec, bool \*isValid);         | 新增     | 查询当前codec实例是否有效      |
| avcodec  | OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec \*codec, bool \*isValid);         | 新增     | 查询当前codec实例是否有效      |
| avcodec  | OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr);         | 新增     | 将填入数据的输入缓冲区提交给视频编码器      |
| avcodec  | OH_AVFormat \*OH_VideoEncoder_GetInputDescription(OH_AVCodec \*codec);         | 新增     | 获取视频编码器接收的描述信息      |