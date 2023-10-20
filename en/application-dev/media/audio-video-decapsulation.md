# Audio and Video Decapsulation

You can call the native APIs provided by the **AVDemuxer** module to decapsulate audio and video, that is, to extract audio and video frame data from bit stream data.

Currently, two data input types are supported: remote connection (over HTTP) and File Descriptor (FD).

The following decapsulation formats are supported:

| Media Format | Encapsulation Format                     |
| -------- | :----------------------------|
| Video    | MP4, MPEG TS                 |
| Audio     | M4A, AAC, MP3, OGG, FLAC, WAV|



**Usage Scenario**

- Audio and video playback
  
  Decapsulate audio and video streams, decode the frame data obtained through decapsulation, and play the decoded data.

- Audio and video editing
  
  Decapsulate audio and video streams, and edit the specified frames.

- Media file format conversion

  Decapsulate audio and video streams, and encapsulate them into a new file format.

## How to Develop
Read [AVDemuxer](../reference/native-apis/_a_v_demuxer.md) and [AVSource](../reference/native-apis/_a_v_source.md) for the API reference.

> **NOTE**
>
> - To call the decapsulation APIs to parse a network playback path, request the **ohos.permission.INTERNET** permission by following the instructions provided in [Applying for Permissions](../security/accesstoken-guidelines.md).
> - To call the decapsulation APIs to parse a local file, request the **ohos.permission.READ_MEDIA** permission by following the instructions provided in [Applying for Permissions](../security/accesstoken-guidelines.md).
> - You can also use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../reference/apis/js-apis-resource-manager.md#getrawfd9).

### Linking the Dynamic Library in the CMake Script
``` cmake
target_link_libraries(sample PUBLIC libnative_media_avdemuxer.so)
target_link_libraries(sample PUBLIC libnative_media_avsource.so)
```

### How to Develop

1. Create a demuxer instance.

   ``` c++
   // Create the FD. You must have the read permission on the file handle when opening the file.
   std::string fileName = "test.mp4";
   int fd = open(fileName.c_str(), O_RDONLY);
   struct stat fileStatus {};
   size_t fileSize = 0;
   if (stat(fileName.c_str(), &fileStatus) == 0) {
      fileSize = static_cast<size_t>(fileStatus.st_size);
   } else {
      printf("get stat failed");
      return;
   }
   // Create a source resource object for the FD resource file. If offset is not the start position of the file or size is not the actual file size, the data obtained may be incomplete. Consequently, the source resource object may fail to create or subsequent decapsulation may fail.
   OH_AVSource *source = OH_AVSource_CreateWithFD(fd, 0, fileSize);
   if (source == nullptr) {
      printf("create source failed");
      return;
   }
   // (Optional) Create a source resource object for the URI resource file.
   // OH_AVSource *source = OH_AVSource_CreateWithURI(uri);
   ```
   ```c++
   // Create a demuxer for the resource object.
   OH_AVDemuxer *demuxer = OH_AVDemuxer_CreateWithSource(source);
   if (demuxer == nullptr) {
      printf("create demuxer failed");
      return;
   }
   ```



2. (Optional) Obtain the number of tracks. If you know the track information, skip this step.

   ``` c++
   // Obtain the number of tracks from the file source information.
   OH_AVFormat *sourceFormat = OH_AVSource_GetSourceFormat(source);
   if (sourceFormat == nullptr) {
      printf("get source format failed");
      return;
   }
   int32_t trackCount = 0;
   OH_AVFormat_GetIntValue(sourceFormat, OH_MD_KEY_TRACK_COUNT, &trackCount);
   OH_AVFormat_Destroy(sourceFormat);
   ```

   

3. (Optional) Obtain the track index and format. If you know the track information, skip this step.

   ``` c++
   uint32_t audioTrackIndex = 0;
   uint32_t videoTrackIndex = 0;
   int32_t w = 0;
   int32_t h = 0;
   int32_t trackType;
   for (uint32_t index = 0; index < (static_cast<uint32_t>(trackCount)); index++) {
      // Obtain the track format.
      OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, index);
      if (trackFormat == nullptr) {
         printf("get track format failed");
         return;
      }
      OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_TRACK_TYPE, &trackType);
      static_cast<OH_MediaType>(trackType) == OH_MediaType::MEDIA_TYPE_AUD ? audioTrackIndex = index : videoTrackIndex = index;
      // Obtain the width and height of the video track.
      if (trackType == OH_MediaType::MEDIA_TYPE_VID) {
         OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_WIDTH, &w);
         OH_AVFormat_GetIntValue(trackFormat, OH_MD_KEY_HEIGHT, &h);
      }
      OH_AVFormat_Destroy(trackFormat);
   }
   ```

   

4. Select a track, from which the demuxer reads data.

   ``` c++
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



5. (Optional) Seek to the specified time for the selected track.

   ``` c++
   // Decapsulation is performed from this time.
   // Note:
   // 1. If OH_AVDemuxer_SeekToTime is called for an MPEG TS file, the target position may be a non-key frame. You can then call OH_AVDemuxer_ReadSample to check whether the current frame is a key frame based on the obtained OH_AVCodecBufferAttr. If it is a non-key frame, which causes display issues on the application side, cyclically read the frames until you reach the first key frame, where you can perform processing such as decoding.
   // 2. If OH_AVDemuxer_SeekToTime is called for an OGG file, the file seeks to the start of the time interval (second) where the input parameter millisecond is located, which may cause a certain number of frame errors.
   OH_AVDemuxer_SeekToTime(demuxer, 0, OH_AVSeekMode::SEEK_MODE_CLOSEST_SYNC);
   ```

6. Start decapsulation and cyclically obtain frame data. The code snippet below uses a file that contains audio and video tracks as an example.

   ``` c++
   // Create a buffer to store the data obtained after decapsulation.
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
      // Before calling OH_AVDemuxer_ReadSample, call OH_AVDemuxer_SelectTrackByID to select the track from which the demuxer reads data.
      // Obtain audio frame data.
      if(!audioIsEnd) {
         ret = OH_AVDemuxer_ReadSample(demuxer, audioTrackIndex, buffer, &info);
         if (ret == AV_ERR_OK) {
            // Obtain the process the audio frame data in the buffer.
            printf("audio info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               audioIsEnd = true;
            }
         }
      }
      if(!videoIsEnd) {
         ret = OH_AVDemuxer_ReadSample(demuxer, videoTrackIndex, buffer, &info);
         if (ret == AV_ERR_OK) {
            // Obtain the process the video frame data in the buffer.
            printf("video info.size: %d\n", info.size);
            if (info.flags == OH_AVCodecBufferFlags::AVCODEC_BUFFER_FLAGS_EOS) {
               videoIsEnd = true;
            }
         }
      }
   }
   OH_AVMemory_Destroy(buffer);
   ```

   

7. Destroy the demuxer instance.

   ``` c++
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
