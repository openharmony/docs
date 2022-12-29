# JS API Changes of the Multimedia Subsystem

The table below lists the APIs changes of the multimedia subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.multimedia.audio | AudioRenderer | on(type: 'interrupt', callback: Callback\<InterruptEvent>): void; | Added|
| ohos.multimedia.audio | InterruptEvent | hintType: InterruptHint; | Added|
| ohos.multimedia.audio | InterruptEvent | forceType: InterruptForceType; | Added|
| ohos.multimedia.audio | InterruptEvent | eventType: InterruptType; | Added|
| ohos.multimedia.audio | InterruptForceType | INTERRUPT_SHARE | Added|
| ohos.multimedia.audio | InterruptForceType | INTERRUPT_FORCE = 0 | Added|
| ohos.multimedia.camera | VideoOutputError | code: VideoOutputErrorCode; | Added|
| ohos.multimedia.camera | VideoOutputErrorCode | ERROR_UNKNOWN = -1 | Added|
| ohos.multimedia.camera | VideoOutput | on(type: 'error', callback: ErrorCallback\<VideoOutputError>): void; | Added|
| ohos.multimedia.camera | VideoOutput | on(type: 'frameEnd', callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.camera | VideoOutput | on(type: 'frameStart', callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.camera | VideoOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.camera | VideoOutput | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.camera | VideoOutput | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | Added|
| ohos.multimedia.camera | camera | function createVideoOutput(surfaceId: string, callback: AsyncCallback\<VideoOutput>): void;<br>function createVideoOutput(surfaceId: string): Promise\<VideoOutput>; | Added|
| ohos.multimedia.camera | PhotoOutputError | code: PhotoOutputErrorCode; | Added|
| ohos.multimedia.camera | PhotoOutputErrorCode | ERROR_UNKNOWN = -1 | Added|
| ohos.multimedia.camera | CaptureEndInfo | frameCount: number; | Added|
| ohos.multimedia.camera | CaptureEndInfo | captureId: number; | Added|
| ohos.multimedia.camera | FrameShutterInfo | timestamp: number; | Added|
| ohos.multimedia.camera | FrameShutterInfo | captureId: number; | Added|
| ohos.multimedia.camera | PhotoOutput | on(type: 'error', callback: ErrorCallback\<PhotoOutputError>): void; | Added|
| ohos.multimedia.camera | PhotoOutput | on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo>): void; | Added|
| ohos.multimedia.camera | PhotoOutput | on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo>): void; | Added|
| ohos.multimedia.camera | PhotoOutput | on(type: 'captureStart', callback: AsyncCallback\<number>): void; | Added|
| ohos.multimedia.camera | PhotoOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.camera | PhotoOutput | capture(callback: AsyncCallback\<void>): void;<br>capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void>): void;<br>capture(setting?: PhotoCaptureSetting): Promise\<void>; | Added|
| ohos.multimedia.camera | PhotoCaptureSetting | rotation?: ImageRotation; | Added|
| ohos.multimedia.camera | PhotoCaptureSetting | quality?: QualityLevel; | Added|
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_LOW | Added|
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_MEDIUM | Added|
| ohos.multimedia.camera | QualityLevel | QUALITY_LEVEL_HIGH = 0 | Added|
| ohos.multimedia.camera | ImageRotation | ROTATION_270 = 270 | Added|
| ohos.multimedia.camera | ImageRotation | ROTATION_180 = 180 | Added|
| ohos.multimedia.camera | ImageRotation | ROTATION_90 = 90 | Added|
| ohos.multimedia.camera | ImageRotation | ROTATION_0 = 0 | Added|
| ohos.multimedia.camera | camera | function createPhotoOutput(surfaceId: string, callback: AsyncCallback\<PhotoOutput>): void;<br>function createPhotoOutput(surfaceId: string): Promise\<PhotoOutput>; | Added|
| ohos.multimedia.camera | PreviewOutputError | code: PreviewOutputErrorCode; | Added|
| ohos.multimedia.camera | PreviewOutputErrorCode | ERROR_UNKNOWN = -1 | Added|
| ohos.multimedia.camera | PreviewOutput | on(type: 'error', callback: ErrorCallback\<PreviewOutputError>): void; | Added|
| ohos.multimedia.camera | PreviewOutput | on(type: 'frameEnd', callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.camera | PreviewOutput | on(type: 'frameStart', callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.camera | PreviewOutput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.camera | camera | function createPreviewOutput(surfaceId: string, callback: AsyncCallback\<PreviewOutput>): void;<br>function createPreviewOutput(surfaceId: string): Promise\<PreviewOutput>; | Added|
| ohos.multimedia.camera | CaptureSessionError | code: CaptureSessionErrorCode; | Added|
| ohos.multimedia.camera | CaptureSessionErrorCode | ERROR_UNKNOWN = -1 | Added|
| ohos.multimedia.camera | CaptureSession | on(type: 'error', callback: ErrorCallback\<CaptureSessionError>): void; | Added|
| ohos.multimedia.camera | CaptureSession | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | removeOutput(previewOutput: PreviewOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(previewOutput: PreviewOutput): Promise\<void>;<br>removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(photoOutput: PhotoOutput): Promise\<void>;<br>removeOutput(videoOutput: VideoOutput, callback: AsyncCallback\<void>): void;<br>removeOutput(videoOutput: VideoOutput): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | removeInput(cameraInput: CameraInput, callback: AsyncCallback\<void>): void;<br>removeInput(cameraInput: CameraInput): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | addOutput(previewOutput: PreviewOutput, callback: AsyncCallback\<void>): void;<br>addOutput(previewOutput: PreviewOutput): Promise\<void>;<br>addOutput(photoOutput: PhotoOutput, callback: AsyncCallback\<void>): void;<br>addOutput(photoOutput: PhotoOutput): Promise\<void>;<br>addOutput(videoOutput: VideoOutput, callback: AsyncCallback\<void>): void;<br>addOutput(videoOutput: VideoOutput): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | addInput(cameraInput: CameraInput, callback: AsyncCallback\<void>): void;<br>addInput(cameraInput: CameraInput): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | commitConfig(callback: AsyncCallback\<void>): void;<br>commitConfig(): Promise\<void>; | Added|
| ohos.multimedia.camera | CaptureSession | beginConfig(callback: AsyncCallback\<void>): void;<br>beginConfig(): Promise\<void>; | Added|
| ohos.multimedia.camera | camera | function createCaptureSession(context: Context, callback: AsyncCallback\<CaptureSession>): void;<br>function createCaptureSession(context: Context): Promise\<CaptureSession>; | Added|
| ohos.multimedia.camera | FocusState | FOCUS_STATE_UNFOCUSED | Added|
| ohos.multimedia.camera | FocusState | FOCUS_STATE_FOCUSED | Added|
| ohos.multimedia.camera | FocusState | FOCUS_STATE_SCAN = 0 | Added|
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_LOCKED | Added|
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_AUTO | Added|
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_CONTINUOUS_AUTO | Added|
| ohos.multimedia.camera | FocusMode | FOCUS_MODE_MANUAL = 0 | Added|
| ohos.multimedia.camera | FlashMode | FLASH_MODE_ALWAYS_OPEN | Added|
| ohos.multimedia.camera | FlashMode | FLASH_MODE_AUTO | Added|
| ohos.multimedia.camera | FlashMode | FLASH_MODE_OPEN | Added|
| ohos.multimedia.camera | FlashMode | FLASH_MODE_CLOSE = 0 | Added|
| ohos.multimedia.camera | CameraInputError | code: CameraInputErrorCode; | Added|
| ohos.multimedia.camera | CameraInputErrorCode | ERROR_UNKNOWN = -1 | Added|
| ohos.multimedia.camera | CameraInput | on(type: 'error', callback: ErrorCallback\<CameraInputError>): void; | Added|
| ohos.multimedia.camera | CameraInput | on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void; | Added|
| ohos.multimedia.camera | CameraInput | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.camera | CameraInput | setZoomRatio(zoomRatio: number, callback: AsyncCallback\<void>): void;<br>setZoomRatio(zoomRatio: number): Promise\<void>; | Added|
| ohos.multimedia.camera | CameraInput | getZoomRatio(callback: AsyncCallback\<number>): void;<br>getZoomRatio(): Promise\<number>; | Added|
| ohos.multimedia.camera | CameraInput | getZoomRatioRange(callback: AsyncCallback\<Array\<number>>): void;<br>getZoomRatioRange(): Promise\<Array\<number>>; | Added|
| ohos.multimedia.camera | CameraInput | setFocusMode(afMode: FocusMode, callback: AsyncCallback\<void>): void;<br>setFocusMode(afMode: FocusMode): Promise\<void>; | Added|
| ohos.multimedia.camera | CameraInput | getFocusMode(callback: AsyncCallback\<FocusMode>): void;<br>getFocusMode(): Promise\<FocusMode>; | Added|
| ohos.multimedia.camera | CameraInput | isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback\<boolean>): void;<br>isFocusModeSupported(afMode: FocusMode): Promise\<boolean>; | Added|
| ohos.multimedia.camera | CameraInput | setFlashMode(flashMode: FlashMode, callback: AsyncCallback\<void>): void;<br>setFlashMode(flashMode: FlashMode): Promise\<void>; | Added|
| ohos.multimedia.camera | CameraInput | getFlashMode(callback: AsyncCallback\<FlashMode>): void;<br>getFlashMode(): Promise\<FlashMode>; | Added|
| ohos.multimedia.camera | CameraInput | isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback\<boolean>): void;<br>isFlashModeSupported(flashMode: FlashMode): Promise\<boolean>; | Added|
| ohos.multimedia.camera | CameraInput | hasFlash(callback: AsyncCallback\<boolean>): void;<br>hasFlash(): Promise\<boolean>; | Added|
| ohos.multimedia.camera | CameraInput | getCameraId(callback: AsyncCallback\<string>): void;<br>getCameraId(): Promise\<string>; | Added|
| ohos.multimedia.camera | Size | width: number; | Added|
| ohos.multimedia.camera | Size | height: number; | Added|
| ohos.multimedia.camera | Camera | readonly connectionType: ConnectionType; | Added|
| ohos.multimedia.camera | Camera | readonly cameraType: CameraType; | Added|
| ohos.multimedia.camera | Camera | readonly cameraPosition: CameraPosition; | Added|
| ohos.multimedia.camera | Camera | readonly cameraId: string; | Added|
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_REMOTE | Added|
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_USB_PLUGIN | Added|
| ohos.multimedia.camera | ConnectionType | CAMERA_CONNECTION_BUILT_IN = 0 | Added|
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_TRUE_DEPTH | Added|
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_TELEPHOTO | Added|
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_ULTRA_WIDE | Added|
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_WIDE_ANGLE | Added|
| ohos.multimedia.camera | CameraType | CAMERA_TYPE_UNSPECIFIED = 0 | Added|
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_FRONT | Added|
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_BACK | Added|
| ohos.multimedia.camera | CameraPosition | CAMERA_POSITION_UNSPECIFIED = 0 | Added|
| ohos.multimedia.camera | CameraStatusInfo | status: CameraStatus; | Added|
| ohos.multimedia.camera | CameraStatusInfo | camera: Camera; | Added|
| ohos.multimedia.camera | CameraManager | on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo>): void; | Added|
| ohos.multimedia.camera | CameraManager | createCameraInput(cameraId: string, callback: AsyncCallback\<CameraInput>): void;<br>createCameraInput(cameraId: string): Promise\<CameraInput>;<br>createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback\<CameraInput>): void;<br>createCameraInput(position: CameraPosition, type: CameraType): Promise\<CameraInput>; | Added|
| ohos.multimedia.camera | CameraManager | getCameras(callback: AsyncCallback\<Array\<Camera>>): void;<br>getCameras(): Promise\<Array\<Camera>>; | Added|
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_UNAVAILABLE | Added|
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_AVAILABLE | Added|
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_DISAPPEAR | Added|
| ohos.multimedia.camera | CameraStatus | CAMERA_STATUS_APPEAR = 0 | Added|
| ohos.multimedia.camera | camera | function getCameraManager(context: Context, callback: AsyncCallback\<CameraManager>): void;<br>function getCameraManager(context: Context): Promise\<CameraManager>; | Added|
| ohos.multimedia.image | ImageReceiver | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.image | ImageReceiver | on(type: 'imageArrival', callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | ImageReceiver | readNextImage(callback: AsyncCallback\<Image>): void;<br>readNextImage(): Promise\<Image>; | Added|
| ohos.multimedia.image | ImageReceiver | readLatestImage(callback: AsyncCallback\<Image>): void;<br>readLatestImage(): Promise\<Image>; | Added|
| ohos.multimedia.image | ImageReceiver | getReceivingSurfaceId(callback: AsyncCallback\<string>): void;<br>getReceivingSurfaceId(): Promise\<string>; | Added|
| ohos.multimedia.image | ImageReceiver | readonly format: ImageFormat; | Added|
| ohos.multimedia.image | ImageReceiver | readonly capacity: number; | Added|
| ohos.multimedia.image | ImageReceiver | readonly size: Size; | Added|
| ohos.multimedia.image | Image | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.image | Image | getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void;<br>getComponent(componentType: ComponentType): Promise\<Component>; | Added|
| ohos.multimedia.image | Image | readonly format: number; | Added|
| ohos.multimedia.image | Image | readonly size: Size; | Added|
| ohos.multimedia.image | Image | clipRect: Region; | Added|
| ohos.multimedia.image | ImageSource | updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;<br>updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | ImageSource | modifyImageProperty(key: string, value: string): Promise\<void>;<br>modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | image | function createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver; | Added|
| ohos.multimedia.image | image | function CreateIncrementalSource(buf: ArrayBuffer): ImageSource; | Added|
| ohos.multimedia.image | InitializationOptions | scaleMode?: ScaleMode; | Added|
| ohos.multimedia.image | InitializationOptions | alphaType?: AlphaType; | Added|
| ohos.multimedia.image | Component | readonly byteBuffer: ArrayBuffer; | Added|
| ohos.multimedia.image | Component | readonly pixelStride: number; | Added|
| ohos.multimedia.image | Component | readonly rowStride: number; | Added|
| ohos.multimedia.image | Component | readonly componentType: ComponentType; | Added|
| ohos.multimedia.image | ComponentType | JPEG = 4 | Added|
| ohos.multimedia.image | ComponentType | YUV_V = 3 | Added|
| ohos.multimedia.image | ComponentType | YUV_U = 2 | Added|
| ohos.multimedia.image | ComponentType | YUV_Y = 1 | Added|
| ohos.multimedia.image | ScaleMode | CENTER_CROP = 1 | Added|
| ohos.multimedia.image | ScaleMode | FIT_TARGET_SIZE = 0 | Added|
| ohos.multimedia.image | AlphaType | UNPREMUL = 3 | Added|
| ohos.multimedia.image | AlphaType | PREMUL = 2 | Added|
| ohos.multimedia.image | AlphaType | OPAQUE = 1 | Added|
| ohos.multimedia.image | AlphaType | UNKNOWN = 0 | Added|
| ohos.multimedia.image | ImageFormat | JPEG = 2000 | Added|
| ohos.multimedia.image | ImageFormat | YCBCR_422_SP = 1000 | Added|
| ohos.multimedia.media | VideoRecorderConfig | location?: Location; | Added|
| ohos.multimedia.media | VideoRecorderConfig | rotation?: number; | Added|
| ohos.multimedia.media | VideoRecorderConfig | url: string; | Added|
| ohos.multimedia.media | VideoRecorderConfig | profile: VideoRecorderProfile; | Added|
| ohos.multimedia.media | VideoRecorderConfig | videoSourceType: VideoSourceType; | Added|
| ohos.multimedia.media | VideoRecorderConfig | audioSourceType: AudioSourceType; | Added|
| ohos.multimedia.media | VideoSourceType | VIDEO_SOURCE_TYPE_SURFACE_ES = 1 | Added|
| ohos.multimedia.media | VideoSourceType | VIDEO_SOURCE_TYPE_SURFACE_YUV = 0 | Added|
| ohos.multimedia.media | AudioSourceType | AUDIO_SOURCE_TYPE_MIC = 1 | Added|
| ohos.multimedia.media | AudioSourceType | AUDIO_SOURCE_TYPE_DEFAULT = 0 | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameRate: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameHeight: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly videoFrameWidth: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly videoCodec: CodecMimeType; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly videoBitrate: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly fileFormat: ContainerFormatType; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly audioSampleRate: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly audioCodec: CodecMimeType; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly audioChannels: number; | Added|
| ohos.multimedia.media | VideoRecorderProfile | readonly audioBitrate: number; | Added|
| ohos.multimedia.media | VideoRecorder | readonly state: VideoRecordState; | Added|
| ohos.multimedia.media | VideoRecorder | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.multimedia.media | VideoRecorder | reset(callback: AsyncCallback\<void>): void;<br>reset(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | resume(callback: AsyncCallback\<void>): void;<br>resume(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoRecorder | getInputSurface(callback: AsyncCallback\<string>): void;<br>getInputSurface(): Promise\<string>; | Added|
| ohos.multimedia.media | VideoRecorder | prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;<br>prepare(config: VideoRecorderConfig): Promise\<void>; | Added|
| ohos.multimedia.media | media | function createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void;<br>function createVideoRecorder(): Promise\<VideoRecorder>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaLibrary | startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, index?: number): Promise\<void>; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaLibrary | storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>storeMediaAsset(option: MediaAssetOption): Promise\<string>; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaSelectOption | count: number; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaSelectOption | type: 'image' \| 'video' \| 'media'; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaAssetOption | relativePath?: string; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaAssetOption | mimeType: string; | Deprecated|
| ohos.multimedia.mediaLibrary | MediaAssetOption | src: string; | Deprecated|
