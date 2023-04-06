# 媒体子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，媒体子系统的API变更如下:

## 接口变更


| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimedia.audio | AudioRenderer | on(type: 'interrupt', callback: Callback\<InterruptEvent>): void; | 新增 |
| ohos.multimedia.audio | InterruptEvent | hintType: InterruptHint; | 新增 |
| ohos.multimedia.audio | InterruptEvent | forceType: InterruptForceType; | 新增 |
| ohos.multimedia.audio | InterruptEvent | eventType: InterruptType; | 新增 |
| ohos.multimedia.audio | InterruptForceType | INTERRUPT_SHARE | 新增 |
| ohos.multimedia.audio | InterruptForceType | INTERRUPT_FORCE = 0 | 新增 |
| ohos.multimedia.camera | VideoOutputError | code: VideoOutputErrorCode; | 新增 |
| ohos.multimedia.camera | VideoOutputErrorCode | ERROR_UNKNOWN = -1 | 新增 |
| ohos.multimedia.camera | VideoOutput | on(type: 'error', callback: ErrorCallback\<VideoOutputError>): void; | 新增 |
| ohos.multimedia.camera | VideoOutput | on(type: 'frameEnd', callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.camera | VideoOutput | on(type: 'frameStart', callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.camera | VideoOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | VideoOutput | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | VideoOutput | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | camera | createVideoOutput(surfaceId: string, callback: AsyncCallback\<VideoOutput>): void;<br>createVideoOutput(surfaceId: string): Promise\<VideoOutput>; | 新增 |
| ohos.multimedia.camera | PhotoOutputError | code: PhotoOutputErrorCode; | 新增 |
| ohos.multimedia.camera | PhotoOutputErrorCode | ERROR_UNKNOWN = -1 | 新增 |
| ohos.multimedia.camera | CaptureEndInfo | frameCount: number; | 新增 |
| ohos.multimedia.camera | CaptureEndInfo | captureId: number; | 新增 |
| ohos.multimedia.camera | FrameShutterInfo | timestamp: number; | 新增 |
| ohos.multimedia.camera | FrameShutterInfo | captureId: number; | 新增 |
| ohos.multimedia.camera | PhotoOutput | on(type: 'error', callback: ErrorCallback\<PhotoOutputError>): void; | 新增 |
| ohos.multimedia.camera | PhotoOutput | on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo>): void; | 新增 |
| ohos.multimedia.camera | PhotoOutput | on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo>): void; | 新增 |
| ohos.multimedia.camera | PhotoOutput | on(type: 'captureStart', callback: AsyncCallback\<number>): void; | 新增 |
| ohos.multimedia.camera | PhotoOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | PhotoOutput | capture(callback: AsyncCallback\<void>): void;<br>capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void>): void;<br>capture(setting?: PhotoCaptureSetting): Promise\<void>; | 新增 |
| ohos.multimedia.camera | PhotoCaptureSetting | rotation?: ImageRotation; | 新增 |
| ohos.multimedia.camera | PhotoCaptureSetting | quality?: QualityLevel; | 新增 |
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_LOW | 新增 |
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_MEDIUM | 新增 |
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_HIGH = 0 | 新增 |
| ohos.multimedia.camera | ImageRotation | ROTATION_270 = 270 | 新增 |
| ohos.multimedia.camera | ImageRotation | ROTATION_180 = 180 | 新增 |
| ohos.multimedia.camera | ImageRotation | ROTATION_90 = 90 | 新增 |
| ohos.multimedia.camera | ImageRotation | ROTATION_0 = 0 | 新增 |
| ohos.multimedia.camera | camera | createPhotoOutput(surfaceId: string, callback: AsyncCallback\<PhotoOutput>): void;<br>createPhotoOutput(surfaceId: string): Promise\<PhotoOutput>; | 新增 |
| ohos.multimedia.camera | PreviewOutputError | code: PreviewOutputErrorCode; | 新增 |
| ohos.multimedia.camera | PreviewOutputErrorCode | ERROR_UNKNOWN = -1 | 新增 |
| ohos.multimedia.camera | PreviewOutput | on(type: 'error', callback: ErrorCallback\<PreviewOutputError>): void; | 新增 |
| ohos.multimedia.camera | PreviewOutput | on(type: 'frameEnd', callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.camera | PreviewOutput | on(type: 'frameStart', callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.camera | PreviewOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | camera | createPreviewOutput(surfaceId: string, callback: AsyncCallback\<PreviewOutput>): void;<br>createPreviewOutput(surfaceId: string): Promise\<PreviewOutput>; | 新增 |
| ohos.multimedia.camera | CaptureSessionError | code: CaptureSessionErrorCode; | 新增 |
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_UNKNOWN = -1 | 新增 |
| ohos.multimedia.camera | CaptureSession | on(type: 'error', callback: ErrorCallback\<CaptureSessionError>): void; | 新增 |
| ohos.multimedia.camera | CaptureSession | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(previewOutput: PreviewOutput): Promise\<void>;<br>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(photoOutput: PhotoOutput): Promise\<void>;<br>removeOutput(videoOutput: VideoOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(videoOutput: VideoOutput): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | removeInput(cameraInput: CameraInput, callback: AsyncCallback\<void>): void;<br>removeInput(cameraInput: CameraInput): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | addOutput(previewOutput: PreviewOutput, callback: AsyncCallback\<void>): void;<br>addOutput(previewOutput: PreviewOutput): Promise\<void>;<br>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback\<void>): void;<br>addOutput(photoOutput: PhotoOutput): Promise\<void>;<br>addOutput(videoOutput: VideoOutput, callback: AsyncCallback\<void>): void;<br>addOutput(videoOutput: VideoOutput): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | addInput(cameraInput: CameraInput, callback: AsyncCallback\<void>): void;<br>addInput(cameraInput: CameraInput): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | commitConfig(callback: AsyncCallback\<void>): void;<br>commitConfig(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CaptureSession | beginConfig(callback: AsyncCallback\<void>): void;<br>beginConfig(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | camera | createCaptureSession(context: Context, callback: AsyncCallback\<CaptureSession>): void;<br>createCaptureSession(context: Context): Promise\<CaptureSession>; | 新增 |
| ohos.multimedia.camera | FocusState | FOCUS_STATE_UNFOCUSED | 新增 |
| ohos.multimedia.camera | FocusState | FOCUS_STATE_FOCUSED | 新增 |
| ohos.multimedia.camera | FocusState | FOCUS_STATE_SCAN = 0 | 新增 |
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_LOCKED | 新增 |
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_AUTO | 新增 |
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_CONTINUOUS_AUTO | 新增 |
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_MANUAL = 0 | 新增 |
| ohos.multimedia.camera | FlashMode | FLASH_MODE_ALWAYS_OPEN | 新增 |
| ohos.multimedia.camera | FlashMode | FLASH_MODE_AUTO | 新增 |
| ohos.multimedia.camera | FlashMode | FLASH_MODE_OPEN | 新增 |
| ohos.multimedia.camera | FlashMode | FLASH_MODE_CLOSE = 0 | 新增 |
| ohos.multimedia.camera | CameraInputError | code: CameraInputErrorCode; | 新增 |
| ohos.multimedia.camera | CameraInputErrorCode | ERROR_UNKNOWN = -1 | 新增 |
| ohos.multimedia.camera | CameraInput | on(type: 'error', callback: ErrorCallback\<CameraInputError>): void; | 新增 |
| ohos.multimedia.camera | CameraInput | on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void; | 新增 |
| ohos.multimedia.camera | CameraInput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CameraInput | setZoomRatio(zoomRatio: number, callback: AsyncCallback\<void>): void;<br>setZoomRatio(zoomRatio: number): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CameraInput | getZoomRatio(callback: AsyncCallback\<number>): void;<br>getZoomRatio(): Promise\<number>; | 新增 |
| ohos.multimedia.camera | CameraInput | getZoomRatioRange(callback: AsyncCallback\<Array\<number>>): void;<br>getZoomRatioRange(): Promise\<Array\<number>>; | 新增 |
| ohos.multimedia.camera | CameraInput | setFocusMode(afMode: FocusMode, callback: AsyncCallback\<void>): void;<br>setFocusMode(afMode: FocusMode): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CameraInput | getFocusMode(callback: AsyncCallback\<FocusMode>): void;<br>getFocusMode(): Promise\<FocusMode>; | 新增 |
| ohos.multimedia.camera | CameraInput | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback\<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise\<boolean>; | 新增 |
| ohos.multimedia.camera | CameraInput | setFlashMode(flashMode: FlashMode, callback: AsyncCallback\<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise\<void>; | 新增 |
| ohos.multimedia.camera | CameraInput | getFlashMode(callback: AsyncCallback\<FlashMode>): void;<br>getFlashMode(): Promise\<FlashMode>; | 新增 |
| ohos.multimedia.camera | CameraInput | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback\<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise\<boolean>; | 新增 |
| ohos.multimedia.camera | CameraInput | hasFlash(callback: AsyncCallback\<boolean>): void;<br>hasFlash(): Promise\<boolean>; | 新增 |
| ohos.multimedia.camera | CameraInput | getCameraId(callback: AsyncCallback\<string>): void;<br>getCameraId(): Promise\<string>; | 新增 |
| ohos.multimedia.camera | Size | width: number; | 新增 |
| ohos.multimedia.camera | Size | height: number; | 新增 |
| ohos.multimedia.camera | Camera | readonly connectionType: ConnectionType; | 新增 |
| ohos.multimedia.camera | Camera | readonly cameraType: CameraType; | 新增 |
| ohos.multimedia.camera | Camera | readonly cameraPosition: CameraPosition; | 新增 |
| ohos.multimedia.camera | Camera | readonly cameraId: string; | 新增 |
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_REMOTE | 新增 |
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_USB_PLUGIN | 新增 |
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_BUILT_IN = 0 | 新增 |
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_TRUE_DEPTH | 新增 |
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_TELEPHOTO | 新增 |
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_ULTRA_WIDE | 新增 |
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_WIDE_ANGLE | 新增 |
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_UNSPECIFIED = 0 | 新增 |
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_FRONT | 新增 |
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_BACK | 新增 |
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_UNSPECIFIED = 0 | 新增 |
| ohos.multimedia.camera | CameraStatusInfo | status: CameraStatus; | 新增 |
| ohos.multimedia.camera | CameraStatusInfo | camera: Camera; | 新增 |
| ohos.multimedia.camera | CameraManager | on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo>): void; | 新增 |
| ohos.multimedia.camera | CameraManager | createCameraInput(cameraId: string, callback: AsyncCallback\<CameraInput>): void;<br>createCameraInput(cameraId: string): Promise\<CameraInput>;<br>createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback\<CameraInput>): void;<br>createCameraInput(position: CameraPosition, type: CameraType): Promise\<CameraInput>; | 新增 |
| ohos.multimedia.camera | CameraManager | getCameras(callback: AsyncCallback\<Array\<Camera>>): void;<br>getCameras(): Promise\<Array\<Camera>>; | 新增 |
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_UNAVAILABLE | 新增 |
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_AVAILABLE | 新增 |
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_DISAPPEAR | 新增 |
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_APPEAR = 0 | 新增 |
| ohos.multimedia.camera | camera | getCameraManager(context: Context, callback: AsyncCallback\<CameraManager>): void;<br>getCameraManager(context: Context): Promise\<CameraManager>; | 新增 |
| ohos.multimedia.image | ImageReceiver | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.image | ImageReceiver | on(type: 'imageArrival', callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.image | ImageReceiver | readNextImage(callback: AsyncCallback\<Image>): void;<br>readNextImage(): Promise\<Image>; | 新增 |
| ohos.multimedia.image | ImageReceiver | readLatestImage(callback: AsyncCallback\<Image>): void;<br>readLatestImage(): Promise\<Image>; | 新增 |
| ohos.multimedia.image | ImageReceiver | getReceivingSurfaceId(callback: AsyncCallback\<string>): void;<br>getReceivingSurfaceId(): Promise\<string>; | 新增 |
| ohos.multimedia.image | ImageReceiver | readonly format: ImageFormat; | 新增 |
| ohos.multimedia.image | ImageReceiver | readonly capacity: number; | 新增 |
| ohos.multimedia.image | ImageReceiver | readonly size: Size; | 新增 |
| ohos.multimedia.image | Image | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.image | Image | getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void;<br>getComponent(componentType: ComponentType): Promise\<Component>; | 新增 |
| ohos.multimedia.image | Image | readonly format: number; | 新增 |
| ohos.multimedia.image | Image | readonly size: Size; | 新增 |
| ohos.multimedia.image | Image | clipRect: Region; | 新增 |
| ohos.multimedia.image | image | createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver; | 新增 |
| ohos.multimedia.image | Component | readonly byteBuffer: ArrayBuffer; | 新增 |
| ohos.multimedia.image | Component | readonly pixelStride: number; | 新增 |
| ohos.multimedia.image | Component | readonly rowStride: number; | 新增 |
| ohos.multimedia.image | Component | readonly componentType: ComponentType; | 新增 |
| ohos.multimedia.image | ComponentType | JPEG = 4 | 新增 |
| ohos.multimedia.image | ComponentType | YUV_V = 3 | 新增 |
| ohos.multimedia.image | ComponentType | YUV_U = 2 | 新增 |
| ohos.multimedia.image | ComponentType | YUV_Y = 1 | 新增 |
| ohos.multimedia.image | ImageFormat | JPEG = 2000 | 新增 |
| ohos.multimedia.image | ImageFormat | YCBCR_422_SP = 1000 | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | location?: Location; | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | rotation?: number; | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | url: string; | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | profile: VideoRecorderProfile; | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | videoSourceType: VideoSourceType; | 新增 |
| ohos.multimedia.media | VideoRecorderConfig | audioSourceType: AudioSourceType; | 新增 |
| ohos.multimedia.media | VideoSourceType | VIDEO_SOURCE_TYPE_SURFACE_ES = 1 | 新增 |
| ohos.multimedia.media | VideoSourceType | VIDEO_SOURCE_TYPE_SURFACE_YUV = 0 | 新增 |
| ohos.multimedia.media | AudioSourceType | AUDIO_SOURCE_TYPE_MIC = 1 | 新增 |
| ohos.multimedia.media | AudioSourceType | AUDIO_SOURCE_TYPE_DEFAULT = 0 | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameRate: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameHeight: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameWidth: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly videoCodec: CodecMimeType; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly videoBitrate: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly fileFormat: ContainerFormatType; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly audioSampleRate: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly audioCodec: CodecMimeType; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly audioChannels: number; | 新增 |
| ohos.multimedia.media | VideoRecorderProfile | readonly audioBitrate: number; | 新增 |
| ohos.multimedia.media | VideoRecorder | readonly state: VideoRecordState; | 新增 |
| ohos.multimedia.media | VideoRecorder | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.multimedia.media | VideoRecorder | reset(callback: AsyncCallback\<void>): void;<br>reset(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | resume(callback: AsyncCallback\<void>): void;<br>resume(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoRecorder | getInputSurface(callback: AsyncCallback\<string>): void;<br>getInputSurface(): Promise\<string>; | 新增 |
| ohos.multimedia.media | VideoRecorder | prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;<br>prepare(config: VideoRecorderConfig): Promise\<void>; | 新增 |
| ohos.multimedia.media | media | createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void;<br>createVideoRecorder(): Promise\<VideoRecorder>; | 新增 |
