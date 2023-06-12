# 媒体子系统 JS API 变更 Changelog

## cl.subsystemname.1 camera 接口变更
1. camera 部件在 API9 版本全量改为 SystemAPI
2. 基于以下原因新增部分功能接口以及废弃部分接口：

提升开发者使用相机接口的便利。
帮助开发者快速掌握相机开发接口，快速投入到开发当中。
易于后续版本中框架功能的扩展，降低框架模块之间的耦合度。

具体参考下方变更内容，开发者需要根据以下说明对应用进行适配。

**变更影响**

影响 API9 版本的 JS 接口，应用需要进行适配才可以在新版本 SDK 环境正常实现功能。

**关键的接口/组件变更**

| 模块名                 | 类名                    | 方法/属性/枚举/常量                                          | 是否为 SystemApi | 变更类型 |
| ---------------------- | ----------------------- | ------------------------------------------------------------ | --------------- | -------- |
| ohos.multimedia.camera | camera                  | function getCameraManager(context: Context): CameraManager;  | 是              | 新增     |
| ohos.multimedia.camera | camera                  | function getCameraManager(context: Context, callback: AsyncCallback<CameraManager>): void;<br/>function getCameraManager(context: Context): Promise<CameraManager>;       | 是              | 废弃     |
| ohos.multimedia.camera | CameraErrorCode         | INVALID_ARGUMENT = 7400101,<br/>OPERATION_NOT_ALLOWED = 7400102,<br/>SESSION_NOT_CONFIG = 7400103,<br/>SESSION_NOT_RUNNING = 7400104,<br/>SESSION_CONFIG_LOCKED = 7400105,<br/>DEVICE_SETTING_LOCKED = 7400106,<br/>CONFILICT_CAMERA = 7400107,<br/>DEVICE_DISABLED = 7400108,<br/>SERVICE_FATAL_ERROR = 7400201                                                      | 是              | 新增     |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(): Array<CameraDevice>;<br/>getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;<br/>createCameraInput(camera: CameraDevice): CameraInput;<br/>createCameraInput(position: CameraPosition, type: CameraType): CameraInput;<br/>createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;<br/>createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;<br/>createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;<br/>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): MetadataOutput;<br/>createCaptureSession(): CaptureSession;                                 | 是              | 新增     |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void;<br/>getSupportedCameras(): Promise<Array<CameraDevice>>;<br/>getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;<br/>getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>;<br/>createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;<br/>createCameraInput(camera: CameraDevice): Promise<CameraInput>;<br/>createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput>): void;<br/>createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput>;<br/>createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br/>createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>;<br/>createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br/>createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>;<br/>createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br/>createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>;<br/>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;<br/>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>;<br/>createCaptureSession(callback: AsyncCallback<CaptureSession>): void;<br/>createCaptureSession(): Promise<CaptureSession>; | 是              | 废弃     |
| ohos.multimedia.camera | CameraType              | CAMERA_TYPE_DEFAULT = 0                                                                           | 是              | 新增     |
| ohos.multimedia.camera | CameraType              | CAMERA_TYPE_UNSPECIFIED = 0                                                                       | 是              | 废弃     |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', camera: CameraDevice, callback: ErrorCallback<BusinessError>): void;            | 是              | 新增     |
| ohos.multimedia.camera | CameraInput             | release(callback: AsyncCallback<void>): void;<br/>release(): Promise<void>;<br/>on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void; | 是              | 废弃     |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_UNKNOWN = -1<br/>ERROR_NO_PERMISSION = 0<br/>ERROR_DEVICE_PREEMPTED = 1<br/>ERROR_DEVICE_DISCONNECTED = 2<br/>ERROR_DEVICE_IN_USE = 3<br/>ERROR_DRIVER_ERROR = 4    | 是              | 废弃     |
| ohos.multimedia.camera | CameraInputError        | code: CameraInputErrorCode                                                                        | 是              | 废弃     |
| ohos.multimedia.camera | CaptureSession          | beginConfig(): void;<br/>addInput(cameraInput: CameraInput): void;<br/>removeInput(cameraInput: CameraInput): void;<br/>addOutput(cameraOutput: CameraOutput): void;<br/>removeOutput(cameraOutput: CameraOutput): void;<br/>hasFlash(): boolean;<br/>isFlashModeSupported(flashMode: FlashMode): boolean;<br/>getFlashMode(): FlashMode;<br/>setFlashMode(flashMode: FlashMode): void;<br/>isExposureModeSupported(aeMode: ExposureMode): boolean;<br/>getExposureMode(): ExposureMode;<br/>setExposureMode(aeMode: ExposureMode): void;<br/>getMeteringPoint(): Point;<br/>setMeteringPoint(point: Point): void;<br/>getExposureBiasRange(): Array<number>;<br/>setExposureBias(exposureBias: number): void;<br/>getExposureValue(): number;<br/>isFocusModeSupported(afMode: FocusMode): boolean;<br/>getFocusMode(): FocusMode;<br/>setFocusMode(afMode: FocusMode): void;<br/>setFocusPoint(point: Point): void;<br/>getFocusPoint(): Point;<br/>getFocalLength(): number;<br/>getZoomRatioRange(): Array<number>;<br/>getZoomRatio(): number;<br/>setZoomRatio(zoomRatio: number): void;<br/>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;<br/>getActiveVideoStabilizationMode(): VideoStabilizationMode;<br/>setVideoStabilizationMode(mode: VideoStabilizationMode): void;<br/>on(type: 'error', callback: ErrorCallback<BusinessError>): void;                             | 是              | 新增     |
| ohos.multimedia.camera | CaptureSession          | beginConfig(callback: AsyncCallback<void>): void;<br/>beginConfig(): Promise<void>;<br/>addInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void;<br/>addInput(cameraInput: CameraInput): Promise<void>;<br/>removeInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void;<br/>removeInput(cameraInput: CameraInput): Promise<void>;<br/>addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>addOutput(cameraOutput: CameraOutput): Promise<void>;<br/>removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br/>removeOutput(cameraOutput: CameraOutput): Promise<void>;<br/>hasFlash(callback: AsyncCallback<boolean>): void;<br/>hasFlash(): Promise<boolean>;<br/>isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br/>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;<br/>getFlashMode(callback: AsyncCallback<FlashMode>): void;<br/>getFlashMode(): Promise<FlashMode>;<br/>setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br/>setFlashMode(flashMode: FlashMode): Promise<void>;<br/>isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br/>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>;<br/>getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br/>getExposureMode(): Promise<ExposureMode>;<br/>setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br/>setExposureMode(aeMode: ExposureMode): Promise<void>;<br/>getMeteringPoint(callback: AsyncCallback<Point>): void;<br/>getMeteringPoint(): Promise<Point>;<br/>setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setMeteringPoint(point: Point): Promise<void>;<br/>getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br/>getExposureBiasRange(): Promise<Array<number>>;<br/>setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br/>setExposureBias(exposureBias: number): Promise<void>;<br/>getExposureValue(callback: AsyncCallback<number>): void;<br/>getExposureValue(): Promise<number>;<br/>isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br/>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;<br/>getFocusMode(callback: AsyncCallback<FocusMode>): void;<br/>getFocusMode(): Promise<FocusMode>;<br/>setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br/>setFocusMode(afMode: FocusMode): Promise<void>;<br/>setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br/>setFocusPoint(point: Point): Promise<void>;<br/>getFocusPoint(callback: AsyncCallback<Point>): void;<br/>getFocusPoint(): Promise<Point>;<br/>getFocalLength(callback: AsyncCallback<number>): void;<br/>getFocalLength(): Promise<number>;<br/>getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br/>getZoomRatioRange(): Promise<Array<number>>;<br/>getZoomRatio(callback: AsyncCallback<number>): void;<br/>getZoomRatio(): Promise<number>;<br/>setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br/>setZoomRatio(zoomRatio: number): Promise<void>;<br/>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void;<br/>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>;<br/>getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void;<br/>getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>;<br/>setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void;<br/>setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>;<br/>on(type: 'error', callback: ErrorCallback<CaptureSessionError>): void;                                     | 是              | 废弃     |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_UNKNOWN = -1<br/>ERROR_INSUFFICIENT_RESOURCES = 0<br/>ERROR_TIMEOUT = 1  | 是              | 废弃     |
| ohos.multimedia.camera | CaptureSessionError     | code: CaptureSessionErrorCode                                                  | 是              | 废弃     |
| ohos.multimedia.camera | PreviewOutput           | on(type: 'error', callback: ErrorCallback<BusinessError>): void;               | 是              | 新增     |
| ohos.multimedia.camera | PreviewOutput           | on(type: 'error', callback: ErrorCallback<PreviewOutputError>): void;          | 是              | 废弃     |
| ohos.multimedia.camera | PreviewOutputErrorCode  | ERROR_UNKNOWN = -1                                                             | 是              | 废弃     |
| ohos.multimedia.camera | PreviewOutputError      | code: PreviewOutputErrorCode                                                   | 是              | 废弃     |
| ohos.multimedia.camera | PhotoOutput             | capture(): Promise<void>;<br/>isMirrorSupported(): boolean;<br/>on(type: 'error', callback: ErrorCallback<BusinessError>): void;                                              | 是              | 新增     |
| ohos.multimedia.camera | PhotoOutput             | isMirrorSupported(callback: AsyncCallback<boolean>): void;<br/>isMirrorSupported(): Promise<boolean>;<br/>on(type: 'error', callback: ErrorCallback<PhotoOutputError>): void; | 是              | 废弃     |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_UNKNOWN = -1<br/>ERROR_DRIVER_ERROR = 0<br/>ERROR_INSUFFICIENT_RESOURCES = 1<br/>ERROR_TIMEOUT = 2 | 是              | 废弃     |
| ohos.multimedia.camera | PhotoOutputError        | code: PhotoOutputErrorCode                                                                               | 是              | 废弃     |
| ohos.multimedia.camera | VideoOutput             | on(type: 'error', callback: ErrorCallback<BusinessError>): void;                                         | 是              | 新增     |
| ohos.multimedia.camera | VideoOutput             | on(type: 'error', callback: ErrorCallback<VideoOutputError>): void;                                      | 是              | 废弃     |
| ohos.multimedia.camera | VideoOutputErrorCode    | ERROR_UNKNOWN = -1<br/>ERROR_DRIVER_ERROR = 0                                                            | 是              | 废弃     |
| ohos.multimedia.camera | VideoOutputError        | code: VideoOutputErrorCode                                                                               | 是              | 废弃     |
| ohos.multimedia.camera | MetadataObject          | readonly type: MetadataObjectType;<br/>readonly timestamp: number;                                       | 是              | 新增     |
| ohos.multimedia.camera | MetadataObject          | getType(callback: AsyncCallback<MetadataObjectType>): void;<br/>getType(): Promise<MetadataObjectType>;<br/>getTimestamp(callback: AsyncCallback<number>): void;<br/>getTimestamp(): Promise<number>;<br/>getBoundingBox(callback: AsyncCallback<Rect>): void;<br/>getBoundingBox(): Promise<Rect>;                                                                                  | 是              | 废弃     |
| ohos.multimedia.camera | MetadataFaceObject      | readonly boundingBox: Rect                                       | 是              | 新增     |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<BusinessError>): void; | 是              | 新增     |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<BusinessError>): void; | 是              | 废弃     |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_UNKNOWN = -1<br/>ERROR_INSUFFICIENT_RESOURCES = 0          | 是              | 废弃     |
| ohos.multimedia.camera | MetadataOutputError     | code: MetadataOutputErrorCode                                    | 是              | 废弃     |

**适配指导**

除新增接口，和废弃接口之外，开发者需要关注变更的接口的适配：

从 Beta4 版本开始，对以下接口进行调整：

**新增接口**

1. CameraErrorCode 枚举

   枚举值名称：INVALID_ARGUMENT，       值：7400101;

   枚举值名称：OPERATION_NOT_ALLOWED，  值：7400102;
   
   枚举值名称：SESSION_NOT_CONFIG，     值：7400103;
   
   枚举值名称：SESSION_NOT_RUNNING，    值：7400104;
   
   枚举值名称：SESSION_CONFIG_LOCKED，  值：7400105;
   
   枚举值名称：DEVICE_SETTING_LOCKED，  值：7400106;
   
   枚举值名称：CONFILICT_CAMERA，       值：7400107;
   
   枚举值名称：DEVICE_DISABLED，        值：7400108;
   
   枚举值名称：SERVICE_FATAL_ERROR，    值：7400201;

2. PhotoOutput 接口新增 capture(): Promise<void>;

3. MetadataObject 接口中新增 readonly type: MetadataObjectType;

4. MetadataObject 接口中新增 readonly timestamp: number;

5. MetadataObject 接口中新增 readonly boundingBox: Rect;

**废弃接口**

1. CameraInput 中废弃接口 release(callback: AsyncCallback<void>): void; 以及 release(): Promise<void>;

2. 废弃枚举 CameraInputErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1，ERROR_NO_PERMISSION = 0，ERROR_DEVICE_PREEMPTED = 1，ERROR_DEVICE_DISCONNECTED = 2，ERROR_DEVICE_IN_USE = 3，ERROR_DRIVER_ERROR = 4）;

3. 废弃接口 CameraInputError 以及接口属性 code:CameraInputErrorCode;

4. 废弃枚举 CaptureSessionErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1，ERROR_INSUFFICIENT_RESOURCES = 0，ERROR_TIMEOUT = 1）;

5. 废弃接口 CaptureSessionError 以及接口属性 code: CaptureSessionErrorCode;

6. 废弃枚举 PreviewOutputErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1）;

7. 废弃接口 PreviewOutputError 以及接口属性 code: PreviewOutputErrorCode;

8. 废弃枚举 PhotoOutputErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1，ERROR_DRIVER_ERROR = 0，ERROR_INSUFFICIENT_RESOURCES = 1，ERROR_TIMEOUT = 2）;

9. 废弃接口 PhotoOutputError 以及接口属性 code:PhotoOutputErrorCode;

10. 废弃枚举 VideoOutputErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1，ERROR_DRIVER_ERROR = 0）;

11. 废弃接口 VideoOutputError 以及接口属性 code:VideoOutputErrorCode;

12. 废弃接口 MetadataObject 中 getType(callback: AsyncCallback<MetadataObjectType>): void;

13. 废弃接口 MetadataObject 中 getType(): Promise<MetadataObjectType>;

14. 废弃接口 MetadataObject 中 getTimestamp(callback: AsyncCallback<number>): void;

15. 废弃接口 MetadataObject 中 getTimestamp(): Promise<number>;

16. 废弃接口 MetadataObject 中 getBoundingBox(callback: AsyncCallback<Rect>): void;

17. 废弃接口 MetadataObject 中 getBoundingBox(): Promise<Rect>;

18. 废弃枚举 MetadataOutputErrorCode 以及所有它里边的枚举值（ERROR_UNKNOWN = -1，ERROR_INSUFFICIENT_RESOURCES = 0）;

19. 废弃接口 MetadataOutputError 以及接口属性 code:MetadataOutputErrorCode;

**接口变更**

1. camera 模块中接口 getCameraManager 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getCameraManager(context: Context, callback: AsyncCallback<CameraManager>): void; 以及 getCameraManager(context: Context): Promise<CameraManager>; 变更为 getCameraManager(context: Context): CameraManager;

   参考代码如下：

   ```
   let cameraManager = camera.getCameraManager(context);
   ```
   
2. CameraManager 中接口 getSupportedCameras 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void; 以及 getSupportedCameras(): Promise<Array<CameraDevice>>; 变更为 getSupportedCameras(): Array<CameraDevice>;

   参考代码如下：

   ```
   let cameras = cameraManager.getSupportedCameras();
   ```
   
3. CameraManager 中接口 getSupportedOutputCapability 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void; 以及 getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>; 变更为 getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;

   参考代码如下：
   
   ```
   let cameraDevice = cameras[0];
   let CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);
   ```
   
4. CameraManager 中接口 createCameraInput(camera: CameraDevice) 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void; 以及 createCameraInput(camera: CameraDevice): Promise<CameraInput>; 变更为 createCameraInput(camera: CameraDevice): CameraInput;

   参考代码如下：
   
   ```
   let cameraDevice = cameras[0];
   let cameraInput = cameraManager.createCameraInput(cameraDevice);
   ```
   
5. CameraManager 中接口 createCameraInput(position: CameraPosition, type: CameraType) 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput>): void; 以及 createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput>; 变更为 createCameraInput(position: CameraPosition, type: CameraType): CameraInput;

   参考代码如下：
   
   ```
   let cameraDevice = cameras[0];
   let position = cameraDevice.cameraPosition;
   let type = cameraDevice.cameraType;
   let cameraInput = cameraManager.createCameraInput(position, type);
   ```
   
6. CameraManager 中接口 createPreviewOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void; 以及 createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>; 变更为 createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;

   参考代码如下：
   
   ```
   let profile = cameraoutputcapability.previewProfiles[0];
   let previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
   ```
   
7. CameraManager 中接口 createPhotoOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void; 以及 createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>; 变更为 createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;

   参考代码如下：
   
   ```
   let profile = cameraoutputcapability.photoProfiles[0];
   let photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
   ```
   
8. CameraManager 中接口 createVideoOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void; 以及 createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>; 变更为 createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;

   参考代码如下：
   
   ```
   let profile = cameraoutputcapability.videoProfiles[0];
   let videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
   ```
   
9. CameraManager 中接口 createMetadataOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void; 以及 createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>; 变更为 createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): MetadataOutput;

   参考代码如下：
   
   ```
   let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
   let metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
   ```
   
10. CameraManager 中接口 createCaptureSession 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 createCaptureSession(callback: AsyncCallback<CaptureSession>): void; 以及 createCaptureSession(): Promise<CaptureSession>; 变更为 createCaptureSession(): CaptureSession;

   参考代码如下：

   ```
   let captureSession = cameraManager.createCaptureSession();
   ```

11. 枚举 CameraType 中，枚举值名称 CAMERA_TYPE_UNSPECIFIED 变更为 CAMERA_TYPE_DEFAULT。

12. CameraInput 中，on 接口返回值类型由 CameraInputError 变更为 BusinessError，因此旧接口 on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void; 变更为 on(type: 'error', camera: CameraDevice, callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   let cameraDevice = cameras[0];
   cameraInput.on('error', cameraDevice, (BusinessError) => {
   
   })
   ```

13. CaptureSession 中接口 beginConfig 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 beginConfig(callback: AsyncCallback<void>): void; 以及 beginConfig(): Promise<void>; 变更为 beginConfig(): void;

   参考代码如下：

   ```
   captureSession.beginConfig();
   ```

14. CaptureSession 中接口 addInput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 addInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void; 以及 addInput(cameraInput: CameraInput): Promise<void>; 变更为 addInput(cameraInput: CameraInput): void;

   参考代码如下：

   ```
   captureSession.addInput(cameraInput);
   ```

15. CaptureSession 中接口 removeInput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 removeInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void; 以及 removeInput(cameraInput: CameraInput): Promise<void>; 变更为 removeInput(cameraInput: CameraInput): void;

   参考代码如下：

   ```
   captureSession.removeInput(cameraInput);
   ```

16. CaptureSession 中接口 addOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void; 以及 addOutput(cameraOutput: CameraOutput): Promise<void>; 变更为 addOutput(cameraOutput: CameraOutput): void;

   参考代码如下：

   ```
   captureSession.addOutput(previewOutput);
   ```

17. CaptureSession 中接口 removeOutput 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void; 以及 removeOutput(cameraOutput: CameraOutput): Promise<void>; 变更为 removeOutput(cameraOutput: CameraOutput): void;

   参考代码如下：

   ```
   captureSession.removeOutput(previewOutput);
   ```

18. CaptureSession 中接口 hasFlash 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 hasFlash(callback: AsyncCallback<boolean>): void; 以及 hasFlash(): Promise<boolean>; 变更为 hasFlash(): boolean;

   参考代码如下：

   ```
   let status = captureSession.hasFlash();
   ```

19. CaptureSession 中接口 isFlashModeSupported 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void; 以及 isFlashModeSupported(flashMode: FlashMode): Promise<boolean>; 变更为 isFlashModeSupported(flashMode: FlashMode): boolean;

   参考代码如下：

   ```
   let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
   ```

20. CaptureSession 中接口 getFlashMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getFlashMode(callback: AsyncCallback<FlashMode>): void; 以及 getFlashMode(): Promise<FlashMode>; 变更为 getFlashMode(): FlashMode;

   参考代码如下：

   ```
   let flashMode = captureSession.getFlashMode();
   ```

21. CaptureSession 中接口 isExposureModeSupported 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void; 以及 isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>; 变更为 isExposureModeSupported(aeMode: ExposureMode): boolean;

   参考代码如下：

   ```
   let isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
   ```

22. CaptureSession 中接口 getExposureMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getExposureMode(callback: AsyncCallback<ExposureMode>): void; 以及 getExposureMode(): Promise<ExposureMode>; 变更为 getExposureMode(): ExposureMode;

   参考代码如下：

   ```
   let exposureMode = captureSession.getExposureMode();
   ```

23. CaptureSession 中接口 setExposureMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void; 以及 setExposureMode(aeMode: ExposureMode): Promise<void>; 变更为 setExposureMode(aeMode: ExposureMode): void;

   参考代码如下：

   ```
   captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
   ```

24. CaptureSession 中接口 getMeteringPoint 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getMeteringPoint(callback: AsyncCallback<Point>): void; 以及 getMeteringPoint(): Promise<Point>; 变更为 getMeteringPoint(): Point;

   参考代码如下：

   ```
   let exposurePoint = captureSession.getMeteringPoint();
   ```

25. CaptureSession 中接口 setMeteringPoint 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setMeteringPoint(point: Point, callback: AsyncCallback<void>): void; 以及 setMeteringPoint(point: Point): Promise<void>; 变更为 setMeteringPoint(point: Point): void;

   参考代码如下：

   ```
   let Point2 = {x: 2, y: 2};
   captureSession.setMeteringPoint(Point2);
   ```

26. CaptureSession 中接口 getExposureBiasRange 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getExposureBiasRange(callback: AsyncCallback<Array<number>>): void; 以及 getExposureBiasRange(): Promise<Array<number>>; 变更为 getExposureBiasRange(): Array<number>;

   参考代码如下：

   ```
   let biasRangeArray = captureSession.getExposureBiasRange();
   ```

27. CaptureSession 中接口 setExposureBias 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void; 以及 setExposureBias(exposureBias: number): Promise<void>; 变更为 setExposureBias(exposureBias: number): void;

   参考代码如下：

   ```
   let exposureBias = biasRangeArray[0];
   captureSession.setExposureBias(exposureBias);
   ```

28. CaptureSession 中接口 getExposureValue 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getExposureValue(callback: AsyncCallback<number>): void; 以及 getExposureValue(): Promise<number>; 变更为 getExposureValue(): number;

   参考代码如下：

   ```
   let exposureValue = captureSession.getExposureValue();
   ```

29. CaptureSession 中接口 isFocusModeSupported 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void; 以及 isFocusModeSupported(afMode: FocusMode): Promise<boolean>; 变更为 isFocusModeSupported(afMode: FocusMode): boolean;

   参考代码如下：

   ```
   let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
   ```

30. CaptureSession 中接口 getFocusMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getFocusMode(callback: AsyncCallback<FocusMode>): void; 以及 getFocusMode(): Promise<FocusMode>; 变更为 getFocusMode(): FocusMode;

   参考代码如下：

   ```
   let afMode = captureSession.getFocusMode();
   ```

31. CaptureSession 中接口 setFocusMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void; 以及 setFocusMode(afMode: FocusMode): Promise<void>; 变更为 setFocusMode(afMode: FocusMode): void;

   参考代码如下：

   ```
   captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
   ```

32. CaptureSession 中接口 setFocusPoint 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setFocusPoint(point: Point, callback: AsyncCallback<void>): void; 以及 setFocusPoint(point: Point): Promise<void>; 变更为 setFocusPoint(point: Point): void;

   参考代码如下：

   ```
   let Point2 = {x: 2, y: 2};
   captureSession.setFocusPoint(Point2);
   ```

33. CaptureSession 中接口 getFocusPoint 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getFocusPoint(callback: AsyncCallback<Point>): void; 以及 getFocusPoint(): Promise<Point>; 变更为 getFocusPoint(): Point;

   参考代码如下：

   ```
   let point = captureSession.getFocusPoint();
   ```

34. CaptureSession 中接口 getFocalLength 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getFocalLength(callback: AsyncCallback<number>): void; 以及 getFocalLength(): Promise<number>; 变更为 getFocalLength(): number;

   参考代码如下：

   ```
   let focalLength = captureSession.getFocalLength();
   ```

35. CaptureSession 中接口 getZoomRatioRange 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getZoomRatioRange(callback: AsyncCallback<Array<number>>): void; 以及 getZoomRatioRange(): Promise<Array<number>>; 变更为 getZoomRatioRange(): Array<number>;

   参考代码如下：

   ```
   let zoomRatioRange = captureSession.getZoomRatioRange();
   ```

36. CaptureSession 中接口 getZoomRatio 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getZoomRatio(callback: AsyncCallback<number>): void; 以及 getZoomRatio(): Promise<number>; 变更为 getZoomRatio(): number;

   参考代码如下：

   ```
   let zoomRatio = captureSession.getZoomRatio();
   ```

37. CaptureSession 中接口 setZoomRatio 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void; 以及 setZoomRatio(zoomRatio: number): Promise<void>; 变更为 setZoomRatio(zoomRatio: number): void;

   参考代码如下：

   ```
   let zoomRatio = zoomRatioRange[0];
   captureSession.setZoomRatio(zoomRatio);
   ```

38. CaptureSession 中接口 isVideoStabilizationModeSupported 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void; 以及 isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>; 变更为 isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;

   参考代码如下：

   ```
   let isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
   ```

39. CaptureSession 中接口 getActiveVideoStabilizationMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void; 以及 getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>; 变更为 getActiveVideoStabilizationMode(): VideoStabilizationMode;

   参考代码如下：

   ```
   let vsMode = captureSession.getActiveVideoStabilizationMode();
   ```

40. CaptureSession 中接口 setVideoStabilizationMode 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void; 以及 setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>; 变更为 setVideoStabilizationMode(mode: VideoStabilizationMode): void;

   参考代码如下：

   ```
   captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
   ```

41. CaptureSession 中，on(type: 'error') callback 类型由 ErrorCallback<CaptureSessionError> 变更为 ErrorCallback<BusinessError>，因此旧接口 on(type: 'error', callback: ErrorCallback<CaptureSessionError>): void; 变更为 on(type: 'error', callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   captureSession.on('error', (BusinessError) => {
   
   })
   ```

42. PreviewOutput 中，on(type: 'error') callback 类型由 ErrorCallback<PreviewOutputError> 变更为 ErrorCallback<BusinessError>，因此旧接口 on(type: 'error', callback: ErrorCallback<PreviewOutputError>): void; 变更为 on(type: 'error', callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   previewOutput.on('error', (BusinessError) => {
   
   })
   ```

43. PhotoOutput 中接口 isMirrorSupported 返回方式由异步 callback 跟异步 promise 变更为同步返回，因此旧接口 isMirrorSupported(callback: AsyncCallback<boolean>): void; 以及 isMirrorSupported(): Promise<boolean>; 变更为 isMirrorSupported(): boolean;

   参考代码如下：

   ```
   let isSupported = photoOutput.isMirrorSupported();
   ```

44. PhotoOutput 中，on(type: 'error') callback 类型由 ErrorCallback<PhotoOutputError> 变更为 ErrorCallback<BusinessError>，因此旧接口 on(type: 'error', callback: ErrorCallback<PhotoOutputError>): void; 变更为 on(type: 'error', callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   PhotoOutput.on('error', (BusinessError) => {
   
   })
   ```

45. VideoOutput 中，on(type: 'error') callback 类型由 ErrorCallback<VideoOutputError> 变更为 ErrorCallback<BusinessError>，因此旧接口 on(type: 'error', callback: ErrorCallback<VideoOutputError>): void; 变更为 on(type: 'error', callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   VideoOutput.on('error', (BusinessError) => {
   
   })
   ```

46. MetadataOutput 中，on(type: 'error') callback 类型由 ErrorCallback<MetadataOutputError> 变更为 ErrorCallback<BusinessError>，因此旧接口 on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void; 变更为 on(type: 'error', callback: ErrorCallback<BusinessError>): void;

   参考代码如下：

   ```
   MetadataOutput.on('error', (BusinessError) => {
   
   })
   ```