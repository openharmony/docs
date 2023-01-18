# JS API Changes of the Multimedia Subsystem

The table below lists the APIs changes of the multimedia subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.multimedia.audio | AudioRenderer | setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void;<br>setInterruptMode(mode: InterruptMode): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly channelMasks: Array\<number>; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly channelCounts: Array\<number>; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly sampleRates: Array\<number>; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly address: string; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly name: string; | Added|
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly id: number; | Added|
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly deviceDescriptors: AudioDeviceDescriptors; | Added|
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly capturerState: AudioState; | Added|
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly capturerInfo: AudioCapturerInfo; | Added|
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly clientUid: number; | Added|
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly streamId: number; | Added|
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly deviceDescriptors: AudioDeviceDescriptors; | Added|
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly rendererState: AudioState; | Added|
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly rendererInfo: AudioRendererInfo; | Added|
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly clientUid: number; | Added|
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly streamId: number; | Added|
| ohos.multimedia.audio | AudioStreamManager | off(type: "audioCapturerChange"); | Added|
| ohos.multimedia.audio | AudioStreamManager | on(type: "audioCapturerChange", callback: Callback\<AudioCapturerChangeInfoArray>): void; | Added|
| ohos.multimedia.audio | AudioStreamManager | off(type: "audioRendererChange"); | Added|
| ohos.multimedia.audio | AudioStreamManager | on(type: "audioRendererChange", callback: Callback\<AudioRendererChangeInfoArray>): void; | Added|
| ohos.multimedia.audio | AudioStreamManager | getCurrentAudioCapturerInfoArray(callback: AsyncCallback\<AudioCapturerChangeInfoArray>): void;<br>getCurrentAudioCapturerInfoArray(): Promise\<AudioCapturerChangeInfoArray>; | Added|
| ohos.multimedia.audio | AudioStreamManager | getCurrentAudioRendererInfoArray(callback: AsyncCallback\<AudioRendererChangeInfoArray>): void;<br>getCurrentAudioRendererInfoArray(): Promise\<AudioRendererChangeInfoArray>; | Added|
| ohos.multimedia.audio | AudioManager | getStreamManager(callback: AsyncCallback\<AudioStreamManager>): void;<br>getStreamManager(): Promise\<AudioStreamManager>; | Added|
| ohos.multimedia.audio | AudioManager | off(type: 'independentInterrupt', callback?: Callback\<InterruptEvent>): void; | Added|
| ohos.multimedia.audio | AudioManager | on(type: 'independentInterrupt', callback: Callback\<InterruptEvent>): void; | Added|
| ohos.multimedia.audio | AudioManager | abandonIndependentInterrupt(focusType: FocusType, callback: AsyncCallback\<boolean>): void;<br>abandonIndependentInterrupt(focusType: FocusType): Promise\<boolean>; | Added|
| ohos.multimedia.audio | AudioManager | requestIndependentInterrupt(focusType: FocusType, callback: AsyncCallback\<boolean>): void;<br>requestIndependentInterrupt(focusType: FocusType): Promise\<boolean>; | Added|
| ohos.multimedia.audio | InterruptMode | INDEPENDENT_MODE = 1 | Added|
| ohos.multimedia.audio | InterruptMode | SHARE_MODE = 0 | Added|
| ohos.multimedia.audio | FocusType | FOCUS_TYPE_RECORDING = 0 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_F32LE = 4 | Added|
| ohos.multimedia.audio | AudioVolumeType | ALL = 100 | Added|
| ohos.multimedia.image | PixelMap | crop(region: Region, callback: AsyncCallback\<void>): void;<br>crop(region: Region): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;<br>flip(horizontal: boolean, vertical: boolean): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | rotate(angle: number, callback: AsyncCallback\<void>): void;<br>rotate(angle: number): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | translate(x: number, y: number, callback: AsyncCallback\<void>): void;<br>translate(x: number, y: number): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | scale(x: number, y: number, callback: AsyncCallback\<void>): void;<br>scale(x: number, y: number): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | createAlphaPixelmap(): Promise\<PixelMap>;<br>createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void; | Added|
| ohos.multimedia.image | PixelMap | opacity(rate: number, callback: AsyncCallback\<void>): void;<br>opacity(rate: number): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | getDensity(): number; | Added|
| ohos.multimedia.image | SourceOptions | sourceSize?: Size; | Added|
| ohos.multimedia.image | SourceOptions | sourcePixelFormat?: PixelMapFormat; | Added|
| ohos.multimedia.image | SourceOptions | sourceDensity: number; | Added|
| ohos.multimedia.media | VideoScaleType | VIDEO_SCALE_TYPE_FIT_CROP | Added|
| ohos.multimedia.media | VideoScaleType | VIDEO_SCALE_TYPE_FIT = 0 | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'availableBitratesCollected', callback: (bitrates: Array\<number>) => void): void | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void; | Added|
| ohos.multimedia.media | VideoPlayer | selectBitrate(bitrate: number): Promise\<number>;<br>selectBitrate(bitrate: number, callback: AsyncCallback\<number>): void; | Added|
| ohos.multimedia.media | VideoPlayer | videoScaleType?: VideoScaleType; | Added|
| ohos.multimedia.media | VideoPlayer | audioInterruptMode?: audio.InterruptMode; | Added|
| ohos.multimedia.media | VideoPlayer | fdSrc: AVFileDescriptor; | Added|
| ohos.multimedia.media | AudioPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void; | Added|
| ohos.multimedia.media | AudioPlayer | audioInterruptMode?: audio.InterruptMode; | Added|
| ohos.multimedia.media | AudioPlayer | fdSrc: AVFileDescriptor; | Added|
| ohos.multimedia.media | AVFileDescriptor | length?: number | Added|
| ohos.multimedia.media | AVFileDescriptor | offset?: number | Added|
| ohos.multimedia.media | AVFileDescriptor | fd: number | Added|
