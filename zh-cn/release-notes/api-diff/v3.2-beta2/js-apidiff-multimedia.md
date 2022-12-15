# 媒体子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，媒体子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimedia.audio | AudioRenderer | setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void;<br>setInterruptMode(mode: InterruptMode): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly channelMasks: Array\<number>; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly channelCounts: Array\<number>; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly sampleRates: Array\<number>; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly address: string; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly name: string; | 新增 |
| ohos.multimedia.audio | AudioDeviceDescriptor | readonly id: number; | 新增 |
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly deviceDescriptors: AudioDeviceDescriptors; | 新增 |
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly capturerState: AudioState; | 新增 |
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly capturerInfo: AudioCapturerInfo; | 新增 |
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly clientUid: number; | 新增 |
| ohos.multimedia.audio | AudioCapturerChangeInfo | readonly streamId: number; | 新增 |
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly deviceDescriptors: AudioDeviceDescriptors; | 新增 |
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly rendererState: AudioState; | 新增 |
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly rendererInfo: AudioRendererInfo; | 新增 |
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly clientUid: number; | 新增 |
| ohos.multimedia.audio | AudioRendererChangeInfo | readonly streamId: number; | 新增 |
| ohos.multimedia.audio | AudioStreamManager | off(type: "audioCapturerChange"); | 新增 |
| ohos.multimedia.audio | AudioStreamManager | on(type: "audioCapturerChange", callback: Callback\<AudioCapturerChangeInfoArray>): void; | 新增 |
| ohos.multimedia.audio | AudioStreamManager | off(type: "audioRendererChange"); | 新增 |
| ohos.multimedia.audio | AudioStreamManager | on(type: "audioRendererChange", callback: Callback\<AudioRendererChangeInfoArray>): void; | 新增 |
| ohos.multimedia.audio | AudioStreamManager | getCurrentAudioCapturerInfoArray(callback: AsyncCallback\<AudioCapturerChangeInfoArray>): void;<br>getCurrentAudioCapturerInfoArray(): Promise\<AudioCapturerChangeInfoArray>; | 新增 |
| ohos.multimedia.audio | AudioStreamManager | getCurrentAudioRendererInfoArray(callback: AsyncCallback\<AudioRendererChangeInfoArray>): void;<br>getCurrentAudioRendererInfoArray(): Promise\<AudioRendererChangeInfoArray>; | 新增 |
| ohos.multimedia.audio | AudioManager | getStreamManager(callback: AsyncCallback\<AudioStreamManager>): void;<br>getStreamManager(): Promise\<AudioStreamManager>; | 新增 |
| ohos.multimedia.audio | AudioManager | off(type: 'independentInterrupt', callback?: Callback\<InterruptEvent>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | on(type: 'independentInterrupt', callback: Callback\<InterruptEvent>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | abandonIndependentInterrupt(focusType: FocusType, callback: AsyncCallback\<boolean>): void;<br>abandonIndependentInterrupt(focusType: FocusType): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | AudioManager | requestIndependentInterrupt(focusType: FocusType, callback: AsyncCallback\<boolean>): void;<br>requestIndependentInterrupt(focusType: FocusType): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | InterruptMode | INDEPENDENT_MODE = 1 | 新增 |
| ohos.multimedia.audio | InterruptMode | SHARE_MODE = 0 | 新增 |
| ohos.multimedia.audio | FocusType | FOCUS_TYPE_RECORDING = 0 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_F32LE = 4 | 新增 |
| ohos.multimedia.audio | AudioVolumeType | ALL = 100 | 新增 |
| ohos.multimedia.image | PixelMap | crop(region: Region, callback: AsyncCallback\<void>): void;<br>crop(region: Region): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;<br>flip(horizontal: boolean, vertical: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | rotate(angle: number, callback: AsyncCallback\<void>): void;<br>rotate(angle: number): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | translate(x: number, y: number, callback: AsyncCallback\<void>): void;<br>translate(x: number, y: number): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | scale(x: number, y: number, callback: AsyncCallback\<void>): void;<br>scale(x: number, y: number): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | createAlphaPixelmap(): Promise\<PixelMap>;<br>createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void; | 新增 |
| ohos.multimedia.image | PixelMap | opacity(rate: number, callback: AsyncCallback\<void>): void;<br>opacity(rate: number): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | getDensity(): number; | 新增 |
| ohos.multimedia.image | SourceOptions | sourceSize?: Size; | 新增 |
| ohos.multimedia.image | SourceOptions | sourcePixelFormat?: PixelMapFormat; | 新增 |
| ohos.multimedia.image | SourceOptions | sourceDensity: number; | 新增 |
| ohos.multimedia.media | VideoScaleType | VIDEO_SCALE_TYPE_FIT_CROP | 新增 |
| ohos.multimedia.media | VideoScaleType | VIDEO_SCALE_TYPE_FIT = 0 | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'availableBitratesCollected', callback: (bitrates: Array\<number>) => void): void | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | selectBitrate(bitrate: number): Promise\<number>;<br>selectBitrate(bitrate: number, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | videoScaleType?: VideoScaleType; | 新增 |
| ohos.multimedia.media | VideoPlayer | audioInterruptMode?: audio.InterruptMode; | 新增 |
| ohos.multimedia.media | VideoPlayer | fdSrc: AVFileDescriptor; | 新增 |
| ohos.multimedia.media | AudioPlayer | on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void; | 新增 |
| ohos.multimedia.media | AudioPlayer | audioInterruptMode?: audio.InterruptMode; | 新增 |
| ohos.multimedia.media | AudioPlayer | fdSrc: AVFileDescriptor; | 新增 |
| ohos.multimedia.media | AVFileDescriptor | length?: number | 新增 |
| ohos.multimedia.media | AVFileDescriptor | offset?: number | 新增 |
| ohos.multimedia.media | AVFileDescriptor | fd: number | 新增 |

