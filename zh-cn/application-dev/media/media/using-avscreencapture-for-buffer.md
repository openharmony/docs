# 使用AVScreenCapture录屏取码流(C/C++)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--SE: @stupig001-->
<!--TSE: @xdlinc-->

屏幕录制支持开发者获取屏幕数据，可用于屏幕录制、会议共享、直播等场景。通过录屏取码流方式获取的流数据可根据场景，进行不同的处理。例如：
- 对接NativeImage作为消费者端，提供Surface关联OpenGL外部纹理，具体使用请参考[NativeImage开发指导](../../graphics/native-image-guidelines.md)。
- 对接编码器、封装器进行数据的编码、封装，具体使用请参考[视频编码](../avcodec/video-encoding.md)、[媒体数据封装](../avcodec/audio-video-muxer.md)。
<!--RP1--><!--RP1End-->

开发者可以调用录屏（[AVScreenCapture](media-kit-intro.md#avscreencapture)）模块的C API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。当开发直播、办公等应用时，可以调用录屏模块获取音视频原始码流，然后通过流的方式流转到其他模块处理，达成直播时共享桌面的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

当前在进行屏幕录制时默认使用主屏，图形默认根据主屏生产录屏帧数据到显示数据缓冲队列，录屏框架从显示数据缓冲队列获取数据进行相应处理。

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始屏幕录制时正在通话中或者屏幕录制过程中来电，录屏将自动停止。因通话中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL状态。

屏幕录制过程中发生系统用户切换事件时，录屏将自动停止。因系统用户切换中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../../reference/apis-media-kit/capi-avscreencapture.md)。

如果配置了采集麦克风音频数据，需对应配置麦克风权限ohos.permission.MICROPHONE和申请长时任务，配置方式请参见[向用户申请权限](../../security/AccessToken/request-user-authorization.md)、[申请长时任务](../../task-management/continuous-task.md)。

<!--RP2--><!--RP2End-->

## 开发步骤及注意事项

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。
在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

**在 CMake 脚本中链接动态库**

```c++
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libnative_buffer.so libnative_media_core.so)
```

1. 添加头文件。

    ```c++
    #include "napi/native_api.h"
    #include <multimedia/player_framework/native_avscreen_capture.h>
    #include <multimedia/player_framework/native_avscreen_capture_base.h>
    #include <multimedia/player_framework/native_avscreen_capture_errors.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <native_buffer/native_buffer.h>
    #include <vector>
    ```

2. 判断当前是否存在未结束的录屏服务实例，若存在，则先停止并释放资源。

3. 创建AVScreenCapture实例capture。

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

4. 配置屏幕录制参数。

    创建AVScreenCapture实例capture后，可以设置屏幕录制所需要的参数，音频信息和视频信息的具体参数配置可参考[详细说明](#详细说明)。

    ```c++
    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
        .innerCapInfo = innerCapInfo,
        .audioEncInfo = audioEncInfo
    };

    OH_VideoInfo videoinfo = {
        .videoCapInfo = videocapinfo,
        .videoEncInfo = videoEncInfo
    };

    OH_AVScreenCaptureConfig config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_ORIGINAL_STREAM,
        .audioInfo = audioinfo,
        .videoInfo = videoinfo
    };

    OH_AVScreenCapture_Init(capture, config);
    ```

5. 设置麦克风开关。(可选)

    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

6. 回调函数的设置，主要监听录屏过程中的错误事件的发生，音频流和视频流数据的产生事件，录屏屏幕id的获取事件，录屏内容变更事件，具体设计可参考[详细说明](#详细说明)。

    ```c++
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);
    OH_AVScreenCapture_SetDisplayCallback(capture, OnDisplaySelected, userData);
    OH_AVScreenCapture_SetCaptureContentChangedCallback(capture, OnCaptureContentChanged, userData);
    OH_AVScreenCapture_SetSelectionCallback(capture, OnUserSelected, userData);
    ```

7. 设置此次录屏的可配置策略。（可选）

   7.1 设置屏幕录制隐私窗口屏蔽模式。（可选）

        value值设为0，表示全屏屏蔽模式。value值设为1，表示窗口屏蔽模式。默认为全屏屏蔽模式。

        ```c++
        int value = 0;
        OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
        OH_AVScreenCapture_StrategyForPrivacyMaskMode(strategy, value);
        OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
        ```

   7.2 设置屏幕录屏自动跟随旋转配置。（可选）

       设为true，表示跟随屏幕旋转，并在横竖屏旋转后，自动调换虚拟屏尺寸，确保输出画面及时跟随旋转。设置后在旋转通知后，无需再手动调用OH_AVScreenCapture_ResizeCanvas接口。

        ```c++
        OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
        OH_AVScreenCapture_StrategyForCanvasFollowRotation(strategy, true);
        OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
        ```

8. 调用StartScreenCapture()方法开始进行屏幕录制。

    ```c++
    bool IsCaptureStreamRunning = true;
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

    或调用StartScreenCaptureWithSurface()方法以Surface模式进行屏幕录制。

    ```c++
    OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window);
    ```

9. 调用StopScreenCapture()方法停止录制，具体设计可参考[详细说明](#详细说明)。

    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

10. 调用Release()方法销毁实例，释放资源。

    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

## PC/2in1设备录屏窗口选择界面规格说明
基于录屏取码流接口提供了PC/2in1设备录屏窗口选择界面，按照以下表格中的配置弹出相应的弹窗。PC/2in1设备弹出Picker选择弹窗并根据传入的窗口Id选中对应窗口。最终录屏内容以Picker弹出后，用户在弹窗上的选择为准。

API 20开始，支持通过[OH_AVScreenCapture_SetCaptureArea](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea)接口，设置区域录屏功能生效，弹出隐私允许/不允许弹窗。

| 屏幕模式类型                                          | 传入窗口Id数量     | 弹窗类型            |
| ----------------------------------------------------- | ------------------ | ------------------- |
| OH_CAPTURE_HOME_SCREEN                                | 传入的窗口Id不生效 | 隐私允许/不允许弹窗 |
| OH_CAPTURE_SPECIFIED_SCREEN                           | 传入的窗口Id不生效 | Picker弹窗          |
| OH_CAPTURE_SPECIFIED_WINDOW                           | 0个或1个窗口Id     | Picker弹窗          |
| OH_CAPTURE_SPECIFIED_WINDOW                           | 2个或多个窗口Id    | 隐私允许/不允许弹窗 |
| 区域录屏（调用OH_AVScreenCapture_SetCaptureArea接口） | 传入的窗口Id不生效 | 隐私允许/不允许弹窗 |

PC/2in1设备录屏窗口选择界面推荐在OH_CAPTURE_SPECIFIED_WINDOW模式下使用，需根据PC/2in1设备分辨率配置录屏的高度和宽度值并传入屏幕Id（若有期望录制的某个窗口，可同时传入单个窗口Id）。

```c++
// 根据PC/2in1设备分辨率在config_中配置录屏的宽度、高度。
config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

// 设置录屏模式为OH_CAPTURE_SPECIFIED_WINDOW，传入屏幕Id。
config_.captureMode = OH_CAPTURE_SPECIFIED_WINDOW;
config_.videoInfo.videoCapInfo.displayId = 0;

// (可选)若有期望录制的窗口，可传入单个窗口Id。
vector<int32_t> missionIds = {61}; // 表示弹出的Picker默认选中61号窗口。
config_.videoInfo.videoCapInfo.missionIDs = &missionIds[0];
config_.videoInfo.videoCapInfo.missionIDsLen = static_cast<int32_t>(missionIds.size());
```

另外，PC/2in1设备录屏窗口选择界面兼容以下几种模式的录屏：

1. OH_CAPTURE_SPECIFIED_WINDOW模式，传入多个窗口Id。

    PC/2in1设备不弹Picker选择界面，弹出隐私允许/不允许弹窗，可同时录制多个窗口；

    ```c++
    // 根据PC/2in1设备分辨率在config_中配置录屏的宽度、高度。
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // 设置录屏模式为OH_CAPTURE_SPECIFIED_WINDOW，传入屏幕Id。
    config_.captureMode = OH_CAPTURE_SPECIFIED_WINDOW;
    config_.videoInfo.videoCapInfo.displayId = 0;

    // 传入多个窗口Id。
    vector<int32_t> missionIds = {60, 61}; // 表示期望同时录制60、61号窗口。
    config_.videoInfo.videoCapInfo.missionIDs = &missionIds[0];
    config_.videoInfo.videoCapInfo.missionIDsLen = static_cast<int32_t>(missionIds.size());
    ```

2. OH_CAPTURE_SPECIFIED_SCREEN模式。

    PC/2in1设备弹出Picker选择弹窗，传入的有效屏幕Id作为Picker弹窗上被选中的默认屏幕；

    ```c++
    // 根据PC/2in1设备分辨率在config_中配置录屏的宽度、高度。
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // 设置录屏模式为OH_CAPTURE_SPECIFIED_SCREEN，传入屏幕Id。
    config_.captureMode = OH_CAPTURE_SPECIFIED_SCREEN;
    config_.videoInfo.videoCapInfo.displayId = 0;
    ```

3. OH_CAPTURE_HOME_SCREEN模式。

    PC/2in1设备不弹Picker选择界面，弹出隐私允许/不允许弹窗；
    此模式下，配置的videoCapInfo.displayId不会生效，默认使用主屏displayId。

    ```c++
    // 根据PC/2in1设备分辨率在config_中配置录屏的宽度、高度。
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // 设置录屏模式为OH_CAPTURE_HOME_SCREEN，传入屏幕Id。
    config_.captureMode = OH_CAPTURE_HOME_SCREEN;
    ```

## 详细说明
针对[开发步骤及注意事项](#开发步骤及注意事项)中屏幕录制参数配置、回调函数设置、停止录屏服务实例步骤进一步详细说明。

1. 屏幕录制参数配置。
    ```c++
    // audioinfo音频信息配置。
    OH_AudioCaptureInfo micCapinfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_SOURCE_DEFAULT
    };
    OH_AudioCaptureInfo innerCapInfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_ALL_PLAYBACK
    };
    OH_AudioEncInfo audioEncInfo = {
        .audioSampleRate = 48000,
        .audioCodecformat = OH_AudioCodecFormat::OH_AAC_LC
    };

    // videoinfo视频信息配置。
    OH_VideoCaptureInfo videoCapInfo = {
        .videoFrameWidth = 768,
        .videoFrameHeight = 1280,
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };
    OH_VideoEncInfo videoEncInfo = {
        .videoCodec = OH_VideoCodecFormat::OH_H264,
        .videoBitrate = 2000000,
        .videoFrameRate = 30
    };
    ```

2. 回调函数设置。
    
    针对录屏过程中可能发生的错误事件、状态变化、数据获取和录屏内容变更，分别设置了相应的事件监听函数。

    ```c++
    // 错误事件发生回调函数OnError()。
    void OnError(OH_AVScreenCapture *capture, int32_t errorCode, void *userData) {
        (void)capture;
        // 应用根据错误码进行事件处理。
        (void)errorCode;
        (void)userData;
    }

    // 状态变更事件处理函数OnStateChange()。
    void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
        (void)capture;
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
            // 处理录屏开始状态变更。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_CANCELED) {
            // 处理录屏取消状态变更。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
            // 录屏被电话打断状态处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE) {
            // 录屏中途麦克风无法获取状态处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
            // 录屏被打断状态处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER) {
            // 录屏中途用户将麦克风禁音处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER) {
            // 录屏中途用户将麦克风解除禁音处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE) {
            // 录屏进入隐私状态处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE) {
            // 录屏退出隐私模式状态处理。
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
            // 录屏被用户切换打断处理。
        }
        (void)userData;
    }

    // 获取并处理音视频原始码流数据回调函数OnBufferAvailable()。
    void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
        // 处于录屏取码流状态。
        if (IsCaptureStreamRunning) {
            if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
                // 视频buffer。
                OH_NativeBuffer *nativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
                if (nativeBuffer != nullptr && capture != nullptr) {
                    // 获取buffer容量。
                    int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                    // 获取buffer属性。
                    OH_AVCodecBufferAttr info;
                    OH_AVBuffer_GetBufferAttr(buffer, &info);

                    // 获取nativeBuffer配置。
                    OH_NativeBuffer_Config config;
                    OH_NativeBuffer_GetConfig(nativeBuffer, &config);

                    // 获取buffer地址。
                    uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                    if (buf == nullptr) {
                        return;
                    }
                    // 使用buffer数据。

                    // nativeBuffer的引用计数值减一，当引用计数值减为0，释放该资源。
                    OH_NativeBuffer_Unreference(nativeBuffer);
                }
            } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
                // 内录buffer。
                // 获取buffer属性。
                OH_AVCodecBufferAttr info;
                OH_AVBuffer_GetBufferAttr(buffer, &info);

                // 获取buffer容量。
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // 获取buffer地址。
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // 使用buffer数据。
            } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
                // 麦克风buffer。
                // 获取buffer容量。
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // 获取buffer地址。
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // 使用buffer数据。
            }
        }
    }

    // 获取录屏屏幕id的回调函数OnDisplaySelected()。
    void OnDisplaySelected(struct OH_AVScreenCapture *capture, uint64_t displayId, void *userData) {
        (void)capture;
        (void)displayId;
        (void)userData;
    }

    // 录屏内容变更回调函数OnCaptureContentChanged()。
    void OnCaptureContentChanged(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect *area, void *userData) {
        (void)capture;
        if (event == OH_SCREEN_CAPTURE_CONTENT_HIDE) {
            // 处理录屏内容变为隐藏。
        }
        if (event == OH_SCREEN_CAPTURE_CONTENT_VISIBLE) {
            // 处理录屏内容变为可见。
            // 录屏内容变为可见时，可通过回调回传的area参数，获取窗口的位置信息。
        }
        if (event == OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE) {
            // 处理录屏内容变为不可用，如录屏窗口关闭。
        }
        (void)area;
        (void)userData;
    }

    // 手工确认页面用户选择结果的回调函数OnUserSelected()。
    void OnUserSelected(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData) {
        (void)capture;
        (void)userData;
        int* selectType = new int;
        uint64_t* displayId = new uint64_t;
        // 通过获取接口，拿到对应的选择类型和屏幕Id。OH_AVScreenCapture_UserSelectionInfo* selections仅在OnUserSelected回调中有效。
        OH_AVSCREEN_CAPTURE_ErrCode errorSelectType = OH_AVScreenCapture_GetCaptureTypeSelected(selections, selectType);
        OH_AVSCREEN_CAPTURE_ErrCode errorDisplayId = OH_AVScreenCapture_GetDisplayIdSelected(selections, displayId);
    }
    ```

3. 停止录屏服务并释放资源。
    ```c++
    void StopScreenCapture() {
        // 处于录屏取码流状态并且录屏服务实例存在。
        if (IsCaptureStreamRunning && capture != nullptr) {
            // 停止录屏。
            OH_AVScreenCapture_StopScreenCapture(capture);

            // 释放录屏资源。
            OH_AVScreenCapture_Release(capture);

            // 清理其他资源，如关闭文件等。

            // 录屏取码流状态置为false，录屏服务实例置空。
            IsCaptureStreamRunning = false;
            capture = nullptr;
        }
    }
    ```

## 完整示例

下面展示了使用AVScreenCapture屏幕录制的完整示例代码。

创建OH_AVBuffer，可参考[视频解码Buffer模式](../avcodec/video-decoding.md#buffer模式)。

使用Surface模式录屏，可参考[视频编码Surface模式](../avcodec/video-encoding.md#surface模式)。

目前阶段流程结束后返回的buffer为原始码流，针对原始码流可以进行编码并以mp4等文件格式保存以供播放。

> **说明：**
> 编码格式当前阶段仅作预留，待后续版本实现。

```c++
#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <multimedia/player_framework/native_avbuffer.h>
#include <native_buffer/native_buffer.h>
#include <vector>

// 错误事件发生回调函数OnError()。
void OnError(OH_AVScreenCapture *capture, int32_t errorCode, void *userData) {
    (void)capture;
    // 应用根据错误码进行事件处理。
    (void)errorCode;
    (void)userData;
}

// 状态变更事件处理函数OnStateChange()。
void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
    (void)capture;
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
        // 处理录屏开始状态变更。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_CANCELED) {
        // 处理录屏取消状态变更。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
        // 录屏被电话打断状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE) {
        // 录屏中途麦克风无法获取状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // 录屏被打断状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER) {
        // 录屏中途用户将麦克风禁音处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER) {
        // 录屏中途用户将麦克风解除禁音处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE) {
        // 录屏进入隐私状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE) {
        // 录屏退出隐私模式状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
        // 录屏被用户切换打断处理。
    }
    (void)userData;
}

// 获取并处理音视频原始码流数据回调函数OnBufferAvailable()。
bool IsCaptureStreamRunning = true;
void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
    // 处于录屏取码流状态。
    if (IsCaptureStreamRunning) {
        if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
            // 视频buffer。
            OH_NativeBuffer *nativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
            if (nativeBuffer != nullptr && capture != nullptr) {
                // 获取buffer容量。
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // 获取buffer属性。
                OH_AVCodecBufferAttr info;
                OH_AVBuffer_GetBufferAttr(buffer, &info);

                // 获取nativeBuffer配置。
                OH_NativeBuffer_Config config;
                OH_NativeBuffer_GetConfig(nativeBuffer, &config);

                // 获取buffer地址。
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // 使用buffer数据。

                // nativeBuffer的引用计数值减一，当引用计数值减为0，释放该资源。
                OH_NativeBuffer_Unreference(nativeBuffer);
            }
        } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
            // 内录buffer。
            // 获取buffer属性。
            OH_AVCodecBufferAttr info;
            OH_AVBuffer_GetBufferAttr(buffer, &info);

            // 获取buffer容量。
            int bufferLen = OH_AVBuffer_GetCapacity(buffer);

            // 获取buffer地址。
            uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
            if (buf == nullptr) {
                return;
            }
            // 使用buffer数据。
        } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
            // 麦克风buffer。
            // 获取buffer容量。
            int bufferLen = OH_AVBuffer_GetCapacity(buffer);

            // 获取buffer地址。
            uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
            if (buf == nullptr) {
                return;
            }
            // 使用buffer数据。
        }
    }
}

// 获取录屏屏幕id的回调函数OnDisplaySelected()。
void OnDisplaySelected(struct OH_AVScreenCapture *capture, uint64_t displayId, void *userData) {
    (void)capture;
    (void)displayId;
    (void)userData;
}

// 录屏内容变更回调函数OnCaptureContentChanged()。
void OnCaptureContentChanged(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect *area, void *userData) {
    (void)capture;
    if (event == OH_SCREEN_CAPTURE_CONTENT_HIDE) {
        // 处理录屏内容变为隐藏。
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_VISIBLE) {
        // 处理录屏内容变为可见。
        // 录屏内容变为可见时，可通过回调回传的area参数，获取窗口的位置信息。
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE) {
        // 处理录屏内容变为不可用，如录屏窗口关闭。
    }
    (void)area;
    (void)userData;
}

// 手工确认页面用户选择结果的回调函数OnUserSelected()。
void OnUserSelected(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData) {
    (void)capture;
    (void)userData;
    int* selectType = new int;
    uint64_t* displayId = new uint64_t;
    // 通过获取接口，拿到对应的选择类型和屏幕Id。OH_AVScreenCapture_UserSelectionInfo* selections仅在OnUserSelected回调中有效。
    OH_AVSCREEN_CAPTURE_ErrCode errorSelectType = OH_AVScreenCapture_GetCaptureTypeSelected(selections, selectType);
    OH_AVSCREEN_CAPTURE_ErrCode errorDisplayId = OH_AVScreenCapture_GetDisplayIdSelected(selections, displayId);
}

struct OH_AVScreenCapture *capture;
// 开始录屏时调用StartScreenCapture。
static napi_value StartScreenCapture(napi_env env, napi_callback_info info) {
    // 从js端获取窗口id number[]。
    std::vector<int> windowIdsExclude = {};
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    // 获取参数。
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取数组长度。
    uint32_t array_length;
    napi_get_array_length(env, args[0], &array_length);
    // 读出窗口id。
    for (uint32_t i = 0; i < array_length; i++) {
        napi_value temp;
        napi_get_element(env, args[0], i, &temp);
        uint32_t tempValue;
        napi_get_value_uint32(env, temp, &tempValue);
        windowIdsExclude.push_back(tempValue);
     }
    // 实例化ScreenCapture。
    capture = OH_AVScreenCapture_Create();
    
    // 设置回调 。
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, nullptr);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, nullptr);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, nullptr);
    // 可选 设置录屏屏幕Id回调，必须在开始录屏前调用。
    OH_AVScreenCapture_SetDisplayCallback(capture, OnDisplaySelected, nullptr);
    // 可选 设置手工确认页面用户选择结果的回调，必须在开始录屏前调用。
    OH_AVScreenCapture_SetSelectionCallback(capture, OnUserSelected, nullptr);

    // 可选，设置录屏内容变化回调。
    OH_Rect* area = nullptr;
    OH_AVScreenCapture_SetCaptureContentChangedCallback(capture, OnCaptureContentChanged, area);

    // 可选，设置隐私窗口屏蔽模式。
    int value = 0;
    OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
    OH_AVScreenCapture_StrategyForPrivacyMaskMode(strategy, value);
	// 可选，设置自动跟随旋转配置。
    OH_AVScreenCapture_StrategyForCanvasFollowRotation(strategy, true);
    OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);

    // 可选 设置光标显示开关，开始录屏前后均可调用。
    OH_AVScreenCapture_ShowCursor(capture, false);
    // 可选 配置录屏旋转，此接口在感知到手机屏幕旋转时调用，如果手机的屏幕实际上没有发生旋转，调用接口是无效的。
    OH_AVScreenCapture_SetCanvasRotation(capture, true);
    // 可选 [过滤音频]。
    OH_AVScreenCapture_ContentFilter *contentFilter= OH_AVScreenCapture_CreateContentFilter();
    // 添加过滤通知音。
    OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
    // 排除指定窗口id。
    OH_AVScreenCapture_ContentFilter_AddWindowContent(contentFilter, &windowIdsExclude[0],
                                                      static_cast<int32_t>(windowIdsExclude.size()));

    OH_AVScreenCapture_ExcludeContent(capture, contentFilter);

    // 初始化录屏，传入配置信息OH_AVScreenRecorderConfig。
    OH_AudioCaptureInfo miccapinfo = {.audioSampleRate = 16000, .audioChannels = 2, .audioSource = OH_MIC};
    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 768, .videoFrameHeight = 1280, .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA};
    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
    };
    OH_VideoInfo videoinfo = {.videoCapInfo = videocapinfo};
    OH_AVScreenCaptureConfig config = {.captureMode = OH_CAPTURE_HOME_SCREEN,
                                       .dataType = OH_ORIGINAL_STREAM,
                                       .audioInfo = audioinfo,
                                       .videoInfo = videoinfo};
    OH_AVScreenCapture_Init(capture, config);

    // 可选（API 20开始支持）：可以根据需要设置区域坐标和大小，设置想要捕获的区域，如下方创建了一个从（0，0）为起点的长100，宽100的矩形区域。此接口也可以在开始录屏以后设置。
    OH_Rect* region = new OH_Rect;
    region->x = 0;
    region->y = 0;
    region->width = 100;
    region->height = 100;
    uint64_t regionDisplayId = 0; // 传入矩形区域所在的屏幕Id。
    OH_AVScreenCapture_SetCaptureArea(capture, regionDisplayId, region);

    // 可选 [Surface模式]。
    // 通过 MIME TYPE 创建编码器，系统会根据MIME创建最合适的编码器。
    // OH_AVCodec *codec = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);    
    // 从视频编码器获取输入Surface。
    // OH_AVErrCode OH_VideoEncoder_GetSurface(codec, window);
    // 启动编码器。
    // int32_t retEnc = OH_VideoEncoder_Start(codec);
    // 指定surface开始录屏。
    // int32_t retStart = OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window); 

    // 开始录屏。
    OH_AVScreenCapture_StartScreenCapture(capture);

    // mic开关设置。
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, true);

    // 可选 豁免隐私窗口 需传递应用豁免子窗口和主窗口ID，传空数组取消豁免隐私窗口。
	// std::vector<int> windowIdsSkipPrivacy = {};
    // OH_AVScreenCapture_SkipPrivacyMode(capture, &windowIdsSkipPrivacy[0],
    //     static_cast<int32_t>(windowIdsSkipPrivacy.size()));

    // 可选 调整录屏分辨率 需在启动后调用，分辨率有范围限制 可参考avcodec编解码能力。
    // OH_AVScreenCapture_ResizeCanvas(capture, 768, 1280);

    // 可选 设置录屏时的最大帧率 需在启动后调用。
    // OH_AVScreenCapture_SetMaxVideoFrameRate(capture, 20);

    // 结束录屏见StopScreenCapture。
    
    // 返回调用结果，示例仅返回随意值。
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

// 停止录屏时调用StopScreenCapture。
static napi_value StopScreenCapture(napi_env env, napi_callback_info info) {
    if (IsCaptureStreamRunning && capture != nullptr) {
        // 停止录屏。
        OH_AVScreenCapture_StopScreenCapture(capture);

        // 释放录屏资源。
        OH_AVScreenCapture_Release(capture);

        // 清理其他资源，如关闭文件等。

        // 录屏取码流状态置为false，录屏服务实例置空。
        IsCaptureStreamRunning = false;
        capture = nullptr;
    }
    // 返回调用结果，示例仅返回随意值。
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"startScreenCapture", nullptr, StartScreenCapture, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"stopScreenCapture", nullptr, StopScreenCapture, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```