# 预览(Native)

预览是启动相机后看见的画面，通常在拍照和录像前执行。

## 开发步骤

详细的API说明请参考[Camera API参考]。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```c++
    // 导入NDK接口头文件 （参考ndk demo：在camera_manager.cpp中调用）
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

2. 在CMake脚本中链接Camera NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

3. 创建Surface。
     
    XComponent组件为预览流提供的Surface，而XComponent的能力由UI提供，相关介绍可参考XComponent组件参考。

    **注**：预览流与录像输出流的分辨率的宽高比要保持一致，如示例代码中宽高比为1920:1080 = 16:9，则需要预览流中的分辨率的宽高比也为16:9，如分辨率选择640:360，或960:540，或1920:1080，以此类推

   ```ts
    // 获取 previewSurfaceId （参考ndk demo：在tableIndex.ets中调用）
    // 创建XComponentController 
    @Component
    struct XComponentPage {
      // 创建XComponentController
      mXComponentController: XComponentController = new XComponentController;
      previewSurfaceId: string = '';

      build() {
        Flex() {
          // 创建XComponent
          XComponent({
            id: '',
            type: 'surface',
            libraryname: '',
            controller: this.mXComponentController
          })
            .onLoad(() => {
              // 获取Surface ID
              this.previewSurfaceId = this.mXComponentController.getXComponentSurfaceId();
            })
            .width('100%')
            .height('100%')
        }
      }
    }
   ```

4. 通过OH_CameraManager_GetSupportedCameraOutputCapability方法获取当前设备支持的预览能力。通过OH_CameraManager_CreatePreviewOutput方法创建预览输出流，其中，OH_CameraManager_CreatePreviewOutput方法中的参数分别是cameraManager指针，previewProfiles数组中的第一项，步骤二中获取的surfaceId，以及返回的previewOutput指针
     
   ```c++
    ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
    if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
    }
   ```

5. 使能。通过start()方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode]。
     
   ```c++
    ret = OH_PreviewOutput_Start(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Start failed.");
    }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。
    
  ```c++
    void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
    }
    PreviewOutput_Callbacks* GetPreviewOutputListener(void)
    {
        static PreviewOutput_Callbacks previewOutputListener = {
            .onFrameStart = PreviewOutputOnFrameStart,
            .onFrameEnd = PreviewOutputOnFrameEnd,
            .onError = PreviewOutputOnError
        };
        return &previewOutputListener;
    }
    ret = OH_PreviewOutput_RegisterCallback(previewOutput_, GetPreviewOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
    }
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```c++
    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode]。
    
  ```c++
    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
    }
  ```

## 相关实例

针对预览(Native)，有以下相关实例可供参考：
- [预览(Native)](https://gitee.com/openharmony/multimedia_camera_framework/tree/master/frameworks/native/camera/test/ndktest/camera_ndk_demo)