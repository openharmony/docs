# 相机开发指导

## 场景介绍

相机模块支持相机相关基础功能的开发，主要包括预览、拍照、录像等。本文将对相机各种基础功能的开发进行介绍说明。

## 开发步骤

### 接口说明

详细API含义请参考：[相机管理API文档](../reference/apis/js-apis-camera.md)

### 全流程场景

包含流程：创建实例、参数设置、会话管理、拍照、录像、释放资源等。

Xcomponent创建方法可参考：[XComponent创建方法](#xcomponent创建方法)

拍照保存接口可参考：[图片处理API文档](../reference/apis/js-apis-image.md)

#### 创建实例

```js
import camera from '@ohos.multimedia.camera'
import image from '@ohos.multimedia.image'
import media from '@ohos.multimedia.media'
import featureAbility from '@ohos.ability.featureAbility'

//创建CameraManager对象
let cameraManager
await camera.getCameraManager(globalThis.Context, (err, manager) => {
    if (err) {
        console.error('Failed to get the CameraManager instance ${err.message}');
        return;
    }
    console.log('Callback returned with the CameraManager instance');
    cameraManager = manager
})

//注册回调函数监听相机状态变化，获取状态变化的相机信息
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})

//获取相机列表
let cameraArray
await cameraManager.getCameras((err, cameras) => {
    if (err) {
        console.error('Failed to get the cameras. ${err.message}');
        return;
    }
    console.log('Callback returned with an array of supported cameras: ' + cameras.length);
    cameraArray = cameras
})

 for(let cameraIndex = 0; cameraIndex < cameraArray.length; cameraIndex) {
     console.log('cameraId : ' + cameraArray[cameraIndex].cameraId)                          //获取相机ID
     console.log('cameraPosition : ' + cameraArray[cameraIndex].cameraPosition)              //获取相机位置
     console.log('cameraType : ' + cameraArray[cameraIndex].cameraType)                      //获取相机类型
     console.log('connectionType : ' + cameraArray[cameraIndex].connectionType)              //获取相机连接类型
 }

 //创建相机输入流
 let cameraInput
 await cameraManager.createCameraInput(cameraArray[0].cameraId).then((input) => {
    console.log('Promise returned with the CameraInput instance');
    cameraInput = input
})

//创建预览输出流
let previewOutput
camera.createPreviewOutput((globalThis.surfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with previewOutput instance');
    previewOutput = output
});

//创建ImageReceiver对象，并设置照片参数
let imageReceiver = await image.createImageReceiver(1920, 1080, 4, 8)
//获取照片显示SurfaceId
let photoSurfaceId = await imageReceiver.getReceivingSurfaceId()
//创建拍照输出流
let photoOutput
camera.createPhotoOutput((photoSurfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the PhotoOutput instance.');
    photoOutput = output
});

//创建视频录制的参数
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
    videoFrameWidth : 640,
    videoFrameHeight : 480,
    videoFrameRate : 30
}
let videoConfig = {
    audioSourceType : 1,
    videoSourceType : 0,
    profile : videoProfile,
    url : 'file:///data/media/01.mp4',
    orientationHint : 0,
    location : { latitude : 30, longitude : 130 },
}

//创建录像输出流
let videoRecorder
await media.createVideoRecorder().then((recorder) => {
    console.log('createVideoRecorder called')
    videoRecorder = recorder
})
//设置视频录制的参数
await videoRecorder.prepare(videoConfig)
//获取录像SurfaceId
await videoRecorder.getInputSurface().then((id) => {
    console.log('getInputSurface called')
    videoSurfaceId = id
})
```
videoRecorder详细创建方法可参考：[视频录制开发指导](./video-recorder.md)
```js
//创建VideoOutput对象
let videoOutput
camera.createVideoOutput((surfaceId), (err, output) => {
    if (err) {
        console.error('Failed to create the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the VideoOutput instance');
    videoOutput = output
});

```

#### 参数设置

```js
//判断设备是否支持闪光灯
let flashStatus
await cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
    flashStatus = status
})
if(flashStatus) {
    //判断是否支持自动闪光灯模式
    let flashModeStatus
    cameraInput.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO, (err, status) => {
        if (err) {
            console.error('Failed to check whether the flash mode is supported. ${err.message}');
            return;
        }
        console.log('Callback returned with the flash mode support status: ' + status);
        flashModeStatus = status
    })
    if(flashModeStatus) {
        //设置自动闪光灯模式
        cameraInput.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO, (err) => {
            if (err) {
                console.error('Failed to set the flash mode  ${err.message}');
                return;
            }
            console.log('Callback returned with the successful execution of setFlashMode.');
        })
    }
}

//判断是否支持连续自动变焦模式
let focusModeStatus
cameraInput.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO, (err, status) => {
    if (err) {
        console.error('Failed to check whether the focus mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the focus mode support status: ' + status);
    focusModeStatus = status
})
if(focusModeStatus) {
    //设置连续自动变焦模式
    cameraInput.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO, (err) => {
        if (err) {
            console.error('Failed to set the focus mode  ${err.message}');
            return;
        }
        console.log('Callback returned with the successful execution of setFocusMode.');
    })
}

//获取相机支持的可变焦距比范围
let zoomRatioRange
cameraInput.getZoomRatioRange((err, range) => {
    if (err) {
        console.error('Failed to get the zoom ratio range. ${err.message}');
        return;
    }
    console.log('Callback returned with zoom ratio range: ' + range.length);
    zoomRatioRange = range
})

//设置可变焦距比
cameraInput.setZoomRatio(zoomRatioRange[0], (err) => {
    if (err) {
        console.error('Failed to set the zoom ratio value ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setZoomRatio.');
})
```

#### 会话管理

##### 创建会话

```js
//创建Context对象
let context = featureAbility.getContext()

//创建会话
let captureSession
await camera.createCaptureSession((context), (err, session) => {
    if (err) {
        console.error('Failed to create the CaptureSession instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CaptureSession instance.' + session);
    captureSession = session
});

//开始配置会话
await captureSession.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});

//向会话中添加相机输入流
await captureSession.addInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to add the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is added.');
});

//向会话中添加预览输入流
await captureSession.addOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to add the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is added.');
});

//向会话中添加拍照输出流
await captureSession.addOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to add the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is added.');
});

//提交会话配置
await captureSession.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});

//启动会话
await captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

##### 切换会话

```js
//停止当前会话
await captureSession.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});

//开始配置会话
await captureSession.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});

//从会话中移除拍照输出流
await captureSession.removeOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is removed.');
});

//向会话中添加录像输出流
await captureSession.addOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to add the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is added.');
});

//提交会话配置
await captureSession.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});

//启动会话
await captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

#### 拍照

```js
let settings = {
    quality: camera.QualityLevel.QUALITY_LEVEL_HIGH                                      //设置图片质量高
    rotation: camera.ImageRotation.ROTATION_0,                                           //设置图片旋转角度0
}
//使用当前拍照设置进行拍照
photoOutput.capture(settings, (err) => {
    if (err) {
        console.error('Failed to capture the photo ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

#### 录像

```js
//启动录像输出流
videoOutput.start((err) => {
    if (err) {
        console.error('Failed to start the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output start success.');
});

//开始录像
await videoRecorder.start().then(() => {
    console.info('videoRecorder start success');
}

//停止录像
await videoRecorder.stop().then(() => {
    console.info('stop success');
}

//停止录像输出流
await videoOutput.stop((err) => {
    if (err) {
        console.error('Failed to stop the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
});
```

#### 释放资源

```js
//停止当前会话
await captureSession.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});
//释放相机输入流
await cameraInput.release((err) => {
    if (err) {
        console.error('Failed to release the CameraInput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is released successfully.');
});
//释放预览输出流
await previewOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
//释放拍照输出流
await photoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is released successfully.');
});
//释放录像输出流
await videoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is released successfully.');
});
//释放会话
await captureSession.release((err) => {
    if (err) {
        console.error('Failed to release the CaptureSession instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
});
```

#### XComponent创建方法
预览画面显示需要获取SurfaceId

```js
mXComponentController: XComponentController = new XComponentController                   //创建XComponentController

build() {
    Flex() {
        XComponent({                                                                     //创建XComponent
            id: '',
            type: 'surface',
            libraryname: '',
            controller: this.mXComponentController
        })
        .onload(() => {                                                                  //设置onload回调
            //设置Surface宽高（1920*1080）
            this.mXComponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080})
            //获取Surface ID
            globalThis.surfaceId = mXComponentController.getXComponentSurfaceId()
        })
        .width('1920px')                                                                 //设置XComponent宽度
        .height('1080px')                                                                //设置XComponent高度
    }
}
```