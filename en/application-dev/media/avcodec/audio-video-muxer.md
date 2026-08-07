# Media Data Multiplexing

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=99fe0f1dd52e5b8b282b1cc3f26fabdf415f071b translatedAt=2026-08-06T13:43:50.153Z pushedAt=2026-08-07T03:26:19.176Z -->

You can call native APIs to multiplex audio and video streams, that is, to store encoded audio and video data to a file in a certain format.

For details about the currently supported multiplexing capabilities, see [Media Data Multiplexing](avcodec-support-formats.md#media-data-multiplexing) in AVCodec supported formats.

<!--RP2--><!--RP2End-->

**When to Use**

- Video and audio recording

  After you encode audio and video streams, multiplex them into files.

- Audio and video editing

  After you edit audio and video, multiplex them into files.

- Audio and video transcoding

  After you transcode audio and video, multiplex them into files.

## Development Guidelines

For details about the APIs, see [native_avmuxer.h](../../reference/apis-avcodec-kit/capi-native-avmuxer-h.md).

> **NOTE**
>
> To call the AVMuxer module to write a local file, request the ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA permissions by following the instructions provided in [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_avmuxer.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

### MP4 Format Multiplexing

Refer to the following sample code to complete the entire process of multiplexing audio and video into an MP4 file.

For details about the keys to be configured for different container formats, see [Media Data Multiplexing](avcodec-support-formats.md#media-data-multiplexing) in AVCodec supported formats.

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

   For details about the defined keys of file-level data, see [Media Data Multiplexing](avcodec-support-formats.md#media-data-multiplexing) in AVCodec supported formats.

   Custom keys must start with **''com.openharmony.''**. The value type can be int32_t, float, or string. The value type uint8_t* is supported since API version 20.

   > **NOTE**
   >
   > The defined keys must be set before **OH_AVMuxer_Start()** is called, and custom keys can be set before **OH_AVMuxer_Stop()** is called.

   ```c++
   OH_AVFormat *format = OH_AVFormat_Create(); // Create a format using OH_AVFormat_Create.

   // Set the defined keys.
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_CREATION_TIME, "2024-12-28T00:00:00.000000Z"); // Starting from API version 14, supports setting the creation time (in ISO 8601 standard time format, UTC time).
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_COMMENT, "comment test"); // Starting from API version 20, supports setting a comment. The value type is string.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_ENABLE_MOOV_FRONT, 1); // Starting from API version 20, supports placing the moov box before the mdat box. The default value is 0. Set to 1 to place the moov box before the mdat box.
   OH_AVFormat_SetFloatValue(format, OH_MD_KEY_LATITUDE, 39.9); // Starting from API version 24, supports setting the latitude. The value type is float, with a range of [-90.0, 90.0]. When setting geographic location information, both latitude and longitude are mandatory; you cannot set only one of them.
   OH_AVFormat_SetFloatValue(format, OH_MD_KEY_LONGITUDE, 116.3); // Starting from API version 24, supports setting the longitude. The value type is float, with a range of [-180.0, 180.0]. When setting geographic location information, both latitude and longitude are mandatory; you cannot set only one of them.
   OH_AVFormat_SetFloatValue(format, OH_MD_KEY_ALTITUDE, 44.4); // Starting from API version 24, supports setting the altitude. The value type is float. Altitude is optional when setting geographic location information.

   // Set a custom key (starting with com.openharmony.).
   OH_AVFormat_SetIntValue(format, "com.openharmony.testInt", 1024); // The value type is int32_t.
   OH_AVFormat_SetFloatValue(format, "com.openharmony.testFloat", 1.024); // The value type is float.
   OH_AVFormat_SetStringValue(format, "com.openharmony.testString", "string test"); // The value type is string, with a maximum length of 256 characters.
   uint8_t testData[] = {1, 2, 3};
   OH_AVFormat_SetBuffer(format, "com.openharmony.testBuffer", testData, sizeof(testData)); // Starting from API version 20, supports the value type uint8_t*.

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
   OH_AVFormat *formatAudio = OH_AVFormat_Create(); // Use OH_AVFormat_Create to create a format. This example muxes AAC-LC audio with a 44100 Hz sample rate and 2 channels.
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

   > **NOTE**
   >
   > - When you need to set color information, you must ensure that the values of `OH_MD_KEY_COLOR_PRIMARIES`, `OH_MD_KEY_TRANSFER_CHARACTERISTICS`, and `OH_MD_KEY_MATRIX_COEFFICIENTS` all fall within their respective parameter ranges. Otherwise, the system will not recognize the data as valid color information. For details about the parameter ranges, see [OH_ColorPrimary](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_colorprimary), [OH_TransferCharacteristic](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_transfercharacteristic), and [OH_MatrixCoefficient](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_matrixcoefficient).
   > - If the color information you input is inconsistent with the color information in the parameter sets of the video bitstream, the system uses the color information in the video bitstream.

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
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_RANGE_FLAG, 1); // Color information, optional. A value of 0 indicates limited range, and a value of 1 indicates full range.
   
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
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // Color information, optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_RANGE_FLAG, 1); // Color information, optional. A value of 0 indicates limited range, and a value of 1 indicates full range.
   
   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failure to add the video track.
   }
   OH_AVFormat_Destroy(formatVideo); // Destroy the format.
   ```

7. Add an auxiliary track.

   > **NOTE**
   >
   > When setting **OH_MD_KEY_TRACK_TYPE**, set the value to **MEDIA_TYPE_AUXILIARY** to add an auxiliary track.<br>
   > When setting **OH_MD_KEY_TRACK_REFERENCE_TYPE**, the value must be one of **hint**, **cdsc**, **font**, **hind**, **vdep**, **vplx**, **subt**, **thmb**, **auxl**, **cdtg**, **shsc**, or **aest**.<br>
   > When setting **OH_MD_KEY_TRACK_DESCRIPTION**, the value must be a string that starts with **com.openharmony.** and does not exceed 256 characters.<br>
   > When setting **OH_MD_KEY_REFERENCE_TRACK_IDS**, the track ID value must be greater than or equal to 0 and must be an existing track ID.

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
   // Call start to write the multiplexing file header. After start, you cannot set media parameters or add audio/video tracks.
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

### FLV Format Multiplexing

FLV format multiplexing is supported since API version 26.0.0.

The FLV format supports only one audio track and one video track. It does not support setting the rotation angle, cover track, or auxiliary track.

For details about the keys to be configured for FLV format multiplexing, see [Media Data Multiplexing](avcodec-support-formats.md#media-data-multiplexing) in AVCodec supported formats.

1. Add the header files.

   ```c++
   #include <multimedia/player_framework/native_avmuxer.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avbuffer.h>
   #include <fcntl.h>
   ```

2. Call `OH_AVMuxer_Create()` to create a muxer instance.

   ```c++
   // Create the fd in read/write mode.
   int32_t fd = open("test.flv", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
   // Set the container format to FLV.
   OH_AVMuxer *muxer = OH_AVMuxer_Create(fd, AV_OUTPUT_FORMAT_FLV);
   ```

3. The FLV format does not support calling `OH_AVMuxer_SetRotation()` to set the rotation angle. Calling this API will return an error.

4. Add file-level data.

   For details about the defined keys of file-level data, see [Media Data Multiplexing](avcodec-support-formats.md#media-data-multiplexing) in AVCodec supported formats.

   Custom keys must start with **''com.openharmony.''**. The value type is string.

   > **NOTE**
   >
   > - The defined keys must be set before **OH_AVMuxer_Start()** is called, and custom keys can be set before **OH_AVMuxer_Stop()** is called.
   > - The FLV format does not support **OH_MD_KEY_ENABLE_MOOV_FRONT**.

   ```c++
   OH_AVFormat *format = OH_AVFormat_Create(); // Use OH_AVFormat_Create to create the format.

   // Set the defined keys.
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_CREATION_TIME, "2024-12-28T00:00:00.000000Z"); // Setting the creation time is supported since API version 14 (using the ISO 8601 standard time format in UTC).
   OH_AVFormat_SetStringValue(format, OH_MD_KEY_COMMENT, "comment test"); // Setting the comment is supported since API version 20. The value type is string.

   // Set a user-defined key (must start with com.openharmony.).
   OH_AVFormat_SetStringValue(format, "com.openharmony.testString", "string test"); // The value type is string, with a maximum length of 256 characters.

   int ret = OH_AVMuxer_SetFormat(muxer, format); // Set the muxer format.
   if (ret != AV_ERR_OK) {
      // Failed to set the format. No valid key data to write was found.
   }
   OH_AVFormat_Destroy(format); // Destroy.
   ```

5. Add an audio track (only one audio track is supported).

   **Adding an AAC Audio Track**

   > **NOTE**
   >
   > When the audio codec type is HE-AAC (AAC_PROFILE_HE or AAC_PROFILE_HE_V2), only sample rates greater than or equal to 16000 Hz are supported.

   ```c++
   int audioTrackId = -1;
   // Example: multiplexing AAC-LC audio with a 44100 Hz sample rate and 2 channels.
   OH_AVFormat *formatAudio = OH_AVFormat_CreateAudioFormat(OH_AVCODEC_MIMETYPE_AUDIO_AAC, 44100, 2);
   OH_AVFormat_SetIntValue(formatAudio, OH_MD_KEY_PROFILE, AAC_PROFILE_LC); // Optional.

   int ret = OH_AVMuxer_AddTrack(muxer, &audioTrackId, formatAudio);
   OH_AVFormat_Destroy(formatAudio);
   if (ret != AV_ERR_OK || audioTrackId < 0) {
       // Failed to add the audio track.
   }
   ```

   <!--RP3--><!--RP3End-->

6. Add a video track (only one video track is supported).

   > **NOTE**
   >
   > When you need to set color information, you must ensure that the values of `OH_MD_KEY_COLOR_PRIMARIES`, `OH_MD_KEY_TRANSFER_CHARACTERISTICS`, and `OH_MD_KEY_MATRIX_COEFFICIENTS` all fall within their respective parameter ranges. Otherwise, the system will not recognize the data as valid color information. For details about the parameter ranges, see [OH_ColorPrimary](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_colorprimary), [OH_TransferCharacteristic](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_transfercharacteristic), and [OH_MatrixCoefficient](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_matrixcoefficient).

   ```c++
   int videoTrackId = -1;
   OH_AVFormat *formatVideo = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1280, 720);
   OH_AVFormat_SetDoubleValue(formatVideo, OH_MD_KEY_FRAME_RATE, 30.0); // Optional.

   int ret = OH_AVMuxer_AddTrack(muxer, &videoTrackId, formatVideo);
   OH_AVFormat_Destroy(formatVideo);
   if (ret != AV_ERR_OK || videoTrackId < 0) {
       // Failed to add the video track.
   }
   ```

   When color information needs to be set for a video track, set the color information-related keys before calling `OH_AVMuxer_AddTrack()`.

   ```c++
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // Optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // Optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // Optional.
   OH_AVFormat_SetIntValue(formatVideo, OH_MD_KEY_RANGE_FLAG, 1); // Optional. A value of 0 indicates limited range, and a value of 1 indicates full range.
   ```

7. Call `OH_AVMuxer_Start()` to start multiplexing.

   ```c++
   // Call start to write the multiplexing file header. After start, you cannot set media parameters or add audio/video tracks.
   if (OH_AVMuxer_Start(muxer) != AV_ERR_OK) {
       // Exception handling.
   }
   ```

8. Call `OH_AVMuxer_WriteSampleBuffer()` to write multiplexing data.

   The multiplexing data includes video and audio data.

   ```c++
   // Data can be written only after start. The following example writes one frame of audio data with a 48000 Hz sample rate and 1024 samples.
   int32_t size = 1024; // Data length of the current encoded frame, in bytes.
   OH_AVBuffer *sample = OH_AVBuffer_Create(size); // Create an AVBuffer.
   // For details about writing data to sampleBuffer through OH_AVBuffer_GetAddr(sample), see the usage of OH_AVBuffer.

   // Create the buffer info.
   OH_AVCodecBufferAttr attr = {0};
   attr.pts = 0; // Start playback time of the current data, in microseconds, relative time. The first frame is 0, and subsequent frames increment by "sample count * 1000000 / sample rate".
   attr.size = size; // Length of the current data, in bytes.
   attr.offset = 0; // Offset, typically 0.
   attr.flags |= AVCODEC_BUFFER_FLAGS_SYNC_FRAME; // Flag of the current data. For details, see OH_AVCodecBufferFlags.
   attr.flags |= AVCODEC_BUFFER_FLAGS_CODEC_DATA; // Flag indicating that the annex-b format AVC/HEVC contains codec config.
   OH_AVBuffer_SetBufferAttr(sample, &attr);
   int trackId = audioTrackId; // Select the audio/video track to write.

   int ret = OH_AVMuxer_WriteSampleBuffer(muxer, trackId, sample);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   OH_AVBuffer_Destroy(sample); // Destroy the buffer after writing is complete.
   ```

9. Call `OH_AVMuxer_Stop()` to stop multiplexing.

   ```c++
   // Call stop to write the multiplexing file trailer. After stop, you cannot write media data.
   int ret = OH_AVMuxer_Stop(muxer);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   ```

10. Call `OH_AVMuxer_Destroy()` to destroy the instance and release resources.

    Do not destroy the instance repeatedly. Otherwise, the program will crash.

    ```c++
    OH_AVMuxer_Destroy(muxer);
    muxer = nullptr;
    close(fd); // Close the file descriptor.
    ```