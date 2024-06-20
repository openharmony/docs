# 音视频资源管理对象

开发者可以调用本模块的Native API接口，创建数据资源对象，获取资源属性或进行[解封装](./audio-video-demuxer.md)。

当前支持的数据输入类型有：远程连接(http协议、HLS协议)和文件描述符(fd)。

支持的文件格式如下：

| 媒体格式  | 封装格式                      | 码流格式                      |
| -------- | :----------------------------| :----------------------------|
| 音视频     | mp4                        |<!--RP1-->视频码流：AVC(H.264)、HEVC(H.265)，音频码流：AAC、MPEG(MP3)<!--RP1End-->|
| 音视频     | fmp4                       |<!--RP2-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)<!--RP2End-->|
| 音视频     | mkv                        |<!--RP3-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)、OPUS<!--RP3End-->|
| 音视频     | mpeg-ts                    |<!--RP4-->视频码流：AVC(H.264)，音频码流：AAC、MPEG(MP3)<!--RP4End-->|
| 音视频     | flv                        |<!--RP5-->视频码流：AVC(H.264)，音频码流：AAC<!--RP5End-->|
| 音频       | m4a                        |<!--RP6-->音频码流：AAC<!--RP6End-->|
| 音频       | aac                        |音频码流：AAC|
| 音频       | mp3                        |音频码流：MPEG(MP3)|
| 音频       | ogg                        |音频码流：OGG|
| 音频       | flac                       |音频码流：FLAC|
| 音频       | wav                        |音频码流：PCM|
| 音频       | amr                        |音频码流：AMR(AMR-NB、AMR-WB)|
| 音频       | ape                        |音频码流：APE|
| 外挂字幕   | srt                        |字幕流：SRT|

**适用场景**：

- 播放
  
  播放媒体文件时，需要先创建资源对象，再对资源对象中音视频流进行解封装，然后使用解封装获取的帧数据进行解码和播放。

- 音视频编辑
  
  编辑媒体文件时，需要先创建资源对象，再对资源对象中音视频流进行解封装，获取到指定帧进行编辑。

- 媒体文件格式转换（转封装）

  媒体文件格式转换时，需要先创建资源对象，再对资源对象中音视频流进行解封装，然后按需将音视频流封装至新的格式文件内。

- 文件信息获取
  获取文件信息时，需要先创建资源对象，再从资源对象中获取对应属性信息。

## 开发指导

详细的API说明参考[AVSource](../../reference/apis-avcodec-kit/_a_v_source.md)

> **说明**
>
> - 调用解封装能力解析网络播放路径，需要[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET
> - 调用解封装能力解析本地文件，需要[向用户申请授权](../../security/AccessToken/request-user-authorization.md)：ohos.permission.READ_MEDIA
> - 如果使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法请参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_avsource.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

### 开发步骤

1. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avsource.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <fcntl.h>
   #include <sys/stat.h>
   ```

2. 创建资源管理实例对象。
   ```c++
   // 创建文件操作符 fd，打开时对文件句柄必须有读权限(filePath 为待解封装文件路径，需预置文件，保证路径指向的文件存在)
   std::string filePath = "test.mp4";
   int fd = open(filePath.c_str(), O_RDONLY);
   struct stat fileStatus {};
   size_t fileSize = 0;
   if (stat(filePath.c_str(), &fileStatus) == 0) {
      fileSize = static_cast<size_t>(fileStatus.st_size);
   } else {
      printf("get stat failed");
      return;
   }
   // 为 fd 资源文件创建 source 资源对象, 传入 offset 不为文件起始位置 或 size 不为文件大小时，可能会因不能获取完整数据导致 source 创建失败、或后续解封装失败等问题
   OH_AVSource *source = OH_AVSource_CreateWithFD(fd, 0, fileSize);
   if (source == nullptr) {
      printf("create source failed");
      return;
   }
   // 为 uri 资源文件创建 source 资源对象(可选)
   // OH_AVSource *source = OH_AVSource_CreateWithURI(uri);

   // 为自定义数据源创建 source 资源对象(可选)。使用该方式前，需要先实现AVSourceReadAt接口函数实现。
   // 当使用OH_AVSource_CreateWithDataSource时需要补充g_filePath
   // g_filePath = filePath ;
   // OH_AVDataSource dataSource = {fileSize, AVSourceReadAt};
   // OH_AVSource *source = OH_AVSource_CreateWithDataSource(&dataSource);
   ```

   AVSourceReadAt接口函数，需要放在创建资源管理实例对象前实现：:

   ```c++
   // 添加头文件
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
         return MediaDataSourceError::SOURCE_ERROR_IO;  // 打开文件失败
      }

      infile.seekg(0, std::ios::end);
      int64_t fileSize = infile.tellg();
      if (pos >= fileSize) {
         printf("AVSourceReadAt : pos over or equals file size!\n");
         return MediaDataSourceError::SOURCE_ERROR_EOF;  // pos已经是文件末尾位置，无法读取
      }

      if (pos + length > fileSize) {
         length = fileSize - pos;    // pos+length长度超过文件大小时，读取从pos到文件末尾的数据
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

3. 获取文件级属性（可选，只在获取文件级属性时需要）。

   ```c++
   // 以获取文件轨道数为例，详细查询能力范围参考注释1
   OH_AVFormat *sourceFormat = OH_AVSource_GetSourceFormat(source);
   if (sourceFormat == nullptr) {
      printf("get source format failed");
      return;
   }
   int32_t trackCount = 0;
   OH_AVFormat_GetIntValue(sourceFormat, OH_MD_KEY_TRACK_COUNT, &trackCount);
   OH_AVFormat_Destroy(sourceFormat);
   ```

4. 获取轨道index及信息（可选，只在获取轨道级属性时需要）。

   ```c++
   // 以获取轨道类型为例，详细查询能力范围参考注释2
   int32_t trackType;
   for (uint32_t index = 0; index < (static_cast<uint32_t>(trackCount)); index++) {
      // 获取轨道信息
      OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, index);
      if (trackFormat == nullptr) {
         printf("get track format failed");
         return;
      }
      OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_TRACK_TYPE, &trackType);
      OH_AVFormat_Destroy(trackFormat);
   }
   ```

# 注释
## 注释1：文件级别属性支持范围
| 名称 | 描述 |
| -- | -- |
|OH_MD_KEY_TITLE|源格式标题的键，值类型为string|
|OH_MD_KEY_ARTIST|艺术家的源格式键，值类型为string|
|OH_MD_KEY_ALBUM|相册的源格式键，值类型为string|
|OH_MD_KEY_ALBUM_ARTIST|相册艺术家的键，值类型为string|
|OH_MD_KEY_DATE|源格式日期的键，值类型为string|
|OH_MD_KEY_COMMENT|源格式注释的键，值类型为string|
|OH_MD_KEY_GENRE|源格式类型的键，值类型为string|
|OH_MD_KEY_COPYRIGHT|源格式版权的键，值类型为string|
|OH_MD_KEY_LANGUAGE|源格式语言的键，值类型为string|
|OH_MD_KEY_DESCRIPTION|源格式描述的键，值类型为string|
|OH_MD_KEY_LYRICS|源格式歌词的键，值类型为string|
|OH_MD_KEY_TRACK_COUNT|源格式轨道数量的键，值类型为uint32_t|
|OH_MD_KEY_DURATION|持续时间键，值类型为int64_t|
|OH_MD_KEY_START_TIME|文件开始时间的键，值类型为int64_t|
注：正常解析时才可以获取对应数据，解析异常时无法获取


## 注释2：轨道级别属性支持范围
| 名称 | 描述 | 音频轨支持 | 视频轨支持 | 字幕轨支持 |
| -- | -- | -- | -- | -- |
|OH_MD_KEY_CODEC_MIME|编解码器mime类型的键，值类型为string，在支持范围内时才能获取|√|√|√|
|OH_MD_KEY_TRACK_TYPE|码流媒体类型的键，值类型为uint8_t，在支持范围内时才能获取|√|√|√|
|OH_MD_KEY_BITRATE|码流比特率的键，值类型为int64_t，正常解析时才可以获取对应数据|√|√||
|OH_MD_KEY_LANGUAGE|码流语言类型的键，值类型为string，正常解析时才可以获取对应数据|√|√||
|OH_MD_KEY_CODEC_CONFIG|编解码器特定数据的键，视频中表示传递xps，音频中表示传递extraData，值类型为uint8_t*，正常解析时才可以获取对应数据|√|√||
|OH_MD_KEY_WIDTH|视频宽度的键，值类型为uint32_t|√|||
|OH_MD_KEY_HEIGHT|视频高度键，值类型为uint32_t|√|||
|OH_MD_KEY_FRAME_RATE|视频帧率的键，值类型为double，正常解析时才可以获取对应数据|√|||
|OH_MD_KEY_ROTATION|旋转角度的键，值类型为int32_t，正常解析时才可以获取对应数据|√|||
|OH_MD_KEY_VIDEO_SAR|样本长宽比的键，值类型为double，正常解析时才可以获取对应数据|√|||
|OH_MD_KEY_PROFILE|编码档次，值类型为int32_t，只针对 hevc 码流使用，正常解析时才可以获取对应数据|√|||
|OH_MD_KEY_RANGE_FLAG|视频YUV值域标志的键，值类型为bool，true表示full range，false表示limited range，只针对 hevc 码流使用|√|||
|OH_MD_KEY_COLOR_PRIMARIES|视频色域的键, 值类型为int32_t，只针对 hevc 码流使用|√|||
|OH_MD_KEY_TRANSFER_CHARACTERISTICS|视频传递函数的键，值类型为int32_t，只针对 hevc 码流使用|√|||
|OH_MD_KEY_MATRIX_COEFFICIENTS|视频矩阵系数的键，值类型为int32_t，只针对 hevc 码流使用|√|||
|OH_MD_KEY_VIDEO_IS_HDR_VIVID|是否是hdr vivid的键，值类型为bool，只针对 HDRVivid 码流，该值为true|√|||
|OH_MD_KEY_AUD_SAMPLE_RATE|音频采样率键，值类型为uint32_t，正常解析时才可以获取对应数据||√||
|OH_MD_KEY_AUD_CHANNEL_COUNT|音频通道计数键，值类型为uint32_t，正常解析时才可以获取对应数据||√||
|OH_MD_KEY_CHANNEL_LAYOUT|所需编码通道布局的键。值类型为int64_t||√||
|OH_MD_KEY_AUDIO_SAMPLE_FORMAT|音频原始格式的键，值类型为uint32_t||√||
|OH_MD_KEY_AAC_IS_ADTS|aac格式的键，值类型为uint32_t，只针对 aac 码流使用||√||
|OH_MD_KEY_BITS_PER_CODED_SAMPLE|每个编码样本位数的键，值类型为uint32_t||√||
