# 媒体开发常见问题
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 使用XComponent组件显示相机的预览输出流时，如何获取相机的帧数据(API 9)

**问题现象**

目前接口不支持实时预览相机的帧数据，只能绑定一个动作来获取，比如拍照动作。

**解决措施**

通过创建双路预览来实现。

1. Xcomponent来创建预览流。

   ```
   // 获取PreviewOutput(预览输出类)实例
   const surfaceId = globalThis.mxXComponentController.getXComponentSurfaceId();
   this.mPreviewOutput = await Camera.createPreviewOutput(surfaceId);
   ```

2. 使用imageReceiver来监听图像信息。

   ```
   // 添加双路预览
   const fullWidth = this.mFullScreenSize.width;
   const fullHeight = this.mFullScreenSize.height;
   const imageReceiver = await image.createImageReceiver(fullWidth, fullHeight, 
     formatImage, capacityImage);
   const photoSurfaceId = await imageReceiver.getReceivingSurfaceId();
   this.mPreviewOutputDouble = await Camera.createPreviewOutput(photoSurfaceId);
   ```


## 如何获取前置摄像头的预览图像(API 9)

**解决措施**

1. 使用系统相机框架\@ohos.multimedia.camera获取物理摄像头信息。

   ```
   let cameraManager = await camera.getCameraManager(context);
   let camerasInfo = await cameraManager.getSupportedCameras();
   let cameraDevice = camerasInfo[0];
   ```

2. 创建并启动物理摄像头输入流通道。

   ```
   let cameraInput = await cameraManager.createCameraInput(cameraDevice);
   await this.cameraInput.open();
   ```

3. 拿到物理摄像头信息查询摄像头支持预览流支持的输出格式，结合XComponent提供的surfaceId创建预览输出通道。

   ```
   let outputCapability = await this.cameraManager.getSupportedOutputCapability(cameraDevice);
   let previewProfile = outputCapability.previewProfiles[0];
   let previewOutput = await cameraManager.createPreviewOutput(previewProfile, previewId);
   ```

4. 创建相机会话，在会话中添加摄像头输入流和预览输出流，然后启动会话，预览画面就会在XComponent组件上送显。

   ```
   let captureSession = await cameraManager.createCaptureSession();
   await captureSession.beginConfig();
   await captureSession.addInput(cameraInput);
   await captureSession.addOutput(previewOutput);
   await this.captureSession.commitConfig()
   await this.captureSession.start();
   ```


## 如何设置相机焦距(API 9)

**解决措施**

1. 判断当前摄像头是否为前置摄像头，前置摄像头不支持设置焦距。

2. 通过captureSession.getZoomRatioRange()接口获取设备焦距设置支持的最大、最小范围。

3. 判断目标焦距参数大小是否在步骤二获取的范围内，然后通过captureSession.setZoomRatio()接口设置相机焦距。


## 创建多个视频组件无法播放(API 9)

**问题现象**

创建十几个视频组件无法播放甚至崩溃。

**解决措施**

当前限制最多创建13个媒体播放实例。


## 如何直接调起图片库(API 9)

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


## 如何申请设备上的媒体读写权限(API 9)

适用于Stage模型。

**解决措施**

1. 在module.json5配置文件中配置媒体读写权限ohos.permission.READ_MEDIA和ohos.permission.WRITE_MEDIA。

   示例：

   ```
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.READ_MEDIA",
           "reason": "$string:reason"
         },
         {
           "name" : "ohos.permission.WRITE_MEDIA",
           "reason": "$string:reason"
         }
       ]
     }
   }
   ```

2. 这两个权限的授权方式均为user_grant，因此需要调用requestPermissionsFromUser接口，以动态弹窗的方式向用户申请授权。

   ```
   let context = getContext(this) as common.UIAbilityContext;
   let atManager = abilityAccessCtrl.createAtManager();
   let permissions: Array<string> = ['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
   atManager.requestPermissionsFromUser(context, permissions)
   .then((data) => {
       console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
   }).catch((error) => {
       console.log("Failed to request permission from user with error: " + JSON.stringify(error))
   })
   ```


## 如何检测当前相机服务的状态(API 9)

适用于Stage模型。

**解决措施**

cameraManager通过设置状态回调返回相机状态。

```
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
  console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
  console.log(`status: ${cameraStatusInfo.status}`);
})
```

相机状态：CameraStatus

枚举，相机状态。

CAMERA_STATUS_APPEAR 0 新的相机出现。

CAMERA_STATUS_DISAPPEAR 1 相机被移除。

CAMERA_STATUS_AVAILABLE 2 相机可用。

CAMERA_STATUS_UNAVAILABLE 3 相机不可用。

参考文档：[CameraStatus](../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#oncamerastatus)

## SoundPool播放的音频是否支持wmv格式？支持哪些格式？(API 10)
**解决措施**

WMV当前是不支持，支持的格式有AAC、MPEG(MP3)、Flac、Vorbis。

**参考资料**

soundpool支持的格式与底层一致，支持的格式可以参考文档：[音频解码](../media/avcodec/audio-decoding.md)

## 如何读取相机的预览图？(API 10)

**解决措施**

使用ImageReceiver.readLatestImage可获取相机的预览图。

**参考资料**

[readLatestImage](../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md#readlatestimage9)

## 如何实现录音监听？(API 10)

**解决措施**

系统音频监听功能都在AudioStreamManager内，录音监听可以通过on(type: 'audioCapturerChange', callback: Callback\<AudioCapturerChangeInfoArray>): void订阅接口实现。

**参考资料**

[onaudiocapturerchange](../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#onaudiocapturerchange9)

## 音频处理哪些场景内置了3A处理的算法(AEC、ANC、AGC)？若内置了，有无音频3A处理的相关接口，如何调用？系统3A算法AEC、ANC、AGC是否支持独立开关？录音场景系统是否支持3A，如果不支持的话，解决方案是什么？例如：如何在播放音乐时，不影响音频录制的音质？(API 10)

**解决措施**

存在STREAM_USAGE_VOICE_COMMUNICATION配置的音频流运行时自动使能内置3A。暂未支持3A独立开关。录音场景支持3A，需要配置对应的AudioScene和SourceType类型进行使能。

**参考资料**

[AudioCapturer](../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md)

## 如何实现低时延音频采集？(API 11)

**解决措施**

支持通过OHAudio C API接口AudioCapturer使用系统低时延采集，具体实现参考：[使用OHAudio开发音频录制功能(C/C++)](../media/audio/using-ohaudio-for-recording.md)。

**参考资料**

[OHAudio](../reference/apis-audio-kit/capi-ohaudio.md)

## 如何实现实时视频流传输？如何实现直播场景？(API 10)

**解决措施**

当前版本AVPlayer支持http、https、HLS。在直播场景中，将直播地址传给Avplayer，即可进行播放对端发来的数据；当前不支持推流，即Avplayer不支持使用当前设备进行直播。

**参考资料**

1. [Media Kit](../media/media/media-kit-intro.md)
2. [AVPlayer](../media/media/using-avplayer-for-playback.md)

## 音频播放器AVPlayer如何在后台进行播放？(API 10)

**解决措施**

需要将APP配置为长时任务，并将媒体会话功能注册到系统内统一管理避免被强制停止播放。

**参考资料**

1. [长时任务](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ContinuousTask)
2. [应用接入AVSession场景介绍](../media/avsession/avsession-access-scene.md)

## 三方应用为什么无法创建相册？(API 10)

**问题描述**

相册资源读写权限设置为system_basic级别权限，且创建相册的接口设置为系统接口不对外开放，这个是开发者常用场景的能力接口，这样设计的背景和原因是什么？(API 10)

**解决措施**

出于对用户图片视频资源的隐私保护，系统权限设计上操作媒体文件要在用户知情下操作，所以不授予三方应用的直接读写权限；系统基于图片视频保存来源生成来源相册，用户自定义相册仅支持图库创建，且支持用户拖动来源相册至用户自定义相册区域。

## 如何将图片压缩至指定大小，有哪些影响因素(API 10)

**问题描述**

关于图片压缩API的质量参数quality与图片原始大小、压缩后大小，是什么关系？如何设置压缩后的图片大小？如果要把图片压缩在指定大小（如500k）以内，那么要怎么设置参数才能使无论多大的原始图片都被压缩至500k？

**解决措施**

对于有损压缩图片格式，如jpeg格式，质量参数会影响压缩后的图片大小，对于无损压缩图片格式，如png格式，质量参数不会影响压缩后的图片大小。
对于有损压缩图片格式，压缩后的图片大小不仅取决于图片原始大小、图片压缩质量，还与图片中内容有较大关系，因此当前系统不支持设置压缩后的图片大小，如果应用想要指定压缩后图片大小，可以根据压缩结果调整质量参数，或者将pixelmap scale到更小的尺寸后再压缩。

**参考资料**

1. [scale](../reference/apis-image-kit/arkts-apis-image-PixelMap.md#scale9)
2. [packing](../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packing13)
