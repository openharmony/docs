# Native API Differences

Compared with earlier versions, OpenHarmony 4.0.8.5 has the following API changes in its native APIs:
 *
## Standard System API Changes

| Module| API                                                    | Change Type| Change Description            |
| -------- | ------------------------------------------------------------ | -------- | -------------------- |
| avmuxer  | OH_AVMuxer \*OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format); | Added    | This API is added to create an **OH_AVMuxer** instance.      |
| avmuxer  | OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer \*muxer, int32_t rotation); | Added    | This API is added to set the rotation angle of an output video.    |
| avmuxer  | OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat); | Added    | This API is added to add a media track.          |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer \*muxer);           | Added    | This API is added to start encapsulation.            |
| avmuxer  | OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info); | Added    | This API is added to write data to the muxer.    |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer \*muxer);            | Added    | This API is added to stop encapsulation.            |
| avmuxer  | OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer \*muxer);         | Added    | This API is added to destroy an **OH_AVMuxer** instance.      |
| avsource  | OH_AVSource *OH_AVSource_CreateWithURI(char *uri);         | Added    | This API is added to create an **OH_AVSource** instance based on a URI.      |
| avsource  | OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size);         | Added    | This API is added to create an **OH_AVSource** instance based on a file descriptor (FD).      |
| avsource  | OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source);         | Added    | This API is added to destroy an **OH_AVSource** instance.      |
| avsource  | OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source);         | Added    | This API is added to obtain source information.      |
| avsource  | OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackCount);         | Added    | This API is added to obtain track information.      |
| avdemuxer  | OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source);         | Added    | This API is added to create an **OH_AVDemuxer** instance based on source information.      |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer);         | Added    | This API is added to destroy an **OH_AVDemuxer** instance.      |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex);         | Added    | This API is added to select a track, from which the demuxer reads data.     |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex);         | Added    | This API is added to deselect a track.      |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info);         | Added    | This API is added to read the frame from a track specified by **trackIndex**.    |
| avdemuxer  | OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode);         | Added    | This API is added to seek to the specified time.      |
|avcapability|OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder);|Added|This API is added to obtain a handle to the codec capability recommended by the system.|
|avcapability|OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category);|Added|This API is added to obtain a handle to the codec capability by category, which can be a hardware codec or software codec.|
|avcapability|bool OH_AVCapability_IsHardware(OH_AVCapability *capability);|Added|This API is added to check whether a codec capability instance describes a hardware codec.|
|avcapability|const char *OH_AVCapability_GetName(OH_AVCapability *capability);|Added|This API is added to obtain the codec name.|
|avcapability|int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability);|Added|This API is added to obtain the maximum number of codec instances supported by a codec.|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange);|Added|This API is added to obtain the bit rate range supported by an encoder.|
|avcapability|bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode);|Added|This API is added to check whether a specific bit rate mode is supported.|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange);|Added|This API is added to obtain the quality range supported by an encoder.|
|avcapability|OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange);|Added|This API is added to obtain the complexity range supported by an encoder.|
|avcapability|OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum);|Added|This API is added to obtain the sampling rates supported by an audio codec.|
|avcapability|OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange);|Added|This API is added to obtain the count range of audio channels supported by an audio codec.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment);|Added|This API is added to obtain the video width alignment.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment);|Added|This API is added to obtain the video height alignment.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange);|Added|This API is added to obtain the video width range based on a given height.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange);|Added|This API is added to obtain the video height range based on a given width.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange);|Added|This API is added to obtain the video width range.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange);|Added|This API is added to obtain the video height range.|
|avcapability|bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height);|Added|This API is added to check whether a video size is supported.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange);|Added|This API is added to obtain the video frame rate range.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange);|Added|This API is added to obtain the video frame rate range based on a given size.|
|avcapability|bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate);|Added|This API is added to check whether the combination of a video size and frame rate is supported.|
|avcapability|OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixFormats, uint32_t *pixFormatNum);|Added|This API is added to obtain the video pixel formats supported.|
|avcapability|OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum);|Added|This API is added to obtain the profiles supported.|
|avcapability|OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels,uint32_t *levelNum);|Added|This API is added to obtain the codec levels supported by a profile.|
|avcapability|bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level);|Added|This API is added to check whether the combination of a profile and level is supported.|
|avformat|struct OH_AVFormat \*OH_AVFormat_CreateAudioFormat(const char \*mimeType, int32_t sampleRate, int32_t channelCount);|Added|This API is added to create an **OH_AVFormat** instance for an audio track (used in **avmuxer**).|
|avformat|struct OH_AVFormat \*OH_AVFormat_CreateVideoFormat(const char \*mimeType, int32_t width, int32_t height);|Added|This API is added to create an **OH_AVFormat** instance for a video track (used in avmuxer).|
|avmemory|OH_AVMemory \*OH_AVMemory_Create(int32_t size);|Added|This API is added to create an **OH_AVMemory** instance.|
|avmemory|OH_AVErrCode OH_AVMemory_Destroy(struct OH_AVMemory \*mem);|Added|This API is added to destroy an **OH_AVMemory** instance.|
| avcodec | OH_AVErrCode OH_AudioDecoder_IsValid(OH_AVCodec \*codec, bool \*isValid); | Added| This API is added to check whether a codec instance is valid. It is used for fault rectification.|
| avcodec | OH_AVErrCode OH_AudioEncoder_IsValid(OH_AVCodec \*codec, bool \*isValid); | Added| This API is added to check whether a codec instance is valid. It is used for fault rectification.|
| avcodec  | OH_AVErrCode OH_VideoDecoder_IsValid(OH_AVCodec \*codec, bool \*isValid);         | Added    | This API is added to check whether a codec instance is valid.     |
| avcodec  | OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec \*codec, bool \*isValid);         | Added    | This API is added to check whether a codec instance is valid.     |
| avcodec  | OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr);         | Added    | This API is added to push the input buffer filled with data to a video encoder.     |
| avcodec  | OH_AVFormat \*OH_VideoEncoder_GetInputDescription(OH_AVCodec \*codec);         | Added    | This API is added to obtain the description received by a video encoder.     |
