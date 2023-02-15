| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：camera<br>方法or属性：function getCameraManager(context: Context): CameraManager;|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：INVALID_ARGUMENT = 7400101|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：INVALID_ARGUMENT = 7400101|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：OPERATION_NOT_ALLOWED = 7400102|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：OPERATION_NOT_ALLOWED = 7400102|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：SESSION_NOT_CONFIG = 7400103|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：SESSION_NOT_CONFIG = 7400103|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：SESSION_NOT_RUNNING = 7400104|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：SESSION_NOT_RUNNING = 7400104|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：SESSION_CONFIG_LOCKED = 7400105|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：SESSION_CONFIG_LOCKED = 7400105|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：DEVICE_SETTING_LOCKED = 7400106|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：DEVICE_SETTING_LOCKED = 7400106|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：CONFILICT_CAMERA = 7400107|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：CONFILICT_CAMERA = 7400107|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：DEVICE_DISABLED = 7400108|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：DEVICE_DISABLED = 7400108|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.camera<br>类名: CameraErrorCode<br>方法 or 属性：SERVICE_FATAL_ERROR = 7400201|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode<br>方法or属性：SERVICE_FATAL_ERROR = 7400201|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：getSupportedCameras(): Array<CameraDevice>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createCameraInput(camera: CameraDevice): CameraInput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createCameraInput(position: CameraPosition, type: CameraType): CameraInput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createMetadataOutput(metadataObjectTypes: Array<MetadataObjectType>): MetadataOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager<br>方法or属性：createCaptureSession(): CaptureSession;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType<br>方法or属性：CAMERA_TYPE_DEFAULT = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：beginConfig(): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：addInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：removeInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：addOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：removeOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：hasFlash(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：isFlashModeSupported(flashMode: FlashMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getFlashMode(): FlashMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setFlashMode(flashMode: FlashMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：isExposureModeSupported(aeMode: ExposureMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getExposureMode(): ExposureMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setExposureMode(aeMode: ExposureMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getMeteringPoint(): Point;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setMeteringPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getExposureBiasRange(): Array<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setExposureBias(exposureBias: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getExposureValue(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：isFocusModeSupported(afMode: FocusMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getFocusMode(): FocusMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setFocusMode(afMode: FocusMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setFocusPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getFocusPoint(): Point;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getFocalLength(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getZoomRatioRange(): Array<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getZoomRatio(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setZoomRatio(zoomRatio: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：getActiveVideoStabilizationMode(): VideoStabilizationMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession<br>方法or属性：setVideoStabilizationMode(mode: VideoStabilizationMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput<br>方法or属性：isMirrorSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject<br>方法or属性：readonly type: MetadataObjectType;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject<br>方法or属性：readonly timestamp: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject<br>方法or属性：readonly boundingBox: Rect;|@ohos.multimedia.camera.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayerState<br>方法 or 属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayerState<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderState<br>方法 or 属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderState<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media<br>方法or属性：function createAVPlayer(callback: AsyncCallback<AVPlayer>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media<br>方法or属性：function createAVPlayer() : Promise<AVPlayer>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media<br>方法or属性：function createAVRecorder(callback: AsyncCallback<AVRecorder>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media<br>方法or属性：function createAVRecorder() : Promise<AVRecorder>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: StateChangeReason|@ohos.multimedia.media.d.ts|
|新增|NA|类名：StateChangeReason<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: StateChangeReason<br>方法 or 属性：USER = 1|@ohos.multimedia.media.d.ts|
|新增|NA|类名：StateChangeReason<br>方法or属性：USER = 1|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: StateChangeReason<br>方法 or 属性：BACKGROUND = 2|@ohos.multimedia.media.d.ts|
|新增|NA|类名：StateChangeReason<br>方法or属性：BACKGROUND = 2|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_OK = 0|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_OK = 0|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_NO_PERMISSION = 201|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_NO_PERMISSION = 201|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_INVALID_PARAMETER = 401|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_INVALID_PARAMETER = 401|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_UNSUPPORT_CAPABILITY = 801|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_UNSUPPORT_CAPABILITY = 801|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_NO_MEMORY = 5400101|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_NO_MEMORY = 5400101|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_OPERATE_NOT_PERMIT = 5400102|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_OPERATE_NOT_PERMIT = 5400102|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_IO = 5400103|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_IO = 5400103|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_TIMEOUT = 5400104|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_TIMEOUT = 5400104|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_SERVICE_DIED = 5400105|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_SERVICE_DIED = 5400105|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVErrorCode<br>方法 or 属性：AVERR_UNSUPPORT_FORMAT = 5400106|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode<br>方法or属性：AVERR_UNSUPPORT_FORMAT = 5400106|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：prepare(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：prepare(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：prepare(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：prepare(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：play(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：play(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：play(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：play(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：pause(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：pause(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：pause(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：pause(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：stop(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：stop(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：stop(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：stop(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：reset(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：reset(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：reset(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：reset(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：release(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：release(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：release(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：release(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：seek(timeMs: number, mode?:SeekMode): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：seek(timeMs: number, mode?:SeekMode): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：setVolume(volume: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：setVolume(volume: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：getTrackDescription() : Promise<Array<MediaDescription>>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：getTrackDescription() : Promise<Array<MediaDescription>>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：url ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：url ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：fdSrc ?: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：fdSrc ?: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：loop: boolean;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：loop: boolean;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：readonly currentTime: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：readonly currentTime: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：readonly duration: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：readonly duration: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：readonly state: AVPlayerState;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：readonly state: AVPlayerState;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：surfaceId ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：surfaceId ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：readonly width: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：readonly width: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：readonly height: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：readonly height: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：setSpeed(speed: PlaybackSpeed): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：setSpeed(speed: PlaybackSpeed): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：setBitrate(bitrate: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：setBitrate(bitrate: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'volumeChange', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'volumeChange', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'volumeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'volumeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'endOfStream', callback: Callback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'endOfStream', callback: Callback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'endOfStream'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'endOfStream'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'seekDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'seekDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'seekDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'seekDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'speedDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'speedDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'speedDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'speedDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'bitrateDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'bitrateDone', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'bitrateDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'bitrateDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'timeUpdate', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'timeUpdate', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'timeUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'timeUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'durationUpdate', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'durationUpdate', callback: Callback<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'durationUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'durationUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'bufferingUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'bufferingUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'startRenderFrame', callback: Callback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'startRenderFrame', callback: Callback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'startRenderFrame'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'startRenderFrame'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'videoSizeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'videoSizeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'audioInterrupt'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'audioInterrupt'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'availableBitrates', callback: (bitrates: Array<number>) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'availableBitrates', callback: (bitrates: Array<number>) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'availableBitrates'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'availableBitrates'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVPlayer<br>方法 or 属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：prepare(config: AVRecorderConfig, callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：prepare(config: AVRecorderConfig, callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：prepare(config: AVRecorderConfig): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：prepare(config: AVRecorderConfig): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：getInputSurface(callback: AsyncCallback<string>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：getInputSurface(callback: AsyncCallback<string>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：getInputSurface(): Promise<string>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：getInputSurface(): Promise<string>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：start(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：start(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：start(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：start(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：pause(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：pause(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：pause(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：pause(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：resume(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：resume(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：resume(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：resume(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：stop(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：stop(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：stop(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：stop(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：reset(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：reset(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：reset(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：reset(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：release(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：release(callback: AsyncCallback<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：release(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：release(): Promise<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：readonly state: AVRecorderState;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：readonly state: AVRecorderState;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorder<br>方法 or 属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder<br>方法or属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：audioBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：audioBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：audioChannels?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：audioChannels?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：audioCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：audioCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：audioSampleRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：audioSampleRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：videoBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：videoBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：videoCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：videoCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：videoFrameWidth?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：videoFrameWidth?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：videoFrameHeight?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：videoFrameHeight?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderProfile<br>方法 or 属性：videoFrameRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile<br>方法or属性：videoFrameRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：videoSourceType?: VideoSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：videoSourceType?: VideoSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：profile: AVRecorderProfile;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：profile: AVRecorderProfile;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：url: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：url: string;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：rotation?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：rotation?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVRecorderConfig<br>方法 or 属性：location?: Location;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig<br>方法or属性：location?: Location;|@ohos.multimedia.media.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:CameraType<br>方法 or 属性:CAMERA_TYPE_UNSPECIFIED = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:CameraInput<br>方法 or 属性:release(callback: AsyncCallback<void>): void;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:CameraInput<br>方法 or 属性:release(): Promise<void>;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_NO_PERMISSION = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_DEVICE_PREEMPTED = 1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_DEVICE_DISCONNECTED = 2|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_DEVICE_IN_USE = 3|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputErrorCode<br>方法 or 属性：ERROR_DRIVER_ERROR = 4|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CameraInputError<br>方法 or 属性：code: CameraInputErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionErrorCode<br>方法 or 属性：ERROR_INSUFFICIENT_RESOURCES = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionErrorCode<br>方法 or 属性：ERROR_TIMEOUT = 1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: CaptureSessionError<br>方法 or 属性：code: CaptureSessionErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PreviewOutputErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PreviewOutputErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PreviewOutputError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PreviewOutputError<br>方法 or 属性：code: PreviewOutputErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputErrorCode<br>方法 or 属性：ERROR_DRIVER_ERROR = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputErrorCode<br>方法 or 属性：ERROR_INSUFFICIENT_RESOURCES = 1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputErrorCode<br>方法 or 属性：ERROR_TIMEOUT = 2|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: PhotoOutputError<br>方法 or 属性：code: PhotoOutputErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: VideoOutputErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: VideoOutputErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: VideoOutputErrorCode<br>方法 or 属性：ERROR_DRIVER_ERROR = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: VideoOutputError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: VideoOutputError<br>方法 or 属性：code: VideoOutputErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getType(callback: AsyncCallback<MetadataObjectType>): void;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getType(): Promise<MetadataObjectType>;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getTimestamp(callback: AsyncCallback<number>): void;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getTimestamp(): Promise<number>;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getBoundingBox(callback: AsyncCallback<Rect>): void;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名：ohos.multimedia.camera<br>类名:MetadataObject<br>方法 or 属性:getBoundingBox(): Promise<Rect>;|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataFaceObject|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataOutputErrorCode|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataOutputErrorCode<br>方法 or 属性：ERROR_UNKNOWN = -1|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataOutputErrorCode<br>方法 or 属性：ERROR_INSUFFICIENT_RESOURCES = 0|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataOutputError|NA|@ohos.multimedia.camera.d.ts|
|删除|模块名: ohos.multimedia.camera<br>类名: MetadataOutputError<br>方法 or 属性：code: MetadataOutputErrorCode;|NA|@ohos.multimedia.camera.d.ts|
|访问级别有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：公开API|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：公开API|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback<AVSession>): void;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback<AVSession>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise<AVSession>;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise<AVSession>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>访问级别：公开API|类名：AVSession<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback<AVSessionController>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback<AVSessionController>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(): Promise<AVSessionController>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getController(): Promise<AVSessionController>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：activate(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：deactivate(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br>访问级别：公开API|类名：AVMetadata<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>访问级别：公开API|类名：AVPlaybackState<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition<br>访问级别：公开API|类名：PlaybackPosition<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>访问级别：公开API|类名：OutputDeviceInfo<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>访问级别：公开API|类名：LoopMode<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>访问级别：公开API|类名：PlaybackState<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>访问级别：公开API|类名：AVSessionController<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback<AVPlaybackState>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback<AVPlaybackState>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise<AVPlaybackState>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise<AVPlaybackState>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback<AVMetadata>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback<AVMetadata>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise<AVMetadata>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise<AVMetadata>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback<WantAgent>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback<WantAgent>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise<WantAgent>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise<WantAgent>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback<boolean>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback<boolean>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(): Promise<boolean>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：isActive(): Promise<boolean>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback<Array<AVControlCommandType>>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback<Array<AVControlCommandType>>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise<Array<AVControlCommandType>>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise<Array<AVControlCommandType>>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array<AVControlCommandType>) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array<AVControlCommandType>) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand<br>访问级别：公开API|类名：AVControlCommand<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode<br>访问级别：公开API|类名：AVSessionErrorCode<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：camera<br>访问级别：公开API|类名：camera<br>访问级别：系统API|@ohos.multimedia.camera.d.ts|
|访问级别有变化|类名：AudioSourceType<br>访问级别：系统API|类名：AudioSourceType<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_DEFAULT = 0<br>访问级别：系统API|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_DEFAULT = 0<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_MIC = 1<br>访问级别：系统API|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_MIC = 1<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>访问级别：系统API|类名：VideoSourceType<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_YUV = 0<br>访问级别：系统API|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_YUV = 0<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_ES = 1<br>访问级别：系统API|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_ES = 1<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：AudioState<br>方法 or 属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：N/A|类名：VideoPlayState<br>方法 or 属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayerState   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media<br>方法 or 属性：function createAudioPlayer(): AudioPlayer;<br>废弃版本：N/A|类名：media<br>方法 or 属性：function createAudioPlayer(): AudioPlayer;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media<br>方法 or 属性：function createAudioRecorder(): AudioRecorder;<br>废弃版本：N/A|类名：media<br>方法 or 属性：function createAudioRecorder(): AudioRecorder;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media<br>方法 or 属性：function createVideoPlayer(callback: AsyncCallback<VideoPlayer>): void;<br>废弃版本：N/A|类名：media<br>方法 or 属性：function createVideoPlayer(callback: AsyncCallback<VideoPlayer>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media<br>方法 or 属性：function createVideoPlayer() : Promise<VideoPlayer>;<br>废弃版本：N/A|类名：media<br>方法 or 属性：function createVideoPlayer() : Promise<VideoPlayer>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>废弃版本：N/A|类名：AudioPlayer<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：play(): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：play(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：pause(): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：pause(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：stop(): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：stop(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：reset(): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：reset(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：seek(timeMs: number): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：seek(timeMs: number): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：setVolume(vol: number): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：setVolume(vol: number): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：release(): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：release(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：getTrackDescription() : Promise<Array<MediaDescription>>;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：getTrackDescription() : Promise<Array<MediaDescription>>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：src: string;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：src: string;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：fdSrc: AVFileDescriptor;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：fdSrc: AVFileDescriptor;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：loop: boolean;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：loop: boolean;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：audioInterruptMode ?: audio.InterruptMode;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：audioInterruptMode ?: audio.InterruptMode;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：readonly currentTime: number;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：readonly currentTime: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：readonly duration: number;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：readonly duration: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：readonly state: AudioState;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：readonly state: AudioState;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'timeUpdate', callback: Callback<number>): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'timeUpdate', callback: Callback<number>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：N/A|类名：AudioPlayer<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>废弃版本：N/A|类名：AudioRecorderConfig<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorderConfig   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：audioEncodeBitRate?: number;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：audioEncodeBitRate?: number;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：audioSampleRate?: number;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：audioSampleRate?: number;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：numberOfChannels?: number;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：numberOfChannels?: number;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：uri: string;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：uri: string;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：location?: Location;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：location?: Location;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：audioEncoderMime?: CodecMimeType;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：audioEncoderMime?: CodecMimeType;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig<br>方法 or 属性：fileFormat?: ContainerFormatType;<br>废弃版本：N/A|类名：AudioRecorderConfig<br>方法 or 属性：fileFormat?: ContainerFormatType;<br>废弃版本：9<br>代替接口：N/A|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>废弃版本：N/A|类名：AudioRecorder<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：prepare(config: AudioRecorderConfig): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：prepare(config: AudioRecorderConfig): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：start(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：start(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：pause(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：pause(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：resume(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：resume(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：stop(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：stop(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：release(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：release(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：reset(): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：reset(): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：N/A|类名：AudioRecorder<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>废弃版本：N/A|类名：VideoPlayer<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer   |@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setDisplaySurface(surfaceId: string): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setDisplaySurface(surfaceId: string): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：prepare(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：prepare(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：prepare(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：prepare(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：play(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：play(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：play(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：play(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：pause(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：pause(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：pause(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：pause(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：stop(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：stop(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：stop(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：stop(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：reset(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：reset(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：reset(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：reset(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, mode:SeekMode, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, mode:SeekMode, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, mode?:SeekMode): Promise<number>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：seek(timeMs: number, mode?:SeekMode): Promise<number>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setVolume(vol: number, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setVolume(vol: number, callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setVolume(vol: number): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setVolume(vol: number): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：release(callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：release(callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：release(): Promise<void>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：release(): Promise<void>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：getTrackDescription(callback: AsyncCallback<Array<MediaDescription>>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：getTrackDescription() : Promise<Array<MediaDescription>>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：getTrackDescription() : Promise<Array<MediaDescription>>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：url: string;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：url: string;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：fdSrc: AVFileDescriptor;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：fdSrc: AVFileDescriptor;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：loop: boolean;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：loop: boolean;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：readonly currentTime: number;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：readonly currentTime: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：readonly duration: number;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：readonly duration: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：readonly state: VideoPlayState;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：readonly state: VideoPlayState;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：readonly width: number;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：readonly width: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：readonly height: number;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：readonly height: number;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：audioInterruptMode ?: audio.InterruptMode;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：audioInterruptMode ?: audio.InterruptMode;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：videoScaleType ?: VideoScaleType;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：videoScaleType ?: VideoScaleType;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setSpeed(speed:number, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setSpeed(speed:number, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：setSpeed(speed:number): Promise<number>;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：setSpeed(speed:number): Promise<number>;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'playbackCompleted', callback: Callback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'playbackCompleted', callback: Callback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'startRenderFrame', callback: Callback<void>): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'startRenderFrame', callback: Callback<void>): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：N/A|类名：VideoPlayer<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;<br>废弃版本：9<br>代替接口：ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>起始版本：N/A|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>起始版本：9|@ohos.multimedia.avsession.d.ts|
|起始版本有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>起始版本：N/A|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>起始版本：9|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：公开API|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：公开API|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：公开API|类名：AVControlCommandType<br>方法 or 属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback<AVSession>): void;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback<AVSession>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise<AVSession>;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise<AVSession>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>访问级别：公开API|类名：avSession<br>方法 or 属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>访问级别：公开API|类名：AVSession<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback<AVSessionController>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback<AVSessionController>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(): Promise<AVSessionController>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getController(): Promise<AVSessionController>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：activate(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：deactivate(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：公开API|类名：AVSession<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br>访问级别：公开API|类名：AVMetadata<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>访问级别：公开API|类名：AVPlaybackState<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition<br>访问级别：公开API|类名：PlaybackPosition<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>访问级别：公开API|类名：OutputDeviceInfo<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>访问级别：公开API|类名：LoopMode<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>访问级别：公开API|类名：PlaybackState<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>访问级别：公开API|类名：AVSessionController<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback<AVPlaybackState>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback<AVPlaybackState>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise<AVPlaybackState>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise<AVPlaybackState>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback<AVMetadata>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback<AVMetadata>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise<AVMetadata>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise<AVMetadata>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback<OutputDeviceInfo>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise<OutputDeviceInfo>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback<WantAgent>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback<WantAgent>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise<WantAgent>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise<WantAgent>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback<boolean>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback<boolean>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(): Promise<boolean>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：isActive(): Promise<boolean>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：destroy(): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback<Array<AVControlCommandType>>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback<Array<AVControlCommandType>>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise<Array<AVControlCommandType>>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise<Array<AVControlCommandType>>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise<void>;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise<void>;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array<AVControlCommandType>) => void);<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array<AVControlCommandType>) => void);<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand<br>访问级别：公开API|类名：AVControlCommand<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode<br>访问级别：公开API|类名：AVSessionErrorCode<br>访问级别：系统API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：camera<br>访问级别：公开API|类名：camera<br>访问级别：系统API|@ohos.multimedia.camera.d.ts|
|访问级别有变化|类名：AudioSourceType<br>访问级别：系统API|类名：AudioSourceType<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_DEFAULT = 0<br>访问级别：系统API|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_DEFAULT = 0<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_MIC = 1<br>访问级别：系统API|类名：AudioSourceType<br>方法 or 属性：AUDIO_SOURCE_TYPE_MIC = 1<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>访问级别：系统API|类名：VideoSourceType<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_YUV = 0<br>访问级别：系统API|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_YUV = 0<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|访问级别有变化|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_ES = 1<br>访问级别：系统API|类名：VideoSourceType<br>方法 or 属性：VIDEO_SOURCE_TYPE_SURFACE_ES = 1<br>访问级别：公开API|@ohos.multimedia.media.d.ts|
|函数有变化|类名：CameraInput<br>方法 or 属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback<CameraInputError>): void;<br>|类名：CameraInput<br>方法 or 属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：CaptureSession<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<CaptureSessionError>): void;<br>|类名：CaptureSession<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PreviewOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<PreviewOutputError>): void;<br>|类名：PreviewOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PhotoOutput<br>方法 or 属性：capture(setting?: PhotoCaptureSetting): Promise<void>;<br>|类名：PhotoOutput<br>方法 or 属性：capture(): Promise<void>;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PhotoOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<PhotoOutputError>): void;<br>|类名：PhotoOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：VideoOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<VideoOutputError>): void;<br>|类名：VideoOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：MetadataOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<MetadataOutputError>): void;<br>|类名：MetadataOutput<br>方法 or 属性：on(type: 'error', callback: ErrorCallback<BusinessError>): void;<br>|@ohos.multimedia.camera.d.ts|
