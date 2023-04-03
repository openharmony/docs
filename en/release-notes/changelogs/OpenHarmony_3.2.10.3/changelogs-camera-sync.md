# Multimedia Subsystem ChangeLog

Compared with OpenHarmony 3.2 Beta4, OpenHarmony3.2.10.3 has the following changes in APIs of the camera component in the multimedia subsystem.

## cl.subsystemname.1 Camera API Changed
1. All the APIs of the camera component are changed to system APIs in the API version 9.
2. Some functional APIs are added and some others are deprecated to:

- Improve the usability of camera APIs.
- Help you quickly understand camera APIs and use them for development.
- Facilitate expansion of framework functions in later versions, and reduce coupling between framework modules.

You need to refer to the following change description to adapt your application.

**Change Impacts**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                | Class                   | Method/Attribute/Enum/Constant                                         | Is System API| Change Type|
| ---------------------- | ----------------------- | ------------------------------------------------------------ | --------------- | -------- |
| ohos.multimedia.camera | camera                  | function getCameraManager(context: Context): CameraManager;  | Yes             | Added    |
| ohos.multimedia.camera | camera                  | function getCameraManager(context: Context, callback: AsyncCallback<CameraManager>): void;<br>function getCameraManager(context: Context): Promise<CameraManager>;       | Yes             | Deprecated    |
| ohos.multimedia.camera | CameraErrorCode         | INVALID_ARGUMENT = 7400101,<br>OPERATION_NOT_ALLOWED = 7400102,<br>SESSION_NOT_CONFIG = 7400103,<br>SESSION_NOT_RUNNING = 7400104,<br>SESSION_CONFIG_LOCKED = 7400105,<br>DEVICE_SETTING_LOCKED = 7400106,<br>CONFILICT_CAMERA = 7400107,<br>DEVICE_DISABLED = 7400108,<br>SERVICE_FATAL_ERROR = 7400201                                                      | Yes             | Added    |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(): Array<CameraDevice>;<br>getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;<br>createCameraInput(camera: CameraDevice): CameraInput;<br>createCameraInput(position: CameraPosition, type: CameraType): CameraInput;<br>createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;<br>createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;<br>createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;<br>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): MetadataOutput;<br>createCaptureSession(): CaptureSession;                                 | Yes             | Added    |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void;<br>getSupportedCameras(): Promise<Array<CameraDevice>>;<br>getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;<br>getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>;<br>createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;<br>createCameraInput(camera: CameraDevice): Promise<CameraInput>;<br>createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput>): void;<br>createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput>;<br>createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br>createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>;<br>createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br>createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>;<br>createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br>createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>;<br>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;<br>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>;<br>createCaptureSession(callback: AsyncCallback<CaptureSession>): void;<br>createCaptureSession(): Promise<CaptureSession>; | Yes             | Deprecated    |
| ohos.multimedia.camera | CameraType              | CAMERA_TYPE_DEFAULT = 0                                                                           | Yes             | Added    |
| ohos.multimedia.camera | CameraType              | CAMERA_TYPE_UNSPECIFIED = 0                                                                       | Yes             | Deprecated    |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', camera: CameraDevice, callback: ErrorCallback<BusinessError>): void;            | Yes             | Added    |
| ohos.multimedia.camera | CameraInput             | release(callback: AsyncCallback<void>): void;<br>release(): Promise<void>;<br>on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void; | Yes             | Deprecated    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_UNKNOWN = -1<br>ERROR_NO_PERMISSION = 0<br>ERROR_DEVICE_PREEMPTED = 1<br>ERROR_DEVICE_DISCONNECTED = 2<br>ERROR_DEVICE_IN_USE = 3<br>ERROR_DRIVER_ERROR = 4    | Yes             | Deprecated    |
| ohos.multimedia.camera | CameraInputError        | code: CameraInputErrorCode                                                                        | Yes             | Deprecated    |
| ohos.multimedia.camera | CaptureSession          | beginConfig(): void;<br>addInput(cameraInput: CameraInput): void;<br>removeInput(cameraInput: CameraInput): void;<br>addOutput(cameraOutput: CameraOutput): void;<br>removeOutput(cameraOutput: CameraOutput): void;<br>hasFlash(): boolean;<br>isFlashModeSupported(flashMode: FlashMode): boolean;<br>getFlashMode(): FlashMode;<br>setFlashMode(flashMode: FlashMode): void;<br>isExposureModeSupported(aeMode: ExposureMode): boolean;<br>getExposureMode(): ExposureMode;<br>setExposureMode(aeMode: ExposureMode): void;<br>getMeteringPoint(): Point;<br>setMeteringPoint(point: Point): void;<br>getExposureBiasRange(): Array<number>;<br>setExposureBias(exposureBias: number): void;<br>getExposureValue(): number;<br>isFocusModeSupported(afMode: FocusMode): boolean;<br>getFocusMode(): FocusMode;<br>setFocusMode(afMode: FocusMode): void;<br>setFocusPoint(point: Point): void;<br>getFocusPoint(): Point;<br>getFocalLength(): number;<br>getZoomRatioRange(): Array<number>;<br>getZoomRatio(): number;<br>setZoomRatio(zoomRatio: number): void;<br>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;<br>getActiveVideoStabilizationMode(): VideoStabilizationMode;<br>setVideoStabilizationMode(mode: VideoStabilizationMode): void;<br>on(type: 'error', callback: ErrorCallback<BusinessError>): void;                             | Yes             | Added    |
| ohos.multimedia.camera | CaptureSession          | beginConfig(callback: AsyncCallback<void>): void;<br>beginConfig(): Promise<void>;<br>addInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void;<br>addInput(cameraInput: CameraInput): Promise<void>;<br>removeInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void;<br>removeInput(cameraInput: CameraInput): Promise<void>;<br>addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>addOutput(cameraOutput: CameraOutput): Promise<void>;<br>removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>removeOutput(cameraOutput: CameraOutput): Promise<void>;<br>hasFlash(callback: AsyncCallback<boolean>): void;<br>hasFlash(): Promise<boolean>;<br>isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;<br>getFlashMode(callback: AsyncCallback<FlashMode>): void;<br>getFlashMode(): Promise<FlashMode>;<br>setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise<void>;<br>isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>;<br>getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br>getExposureMode(): Promise<ExposureMode>;<br>setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br>setExposureMode(aeMode: ExposureMode): Promise<void>;<br>getMeteringPoint(callback: AsyncCallback<Point>): void;<br>getMeteringPoint(): Promise<Point>;<br>setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br>setMeteringPoint(point: Point): Promise<void>;<br>getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br>getExposureBiasRange(): Promise<Array<number>>;<br>setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br>setExposureBias(exposureBias: number): Promise<void>;<br>getExposureValue(callback: AsyncCallback<number>): void;<br>getExposureValue(): Promise<number>;<br>isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;<br>getFocusMode(callback: AsyncCallback<FocusMode>): void;<br>getFocusMode(): Promise<FocusMode>;<br>setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br>setFocusMode(afMode: FocusMode): Promise<void>;<br>setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br>setFocusPoint(point: Point): Promise<void>;<br>getFocusPoint(callback: AsyncCallback<Point>): void;<br>getFocusPoint(): Promise<Point>;<br>getFocalLength(callback: AsyncCallback<number>): void;<br>getFocalLength(): Promise<number>;<br>getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br>getZoomRatioRange(): Promise<Array<number>>;<br>getZoomRatio(callback: AsyncCallback<number>): void;<br>getZoomRatio(): Promise<number>;<br>setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br>setZoomRatio(zoomRatio: number): Promise<void>;<br>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void;<br>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>;<br>getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void;<br>getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>;<br>setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void;<br>setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>;<br>on(type: 'error', callback: ErrorCallback<CaptureSessionError>): void;                                     | Yes             | Deprecated    |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_UNKNOWN = -1<br>ERROR_INSUFFICIENT_RESOURCES = 0<br>ERROR_TIMEOUT = 1  | Yes             | Deprecated    |
| ohos.multimedia.camera | CaptureSessionError     | code: CaptureSessionErrorCode                                                  | Yes             | Deprecated    |
| ohos.multimedia.camera | PreviewOutput           | on(type: 'error', callback: ErrorCallback<BusinessError>): void;               | Yes             | Added    |
| ohos.multimedia.camera | PreviewOutput           | on(type: 'error', callback: ErrorCallback<PreviewOutputError>): void;          | Yes             | Deprecated    |
| ohos.multimedia.camera | PreviewOutputErrorCode  | ERROR_UNKNOWN = -1                                                             | Yes             | Deprecated    |
| ohos.multimedia.camera | PreviewOutputError      | code: PreviewOutputErrorCode                                                   | Yes             | Deprecated    |
| ohos.multimedia.camera | PhotoOutput             | capture(): Promise<void>;<br>isMirrorSupported(): boolean;<br>on(type: 'error', callback: ErrorCallback<BusinessError>): void;                                              | Yes             | Added    |
| ohos.multimedia.camera | PhotoOutput             | isMirrorSupported(callback: AsyncCallback<boolean>): void;<br>isMirrorSupported(): Promise<boolean>;<br>on(type: 'error', callback: ErrorCallback<PhotoOutputError>): void; | Yes             | Deprecated    |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_UNKNOWN = -1<br>ERROR_DRIVER_ERROR = 0<br>ERROR_INSUFFICIENT_RESOURCES = 1<br>ERROR_TIMEOUT = 2 | Yes             | Deprecated    |
| ohos.multimedia.camera | PhotoOutputError        | code: PhotoOutputErrorCode                                                                               | Yes             | Deprecated    |
| ohos.multimedia.camera | VideoOutput             | on(type: 'error', callback: ErrorCallback<BusinessError>): void;                                         | Yes             | Added    |
| ohos.multimedia.camera | VideoOutput             | on(type: 'error', callback: ErrorCallback<VideoOutputError>): void;                                      | Yes             | Deprecated    |
| ohos.multimedia.camera | VideoOutputErrorCode    | ERROR_UNKNOWN = -1<br>ERROR_DRIVER_ERROR = 0                                                            | Yes             | Deprecated    |
| ohos.multimedia.camera | VideoOutputError        | code: VideoOutputErrorCode                                                                               | Yes             | Deprecated    |
| ohos.multimedia.camera | MetadataObject          | readonly type: MetadataObjectType;<br>readonly timestamp: number;                                       | Yes             | Added    |
| ohos.multimedia.camera | MetadataObject          | getType(callback: AsyncCallback<MetadataObjectType>): void;<br>getType(): Promise<MetadataObjectType>;<br>getTimestamp(callback: AsyncCallback<number>): void;<br>getTimestamp(): Promise<number>;<br>getBoundingBox(callback: AsyncCallback<Rect>): void;<br>getBoundingBox(): Promise<Rect>;                                                                                  | Yes             | Deprecated    |
| ohos.multimedia.camera | MetadataFaceObject      | readonly boundingBox: Rect                                       | Yes             | Added    |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<BusinessError>): void; | Yes             | Added    |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<BusinessError>): void; | Yes             | Deprecated    |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_UNKNOWN = -1<br>ERROR_INSUFFICIENT_RESOURCES = 0          | Yes             | Deprecated    |
| ohos.multimedia.camera | MetadataOutputError     | code: MetadataOutputErrorCode                                    | Yes             | Deprecated    |

**Adaptation Guide**

In addition to the new APIs and deprecated APIs, you need to adapt your application to the changed APIs.

In Beta4 and later versions, the following APIs are changed.

**New APIs**

1. **CameraErrorCode** enums

   Enum: INVALID_ARGUMENT; value: 7400101

   Enum: OPERATION_NOT_ALLOWED; value: 7400102
   
   Enum: SESSION_NOT_CONFIG; value: 7400103
   
   Enum: SESSION_NOT_RUNNING; value: 7400104
   
   Enum: SESSION_CONFIG_LOCKED; value: 7400105
   
   Enum: DEVICE_SETTING_LOCKED; value: 7400106
   
   Enum: CONFILICT_CAMERA; value: 7400107
   
   Enum: DEVICE_DISABLED; value: 7400108
   
   Enum: SERVICE_FATAL_ERROR; value: 7400201

2. Added **capture(): Promise<void>** to the **PhotoOutput** API.

3. Added the readonly type **MetadataObjectType** to the **MetadataObject** API.

4. Added **readonly timestamp: number** to the **MetadataObject** API.

5. Added **readonly boundingBox: Rect** to the **MetadataObject** API.

**Deprecated APIs**

1. Deprecated the **release(callback: AsyncCallback<void>): void** and **release(): Promise<void>** APIs in **CameraInput**.

2. Deprecated the **CameraInputErrorCode** enums and all their values: **ERROR_UNKNOWN** = **-1**, **ERROR_NO_PERMISSION** = **0**, **ERROR_DEVICE_PREEMPTED** = **1**, **ERROR_DEVICE_DISCONNECTED** = **2**, **ERROR_DEVICE_IN_USE** = **3**, **ERROR_DRIVER_ERROR** = **4**

3. Deprecated the **CameraInputError** API and its attribute **CameraInputErrorCode**.

4. Deprecated the **CaptureSessionErrorCode** enums and all their values: **ERROR_UNKNOWN** = **-1**, **ERROR_INSUFFICIENT_RESOURCES** = **0**, **ERROR_TIMEOUT** = **1**

5. Deprecated the **CaptureSessionError** API and its attribute **CaptureSessionErrorCode**.

6. Deprecated the **PreviewOutputErrorCode** enum and its value: **ERROR_UNKNOWN** = **-1**

7. Deprecated the **PreviewOutputError** API and its attribute **PreviewOutputErrorCode**.

8. Deprecated the **PhotoOutputErrorCode** enums and all their values: **ERROR_UNKNOWN** = **-1**, **ERROR_DRIVER_ERROR** = **0**, **ERROR_INSUFFICIENT_RESOURCES** = **1**, **ERROR_TIMEOUT** = **2**

9. Deprecated the **PhotoOutputError** API and its attribute **PhotoOutputErrorCode**.

10. Deprecated the **VideoOutputErrorCode** enums and all their values: **ERROR_UNKNOWN** = **-1**, **ERROR_DRIVER_ERROR** = **0**

11. Deprecated the **VideoOutputError** API and its attribute **VideoOutputErrorCode**.

12. Deprecated **getType(callback: AsyncCallback<MetadataObjectType>): void** in the **MetadataObject** API.

13. Deprecated **getType(): Promise<MetadataObjectType>** in the **MetadataObject** API.

14. Deprecated **getTimestamp(callback: AsyncCallback<number>): void** in the **MetadataObject** API.

15. Deprecated **getTimestamp(): Promise<number>** in the **MetadataObject** API.

16. Deprecated **getBoundingBox(callback: AsyncCallback<Rect>): void** in the **MetadataObject** API.

17. Deprecated **getBoundingBox(): Promise<Rect>** in the **MetadataObject** API.

18. Deprecated the **MetadataOutputErrorCode** enums and all their values: **ERROR_UNKNOWN** = **-1**, **ERROR_INSUFFICIENT_RESOURCES** = **0**

19. Deprecated the **MetadataOutputError** API and its attribute **MetadataOutputErrorCode**.

**Changed APIs**

1. Changed the return modes of the **getCameraManager** API in the camera module from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getCameraManager(context: Context, callback: AsyncCallback<CameraManager>): void** and **getCameraManager(context: Context): Promise<CameraManager>** are changed to **getCameraManager(context: Context): CameraManager**.

   The sample code is as follows:

   ```
   let cameraManager = camera.getCameraManager(context);
   ```

2. Changed the return modes of the **getSupportedCameras** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void** and **getSupportedCameras(): Promise<Array<CameraDevice>>** are changed to **getSupportedCameras(): Array<CameraDevice>**.

   The sample code is as follows:

   ```
   let cameras = cameraManager.getSupportedCameras();
   ```

3. Changed the return modes of the **getSupportedOutputCapability** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void** and **getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>** are changed to **getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability**.

   The sample code is as follows:

   ```
   let cameraDevice = cameras[0];
   let CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);
   ```

4. Changed the return modes of the **createCameraInput(camera: CameraDevice)** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void** and **createCameraInput(camera: CameraDevice): Promise<CameraInput>** are changed to **createCameraInput(camera: CameraDevice): CameraInput**.

   The sample code is as follows:

   ```
   let cameraDevice = cameras[0];
   let cameraInput = cameraManager.createCameraInput(cameraDevice);
   ```

5. Changed the return modes of the **createCameraInput(position: CameraPosition, type: CameraType)** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput>): void** and **createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput>** are changed to **createCameraInput(position: CameraPosition, type: CameraType): CameraInput**.

   The sample code is as follows:

   ```
   let cameraDevice = cameras[0];
   let position = cameraDevice.cameraPosition;
   let type = cameraDevice.cameraType;
   let cameraInput = cameraManager.createCameraInput(position, type);
   ```

6. Changed the return modes of the **createPreviewOutput** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void** and **createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>** are changed to **createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput**.

   The sample code is as follows:

   ```
   let profile = cameraoutputcapability.previewProfiles[0];
   let previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
   ```

7. Changed the return modes of the **createPhotoOutput** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void** and **createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>** are changed to **createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput**.

   The sample code is as follows:

   ```
   let profile = cameraoutputcapability.photoProfiles[0];
   let photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
   ```

8. Changed the return modes of the **createVideoOutput** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void** and **createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>** are changed to **createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput**.

   The sample code is as follows:

   ```
   let profile = cameraoutputcapability.videoProfiles[0];
   let videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
   ```

9. Changed the return modes of the **createMetadataOutput** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void** and **createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>** are changed to **createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): MetadataOutput**.

   The sample code is as follows:

   ```
   let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
   let metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
   ```

10. Changed the return modes of the **createCaptureSession** API in CameraManager from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **createCaptureSession(callback: AsyncCallback<CaptureSession>): void** and **createCaptureSession(): Promise<CaptureSession>** are changed to **createCaptureSession(): CaptureSession**.

    The sample code is as follows:

    ```
    let captureSession = cameraManager.createCaptureSession();
    ```

11. Changed the enum **CAMERA_TYPE_UNSPECIFIED** of **CameraType** to **CAMERA_TYPE_DEFAULT**.

12. Changed the return value type of the **on** API in CameraInput from **CameraInputError** to **BusinessError**. Therefore, the original API **on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void** is changed to **on(type: 'error', camera: CameraDevice, callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    let cameraDevice = cameras[0];
    cameraInput.on('error', cameraDevice, (BusinessError) => {

    })
    ```

13. Changed the return modes of the **beginConfig** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **beginConfig(callback: AsyncCallback<void>): void** and **beginConfig(): Promise<void>** are changed to **beginConfig(): void**.

    The sample code is as follows:

    ```
    captureSession.beginConfig();
    ```

14. Changed the return modes of the **addInput** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **addInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void** and **addInput(cameraInput: CameraInput): Promise<void>** are changed to **addInput(cameraInput: CameraInput): void**.

    The sample code is as follows:

    ```
    captureSession.addInput(cameraInput);
    ```

15. Changed the return modes of the **removeInput** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **removeInput(cameraInput: CameraInput, callback: AsyncCallback<void>): void** and **removeInput(cameraInput: CameraInput): Promise<void>** are changed to **removeInput(cameraInput: CameraInput): void**.

    The sample code is as follows:

    ```
    captureSession.removeInput(cameraInput);
    ```

16. Changed the return modes of the **addOutput** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void** and **addOutput(cameraOutput: CameraOutput): Promise<void>** are changed to **addOutput(cameraOutput: CameraOutput): void**.

    The sample code is as follows:

    ```
    captureSession.addOutput(previewOutput);
    ```

17. Changed the return modes of the **removeOutput** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void** and **removeOutput(cameraOutput: CameraOutput): Promise<void>** are changed to **removeOutput(cameraOutput: CameraOutput): void**.

    The sample code is as follows:

    ```
    captureSession.removeOutput(previewOutput);
    ```

18. Changed the return modes of the **hasFlash** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **hasFlash(callback: AsyncCallback<boolean>): void** and **hasFlash(): Promise<boolean>** are changed to **hasFlash(): boolean**.

    The sample code is as follows:

    ```
    let status = captureSession.hasFlash();
    ```

19. Changed the return modes of the **isFlashModeSupported** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void** and **isFlashModeSupported(flashMode: FlashMode): Promise<boolean>** are changed to **isFlashModeSupported(flashMode: FlashMode): boolean**.

    The sample code is as follows:

    ```
    let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
    ```

20. Changed the return modes of the **getFlashMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getFlashMode(callback: AsyncCallback<FlashMode>): void** and **getFlashMode(): Promise<FlashMode>** are changed to **getFlashMode(): FlashMode**.

    The sample code is as follows:

    ```
    let flashMode = captureSession.getFlashMode();
    ```

21. Changed the return modes of the **isExposureModeSupported** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void** and **isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>** are changed to **isExposureModeSupported(aeMode: ExposureMode): boolean**.

    The sample code is as follows:

    ```
    let isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
    ```

22. Changed the return modes of the **getExposureMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getExposureMode(callback: AsyncCallback<ExposureMode>): void** and **getExposureMode(): Promise<ExposureMode>** are changed to **getExposureMode(): ExposureMode**.

    The sample code is as follows:

    ```
    let exposureMode = captureSession.getExposureMode();
    ```

23. Changed the return modes of the **setExposureMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void** and **setExposureMode(aeMode: ExposureMode): Promise<void>** are changed to **setExposureMode(aeMode: ExposureMode): void**.

    The sample code is as follows:

    ```
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
    ```

24. Changed the return modes of the **getMeteringPoint** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getMeteringPoint(callback: AsyncCallback<Point>): void** and **getMeteringPoint(): Promise<Point>** are changed to **getMeteringPoint(): Point**.

    The sample code is as follows:

    ```
    let exposurePoint = captureSession.getMeteringPoint();
    ```

25. Changed the return modes of the **setMeteringPoint** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setMeteringPoint(point: Point, callback: AsyncCallback<void>): void** and **setMeteringPoint(point: Point): Promise<void>** are changed to **setMeteringPoint(point: Point): void**.

    The sample code is as follows:

    ```
    let Point2 = {x: 2, y: 2};
    captureSession.setMeteringPoint(Point2);
    ```

26. Changed the return modes of the **getExposureBiasRange** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getExposureBiasRange(callback: AsyncCallback<Array<number>>): void** and **getExposureBiasRange(): Promise<Array<number>>** are changed to **getExposureBiasRange(): Array<number>**.

    The sample code is as follows:

    ```
    let biasRangeArray = captureSession.getExposureBiasRange();
    ```

27. Changed the return modes of the **setExposureBias** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void** and **setExposureBias(exposureBias: number): Promise<void>** are changed to **setExposureBias(exposureBias: number): void**.

    The sample code is as follows:

    ```
    let exposureBias = biasRangeArray[0];
    captureSession.setExposureBias(exposureBias);
    ```

28. Changed the return modes of the **getExposureValue** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getExposureValue(callback: AsyncCallback<number>): void** and **getExposureValue(): Promise<number>** are changed to **getExposureValue(): number**.

    The sample code is as follows:

    ```
    let exposureValue = captureSession.getExposureValue();
    ```

29. Changed the return modes of the **isFocusModeSupported** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void** and **isFocusModeSupported(afMode: FocusMode): Promise<boolean>** are changed to **isFocusModeSupported(afMode: FocusMode): boolean**.

    The sample code is as follows:

    ```
    let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
    ```

30. Changed the return modes of the **getFocusMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getFocusMode(callback: AsyncCallback<FocusMode>): void** and **getFocusMode(): Promise<FocusMode>** are changed to **getFocusMode(): FocusMode**.

    The sample code is as follows:

    ```
    let afMode = captureSession.getFocusMode();
    ```

31. Changed the return modes of the **setFocusMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void** and **setFocusMode(afMode: FocusMode): Promise<void>** are changed to **setFocusMode(afMode: FocusMode): void**.

    The sample code is as follows:

    ```
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
    ```

32. Changed the return modes of the **setFocusPoint** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setFocusPoint(point: Point, callback: AsyncCallback<void>): void** and **setFocusPoint(point: Point): Promise<void>** are changed to **setFocusPoint(point: Point): void**.

    The sample code is as follows:

    ```
    let Point2 = {x: 2, y: 2};
    captureSession.setFocusPoint(Point2);
    ```

33. Changed the return modes of the **getFocusPoint** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getFocusPoint(callback: AsyncCallback<Point>): void** and **getFocusPoint(): Promise<Point>** are changed to **getFocusPoint(): Point**.

    The sample code is as follows:

    ```
    let point = captureSession.getFocusPoint();
    ```

34. Changed the return modes of the **getFocalLength** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getFocalLength(callback: AsyncCallback<number>): void** and **getFocalLength(): Promise<number>** are changed to **getFocalLength(): number**.

    The sample code is as follows:

    ```
    let focalLength = captureSession.getFocalLength();
    ```

35. Changed the return modes of the **getZoomRatioRange** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getZoomRatioRange(callback: AsyncCallback<Array<number>>): void** and **getZoomRatioRange(): Promise<Array<number>>** are changed to **getZoomRatioRange(): Array<number>**.

    The sample code is as follows:

    ```
    let zoomRatioRange = captureSession.getZoomRatioRange();
    ```

36. Changed the return modes of the **getZoomRatio** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getZoomRatio(callback: AsyncCallback<number>): void** and **getZoomRatio(): Promise<number>** are changed to **getZoomRatio(): number**.

    The sample code is as follows:

    ```
    let zoomRatio = captureSession.getZoomRatio();
    ```

37. Changed the return modes of the **setZoomRatio** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void** and **setZoomRatio(zoomRatio: number): Promise<void>** are changed to **setZoomRatio(zoomRatio: number): void**.

    The sample code is as follows:

    ```
    let zoomRatio = zoomRatioRange[0];
    captureSession.setZoomRatio(zoomRatio);
    ```

38. Changed the return modes of the **isVideoStabilizationModeSupported** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void** and **isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>** are changed to **isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean**.

    The sample code is as follows:

    ```
    let isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
    ```

39. Changed the return modes of the **getActiveVideoStabilizationMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void** and **getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>** are changed to **getActiveVideoStabilizationMode(): VideoStabilizationMode**.

    The sample code is as follows:

    ```
    let vsMode = captureSession.getActiveVideoStabilizationMode();
    ```

40. Changed the return modes of the **setVideoStabilizationMode** API in CaptureSession from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void** and **setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>** are changed to **setVideoStabilizationMode(mode: VideoStabilizationMode): void**.

    The sample code is as follows:

    ```
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
    ```

41. Changed the **on(type:'error') callback** type in CaptureSession from **ErrorCallback<CaptureSessionError>** to **ErrorCallback<BusinessError>**. Therefore, the original API **on(type: 'error', callback: ErrorCallback<CaptureSessionError>): void** is changed to **on(type: 'error', callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    captureSession.on('error', (BusinessError) => {

    })
    ```

42. Changed the **on(type:'error') callback** type in PreviewOutput, from **ErrorCallback<PreviewOutputError>** to **ErrorCallback<BusinessError>**. Therefore, the original API **on(type: 'error', callback: ErrorCallback<PreviewOutputError>): void** is changed to **on(type: 'error', callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    previewOutput.on('error', (BusinessError) => {

    })
    ```

43. Changed the return modes of the **isMirrorSupported** API in PhotoOutput from asynchronous callback and asynchronous promise to the synchronous mode. Therefore, the original APIs **isMirrorSupported(callback: AsyncCallback<boolean>): void** and **isMirrorSupported(): Promise<boolean>** are changed to **isMirrorSupported(): boolean**.

    The sample code is as follows:

    ```
    let isSupported = photoOutput.isMirrorSupported();
    ```

44. Changed the **on(type:'error') callback** type in PhotoOutput, from **ErrorCallback<PhotoOutputError>** to **ErrorCallback<BusinessError>**. Therefore, the original API **on(type: 'error', callback: ErrorCallback<PhotoOutputError>): void** is changed to **on(type: 'error', callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    PhotoOutput.on('error', (BusinessError) => {

    })
    ```

45. Changed the **on(type:'error') callback** type in VideoOutput, from **ErrorCallback<VideoOutputError>** to **ErrorCallback<BusinessError>**. Therefore, the original API **on(type: 'error', callback: ErrorCallback<VideoOutputError>): void** is changed to **on(type: 'error', callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    VideoOutput.on('error', (BusinessError) => {

    })
    ```

46. Changed the **on(type:'error') callback** type in MetadataOutput, from **ErrorCallback<MetadataOutputError>** to **ErrorCallback<BusinessError>**. Therefore, the original API **on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void** is changed to **on(type: 'error', callback: ErrorCallback<BusinessError>): void**.

    The sample code is as follows:

    ```
    MetadataOutput.on('error', (BusinessError) => {

    })
    ```