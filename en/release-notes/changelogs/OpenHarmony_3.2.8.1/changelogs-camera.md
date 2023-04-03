# ChangeLog of JS API Changes in the Multimedia Subsystem

Compared with OpenHarmony 3.2 Beta3, OpenHarmony 3.2 Beta4 has the following changes in APIs of the camera component in the multimedia subsystem.

## Camera API Changes
Some functional APIs are added and some others are deprecated to:
1. Improve the usability of camera APIs.
2. Help you quickly understand camera APIs and use them for development.
3. Facilitate expansion of framework functions in later versions, and reduce coupling between framework modules.

You need to refer to the following change description to adapt your application.

**Change Impacts**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module                | Class                   | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ---------------------- | ----------------------- | ------------------------------------------------------------ | -------- |
| ohos.multimedia.camera | Profile                 | readonly format:CameraFormat;                                | Added    |
| ohos.multimedia.camera | Profile                 | readonly size: Size;                                         | Added    |
| ohos.multimedia.camera | FrameRateRange          | readonly min: number;                                        | Added    |
| ohos.multimedia.camera | FrameRateRange          | readonly max: number;                                        | Added    |
| ohos.multimedia.camera | VideoProfile            | readonly frameRateRange: FrameRateRange;                     | Added    |
| ohos.multimedia.camera | CameraOutputCapability  | readonly previewProfiles: Array<Profile>;                    | Added    |
| ohos.multimedia.camera | CameraOutputCapability  | readonly photoProfiles: Array<Profile>;                      | Added    |
| ohos.multimedia.camera | CameraOutputCapability  | readonly videoProfiles: Array<VideoProfile>;                 | Added    |
| ohos.multimedia.camera | CameraOutputCapability  | readonly supportedMetadataObjectTypes: Array<MetadataObjectType>; | Added    |
| ohos.multimedia.camera | CameraManager           | getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void;<br>getSupportedCameras(): Promise<Array<CameraDevice>>; | Added    |
| ohos.multimedia.camera | CameraManager           | getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;<br>getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>; | Added    |
| ohos.multimedia.camera | CameraManager           | isCameraMuted(): boolean;                                    | Added    |
| ohos.multimedia.camera | CameraManager           | isCameraMuteSupported(): boolean;                            | Added    |
| ohos.multimedia.camera | CameraManager           | muteCamera(mute: boolean): void;                             | Added    |
| ohos.multimedia.camera | CameraManager           | createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;<br>createCameraInput(camera: CameraDevice): Promise<CameraInput>; | Added    |
| ohos.multimedia.camera | CameraManager           | createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br>createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>; | Added    |
| ohos.multimedia.camera | CameraManager           | createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br>createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>; | Added    |
| ohos.multimedia.camera | CameraManager           | createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br>createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>; | Added    |
| ohos.multimedia.camera | CameraManager           | createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;<br>createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>; | Added    |
| ohos.multimedia.camera | CameraManager           | createCaptureSession(callback: AsyncCallback<CaptureSession>): void;<br>createCaptureSession(): Promise<CaptureSession>; | Added    |
| ohos.multimedia.camera | CameraManager           | on(type: 'cameraMute', callback: AsyncCallback<boolean>): void; | Added    |
| ohos.multimedia.camera | CameraManager           | getCameras(callback: AsyncCallback<Array<Camera>>): void;<br>getCameras(): Promise<Array<Camera>>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput>): void;<br>createCameraInput(cameraId: string): Promise<CameraInput>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | createCaptureSession(context: Context, callback: AsyncCallback<CaptureSession>): void;<br>createCaptureSession(context: Context): Promise<CaptureSession>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;<br>createPreviewOutput(surfaceId: string): Promise<PreviewOutput>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | CreatePhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;<br>CreatePhotoOutput(surfaceId: string): Promise<PhotoOutput>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput>): void;<br>createVideoOutput(surfaceId: string): Promise<VideoOutput>; | Deprecated    |
| ohos.multimedia.camera | CameraManager           | createMetadataOutput(callback: AsyncCallback<MetadataOutput>): void;<br>createVideoOutput(): Promise<MetadataOutput>; | Deprecated    |
| ohos.multimedia.camera | CameraStatusInfo        | camera: CameraDevice;                                        | Added    |
| ohos.multimedia.camera | CameraStatusInfo        | camera: Camera;                                              | Deprecated    |
| ohos.multimedia.camera | CameraDevice            | interface CameraDevice                                       | Added    |
| ohos.multimedia.camera | Camera                  | interface Camera                                             | Deprecated    |
| ohos.multimedia.camera | CameraInput             | open(callback: AsyncCallback<void>): void;<br>open(): Promise<void>; | Added    |
| ohos.multimedia.camera | CameraInput             | close(callback: AsyncCallback<void>): void;<br>close(): Promise<void>; | Added    |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void; | Added    |
| ohos.multimedia.camera | CameraInput             | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise<boolean>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br>getFocusMode(): Promise<FocusMode>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br>setFocusMode(afMode: FocusMode): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br>getZoomRatioRange(): Promise<Array<number>>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | getZoomRatio(callback: AsyncCallback<number>): void;<br>getZoomRatio(): Promise<number>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br>setZoomRatio(zoomRatio: number): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | getCameraId(callback: AsyncCallback<string>): void;<br>getCameraId(): Promise<string>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | getExposurePoint(callback: AsyncCallback<Point>): void;<br>getExposurePoint(): Promise<Point>; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | setExposurePoint(exposurePoint: Point, callback: AsyncCallback<void>): void;<br>setExposurePoint(exposurePoint: Point): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | CameraInput          | hasFlash(callback: AsyncCallback<boolean>): void;<br>hasFlash(): Promise<boolean>;                                                                         | Deprecated    |
| ohos.multimedia.camera | CameraInput          | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;       | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getFlashMode(callback: AsyncCallback<FlashMode>): void;<br>getFlashMode(): Promise<FlashMode>;                                                             | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise<void>;                             | Deprecated    |
| ohos.multimedia.camera | CameraInput          | isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>; | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br>getExposureMode(): Promise<ExposureMode>;                                                 | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br>setExposureMode(aeMode: ExposureMode): Promise<void>;                       | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getMeteringPoint(callback: AsyncCallback<Point>): void;<br>getMeteringPoint(): Promise<Point>;                                                             | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br>setMeteringPoint(point: Point): Promise<void>;                                     | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br>getExposureBiasRange(): Promise<Array<number>>;                                     | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br>setExposureBias(exposureBias: number): Promise<void>;                       | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getExposureValue(callback: AsyncCallback<number>): void;<br>getExposureValue(): Promise<number>;                                                           | Deprecated    |
| ohos.multimedia.camera | CameraInput          | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;             | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br>getFocusMode(): Promise<FocusMode>;                                                             | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br>setFocusMode(afMode: FocusMode): Promise<void>;                                   | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br>setFocusPoint(point: Point): Promise<void>;                                           | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getFocusPoint(callback: AsyncCallback<Point>): void;<br>getFocusPoint(): Promise<Point>;                                                                   | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getFocalLength(callback: AsyncCallback<number>): void;<br>getFocalLength(): Promise<number>;                                                               | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br>getZoomRatioRange(): Promise<Array<number>>;                                           | Deprecated    |
| ohos.multimedia.camera | CameraInput          | getZoomRatio(callback: AsyncCallback<number>): void;<br>getZoomRatio(): Promise<number>;                                                                   | Deprecated    |
| ohos.multimedia.camera | CameraInput          | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br>setZoomRatio(zoomRatio: number): Promise<void>;                                   | Deprecated    |
| ohos.multimedia.camera | CameraInput             | on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | on(type: 'exposureStateChange', callback: AsyncCallback<ExposureState>): void; | Deprecated    |
| ohos.multimedia.camera | CameraInput             | on(type: 'error', callback: ErrorCallback<CameraInputError>): void; | Deprecated    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_NO_PERMISSION = 0                                      | Added    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_PREEMPTED = 1                                   | Added    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_DISCONNECTED = 2                                | Added    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DEVICE_IN_USE = 3                                      | Added    |
| ohos.multimedia.camera | CameraInputErrorCode    | ERROR_DRIVER_ERROR = 4                                       | Added    |
| ohos.multimedia.camera | CameraFormat            | CAMERA_FORMAT_RGBA_8888 = 3                                  | Added    |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_AUTO = 1                                       | Added    |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_CONTINUOUS_AUTO = 2                            | Added    |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_AUTO                                      | Deprecated    |
| ohos.multimedia.camera | ExposureMode            | EXPOSURE_MODE_CONTINUOUS_AUTO                          | Deprecated    |
| ohos.multimedia.camera | VideoStabilizationMode  | LOW = 1                                                      | Added    |
| ohos.multimedia.camera | VideoStabilizationMode  | MIDDLE = 2                                                   | Added    |
| ohos.multimedia.camera | VideoStabilizationMode  | HIGH = 3                                                     | Added    |
| ohos.multimedia.camera | VideoStabilizationMode  | AUTO = 4                                                     | Added    |
| ohos.multimedia.camera | VideoStabilizationMode  | LOW                                                    | Deprecated    |
| ohos.multimedia.camera | VideoStabilizationMode  | MIDDLE                                                 | Deprecated    |
| ohos.multimedia.camera | VideoStabilizationMode  | HIGH                                                     | Deprecated    |
| ohos.multimedia.camera | VideoStabilizationMode  | AUTO                                                     | Deprecated    |
| ohos.multimedia.camera | CaptureSession          | addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>addOutput(cameraOutput: CameraOutput): Promise<void>; | Added    |
| ohos.multimedia.camera | CaptureSession          | removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>removeOutput(cameraOutput: CameraOutput): Promise<void>; | Added    |
| ohos.multimedia.camera | CaptureSession          | isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean>): void;<br>isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean>; | Added    |
| ohos.multimedia.camera | CaptureSession          | getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode>): void;<br>getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode>; | Added    |
| ohos.multimedia.camera | CaptureSession          | setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void>): void;<br>setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void>; | Added    |
| ohos.multimedia.camera | CaptureSession          | on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void; | Added    |
| ohos.multimedia.camera | CaptureSession          | hasFlash(callback: AsyncCallback<boolean>): void;<br>hasFlash(): Promise<boolean>;                                                                         | Added    |
| ohos.multimedia.camera | CaptureSession          | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;       | Added    |
| ohos.multimedia.camera | CaptureSession          | getFlashMode(callback: AsyncCallback<FlashMode>): void;<br>getFlashMode(): Promise<FlashMode>;                                                             | Added    |
| ohos.multimedia.camera | CaptureSession          | setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise<void>;                             | Added    |
| ohos.multimedia.camera | CaptureSession          | isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>; | Added    |
| ohos.multimedia.camera | CaptureSession          | getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br>getExposureMode(): Promise<ExposureMode>;                                                 | Added    |
| ohos.multimedia.camera | CaptureSession          | setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br>setExposureMode(aeMode: ExposureMode): Promise<void>;                       | Added    |
| ohos.multimedia.camera | CaptureSession          | getMeteringPoint(callback: AsyncCallback<Point>): void;<br>getMeteringPoint(): Promise<Point>;                                                             | Added    |
| ohos.multimedia.camera | CaptureSession          | setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br>setMeteringPoint(point: Point): Promise<void>;                                     | Added    |
| ohos.multimedia.camera | CaptureSession          | getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br>getExposureBiasRange(): Promise<Array<number>>;                                     | Added    |
| ohos.multimedia.camera | CaptureSession          | setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br>setExposureBias(exposureBias: number): Promise<void>;                       | Added    |
| ohos.multimedia.camera | CaptureSession          | getExposureValue(callback: AsyncCallback<number>): void;<br>getExposureValue(): Promise<number>;                                                           | Added    |
| ohos.multimedia.camera | CaptureSession          | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;             | Added    |
| ohos.multimedia.camera | CaptureSession          | getFocusMode(callback: AsyncCallback<FocusMode>): void;<br>getFocusMode(): Promise<FocusMode>;                                                             | Added    |
| ohos.multimedia.camera | CaptureSession          | setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br>setFocusMode(afMode: FocusMode): Promise<void>;                                   | Added    |
| ohos.multimedia.camera | CaptureSession          | setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br>setFocusPoint(point: Point): Promise<void>;                                           | Added    |
| ohos.multimedia.camera | CaptureSession          | getFocusPoint(callback: AsyncCallback<Point>): void;<br>getFocusPoint(): Promise<Point>;                                                                   | Added    |
| ohos.multimedia.camera | CaptureSession          | getFocalLength(callback: AsyncCallback<number>): void;<br>getFocalLength(): Promise<number>;                                                               | Added    |
| ohos.multimedia.camera | CaptureSession          | getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br>getZoomRatioRange(): Promise<Array<number>>;                                           | Added    |
| ohos.multimedia.camera | CaptureSession          | getZoomRatio(callback: AsyncCallback<number>): void;<br>getZoomRatio(): Promise<number>;                                                                   | Added    |
| ohos.multimedia.camera | CaptureSession          | setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br>setZoomRatio(zoomRatio: number): Promise<void>;                                   | Added    |
| ohos.multimedia.camera | CaptureSession          | addOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br>addOutput(previewOutput: PreviewOutput): Promise<void>;<br>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br>addOutput(photoOutput: PhotoOutput): Promise<void>;<br>addOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br>addOutput(videoOutput: VideoOutput): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | CaptureSession          | removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br>removeOutput(previewOutput: PreviewOutput): Promise<void>;<br>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br>removeOutput(photoOutput: PhotoOutput): Promise<void>;removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br>removeOutput(videoOutput: VideoOutput): Promise<void>;<br>removeOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br>removeOutput(metadataOutput: MetadataOutput): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_INSUFFICIENT_RESOURCES = 0                             | Added    |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_TIMEOUT = 1                                            | Added    |
| ohos.multimedia.camera | CameraOutput            | release(callback: AsyncCallback<void>): void;<br>release(): Promise<void>; | Added    |
| ohos.multimedia.camera | PreviewOutput           | start(callback: AsyncCallback<void>): void;<br>start(): Promise<void>; | Added    |
| ohos.multimedia.camera | PreviewOutput           | stop(callback: AsyncCallback<void>): void;<br>stop(): Promise<void>; | Added    |
| ohos.multimedia.camera | PreviewOutput           | release(callback: AsyncCallback<void>): void;<br>release(): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | PhotoOutput             | release(callback: AsyncCallback<void>): void;<br>release(): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | VideoOutput             | release(callback: AsyncCallback<void>): void;<br>release(): Promise<void>; | Deprecated    |
| ohos.multimedia.camera | PhotoCaptureSetting     | mirror?: boolean;                                            | Added    |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_DRIVER_ERROR = 0                                       | Added    |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_INSUFFICIENT_RESOURCES = 1                             | Added    |
| ohos.multimedia.camera | PhotoOutputErrorCode    | ERROR_TIMEOUT = 2                                            | Added    |
| ohos.multimedia.camera | VideoOutputErrorCode    | ERROR_DRIVER_ERROR = 0                                       | Added    |
| ohos.multimedia.camera | MetadataObjectType      | FACE_DETECTION = 0                                           | Added    |
| ohos.multimedia.camera | MetadataObjectType      | FACE = 0                                                 | Deprecated    |
| ohos.multimedia.camera | MetadataOutput          | on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void; | Added    |
| ohos.multimedia.camera | MetadataOutput      | setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<void>): void;<br>setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>): Promise<void>;    | Deprecated    |
| ohos.multimedia.camera | MetadataOutput      | getSupportedMetadataObjectTypes(callback: AsyncCallback<Array<MetadataObjectType>>): void;<br>getSupportedMetadataObjectTypes(): Promise<Array<MetadataObjectType>>;    | Deprecated    |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_UNKNOWN = -1                                           | Added    |
| ohos.multimedia.camera | MetadataOutputErrorCode | ERROR_INSUFFICIENT_RESOURCES = 0                             | Added    |
| ohos.multimedia.camera | MetadataOutputError     | code: MetadataOutputErrorCode;                              | Added    |

**Adaptation Guide**

In addition to new APIs and deprecated APIs, you need to adapt your application to changed APIs.

In Beta4 and later versions, the following APIs are changed.

**New APIs**

1. **Profile** API

   Attribute 1: readonly format; type: CameraFormat

   Attribute 2: readonly size; type: Size

2. **FrameRateRange** API

   Attribute 1: readonly min; type: number

   Attribute 2: readonly max; type: number

3. **VideoProfile** API (inherited from **Profile**)

   Attribute: readonly frameRateRange; type: FrameRateRange

4. **CameraOutputCapability** API

   Attribute 1: readonly previewProfiles; type: Array<Profile>

   Attribute 2: readonly photoProfiles; type: Array<Profile>

   Attribute 3: readonly videoProfiles; type: Array<VideoProfile>

   Attribute 4: readonly supportedMetadataObjectTypes; type: Array<MetadataObjectType>

5. The following APIs are added to **CameraManager**:

   getSupportedOutputCapability(camera: CameraDevice, callback: AsyncCallback<CameraOutputCapability>): void;

   getSupportedOutputCapability(camera: CameraDevice): Promise<CameraOutputCapability>;

   The sample code is as follows:

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

6. The **isCameraMuted(): boolean;** API is added to **CameraManager**.

   The sample code is as follows:

   ```
   let ismuted = cameraManager.isCameraMuted();
   ```

7. The **isCameraMuteSupported(): boolean;** API is added to **CameraManager**.

   The sample code is as follows:

   ```
   let ismutesuppotred = cameraManager.isCameraMuteSupported();
   ```

8. The **muteCamera(mute: boolean): void;** API is added to **CameraManager**.

   The sample code is as follows:

   ```
   let mute = true;
   cameraManager.muteCamera(mute);
   ```

9. The **on(type: 'cameraMute', callback: AsyncCallback<boolean>): void;** API is added to **CameraManager**.

   The sample code is as follows:

   ```
   cameraManager.on('cameraMute', (err, curMuetd) => {
       if (err) {
           console.error(`Failed to get cameraMute callback. ${err.message}`);
           return;
       }
   })
   ```

10. The **open(callback: AsyncCallback<void>): void;** and **open(): Promise<void>;** APIs are added to **CameraInput**.

The sample code is as follows:

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

11. The **close(callback: AsyncCallback<void>): void;** and **close(): Promise<void>;** APIs are added to **CameraInput**.

    The sample code is as follows:

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

12. The following enumerations are added to **CameraInputErrorCode**:

    Enumeration: ERROR_NO_PERMISSION; value: 0

    Enumeration: ERROR_DEVICE_PREEMPTED; value: 1

    Enumeration: ERROR_DEVICE_DISCONNECTED; value: 2

    Enumeration: ERROR_DEVICE_IN_USE; value: 3

    Enumeration: ERROR_DRIVER_ERROR; value: 4

13. The following enumeration is added to **CameraFormat**:

    Enumeration: CAMERA_FORMAT_RGBA_8888; value: 3

14. The **getMeteringPoint(callback: AsyncCallback<Point>): void;** and **getMeteringPoint(): Promise<Point>;** APIs are added to **CaptureSession**.

    The sample code is as follows:

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

15. The **setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;** and **setMeteringPoint(point: Point): Promise<void>;** APIs are added to **CaptureSession**.

    The sample code is as follows:

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

16. The following enumerations are added to **CaptureSessionErrorCode**:

    Enumeration: ERROR_INSUFFICIENT_RESOURCES; value: 0

    Enumeration: ERROR_TIMEOUT; value: 1

17. The **CameraOutput** API is added and contains the **release(callback: AsyncCallback<void>): void;** and **release(): Promise<void>;** methods.

    The sample code (for **previewOutput**) is as follows:

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

18. The **start(callback: AsyncCallback<void>): void;** and **start(): Promise<void>;** APIs are added to **PreviewOutput**.

    The sample code is as follows:

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

19. The **stop(callback: AsyncCallback<void>): void;** and **stop(): Promise<void>;** APIs are added to **PreviewOutput**.

    The sample code is as follows:

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

20. **PhotoCaptureSetting** API

    Attribute 1: mirror?; type: boolean

21. The following enumerations are added to **PhotoOutputErrorCode**:

    Enumeration: ERROR_DRIVER_ERROR; value: 0

    Enumeration: ERROR_INSUFFICIENT_RESOURCES; value: 1

    Enumeration: ERROR_TIMEOUT; value: 2

22. The following enumeration is added to **VideoOutputErrorCode**:

    Enumeration: ERROR_DRIVER_ERROR; value: 0

23. The **on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void;** API is added to **MetadataOutput**.

    The sample code is as follows:

    ```
    metadataOutput.on('error', (metadataOutputError) => {
        console.log(`Metadata output error code: ${metadataOutputError.code}`);
    })
    ```

24. The following enumerations are added to **MetadataOutputErrorCode**.

    Enumeration: ERROR_UNKNOWN; value: -1

    Enumeration: ERROR_INSUFFICIENT_RESOURCES; value: 0

25. **MetadataOutputError** API

    Attribute: code; value: MetadataOutputErrorCode

**Deprecated APIs**

1. The **on(type: 'exposureStateChange', callback: AsyncCallback<ExposureState>): void;** API in **CameraInput** is deprecated.

2. The **release(callback: AsyncCallback<void>): void;** and **release(): Promise<void>;** APIs in **previewOutput** are deprecated.

3. The following APIs in **metadataOutput** are deprecated:

   setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<void>): void;<br>setCapturingMetadataObjectTypes(metadataObjectTypes: Array<MetadataObjectType>): Promise<void>;

4. The following APIs in **metadataOutput** are deprecated:

   getSupportedMetadataObjectTypes(callback: AsyncCallback<Array<MetadataObjectType>>): void;<br>getSupportedMetadataObjectTypes(): Promise<Array<MetadataObjectType>>;

5. The **release(callback: AsyncCallback<void>): void;** and **release(): Promise<void>;** APIs in **PreviewOutput** are deprecated.

6. The **release(callback: AsyncCallback<void>): void;** and **release(): Promise<void>;** APIs in **PhotoOutput** are deprecated.

7. The **release(callback: AsyncCallback<void>): void;** and **release(): Promise<void>;** APIs in **VideoOutput** are deprecated.

8. The **getCameraId(callback: AsyncCallback<string>): void;** and **getCameraId(): Promise<string>;** APIs in **CameraInput** are deprecated.

9. The **getExposurePoint(callback: AsyncCallback<Point>): void;** and **getExposurePoint(): Promise<Point>;** APIs in **CameraInput** are deprecated.

10. The **setExposurePoint(exposurePoint: Point, callback: AsyncCallback<void>): void;** and **setExposurePoint(exposurePoint: Point): Promise<void>;** APIs in **CameraInput** are deprecated.

**Changed APIs**

1. In **CameraManager**, the return value of **getCameras** is changed from **Array<Camera>** to **Array<CameraDevice>**, and the API name is changed from **getCameras** to **getSupportedCameras**. Therefore, the **getCameras(callback: AsyncCallback<Array<Camera>>): void;** and **getCameras(): Promise<Array<Camera>>;** APIs are changed to **getSupportedCameras(callback: AsyncCallback<Array<CameraDevice>>): void** and **getSupportedCameras(): Promise<Array<CameraDevice>>;**.

   The sample code is as follows:

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

2. In **CameraManager**, the input parameter of **createCameraInput** is changed from **cameraId: string** to **camera: CameraDevice**. Therefore, the **createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput>): void;** and **createCameraInput(cameraId: string): Promise<CameraInput>;** APIs are changed to **createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput>): void;** and **createCameraInput(camera: CameraDevice): Promise<CameraInput>;**.

   The sample code is as follows:

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

3. In **CameraManager**, the input parameter **profile: Profile** is added to **createPreviewOutput** and the **profile** parameter is obtained by the **getSupportedOutputCapability** API. Therefore, the **createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;** and **createPreviewOutput(surfaceId: string): Promise<PreviewOutput>;** APIs are changed to **createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput>): void;** and **createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput>;**.

   The sample code is as follows:

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

4. In **CameraManager**, the input parameter **profile: Profile** is added to **createPhotoOutput** and the **profile** parameter is obtained by the **getSupportedOutputCapability** API. Therefore, the **CreatePhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;** and **CreatePhotoOutput(surfaceId: string): Promise<PhotoOutput>;** APIs are changed to **createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput>): void;** and **createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput>;**.

   The sample code is as follows:

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

5. In **CameraManager**, the input parameter **profile: Profile** is added to **createVideoOutput** and the **profile** parameter is obtained by the **getSupportedOutputCapability** API. Therefore, the **createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput>): void;** and **createVideoOutput(surfaceId: string): Promise<VideoOutput>;** APIs are changed to **createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput>): void;** and **createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput>;**.

   The sample code is as follows:

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

6. In **CameraManager**, the input parameter **metadataObjectTypes: Array<MetadataObjectType>** is added to **createMetadataOutput**, and the **metadataObjectTypes** parameter is obtained by the **getSupportedOutputCapability** API. Therefore, the **function createMetadataOutput(callback: AsyncCallback<MetadataOutput>): void;** and **function createMetadataOutput(): Promise<MetadataOutput>;** APIs are changed to **createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>, callback: AsyncCallback<MetadataOutput>): void;** and **createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): Promise<MetadataOutput>;**.

   The sample code is as follows:

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
   
7. In **CameraManager**, **createCaptureSession** does not need to consider the context attribute. Therefore, the **createCaptureSession(context: Context, callback: AsyncCallback<CaptureSession>): void;** and **createCaptureSession(context: Context): Promise<CaptureSession>;** APIs are changed to **createCaptureSession(callback: AsyncCallback<CaptureSession>): void;** and **createCaptureSession(): Promise<CaptureSession>;**.

   The sample code is as follows:

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

8. The type of the **camera** attribute of the **CameraStatusInfo** API is changed from **Camera** to **CameraDevice**.

9. In **CameraInput**, the input parameter **camera: CameraDevice** is added to the **on(type: 'error')** API. Therefore, the **on(type: 'error', callback: ErrorCallback<CameraInputError>): void;** API is changed to **on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void;**.

   The sample code is as follows:

   ```
   let cameraDevice = cameras[0];
   cameraInput.on('error', cameraDevice, (cameraInputError) => {
       console.log(`Camera input error code: ${cameraInputError.code}`);
   })
   ```
	
10. The following APIs are moved from **CameraInput** to **CaptureSession**:

    hasFlash(callback: AsyncCallback<boolean>): void;<br>hasFlash(): Promise<boolean>;<br>

    isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise<boolean>;<br>

    getFlashMode(callback: AsyncCallback<FlashMode>): void;<br>getFlashMode(): Promise<FlashMode>;<br>

    setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise<void>;<br>

    isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean>): void;<br>isExposureModeSupported(aeMode: ExposureMode): Promise<boolean>;<br>

    getExposureMode(callback: AsyncCallback<ExposureMode>): void;<br>getExposureMode(): Promise<ExposureMode>;<br>

    setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void>): void;<br>setExposureMode(aeMode: ExposureMode): Promise<void>;<br>

    getMeteringPoint(callback: AsyncCallback<Point>): void;<br>getMeteringPoint(): Promise<Point>;<br>

    setMeteringPoint(point: Point, callback: AsyncCallback<void>): void;<br>setMeteringPoint(point: Point): Promise<void>;<br>

    getExposureBiasRange(callback: AsyncCallback<Array<number>>): void;<br>getExposureBiasRange(): Promise<Array<number>>;<br>

    setExposureBias(exposureBias: number, callback: AsyncCallback<void>): void;<br>setExposureBias(exposureBias: number): Promise<void>;<br>

    getExposureValue(callback: AsyncCallback<number>): void;<br>getExposureValue(): Promise<number>;<br>

    isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise<boolean>;<br>

    getFocusMode(callback: AsyncCallback<FocusMode>): void;<br>getFocusMode(): Promise<FocusMode>;<br>

    setFocusMode(afMode: FocusMode, callback: AsyncCallback<void>): void;<br>setFocusMode(afMode: FocusMode): Promise<void>;<br>

    setFocusPoint(point: Point, callback: AsyncCallback<void>): void;<br>setFocusPoint(point: Point): Promise<void>;<br>

    getFocusPoint(callback: AsyncCallback<Point>): void;<br>getFocusPoint(): Promise<Point>;<br>

    getFocalLength(callback: AsyncCallback<number>): void;<br>getFocalLength(): Promise<number>;<br>

    getZoomRatioRange(callback: AsyncCallback<Array<number>>): void;<br>getZoomRatioRange(): Promise<Array<number>>;<br>

    getZoomRatio(callback: AsyncCallback<number>): void;<br>getZoomRatio(): Promise<number>;<br>

    setZoomRatio(zoomRatio: number, callback: AsyncCallback<void>): void;<br>setZoomRatio(zoomRatio: number): Promise<void>;
	
11. The **on(type: 'focusStateChange', callback: AsyncCallback<FocusState>): void;** API is moved from **CameraInput** to **CaptureSession**.

    The sample code is as follows:

    ```
    captureSession.on('focusStateChange', (focusState) => {
        console.log(`Focus state  : ${focusState}`);
    })
    ```

12. The following enumerations are added to **ExposureMode**:

    Enumeration: EXPOSURE_MODE_AUTO; initial value: changed from the default value to **1**

    Enumeration: EXPOSURE_MODE_CONTINUOUS_AUTO; initial value: changed from the default value to **2**

13. The following enumerations are added to **VideoStabilizationMode**:

    Enumeration: LOW; initial value: changed from the default value to **1**

    Enumeration: MIDDLE; initial value: changed from the default value to **2**

    Enumeration: HIGH; initial value: changed from the default value to **3**

    Enumeration: AUTO; initial value: changed from the default value to **4**

14. In **CaptureSession**, the parameter of the **addOutput** API is changed from the original subclass type (**PreviewOutput**, **PhotoOutput**, **VideoOutput**, and **MetadataOutput**) to the base class type (**CameraOutput**). After the change, the number of APIs is reduced from 8 to 2.

    APIs before change:

    addOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br>addOutput(previewOutput: PreviewOutput): Promise<void>;<br>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br>addOutput(photoOutput: PhotoOutput): Promise<void>;<br>addOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br>addOutput(videoOutput: VideoOutput): Promise<void>;<br>addOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br>addOutput(metadataOutput: MetadataOutput): Promise<void>;

    APIs after change:

    addOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>addOutput(cameraOutput: CameraOutput): Promise<void>;

    The sample code (for **PreviewOutput**) is as follows:

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

15. In **CaptureSession**, the parameter of the **removeOutput** API is changed from the original subclass type (**PreviewOutput**, **PhotoOutput**, **VideoOutput**, and **MetadataOutput**) to the base class type (**CameraOutput**). After the change, the number of APIs is reduced from 8 to 2.

    APIs before change:

    removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback<void>): void;<br>removeOutput(previewOutput: PreviewOutput): Promise<void>;<br>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void>): void;<br>removeOutput(photoOutput: PhotoOutput): Promise<void>;<br>removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void>): void;<br>removeOutput(videoOutput: VideoOutput): Promise<void>;<br>removeOutput(metadataOutput: MetadataOutput, callback: AsyncCallback<void>): void;<br>removeOutput(metadataOutput: MetadataOutput): Promise<void>;

    APIs after change:

    removeOutput(cameraOutput: CameraOutput, callback: AsyncCallback<void>): void;<br>removeOutput(cameraOutput: CameraOutput): Promise<void>;

    The sample code (for **PreviewOutput**) is as follows:

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

16. The following enumeration in **MetadataObjectType** is changed:

    The enumeration value name is changed from **FACE** to **FACE_DETECTION**.

17. The name of the **Camera** API is changed to **CameraDevice**.
