# DRM Playback with AVCodec (C/C++)

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ecefca9013cc090f0688005ae538b04dd2dd930a translatedAt=2026-08-11T01:41:28.095Z pushedAt=2026-08-11T02:40:29.701Z -->

## When to Use

To play DRM-protected content using AVCodec, you can use the native APIs provided by DRM Kit.

Currently, the following decryption capabilities are supported:

| Audio Container| Audio Decryption|
|----------|:-------|
| mp4      | AAC    |

| Video Container| Video Decryption|
|----------|:------------|
| ts       | AVC(H.264)  |
| mp4      | AVC(H.264)  |

<!--RP1--><!--RP1End-->

**Usage Scenario**

Before setting up DRM, obtain the DRM information. For details, see step 4 in [Media Data Demultiplexing](../avcodec/audio-video-demuxer.md#how-to-develop).

## Development Guidelines

For detailed API descriptions, refer to [DRM](../../reference/apis-drm-kit/capi-drm.md).

Follow the sample code below to implement the entire DRM workflow, including obtaining a name and ID list of the DRM solutions supported by the device, creating a MediaKeySystem, creating a MediaKeySession, generating a media key request, processing a media key response, checking for secure video decoding requirements, and cleaning up resources.

When developing your application, follow the specified order of API calls to avoid exceptions or undefined behaviors. The development steps and explanations below outline the correct sequence.

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_drm.so)
```

> **NOTE**
>
> Replace 'sample' with your actual project name as needed.
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
    uint32_t count = 3; // count specifies the number of DRM plugins supported by the device. Pass in the actual number.
    DRM_MediaKeySystemDescription descriptions[3];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
    ```

    After obtaining the list of names and unique identifiers of the DRM solutions supported by the device, match them with the DRM information and create the corresponding DRM solution. The DRM information can be obtained through step 4 of the development procedure in [Media Data Demultiplexing](../avcodec/audio-video-demuxer.md#how-to-develop).

    Alternatively, directly parse the media protocol or media data to extract the unique identifier of the DRM solution and the PSSH data to generate the DRM information.

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
    if (sizeof("video/mp4") <= sizeof(info.mimeType)) {
    memcpy(info.mimeType, "video/mp4", sizeof("video/mp4"));
    }
    if (info.initDataLen <= sizeof(info.initData)) {
    memcpy(info.initData, initData, info.initDataLen);
    }
    if (sizeof("optionalDataName") <= sizeof(info.optionName[0])) {
    memcpy(info.optionName[0], "optionalDataName", sizeof("optionalDataName"));
    }

    if (sizeof("optionalDataValue") <= sizeof(info.optionData[0])) {
    memcpy(info.optionData[0], "optionalDataValue", sizeof("optionalDataValue"));
    }
    info.optionsCount = 1;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(mediaKeySession, &info, &mediaKeyRequest);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateMediaKeyRequest failed.");
    }
    /*
     The app requests the DRM service over the network to obtain mediaKeyResponse and passes it to OH_MediaKeySession_ProcessMediaKeyResponse.
    When processing an offline media key response, the API returns the offline media key ID, mediaKeyId. Pass the actual data and data length as required.
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

    If required, set the audio decryption configuration by following step 4 in [Audio Decoding](../avcodec/audio-decoding.md#how-to-develop), and set the video decryption configuration by following step 4 in [Surface Mode in Video Decoding](../avcodec/video-decoding.md#surface-mode) or step 4 in [Buffer Mode in Video Decoding](../avcodec/video-decoding.md#buffer-mode).

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