# 媒体数据封装

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

开发者可以调用本模块的Native API接口，完成音视频封装，即将音频、视频等编码后的媒体数据，按一定的格式存储到文件里。

当前支持的封装能力请参考[AVCodec支持的格式](avcodec-support-formats.md#媒体数据封装)。

<!--RP2--><!--RP2End-->

**适用场景**

- 录像、录音
  
  保存录像、录音文件时，需要先对音视频流进行编码，再封装为文件。

- 音视频编辑
  
  完成编辑后的音视频，需要封装为文件。

- 音视频转码

  转码后，保存文件时需要封装。

## 开发指导

详细的API说明请参考[API文档](../../reference/apis-avcodec-kit/capi-native-avmuxer-h.md)。

> **说明：**
>
> 如果调用封装模块写本地文件，需要[向用户申请授权](../../security/AccessToken/request-user-authorization.md)：ohos.permission.READ_MEDIA, ohos.permission.WRITE_MEDIA。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_avmuxer.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

### 开发步骤

参考以下示例代码，完成音视频封装的全流程。以封装mp4格式的音视频文件为例。

不同的封装格式需要配置的key请参考[AVCodec支持的格式](avcodec-support-formats.md#媒体数据封装)。

1. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avmuxer.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   #include <fcntl.h>
   ```

2. 调用OH_AVMuxer_Create()创建封装器实例对象。

   ```c++
   // 设置封装格式为mp4。
   OH_AVOutputFormat format = AV_OUTPUT_FORMAT_MPEG_4;
   // 以读写方式创建fd。
   int32_t fd = open("test.mp4", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
   OH_AVMuxer *muxer = OH_AVMuxer_Create(fd, format);
   ```

3. （可选）调用OH_AVMuxer_SetRotation()设置旋转角度。

   ```c++
   // 旋转角度，视频画面需要旋转的时候设置。
   OH_AVMuxer_SetRotation(muxer, 0);
   ```

4. 添加文件级数据。
   ```c++
   OH_AVFormat *format = OH_AVFormat_Create(); // 用OH_AVFormat_Create创建format。
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_CREATION_TIME, "2024-12-28T00:00:00:000000Z"); // 设置创建时间（使用ISO 8601标准的时间格式且为UTC时间）。
   int ret = OH_AVMuxer_SetFormat(muxer, format); // 设置封装的format。
   if (ret != AV_ERR_OK) {
      // 设置format失败，未找到有效待写入的key数据。
   }
   OH_AVFormat_Destroy(format); // 销毁。
   ```

5. 添加音频轨。

   **方法一：用OH_AVFormat_Create创建format**

   ```c++
   int audioTrackId = -1;
   uint8_t *buffer = ...; // 编码config data，如果没有可以不传。
   size_t size = ...;  // 编码config data的长度，根据实际情况配置。
   OH_AVFormat *formatAudio = OH_AVFormat_Create(); // 用OH_AVFormat_Create创建format，这里以封装44100Hz采样率、2声道的AAC-LC音频为例。
   OH_AVFormat_SetStringValue(formatAudio, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_AUDIO_AAC); // 必填。
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_SAMPLE_RATE, 44100); // 必填。
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_CHANNEL_COUNT, 2); // 必填。
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // 选填。
   OH_AVFormat_SetBuffer(formatAudio, OH_MD_KEY_CODEC_CONFIG, buffer, size); // 选填。
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // 音频轨添加失败。
   }
   OH_AVFormat_Destroy(formatAudio); // 销毁。
   ```

   **方法二：用OH_AVFormat_CreateAudioFormat创建format**

   ```c++
   int audioTrackId = -1;
   uint8_t *buffer = ...; // 编码config data，如果没有可以不传。
   size_t size = ...;  // 编码config data的长度，根据实际情况配置。
   OH_AVFormat *formatAudio = OH_AVFormat_CreateAudioFormat(OH_AVCODEC_MIMETYPE_AUDIO_AAC, 44100, 2);
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // 选填。
   OH_AVFormat_SetBuffer(formatAudio, OH_MD_KEY_CODEC_CONFIG, buffer, size); // 选填。
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // 音频轨添加失败。
   }
   OH_AVFormat_Destroy(formatAudio); // 销毁。
   ```

6. 添加视频轨。

   **方法一：用OH_AVFormat_Create创建format**

   ```c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // 编码config data，如果没有可以不传。
   size_t size = ...;  // 编码config data的长度，根据实际情况配置。
   OH_AVFormat *formatVideo = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatVideo, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_VIDEO_AVC); // 必填。
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_WIDTH, 1280); // 必填。
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_HEIGHT, 720); // 必填。
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // 非必须。
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // 视频轨添加失败。
   }
   OH_AVFormat_Destroy(formatVideo); // 销毁。
   ```

   **方法二：用OH_AVFormat_CreateVideoFormat创建format**

   ```c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // 编码config data，如果没有可以不传。
   size_t size = ...;  // 编码config data的长度，根据实际情况配置。
   OH_AVFormat *formatVideo = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1280, 720);
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // 非必须。
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // 视频轨添加失败。
   }
   OH_AVFormat_Destroy(formatVideo); // 销毁。
   ```

7. 添加辅助轨。
   > **说明：**
   >
   > 设置OH_MD_KEY_TRACK_TYPE时，值为MEDIA_TYPE_AUXILIARY代表添加辅助轨。<br>
   > 设置OH_MD_KEY_TRACK_REFERENCE_TYPE时，值必须为"hint"、"cdsc"、"font"、"hind"、"vdep"、"vplx"、"subt"、"thmb"、"auxl"、"cdtg"、"shsc"或"aest"其中一项。<br>
   > 设置OH_MD_KEY_TRACK_DESCRIPTION时，值必须为"com.openharmony."开头且长度不超过256的字符串。<br>
   > 设置OH_MD_KEY_REFERENCE_TRACK_IDS时，track id值必须大于等于0，且必须是已经存在的track id。

   **添加音频辅助轨**

   ```c++
   int32_t audioAuxlTrackId = -1;
   std::vector<int32_t> audioTrackIDsVector = {0}; // 根据实际情况设置被辅助音频轨的编号，可填写多个值。
   int32_t *audioAuxlTrackIDs = audioTrackIDsVector.data();
   OH_AVFormat *audioAuxlFormat = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_AUDIO_AAC); // 必填。
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_AUD_SAMPLE_RATE, 44100); // 必填。
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_AUD_CHANNEL_COUNT, 2); // 必填。
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // 选填。
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_TRACK_TYPE, static_cast<int32_t>(OH_MediaType::MEDIA_TYPE_AUXILIARY)); // 必填。
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_TRACK_REFERENCE_TYPE, "auxl"); // 必填。
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_TRACK_DESCRIPTION, "com.openharmony.audiomode.auxiliary"); // 必填。
   OH_AVFormat_SetIntBuffer(audioAuxlFormat, OH_MD_KEY_REFERENCE_TRACK_IDS, audioAuxlTrackIDs, audioTrackIDsVector.size()); // 必填。

   int ret = OH_AVMuxer_AddTrack(muxer, &audioAuxlTrackId, audioAuxlFormat);
   if (ret != AV_ERR_OK || audioAuxlTrackId < 0) {
       // 音频辅助轨添加失败。
   }
   ```

   **添加视频辅助轨**

   ```c++
   int32_t videoAuxlTrackId = -1;
   std::vector<int32_t> videoTrackIDsVector = {0}; // 根据实际情况设置被辅助视频轨的编号，可填写多个值。
   int32_t *videoAuxlTrackIDs = videoTrackIDsVector.data();
   OH_AVFormat *videoAuxlFormat = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_VIDEO_AVC); // 必填。
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_WIDTH, 1280); // 必填。
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_HEIGHT, 720); // 必填。
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_TRACK_TYPE, static_cast<int32_t>(OH_MediaType::MEDIA_TYPE_AUXILIARY)); // 必填。
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_TRACK_REFERENCE_TYPE, "vdep"); // 必填。
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_TRACK_DESCRIPTION, "com.openharmony.moviemode.depth"); // 必填。
   OH_AVFormat_SetIntBuffer(videoAuxlFormat, OH_MD_KEY_REFERENCE_TRACK_IDS, videoAuxlTrackIDs, videoTrackIDsVector.size()); // 必填。

   int ret = OH_AVMuxer_AddTrack(muxer, &videoAuxlTrackId, videoAuxlFormat);
   if (ret != AV_ERR_OK || videoAuxlTrackId < 0) {
       // 视频辅助轨添加失败。
   }
   ```

8. 添加封面轨。

   **方法一：用OH_AVFormat_Create创建format**

   ```c++
   int coverTrackId = -1;
   OH_AVFormat *formatCover = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatCover, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_IMAGE_JPG);
   OH_AVFormat_SetIntValue(formatCover, OH_MD_KEY_WIDTH, 1280);
   OH_AVFormat_SetIntValue(formatCover, OH_MD_KEY_HEIGHT, 720);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &coverTrackId, formatCover);
   if (ret != AV_ERR_OK || coverTrackId < 0) {
       // 添加封面失败。
   }
   OH_AVFormat_Destroy(formatCover); // 销毁。
   ```

   **方法二：用OH_AVFormat_CreateVideoFormat创建format**

   ```c++
   int coverTrackId = -1;
   OH_AVFormat *formatCover = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_IMAGE_JPG, 1280, 720);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &coverTrackId, formatCover);
   if (ret != AV_ERR_OK || coverTrackId < 0) {
       // 添加封面失败。
   }
   OH_AVFormat_Destroy(formatCover); // 销毁。
   ```

9. 调用OH_AVMuxer_Start()开始封装。

   ```c++
   // 调用start，写封装文件头。start后，不能设置媒体参数、不能添加音视频轨。
   if (OH_AVMuxer_Start(muxer) != AV_ERR_OK) {
       // 异常处理。
   }
   ```

10. 调用OH_AVMuxer_WriteSampleBuffer()，写入封装数据。

    封装数据包括视频、音频、封面等数据。

    ```c++
    // start后，才能开始写入数据。
    int size = ...;
    OH_AVBuffer *sample = OH_AVBuffer_Create(size); // 创建AVBuffer。
    // 通过OH_AVBuffer_GetAddr(sample)往sampleBuffer里写入数据参考OH_AVBuffer的使用方法。
    // 封装封面，必须一次写完一张图片。
    
    // 创建buffer info。
    OH_AVCodecBufferAttr info = {0};
    info.pts = ...; // 当前数据的开始播放的时间，单位微秒，相对时间。
    info.size = size; // 当前数据的长度。
    info.offset = 0; // 偏移，一般为0。
    info.flags |= AVCODEC_BUFFER_FLAGS_SYNC_FRAME; // 当前数据的标志。具体参考OH_AVCodecBufferFlags。
    info.flags |= AVCODEC_BUFFER_FLAGS_CODEC_DATA; // 当annex-b格式的avc包含codec config的标志。
    OH_AVBuffer_SetBufferAttr(sample, &info); // 设置buffer的属性。
    int trackId = audioTrackId; // 选择写的音视频轨。
    
    int ret = OH_AVMuxer_WriteSampleBuffer(muxer, trackId, sample);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    ```

11. 调用OH_AVMuxer_Stop()，停止封装。

    ```c++
    // 调用stop，写封装文件尾。stop后不能写入媒体数据。
    if (OH_AVMuxer_Stop(muxer) != AV_ERR_OK) {
        // 异常处理。
    }
    ```

12. 调用OH_AVMuxer_Destroy()销毁实例，释放资源。

    注意不能重复销毁，否则将会导致程序崩溃。

    ```c++
    if (OH_AVMuxer_Destroy(muxer) != AV_ERR_OK) {
        // 异常处理。
    }
    muxer = NULL;
    close(fd); // 关闭文件描述符。
    ```
