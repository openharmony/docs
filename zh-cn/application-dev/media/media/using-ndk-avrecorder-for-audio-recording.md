# 使用AVRecorder录制音频(C/C++)

AVRecorder支持开发音频或视频单独录制，集成了音频捕获，音频编码，视频编码，音视频封装功能，适用于实现简单音视频录制并直接得到本地媒体文件的场景。

本开发指导将以“开始录制-暂停录制-恢复录制-停止录制”的一次流程为示例，向开发者讲解如何使用AVRecorder进行音频录制。

在进行应用开发的过程中，开发者可以通过AVRecorder的state属性主动获取当前状态，或使用OH_AVRecorder_SetStateCallback方法注册回调监听状态变化。开发过程中应该严格遵循状态机要求，例如只能在started状态下调用pause()接口，只能在paused状态下调用resume()接口。

**图1** 录制状态变化示意图

![Recording status change](figures/recording-status-change-ndk.png)

状态的详细说明请参考[AVRecorderState](../../reference/apis-media-kit/js-apis-media.md#avrecorderstate9)。


## 申请权限

在开发此功能前，开发者应根据实际需求申请相关权限：
- 当需要使用麦克风时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要读取和保存音频文件时，请优先使用[AudioViewPicker音频选择器对象](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)。

> **说明：**
>
> 仅应用需要克隆、备份或同步用户公共目录的音频类文件时，可申请ohos.permission.READ_AUDIO、ohos.permission.WRITE_AUDIO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。

## 开发步骤及注意事项

> 选择只录音频时，与视频相关的所有参数（如videoFrameWidth和videoFrameHeight）均不需要配置。同理，选择只录视频不录音频时，与音频相关的所有参数（如audioBitrate和audioChannels）均不需要配置。


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
   > - 录制输出的url地址（即示例里avConfig中的url），形式为fd://xx (fd number)。需要调用基础文件操作接口实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/native-fileio-guidelines.md)。

   ```C++
   void SetConfig(OH_AVRecorder_Config &config)
   {
       config.audioSourceType = AVRECORDER_MIC;

       // 设置媒体属性。
       config.profile.audioBitrate = 100000;
       config.profile.audioChannels = 2;
       config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
       config.profile.audioSampleRate = 48000;
    
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4A;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;

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
        int32_t outputFd = open((AVREORDER_ROOT + "avrecorder01.mp3").c_str(), O_RDWR | O_CREAT, 0777); // 设置文件名。
        std::string fileUrl = "fd://" + std::to_string(outputFd);
        config->url = const_cast<char *>(fileUrl.c_str());
        OH_LOG_INFO(LOG_APP, "config.url is: %s", const_cast<char *>(fileUrl.c_str()));

        // 2. 设置回调。
        // 状态回调。
        OH_AVRecorder_SetStateCallback(g_avRecorder, OnStateChange, nullptr);

        // 错误回调。
        OH_AVRecorder_SetErrorCallback(g_avRecorder, OnError, nullptr);

        // 生成媒体文件回调（fileGenerationMode选择AUTO_CREATE时设置）。
        OH_LOG_INFO(LOG_APP, "==NDKDemo== OH_AVRecorder_SetUriCallback in!");
        OH_AVErrCode ret = OH_AVRecorder_SetUriCallback(g_avRecorder, OnUri, nullptr);
        OH_LOG_INFO(LOG_APP, "==NDKDemo== OH_AVRecorder_SetUriCallback out!");
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

4. 开始录制，调用OH_AVRecorder_Start()接口，此时AVRecorder进入started状态。

   ```C++
   OH_AVRecorder_Start(g_avRecorder);
   ```

5. 暂停录制，调用OH_AVRecorder_Pause()接口，此时AVRecorder进入paused状态，同时暂停输入源输入数据。

   ```C++
   OH_AVRecorder_Pause(g_avRecorder);
   ```

6. 恢复录制，调用OH_AVRecorder_Resume()接口，此时再次进入started状态。

   ```C++
   OH_AVRecorder_Resume(g_avRecorder);
   ```

7. 停止录制，调用OH_AVRecorder_Stop()接口，此时进入stopped状态。

   ```C++
   OH_AVRecorder_Stop(g_avRecorder);
   ```

8. 重置资源，调用OH_AVRecorder_Reset()重新进入idle状态，允许重新配置录制参数。

   ```C++
   OH_AVRecorder_Reset(g_avRecorder);
   ```

9. 销毁实例，调用OH_AVRecorder_Release()进入released状态，退出录制。

   ```C++
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
       OH_AVRecorder_StateChangeReason reason, void *userData) {
      (void)recorder;
      (void)userData;

      // 将 reason 转换为字符串表示。
      const char *reasonStr = (reason == AVRECORDER_USER) ? "USER" : (reason == AVRECORDER_BACKGROUND) ? "BACKGROUND" : "UNKNOWN";

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

      // 设置媒体属性。
      config.profile.audioBitrate = 96000;
      config.profile.audioChannels = 2;
      config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
      config.profile.audioSampleRate = 48000;

      config.profile.fileFormat = AVRECORDER_CFT_MPEG_4;
      config.fileGenerationMode = AVRECORDER_APP_CREATE;

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
      int32_t outputFd = open((AVREORDER_ROOT + "avrecorder01.mp3").c_str(), O_RDWR | O_CREAT, 0777); // 设置文件名。
      std::string fileUrl = "fd://" + std::to_string(outputFd);
      config->url = const_cast<char *>(fileUrl.c_str());
      OH_LOG_INFO(LOG_APP, "config.url is: %s", const_cast<char *>(fileUrl.c_str()));

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

   // 2. 开始录制。
   static napi_value StartAVRecorder(napi_env env, napi_callback_info info)
   {
      (void)info;
      OH_LOG_INFO(LOG_APP, "==NDKDemo== g_avRecorder start: %{public}p", g_avRecorder);
      int result = OH_AVRecorder_Start(g_avRecorder);
      if (result != AV_ERR_OK) {
         OH_LOG_ERROR(LOG_APP, "==NDKDemo== AVRecorder Start failed %{public}d", result);
      }
      napi_value res;
      napi_create_int32(env, result, &res);
      return res;
   }

   // 3. 暂停录制。
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

   // 4. 恢复录制。
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

   // 5. 停止录制。
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
   
   // 6. 重置录制状态。
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

   // 7. 释放录制资源。
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