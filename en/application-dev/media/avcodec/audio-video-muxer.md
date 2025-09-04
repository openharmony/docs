# Media Data Multiplexing

You can call native APIs to multiplex audio and video streams, that is, to store encoded audio and video data to a file in a certain format.

For details about the supported multiplexing formats, see [AVCodec Supported Formats](avcodec-support-formats.md#media-data-multiplexing).

<!--RP2--><!--RP2End-->

**When to Use**

- Video and audio recording
  
  After you encode audio and video streams, multiplex them into files.

- Audio and video editing
  
  After you edit audio and video, multiplex them into files.

- Audio and video transcoding

  After you transcode audio and video, multiplex them into files.

## Development Guidelines

Read [AVMuxer](../../reference/apis-avcodec-kit/_a_v_muxer.md) for the API reference.

> **NOTE**
>
> To call the AVMuxer module to write a local file, request the ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA permissions by following the instructions provided in [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_avmuxer.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

### How to Develop

The following walks you through how to implement the entire process of audio and video multiplexing. It uses the MP4 format as an example.

For details about the keys to be configured for different container formats, see [AVCodec Supported Formats](avcodec-support-formats.md#media-data-multiplexing).

1. Add the header files.

   ```c++
   #include <multimedia/player_framework/native_avmuxer.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   #include <fcntl.h>
   ```

2. Call **OH_AVMuxer_Create()** to create an OH_AVMuxer instance.

   ```c++
   // Set the container format to MP4.
   OH_AVOutputFormat format = AV_OUTPUT_FORMAT_MPEG_4;
   // Create an FD in read/write mode.
   int32_t fd = open("test.mp4", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
   OH_AVMuxer *muxer = OH_AVMuxer_Create(fd, format);
   ```

3. (Optional) Call **OH_AVMuxer_SetRotation()** to set the rotation angle.

   ```c++
   // Set the rotation angle when a video image needs to be rotated.
   OH_AVMuxer_SetRotation(muxer, 0);
   ```

4. Add file-level data.
   ```c++
   OH_AVFormat *format = OH_AVFormat_Create(); // Call OH_AVFormat_Create to create a format.
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_CREATION_TIME, "2024-12-28T00:00:00:000000Z"); // Set the creation time (UTC time in ISO 8601 format).
   int ret = OH_AVMuxer_SetFormat(muxer, format); // Set format data to the muxer.
   if (ret != AV_ERR_OK) {
      // Failed to set the format because no valid key data to be written is found.
   }
   OH_AVFormat_Destroy(format); // Destroy the format.
   ```

5. Add an audio track.

   **Method 1: Use OH_AVFormat_Create to create the format.**

   ```c++
   int audioTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size = ...;  // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatAudio = OH_AVFormat_Create(); // Call OH_AVFormat_Create to create a format. The following showcases how to multiplex an AAC-LC audio with the sample rate of 44100 Hz and two audio channels.
   OH_AVFormat_SetStringValue(formatAudio, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_AUDIO_AAC); // Mandatory.
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_SAMPLE_RATE, 44100); // Mandatory.
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_AUD_CHANNEL_COUNT, 2); // Mandatory.
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // Optional.
   OH_AVFormat_SetBuffer(formatAudio, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // Failure to add the audio track.
   }
   OH_AVFormat_Destroy (formatAudio); // Destroy the format.
   ```

   **Method 2: Use OH_AVFormat_CreateAudioFormat to create the format.**

   ```c++
   int audioTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size = ...;  // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatAudio = OH_AVFormat_CreateAudioFormat(OH_AVCODEC_MIMETYPE_AUDIO_AAC, 44100, 2);
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // Optional.
   OH_AVFormat_SetBuffer(formatAudio, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // Failure to add the audio track.
   }
   OH_AVFormat_Destroy (formatAudio); // Destroy the format.
   ```

6. Add a video track.

   **Method 1: Use OH_AVFormat_Create to create the format.**

   ```c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size = ...;  // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatVideo = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(formatVideo, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_VIDEO_AVC); // Mandatory.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_WIDTH, 1280); // Mandatory.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_HEIGHT, 720); // Mandatory.
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failure to add the video track.
   }
   OH_AVFormat_Destroy(formatVideo); // Destroy the format.
   ```

   **Method 2: Use OH_AVFormat_CreateVideoFormat to create the format.**

   ```c++
   int videoTrackId = -1;
   uint8_t *buffer = ...; // Encoding configuration data. If there is no configuration data, leave the parameter unspecified.
   size_t size = ...;  // Length of the encoding configuration data. Set this parameter based on project requirements.
   OH_AVFormat *formatVideo = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1280, 720);
   OH_AVFormat_SetBuffer(formatVideo, OH_MD_KEY_CODEC_CONFIG, buffer, size); // Optional.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failure to add the video track.
   }
   OH_AVFormat_Destroy(formatVideo); // Destroy the format.
   ```

7. Add an auxiliary track.
   > **NOTE**
   >
   > To add an auxiliary track, set **OH_MD_KEY_TRACK_TYPE** to **MEDIA_TYPE_AUXILIARY**.<br>
   > When setting **OH_MD_KEY_TRACK_REFERENCE_TYPE**, choose from **hint**, **cdsc**, **font**, **hind**, **vdep**, **vplx**, **subt**, **thmb**, **auxl**, **cdtg**, **shsc**, or **aest**.<br>
   > When setting **OH_MD_KEY_TRACK_DESCRIPTION**, use a string that starts with **"com.openharmony."** and contains no more than 256 characters.<br>
   > When setting **OH_MD_KEY_REFERENCE_TRACK_IDS**, ensure that the track ID is greater than or equal to 0 and refers to an existing track.

   Add an audio auxiliary track.

   ```c++
   int32_t audioAuxlTrackId = -1;
   std::vector<int32_t> audioTrackIDsVector = {0}; // Set the IDs of the audio auxiliary tracks based on the actual situation. Multiple values can be entered.
   int32_t *audioAuxlTrackIDs = audioTrackIDsVector.data();
   OH_AVFormat *audioAuxlFormat = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_AUDIO_AAC); // Mandatory.
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_AUD_SAMPLE_RATE, 44100); // Mandatory.
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_AUD_CHANNEL_COUNT, 2); // Mandatory.
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // Optional.
   OH_AVFormat_SetIntValue(audioAuxlFormat, OH_MD_KEY_TRACK_TYPE, static_cast<int32_t>(OH_MediaType::MEDIA_TYPE_AUXILIARY)); // Mandatory.
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_TRACK_REFERENCE_TYPE, "auxl"); // Mandatory.
   OH_AVFormat_SetStringValue(audioAuxlFormat, OH_MD_KEY_TRACK_DESCRIPTION, "com.openharmony.audiomode.auxiliary"); // Mandatory.
   OH_AVFormat_SetIntBuffer(audioAuxlFormat, OH_MD_KEY_REFERENCE_TRACK_IDS, audioAuxlTrackIDs, audioTrackIDsVector.size()); // Mandatory.

   int ret = OH_AVMuxer_AddTrack(muxer, &audioAuxlTrackId, audioAuxlFormat);
   if (ret != AV_ERR_OK || audioAuxlTrackId < 0) {
       // Failed to add the audio auxiliary track.
   }
   ```

   Add a video auxiliary track.

   ```c++
   int32_t videoAuxlTrackId = -1;
   std::vector<int32_t> videoTrackIDsVector = {0}; // Set the IDs of the video auxiliary tracks based on the actual situation. Multiple values can be entered.
   int32_t *videoAuxlTrackIDs = videoTrackIDsVector.data();
   OH_AVFormat *videoAuxlFormat = OH_AVFormat_Create();
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_CODEC_MIME, OH_AVCODEC_MIMETYPE_VIDEO_AVC); // Mandatory.
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_WIDTH, 1280); // Mandatory.
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_HEIGHT, 720); // Mandatory.
   OH_AVFormat_SetIntValue(videoAuxlFormat, OH_MD_KEY_TRACK_TYPE, static_cast<int32_t>(OH_MediaType::MEDIA_TYPE_AUXILIARY)); // Mandatory.
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_TRACK_REFERENCE_TYPE, "vdep"); // Mandatory.
   OH_AVFormat_SetStringValue(videoAuxlFormat, OH_MD_KEY_TRACK_DESCRIPTION, "com.openharmony.moviemode.depth"); // Mandatory.
   OH_AVFormat_SetIntBuffer(videoAuxlFormat, OH_MD_KEY_REFERENCE_TRACK_IDS, videoAuxlTrackIDs, videoTrackIDsVector.size()); // Mandatory.

   int ret = OH_AVMuxer_AddTrack(muxer, &videoAuxlTrackId, videoAuxlFormat);
   if (ret != AV_ERR_OK || videoAuxlTrackId < 0) {
       // Failed to add the video auxiliary track.
   }
   ```

8. Add a cover track.

   **Method 1: Use OH_AVFormat_Create to create the format.**

   ```c++
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

   ```c++
   int coverTrackId = -1;
   OH_AVFormat *formatCover = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_IMAGE_JPG, 1280, 720);
   
   int ret = OH_AVMuxer_AddTrack(muxer, &coverTrackId, formatCover);
   if (ret != AV_ERR_OK || coverTrackId < 0) {
       // Failure to add the cover track.
   }
   OH_AVFormat_Destroy(formatCover); // Destroy the format.
   ```

9. Call **OH_AVMuxer_Start()** to start multiplexing.

   ```c++
   // Call Start() to write the file header. After this API is called, you cannot set media parameters or add tracks.
   if (OH_AVMuxer_Start(muxer) != AV_ERR_OK) {
       // Handle exceptions.
   }
   ```

10. Call **OH_AVMuxer_WriteSampleBuffer()** to write data.

    The encapsulated data includes video, audio, and cover data.

    ```c++
    // Data can be written only after Start() is called.
    int size = ...;
    OH_AVBuffer *sample = OH_AVBuffer_Create(size); // Create an AVBuffer instance.
    // Write data to the sample buffer by using OH_AVBuffer_GetAddr(sample). For details, see the usage of OH_AVBuffer.
    // Multiplex the cover. One image must be written at a time.
    
    // Set buffer information.
    OH_AVCodecBufferAttr info = {0};
    info.pts =...; // Playback start time of the current data, in microseconds. The relative time is used.
    info.size = size; // Length of the current data.
    info.offset = 0; // Offset. Generally, the value is 0.
    info.flags |= AVCODEC_BUFFER_FLAGS_SYNC_FRAME; // Flag of the current data. For details, see OH_AVCodecBufferFlags.
    info.flags |= AVCODEC_BUFFER_FLAGS_CODEC_DATA; // The AVC in annex-b format contains the codec configuration flag.
    OH_AVBuffer_SetBufferAttr(sample, &info); // Set the buffer attribute.
    int trackId = audioTrackId; // Select the audio or video track to be written.
    
    int ret = OH_AVMuxer_WriteSampleBuffer(muxer, trackId, sample);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

11. Call **OH_AVMuxer_Stop()** to stop multiplexing.

    ```c++
    // Call Stop() to write the file trailer. After this API is called, you cannot write media data.
    if (OH_AVMuxer_Stop(muxer) != AV_ERR_OK) {
        // Handle exceptions.
    }
    ```

12. Call **OH_AVMuxer_Destroy()** to release the instance.

    Do not repeatedly destroy the instance. Otherwise, the program may crash.

    ```c++
    if (OH_AVMuxer_Destroy(muxer) != AV_ERR_OK) {
        // Handle exceptions.
    }
    muxer = NULL;
    close(fd); // Close the FD.
    ```
