# 使用AVRecorder录制视频(C/C++)

AVRecorder支持开发音视频录制，集成了音频捕获，音频编码，视频编码，音视频封装功能，适用于实现简单视频录制并直接得到本地媒体文件的场景。

本开发指导将以“开始录制-暂停录制-恢复录制-停止录制”的一次流程为示例，向开发者讲解如何使用AVRecorder进行视频录制。

在进行应用开发的过程中，开发者可以通过AVRecorder的state属性主动获取当前状态，或使用OH_AVRecorder_SetStateCallback方法注册回调监听状态变化。开发过程中应该严格遵循状态机要求，例如只能在started状态下调用pause()接口，只能在paused状态下调用resume()接口。

**图1** 录制状态变化示意图

![Recording status change](figures/recording-status-change-ndk.png)

状态的详细说明请参考[AVRecorderState](../../reference/apis-media-kit/js-apis-media.md#avrecorderstate9)。


## 申请权限

在开发此功能前，开发者应根据实际需求申请相关权限：
- 当需要使用麦克风时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要使用相机拍摄时，需要申请**ohos.permission.CAMERA**相机权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要从图库读取图片或视频文件时，请优先使用媒体库[Picker选择媒体资源](../medialibrary/photoAccessHelper-photoviewpicker.md)。
- 当需要保存图片或视频文件至图库时，请优先使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)。

> **说明：**
>
> 仅应用需要克隆、备份或同步用户公共目录的图片、视频类文件时，可申请ohos.permission.READ_IMAGEVIDEO、ohos.permission.WRITE_IMAGEVIDEO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。


## 开发步骤及注意事项

> **说明：**
>
> AVRecorder只负责视频数据的处理，需要与视频数据采集模块配合才能完成视频录制。视频数据采集模块需要通过Surface将视频数据传递给AVRecorder进行数据处理。当前常用的数据采集模块为相机模块，具体请参考[相机-录像](../camera/native-camera-recording.md)。
> 文件的创建与存储，请参考[应用文件访问与管理](../../file-management/app-file-access.md)，默认存储在应用的沙箱路径之下，如需存储至图库，请使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)对沙箱内文件进行存储。


开发者通过引入[avrecorder.h](../../reference/apis-media-kit/capi-avrecorder-h.md)、[avrecorder_base.h](../../reference/apis-media-kit/capi-avrecorder-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用视频录制相关API。

AVRecorder详细的API说明请参考[AVRecorder API参考](../../reference/apis-media-kit/capi-avrecorder.md)。

在 CMake 脚本中链接动态库。
```
target_link_libraries(entry PUBLIC libavrecorder.so)
```

使用[OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat)相关接口时，需引入如下头文件。
```
#include <multimedia/player_framework/native_avformat.h>
```

并在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libnative_media_core.so)
```

开发者使用系统日志能力时，需引入如下头文件。
```
#include <hilog/log.h>
```

并需要在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```

1. 创建AVRecorder实例，实例创建完成进入idle状态。

   ```C++
   #include <multimedia/player_framework/avrecorder.h>
   #include <multimedia/player_framework/avrecorder_base.h>

   static struct OH_AVRecorder *g_avRecorder = {};
   g_avRecorder = OH_AVRecorder_Create();
   ```

2. 设置业务需要的监听事件，监听状态变化及错误上报。
   | 事件类型 | 说明 |
   | -------- | -------- |
   | OnStateChange | 监听AVRecorder的状态改变。 |
   | OnError | 监听AVRecorder的错误信息。 |
   | OnUri | 监听AVRecorder生成媒体文件。 |

   ```C++
   // 设置状态回调。
   void OnStateChange(OH_AVRecorder *recorder, OH_AVRecorder_State state,
       OH_AVRecorder_StateChangeReason reason, void *userData) {
       (void)recorder;
       (void)userData;

       // 将 reason 转换为字符串表示。
       const char *reasonStr = (reason == AVRECORDER_USER) ? "USER" : (reason == AVRECORDER_BACKGROUND) ? "BACKGROUND" : "UNKNOWN";

       if (state == IDLE) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange IDLE, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == PREPARED) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange PREPARED, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == STARTED) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange STARTED, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == PAUSED) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange PAUSED, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == STOPPED) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange STOPPED, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == RELEASED) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange RELEASED, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
       if (state == ERROR) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange ERROR, reason: %{public}s", reasonStr);
           // 处理状态变更。
       }
   }

   // 设置错误回调。
   void OnError(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData) {
       (void)recorder;
       (void)userData;
       OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnError errorCode: %{public}d, error message: %{public}s",
           errorCode, errorMsg);
   }

   // 设置生成媒体文件回调（fileGenerationMode选择AUTO_CREATE时设置）。
   void OnUri(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData) {
       (void)recorder;
       (void)userData;
       if (asset != nullptr) {
           auto changeRequest = OH_MediaAssetChangeRequest_Create(asset);
           if (changeRequest == nullptr) {
               OH_LOG_ERROR(LOG_APP, "==NDKDemo== changeRequest is null!");
               return;
           }
           MediaLibrary_ImageFileType imageFileType = MEDIA_LIBRARY_IMAGE_JPEG; // 待媒体库提供可用的VIDEO接口。
           uint32_t result = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, imageFileType);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAssetChangeRequest_SaveCameraPhoto: %d", result);

           uint32_t resultChange = OH_MediaAccessHelper_ApplyChanges(changeRequest);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAccessHelper_ApplyChanges: %d", resultChange);

           OH_MediaAsset_Release(asset);
           OH_MediaAssetChangeRequest_Release(changeRequest);
       } else {
           OH_LOG_ERROR(LOG_APP, "Received null media asset!");
       }
   }
   ```

3. 配置视频录制参数，调用OH_AVRecorder_Prepare()接口，此时进入prepared状态。

   > **说明：**
   >
   > 配置参数需要注意：
   >
   > - 配置参数之前需要确保完成对应权限的申请，请参考[申请权限](#申请权限)。
   >
   > - prepare接口的入参OH_AVRecorder_Config中设置音视频相关的配置参数，如示例代码所示。
   >
   > - 需要使用支持的[录制规格](media-kit-intro.md#支持的格式)，视频比特率、分辨率、帧率以实际硬件设备支持的范围为准。
   >
   > - 录制输出的url地址（即示例里avConfig中的url），形式为fd://xx (fd number)。需要调用基础文件操作接口实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/native-fileio-guidelines.md)。

   ```C++
   void SetConfig(OH_AVRecorder_Config &config)
   {
       config.audioSourceType = AVRECORDER_MIC;
       config.videoSourceType = AVRECORDER_SURFACE_ES;

       // 设置媒体属性。
       config.profile.audioBitrate = 96000;
       config.profile.audioChannels = 2;
       config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
       config.profile.audioSampleRate = 48000;

       config.profile.videoBitrate = 2000000;
       config.profile.videoFrameWidth = 1280;
       config.profile.videoFrameHeight = 720;
       config.profile.videoFrameRate = 30;
       config.profile.videoCodec = AVRECORDER_VIDEO_AVC;
       config.profile.isHdr = false;
       config.profile.enableTemporalScale = false;
    
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;

       config.metadata.videoOrientation = (char*)malloc(2);
       if (config.metadata.videoOrientation != nullptr) {
           strcpy(config.metadata.videoOrientation, "0"); // 视频旋转角度，支持0、90、180、270。
       }
       OH_LOG_INFO(LOG_APP, "==NDKDemo== videoOrientation: %{public}s", config.metadata.videoOrientation);

       config.metadata.location.latitude = 27.791863;
       config.metadata.location.longitude = 64.574687;
    }

    // 准备录制。
    static napi_value PrepareAVRecorder(napi_env env, napi_callback_info info)
    {
        (void)info;
        OH_LOG_INFO(LOG_APP, "==NDKDemo== PrepareAVRecorder in!");
        g_avRecorder = OH_AVRecorder_Create();
        OH_LOG_INFO(LOG_APP, "==NDKDemo== AVRecorder Create ok! g_avRecorder: %{public}p", g_avRecorder);
        if (g_avRecorder == nullptr) {
            OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Create failed!");
        }
        OH_AVRecorder_Config *config = new OH_AVRecorder_Config();
        
        SetConfig(*config);
    
        // 1. 设置URL（fileGenerationMode选择APP_CREATE时设置）。
        const std::string AVREORDER_ROOT = "/data/storage/el2/base/files/";
        int32_t outputFd = open((AVREORDER_ROOT + "avrecorder01.mp4").c_str(), O_RDWR | O_CREAT, 0777); // 设置文件名。
        std::string fileUrl = "fd://" + std::to_string(outputFd);
        config->url = const_cast<char *>(fileUrl.c_str());
        OH_LOG_INFO(LOG_APP, "config.url is: %s", const_cast<char *>(fileUrl.c_str()));
    
        // 2. 设置回调。
        // 状态回调。
        OH_AVRecorder_SetStateCallback(g_avRecorder, OnStateChange, nullptr);

        // 错误回调。
        OH_AVRecorder_SetErrorCallback(g_avRecorder, OnError, nullptr);

        // 生成媒体文件回调（fileGenerationMode选择AUTO_CREATE时设置）。
        OH_AVErrCode ret = OH_AVRecorder_SetUriCallback(g_avRecorder, OnUri, nullptr);
        if (ret == AV_ERR_OK) {
            OH_LOG_INFO(LOG_APP, "==NDKDemo==  OH_AVRecorder_SetUriCallback succeed!");
        } else {
            OH_LOG_ERROR(LOG_APP, "==NDKDemo==  Failed to set URI callback, error code: %d", ret);
        }
        
        // 3. 调用prepare接口。
        int result = OH_AVRecorder_Prepare(g_avRecorder, config);
        if (result != AV_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Prepare failed %{public}d", result);
        }
      
        napi_value res;
        napi_create_int32(env, result, &res);
        return res;
    }
   ```

4. 获取视频录制需要的SurfaceID，初始化视频数据输入源。该步骤需要在输入源模块完成，以相机为例，需要创建录像输出流，包括创建Camera对象、获取相机列表、创建相机输入流等，相机详细步骤请参考[相机-录像方案](../camera/native-camera-recording.md)。
   调用getInputSurface()接口，接口的返回值SurfaceID用于传递给视频数据输入源模块。常用的输入源模块为相机，以下示例代码中，仅展示获取SurfaceID的步骤。

   输入源模块通过SurfaceID可以获取到Surface，通过Surface可以将视频数据流传递给AVRecorder，由AVRecorder再进行视频数据的处理。

   ```C++
   // 获取surfaceID。
   OHNativeWindow *window = nullptr;
   int resultCode = OH_AVRecorder_GetInputSurface(g_avRecorder, &window);
   uint64_t surfaceId = 0;
   OH_NativeWindow_GetSurfaceId(window, &surfaceId);
   ```

5. 初始化视频数据输入源。该步骤需要在输入源模块完成，以相机为例，需要创建录像输出流，包括创建Camera对象、获取相机列表、创建相机输入流等，相机详细步骤请参考[相机-录像方案](../camera/native-camera-recording.md)。

6. 开始录制，启动输入源输入视频数据，例如相机模块调用OH_VideoOutput_Start()接口启动相机录制。然后调用OH_AVRecorder_Start()接口，此时AVRecorder进入started状态。
   ```
   OH_AVRecorder_Start(g_avRecorder);
   ```
7. 暂停录制，调用OH_AVRecorder_Pause()接口，此时AVRecorder进入paused状态，同时暂停输入源输入数据。例如相机模块调用OH_VideoOutput_Stop()停止相机视频数据输入。
   ```
   OH_AVRecorder_Pause(g_avRecorder);
   ```
8. 恢复录制，调用OH_AVRecorder_Resume()接口，此时再次进入started状态。
   ```
   OH_AVRecorder_Resume(g_avRecorder);
   ```
9. 停止录制，调用OH_AVRecorder_Stop()接口，此时进入stopped状态，同时停止相机录制。
   ```
   OH_AVRecorder_Stop(g_avRecorder);
   ```
10. 重置资源，调用OH_AVRecorder_Reset()重新进入idle状态，允许重新配置录制参数。
      ```
      OH_AVRecorder_Reset(g_avRecorder);
      ```
11. 销毁实例，调用OH_AVRecorder_Release()进入released状态，退出录制，释放视频数据输入源相关资源，例如相机资源。
      ```
      OH_AVRecorder_Release(g_avRecorder);
      ```


## 完整示例

参考以下示例，包括“创建录制实例-准备录制-开始录制-暂停录制-恢复录制-停止录制-重置录制状态-释放录制资源”的完整流程。

   ```C++
   #include <fcntl.h>
   #include "hilog/log.h"
   #include <multimedia/player_framework/avrecorder.h>
   #include <multimedia/player_framework/avrecorder_base.h>
   #include <multimedia/media_library/media_asset_change_request_capi.h>
   #include <multimedia/media_library/media_access_helper_capi.h>
   #include <multimedia/media_library/media_asset_capi.h>

   static struct OH_AVRecorder *g_avRecorder = {};

   // 设置状态回调。
   void OnStateChange(OH_AVRecorder *recorder, OH_AVRecorder_State state,
                      OH_AVRecorder_StateChangeReason reason, void *userData)
   {
      (void)recorder;
      (void)userData;

      // 将 reason 转换为字符串表示。
      const char *reasonStr = (reason == AVRECORDER_USER) ? "USER" :
                              (reason == AVRECORDER_BACKGROUND) ? "BACKGROUND" : "UNKNOWN";

      if (state == AVRECORDER_IDLE) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange IDLE, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_PREPARED) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange PREPARED, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_STARTED) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange STARTED, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_PAUSED) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange PAUSED, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_STOPPED) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange STOPPED, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_RELEASED) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange RELEASED, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
      if (state == AVRECORDER_ERROR) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange ERROR, reason: %{public}s", reasonStr);
         // 处理状态变更。
      }
   }

   // 设置错误回调。
   void OnError(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
   {
      (void)recorder;
      (void)userData;
      OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnError errorCode: %{public}d, error message: %{public}s",
                  errorCode, errorMsg);
   }

   // 设置生成媒体文件回调（fileGenerationMode选择AUTO_CREATE时设置）。
   void OnUri(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
   {
      (void)recorder;
      (void)userData;
      OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri in!");
      if (asset != nullptr) {
         auto changeRequest = OH_MediaAssetChangeRequest_Create(asset);
         if (changeRequest == nullptr) {
            OH_LOG_ERROR(LOG_APP, "==NDKDemo== changeRequest is null!");
            return;
         }
         MediaLibrary_ImageFileType imageFileType = MEDIA_LIBRARY_IMAGE_JPEG; // 待媒体库提供可用的VIDEO接口。
         uint32_t result = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, imageFileType);
         OH_LOG_INFO(LOG_APP, "result of OH_MediaAssetChangeRequest_SaveCameraPhoto: %d", result);

         uint32_t resultChange = OH_MediaAccessHelper_ApplyChanges(changeRequest);
         OH_LOG_INFO(LOG_APP, "result of OH_MediaAccessHelper_ApplyChanges: %d", resultChange);

         OH_MediaAsset_Release(asset);
         OH_MediaAssetChangeRequest_Release(changeRequest);
      } else {
         OH_LOG_ERROR(LOG_APP, "Received null media asset!");
      }
      OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri out!");
   }

   void SetConfig(OH_AVRecorder_Config &config)
   {
      config.audioSourceType = AVRECORDER_MIC;
      config.videoSourceType = AVRECORDER_SURFACE_ES;

      // 设置媒体属性。
      config.profile.audioBitrate = 96000;
      config.profile.audioChannels = 2;
      config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
      config.profile.audioSampleRate = 48000;

      config.profile.videoBitrate = 2000000;
      config.profile.videoFrameWidth = 1280;
      config.profile.videoFrameHeight = 720;
      config.profile.videoFrameRate = 30;
      config.profile.videoCodec = AVRECORDER_VIDEO_AVC;
      config.profile.isHdr = false;
      config.profile.enableTemporalScale = false;

      config.profile.fileFormat = AVRECORDER_CFT_MPEG_4;
      config.fileGenerationMode = AVRECORDER_APP_CREATE;

      config.metadata.videoOrientation = (char *)malloc(2);
      if (config.metadata.videoOrientation != nullptr) {
         strcpy(config.metadata.videoOrientation, "0"); // 视频旋转角度，支持0、90、180、270。
      }
      OH_LOG_INFO(LOG_APP, "==NDKDemo== videoOrientation: %{public}s", config.metadata.videoOrientation);

      config.metadata.location.latitude = 27.791863;
      config.metadata.location.longitude = 64.574687;
   }

   // 1.准备录制。
   static napi_value PrepareAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      OH_LOG_INFO(LOG_APP, "==NDKDemo== PrepareAVRecorder in!");
      g_avRecorder = OH_AVRecorder_Create();
      OH_LOG_INFO(LOG_APP, "==NDKDemo== AVRecorder Create ok! g_avRecorder: %{public}p", g_avRecorder);
      if (g_avRecorder == nullptr) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Create failed!");
      }
      OH_AVRecorder_Config *config = new OH_AVRecorder_Config();

      SetConfig(*config);

      // 1.1 设置URL（fileGenerationMode选择APP_CREATE时设置）。
      const std::string AVREORDER_ROOT = "/data/storage/el2/base/files/";
      int32_t outputFd = open((AVREORDER_ROOT + "avrecorder01.mp4").c_str(), O_RDWR | O_CREAT, 0777); // 设置文件名。
      std::string fileUrl = "fd://" + std::to_string(outputFd);
      config->url = const_cast<char *>(fileUrl.c_str());

      // 1.2 设置回调。
      // 状态回调。
      OH_AVRecorder_SetStateCallback(g_avRecorder, OnStateChange, nullptr);

      // 错误回调。
      OH_AVRecorder_SetErrorCallback(g_avRecorder, OnError, nullptr);

      // 生成媒体文件回调（fileGenerationMode选择AUTO_CREATE时设置）。
      OH_AVErrCode ret = OH_AVRecorder_SetUriCallback(g_avRecorder, OnUri, nullptr);
      if (ret == AV_ERR_OK) {
         OH_LOG_INFO(LOG_APP, "==NDKDemo==  OH_AVRecorder_SetUriCallback succeed!");
      } else {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo==  Failed to set URI callback, error code: %d", ret);
      }

      // 1.3 调用prepare接口。
      int result = OH_AVRecorder_Prepare(g_avRecorder, config);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Prepare failed %{public}d", result);
      }

      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 2. 启动相机。
   static napi_value PrepareCamera(napi_env env, napi_callback_info info)
   {
      OH_LOG_INFO(LOG_APP, "==NDKDemo== AVRecorder PrepareCamera");
      (void)info;

      OHNativeWindow *window = nullptr;
      int resultCode = OH_AVRecorder_GetInputSurface(g_avRecorder, &window);
      if (resultCode != AV_ERR_OK || window == nullptr) {
          OH_LOG_INFO(LOG_APP, "==NDKDemo== AVRecorder OH_AVRecorder_GetInputSurface failed!");
          napi_value errorResult;
          napi_create_int32(env, -1, &errorResult); // -1 表示错误
          return errorResult;
      }
      uint64_t surfaceId = 0;
      OH_NativeWindow_GetSurfaceId(window, &surfaceId);

      // 将surfaceId传入数据采集模块，具体请参考相机模块。

      int result = 0;
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 3. 开始录制。
   static napi_value StartAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      int result = OH_AVRecorder_Start(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Start failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 4. 暂停录制。
   static napi_value PauseAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      int result = OH_AVRecorder_Pause(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Pause failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 5. 恢复录制。
   static napi_value ResumeAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      int result = OH_AVRecorder_Resume(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Resume failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 6. 停止录制。
   static napi_value StopAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      int result = OH_AVRecorder_Stop(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Stop failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 7. 重置录制状态。
   static napi_value ResetAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      // 检查 g_avRecorder 是否有效。
      if (g_avRecorder == nullptr) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== g_avRecorder is nullptr!");
         napi_value res;
         napi_create_int32(env, AV_ERR_INVALID_VAL, &res);
         return res;
      }

      int result = OH_AVRecorder_Reset(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Reset failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 8. 释放录制资源。
   static napi_value ReleaseAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      // 检查 g_avRecorder 是否有效。
      if (g_avRecorder == nullptr) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== g_avRecorder is nullptr!");
         napi_value res;
         napi_create_int32(env, AV_ERR_INVALID_VAL, &res);
         return res;
      }
      
      int result = OH_AVRecorder_Release(g_avRecorder);
      g_avRecorder = nullptr;   // 释放录制资源后，需要显式地将g_avRecorder指针置空。

      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Release failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }
   ```