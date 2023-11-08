# Audio and Video Encapsulation

You can call the native APIs provided by the **AVMuxer** module to encapsulate audio and video, that is, to store encoded audio and video data to a file in a certain format.

Currently, the following encapsulation capabilities are supported:

| Encapsulation Format| Video Codec Type       | Audio Codec Type  | Cover Type      |
| -------- | --------------------- | ---------------- | -------------- |
| mp4      | MPEG-4, AVC (H.264)| AAC, MPEG (MP3)| jpeg, png, bmp|
| m4a      | MPEG-4, AVC (H.264)| AAC              | jpeg, png, bmp|

**Usage Scenario**

- Video and audio recording
  
  After you encode audio and video streams, encapsulate them into files.

- Audio and video editing
  
  After you edit audio and video, encapsulate them into files.

- Audio and video transcoding

  After you transcode audio and video, encapsulate them into files.

## How to Develop

Read [AVMuxer](../reference/native-apis/_a_v_muxer.md) for the API reference.

> **NOTE**
> 
> To call the encapsulation APIs to write a local file, request the **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** permissions by following the instructions provided in [Applying for Permissions](../security/accesstoken-guidelines.md).

### Linking the Dynamic Library in the CMake Script
``` cmake
target_link_libraries(sample PUBLIC libnative_media_avmuxer.so)
```

### How to Develop

The following walks you through how to implement the entire process of audio and video encapsulation. It uses the MP4 format as an example.

1. Call **OH_AVMuxer_Create()** to create an **OH_AVMuxer** instance.

   ``` c++
   // Set the encapsulation format to MP4.
   OH_AVOutputFormat format = AV_OUTPUT_FORMAT_MPEG_4;
   // Create a File Descriptor (FD) in read/write mode.
   int32_t fd = open("test.mp4", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
   OH_AVMuxer *muxer = OH_AVMuxer_Create(fd, format);
   ```

2. (Optional) Call **OH_AVMuxer_SetRotation()** to set the rotation angle.
   
   ``` c++
   // Set the rotation angle when a video image needs to be rotated.
   OH_AVMuxer_SetRotation(muxer, 0);
   ```

3. Add an audio track.
   
   **Method 1: Use OH_AVFormat_Create to create the format.**

   ``` c++
   int audioTrackId = -1;
   OH_AVFormat *formatAudio = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatAudio, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_AUDIO_AAC); // Mandatory.
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_SAMPLE_RATE, 44100); // Mandatory.
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_CHANNEL_COUNT, 2); // Mandatory.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // Failure to add the audio track.
   }
   OH_AVFormat_Destroy (formatAudio); // Destroy the format.
   ```
   
   **Method 2: Use OH_AVFormat_CreateAudioFormat to create the format.**
   
   ``` c++
   int audioTrackId = -1;
   OH_AVFormat *formatAudio = OH_AVFormat_CreateAudioFormat(OH_AVCODEC_MIMETYPE_AUDIO_AAC, 44100, 2);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // Failure to add the audio track.
   }
   OH_AVFormat_Destroy (formatAudio); // Destroy the format.
   ```

4. Add a video track.

   **Method 1: Use OH_AVFormat_Create to create the format.**

   ``` c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size =...; // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatVideo = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatVideo, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_VIDEO_MPEG4); // Mandatory.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_WIDTH, 1280); // Mandatory.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_HEIGHT, 720); // Mandatory.
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failure to add the video track.
   }
   OH_AVFormat_Destroy(formatVideo); // Destroy the format.
   ```
   
   **Method 2: Use OH_AVFormat_CreateVideoFormat to create the format.**
   
   ``` c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size =...; // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatVideo = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_MPEG4, 1280, 720);
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failure to add the video track.
   }
   OH_AVFormat_Destroy(formatVideo); // Destroy the format.
   ```

5. Add a cover track.

   **Method 1: Use OH_AVFormat_Create to create the format.**

   ``` c++
   int coverTrackId = -1;
   OH_AVFormat *formatCover = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatCover, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_IMAGE_JPG);
   OH_AVFormat_SetIntValue(formatCover, OH_MD_KEY_WIDTH, 1280);
   OH_AVFormat_SetIntValue(formatCover, OH_MD_KEY_HEIGHT, 720);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &coverTrackId, formatCover);
   if (ret != AV_ERR_OK || coverTrackId < 0) {
       // Failure to add the cover track.
   }
   OH_AVFormat_Destroy(formatCover); // Destroy the format.
   ```
   
   **Method 2: Use OH_AVFormat_CreateVideoFormat to create the format.**

   ``` c++
   int coverTrackId = -1;
   OH_AVFormat *formatCover = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_IMAGE_JPG, 1280, 720);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &coverTrackId, formatCover);
   if (ret != AV_ERR_OK || coverTrackId < 0) {
       // Failure to add the cover track.
   }
   OH_AVFormat_Destroy(formatCover); // Destroy the format.
   ```

6. Call **OH_AVMuxer_Start()** to start encapsulation.
   
   ``` c++
   // Call Start() to write the file header. After this API is called, you cannot set media parameters or add tracks.
   if (OH_AVMuxer_Start(muxer) != AV_ERR_OK) {
       // Exception handling.
   }
   ```

7. Call **OH_AVMuxer_WriteSample()** to write data, including video, audio, and cover data.

   ``` c++
   // Data can be written only after Start() is called.
   int size = ...;
   OH_AVMemory *sample = OH_AVMemory_Create (size); // Create an AVMemory instance.
   // Write data to the sample buffer. For details, see the usage of OH_AVMemory.
   // Encapsulate the cover. One image must be written at a time.
   
   // Set buffer information.
   OH_AVCodecBufferAttr info;
   info.pts =...; // Playback start time of the current data, in microseconds.
   info.size = size; // Length of the current data.
   info.offset = 0; // Offset. Generally, the value is 0.
   info.flags |= AVCODEC_BUFFER_FLAGS_SYNC_FRAME; // Flag of the current data. For details, see OH_AVCodecBufferFlags.
   int trackId = audioTrackId; // Select the track to be written.
   
   int ret = OH_AVMuxer_WriteSample(muxer, trackId, sample, info);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```

8. Call **OH_AVMuxer_Stop()** to stop encapsulation.

   ``` c++
   // Call Stop() to write the file trailer. After this API is called, you cannot write media data.
   if (OH_AVMuxer_Stop(muxer) != AV_ERR_OK) {
       // Exception handling.
   }
   ```

9. Call **OH_AVMuxer_Destroy()** to release the instance.

   ``` c++
   if (OH_AVMuxer_Destroy(muxer) != AV_ERR_OK) {
       // Exception handling.
   }
   muxer = NULL;
   close(fd); // Close the FD.
   ```
