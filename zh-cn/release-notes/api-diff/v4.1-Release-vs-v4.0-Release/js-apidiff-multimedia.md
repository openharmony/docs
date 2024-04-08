| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API跨平台权限变更|类名：global；<br>API声明： declare namespace image<br>差异内容：NA|类名：global；<br>API声明： declare namespace image<br>差异内容：crossplatform|api/@ohos.multimedia.image.d.ts|
|API跨平台权限变更|类名：PixelMap；<br>API声明：getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>差异内容：NA|类名：PixelMap；<br>API声明：getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>差异内容：crossplatform|api/@ohos.multimedia.image.d.ts|
|API跨平台权限变更|类名：PixelMap；<br>API声明：setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>差异内容：NA|类名：PixelMap；<br>API声明：setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>差异内容：crossplatform|api/@ohos.multimedia.image.d.ts|
|syscap变更|类名：avSession；<br>API声明： interface AVMetadata<br>差异内容：NA|类名：avSession；<br>API声明： interface AVMetadata<br>差异内容：SystemCapability.Multimedia.AVSession.Core|api/@ohos.multimedia.avsession.d.ts|
|syscap变更|类名：MetadataObjectType；<br>API声明：FACE_DETECTION = 0<br>差异内容：NA|类名：MetadataObjectType；<br>API声明：FACE_DETECTION = 0<br>差异内容：SystemCapability.Multimedia.Camera.Core|api/@ohos.multimedia.camera.d.ts|
|syscap变更|类名：global；<br>API声明： declare namespace image<br>差异内容：NA|类名：global；<br>API声明： declare namespace image<br>差异内容：SystemCapability.Multimedia.Image.Core|api/@ohos.multimedia.image.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'stateChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'stateChange'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'volumeChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'volumeChange'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'endOfStream'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'endOfStream'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'seekDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'seekDone'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'speedDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'speedDone'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'bitrateDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'bitrateDone'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'timeUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'timeUpdate'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'durationUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'durationUpdate'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'bufferingUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'bufferingUpdate'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'startRenderFrame'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'startRenderFrame'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'videoSizeChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'videoSizeChange'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'audioInterrupt'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'audioInterrupt'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'availableBitrates'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'availableBitrates'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|syscap变更|类名：AVPlayer；<br>API声明：off(type: 'error'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'error'): void;<br>差异内容：SystemCapability.Multimedia.Media.AVPlayer|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：Filter；<br>API声明：getPixelMap(): image.PixelMap;<br>差异内容：NA|类名：Filter；<br>API声明：getPixelMap(): image.PixelMap;<br>差异内容：11|api/@ohos.effectKit.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：AudioManager；<br>API声明：setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：setAudioParameter(key: string, value: string): Promise\<void>;<br>差异内容：NA|类名：AudioManager；<br>API声明：setAudioParameter(key: string, value: string): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：getAudioParameter(key: string, callback: AsyncCallback\<string>): void;<br>差异内容：NA|类名：AudioManager；<br>API声明：getAudioParameter(key: string, callback: AsyncCallback\<string>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：getAudioParameter(key: string): Promise\<string>;<br>差异内容：NA|类名：AudioManager；<br>API声明：getAudioParameter(key: string): Promise\<string>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void;<br>差异内容：NA|类名：AudioManager；<br>API声明：on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioManager；<br>API声明：off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void;<br>差异内容：NA|类名：AudioManager；<br>API声明：off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioVolumeGroupManager；<br>API声明：setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：AudioVolumeGroupManager；<br>API声明：setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioVolumeGroupManager；<br>API声明：setMicrophoneMute(mute: boolean): Promise\<void>;<br>差异内容：NA|类名：AudioVolumeGroupManager；<br>API声明：setMicrophoneMute(mute: boolean): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：write(buffer: ArrayBuffer): Promise\<number>;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：write(buffer: ArrayBuffer): Promise\<number>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：setRenderRate(rate: AudioRendererRate): Promise\<void>;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：setRenderRate(rate: AudioRendererRate): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：getRenderRate(): Promise\<AudioRendererRate>;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：getRenderRate(): Promise\<AudioRendererRate>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioRenderer；<br>API声明：getRenderRateSync(): AudioRendererRate;<br>差异内容：NA|类名：AudioRenderer；<br>API声明：getRenderRateSync(): AudioRendererRate;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioCapturer；<br>API声明：read(size: number, isBlockingRead: boolean, callback: AsyncCallback\<ArrayBuffer>): void;<br>差异内容：NA|类名：AudioCapturer；<br>API声明：read(size: number, isBlockingRead: boolean, callback: AsyncCallback\<ArrayBuffer>): void;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：AudioCapturer；<br>API声明：read(size: number, isBlockingRead: boolean): Promise\<ArrayBuffer>;<br>差异内容：NA|类名：AudioCapturer；<br>API声明：read(size: number, isBlockingRead: boolean): Promise\<ArrayBuffer>;<br>差异内容：11|api/@ohos.multimedia.audio.d.ts|
|API废弃版本变更|类名：CameraManager；<br>API声明：getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;<br>差异内容：NA|类名：CameraManager；<br>API声明：getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CameraManager；<br>API声明：createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;<br>差异内容：NA|类名：CameraManager；<br>API声明：createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CameraManager；<br>API声明：createCaptureSession(): CaptureSession;<br>差异内容：NA|类名：CameraManager；<br>API声明：createCaptureSession(): CaptureSession;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：camera；<br>API声明： interface CaptureSession<br>差异内容：NA|类名：camera；<br>API声明： interface CaptureSession<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：beginConfig(): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：beginConfig(): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：commitConfig(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：commitConfig(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：commitConfig(): Promise\<void>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：commitConfig(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：addInput(cameraInput: CameraInput): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：addInput(cameraInput: CameraInput): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：removeInput(cameraInput: CameraInput): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：removeInput(cameraInput: CameraInput): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：addOutput(cameraOutput: CameraOutput): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：addOutput(cameraOutput: CameraOutput): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：removeOutput(cameraOutput: CameraOutput): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：removeOutput(cameraOutput: CameraOutput): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：start(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：start(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：start(): Promise\<void>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：start(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：stop(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：stop(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：stop(): Promise\<void>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：stop(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：release(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：release(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：release(): Promise\<void>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：release(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：hasFlash(): boolean;<br>差异内容：NA|类名：CaptureSession；<br>API声明：hasFlash(): boolean;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：isFlashModeSupported(flashMode: FlashMode): boolean;<br>差异内容：NA|类名：CaptureSession；<br>API声明：isFlashModeSupported(flashMode: FlashMode): boolean;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getFlashMode(): FlashMode;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getFlashMode(): FlashMode;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setFlashMode(flashMode: FlashMode): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setFlashMode(flashMode: FlashMode): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：isExposureModeSupported(aeMode: ExposureMode): boolean;<br>差异内容：NA|类名：CaptureSession；<br>API声明：isExposureModeSupported(aeMode: ExposureMode): boolean;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getExposureMode(): ExposureMode;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getExposureMode(): ExposureMode;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setExposureMode(aeMode: ExposureMode): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setExposureMode(aeMode: ExposureMode): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getMeteringPoint(): Point;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getMeteringPoint(): Point;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setMeteringPoint(point: Point): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setMeteringPoint(point: Point): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getExposureBiasRange(): Array\<number>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getExposureBiasRange(): Array\<number>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setExposureBias(exposureBias: number): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setExposureBias(exposureBias: number): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getExposureValue(): number;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getExposureValue(): number;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：isFocusModeSupported(afMode: FocusMode): boolean;<br>差异内容：NA|类名：CaptureSession；<br>API声明：isFocusModeSupported(afMode: FocusMode): boolean;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getFocusMode(): FocusMode;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getFocusMode(): FocusMode;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setFocusMode(afMode: FocusMode): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setFocusMode(afMode: FocusMode): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setFocusPoint(point: Point): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setFocusPoint(point: Point): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getFocusPoint(): Point;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getFocusPoint(): Point;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getFocalLength(): number;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getFocalLength(): number;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getZoomRatioRange(): Array\<number>;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getZoomRatioRange(): Array\<number>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getZoomRatio(): number;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getZoomRatio(): number;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setZoomRatio(zoomRatio: number): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setZoomRatio(zoomRatio: number): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;<br>差异内容：NA|类名：CaptureSession；<br>API声明：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：getActiveVideoStabilizationMode(): VideoStabilizationMode;<br>差异内容：NA|类名：CaptureSession；<br>API声明：getActiveVideoStabilizationMode(): VideoStabilizationMode;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：setVideoStabilizationMode(mode: VideoStabilizationMode): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：setVideoStabilizationMode(mode: VideoStabilizationMode): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：CaptureSession；<br>API声明：off(type: 'error', callback?: ErrorCallback): void;<br>差异内容：NA|类名：CaptureSession；<br>API声明：off(type: 'error', callback?: ErrorCallback): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PreviewOutput；<br>API声明：start(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：PreviewOutput；<br>API声明：start(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PreviewOutput；<br>API声明：start(): Promise\<void>;<br>差异内容：NA|类名：PreviewOutput；<br>API声明：start(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PreviewOutput；<br>API声明：stop(callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：PreviewOutput；<br>API声明：stop(callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PreviewOutput；<br>API声明：stop(): Promise\<void>;<br>差异内容：NA|类名：PreviewOutput；<br>API声明：stop(): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PhotoOutput；<br>API声明：on(type: 'captureStart', callback: AsyncCallback\<number>): void;<br>差异内容：NA|类名：PhotoOutput；<br>API声明：on(type: 'captureStart', callback: AsyncCallback\<number>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：PhotoOutput；<br>API声明：off(type: 'captureStart', callback?: AsyncCallback\<number>): void;<br>差异内容：NA|类名：PhotoOutput；<br>API声明：off(type: 'captureStart', callback?: AsyncCallback\<number>): void;<br>差异内容：11|api/@ohos.multimedia.camera.d.ts|
|API废弃版本变更|类名：image；<br>API声明： interface GetImagePropertyOptions<br>差异内容：NA|类名：image；<br>API声明： interface GetImagePropertyOptions<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：GetImagePropertyOptions；<br>API声明：index?: number;<br>差异内容：NA|类名：GetImagePropertyOptions；<br>API声明：index?: number;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：GetImagePropertyOptions；<br>API声明：defaultValue?: string;<br>差异内容：NA|类名：GetImagePropertyOptions；<br>API声明：defaultValue?: string;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：image；<br>API声明：function createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver;<br>差异内容：NA|类名：image；<br>API声明：function createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：image；<br>API声明：function createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator;<br>差异内容：NA|类名：image；<br>API声明：function createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：ImageSource；<br>API声明：getImageProperty(key: string, options?: GetImagePropertyOptions): Promise\<string>;<br>差异内容：NA|类名：ImageSource；<br>API声明：getImageProperty(key: string, options?: GetImagePropertyOptions): Promise\<string>;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：ImageSource；<br>API声明：getImageProperty(key: string, callback: AsyncCallback\<string>): void;<br>差异内容：NA|类名：ImageSource；<br>API声明：getImageProperty(key: string, callback: AsyncCallback\<string>): void;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：ImageSource；<br>API声明：getImageProperty(key: string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void;<br>差异内容：NA|类名：ImageSource；<br>API声明：getImageProperty(key: string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：ImageSource；<br>API声明：modifyImageProperty(key: string, value: string): Promise\<void>;<br>差异内容：NA|类名：ImageSource；<br>API声明：modifyImageProperty(key: string, value: string): Promise\<void>;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：ImageSource；<br>API声明：modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：ImageSource；<br>API声明：modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;<br>差异内容：11|api/@ohos.multimedia.image.d.ts|
|API废弃版本变更|类名：media；<br>API声明： enum MediaErrorCode<br>差异内容：NA|类名：media；<br>API声明： enum MediaErrorCode<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_OK = 0<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_OK = 0<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_NO_MEMORY = 1<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_NO_MEMORY = 1<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_OPERATION_NOT_PERMIT = 2<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_OPERATION_NOT_PERMIT = 2<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_INVALID_VAL = 3<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_INVALID_VAL = 3<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_IO = 4<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_IO = 4<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_TIMEOUT = 5<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_TIMEOUT = 5<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_UNKNOWN = 6<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_UNKNOWN = 6<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_SERVICE_DIED = 7<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_SERVICE_DIED = 7<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_INVALID_STATE = 8<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_INVALID_STATE = 8<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|API废弃版本变更|类名：MediaErrorCode；<br>API声明：MSERR_UNSUPPORTED = 9<br>差异内容：NA|类名：MediaErrorCode；<br>API声明：MSERR_UNSUPPORTED = 9<br>差异内容：11|api/@ohos.multimedia.media.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>差异内容：62980096,62980103,62980110,62980111,62980118|类名：ImageSource；<br>API声明：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>差异内容：401,62980096,62980099,62980101,62980103,62980106,62980109,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137,62980173,62980174|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>差异内容：62980096,62980103,62980110,62980111,62980118|类名：ImageSource；<br>API声明：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>差异内容：401,62980096,62980099,62980101,62980103,62980106,62980109,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137,62980173,62980174|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>差异内容：62980096,62980103,62980110,62980111,62980118|类名：ImageSource；<br>API声明：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>差异内容：401,62980096,62980099,62980101,62980103,62980106,62980109,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137,62980173,62980174|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：getDelayTimeList(): Promise\<Array\<number>>;<br>差异内容：62980096,62980110,62980111,62980113,62980116,62980118,62980122|类名：ImageSource；<br>API声明：getDelayTimeList(): Promise\<Array\<number>>;<br>差异内容：401,62980096,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137,62980149|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;<br>差异内容：62980096,62980110,62980111,62980113,62980116,62980118,62980122|类名：ImageSource；<br>API声明：getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;<br>差异内容：401,62980096,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137,62980149|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：getFrameCount(): Promise\<number>;<br>差异内容：62980096,62980110,62980111,62980113,62980116,62980118,62980122|类名：ImageSource；<br>API声明：getFrameCount(): Promise\<number>;<br>差异内容：401,62980096,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：ImageSource；<br>API声明：getFrameCount(callback: AsyncCallback\<number>): void;<br>差异内容：62980096,62980110,62980111,62980113,62980116,62980118,62980122|类名：ImageSource；<br>API声明：getFrameCount(callback: AsyncCallback\<number>): void;<br>差异内容：401,62980096,62980110,62980111,62980112,62980113,62980115,62980116,62980118,62980122,62980137|api/@ohos.multimedia.image.d.ts|
|错误码变更|类名：AVRecorder；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：201,401,5400101,5400102,5400103,5400104,5400105,5400106,801|类名：AVRecorder；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：201,401,5400101,5400102,5400103,5400104,5400105,5400106,5400107,801|api/@ohos.multimedia.media.d.ts|
|权限变更|类名：CaptureFilterOptions；<br>API声明：usages: Array\<StreamUsage>;<br>差异内容：ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO|类名：CaptureFilterOptions；<br>API声明：usages: Array\<StreamUsage>;<br>差异内容：NA|api/@ohos.multimedia.audio.d.ts|
|函数变更|类名：PhotoOutput；<br>API声明：capture(setting?: PhotoCaptureSetting): Promise\<void>;<br>差异内容：setting?: PhotoCaptureSetting|类名：PhotoOutput；<br>API声明：capture(setting: PhotoCaptureSetting): Promise\<void>;<br>差异内容：setting: PhotoCaptureSetting|api/@ohos.multimedia.camera.d.ts|
|函数变更|类名：ImageSource；<br>API声明：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;<br>差异内容：value: number|类名：ImageSource；<br>API声明：updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number): Promise\<void>;<br>差异内容：offset: number|api/@ohos.multimedia.image.d.ts|
|函数变更|类名：ImageSource；<br>API声明：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void;<br>差异内容：value: number|类名：ImageSource；<br>API声明：updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number, callback: AsyncCallback\<void>): void;<br>差异内容：offset: number|api/@ohos.multimedia.image.d.ts|
|函数变更|类名：AVSession；<br>API声明：on(type: 'fastForward', callback: () => void): void;<br>差异内容：callback: () => void|类名：AVSession；<br>API声明：on(type: 'fastForward', callback: (time?: number) => void): void;<br>差异内容：callback: (time?: number) => void|api/@ohos.multimedia.avsession.d.ts|
|函数变更|类名：AVSession；<br>API声明：on(type: 'rewind', callback: () => void): void;<br>差异内容：callback: () => void|类名：AVSession；<br>API声明：on(type: 'rewind', callback: (time?: number) => void): void;<br>差异内容：callback: (time?: number) => void|api/@ohos.multimedia.avsession.d.ts|
|自定义类型变更|类名：avSession；<br>API声明：type AVSessionType = 'audio' \| 'video';<br>差异内容：'audio','video'|类名：avSession；<br>API声明：type AVSessionType = 'audio' \| 'video' \| 'voice_call';<br>差异内容：'audio','video','voice_call'|api/@ohos.multimedia.avsession.d.ts|
|自定义类型变更|类名：avSession；<br>API声明：type AVCastControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \| 'seek' \| 'setVolume' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>差异内容：'play','pause','stop','playNext','playPrevious','fastForward','rewind','seek','setVolume','setSpeed','setLoopMode','toggleFavorite'|类名：avSession；<br>API声明：type AVCastControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \| 'seek' \| 'setVolume' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite' \| 'toggleMute';<br>差异内容：'play','pause','stop','playNext','playPrevious','fastForward','rewind','seek','setVolume','setSpeed','setLoopMode','toggleFavorite','toggleMute'|api/@ohos.multimedia.avsession.d.ts|
|自定义类型变更|类名：avSession；<br>API声明：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \| 'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>差异内容：'play','pause','stop','playNext','playPrevious','fastForward','rewind','seek','setSpeed','setLoopMode','toggleFavorite'|类名：avSession；<br>API声明：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \| 'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite' \| 'playFromAssetId' \| 'answer' \| 'hangUp' \| 'toggleCallMute';<br>差异内容：'play','pause','stop','playNext','playPrevious','fastForward','rewind','seek','setSpeed','setLoopMode','toggleFavorite','playFromAssetId','answer','hangUp','toggleCallMute'|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability;<br>差异内容：getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：createPhotoOutput(profile: Profile): PhotoOutput;<br>差异内容：createPhotoOutput(profile: Profile): PhotoOutput;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：image；<br>API声明：function createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource;<br>差异内容：function createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：image；<br>API声明：function createImageReceiver(size: Size, format: ImageFormat, capacity: number): ImageReceiver;<br>差异内容：function createImageReceiver(size: Size, format: ImageFormat, capacity: number): ImageReceiver;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：image；<br>API声明：function createImageCreator(size: Size, format: ImageFormat, capacity: number): ImageCreator;<br>差异内容：function createImageCreator(size: Size, format: ImageFormat, capacity: number): ImageCreator;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImageSource；<br>API声明：getImageProperty(key: PropertyKey, options?: ImagePropertyOptions): Promise\<string>;<br>差异内容：getImageProperty(key: PropertyKey, options?: ImagePropertyOptions): Promise\<string>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImageSource；<br>API声明：modifyImageProperty(key: PropertyKey, value: string): Promise\<void>;<br>差异内容：modifyImageProperty(key: PropertyKey, value: string): Promise\<void>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：Filter；<br>API声明：getEffectPixelMap(): Promise\<image.PixelMap>;<br>差异内容：getEffectPixelMap(): Promise\<image.PixelMap>;|api/@ohos.effectKit.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_3 = 3<br>差异内容：CHANNEL_3 = 3|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_4 = 4<br>差异内容：CHANNEL_4 = 4|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_5 = 5<br>差异内容：CHANNEL_5 = 5|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_6 = 6<br>差异内容：CHANNEL_6 = 6|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_7 = 7<br>差异内容：CHANNEL_7 = 7|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_8 = 8<br>差异内容：CHANNEL_8 = 8|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_9 = 9<br>差异内容：CHANNEL_9 = 9|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_10 = 10<br>差异内容：CHANNEL_10 = 10|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_12 = 12<br>差异内容：CHANNEL_12 = 12|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_14 = 14<br>差异内容：CHANNEL_14 = 14|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannel；<br>API声明：CHANNEL_16 = 16<br>差异内容：CHANNEL_16 = 16|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamInfo；<br>API声明：channelLayout?: AudioChannelLayout;<br>差异内容：channelLayout?: AudioChannelLayout;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturerChangeInfo；<br>API声明：readonly muted?: boolean;<br>差异内容：readonly muted?: boolean;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioDeviceDescriptor；<br>API声明：readonly encodingTypes?: Array\<AudioEncodingType>;<br>差异内容：readonly encodingTypes?: Array\<AudioEncodingType>;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：audio；<br>API声明： enum ChannelBlendMode<br>差异内容： enum ChannelBlendMode|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：ChannelBlendMode；<br>API声明：MODE_DEFAULT = 0<br>差异内容：MODE_DEFAULT = 0|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：ChannelBlendMode；<br>API声明：MODE_BLEND_LR = 1<br>差异内容：MODE_BLEND_LR = 1|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：ChannelBlendMode；<br>API声明：MODE_ALL_LEFT = 2<br>差异内容：MODE_ALL_LEFT = 2|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：ChannelBlendMode；<br>API声明：MODE_ALL_RIGHT = 3<br>差异内容：MODE_ALL_RIGHT = 3|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：audio；<br>API声明： enum AudioStreamDeviceChangeReason<br>差异内容： enum AudioStreamDeviceChangeReason|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeReason；<br>API声明：REASON_UNKNOWN = 0<br>差异内容：REASON_UNKNOWN = 0|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeReason；<br>API声明：REASON_NEW_DEVICE_AVAILABLE = 1<br>差异内容：REASON_NEW_DEVICE_AVAILABLE = 1|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeReason；<br>API声明：REASON_OLD_DEVICE_UNAVAILABLE = 2<br>差异内容：REASON_OLD_DEVICE_UNAVAILABLE = 2|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeReason；<br>API声明：REASON_OVERRODE = 3<br>差异内容：REASON_OVERRODE = 3|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：audio；<br>API声明： interface AudioStreamDeviceChangeInfo<br>差异内容： interface AudioStreamDeviceChangeInfo|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeInfo；<br>API声明：devices: AudioDeviceDescriptors;<br>差异内容：devices: AudioDeviceDescriptors;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioStreamDeviceChangeInfo；<br>API声明：changeReason: AudioStreamDeviceChangeReason;<br>差异内容：changeReason: AudioStreamDeviceChangeReason;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：flush(): Promise\<void>;<br>差异内容：flush(): Promise\<void>;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：setSpeed(speed: number): void;<br>差异内容：setSpeed(speed: number): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：getSpeed(): number;<br>差异内容：getSpeed(): number;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：setVolumeWithRamp(volume: number, duration: number): void;<br>差异内容：setVolumeWithRamp(volume: number, duration: number): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：setChannelBlendMode(mode: ChannelBlendMode): void;<br>差异内容：setChannelBlendMode(mode: ChannelBlendMode): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：on(type: 'outputDeviceChangeWithInfo', callback: Callback\<AudioStreamDeviceChangeInfo>): void;<br>差异内容：on(type: 'outputDeviceChangeWithInfo', callback: Callback\<AudioStreamDeviceChangeInfo>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：off(type: 'outputDeviceChangeWithInfo', callback?: Callback\<AudioStreamDeviceChangeInfo>): void;<br>差异内容：off(type: 'outputDeviceChangeWithInfo', callback?: Callback\<AudioStreamDeviceChangeInfo>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：on(type: 'writeData', callback: Callback\<ArrayBuffer>): void;<br>差异内容：on(type: 'writeData', callback: Callback\<ArrayBuffer>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioRenderer；<br>API声明：off(type: 'writeData', callback?: Callback\<ArrayBuffer>): void;<br>差异内容：off(type: 'writeData', callback?: Callback\<ArrayBuffer>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：getCurrentInputDevices(): AudioDeviceDescriptors;<br>差异内容：getCurrentInputDevices(): AudioDeviceDescriptors;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：getCurrentAudioCapturerChangeInfo(): AudioCapturerChangeInfo;<br>差异内容：getCurrentAudioCapturerChangeInfo(): AudioCapturerChangeInfo;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：on(type: 'inputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void;<br>差异内容：on(type: 'inputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：off(type: 'inputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void;<br>差异内容：off(type: 'inputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：on(type: 'audioCapturerChange', callback: Callback\<AudioCapturerChangeInfo>): void;<br>差异内容：on(type: 'audioCapturerChange', callback: Callback\<AudioCapturerChangeInfo>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：off(type: 'audioCapturerChange', callback?: Callback\<AudioCapturerChangeInfo>): void;<br>差异内容：off(type: 'audioCapturerChange', callback?: Callback\<AudioCapturerChangeInfo>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：on(type: 'readData', callback: Callback\<ArrayBuffer>): void;<br>差异内容：on(type: 'readData', callback: Callback\<ArrayBuffer>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioCapturer；<br>API声明：off(type: 'readData', callback?: Callback\<ArrayBuffer>): void;<br>差异内容：off(type: 'readData', callback?: Callback\<ArrayBuffer>): void;|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：audio；<br>API声明： enum AudioChannelLayout<br>差异内容： enum AudioChannelLayout|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_UNKNOWN = 0x0<br>差异内容：CH_LAYOUT_UNKNOWN = 0x0|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_MONO = 0x4<br>差异内容：CH_LAYOUT_MONO = 0x4|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_STEREO = 0x3<br>差异内容：CH_LAYOUT_STEREO = 0x3|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_STEREO_DOWNMIX = 0x60000000<br>差异内容：CH_LAYOUT_STEREO_DOWNMIX = 0x60000000|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_2POINT1 = 0xB<br>差异内容：CH_LAYOUT_2POINT1 = 0xB|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_3POINT0 = 0x103<br>差异内容：CH_LAYOUT_3POINT0 = 0x103|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_SURROUND = 0x7<br>差异内容：CH_LAYOUT_SURROUND = 0x7|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_3POINT1 = 0xF<br>差异内容：CH_LAYOUT_3POINT1 = 0xF|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_4POINT0 = 0x107<br>差异内容：CH_LAYOUT_4POINT0 = 0x107|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_QUAD = 0x33<br>差异内容：CH_LAYOUT_QUAD = 0x33|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_QUAD_SIDE = 0x603<br>差异内容：CH_LAYOUT_QUAD_SIDE = 0x603|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_2POINT0POINT2 = 0x3000000003<br>差异内容：CH_LAYOUT_2POINT0POINT2 = 0x3000000003|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER1_ACN_N3D = 0x100000000001<br>差异内容：CH_LAYOUT_AMB_ORDER1_ACN_N3D = 0x100000000001|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER1_ACN_SN3D = 0x100000001001<br>差异内容：CH_LAYOUT_AMB_ORDER1_ACN_SN3D = 0x100000001001|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER1_FUMA = 0x100000000101<br>差异内容：CH_LAYOUT_AMB_ORDER1_FUMA = 0x100000000101|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_4POINT1 = 0x10F<br>差异内容：CH_LAYOUT_4POINT1 = 0x10F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT0 = 0x607<br>差异内容：CH_LAYOUT_5POINT0 = 0x607|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT0_BACK = 0x37<br>差异内容：CH_LAYOUT_5POINT0_BACK = 0x37|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_2POINT1POINT2 = 0x300000000B<br>差异内容：CH_LAYOUT_2POINT1POINT2 = 0x300000000B|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_3POINT0POINT2 = 0x3000000007<br>差异内容：CH_LAYOUT_3POINT0POINT2 = 0x3000000007|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT1 = 0x60F<br>差异内容：CH_LAYOUT_5POINT1 = 0x60F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT1_BACK = 0x3F<br>差异内容：CH_LAYOUT_5POINT1_BACK = 0x3F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_6POINT0 = 0x707<br>差异内容：CH_LAYOUT_6POINT0 = 0x707|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_HEXAGONAL = 0x137<br>差异内容：CH_LAYOUT_HEXAGONAL = 0x137|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_3POINT1POINT2 = 0x500F<br>差异内容：CH_LAYOUT_3POINT1POINT2 = 0x500F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_6POINT0_FRONT = 0x6C3<br>差异内容：CH_LAYOUT_6POINT0_FRONT = 0x6C3|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_6POINT1 = 0x70F<br>差异内容：CH_LAYOUT_6POINT1 = 0x70F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_6POINT1_BACK = 0x13F<br>差异内容：CH_LAYOUT_6POINT1_BACK = 0x13F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_6POINT1_FRONT = 0x6CB<br>差异内容：CH_LAYOUT_6POINT1_FRONT = 0x6CB|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT0 = 0x637<br>差异内容：CH_LAYOUT_7POINT0 = 0x637|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT0_FRONT = 0x6C7<br>差异内容：CH_LAYOUT_7POINT0_FRONT = 0x6C7|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT1 = 0x63F<br>差异内容：CH_LAYOUT_7POINT1 = 0x63F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_OCTAGONAL = 0x737<br>差异内容：CH_LAYOUT_OCTAGONAL = 0x737|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT1POINT2 = 0x300000060F<br>差异内容：CH_LAYOUT_5POINT1POINT2 = 0x300000060F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT1_WIDE = 0x6CF<br>差异内容：CH_LAYOUT_7POINT1_WIDE = 0x6CF|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT1_WIDE_BACK = 0xFF<br>差异内容：CH_LAYOUT_7POINT1_WIDE_BACK = 0xFF|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER2_ACN_N3D = 0x100000000002<br>差异内容：CH_LAYOUT_AMB_ORDER2_ACN_N3D = 0x100000000002|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER2_ACN_SN3D = 0x100000001002<br>差异内容：CH_LAYOUT_AMB_ORDER2_ACN_SN3D = 0x100000001002|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER2_FUMA = 0x100000000102<br>差异内容：CH_LAYOUT_AMB_ORDER2_FUMA = 0x100000000102|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_5POINT1POINT4 = 0x2D60F<br>差异内容：CH_LAYOUT_5POINT1POINT4 = 0x2D60F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT1POINT2 = 0x300000063F<br>差异内容：CH_LAYOUT_7POINT1POINT2 = 0x300000063F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_7POINT1POINT4 = 0x2D63F<br>差异内容：CH_LAYOUT_7POINT1POINT4 = 0x2D63F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_10POINT2 = 0x180005737<br>差异内容：CH_LAYOUT_10POINT2 = 0x180005737|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_9POINT1POINT4 = 0x18002D63F<br>差异内容：CH_LAYOUT_9POINT1POINT4 = 0x18002D63F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_9POINT1POINT6 = 0x318002D63F<br>差异内容：CH_LAYOUT_9POINT1POINT6 = 0x318002D63F|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_HEXADECAGONAL = 0x18003F737<br>差异内容：CH_LAYOUT_HEXADECAGONAL = 0x18003F737|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER3_ACN_N3D = 0x100000000003<br>差异内容：CH_LAYOUT_AMB_ORDER3_ACN_N3D = 0x100000000003|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER3_ACN_SN3D = 0x100000001003<br>差异内容：CH_LAYOUT_AMB_ORDER3_ACN_SN3D = 0x100000001003|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：AudioChannelLayout；<br>API声明：CH_LAYOUT_AMB_ORDER3_FUMA = 0x100000000103<br>差异内容：CH_LAYOUT_AMB_ORDER3_FUMA = 0x100000000103|api/@ohos.multimedia.audio.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace audioHaptic<br>差异内容： declare namespace audioHaptic|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明：function getAudioHapticManager(): AudioHapticManager;<br>差异内容：function getAudioHapticManager(): AudioHapticManager;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明： enum AudioLatencyMode<br>差异内容： enum AudioLatencyMode|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioLatencyMode；<br>API声明：AUDIO_LATENCY_MODE_NORMAL = 0<br>差异内容：AUDIO_LATENCY_MODE_NORMAL = 0|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioLatencyMode；<br>API声明：AUDIO_LATENCY_MODE_FAST = 1<br>差异内容：AUDIO_LATENCY_MODE_FAST = 1|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明： interface AudioHapticPlayerOptions<br>差异内容： interface AudioHapticPlayerOptions|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayerOptions；<br>API声明：muteAudio?: boolean;<br>差异内容：muteAudio?: boolean;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayerOptions；<br>API声明：muteHaptics?: boolean;<br>差异内容：muteHaptics?: boolean;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明： interface AudioHapticManager<br>差异内容： interface AudioHapticManager|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticManager；<br>API声明：registerSource(audioUri: string, hapticUri: string): Promise\<number>;<br>差异内容：registerSource(audioUri: string, hapticUri: string): Promise\<number>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticManager；<br>API声明：unregisterSource(id: number): Promise\<void>;<br>差异内容：unregisterSource(id: number): Promise\<void>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticManager；<br>API声明：setAudioLatencyMode(id: number, latencyMode: AudioLatencyMode): void;<br>差异内容：setAudioLatencyMode(id: number, latencyMode: AudioLatencyMode): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticManager；<br>API声明：setStreamUsage(id: number, usage: audio.StreamUsage): void;<br>差异内容：setStreamUsage(id: number, usage: audio.StreamUsage): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticManager；<br>API声明：createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise\<AudioHapticPlayer>;<br>差异内容：createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise\<AudioHapticPlayer>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明： enum AudioHapticType<br>差异内容： enum AudioHapticType|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticType；<br>API声明：AUDIO_HAPTIC_TYPE_AUDIO = 0<br>差异内容：AUDIO_HAPTIC_TYPE_AUDIO = 0|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticType；<br>API声明：AUDIO_HAPTIC_TYPE_HAPTIC = 1<br>差异内容：AUDIO_HAPTIC_TYPE_HAPTIC = 1|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：audioHaptic；<br>API声明： interface AudioHapticPlayer<br>差异内容： interface AudioHapticPlayer|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：isMuted(type: AudioHapticType): boolean;<br>差异内容：isMuted(type: AudioHapticType): boolean;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：start(): Promise\<void>;<br>差异内容：start(): Promise\<void>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：stop(): Promise\<void>;<br>差异内容：stop(): Promise\<void>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：release(): Promise\<void>;<br>差异内容：release(): Promise\<void>;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：on(type: 'endOfStream', callback: Callback\<void>): void;<br>差异内容：on(type: 'endOfStream', callback: Callback\<void>): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：off(type: 'endOfStream', callback?: Callback\<void>): void;<br>差异内容：off(type: 'endOfStream', callback?: Callback\<void>): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void;<br>差异内容：on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AudioHapticPlayer；<br>API声明：off(type: 'audioInterrupt', callback?: Callback\<audio.InterruptEvent>): void;<br>差异内容：off(type: 'audioInterrupt', callback?: Callback\<audio.InterruptEvent>): void;|api/@ohos.multimedia.audioHaptic.d.ts|
|新增API|NA|类名：AVCastPicker；<br>API声明：@Prop<br>    normalColor?: Color \| number \| string;<br>差异内容：@Prop<br>    normalColor?: Color \| number \| string;|api/@ohos.multimedia.avCastPicker.d.ets|
|新增API|NA|类名：AVCastPicker；<br>API声明：@Prop<br>    activeColor?: Color \| number \| string;<br>差异内容：@Prop<br>    activeColor?: Color \| number \| string;|api/@ohos.multimedia.avCastPicker.d.ets|
|新增API|NA|类名：AVCastPicker；<br>API声明：onStateChange?: (state: AVCastPickerState) => void;<br>差异内容：onStateChange?: (state: AVCastPickerState) => void;|api/@ohos.multimedia.avCastPicker.d.ets|
|新增API|NA|类名：global；<br>API声明： export declare enum AVCastPickerState<br>差异内容： export declare enum AVCastPickerState|api/@ohos.multimedia.avCastPickerParam.d.ts|
|新增API|NA|类名：AVCastPickerState；<br>API声明：STATE_APPEARING<br>差异内容：STATE_APPEARING|api/@ohos.multimedia.avCastPickerParam.d.ts|
|新增API|NA|类名：AVCastPickerState；<br>API声明：STATE_DISAPPEARING<br>差异内容：STATE_DISAPPEARING|api/@ohos.multimedia.avCastPickerParam.d.ts|
|新增API|NA|类名：avSession；<br>API声明： enum ProtocolType<br>差异内容： enum ProtocolType|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：ProtocolType；<br>API声明：TYPE_LOCAL = 0<br>差异内容：TYPE_LOCAL = 0|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：ProtocolType；<br>API声明：TYPE_CAST_PLUS_STREAM = 2<br>差异内容：TYPE_CAST_PLUS_STREAM = 2|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void;<br>差异内容：setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：setCallMetadata(data: CallMetadata): Promise\<void>;<br>差异内容：setCallMetadata(data: CallMetadata): Promise\<void>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void;<br>差异内容：setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：setAVCallState(state: AVCallState): Promise\<void>;<br>差异内容：setAVCallState(state: AVCallState): Promise\<void>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：on(type: 'playFromAssetId', callback: (assetId: number) => void): void;<br>差异内容：on(type: 'playFromAssetId', callback: (assetId: number) => void): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：off(type: 'playFromAssetId', callback?: (assetId: number) => void): void;<br>差异内容：off(type: 'playFromAssetId', callback?: (assetId: number) => void): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：on(type: 'answer', callback: Callback\<void>): void;<br>差异内容：on(type: 'answer', callback: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：off(type: 'answer', callback?: Callback\<void>): void;<br>差异内容：off(type: 'answer', callback?: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：on(type: 'hangUp', callback: Callback\<void>): void;<br>差异内容：on(type: 'hangUp', callback: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：off(type: 'hangUp', callback?: Callback\<void>): void;<br>差异内容：off(type: 'hangUp', callback?: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：on(type: 'toggleCallMute', callback: Callback\<void>): void;<br>差异内容：on(type: 'toggleCallMute', callback: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSession；<br>API声明：off(type: 'toggleCallMute', callback?: Callback\<void>): void;<br>差异内容：off(type: 'toggleCallMute', callback?: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：getValidCommands(callback: AsyncCallback\<Array\<AVCastControlCommandType>>): void;<br>差异内容：getValidCommands(callback: AsyncCallback\<Array\<AVCastControlCommandType>>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：getValidCommands(): Promise\<Array\<AVCastControlCommandType>>;<br>差异内容：getValidCommands(): Promise\<Array\<AVCastControlCommandType>>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：release(callback: AsyncCallback\<void>): void;<br>差异内容：release(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：release(): Promise\<void>;<br>差异内容：release(): Promise\<void>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void;<br>差异内容：on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void;<br>差异内容：off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：on(type: 'endOfStream', callback: Callback\<void>): void;<br>差异内容：on(type: 'endOfStream', callback: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：off(type: 'endOfStream', callback?: Callback\<void>): void;<br>差异内容：off(type: 'endOfStream', callback?: Callback\<void>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>);<br>差异内容：on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>);|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCastController；<br>API声明：off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>);<br>差异内容：off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>);|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：avSession；<br>API声明： enum DisplayTag<br>差异内容： enum DisplayTag|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：DisplayTag；<br>API声明：TAG_AUDIO_VIVID = 1<br>差异内容：TAG_AUDIO_VIVID = 1|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：avQueueId?: string;<br>差异内容：avQueueId?: string;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：avQueueImage?: image.PixelMap \| string;<br>差异内容：avQueueImage?: image.PixelMap \| string;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：filter?: number;<br>差异内容：filter?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：skipIntervals?: SkipIntervals;<br>差异内容：skipIntervals?: SkipIntervals;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：displayTags?: number;<br>差异内容：displayTags?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVMediaDescription；<br>API声明：displayTags?: number;<br>差异内容：displayTags?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVPlaybackState；<br>API声明：maxVolume?: number;<br>差异内容：maxVolume?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVPlaybackState；<br>API声明：muted?: boolean;<br>差异内容：muted?: boolean;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVPlaybackState；<br>API声明：duration?: number;<br>差异内容：duration?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVPlaybackState；<br>API声明：videoWidth?: number;<br>差异内容：videoWidth?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVPlaybackState；<br>API声明：videoHeight?: number;<br>差异内容：videoHeight?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：avSession；<br>API声明： interface CallMetadata<br>差异内容： interface CallMetadata|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallMetadata；<br>API声明：name?: string;<br>差异内容：name?: string;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallMetadata；<br>API声明：phoneNumber?: string;<br>差异内容：phoneNumber?: string;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallMetadata；<br>API声明：avatar?: image.PixelMap;<br>差异内容：avatar?: image.PixelMap;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：avSession；<br>API声明： interface AVCallState<br>差异内容： interface AVCallState|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCallState；<br>API声明：state: CallState;<br>差异内容：state: CallState;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVCallState；<br>API声明：muted: boolean;<br>差异内容：muted: boolean;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：avSession；<br>API声明： enum CallState<br>差异内容： enum CallState|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_IDLE = 0<br>差异内容：CALL_STATE_IDLE = 0|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_INCOMING = 1<br>差异内容：CALL_STATE_INCOMING = 1|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_ACTIVE = 2<br>差异内容：CALL_STATE_ACTIVE = 2|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_DIALING = 3<br>差异内容：CALL_STATE_DIALING = 3|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_WAITING = 4<br>差异内容：CALL_STATE_WAITING = 4|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_HOLDING = 5<br>差异内容：CALL_STATE_HOLDING = 5|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CallState；<br>API声明：CALL_STATE_DISCONNECTING = 6<br>差异内容：CALL_STATE_DISCONNECTING = 6|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：DeviceInfo；<br>API声明：supportedProtocols?: number;<br>差异内容：supportedProtocols?: number;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：LoopMode；<br>API声明：LOOP_MODE_CUSTOM = 4<br>差异内容：LOOP_MODE_CUSTOM = 4|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：avSession；<br>API声明： enum SkipIntervals<br>差异内容： enum SkipIntervals|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：SkipIntervals；<br>API声明：SECONDS_10 = 10<br>差异内容：SECONDS_10 = 10|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：SkipIntervals；<br>API声明：SECONDS_15 = 15<br>差异内容：SECONDS_15 = 15|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：SkipIntervals；<br>API声明：SECONDS_30 = 30<br>差异内容：SECONDS_30 = 30|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：PlaybackState；<br>API声明：PLAYBACK_STATE_IDLE = 10<br>差异内容：PLAYBACK_STATE_IDLE = 10|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：PlaybackState；<br>API声明：PLAYBACK_STATE_BUFFERING = 11<br>差异内容：PLAYBACK_STATE_BUFFERING = 11|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：getAVCallState(callback: AsyncCallback\<AVCallState>): void;<br>差异内容：getAVCallState(callback: AsyncCallback\<AVCallState>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：getAVCallState(): Promise\<AVCallState>;<br>差异内容：getAVCallState(): Promise\<AVCallState>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：getCallMetadata(callback: AsyncCallback\<CallMetadata>): void;<br>差异内容：getCallMetadata(callback: AsyncCallback\<CallMetadata>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：getCallMetadata(): Promise\<CallMetadata>;<br>差异内容：getCallMetadata(): Promise\<CallMetadata>;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> \| 'all', callback: Callback\<CallMetadata>): void;<br>差异内容：on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> \| 'all', callback: Callback\<CallMetadata>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void;<br>差异内容：off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：on(type: 'callStateChange', filter: Array\<keyof AVCallState> \| 'all', callback: Callback\<AVCallState>): void;<br>差异内容：on(type: 'callStateChange', filter: Array\<keyof AVCallState> \| 'all', callback: Callback\<AVCallState>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：AVSessionController；<br>API声明：off(type: 'callStateChange', callback?: Callback\<AVCallState>): void;<br>差异内容：off(type: 'callStateChange', callback?: Callback\<AVCallState>): void;|api/@ohos.multimedia.avsession.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode>;<br>差异内容：getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：createSession\<T extends Session>(mode: SceneMode): T;<br>差异内容：createSession\<T extends Session>(mode: SceneMode): T;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：isTorchSupported(): boolean;<br>差异内容：isTorchSupported(): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：isTorchModeSupported(mode: TorchMode): boolean;<br>差异内容：isTorchModeSupported(mode: TorchMode): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：getTorchMode(): TorchMode;<br>差异内容：getTorchMode(): TorchMode;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：setTorchMode(mode: TorchMode): void;<br>差异内容：setTorchMode(mode: TorchMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：on(type: 'torchStatusChange', callback: AsyncCallback\<TorchStatusInfo>): void;<br>差异内容：on(type: 'torchStatusChange', callback: AsyncCallback\<TorchStatusInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraManager；<br>API声明：off(type: 'torchStatusChange', callback?: AsyncCallback\<TorchStatusInfo>): void;<br>差异内容：off(type: 'torchStatusChange', callback?: AsyncCallback\<TorchStatusInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface TorchStatusInfo<br>差异内容： interface TorchStatusInfo|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchStatusInfo；<br>API声明：readonly isTorchAvailable: boolean;<br>差异内容：readonly isTorchAvailable: boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchStatusInfo；<br>API声明：readonly isTorchActive: boolean;<br>差异内容：readonly isTorchActive: boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchStatusInfo；<br>API声明：readonly torchLevel: number;<br>差异内容：readonly torchLevel: number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： enum TorchMode<br>差异内容： enum TorchMode|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchMode；<br>API声明：OFF = 0<br>差异内容：OFF = 0|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchMode；<br>API声明：ON = 1<br>差异内容：ON = 1|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：TorchMode；<br>API声明：AUTO = 2<br>差异内容：AUTO = 2|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraPosition；<br>API声明：CAMERA_POSITION_FOLD_INNER = 3<br>差异内容：CAMERA_POSITION_FOLD_INNER = 3|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： enum SceneMode<br>差异内容： enum SceneMode|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：SceneMode；<br>API声明：NORMAL_PHOTO = 1<br>差异内容：NORMAL_PHOTO = 1|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：SceneMode；<br>API声明：NORMAL_VIDEO = 2<br>差异内容：NORMAL_VIDEO = 2|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraFormat；<br>API声明：CAMERA_FORMAT_YCBCR_P010<br>差异内容：CAMERA_FORMAT_YCBCR_P010|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CameraFormat；<br>API声明：CAMERA_FORMAT_YCRCB_P010<br>差异内容：CAMERA_FORMAT_YCRCB_P010|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Flash<br>差异内容： interface Flash|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Flash；<br>API声明：hasFlash(): boolean;<br>差异内容：hasFlash(): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Flash；<br>API声明：isFlashModeSupported(flashMode: FlashMode): boolean;<br>差异内容：isFlashModeSupported(flashMode: FlashMode): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Flash；<br>API声明：getFlashMode(): FlashMode;<br>差异内容：getFlashMode(): FlashMode;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Flash；<br>API声明：setFlashMode(flashMode: FlashMode): void;<br>差异内容：setFlashMode(flashMode: FlashMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface AutoExposure<br>差异内容： interface AutoExposure|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：isExposureModeSupported(aeMode: ExposureMode): boolean;<br>差异内容：isExposureModeSupported(aeMode: ExposureMode): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：getExposureMode(): ExposureMode;<br>差异内容：getExposureMode(): ExposureMode;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：setExposureMode(aeMode: ExposureMode): void;<br>差异内容：setExposureMode(aeMode: ExposureMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：getMeteringPoint(): Point;<br>差异内容：getMeteringPoint(): Point;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：setMeteringPoint(point: Point): void;<br>差异内容：setMeteringPoint(point: Point): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：getExposureBiasRange(): Array\<number>;<br>差异内容：getExposureBiasRange(): Array\<number>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：setExposureBias(exposureBias: number): void;<br>差异内容：setExposureBias(exposureBias: number): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：AutoExposure；<br>API声明：getExposureValue(): number;<br>差异内容：getExposureValue(): number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Focus<br>差异内容： interface Focus|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：isFocusModeSupported(afMode: FocusMode): boolean;<br>差异内容：isFocusModeSupported(afMode: FocusMode): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：getFocusMode(): FocusMode;<br>差异内容：getFocusMode(): FocusMode;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：setFocusMode(afMode: FocusMode): void;<br>差异内容：setFocusMode(afMode: FocusMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：setFocusPoint(point: Point): void;<br>差异内容：setFocusPoint(point: Point): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：getFocusPoint(): Point;<br>差异内容：getFocusPoint(): Point;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Focus；<br>API声明：getFocalLength(): number;<br>差异内容：getFocalLength(): number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： enum SmoothZoomMode<br>差异内容： enum SmoothZoomMode|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：SmoothZoomMode；<br>API声明：NORMAL = 0<br>差异内容：NORMAL = 0|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface SmoothZoomInfo<br>差异内容： interface SmoothZoomInfo|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：SmoothZoomInfo；<br>API声明：duration: number;<br>差异内容：duration: number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Zoom<br>差异内容： interface Zoom|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Zoom；<br>API声明：getZoomRatioRange(): Array\<number>;<br>差异内容：getZoomRatioRange(): Array\<number>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Zoom；<br>API声明：getZoomRatio(): number;<br>差异内容：getZoomRatio(): number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Zoom；<br>API声明：setZoomRatio(zoomRatio: number): void;<br>差异内容：setZoomRatio(zoomRatio: number): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Zoom；<br>API声明：setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void;<br>差异内容：setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Stabilization<br>差异内容： interface Stabilization|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Stabilization；<br>API声明：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;<br>差异内容：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Stabilization；<br>API声明：getActiveVideoStabilizationMode(): VideoStabilizationMode;<br>差异内容：getActiveVideoStabilizationMode(): VideoStabilizationMode;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Stabilization；<br>API声明：setVideoStabilizationMode(mode: VideoStabilizationMode): void;<br>差异内容：setVideoStabilizationMode(mode: VideoStabilizationMode): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Session<br>差异内容： interface Session|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：beginConfig(): void;<br>差异内容：beginConfig(): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：commitConfig(callback: AsyncCallback\<void>): void;<br>差异内容：commitConfig(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：commitConfig(): Promise\<void>;<br>差异内容：commitConfig(): Promise\<void>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：canAddInput(cameraInput: CameraInput): boolean;<br>差异内容：canAddInput(cameraInput: CameraInput): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：addInput(cameraInput: CameraInput): void;<br>差异内容：addInput(cameraInput: CameraInput): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：removeInput(cameraInput: CameraInput): void;<br>差异内容：removeInput(cameraInput: CameraInput): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：canAddOutput(cameraOutput: CameraOutput): boolean;<br>差异内容：canAddOutput(cameraOutput: CameraOutput): boolean;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：addOutput(cameraOutput: CameraOutput): void;<br>差异内容：addOutput(cameraOutput: CameraOutput): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：removeOutput(cameraOutput: CameraOutput): void;<br>差异内容：removeOutput(cameraOutput: CameraOutput): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：start(callback: AsyncCallback\<void>): void;<br>差异内容：start(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：start(): Promise\<void>;<br>差异内容：start(): Promise\<void>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：stop(callback: AsyncCallback\<void>): void;<br>差异内容：stop(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：stop(): Promise\<void>;<br>差异内容：stop(): Promise\<void>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：release(callback: AsyncCallback\<void>): void;<br>差异内容：release(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Session；<br>API声明：release(): Promise\<void>;<br>差异内容：release(): Promise\<void>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface PhotoSession<br>差异内容： interface PhotoSession|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：on(type: 'error', callback: ErrorCallback): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：off(type: 'error', callback?: ErrorCallback): void;<br>差异内容：off(type: 'error', callback?: ErrorCallback): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;<br>差异内容：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;<br>差异内容：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo>): void;<br>差异内容：on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoSession；<br>API声明：off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo>): void;<br>差异内容：off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface VideoSession<br>差异内容： interface VideoSession|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：on(type: 'error', callback: ErrorCallback): void;<br>差异内容：on(type: 'error', callback: ErrorCallback): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：off(type: 'error', callback?: ErrorCallback): void;<br>差异内容：off(type: 'error', callback?: ErrorCallback): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;<br>差异内容：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;<br>差异内容：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo>): void;<br>差异内容：on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：VideoSession；<br>API声明：off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo>): void;<br>差异内容：off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface Photo<br>差异内容： interface Photo|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Photo；<br>API声明：main: image.Image;<br>差异内容：main: image.Image;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：Photo；<br>API声明：release(): Promise\<void>;<br>差异内容：release(): Promise\<void>;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoOutput；<br>API声明：on(type: 'photoAvailable', callback: AsyncCallback\<Photo>): void;<br>差异内容：on(type: 'photoAvailable', callback: AsyncCallback\<Photo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoOutput；<br>API声明：off(type: 'photoAvailable', callback?: AsyncCallback\<Photo>): void;<br>差异内容：off(type: 'photoAvailable', callback?: AsyncCallback\<Photo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoOutput；<br>API声明：on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo>): void;<br>差异内容：on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：PhotoOutput；<br>API声明：off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo>): void;<br>差异内容：off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo>): void;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：camera；<br>API声明： interface CaptureStartInfo<br>差异内容： interface CaptureStartInfo|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CaptureStartInfo；<br>API声明：captureId: number;<br>差异内容：captureId: number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：CaptureStartInfo；<br>API声明：time: number;<br>差异内容：time: number;|api/@ohos.multimedia.camera.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace cameraPicker<br>差异内容： declare namespace cameraPicker|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：cameraPicker；<br>API声明： class PickerProfile<br>差异内容： class PickerProfile|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerProfile；<br>API声明：cameraPosition: camera.CameraPosition;<br>差异内容：cameraPosition: camera.CameraPosition;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerProfile；<br>API声明：saveUri?: string;<br>差异内容：saveUri?: string;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerProfile；<br>API声明：videoDuration?: number;<br>差异内容：videoDuration?: number;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：cameraPicker；<br>API声明： enum PickerMediaType<br>差异内容： enum PickerMediaType|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerMediaType；<br>API声明：PHOTO = 'photo'<br>差异内容：PHOTO = 'photo'|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerMediaType；<br>API声明：VIDEO = 'video'<br>差异内容：VIDEO = 'video'|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：cameraPicker；<br>API声明： class PickerResult<br>差异内容： class PickerResult|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerResult；<br>API声明：resultCode: number;<br>差异内容：resultCode: number;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerResult；<br>API声明：resultUri: string;<br>差异内容：resultUri: string;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：PickerResult；<br>API声明：mediaType: PickerMediaType;<br>差异内容：mediaType: PickerMediaType;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：cameraPicker；<br>API声明：function pick(context: Context, mediaTypes: Array\<PickerMediaType>, pickerProfile: PickerProfile): Promise\<PickerResult>;<br>差异内容：function pick(context: Context, mediaTypes: Array\<PickerMediaType>, pickerProfile: PickerProfile): Promise\<PickerResult>;|api/@ohos.multimedia.cameraPicker.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace drm<br>差异内容： declare namespace drm|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum DrmErrorCode<br>差异内容： enum DrmErrorCode|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：DrmErrorCode；<br>API声明：ERROR_UNKNOWN = 24700101<br>差异内容：ERROR_UNKNOWN = 24700101|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：DrmErrorCode；<br>API声明：MAX_SYSTEM_NUM_REACHED = 24700103<br>差异内容：MAX_SYSTEM_NUM_REACHED = 24700103|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：DrmErrorCode；<br>API声明：MAX_SESSION_NUM_REACHED = 24700104<br>差异内容：MAX_SESSION_NUM_REACHED = 24700104|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：DrmErrorCode；<br>API声明：SERVICE_FATAL_ERROR = 24700201<br>差异内容：SERVICE_FATAL_ERROR = 24700201|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum PreDefinedConfigName<br>差异内容： enum PreDefinedConfigName|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_DEVICE_VENDOR = 'vendor'<br>差异内容：CONFIG_DEVICE_VENDOR = 'vendor'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_DEVICE_VERSION = 'version'<br>差异内容：CONFIG_DEVICE_VERSION = 'version'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_DEVICE_DESCRIPTION = 'description'<br>差异内容：CONFIG_DEVICE_DESCRIPTION = 'description'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_DEVICE_ALGORITHMS = 'algorithms'<br>差异内容：CONFIG_DEVICE_ALGORITHMS = 'algorithms'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_DEVICE_UNIQUE_ID = 'deviceUniqueId'<br>差异内容：CONFIG_DEVICE_UNIQUE_ID = 'deviceUniqueId'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_SESSION_MAX = 'maxSessionNum'<br>差异内容：CONFIG_SESSION_MAX = 'maxSessionNum'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PreDefinedConfigName；<br>API声明：CONFIG_SESSION_CURRENT = 'currentSessionNum'<br>差异内容：CONFIG_SESSION_CURRENT = 'currentSessionNum'|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum MediaKeyType<br>差异内容： enum MediaKeyType|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyType；<br>API声明：MEDIA_KEY_TYPE_OFFLINE = 0<br>差异内容：MEDIA_KEY_TYPE_OFFLINE = 0|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyType；<br>API声明：MEDIA_KEY_TYPE_ONLINE<br>差异内容：MEDIA_KEY_TYPE_ONLINE|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum OfflineMediaKeyStatus<br>差异内容： enum OfflineMediaKeyStatus|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：OfflineMediaKeyStatus；<br>API声明：OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0<br>差异内容：OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：OfflineMediaKeyStatus；<br>API声明：OFFLINE_MEDIA_KEY_STATUS_USABLE = 1<br>差异内容：OFFLINE_MEDIA_KEY_STATUS_USABLE = 1|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：OfflineMediaKeyStatus；<br>API声明：OFFLINE_MEDIA_KEY_STATUS_INACTIVE = 2<br>差异内容：OFFLINE_MEDIA_KEY_STATUS_INACTIVE = 2|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum CertificateStatus<br>差异内容： enum CertificateStatus|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：CertificateStatus；<br>API声明：CERT_STATUS_PROVISIONED = 0<br>差异内容：CERT_STATUS_PROVISIONED = 0|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：CertificateStatus；<br>API声明：CERT_STATUS_NOT_PROVISIONED<br>差异内容：CERT_STATUS_NOT_PROVISIONED|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：CertificateStatus；<br>API声明：CERT_STATUS_EXPIRED<br>差异内容：CERT_STATUS_EXPIRED|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：CertificateStatus；<br>API声明：CERT_STATUS_INVALID<br>差异内容：CERT_STATUS_INVALID|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：CertificateStatus；<br>API声明：CERT_STATUS_UNAVAILABLE<br>差异内容：CERT_STATUS_UNAVAILABLE|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum MediaKeyRequestType<br>差异内容： enum MediaKeyRequestType|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0<br>差异内容：MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_INITIAL = 1<br>差异内容：MEDIA_KEY_REQUEST_TYPE_INITIAL = 1|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_RENEWAL = 2<br>差异内容：MEDIA_KEY_REQUEST_TYPE_RENEWAL = 2|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_RELEASE = 3<br>差异内容：MEDIA_KEY_REQUEST_TYPE_RELEASE = 3|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_NONE = 4<br>差异内容：MEDIA_KEY_REQUEST_TYPE_NONE = 4|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequestType；<br>API声明：MEDIA_KEY_REQUEST_TYPE_UPDATE = 5<br>差异内容：MEDIA_KEY_REQUEST_TYPE_UPDATE = 5|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： enum ContentProtectionLevel<br>差异内容： enum ContentProtectionLevel|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ContentProtectionLevel；<br>API声明：CONTENT_PROTECTION_LEVEL_UNKNOWN = 0<br>差异内容：CONTENT_PROTECTION_LEVEL_UNKNOWN = 0|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ContentProtectionLevel；<br>API声明：CONTENT_PROTECTION_LEVEL_SW_CRYPTO<br>差异内容：CONTENT_PROTECTION_LEVEL_SW_CRYPTO|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ContentProtectionLevel；<br>API声明：CONTENT_PROTECTION_LEVEL_HW_CRYPTO<br>差异内容：CONTENT_PROTECTION_LEVEL_HW_CRYPTO|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ContentProtectionLevel；<br>API声明：CONTENT_PROTECTION_LEVEL_ENHANCED_HW<br>差异内容：CONTENT_PROTECTION_LEVEL_ENHANCED_HW|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ContentProtectionLevel；<br>API声明：CONTENT_PROTECTION_LEVEL_MAX<br>差异内容：CONTENT_PROTECTION_LEVEL_MAX|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface ProvisionRequest<br>差异内容： interface ProvisionRequest|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ProvisionRequest；<br>API声明：data: Uint8Array;<br>差异内容：data: Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：ProvisionRequest；<br>API声明：defaultURL: string;<br>差异内容：defaultURL: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface OptionsData<br>差异内容： interface OptionsData|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：OptionsData；<br>API声明：name: string;<br>差异内容：name: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：OptionsData；<br>API声明：value: string;<br>差异内容：value: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface MediaKeyRequest<br>差异内容： interface MediaKeyRequest|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequest；<br>API声明：mediaKeyRequestType: MediaKeyRequestType;<br>差异内容：mediaKeyRequestType: MediaKeyRequestType;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequest；<br>API声明：data: Uint8Array;<br>差异内容：data: Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyRequest；<br>API声明：defaultURL: string;<br>差异内容：defaultURL: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface EventInfo<br>差异内容： interface EventInfo|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：EventInfo；<br>API声明：info: Uint8Array;<br>差异内容：info: Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：EventInfo；<br>API声明：extraInfo: string;<br>差异内容：extraInfo: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface StatisticKeyValue<br>差异内容： interface StatisticKeyValue|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：StatisticKeyValue；<br>API声明：name: string;<br>差异内容：name: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：StatisticKeyValue；<br>API声明：value: string;<br>差异内容：value: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface MediaKeyStatus<br>差异内容： interface MediaKeyStatus|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyStatus；<br>API声明：name: string;<br>差异内容：name: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeyStatus；<br>API声明：value: string;<br>差异内容：value: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface KeysInfo<br>差异内容： interface KeysInfo|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：KeysInfo；<br>API声明：keyId: Uint8Array;<br>差异内容：keyId: Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：KeysInfo；<br>API声明：value: string;<br>差异内容：value: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface MediaKeySystemInfo<br>差异内容： interface MediaKeySystemInfo|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystemInfo；<br>API声明：uuid: string;<br>差异内容：uuid: string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystemInfo；<br>API声明：pssh: Uint8Array;<br>差异内容：pssh: Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明：function createMediaKeySystem(name: string): MediaKeySystem;<br>差异内容：function createMediaKeySystem(name: string): MediaKeySystem;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明：function isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean;<br>差异内容：function isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明：function isMediaKeySystemSupported(name: string, mimeType: string): boolean;<br>差异内容：function isMediaKeySystemSupported(name: string, mimeType: string): boolean;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明：function isMediaKeySystemSupported(name: string): boolean;<br>差异内容：function isMediaKeySystemSupported(name: string): boolean;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface MediaKeySystem<br>差异内容： interface MediaKeySystem|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getConfigurationString(configName: string): string;<br>差异内容：getConfigurationString(configName: string): string;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：setConfigurationString(configName: string, value: string): void;<br>差异内容：setConfigurationString(configName: string, value: string): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getConfigurationByteArray(configName: string): Uint8Array;<br>差异内容：getConfigurationByteArray(configName: string): Uint8Array;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：setConfigurationByteArray(configName: string, value: Uint8Array): void;<br>差异内容：setConfigurationByteArray(configName: string, value: Uint8Array): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getStatistics(): StatisticKeyValue[];<br>差异内容：getStatistics(): StatisticKeyValue[];|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getMaxContentProtectionLevel(): ContentProtectionLevel;<br>差异内容：getMaxContentProtectionLevel(): ContentProtectionLevel;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：generateKeySystemRequest(): Promise\<ProvisionRequest>;<br>差异内容：generateKeySystemRequest(): Promise\<ProvisionRequest>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：processKeySystemResponse(response: Uint8Array): Promise\<void>;<br>差异内容：processKeySystemResponse(response: Uint8Array): Promise\<void>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getCertificateStatus(): CertificateStatus;<br>差异内容：getCertificateStatus(): CertificateStatus;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void;<br>差异内容：on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void;<br>差异内容：off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：createMediaKeySession(level: ContentProtectionLevel): MediaKeySession;<br>差异内容：createMediaKeySession(level: ContentProtectionLevel): MediaKeySession;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：createMediaKeySession(): MediaKeySession;<br>差异内容：createMediaKeySession(): MediaKeySession;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getOfflineMediaKeyIds(): Uint8Array[];<br>差异内容：getOfflineMediaKeyIds(): Uint8Array[];|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus;<br>差异内容：getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：clearOfflineMediaKeys(mediaKeyId: Uint8Array): void;<br>差异内容：clearOfflineMediaKeys(mediaKeyId: Uint8Array): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySystem；<br>API声明：destroy(): void;<br>差异内容：destroy(): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：drm；<br>API声明： interface MediaKeySession<br>差异内容： interface MediaKeySession|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise\<MediaKeyRequest>;<br>差异内容：generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise\<MediaKeyRequest>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：processMediaKeyResponse(response: Uint8Array): Promise\<Uint8Array>;<br>差异内容：processMediaKeyResponse(response: Uint8Array): Promise\<Uint8Array>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：checkMediaKeyStatus(): MediaKeyStatus[];<br>差异内容：checkMediaKeyStatus(): MediaKeyStatus[];|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：clearMediaKeys(): void;<br>差异内容：clearMediaKeys(): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：generateOfflineReleaseRequest(mediaKeyId: Uint8Array): Promise\<Uint8Array>;<br>差异内容：generateOfflineReleaseRequest(mediaKeyId: Uint8Array): Promise\<Uint8Array>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise\<void>;<br>差异内容：processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise\<void>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise\<void>;<br>差异内容：restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise\<void>;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：getContentProtectionLevel(): ContentProtectionLevel;<br>差异内容：getContentProtectionLevel(): ContentProtectionLevel;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：requireSecureDecoderModule(mimeType: string): boolean;<br>差异内容：requireSecureDecoderModule(mimeType: string): boolean;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void;<br>差异内容：on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void;<br>差异内容：off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void;<br>差异内容：on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void;<br>差异内容：off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void;<br>差异内容：on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void;<br>差异内容：off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void;<br>差异内容：on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void;<br>差异内容：off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void;<br>差异内容：on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void;<br>差异内容：off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：MediaKeySession；<br>API声明：destroy(): void;<br>差异内容：destroy(): void;|api/@ohos.multimedia.drm.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：ROLL_ANGLE = 'HwMnoteRollAngle'<br>差异内容：ROLL_ANGLE = 'HwMnoteRollAngle'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：PITCH_ANGLE = 'HwMnotePitchAngle'<br>差异内容：PITCH_ANGLE = 'HwMnotePitchAngle'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_FOOD_CONF = 'HwMnoteSceneFoodConf'<br>差异内容：SCENE_FOOD_CONF = 'HwMnoteSceneFoodConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_STAGE_CONF = 'HwMnoteSceneStageConf'<br>差异内容：SCENE_STAGE_CONF = 'HwMnoteSceneStageConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_BLUE_SKY_CONF = 'HwMnoteSceneBlueSkyConf'<br>差异内容：SCENE_BLUE_SKY_CONF = 'HwMnoteSceneBlueSkyConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_GREEN_PLANT_CONF = 'HwMnoteSceneGreenPlantConf'<br>差异内容：SCENE_GREEN_PLANT_CONF = 'HwMnoteSceneGreenPlantConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_BEACH_CONF = 'HwMnoteSceneBeachConf'<br>差异内容：SCENE_BEACH_CONF = 'HwMnoteSceneBeachConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_SNOW_CONF = 'HwMnoteSceneSnowConf'<br>差异内容：SCENE_SNOW_CONF = 'HwMnoteSceneSnowConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_SUNSET_CONF = 'HwMnoteSceneSunsetConf'<br>差异内容：SCENE_SUNSET_CONF = 'HwMnoteSceneSunsetConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_FLOWERS_CONF = 'HwMnoteSceneFlowersConf'<br>差异内容：SCENE_FLOWERS_CONF = 'HwMnoteSceneFlowersConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_NIGHT_CONF = 'HwMnoteSceneNightConf'<br>差异内容：SCENE_NIGHT_CONF = 'HwMnoteSceneNightConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：SCENE_TEXT_CONF = 'HwMnoteSceneTextConf'<br>差异内容：SCENE_TEXT_CONF = 'HwMnoteSceneTextConf'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：FACE_COUNT = 'HwMnoteFaceCount'<br>差异内容：FACE_COUNT = 'HwMnoteFaceCount'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PropertyKey；<br>API声明：FOCUS_MODE = 'HwMnoteFocusMode'<br>差异内容：FOCUS_MODE = 'HwMnoteFocusMode'|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImageInfo；<br>API声明：stride: number;<br>差异内容：stride: number;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：image；<br>API声明： interface ImagePropertyOptions<br>差异内容： interface ImagePropertyOptions|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePropertyOptions；<br>API声明：index?: number;<br>差异内容：index?: number;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePropertyOptions；<br>API声明：defaultValue?: string;<br>差异内容：defaultValue?: string;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：DecodingOptions；<br>API声明：desiredColorSpace?: colorSpaceManager.ColorSpaceManager;<br>差异内容：desiredColorSpace?: colorSpaceManager.ColorSpaceManager;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：image；<br>API声明：function createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap;<br>差异内容：function createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：image；<br>API声明：function createPixelMapFromSurface(surfaceId: string, region: Region): Promise\<PixelMap>;<br>差异内容：function createPixelMapFromSurface(surfaceId: string, region: Region): Promise\<PixelMap>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PixelMap；<br>API声明：readonly isStrideAlignment: boolean;<br>差异内容：readonly isStrideAlignment: boolean;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PixelMap；<br>API声明：applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void;<br>差异内容：applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：PixelMap；<br>API声明：applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>;<br>差异内容：applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePacker；<br>API声明：packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void;<br>差异内容：packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePacker；<br>API声明：packToFile(source: ImageSource, fd: number, options: PackingOption): Promise\<void>;<br>差异内容：packToFile(source: ImageSource, fd: number, options: PackingOption): Promise\<void>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePacker；<br>API声明：packToFile(source: PixelMap, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void;<br>差异内容：packToFile(source: PixelMap, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：ImagePacker；<br>API声明：packToFile(source: PixelMap, fd: number, options: PackingOption): Promise\<void>;<br>差异内容：packToFile(source: PixelMap, fd: number, options: PackingOption): Promise\<void>;|api/@ohos.multimedia.image.d.ts|
|新增API|NA|类名：media；<br>API声明：function createAVMetadataExtractor(): Promise\<AVMetadataExtractor>;<br>差异内容：function createAVMetadataExtractor(): Promise\<AVMetadataExtractor>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：media；<br>API声明：function createAVMetadataExtractor(callback: AsyncCallback\<AVMetadataExtractor>): void;<br>差异内容：function createAVMetadataExtractor(callback: AsyncCallback\<AVMetadataExtractor>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：media；<br>API声明： interface AVMetadataExtractor<br>差异内容： interface AVMetadataExtractor|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：fdSrc?: AVFileDescriptor;<br>差异内容：fdSrc?: AVFileDescriptor;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：dataSrc?: AVDataSrcDescriptor;<br>差异内容：dataSrc?: AVDataSrcDescriptor;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：fetchMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>差异内容：fetchMetadata(callback: AsyncCallback\<AVMetadata>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：fetchMetadata(): Promise\<AVMetadata>;<br>差异内容：fetchMetadata(): Promise\<AVMetadata>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：fetchAlbumCover(callback: AsyncCallback\<image.PixelMap>): void;<br>差异内容：fetchAlbumCover(callback: AsyncCallback\<image.PixelMap>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：fetchAlbumCover(): Promise\<image.PixelMap>;<br>差异内容：fetchAlbumCover(): Promise\<image.PixelMap>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：release(callback: AsyncCallback\<void>): void;<br>差异内容：release(callback: AsyncCallback\<void>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadataExtractor；<br>API声明：release(): Promise\<void>;<br>差异内容：release(): Promise\<void>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：media；<br>API声明： interface AVMetadata<br>差异内容： interface AVMetadata|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：album?: string;<br>差异内容：album?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：albumArtist?: string;<br>差异内容：albumArtist?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：artist?: string;<br>差异内容：artist?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：author?: string;<br>差异内容：author?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：dateTime?: string;<br>差异内容：dateTime?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：dateTimeFormat?: string;<br>差异内容：dateTimeFormat?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：composer?: string;<br>差异内容：composer?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：duration?: string;<br>差异内容：duration?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：genre?: string;<br>差异内容：genre?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：hasAudio?: string;<br>差异内容：hasAudio?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：hasVideo?: string;<br>差异内容：hasVideo?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：mimeType?: string;<br>差异内容：mimeType?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：trackCount?: string;<br>差异内容：trackCount?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：sampleRate?: string;<br>差异内容：sampleRate?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：title?: string;<br>差异内容：title?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：videoHeight?: string;<br>差异内容：videoHeight?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：videoWidth?: string;<br>差异内容：videoWidth?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVMetadata；<br>API声明：videoOrientation?: string;<br>差异内容：videoOrientation?: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVErrorCode；<br>API声明：AVERR_AUDIO_INTERRUPTED = 5400107<br>差异内容：AVERR_AUDIO_INTERRUPTED = 5400107|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void;<br>差异内容：setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>;<br>差异内容：getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：on(type: 'mediaKeySystemInfoUpdate', callback: (mediaKeySystemInfo: Array\<drm.MediaKeySystemInfo>) => void): void;<br>差异内容：on(type: 'mediaKeySystemInfoUpdate', callback: (mediaKeySystemInfo: Array\<drm.MediaKeySystemInfo>) => void): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：off(type: 'mediaKeySystemInfoUpdate', callback?: (mediaKeySystemInfo: Array\<drm.MediaKeySystemInfo>) => void): void;<br>差异内容：off(type: 'mediaKeySystemInfoUpdate', callback?: (mediaKeySystemInfo: Array\<drm.MediaKeySystemInfo>) => void): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void;<br>差异内容：on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVPlayer；<br>API声明：off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void;<br>差异内容：off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAVRecorderConfig(callback: AsyncCallback\<AVRecorderConfig>): void;<br>差异内容：getAVRecorderConfig(callback: AsyncCallback\<AVRecorderConfig>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAVRecorderConfig(): Promise\<AVRecorderConfig>;<br>差异内容：getAVRecorderConfig(): Promise\<AVRecorderConfig>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getCurrentAudioCapturerInfo(callback: AsyncCallback\<audio.AudioCapturerChangeInfo>): void;<br>差异内容：getCurrentAudioCapturerInfo(callback: AsyncCallback\<audio.AudioCapturerChangeInfo>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getCurrentAudioCapturerInfo(): Promise\<audio.AudioCapturerChangeInfo>;<br>差异内容：getCurrentAudioCapturerInfo(): Promise\<audio.AudioCapturerChangeInfo>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAudioCapturerMaxAmplitude(callback: AsyncCallback\<number>): void;<br>差异内容：getAudioCapturerMaxAmplitude(callback: AsyncCallback\<number>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAudioCapturerMaxAmplitude(): Promise\<number>;<br>差异内容：getAudioCapturerMaxAmplitude(): Promise\<number>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAvailableEncoder(callback: AsyncCallback\<Array\<EncoderInfo>>): void;<br>差异内容：getAvailableEncoder(callback: AsyncCallback\<Array\<EncoderInfo>>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：getAvailableEncoder(): Promise\<Array\<EncoderInfo>>;<br>差异内容：getAvailableEncoder(): Promise\<Array\<EncoderInfo>>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：on(type: 'audioCapturerChange', callback: Callback\<audio.AudioCapturerChangeInfo>): void;<br>差异内容：on(type: 'audioCapturerChange', callback: Callback\<audio.AudioCapturerChangeInfo>): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorder；<br>API声明：off(type: 'audioCapturerChange'): void;<br>差异内容：off(type: 'audioCapturerChange'): void;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：media；<br>API声明： interface EncoderInfo<br>差异内容： interface EncoderInfo|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：mimeType: CodecMimeType;<br>差异内容：mimeType: CodecMimeType;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：type: string;<br>差异内容：type: string;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：bitRate?: Range;<br>差异内容：bitRate?: Range;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：frameRate?: Range;<br>差异内容：frameRate?: Range;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：width?: Range;<br>差异内容：width?: Range;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：height?: Range;<br>差异内容：height?: Range;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：channels?: Range;<br>差异内容：channels?: Range;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：EncoderInfo；<br>API声明：sampleRate?: Array\<number>;<br>差异内容：sampleRate?: Array\<number>;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：media；<br>API声明： interface Range<br>差异内容： interface Range|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：Range；<br>API声明：min: number;<br>差异内容：min: number;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：Range；<br>API声明：max: number;<br>差异内容：max: number;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：AVRecorderProfile；<br>API声明：isHdr?: boolean;<br>差异内容：isHdr?: boolean;|api/@ohos.multimedia.media.d.ts|
|新增API|NA|类名：CodecMimeType；<br>API声明：VIDEO_HEVC = 'video/hevc'<br>差异内容：VIDEO_HEVC = 'video/hevc'|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：avSession；<br>API声明： interface AVMetadata<br>差异内容：NA|类名：avSession；<br>API声明： interface AVMetadata<br>差异内容：10|api/@ohos.multimedia.avsession.d.ts|
|起始版本有变化|类名：MetadataObjectType；<br>API声明：FACE_DETECTION = 0<br>差异内容：NA|类名：MetadataObjectType；<br>API声明：FACE_DETECTION = 0<br>差异内容：10|api/@ohos.multimedia.camera.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'stateChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'stateChange'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'volumeChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'volumeChange'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'endOfStream'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'endOfStream'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'seekDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'seekDone'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'speedDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'speedDone'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'bitrateDone'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'bitrateDone'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'timeUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'timeUpdate'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'durationUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'durationUpdate'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'bufferingUpdate'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'bufferingUpdate'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'startRenderFrame'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'startRenderFrame'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'videoSizeChange'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'videoSizeChange'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'audioInterrupt'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'audioInterrupt'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'availableBitrates'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'availableBitrates'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|起始版本有变化|类名：AVPlayer；<br>API声明：off(type: 'error'): void;<br>差异内容：NA|类名：AVPlayer；<br>API声明：off(type: 'error'): void;<br>差异内容：9|api/@ohos.multimedia.media.d.ts|
|kit变更|NA|ArkGraphics2D|api/@ohos.effectKit.d.ts|
|kit变更|NA|AudioKit|api/@ohos.multimedia.audio.d.ts|
|kit变更|NA|AVSessionKit|api/@ohos.multimedia.avCastPicker.d.ets|
|kit变更|NA|AVSessionKit|api/@ohos.multimedia.avsession.d.ts|
|kit变更|NA|CameraKit|api/@ohos.multimedia.camera.d.ts|
|kit变更|NA|ImageKit|api/@ohos.multimedia.image.d.ts|
|kit变更|NA|MediaKit|api/@ohos.multimedia.media.d.ts|
|kit变更|NA|MediaLibraryKit|api/@ohos.multimedia.mediaLibrary.d.ts|
