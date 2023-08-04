# 媒体开发常见问题

## 使用XComponent组件显示相机的预览输出流时，如何获取相机的帧数据

适用于：OpenHarmony 3.2 版本  API 9 Stage模型

**问题现象**

目前接口不支持实时预览相机的帧数据，只能绑定一个动作来获取，比如拍照动作。

**解决措施**

通过创建双路预览来实现。

1.  Xcomponent来创建预览流。

    ```
    // 获取PreviewOutput(预览输出类)实例
    const surfaceId = globalThis.mxXComponentController.getXComponentSurfaceld();
    this.mPreviewOutput = await Camera.createPreviewOutput(surfaceld) ;
    ```

2.  使用imageReceiver来监听图像信息。

    ```
    // 添加双路预览
    const fullWidth = this.mFullScreenSize.width;
    const fullHeight = this.mFullScreenSize.height;
    const imageReceiver = await image.createImageReceiver(fullwidth, fullHeight, 
      formatImage, capacityImage) ;
    const photoSurfaceId = await imageReceiver.getReceivingSurfaceld();
    this.mPreviewOutputDouble = await Camera.createPreviewOutput ( photoSurfaceld)
    ```


## 如何获取前置摄像头的预览图像

适用于：OpenHarmony 3.2版本  API 9 Stage模型

**解决措施**

1.  使用系统相机框架@ohos.multimedia.camera获取物理摄像头信息。

    ```
    let cameraManager = await camera.getCameraManager(context);
    let camerasInfo = await cameraManager.getSupportedCameras();
    let cameraDevice = this.camerasInfo[0];
    ```

2.  创建并启动物理摄像头输入流通道。

    ```
    let cameraInput = await cameraManager.createCameraInput(cameraDevice);
    await this.cameraInput.open();
    ```

3.  拿到物理摄像头信息查询摄像头支持预览流支持的输出格式，结合XComponent提供的surfaceId创建预览输出通道。

    ```
    let outputCapability = await this.cameraManager.getSupportedOutputCapability(cameraDevice);
    let previewProfile = this.outputCapability.previewProfiles[0];
    let previewOutput = await cameraManager.createPreviewOutput(previewProfile, previewId);
    ```

4.  创建相机会话，在会话中添加摄像头输入流和预览输出流，然后启动会话，预览画面就会在XComponent组件上送显。

    ```
    let captureSession = await cameraManager.createCaptureSession();
    await captureSession.beginConfig();
    await captureSession.addInput(cameraInput);
    await captureSession.addOutput(previewOutput);
    await this.captureSession.commitConfig()
    await this.captureSession.start();
    ```


## 如何设置相机焦距

适用于：OpenHarmony 3.2版本  API 9 Stage模型

**解决措施**

1.  判断当前摄像头是否为前置摄像头，前置摄像头不支持设置焦距。
2.  通过captureSession.getZoomRatioRange\(\)接口获取设备焦距设置支持的最大、最小范围。
3.  判断目标焦距参数大小是否在步骤二获取的范围内，然后通过captureSession.setZoomRatio\(\)接口设置相机焦距。

## 如何后台播放音乐

适用于：OpenHarmony 3.2版本  API 9 Stage模型

**问题现象**

无法后台播放音乐。

**解决措施**

AVSession对媒体播放做了管控，当三方应用从前台切入后台或者进入锁屏状态，媒体播放会被强制暂停而应用不感知，如果要开发后台播放功能，应该启动后台任务管理的长时任务中播放音乐，同时接入AVSession能力，允许控制中心的播控面板控制三方应用的播放功能。

**参考链接**

[后台任务管理的长时任务开发指导参考](../task-management/continuous-task.md)

[AVSession开发指导参考](../media/using-avsession-developer.md)


## 创建多个视频组件无法播放

适用于：OpenHarmony 3.2版本 API 9 Stage模型

**问题现象**

创建十几个视频组件无法播放甚至崩溃。

**解决措施**

当前限制最多创建13个媒体播放实例。


## 如何直接调起图片库

适用于：OpenHarmony 3.2版本   API 9 Stage模型

**解决措施**

```
let want = {
  bundleName: 'com.ohos.photos',
  abilityName: 'com.ohos.photos.MainAbility',
  parameters: {
 uri: 'detail'
  }
};
let context = getContext(this) as common.UIAbilityContext;
context.startAbility(want);
```

