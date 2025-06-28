# 媒体数据解析

开发者可以调用本模块的Native API接口，完成媒体数据的解封装相关操作，即从比特流数据中取出音频、视频、字幕等媒体sample，获得DRM相关信息。

当前支持的数据输入类型有：远程连接(http协议)和文件描述符(fd)。

当前支持的解封装格式请参考[AVCodec支持的格式](avcodec-support-formats.md#媒体数据解析)。

**适用场景**：

- 播放
  
  播放媒体文件时，需要先对媒体流进行解封装，然后使用解封装获取的sample进行解码和播放。

- 音视频编辑
  
  编辑媒体文件时，需要先对媒体流进行解封装，获取到指定sample进行编辑。

- 媒体文件格式转换（转封装）

  媒体文件格式转换时，需要先对媒体流进行解封装，然后按需将媒体流封装至新的格式文件内。

## 开发指导

详细的API说明参考[AVDemuxer](../../reference/apis-avcodec-kit/_a_v_demuxer.md)和[AVSource](../../reference/apis-avcodec-kit/_a_v_source.md)

> **说明**
>
> - 调用解封装能力解析网络播放路径，需要[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET
> - 调用解封装能力解析本地文件，需要[向用户申请授权](../../security/AccessToken/request-user-authorization.md)：ohos.permission.READ_MEDIA
> - 如果使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法请参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_avdemuxer.so)
target_link_libraries(sample PUBLIC libnative_media_avsource.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

> **说明：**
>
> 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。
>

### 开发步骤

1. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avdemuxer.h>
   #include <multimedia/player_framework/native_avsource.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   #include <fcntl.h>
   #include <sys/stat.h>
   ```

2. 创建资源管理实例。

   开发者HAP中使用open获取fd时，filepath需要转换为[沙箱路径](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)，才能获取沙盒资源。

   ```c++
   // 创建文件操作符 fd，打开时对文件实例必须有读权限（filePath 为待解封装文件路径，需预置文件，保证路径指向的文件存在）。
   std::string filePath = "test.mp4";
   int32_t fd = open(filePath.c_str(), O_RDONLY);
   struct stat fileStatus {};
   int64_t fileSize = 0;
   if (stat(filePath.c_str(), &fileStatus) == 0) {
      fileSize = static_cast<int64_t>(fileStatus.st_size);
   } else {
      printf("get stat failed");
      return;
   }
   // 为 fd 资源文件创建 source 资源实例, 传入 offset 不为文件起始位置或 size 不为文件大小时，可能会因不能获取完整数据导致 source 创建失败、或后续解封装失败等问题。
   OH_AVSource *source = OH_AVSource_CreateWithFD(fd, 0, fileSize);
   if (source == nullptr) {
      printf("create source failed");
      return;
   }
   // 为 uri 资源文件创建 source 资源实例（可选）。
   // OH_AVSource *source = OH_AVSource_CreateWithURI(uri);

   // 为自定义数据源创建 source 资源实例（可选）。使用该方式前，需要先实现AVSourceReadAt接口函数实现。
   // 当使用OH_AVSource_CreateWithDataSource时需要补充g_filePath。
   // g_filePath = filePath ;
   // OH_AVDataSource dataSource = {fileSize, AVSourceReadAt};
   // OH_AVSource *source = OH_AVSource_CreateWithDataSource(&dataSource);
   ```

   AVSourceReadAt接口函数，需要放在创建资源管理实例前实现：

   ```c++
   // 添加头文件。
   #include <fstream>
   ```

   ```c++
   static std::string g_filePath;

   enum MediaDataSourceError : int32_t {
      SOURCE_ERROR_IO = -2,
      SOURCE_ERROR_EOF = -1
   };

   int32_t AVSourceReadAt(OH_AVBuffer *data, int32_t length, int64_t pos)
   {
      if (data == nullptr) {
         printf("AVSourceReadAt : data is nullptr!\n");
         return MediaDataSourceError::SOURCE_ERROR_IO;
      }

      std::ifstream infile(g_filePath, std::ofstream::binary);
      if (!infile.is_open()) {
         printf("AVSourceReadAt : open file failed! file:%s\n", g_filePath.c_str());
         return MediaDataSourceError::SOURCE_ERROR_IO;  // 打开文件失败。
      }

      infile.seekg(0, std::ios::end);
      int64_t fileSize = infile.tellg();
      if (pos >= fileSize) {
         printf("AVSourceReadAt : pos over or equals file size!\n");
         return MediaDataSourceError::SOURCE_ERROR_EOF;  // pos已经是文件末尾位置，无法读取。
      }

      if (pos + length > fileSize) {
         length = fileSize - pos;    // pos+length长度超过文件大小时，读取从pos到文件末尾的数据。
      }

      infile.seekg(pos, std::ios::beg);
      if (length <= 0) {
         printf("AVSourceReadAt : raed length less than zero!\n");
         return MediaDataSourceError::SOURCE_ERROR_IO;
      }
      char* buffer = new char[length];
      infile.read(buffer, length);
      infile.close();

      memcpy(reinterpret_cast<char *>(OH_AVBuffer_GetAddr(data)),
         buffer, length);
      delete[] buffer;

      return length;
   }
   ```
3. 创建解封装器实例。
   ```c++
   // 为资源实例创建对应的解封装器。
   OH_AVDemuxer *demuxer = OH_AVDemuxer_CreateWithSource(source);
   if (demuxer == nullptr) {
      printf("create demuxer failed");
      return;
   }
   ```
4. 注册[DRM信息监听函数](../../reference/apis-avcodec-kit/_a_v_demuxer.md#demuxer_mediakeysysteminfocallback)（可选，若非DRM码流或已获得[DRM信息](../../reference/apis-drm-kit/_drm.md#drm_mediakeysysteminfo)，可跳过此步）。

   设置DRM信息监听的接口，回调函数支持返回解封装器实例，适用于多个解封装器场景。

   ```c++
   // DRM信息监听回调OnDrmInfoChangedWithObj实现。
   static void OnDrmInfoChangedWithObj(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *drmInfo)
   {
      // 解析DRM信息，包括数量、DRM类型及对应pssh。
   }

   Demuxer_MediaKeySystemInfoCallback callback = &OnDrmInfoChangedWithObj;
   Drm_ErrCode ret = OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(demuxer, callback);
   ```
   在监听到DRM信息后，也可主动调用获取DRM信息(uuid及对应pssh)接口。

   ```c++
   DRM_MediaKeySystemInfo mediaKeySystemInfo;
   OH_AVDemuxer_GetMediaKeySystemInfo(demuxer, &mediaKeySystemInfo);
   ```
   在获取、解析DRM信息后，需创建对应DRM解决方案的[MediaKeySystem、MediaKeySession](../drm/drm-c-dev-guide.md)，获取DRM许可证等。并根据需要设置音频解密配置(详见[音频解码开发指南开发步骤](audio-decoding.md#开发步骤)第4步)、设置视频解密配置（详见[视频解码开发指南开发步骤Surface模式](video-decoding.md#surface模式)第5步或[Buffer模式](video-decoding.md#buffer模式)第4步），实现DRM内容解密。

5. 获取文件信息。

   ```c++
   // 获取文件用户自定义属性（可选，若用户无需获取自定义属性，可跳过此步）。
   // 从文件 source 获取用户自定义属性信息。
   OH_AVFormat *customMetadataFormat = OH_AVSource_GetCustomMetadataFormat(source);
   if (customMetadataFormat == nullptr) {
      printf("get custom metadata format failed");
      return;
   }
   // 注意事项：
   // 1. customKey需与封装时写入的key完全一致（含完整命名层级），
   //    示例key仅为演示，实际应替换为用户自定义的字符串。
   //    例：封装时写入key为"com.openharmony.custom.meta.abc.efg"，
   //       获取时必须使用完整key，截断使用"com.openharmony.custom.meta.abc"会失败。
   // 2. value类型需与封装时数据类型匹配（示例为string类型，int/float类型需调用对应接口）。
   const char *customKey = "com.openharmony.custom.meta.string"; // 替换为实际封装时使用的完整key。
   const char *customValue;
   if (!OH_AVFormat_GetStringValue(customMetadataFormat, customKey, &customValue)) {
      printf("get custom metadata from custom metadata format failed");
      return;
   }
   OH_AVFormat_Destroy(customMetadataFormat);

   // 获取文件轨道数（可选，若用户已知轨道信息，可跳过此步）。
   // 从文件 source 信息获取文件轨道数，用户可通过该接口获取文件级别属性，具体支持信息参考附表 1。
   OH_AVFormat *sourceFormat = OH_AVSource_GetSourceFormat(source);
   if (sourceFormat == nullptr) {
      printf("get source format failed");
      return;
   }
   int32_t trackCount = 0;
   if (!OH_AVFormat_GetIntValue(sourceFormat, OH_MD_KEY_TRACK_COUNT, &trackCount)) {
      printf("get track count from source format failed");
      return;
   }
   OH_AVFormat_Destroy(sourceFormat);
   ```

6. 获取轨道index及信息（可选，若用户已知轨道信息，可跳过此步）。

   ```c++
   uint32_t audioTrackIndex = 0;
   uint32_t videoTrackIndex = 0;
   int32_t w = 0;
   int32_t h = 0;
   int64_t bitRate = 0; // 配置比特率，单位为bps。
   double frameRate = 0.0;
   const char* mimetype = nullptr;
   uint8_t *codecConfig = nullptr;
   size_t bufferSize = 0;
   int32_t trackType;
   for (uint32_t index = 0; index < (static_cast<uint32_t>(trackCount)); index++) {
      // 获取轨道信息，用户可通过该接口获取对应轨道级别属性，具体支持信息参考附表 2。
      OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, index);
      if (trackFormat == nullptr) {
         printf("get track format failed");
         return;
      }
      if (!OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_TRACK_TYPE, &trackType)) {
         printf("get track type from track format failed");
         return;
      }
      static_cast<OH_MediaType>(trackType) == OH_MediaType::MEDIA_TYPE_AUD ? audioTrackIndex = index : videoTrackIndex = index;
      // 获取视频轨宽高。
      if (trackType == OH_MediaType::MEDIA_TYPE_VID) {
         if (!OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_WIDTH, &w)) {
            printf("get track width from track format failed");
            return;
         }
         if (!OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_HEIGHT, &h)) {
            printf("get track height from track format failed");
            return;
         }
         if (!OH_AVFormat_GetLongValue(format, OH_MD_KEY_BITRATE, &bitRate)) {
            printf("get track bitRate from track format failed");
            return;
         }
         if (!OH_AVFormat_GetDoubleValue(format, OH_MD_KEY_FRAME_RATE, &frameRate)) {
            printf("get track frameRate from track format failed");
            return;
         }
         if (!OH_AVFormat_GetStringValue(format, OH_MD_KEY_CODEC_MIME, &mimetype)) {
            printf("get track mimetype from track format failed");
            return;
         }
         if (!OH_AVFormat_GetBuffer(format, OH_MD_KEY_CODEC_CONFIG, &codecConfig, &bufferSize)) {
            printf("get track codecConfig from track format failed");
            return;
         }
         printf(" track width%d, track height：%d, track bitRate：%ld, track frameRate：%f, track mimetype：%s\n", w, h, bitRate, frameRate, mimetype);
      }
      OH_AVFormat_Destroy(trackFormat);
   }
   ```

7. 添加解封装轨道。

   ```c++
   if(OH_AVDemuxer_SelectTrackByID(demuxer, audioTrackIndex) != AV_ERR_OK){
      printf("select audio track failed: %d", audioTrackIndex);
      return;
   }
   if(OH_AVDemuxer_SelectTrackByID(demuxer, videoTrackIndex) != AV_ERR_OK){
      printf("select video track failed: %d", videoTrackIndex);
      return;
   }
   // 取消选择轨道（可选）。
   // OH_AVDemuxer_UnselectTrackByID(demuxer, audioTrackIndex);
   ```

8. 调整轨道到指定时间点（可选）。

   ```c++
   // 调整轨道到指定时间点，后续从该时间点进行解封装。
   // 注意：
   // 1. mpegts、mpg 格式文件使用OH_AVDemuxer_SeekToTime功能时，跳转到的位置可能为非关键帧。可在跳转后调用OH_AVDemuxer_ReadSampleBuffer，通过获取到的OH_AVCodecBufferAttr判断当前帧是否为关键帧。若非关键帧影响应用侧显示等功能，可在跳转后循环读取，获取到后续第一帧关键帧后，再进行解码等处理。
   // 2. ogg格式文件使用OH_AVDemuxer_SeekToTime功能时，会跳转到传入时间millisecond所在时间间隔(秒)的起始处，可能会导致一定数量的帧误差。
   // 3. demuxer的seek处理只针对解码行为一致的码流进行处理，如果seek后需要解码器重新配置参数，或者需要重新送入参数集的数据才可以正确解码的码流，seek后可能会出现花屏、解码卡死等问题。
   OH_AVDemuxer_SeekToTime(demuxer, 0, OH_AVSeekMode::SEEK_MODE_CLOSEST_SYNC);
   ```

9. 开始解封装，循环获取sample（以含音频、视频两轨的文件为例）。

   BufferAttr包含的属性：
   - size：sample尺寸；
   - offset：数据在AVBuffer中的偏移，一般为0；
   - pts：文件封装的显示时间戳；
   - flags：sample属性。

   | flag | 描述 |
   | -------- | -------- |
   | AVCODEC_BUFFER_FLAGS_NONE | 默认。 |
   | AVCODEC_BUFFER_FLAGS_EOS | 结尾sample，数据为空。 |
   | AVCODEC_BUFFER_FLAGS_SYNC_FRAME | IDR帧或I帧。 |
   | AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME | 非完整的sample，一般由于buffer过小，无法拷贝完整的sample。 |
   | AVCODEC_BUFFER_FLAGS_CODEC_DATA | 含参数集信息的帧。 |
   | AVCODEC_BUFFER_FLAGS_DISCARD  | 可丢弃的帧。 |

   OH_AVDemuxer_ReadSampleBuffer接口本身可能存在耗时久，取决于文件IO，建议以异步方式进行调用。
   ```c++
   // 为每个线程定义处理函数。
   void ReadTrackSamples(OH_AVFormatDemuxer *demuxer, uint32_t trackIndex, int buffer_size, 
                         std::atomic<bool>& isEnd, std::atomic<bool>& threadFinished)
   {
      // 创建缓冲区。
      OH_AVBuffer *buffer = OH_AVBuffer_Create(buffer_size);
      if (buffer == nullptr) {
         printf("Create buffer failed for track %d\n", trackIndex);
         threadFinished.store(true);
         return;
      }
      OH_AVCodecBufferAttr info;
      int32_t ret;

      while (!isEnd.load()) {
         ret = OH_AVDemuxer_ReadSampleBuffer(demuxer, trackIndex, buffer);
         if (ret == AV_ERR_OK) {
               OH_AVBuffer_GetBufferAttr(buffer, &info);
               printf("Track %d sample size: %d\n", trackIndex, info.size);
               // 检查EOS标志。
               if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
                  isEnd.store(true);
               }
               // 处理缓冲区数据（这里可以根据需要实现解码逻辑）。
         } else {
               printf("Read sample failed for track %d\n", trackIndex);
         }
         // 销毁缓冲区。
         OH_AVBuffer_Destroy(buffer);
         buffer = nullptr;
      }
      threadFinished.store(true);
   }

   // 根据需求计算合适的缓冲区大小。
   int audioBufferSize = 4096;  // 典型音频缓冲区大小。
   int videoBufferSize = w * h * 3 >> 1;  // 原始视频缓冲区大小。

   // 创建原子变量用于线程通信。
   std::atomic<bool> audioIsEnd{false}, videoIsEnd{false}; // 表示流是否结束。
   std::atomic<bool> audioThreadFinished{false}, videoThreadFinished{false}; // 表示线程是否暂停。

   // 创建线程。
   std::thread audioThread(ReadTrackSamples, demuxer, audioTrackIndex, audioBufferSize, 
                           std::ref(audioIsEnd), std::ref(audioThreadFinished));
   std::thread videoThread(ReadTrackSamples, demuxer, videoTrackIndex, videoBufferSize, 
                           std::ref(videoIsEnd), std::ref(videoThreadFinished));
   audioThread.join();
   videoThread.join();
   ```

10. 销毁解封装实例。
      ```c++
      // 需要用户调用 OH_AVSource_Destroy 接口成功后，手动将实例置为nullptr，对同一实例重复调用 OH_AVSource_Destroy 会导致程序错误。
      if (OH_AVSource_Destroy(source) != AV_ERR_OK) {
         printf("destroy source pointer error");
      }
      source = nullptr;
      // 需要用户调用 OH_AVDemuxer_Destroy 接口成功后，手动将实例置为nullptr，对同一实例重复调用 OH_AVDemuxer_Destroy 会导致程序错误。
      if (OH_AVDemuxer_Destroy(demuxer) != AV_ERR_OK) {
         printf("destroy demuxer pointer error");
      }
      demuxer = nullptr;
      close(fd);
      ```

## 附表
### 文件级别属性支持范围

> **说明：**
> 正常解析时才可以获取对应属性数据，如果文件信息错误或缺失，将导致解析异常，无法获取数据。
> 当前GBK格式字符集数据会转换为UTF8提供，其他类型字符集如果需要转换为UTF8格式使用，需要调用方自行转换，参考[icu4c](../../reference/native-lib/icu4c.md)。
> 
> 数据类型及详细取值范围参考[媒体数据键值对](../../reference/apis-avcodec-kit/_codec_base.md#媒体数据键值对)。

**表1** 文件级别属性支持范围
| 名称 | 描述 |
| -- | -- |
|OH_MD_KEY_TITLE|文件标题的键|
|OH_MD_KEY_ARTIST|文件艺术家的键|
|OH_MD_KEY_ALBUM|文件专辑的键|
|OH_MD_KEY_ALBUM_ARTIST|文件专辑艺术家的键|
|OH_MD_KEY_DATE|文件日期的键|
|OH_MD_KEY_COMMENT|文件注释的键|
|OH_MD_KEY_GENRE|文件流派的键|
|OH_MD_KEY_COPYRIGHT|文件版权的键|
|OH_MD_KEY_LANGUAGE|文件语言的键|
|OH_MD_KEY_DESCRIPTION|文件描述的键|
|OH_MD_KEY_LYRICS|文件歌词的键|
|OH_MD_KEY_TRACK_COUNT|文件轨道数量的键|
|OH_MD_KEY_DURATION|文件时长的键|
|OH_MD_KEY_START_TIME|文件起始时间的键|

### 轨道级别属性支持范围

> **说明：**
> 正常解析时才可以获取对应属性数据；如果文件信息错误或缺失，将导致解析异常，无法获取数据。
> 
> 数据类型及详细取值范围参考[媒体数据键值对](../../reference/apis-avcodec-kit/_codec_base.md#媒体数据键值对)。

**表2** 轨道级别属性支持范围
| 名称 | 描述 | 视频轨支持 | 音频轨支持 | 字幕轨支持 |
| -- | -- | -- | -- | -- |
|OH_MD_KEY_CODEC_MIME|码流编解码器类型的键|√|√|√|
|OH_MD_KEY_TRACK_TYPE|码流媒体类型的键|√|√|√|
|OH_MD_KEY_TRACK_START_TIME|码流起始时间的键|√|√|√|
|OH_MD_KEY_BITRATE|码流比特率的键|√|√|-|
|OH_MD_KEY_LANGUAGE|码流语言类型的键|√|√|-|
|OH_MD_KEY_CODEC_CONFIG|编解码器特定数据的键，视频中表示传递参数集，音频中表示传递解码器的参数配置信息|√|√|-|
|OH_MD_KEY_WIDTH|视频流宽度的键|√|-|-|
|OH_MD_KEY_HEIGHT|视频流高度的键|√|-|-|
|OH_MD_KEY_FRAME_RATE|视频流帧率的键|√|-|-|
|OH_MD_KEY_ROTATION|视频流旋转角度的键|√|-|-|
|OH_MD_KEY_VIDEO_SAR|视频流样本长宽比的键|√|-|-|
|OH_MD_KEY_PROFILE|视频流编码档次，只针对 h265 码流使用|√|-|-|
|OH_MD_KEY_RANGE_FLAG|视频流视频YUV值域标志的键，只针对 h265 码流使用|√|-|-|
|OH_MD_KEY_COLOR_PRIMARIES|视频流视频色域的键，只针对 h265 码流使用|√|-|-|
|OH_MD_KEY_TRANSFER_CHARACTERISTICS|视频流视频传递函数的键，只针对 h265 码流使用|√|-|-|
|OH_MD_KEY_MATRIX_COEFFICIENTS|视频矩阵系数的键，只针对 h265 码流使用|√|-|-|
|OH_MD_KEY_VIDEO_IS_HDR_VIVID|视频流标记是否为 HDRVivid 的键，只针对 HDRVivid 码流使用|√|-|-|
|OH_MD_KEY_AUD_SAMPLE_RATE|音频流采样率的键|-|√|-|
|OH_MD_KEY_AUD_CHANNEL_COUNT|音频流通道数的键|-|√|-|
|OH_MD_KEY_CHANNEL_LAYOUT|音频流所需编码通道布局的键|-|√|-|
|OH_MD_KEY_AUDIO_SAMPLE_FORMAT|音频流样本格式的键|-|√|-|
|OH_MD_KEY_AAC_IS_ADTS|aac格式的键，只针对 aac 码流使用|-|√|-|
|OH_MD_KEY_BITS_PER_CODED_SAMPLE|音频流每个编码样本位数的键|-|√|-|