# Using AVPlayer to Play DRM Content (C/C++)

## When to Use

You can call the native APIs of DRM Kit to play DRM-protected programs.

Currently, the following decryption capabilities are supported:

| Audio Container Format| Audio Decryption Type|
|----------|:-------|
| mp4      | AAC    |

| Video Container Format| Video Decryption Type|
|----------|:------------|
| ts       | AVC(H.264)  |
| mp4      | AVC(H.264)  |
<!--RP1--><!--RP1End-->

**Usage Scenario**

Before creating DRM, obtain the DRM information. For details, see step 4 in [Media Data Demuxing](../avcodec/audio-video-demuxer.md#how-to-develop).

## How to Develop

Read [DRM](../../reference/apis-drm-kit/_drm.md) for the API reference.

Refer to the following sample code to complete the entire DRM process, including obtaining the name and ID list of the DRM solutions supported by the device, creating MediaKeySystem and MediaKeySession instances, generating a media key request, processing a media key response, checking whether secure video decoding is required, and destroying resources.

During application development, you must call the APIs in the defined sequence. Otherwise, an exception or undefined behavior may occur.  

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_drm.so)
```

> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
>

## How to Develop

1. Import the DRM Kit module.

    ```c++
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
    ```

2. Obtain the name and ID list of the DRM solutions supported by the device.

    ```c++
    uint32_t count = 3; // count indicates the number of DRM plugins supported by the device. Pass in the actual number.
    DRM_MediaKeySystemDescription descriptions[3];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
    ```

    After obtaining the name and ID list of DRM solutions supported by the device, match against the DRM information and create the corresponding DRM solution. You can obtain the DRM information by referring to step 4 in the [Media Data Demuxing](../avcodec/audio-video-demuxer.md#how-to-develop).

    Alternatively, directly parse the media protocol or media data to obtain the unique identifier of the DRM solution and the PSSH data, so as to generate the DRM information.

3. Create a MediaKeySystem instance.

    ```c++
    MediaKeySystem *mediaKeySystem = nullptr;
    ret = OH_MediaKeySystem_Create("com.clearplay.drm", &mediaKeySystem);
    if (ret != DRM_ERR_OK || mediaKeySystem == nullptr) {
        printf("OH_MediaKeySystem_Create failed.");
    }
    ```

4. Create a MediaKeySession instance.

    ```c++
    MediaKeySession *mediaKeySession = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO; // Set the content protection level supported by the device.
    ret = OH_MediaKeySystem_CreateMediaKeySession(mediaKeySystem, &contentProtectionLevel, &mediaKeySession);
    if (ret != DRM_ERR_OK || mediaKeySession == nullptr) {
        printf("OH_MediaKeySystem_CreateMediaKeySession failed.");
    }
    ```

5. Check whether secure decoding is required.

    ```c++
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession, "video/avc", &requireSecureDecoder);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RequireSecureDecoderModule failed.");
    }
    ```

6. Generate a media key request and process its response.

    ```c++
    #define MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE 24576 // 24576: (2 * 12 * 1024)
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    // initData corresponds to PSSH data in the stream. Pass in the actual data.
    unsigned char initData[512] = {0x00};
    memset(&info, 0, sizeof(DRM_MediaKeyRequestInfo));
    info.initDataLen = sizeof(initData);
    info.type = MEDIA_KEY_TYPE_ONLINE; // MEDIA_KEY_TYPE_ONLINE: online media key request; MEDIA_KEY_TYPE_OFFLINE: offline media key request.
    memcpy(info.mimeType, (char *)"video/mp4", sizeof("video/mp4"));
    memcpy(info.initData, initData, sizeof(initData));
    memcpy(info.optionName[0], (char *)"optionalDataName", sizeof("optionalDataName"));
    memcpy(info.optionData[0], (char *)"optionalDataValue", sizeof("optionalDataValue"));
    info.optionsCount = 1;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(mediaKeySession, &info, &mediaKeyRequest);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateMediaKeyRequest failed.");
    }
    /*
      The application requests the DRM service through the network, obtains a media key response, and sends the response to OH_MediaKeySession_ProcessMediaKeyResponse.
      If the response is an offline media key response, the offline media key ID is returned. Set mediaKeyId based on the actual data and length.
    */
    unsigned char mediaKeyId[128] = {0x00};
    int32_t mediaKeyIdLen = 128;
    // MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE specifies the maximum length of a media key response. Pass in the actual length.
    unsigned char mediaKeyResponse[MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE] = {0x00};
    int32_t mediaKeyResponseLen = MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE;
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession, mediaKeyResponse,
        mediaKeyResponseLen, mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessMediaKeyResponse failed.");
    }
    ```

    If required, set the audio decryption configuration by following step 4 in [Audio Decoding](../avcodec/audio-decoding.md#how-to-develop), and set the video decryption configuration by following step 4 in [Surface Output in Video Decoding](../avcodec/video-decoding.md#surface-mode) or step 4 in [Buffer Output in Video Decoding](../avcodec/video-decoding.md#buffer-mode).

7. Destroy the MediaKeySession instance.

    ```c++
    ret = OH_MediaKeySession_Destroy(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_Destroy failed.");
    }
    ```

8. Destroy the MediaKeySystem instance.

    ```c++
    ret = OH_MediaKeySystem_Destroy(mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Destroy failed.");
    }
    ```
