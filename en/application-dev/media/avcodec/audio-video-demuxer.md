# Audio and Video Demuxing

You can call the native APIs provided by the **AVDemuxer** module to demux audio and video, that is, to extract audio and video frame data from bit stream data.

Currently, two data input types are supported: remote connection (over HTTP or HLS) and File Descriptor (FD).

The following demuxing formats are supported:

| Media Format | Muxing Format                     | Stream Format                     |
| -------- | :----------------------------| :----------------------------|
| Audio/Video    | mp4                        |<!--RP1-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3); subtitle stream: WEBVTT<!--RP1End-->|
| Audio/Video    | fmp4                       |<!--RP2-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3)<!--RP2End-->|
| Audio/Video    | mkv                        |<!--RP3-->Video stream: AVC (H.264); audio stream: AAC, MPEG (MP3), and OPUS<!--RP3End-->|
| Audio/Video    | mpeg-ts                    |<!--RP4-->Video stream: AVC (H.264); audio stream: AAC and MPEG (MP3)<!--RP4End-->|
| Audio/Video    | flv                        |<!--RP5-->Video stream: AVC (H.264); audio stream: AAC<!--RP5End-->|
| Audio      | m4a                        |<!--RP6-->Audio stream: AAC<!--RP6End-->|
| Audio      | aac                        |Audio stream: AAC|
| Audio      | mp3                        |Audio stream: MPEG (MP3)|
| Audio      | ogg                        |Audio stream: OGG|
| Audio      | flac                       |Audio stream: FLAC|
| Audio      | wav                        |Audio stream: PCM and PCM-MULAW|
| Audio      | amr                        |Audio stream: AMR (AMR-NB and AMR-WB)|
| Audio      | ape                        |Audio stream: APE|
| External subtitle  | srt                        |Subtitle stream: SRT|
| External subtitle  | webvtt                     |Subtitle stream: WEBVTT|

The DRM demuxting capability supports the following formats: <!--RP7-->mp4 (H.264 and AAC) and mpeg-ts (H.264 and AAC)<!--RP7End-->.

**Usage Scenario**

- Audio and video playback
  
  Demux audio and video streams, decode the frame data obtained through demuxing, and play the decoded data.

- Audio and video editing
  
  Demux audio and video streams, and edit the specified frames.

- Media file format conversion

  Demux audio and video streams, and encapsulate them into a new file format.

## How to Develop

Read [AVDemuxer](../../reference/apis-avcodec-kit/_a_v_demuxer.md) and [AVSource](../../reference/apis-avcodec-kit/_a_v_source.md) for the API reference.

> **NOTE**
>
> - To call the demuxer APIs to parse a network playback path, declare the **ohos.permission.INTERNET** permission by following the instructions provided in [Declaring Permissions](../../security/AccessToken/declare-permissions.md).
> - To call the demuxer APIs to write a local file, request the **ohos.permission.READ_MEDIA** permission by following the instructions provided in [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
> - You can also use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_avdemuxer.so)
target_link_libraries(sample PUBLIC libnative_media_avsource.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
>

### How to Develop

1. Add the header files.

   ```c++
   #include <multimedia/player_framework/native_avdemuxer.h>
   #include <multimedia/player_framework/native_avsource.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   #include <fcntl.h>
   #include <sys/stat.h>
   ```

2. Create a resource object.
   ```c++
   // Create the FD. You must have the read permission on the file handle when opening the file. (filePath indicates the path of the file to be demuxed. The file must exist.)
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
   // Create a source resource object for the FD resource file. If offset is not the start position of the file or size is not the actual file size, the data obtained may be incomplete. Consequently, the source resource object may fail to create or subsequent demuxing may fail.
   OH_AVSource *source = OH_AVSource_CreateWithFD(fd, 0, fileSize);
   if (source == nullptr) {
      printf("create source failed");
      return;
   }
   // (Optional) Create a source resource object for the URI resource file.
   // OH_AVSource *source = OH_AVSource_CreateWithURI(uri);

   // (Optional) Create a source resource object for the custom data source. Before the operation, you must implement AVSourceReadAt.
   // Add g_filePath when OH_AVSource_CreateWithDataSource is used.
   // g_filePath = filePath ;
   // OH_AVDataSource dataSource = {fileSize, AVSourceReadAt};
   // OH_AVSource *source = OH_AVSource_CreateWithDataSource(&dataSource);
   ```

   Implement the **AVSourceReadAt** API before creating the resource object.

   ```c++
   // Add the header file.
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
         return MediaDataSourceError::SOURCE_ERROR_IO; // Failed to open the file.
      }

      infile.seekg(0, std::ios::end);
      int64_t fileSize = infile.tellg();
      if (pos >= fileSize) {
         printf("AVSourceReadAt : pos over or equals file size!\n");
         return MediaDataSourceError::SOURCE_ERROR_EOF; // pos is already at the end of the file and cannot be read.
      }

      if (pos + length > fileSize) {
         length of length = fileSize - pos; // When the sum of pos and length exceeds the file size, the data from pos to the end of the file is read.
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
3. Create a demuxer instance.
   ```c++
   // Create a demuxer for the resource object.
   OH_AVDemuxer *demuxer = OH_AVDemuxer_CreateWithSource(source);
   if (demuxer == nullptr) {
      printf("create demuxer failed");
      return;
   }
   ```
4. (Optional) Register a [callback to obtain the media key system information](../../reference/apis-drm-kit/_drm.md#drm_mediakeysysteminfocallback). If the stream is not a DRM stream or the [media key system information](../../reference/apis-drm-kit/_drm.md#drm_mediakeysysteminfo) has been obtained, you can skip this step.

   Add the header file.
   ```c++
   #include <multimedia/drm_framework/native_drm_common.h>
   ```
   Link the dynamic library in the cmake script.

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_drm.so)
   ```
   There are two types of APIs for setting DRM information listeners. The callback function shown in example 1 can return a demuxer instance and therefore is recommended in the scenario where multiple demuxer instances are used. The callback function shown in example 2 does not return a demuxer instance and is applicable to the scenario where a single demuxer instance is used.

   Example 1:
   ```c++
   // Implement the OnDrmInfoChangedWithObj callback.
   static void OnDrmInfoChangedWithObj(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *drmInfo)
   {
      // Parse the media key system information, including the quantity, DRM type, and corresponding PSSH.
   }

   Demuxer_MediaKeySystemInfoCallback callback = &OnDrmInfoChangedWithObj;
   Drm_ErrCode ret = OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(demuxer, callback);

   ```

   Example 2:
   ```c++
   // Implement the OnDrmInfoChanged callback.
   static void OnDrmInfoChanged(DRM_MediaKeySystemInfo *drmInfo)
   {
      // Parse the media key system information, including the quantity, DRM type, and corresponding PSSH.
   }

   DRM_MediaKeySystemInfoCallback callback = &OnDrmInfoChanged;
   Drm_ErrCode ret = OH_AVDemuxer_SetMediaKeySystemInfoCallback(demuxer, callback);
   ```

   After the callback is invoked, you can call the API to proactively obtain the media key system information (UUID and corresponding PSSH).
   ```c++
   DRM_MediaKeySystemInfo mediaKeySystemInfo;
   OH_AVDemuxer_GetMediaKeySystemInfo(demuxer, &mediaKeySystemInfo);
   ```
   After obtaining and parsing DRM information, create [MediaKeySystem](../drm/native-drm-mediakeysystem-management.md) and [MediaKeySession](../drm/native-drm-mediakeysession-management.md) instances of the corresponding DRM scheme to obtain a media key. If required, set the audio decryption configuration by following step 4 in [Audio Decoding](./audio-decoding.md#how-to-develop), and set the video decryption configuration by following step 5 [Surface Output in Video Decoding](./video-decoding.md#surface-mode) or step 4 in [Buffer Output in Video Decoding](./video-decoding.md#buffer mode).

5. (Optional) Obtain the number of tracks. If you know the track information, skip this step.

   ```c++
   // Obtain the number of tracks from the file source information. You can call the API to obtain file-level attributes. For details, see Table 1 in Appendix 1.
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

6. (Optional) Obtain the track index and format. If you know the track information, skip this step.

   ```c++
   uint32_t audioTrackIndex = 0;
   uint32_t videoTrackIndex = 0;
   int32_t w = 0;
   int32_t h = 0;
   int32_t trackType;
   for (uint32_t index = 0; index < (static_cast<uint32_t>(trackCount)); index++) {
      // Obtain the track information. You can call the API to obtain track-level attributes. For details, see Table 2 in Appendix.
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
      // Obtain the width and height of the video track.
      if (trackType == OH_MediaType::MEDIA_TYPE_VID) {
         if (!OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_WIDTH, &w)) {
            printf("get track width from track format failed");
            return;
         }
         if (!OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_HEIGHT, &h)) {
            printf("get track height from track format failed");
            return;
         }
      }
      OH_AVFormat_Destroy(trackFormat);
   }
   ```

7. Select a track, from which the demuxer reads data.

   ```c++
   if(OH_AVDemuxer_SelectTrackByID(demuxer, audioTrackIndex) != AV_ERR_OK){
      printf("select audio track failed: %d", audioTrackIndex);
      return;
   }
   if(OH_AVDemuxer_SelectTrackByID(demuxer, videoTrackIndex) != AV_ERR_OK){
      printf("select video track failed: %d", videoTrackIndex);
      return;
   }
   // (Optional) Deselect the track.
   // OH_AVDemuxer_UnselectTrackByID(demuxer, audioTrackIndex);
   ```

8. (Optional) Seek to the specified time for the selected track.

   ```c++
   // Demuxing is performed from this time.
   // Note:
   // 1. If OH_AVDemuxer_SeekToTime is called for an MPEG TS file, the target position may be a non-key frame. You can then call OH_AVDemuxer_ReadSampleBuffer to check whether the current frame is a key frame based on the obtained OH_AVCodecBufferAttr. If it is a non-key frame, which causes display issues on the application side, cyclically read the frames until you reach the first key frame, where you can perform processing such as decoding.
   // 2. If OH_AVDemuxer_SeekToTime is called for an OGG file, the file seeks to the start of the time interval (second) where the input parameter millisecond is located, which may cause a certain number of frame errors.
   OH_AVDemuxer_SeekToTime(demuxer, 0, OH_AVSeekMode::SEEK_MODE_CLOSEST_SYNC);
   ```

9. Start demuxing and cyclically obtain frame data. The code snippet below uses a file that contains audio and video tracks as an example.

   ```c++
   // Create a buffer to store the data obtained after demuxing.
   OH_AVBuffer *buffer = OH_AVBuffer_Create(w * h * 3 >> 1);
   if (buffer == nullptr) {
      printf("build buffer failed");
      return;
   }
   OH_AVCodecBufferAttr info;
   bool videoIsEnd = false;
   bool audioIsEnd = false;
   int32_t ret;
   while (!audioIsEnd || !videoIsEnd) {
      // Before calling OH_AVDemuxer_ReadSampleBuffer, call OH_AVDemuxer_SelectTrackByID to select the track from which the demuxer reads data.
      // Obtain audio frame data.
      if(!audioIsEnd) {
         ret = OH_AVDemuxer_ReadSampleBuffer(demuxer, audioTrackIndex, buffer);
         if (ret == AV_ERR_OK) {
            // Obtain the process the audio frame data in the buffer.
            OH_AVBuffer_GetBufferAttr(buffer, &info);
            printf("audio info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               audioIsEnd = true;
            }
         }
      }
      if(!videoIsEnd) {
         ret = OH_AVDemuxer_ReadSampleBuffer(demuxer, videoTrackIndex, buffer);
         if (ret == AV_ERR_OK) {
            // Obtain the process the video frame data in the buffer.
            OH_AVBuffer_GetBufferAttr(buffer, &info);
            printf("video info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               videoIsEnd = true;
            }
         }
      }
   }
   OH_AVBuffer_Destroy(buffer);
   ```

10. Destroy the demuxer instance.
      ```c++
      // Manually set the instance to NULL after OH_AVSource_Destroy is called. Do not call this API repeatedly for the same instance; otherwise, a program error occurs.
      if (OH_AVSource_Destroy(source) != AV_ERR_OK) {
         printf("destroy source pointer error");
      }
      source = NULL;
      // Manually set the instance to NULL after OH_AVDemuxer_Destroy is called. Do not call this API repeatedly for the same instance; otherwise, a program error occurs.
      if (OH_AVDemuxer_Destroy(demuxer) != AV_ERR_OK) {
         printf("destroy demuxer pointer error");
      }
      demuxer = NULL;
      close(fd);
      ```

## Appendix
### Supported File-Level Attributes

> **NOTE**
>
> Attribute data can be obtained only when the file is parsed normally. If the file information is incorrect or missing, the parsing is abnormal and the corresponding data cannot be obtained.
> 
> For details about the data type and value range, see [Media Data Key-Value Pairs](../../reference/apis-avcodec-kit/_codec_base.md#media-data-key-value-pairs).

**Table 1** Supported file-level attributes
| Attribute| Description|
| -- | -- |
|OH_MD_KEY_TITLE|Title.|
|OH_MD_KEY_ARTIST|Artist.|
|OH_MD_KEY_ALBUM|Album.|
|OH_MD_KEY_ALBUM_ARTIST|Album artist.|
|OH_MD_KEY_DATE|Date.|
|OH_MD_KEY_COMMENT|Comment.|
|OH_MD_KEY_GENRE|Genre.|
|OH_MD_KEY_COPYRIGHT|Copyright.|
|OH_MD_KEY_LANGUAGE|Language.|
|OH_MD_KEY_DESCRIPTION|Description.|
|OH_MD_KEY_LYRICS|Lyrics.|
|OH_MD_KEY_TRACK_COUNT|Track count.|
|OH_MD_KEY_DURATION|Duration.|
|OH_MD_KEY_START_TIME|Start time.|

### Supported Track-Level Attributes

> **NOTE**
>
> Attribute data can be obtained only when the file is parsed normally. If the file information is incorrect or missing, the parsing is abnormal and the corresponding data cannot be obtained.
> 
> For details about the data type and value range, see [Media Data Key-Value Pairs](../../reference/apis-avcodec-kit/_codec_base.md#media-data-key-value-pairs).

**Table 2** Supported track-level attributes
| Name| Description| Supported by Video Tracks| Supported by Audio Tracks| Supported by Subtitle Tracks|
| -- | -- | -- | -- | -- |
|OH_MD_KEY_CODEC_MIME|Stream codec type.|Supported|Supported|Supported|
|OH_MD_KEY_TRACK_TYPE|Stream track type.|Supported|Supported|Supported|
|OH_MD_KEY_TRACK_START_TIME|Start time of the stream.|Supported|Supported|Supported|
|OH_MD_KEY_BITRATE|Stream bit rate.|Supported|Supported|Not supported|
|OH_MD_KEY_LANGUAGE|Stream language type.|Supported|Supported|Not supported|
|OH_MD_KEY_CODEC_CONFIG|Codec-specific data. In the case of video, data carried in **xps** is transferred. In the case of audio, data carried in **extraData** is transferred.|Supported|Supported|Not supported|
|OH_MD_KEY_WIDTH|Video stream width.|Supported|Not supported|Not supported|
|OH_MD_KEY_HEIGHT|Video stream height.|Supported|Not supported|Not supported|
|OH_MD_KEY_FRAME_RATE|Video stream frame rate.|Supported|Not supported|Not supported|
|OH_MD_KEY_ROTATION|Rotation angle of the video stream.|Supported|Not supported|Not supported|
|OH_MD_KEY_VIDEO_SAR|Aspect ratio of the video stream sample.|Supported|Not supported|Not supported|
|OH_MD_KEY_PROFILE|Encoding profile of the video stream. This key is valid only for H.265 streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_RANGE_FLAG|Video YUV value range flag of the video stream. This key is valid only for H.265 streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_COLOR_PRIMARIES|Video primary color of the video stream. This key is valid only for H.265 streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_TRANSFER_CHARACTERISTICS|Video transfer characteristics of the video stream. This key is valid only for H.265 streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_MATRIX_COEFFICIENTS|Video matrix coefficient. This key is valid only for H.265 streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_VIDEO_IS_HDR_VIVID|Flag indicating whether the video stream is HDR Vivid. This key is valid only for HDR Vivid streams.|Supported|Not supported|Not supported|
|OH_MD_KEY_AUD_SAMPLE_RATE|Audio stream sampling rate.|Not supported|Supported|Not supported|
|OH_MD_KEY_AUD_CHANNEL_COUNT|Number of audio stream channels.|Not supported|Supported|Not supported|
|OH_MD_KEY_CHANNEL_LAYOUT|Encoding channel layout required by the audio stream.|Not supported|Supported|Not supported|
|OH_MD_KEY_AUDIO_SAMPLE_FORMAT|Audio stream sample format.|Not supported|Supported|Not supported|
|OH_MD_KEY_AAC_IS_ADTS|AAC format. This key is valid only for AAC streams.|Not supported|Supported|Not supported|
|OH_MD_KEY_BITS_PER_CODED_SAMPLE|Number of bits per coded sample in the audio stream.|Not supported|Supported|Not supported|
