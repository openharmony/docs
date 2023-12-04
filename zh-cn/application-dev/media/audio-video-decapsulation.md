# 音视频解封装

开发者可以调用本模块的Native API接口，完成音视频解封装，即从比特流数据中取出音频、视频等媒体帧数据。

当前支持的数据输入类型有：远程连接(http协议)和文件描述符(fd)。

支持的解封装格式如下：

| 媒体格式  | 封装格式                      |
| -------- | :----------------------------|
| 视频     | mp4、mpeg-ts                  |
| 音频      | m4a、aac、mp3、ogg、flac、wav |

**适用场景**：

- 播放
  
  播放媒体文件时，需要先对音视频流进行解封装，然后使用解封装获取的帧数据进行解码和播放。

- 音视频编辑
  
  编辑媒体文件时，需要先对音视频流进行解封装，获取到指定帧进行编辑。

- 媒体文件格式转换（转封装）

  媒体文件格式转换时，需要先对音视频流进行解封装，然后按需将音视频流封装至新的格式文件内。

## 开发指导

详细的API说明参考[AVDemuxer](../reference/native-apis/_a_v_demuxer.md)和[AVSource](../reference/native-apis/_a_v_source.md)

> **说明**
>
> - 调用解封装能力解析网络播放路径，需要[申请相关权限](../security/accesstoken-guidelines.md)：ohos.permission.INTERNET
> - 调用解封装能力解析本地文件，需要[申请相关权限](../security/accesstoken-guidelines.md)：ohos.permission.READ_MEDIA
> - 如果使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法请参考[ResourceManager API参考](../reference/apis/js-apis-resource-manager.md#getrawfd9)

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_avdemuxer.so)
target_link_libraries(sample PUBLIC libnative_media_avsource.so)
```

### 开发步骤

1. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avdemuxer.h>
   #include <multimedia/player_framework/native_avsource.h>
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   ```

2. 创建解封装器实例对象。

   ``` c++
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
   ```

   ```c++
   // 为资源对象创建对应的解封装器
   OH_AVDemuxer *demuxer = OH_AVDemuxer_CreateWithSource(source);
   if (demuxer == nullptr) {
      printf("create demuxer failed");
      return;
   }
   ```

3. 获取文件轨道数（可选，若用户已知轨道信息，可跳过此步）。

   ``` c++
   // 从文件 source 信息获取文件轨道数
   OH_AVFormat *sourceFormat = OH_AVSource_GetSourceFormat(source);
   if (sourceFormat == nullptr) {
      printf("get source format failed");
      return;
   }
   int32_t trackCount = 0;
   OH_AVFormat_GetIntValue(sourceFormat, OH_MD_KEY_TRACK_COUNT, &trackCount);
   OH_AVFormat_Destroy(sourceFormat);
   ```

4. 获取轨道index及信息（可选，若用户已知轨道信息，可跳过此步）。

   ``` c++
   uint32_t audioTrackIndex = 0;
   uint32_t videoTrackIndex = 0;
   int32_t w = 0;
   int32_t h = 0;
   int32_t trackType;
   for (uint32_t index = 0; index < (static_cast<uint32_t>(trackCount)); index++) {
      // 获取轨道信息
      OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, index);
      if (trackFormat == nullptr) {
         printf("get track format failed");
         return;
      }
      OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_TRACK_TYPE, &trackType);
      static_cast<OH_MediaType>(trackType) == OH_MediaType::MEDIA_TYPE_AUD ? audioTrackIndex = index : videoTrackIndex = index;
      // 获取视频轨宽高
      if (trackType == OH_MediaType::MEDIA_TYPE_VID) {
         OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_WIDTH, &w);
         OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_HEIGHT, &h);
      }
      OH_AVFormat_Destroy(trackFormat);
   }
   ```

5. 添加解封装轨道。

   ``` c++
   if(OH_AVDemuxer_SelectTrackByID(demuxer, audioTrackIndex) != AV_ERR_OK){
      printf("select audio track failed: %d", audioTrackIndex);
      return;
   }
   if(OH_AVDemuxer_SelectTrackByID(demuxer, videoTrackIndex) != AV_ERR_OK){
      printf("select video track failed: %d", videoTrackIndex);
      return;
   }
   // 取消选择轨道(可选)
   // OH_AVDemuxer_UnselectTrackByID(demuxer, audioTrackIndex);
   ```

6. 调整轨道到指定时间点(可选)。

   ``` c++
   // 调整轨道到指定时间点，后续从该时间点进行解封装
   // 注意：
   // 1. mpegts格式文件使用OH_AVDemuxer_SeekToTime功能时，跳转到的位置可能为非关键帧。可在跳转后调用OH_AVDemuxer_ReadSample，通过获取到的OH_AVCodecBufferAttr判断当前帧是否为关键帧。若非关键帧影响应用侧显示等功能，可在跳转后循环读取，获取到后续第一帧关键帧后，再进行解码等处理。
   // 2. ogg格式文件使用OH_AVDemuxer_SeekToTime功能时，会跳转到传入时间millisecond所在时间间隔(秒)的起始处，可能会导致一定数量的帧误差。
   OH_AVDemuxer_SeekToTime(demuxer, 0, OH_AVSeekMode::SEEK_MODE_CLOSEST_SYNC);
   ```

7. 开始解封装，循环获取帧数据(以含音频、视频两轨的文件为例)。

   ``` c++
   // 创建 buffer，用与保存用户解封装得到的数据
   OH_AVMemory *buffer = OH_AVMemory_Create(w * h * 3 >> 1);
   if (buffer == nullptr) {
      printf("build buffer failed");
      return;
   }
   OH_AVCodecBufferAttr info;
   bool videoIsEnd = false;
   bool audioIsEnd = false;
   int32_t ret;
   while (!audioIsEnd || !videoIsEnd) {
      // 在调用 OH_AVDemuxer_ReadSample 接口获取数据前，需要先调用 OH_AVDemuxer_SelectTrackByID 选中需要获取数据的轨道
      // 获取音频帧数据
      if(!audioIsEnd) {
         ret = OH_AVDemuxer_ReadSample(demuxer, audioTrackIndex, buffer, &info);
         if (ret == AV_ERR_OK) {
            // 可通过 buffer 获取并处理音频帧数据
            printf("audio info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               audioIsEnd = true;
            }
         }
      }
      if(!videoIsEnd) {
         ret = OH_AVDemuxer_ReadSample(demuxer, videoTrackIndex, buffer, &info);
         if (ret == AV_ERR_OK) {
            // 可通过 buffer 获取并处理视频帧数据
            printf("video info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               videoIsEnd = true;
            }
         }
      }
   }
   OH_AVMemory_Destroy(buffer);
   ```

8. 销毁解封装实例。

   ``` c++
   // 需要用户调用 OH_AVSource_Destroy 接口成功后，手动将对象置为 NULL，对同一对象重复调用 OH_AVSource_Destroy 会导致程序错误
   if (OH_AVSource_Destroy(source) != AV_ERR_OK) {
      printf("destroy source pointer error");
   }
   source = NULL;
   // 需要用户调用 OH_AVDemuxer_Destroy 接口成功后，手动将对象置为 NULL，对同一对象重复调用 OH_AVDemuxer_Destroy 会导致程序错误
   if (OH_AVDemuxer_Destroy(demuxer) != AV_ERR_OK) {
      printf("destroy demuxer pointer error");
   }
   demuxer = NULL;
   close(fd);
   ```
