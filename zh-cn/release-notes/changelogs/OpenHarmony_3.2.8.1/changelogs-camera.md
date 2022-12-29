# 媒体子系统JS API变更Changelog

OpenHarmony3.2 Beta4版本相较于OpenHarmony3.2 Beta3版本，媒体子系统camera部件API变更如下

## camera接口变更
基于以下原因新增部分功能接口以及废弃部分接口：
1. 提升开发者使用相机接口的便利。
2. 帮助开发者快速掌握相机开发接口，快速投入到开发当中。
3. 易于后续版本中框架功能的扩展，降低框架模块之间的耦合度。

具体参考下方变更内容，开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                 | 类名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ---------------------- | ----------------------- | ------------------------------------------------------------ | -------- |
| ohos.multimedia.camera | Profile                 | readonly format:CameraFormat;                                | 新增     |
| ohos.multimedia.camera | Profile                 | readonly size: Size;                                         | 新增     |
| ohos.multimedia.camera | FrameRateRange          | readonly min: number;                                        | 新增     |
| ohos.multimedia.camera | FrameRateRange          | readonly max: number;                                        | 新增     |
| ohos.multimedia.camera | VideoProfile            | readonly frameRateRange: FrameRateRange;                     | 新增     |
| ohos.multimedia.camera | CameraOutputCapability  | readonly previewProfiles: Array<Profile>;                    | 新增     |
| ohos.multimedia.camera | CameraOutputCapability  | readonly photoProfiles: Array<Profile>;                      | 新增     |
| ohos.multimedia.camera | CameraOutputCapability  | readonly videoProfiles: Array<VideoProfile>;                 | 新增     |
| ohos.multimedia.camera | CameraOutputCapability  | readonly supportedMetadataObjectTypes: Array<MetadataObjectType>; | 新增     |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void;<br/>getSupportedCameras(): Promise<Array<CameraDevice>>; | 新增     |
| ohos.multimedia.camera | CameraManager           | getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;<br/>getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>; | 新增     |
| ohos.multimedia.camera | CameraManager           | isCameraMuted(): boolean;                                    | 新增     |
| ohos.multimedia.camera | CameraManager           | isCameraMuteSupported(): boolean;                            | 新增     |
| ohos.multimedia.camera | CameraManager           | muteCamera(mute: boolean): void;                             | 新增     |
| ohos.multimedia.camera | CameraManager           | createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;<br/>createCameraInput(camera: CameraDevice): Promise<CameraInput>; | 新增     |
| ohos.multimedia.camera | CameraManager           | createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br/>createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>; | 新增     |
| ohos.multimedia.camera | CameraManager           | createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br/>createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>; | 新增     |
| ohos.multimedia.camera | CameraManager           | createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br/>createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>; | 新增     |
| ohos.multimedia.camera | CameraManager           | createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;<br/>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>; | 新增     |
| ohos.multimedia.camera | CameraManager           | createCaptureSession(callback: AsyncCallback<CaptureSession>): void;<br/>createCaptureSession(): Promise<CaptureSession>; | 新增     |
| ohos.multimedia.camera | CameraManager           | on(type: 'cameraMute', callback: AsyncCallback<boolean>): void; | 新增     |
| ohos.multimedia.camera | CameraManager           | getCameras(callback: AsyncCallback<Array<Camera>>): void;<br/>getCameras(): Promise<Array<Camera>>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput>): void;<br/>createCameraInput(cameraId: string): Promise<CameraInput>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | createCaptureSession(context: Context, callback: AsyncCallback<CaptureSession>): void;<br/>createCaptureSession(context: Context): Promise<CaptureSession>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br/>createPreviewOutput(surfaceId: string): Promise<PreviewOutput>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | CreatePhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br/>CreatePhotoOutput(surfaceId: string): Promise<PhotoOutput>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br/>createVideoOutput(surfaceId: string): Promise<VideoOutput>; | 废弃     |
| ohos.multimedia.camera | CameraManager           | createMetadataOutput(callback: AsyncCallback<MetadataOutput>): void;<br/>createVideoOutput(): Promise<MetadataOutput>; | 废弃     |
| ohos.multimedia.camera | CameraStatusInfo        | camera: CameraDevice;                                        | 新增     |
| ohos.multimedia.camera | CameraStatusInfo        | camera: Camera;                                              | 废弃     |
| ohos.multimedia.camera | CameraDevice            | interface CameraDevice                                       | 新增     |
| ohos.multimedia.camera | Camera                  | interface Camera                                             | 废弃     |
| ohos.multimedia.camera | CameraInput             | open(callback: AsyncCallback<void>): void;<br/>open(): Promise<void>; | 新增     |
| ohos.multimedia.camera | CameraInput             | close(callback: AsyncCallback<void>): void;<br/>close(): Promise<void>; | 新增     |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void; | 新增     |
| ohos.multimedia.camera | CameraInput             | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br/>isFocusModeSupported(afMode: FocusMode): Promise<boolean>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br/>getFocusMode(): Promise<FocusMode>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br/>setFocusMode(afMode: FocusMode): Promise<void>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br/>getZoomRatioRange(): Promise<Array<number>>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | getZoomRatio(callback: AsyncCallback<number>): void;<br/>getZoomRatio(): Promise<number>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br/>setZoomRatio(zoomRatio: number): Promise<void>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | getCameraId(callback: AsyncCallback<string>): void;<br/>getCameraId(): Promise<string>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | getExposurePoint(callback: AsyncCallback<Point>): void;<br/>getExposurePoint(): Promise<Point>; | 废弃     |
| ohos.multimedia.camera | CameraInput             | setExposurePoint(exposurePoint: Point, callback: AsyncCallback<void>): void;<br/>setExposurePoint(exposurePoint: Point): Promise<void>; | 废弃     |
| ohos.multimedia.camera | CameraInput          | hasFlash(callback: AsyncCallback<boolean>): void;<br/>hasFlash(): Promise<boolean>;                                                                         | 废弃     |
| ohos.multimedia.camera | CameraInput          | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br/>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;       | 废弃     |
| ohos.multimedia.camera | CameraInput          | getFlashMode(callback: AsyncCallback<FlashMode>): void;<br/>getFlashMode(): Promise<FlashMode>;                                                             | 废弃     |
| ohos.multimedia.camera | CameraInput          | setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br/>setFlashMode(flashMode: FlashMode): Promise<void>;                             | 废弃     |
| ohos.multimedia.camera | CameraInput          | isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br/>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>; | 废弃     |
| ohos.multimedia.camera | CameraInput          | getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br/>getExposureMode(): Promise<ExposureMode>;                                                 | 废弃     |
| ohos.multimedia.camera | CameraInput          | setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br/>setExposureMode(aeMode: ExposureMode): Promise<void>;                       | 废弃     |
| ohos.multimedia.camera | CameraInput          | getMeteringPoint(callback: AsyncCallback<Point>): void;<br/>getMeteringPoint(): Promise<Point>;                                                             | 废弃     |
| ohos.multimedia.camera | CameraInput          | setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setMeteringPoint(point: Point): Promise<void>;                                     | 废弃     |
| ohos.multimedia.camera | CameraInput          | getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br/>getExposureBiasRange(): Promise<Array<number>>;                                     | 废弃     |
| ohos.multimedia.camera | CameraInput          | setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br/>setExposureBias(exposureBias: number): Promise<void>;                       | 废弃     |
| ohos.multimedia.camera | CameraInput          | getExposureValue(callback: AsyncCallback<number>): void;<br/>getExposureValue(): Promise<number>;                                                           | 废弃     |
| ohos.multimedia.camera | CameraInput          | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br/>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;             | 废弃     |
| ohos.multimedia.camera | CameraInput          | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br/>getFocusMode(): Promise<FocusMode>;                                                             | 废弃     |
| ohos.multimedia.camera | CameraInput          | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br/>setFocusMode(afMode: FocusMode): Promise<void>;                                   | 废弃     |
| ohos.multimedia.camera | CameraInput          | setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setFocusPoint(point: Point): Promise<void>;                                           | 废弃     |
| ohos.multimedia.camera | CameraInput          | getFocusPoint(callback: AsyncCallback<Point>): void;<br/>getFocusPoint(): Promise<Point>;                                                                   | 废弃     |
| ohos.multimedia.camera | CameraInput          | getFocalLength(callback: AsyncCallback<number>): void;<br/>getFocalLength(): Promise<number>;                                                               | 废弃     |
| ohos.multimedia.camera | CameraInput          | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br/>getZoomRatioRange(): Promise<Array<number>>;                                           | 废弃     |
| ohos.multimedia.camera | CameraInput          | getZoomRatio(callback: AsyncCallback<number>): void;<br/>getZoomRatio(): Promise<number>;                                                                   | 废弃     |
| ohos.multimedia.camera | CameraInput          | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br/>setZoomRatio(zoomRatio: number): Promise<void>;                                   | 废弃     |
| ohos.multimedia.camera | CameraInput             | on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void; | 废弃     |
| ohos.multimedia.camera | CameraInput             | on(type: 'exposureStateChange', callback: AsyncCallback<ExposureState>): void; | 废弃     |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', callback: ErrorCallback<CameraInputError>): void; | 废弃     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_NO_PERMISSION = 0                                      | 新增     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_PREEMPTED = 1                                   | 新增     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_DISCONNECTED = 2                                | 新增     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_IN_USE = 3                                      | 新增     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DRIVER_ERROR = 4                                       | 新增     |
| ohos.multimedia.camera | CameraFormat            | CAMERA_FORMAT_RGBA_8888 = 3                                  | 新增     |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_AUTO = 1                                       | 新增     |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_CONTINUOUS_AUTO = 2                            | 新增     |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_AUTO                                      | 废弃     |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_CONTINUOUS_AUTO                          | 废弃     |
| ohos.multimedia.camera | VideoStabilizationMode  | LOW = 1                                                      | 新增     |
| ohos.multimedia.camera | VideoStabilizationMode  | MIDDLE = 2                                                   | 新增     |
| ohos.multimedia.camera | VideoStabilizationMode  | HIGH = 3                                                     | 新增     |
| ohos.multimedia.camera | VideoStabilizationMode  | AUTO = 4                                                     | 新增     |
| ohos.multimedia.camera | VideoStabilizationMode  | LOW                                                    | 废弃     |
| ohos.multimedia.camera | VideoStabilizationMode  | MIDDLE                                                 | 废弃     |
| ohos.multimedia.camera | VideoStabilizationMode  | HIGH                                                     | 废弃     |
| ohos.multimedia.camera | VideoStabilizationMode  | AUTO                                                     | 废弃     |
| ohos.multimedia.camera | CaptureSession          | addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>addOutput(cameraOutput: CameraOutput): Promise<void>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(cameraOutput: CameraOutput): Promise<void>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void;<br/>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void;<br/>getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void;<br/>setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void; | 新增     |
| ohos.multimedia.camera | CaptureSession          | hasFlash(callback: AsyncCallback<boolean>): void;<br/>hasFlash(): Promise<boolean>;                                                                         | 新增     |
| ohos.multimedia.camera | CaptureSession          | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br/>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;       | 新增     |
| ohos.multimedia.camera | CaptureSession          | getFlashMode(callback: AsyncCallback<FlashMode>): void;<br/>getFlashMode(): Promise<FlashMode>;                                                             | 新增     |
| ohos.multimedia.camera | CaptureSession          | setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br/>setFlashMode(flashMode: FlashMode): Promise<void>;                             | 新增     |
| ohos.multimedia.camera | CaptureSession          | isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br/>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>; | 新增     |
| ohos.multimedia.camera | CaptureSession          | getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br/>getExposureMode(): Promise<ExposureMode>;                                                 | 新增     |
| ohos.multimedia.camera | CaptureSession          | setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br/>setExposureMode(aeMode: ExposureMode): Promise<void>;                       | 新增     |
| ohos.multimedia.camera | CaptureSession          | getMeteringPoint(callback: AsyncCallback<Point>): void;<br/>getMeteringPoint(): Promise<Point>;                                                             | 新增     |
| ohos.multimedia.camera | CaptureSession          | setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setMeteringPoint(point: Point): Promise<void>;                                     | 新增     |
| ohos.multimedia.camera | CaptureSession          | getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br/>getExposureBiasRange(): Promise<Array<number>>;                                     | 新增     |
| ohos.multimedia.camera | CaptureSession          | setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br/>setExposureBias(exposureBias: number): Promise<void>;                       | 新增     |
| ohos.multimedia.camera | CaptureSession          | getExposureValue(callback: AsyncCallback<number>): void;<br/>getExposureValue(): Promise<number>;                                                           | 新增     |
| ohos.multimedia.camera | CaptureSession          | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br/>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;             | 新增     |
| ohos.multimedia.camera | CaptureSession          | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br/>getFocusMode(): Promise<FocusMode>;                                                             | 新增     |
| ohos.multimedia.camera | CaptureSession          | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br/>setFocusMode(afMode: FocusMode): Promise<void>;                                   | 新增     |
| ohos.multimedia.camera | CaptureSession          | setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setFocusPoint(point: Point): Promise<void>;                                           | 新增     |
| ohos.multimedia.camera | CaptureSession          | getFocusPoint(callback: AsyncCallback<Point>): void;<br/>getFocusPoint(): Promise<Point>;                                                                   | 新增     |
| ohos.multimedia.camera | CaptureSession          | getFocalLength(callback: AsyncCallback<number>): void;<br/>getFocalLength(): Promise<number>;                                                               | 新增     |
| ohos.multimedia.camera | CaptureSession          | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br/>getZoomRatioRange(): Promise<Array<number>>;                                           | 新增     |
| ohos.multimedia.camera | CaptureSession          | getZoomRatio(callback: AsyncCallback<number>): void;<br/>getZoomRatio(): Promise<number>;                                                                   | 新增     |
| ohos.multimedia.camera | CaptureSession          | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br/>setZoomRatio(zoomRatio: number): Promise<void>;                                   | 新增     |
| ohos.multimedia.camera | CaptureSession          | addOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br/>addOutput(previewOutput: PreviewOutput): Promise<void>;<br/>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br/>addOutput(photoOutput: PhotoOutput): Promise<void>;<br/>addOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br/>addOutput(videoOutput: VideoOutput): Promise<void>; | 废弃     |
| ohos.multimedia.camera | CaptureSession          | removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(previewOutput: PreviewOutput): Promise<void>;<br/>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(photoOutput: PhotoOutput): Promise<void>;removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(videoOutput: VideoOutput): Promise<void>;<br/>removeOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(metadataOutput: MetadataOutput): Promise<void>; | 废弃     |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_INSUFFICIENT_RESOURCES = 0                             | 新增     |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_TIMEOUT = 1                                            | 新增     |
| ohos.multimedia.camera | CameraOutput            | release(callback: AsyncCallback<void>): void;<br/>release(): Promise<void>; | 新增     |
| ohos.multimedia.camera | PreviewOutput           | start(callback: AsyncCallback<void>): void;<br/>start(): Promise<void>; | 新增     |
| ohos.multimedia.camera | PreviewOutput           | stop(callback: AsyncCallback<void>): void;<br/>stop(): Promise<void>; | 新增     |
| ohos.multimedia.camera | PreviewOutput           | release(callback: AsyncCallback<void>): void;<br/>release(): Promise<void>; | 废弃     |
| ohos.multimedia.camera | PhotoOutput             | release(callback: AsyncCallback<void>): void;<br/>release(): Promise<void>; | 废弃     |
| ohos.multimedia.camera | VideoOutput             | release(callback: AsyncCallback<void>): void;<br/>release(): Promise<void>; | 废弃     |
| ohos.multimedia.camera | PhotoCaptureSetting     | mirror?: boolean;                                            | 新增     |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_DRIVER_ERROR = 0                                       | 新增     |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_INSUFFICIENT_RESOURCES = 1                             | 新增     |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_TIMEOUT = 2                                            | 新增     |
| ohos.multimedia.camera | VideoOutputErrorCode    | ERROR_DRIVER_ERROR = 0                                       | 新增     |
| ohos.multimedia.camera | MetadataObjectType      | FACE_DETECTION = 0                                           | 新增     |
| ohos.multimedia.camera | MetadataObjectType      | FACE = 0                                                 | 废弃     |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void; | 新增     |
| ohos.multimedia.camera | MetadataOutput      | setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<void>): void;<br/>setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>): Promise<void>;    | 废弃     |
| ohos.multimedia.camera | MetadataOutput      | getSupportedMetadataObjectTypes(callback: AsyncCallback<Array<MetadataObjectType>>): void;<br/>getSupportedMetadataObjectTypes(): Promise<Array<MetadataObjectType>>;    | 废弃     |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_UNKNOWN = -1                                           | 新增     |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_INSUFFICIENT_RESOURCES = 0                             | 新增     |
| ohos.multimedia.camera | MetadataOutputError     | code: MetadataOutputErrorCode;                              | 新增     |

**适配指导**

除新增接口，和废弃接口之外，开发者需要关注变更的接口的适配：

从Beta4版本开始，对以下接口进行调整：

**新增接口**

1. Profile接口

   属性1：readonly format，类型：CameraFormat;

   属性2：readonly size，类型：Size;

2. FrameRateRange接口

   属性1：readonly min，类型：number;

   属性2：readonly max，类型：number;

3. VideoProfile接口，继承自Profile

   属性：readonly frameRateRange，类型：FrameRateRange;

4. CameraOutputCapability接口

   属性1：readonly previewProfiles，类型：Array<Profile>;

   属性2：readonly photoProfiles，类型：Array<Profile>;

   属性3：readonly videoProfiles，类型：Array<VideoProfile>;

   属性4：readonly supportedMetadataObjectTypes，类型：Array<MetadataObjectType>;

5. CameraManager中新增

   getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;

   getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>;

   参考代码如下：

   ```
   cameraManager.getSupportedCameras().then((cameras) => {
       let cameraDevice = cameras[0];
       cameraManager.getSupportedOutputCapability(cameraDevice, (err, CameraOutputCapability) => {
           if (err) {
               console.error(`Failed to get the outputCapability. ${err.message}`);
               return;
           }
           console.log('Callback returned with an array of supported outputCapability');
       })
   })
   ```

   ```
   cameraManager.getSupportedCameras().then((cameras) => {
       let cameraDevice = cameras[0];
       cameraManager.getSupportedOutputCapability(cameraDevice).then((cameraoutputcapability) => {
           console.log('Promise returned with an array of supported outputCapability');
       })
   })
   ```

6. CameraManager中新增isCameraMuted(): boolean; 

   参考代码如下：

   ```
   let ismuted = cameraManager.isCameraMuted();
   ```

7. CameraManager中新增isCameraMuteSupported(): boolean; 

   参考代码如下：

   ```
   let ismutesuppotred = cameraManager.isCameraMuteSupported();
   ```

8. CameraManager中新增muteCamera(mute: boolean): void;

   参考代码如下：

   ```
   let mute = true;
   cameraManager.muteCamera(mute);
   ```

9. CameraManager中新增on(type: 'cameraMute', callback: AsyncCallback<boolean>): void;

   参考代码如下：

   ```
   cameraManager.on('cameraMute', (err, curMuetd) => {
       if (err) {
           console.error(`Failed to get cameraMute callback. ${err.message}`);
           return;
       }
   })
   ```

10. CameraInput中新增open(callback: AsyncCallback<void>): void;以及open(): Promise<void>;

参考代码如下：

```
cameraInput.open((err) => {
    if (err) {
        console.error(`Failed to open the camera. ${err.message}`);
        return;
    }
    console.log('Callback returned with camera opened.');
})
```

```
cameraInput.open().then(() => {
    console.log('Promise returned with camera opened.');
})
```

11. CameraInput中新增close(callback: AsyncCallback<void>): void;以及close(): Promise<void>;

    参考代码如下：

    ```
    cameraInput.close((err) => {
        if (err) {
            console.error(`Failed to close the cameras. ${err.message}`);
            return;
        }
        console.log('Callback returned with camera closed.');
    })
    ```

    ```
    cameraInput.close().then(() => {
        console.log('Promise returned with camera closed.');
    })
    ```

12. 枚举CameraInputErrorCode中新增

    枚举值名称：ERROR_NO_PERMISSION，值：0;

    枚举值名称：ERROR_DEVICE_PREEMPTED，值：1;

    枚举值名称：ERROR_DEVICE_DISCONNECTED，值：2;

    枚举值名称：ERROR_DEVICE_IN_USE，值：3;

    枚举值名称：ERROR_DRIVER_ERROR，值：4;

13. 枚举CameraFormat中新增

    枚举值名称：CAMERA_FORMAT_RGBA_8888，值：3;

14. CaptureSession中新增getMeteringPoint(callback: AsyncCallback<Point>): void;以及getMeteringPoint(): Promise<Point>;

    参考代码如下：

    ```
    captureSession.getMeteringPoint((err, exposurePoint) => {
        if (err) {
            console.log(`Failed to get the current exposure point ${err.message}`);
            return ;
        }
        console.log(`Callback returned with current exposure point: ${exposurePoint}`);
    })
    ```

    ```
    captureSession.getMeteringPoint().then((exposurePoint) => {
        console.log(`Promise returned with current exposure point : ${exposurePoint}`);
    })
    ```

15. CaptureSession中新增setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;以及setMeteringPoint(point: Point): Promise<void>;

    参考代码如下：

    ```
    const Point1 = {x: 1, y: 1};
    
    captureSession.setMeteringPoint(Point1,(err) => {
        if (err) {
            console.log(`Failed to set the exposure point ${err.message}`);
            return ;
        }
        console.log('Callback returned with the successful execution of setMeteringPoint');
    })
    ```

    ```
    const Point2 = {x: 2, y: 2};
    
    captureSession.setMeteringPoint(Point2).then(() => {
        console.log('Promise returned with the successful execution of setMeteringPoint');
    })
    ```

16. 枚举CaptureSessionErrorCode中新增

    枚举值名称：ERROR_INSUFFICIENT_RESOURCES，值：0;

    枚举值名称：ERROR_TIMEOUT，值：1;

17. 新增接口CameraOutput，接口下有release(callback: AsyncCallback<void>): void;以及release(): Promise<void>;方法

    参考代码如下：用previewOutput做示例

    ```
    previewOutput.release((err) => {
        if (err) {
            console.error(`Failed to release the PreviewOutput instance ${err.message}`);
            return;
        }
        console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
    });
    ```

    ```
    previewOutput.release().then(() => {
        console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
    })
    ```

18. PreviewOutput中新增start(callback: AsyncCallback<void>): void;以及start(): Promise<void>;

    参考代码如下

    ```
    previewOutput.start((err) => {
        if (err) {
            console.error(`Failed to start the previewOutput. ${err.message}`);
            return;
        }
        console.log('Callback returned with previewOutput started.');
    })
    ```

    ```
    previewOutput.start().then(() => {
        console.log('Promise returned with previewOutput started.');
    })
    ```

19. PreviewOutput中新增stop(callback: AsyncCallback<void>): void;以及stop(): Promise<void>;

    参考代码如下

    ```
    previewOutput.stop((err) => {
        if (err) {
            console.error(`Failed to stop the previewOutput. ${err.message}`);
            return;
        }
        console.log('Callback returned with previewOutput stopped.');
    })
    ```

    ```
    previewOutput.stop().then(() => {
        console.log('Callback returned with previewOutput stopped.');
    })
    ```

20. PhotoCaptureSetting接口

    属性1：mirror?，类型：boolean;

21. 枚举PhotoOutputErrorCode中新增

    枚举值名称：ERROR_DRIVER_ERROR，值：0;

    枚举值名称：ERROR_INSUFFICIENT_RESOURCES，值：1;

    枚举值名称：ERROR_TIMEOUT，值：2;

22. 枚举VideoOutputErrorCode中新增

    枚举值名称：ERROR_DRIVER_ERROR，值：0;

23. MetadataOutput中新增on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void;

    参考代码如下

    ```
    metadataOutput.on('error', (metadataOutputError) => {
        console.log(`Metadata output error code: ${metadataOutputError.code}`);
    })
    ```

24. MetadataOutputErrorCode枚举

    枚举值名称：ERROR_UNKNOWN，值：-1;

    枚举值名称：ERROR_INSUFFICIENT_RESOURCES，值：0;

25. MetadataOutputError接口

    属性名称：code，值：MetadataOutputErrorCode

**废弃接口**

1. CameraInput中废弃接口on(type: 'exposureStateChange', callback: AsyncCallback<ExposureState>): void;

2. previewOutput中废弃接口release(callback: AsyncCallback<void>): void;以及release(): Promise<void>;

3. metadataOutput中废弃接口

   setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<void>): void;<br/>setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>): Promise<void>;

4. metadataOutput中废弃接口

   getSupportedMetadataObjectTypes(callback: AsyncCallback<Array<MetadataObjectType>>): void;<br/>getSupportedMetadataObjectTypes(): Promise<Array<MetadataObjectType>>;

5. PreviewOutput中废弃接口release(callback: AsyncCallback<void>): void;以及release(): Promise<void>;

6. PhotoOutput中废弃接口release(callback: AsyncCallback<void>): void;以及release(): Promise<void>;

7. VideoOutput中废弃接口release(callback: AsyncCallback<void>): void;以及release(): Promise<void>;

8. CameraInput中废弃接口getCameraId(callback: AsyncCallback<string>): void;以及getCameraId(): Promise<string>;

9. CameraInput中废弃接口getExposurePoint(callback: AsyncCallback<Point>): void;以及getExposurePoint(): Promise<Point>;

10. CameraInput中废弃接口setExposurePoint(exposurePoint: Point, callback: AsyncCallback<void>): void;以及setExposurePoint(exposurePoint: Point): Promise<void>;

**接口变更**

1. CameraManager中接口getCameras返回值由Array<Camera>变更为Array<CameraDevice>，接口名由getCameras 更换为 getSupportedCameras，因此旧接口getCameras(callback: AsyncCallback<Array<Camera>>): void;以及getCameras(): Promise<Array<Camera>>;变更为getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void和getSupportedCameras(): Promise<Array<CameraDevice>>;

   参考代码如下：

   ```
   cameraManager.getSupportedCameras((err, cameras) => {
       if (err) {
           console.error(`Failed to get the cameras. ${err.message}`);
           return;
       }
       console.log(`Callback returned with an array of supported cameras: ${cameras.length}`);
   })
   ```

   ```
   cameraManager.getSupportedCameras().then((cameras) => {
       console.log(`Promise returned with an array of supported cameras: ${cameras.length}`);
   })
   ```

2. CameraManager中接口createCameraInput传递参数由原来cameraId: string变更为camera: CameraDevice，因此旧接口createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput>): void;以及createCameraInput(cameraId: string): Promise<CameraInput>;变更为createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;和createCameraInput(camera: CameraDevice): Promise<CameraInput>;

   参考代码如下：

   ```
   let cameraDevice = cameras[0];
   cameraManager.createCameraInput(cameraDevice, (err, cameraInput) => {
       if (err) {
           console.error(`Failed to create the CameraInput instance. ${err.message}`);
           return;
       }
       console.log('Callback returned with the CameraInput instance.');
   })
   ```

   ```
   let cameraDevice = cameras[0];
   cameraManager.createCameraInput(cameraDevice).then((cameraInput) => {
       console.log('Promise returned with the CameraInput instance');
   })
   ```

3. CameraManager中接口createPreviewOutput新增传递参数profile: Profile，profile参数由getSupportedOutputCapability接口获取，因此旧接口createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;以及createPreviewOutput(surfaceId: string): Promise<PreviewOutput>;变更为createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>;

   参考代码如下：

   ```
   let profile = cameraoutputcapability.previewProfiles[0];
   cameraManager.createPreviewOutput(profile, surfaceId, (err, previewOutput) => {
       if (err) {
           console.error(`Failed to gcreate previewOutput. ${err.message}`);
           return;
       }
       console.log('Callback returned with previewOutput created.');
   })
   ```

   ```
   let profile = cameraoutputcapability.previewProfiles[0];
   cameraManager.createPreviewOutput(profile, surfaceId).then((previewOutput) => {
       console.log('Promise returned with previewOutput created.');
   })
   ```

4. CameraManager中接口createPhotoOutput新增传递参数profile: Profile，profile参数由getSupportedOutputCapability接口获取，因此旧接口CreatePhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;以及CreatePhotoOutput(surfaceId: string): Promise<PhotoOutput>;变更为createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;和createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>;

   参考代码如下：

   ```
   let profile = cameraoutputcapability.photoProfiles[0];
   cameraManager.createPhotoOutput(profile, surfaceId, (err, photoOutput) => {
       if (err) {
           console.error(`Failed to create photoOutput. ${err.message}`);
           return;
       }
       console.log('Callback returned with photoOutput created.');
   })
   ```

   ```
   let profile = cameraoutputcapability.photoProfiles[0];
   cameraManager.createPhotoOutput(profile, surfaceId).then((photoOutput) => {
       console.log('Promise returned with photoOutput created.');
   })
   ```

5. CameraManager中接口createVideoOutput新增传递参数profile: Profile，profile参数由getSupportedOutputCapability接口获取，因此旧接口createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput>): void;以及createVideoOutput(surfaceId: string): Promise<VideoOutput>;变更为createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;和createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>;

   参考代码如下：

   ```
   let profile = cameraoutputcapability.videoProfiles[0];
   cameraManager.createVideoOutput(profile, surfaceId, (err, videoOutput) => {
       if (err) {
           console.error(`Failed to create videoOutput. ${err.message}`);
           return;
       }
       console.log('Callback returned with an array of supported outputCapability' );
   })
   ```

   ```
   let profile = cameraoutputcapability.videoProfiles[0];
   cameraManager.createVideoOutput(profile, surfaceId).then((videoOutput) => {
       console.log('Promise returned with videoOutput created.');
   })
   ```

6. CameraManager中接口createMetadataOutput新增传递参数metadataObjectTypes: Array<MetadataObjectType>,metadataObjectTypes参数由getSupportedOutputCapability接口获取，因此旧接口function createMetadataOutput(callback: AsyncCallback<MetadataOutput>): void;以及function createMetadataOutput(): Promise<MetadataOutput>;变更为createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;和createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>;

   参考代码如下：

   ```
   let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
   cameraManager.createMetadataOutput(metadataObjectTypes, (err, metadataOutput) => {
       if (err) {
           console.error(`Failed to create metadataOutput. ${err.message}`);
           return;
       }
       console.log('Callback returned with metadataOutput created.');
   })
   ```

   ```
   let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
   cameraManager.createMetadataOutput(metadataObjectTypes).then((metadataOutput) => {
       console.log('Promise returned with metadataOutput created.');
   })
   ```
   
7. CameraManager中createCaptureSession不需要考虑context属性，因此旧接口createCaptureSession(context: Context, callback: AsyncCallback<CaptureSession>): void;以及createCaptureSession(context: Context): Promise<CaptureSession>;改为createCaptureSession(callback: AsyncCallback<CaptureSession>): void;和createCaptureSession(): Promise<CaptureSession>;

   参考代码如下：

   ```typescript
   cameraManager.createCaptureSession((err, captureSession) => {
       if (err) {
           console.error(`Failed to create captureSession. ${err.message}`);
           return;
       }
       console.log('Callback returned with captureSession created.');
   })
   ```

   ```
   cameraManager.createCaptureSession().then((captureSession) => {
       console.log('Promise returned with captureSession created.');
   })
   ```

8. CameraStatusInfo接口下属性camera类型由Camera变更为CameraDevice

9. CameraInput中接口on(type: 'error'）新增传递参数camera: CameraDevice，因此旧接口on(type: 'error', callback: ErrorCallback<CameraInputError>): void;变更为on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void;

   参考代码如下：

   ```
   let cameraDevice = cameras[0];
   cameraInput.on('error', cameraDevice, (cameraInputError) => {
       console.log(`Camera input error code: ${cameraInputError.code}`);
   })
   ```
	
10. CameraInput中以下接口调整到CaptureSession中

    hasFlash(callback: AsyncCallback<boolean>): void;<br/>hasFlash(): Promise<boolean>;<br/>

    isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br/>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;<br/>

    getFlashMode(callback: AsyncCallback<FlashMode>): void;<br/>getFlashMode(): Promise<FlashMode>;<br/>

    setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br/>setFlashMode(flashMode: FlashMode): Promise<void>;<br/>

    isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br/>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>;<br/>

    getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br/>getExposureMode(): Promise<ExposureMode>;<br/>

    setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br/>setExposureMode(aeMode: ExposureMode): Promise<void>;<br/>

    getMeteringPoint(callback: AsyncCallback<Point>): void;<br/>getMeteringPoint(): Promise<Point>;<br/>

    setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setMeteringPoint(point: Point): Promise<void>;<br/>

    getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br/>getExposureBiasRange(): Promise<Array<number>>;<br/>

    setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br/>setExposureBias(exposureBias: number): Promise<void>;<br/>

    getExposureValue(callback: AsyncCallback<number>): void;<br/>getExposureValue(): Promise<number>;<br/>

    isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br/>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;<br/>

    getFocusMode(callback: AsyncCallback<FocusMode>): void;<br/>getFocusMode(): Promise<FocusMode>;<br/>

    setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br/>setFocusMode(afMode: FocusMode): Promise<void>;<br/>

    setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setFocusPoint(point: Point): Promise<void>;<br/>

    getFocusPoint(callback: AsyncCallback<Point>): void;<br/>getFocusPoint(): Promise<Point>;<br/>

    getFocalLength(callback: AsyncCallback<number>): void;<br/>getFocalLength(): Promise<number>;<br/>

    getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br/>getZoomRatioRange(): Promise<Array<number>>;<br/>

    getZoomRatio(callback: AsyncCallback<number>): void;<br/>getZoomRatio(): Promise<number>;<br/>

    setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br/>setZoomRatio(zoomRatio: number): Promise<void>;
	
11. CameraInput中接口on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void;调整到CaptureSession中，对应接口on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void;

    参考代码如下：

    ```
    captureSession.on('focusStateChange', (focusState) => {
        console.log(`Focus state  : ${focusState}`);
    })
    ```

12. 枚举ExposureMode中

    枚举值名称：EXPOSURE_MODE_AUTO，初值由默认变更为1;

    枚举值名称：EXPOSURE_MODE_CONTINUOUS_AUTO，初值由默认变更为2;

13. 枚举VideoStabilizationMode中

    枚举值名称：LOW，初值由默认变更为1;

    枚举值名称：MIDDLE，初值由默认变更为2;

    枚举值名称：HIGH，初值由默认变更为3;

    枚举值名称：AUTO，初值由默认变更为4;

14. CaptureSession中接口addOutput参数由原来子类类型（PreviewOutput，PhotoOutput，VideoOutput，MetadataOutput）统一修改为基类类型（CameraOutput），变更后由原来8个接口缩减为2个接口。

    改变前接口为：

    addOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br/>addOutput(previewOutput: PreviewOutput): Promise<void>;<br/>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br/>addOutput(photoOutput: PhotoOutput): Promise<void>;<br/>addOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br/>addOutput(videoOutput: VideoOutput): Promise<void>;<br/>addOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br/>addOutput(metadataOutput: MetadataOutput): Promise<void>;

    改变后接口为：

    addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>addOutput(cameraOutput: CameraOutput): Promise<void>;

    参考代码如下：以PreviewOutput为例

    ```
    captureSession.addOutput(previewOutput, (err) => {
        if (err) {
            console.error(`Failed to add output. ${err.message}`);
            return;
        }
        console.log('Callback returned with output added.');
    })
    ```

    ```
    captureSession.addOutput(previewOutput).then(() => {
        console.log('Promise returned with cameraOutput added.');
    })
    ```

15. CaptureSession中接口removeOutput参数由原来子类类型（PreviewOutput，PhotoOutput，VideoOutput，MetadataOutput）统一修改为基类类型（CameraOutput），变更后由原来8个接口缩减为2个接口。

    改变前接口为：

    removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(previewOutput: PreviewOutput): Promise<void>;<br/>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(photoOutput: PhotoOutput): Promise<void>;<br/>removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(videoOutput: VideoOutput): Promise<void>;<br/>removeOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(metadataOutput: MetadataOutput): Promise<void>;

    改变后接口为：

    removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(cameraOutput: CameraOutput): Promise<void>;

    参考代码如下：以PreviewOutput为例

    ```
    captureSession.removeOutput(previewOutput, (err) => {
        if (err) {
            console.error(`Failed to remove the CameraOutput instance. ${err.message}`);
            return;
        }
        console.log('Callback invoked to indicate that the CameraOutput instance is removed.');
    });
    ```

    ```
    captureSession.removeOutput(previewOutput).then(() => {
        console.log('Promise returned to indicate that the CameraOutput instance is removed.');
    })
    ```

16. 枚举MetadataObjectType中

    枚举值名称由FACE变更为FACE_DETECTION;

17. 接口Camera名称更改为CameraDevice
