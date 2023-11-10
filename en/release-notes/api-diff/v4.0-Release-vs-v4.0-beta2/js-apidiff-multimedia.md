| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_ULTRASONIC = 9|NA|@ohos.multimedia.audio.d.ts|
|Deleted|Class name: AVMediaDescription;<br>Method or attribute name: mediaId: string;|NA|@ohos.multimedia.avsession.d.ts|
|Deleted|Class name: AVMediaDescription;<br>Method or attribute name: icon?: image.PixelMap;|NA|@ohos.multimedia.avsession.d.ts|
|Deleted|Class name: AVMediaDescription;<br>Method or attribute name: iconUri?: string;|NA|@ohos.multimedia.avsession.d.ts|
|Deleted|Class name: ImageSource;<br>Method or attribute name: getDelayTime(): Promise\<Array\<number>>;|NA|@ohos.multimedia.image.d.ts|
|Deleted|Class name: ImageSource;<br>Method or attribute name: getDelayTime(callback: AsyncCallback\<Array\<number>>): void;|NA|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: AudioManager;<br>Method or attribute name: getAudioSceneSync(): AudioScene;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: on(type: 'preferredInputDeviceChangeForCapturerInfo', capturerInfo: AudioCapturerInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: off(type: 'preferredInputDeviceChangeForCapturerInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: isCommunicationDeviceActiveSync(deviceType: CommunicationDeviceType): boolean;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferredOutputDeviceForRendererInfoSync(rendererInfo: AudioRendererInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferredInputDeviceForCapturerInfoSync(capturerInfo: AudioCapturerInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioRendererInfoArraySync(): AudioRendererChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioCapturerInfoArraySync(): AudioCapturerChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getAudioEffectInfoArraySync(usage: StreamUsage): AudioEffectInfoArray;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: isActiveSync(volumeType: AudioVolumeType): boolean;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupInfosSync(networkId: string): VolumeGroupInfos;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupManagerSync(groupId: number): AudioVolumeGroupManager;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMinVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMaxVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMuteSync(volumeType: AudioVolumeType): boolean;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getRingerModeSync(): AudioRingMode;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMicrophoneMuteSync(): boolean;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getRendererInfoSync(): AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getRenderRateSync(): AudioRendererRate;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: setInterruptModeSync(mode: InterruptMode): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getMinStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getMaxStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getUnderflowCountSync(): number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getCurrentOutputDevicesSync(): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: SourceType;<br>Method or attribute name: SOURCE_TYPE_WAKEUP = 3|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getCapturerInfoSync(): AudioCapturerInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMediaDescription;<br>Method or attribute name: assetId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMediaDescription;<br>Method or attribute name: mediaImage?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVPlaybackStateSync(): AVPlaybackState;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVMetadataSync(): AVMetadata;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVQueueTitleSync(): string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVQueueItemsSync(): Array\<AVQueueItem>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: isActiveSync(): boolean;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getValidCommandsSync(): Array\<AVControlCommandType>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: camera;<br>Method or attribute name: function getModeManager(context: Context): ModeManager;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: off(type: 'cameraMute', callback?: AsyncCallback\<boolean>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: NONE = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: CLASSIC = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: DAWN = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: PURE = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: GREY = 4|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: NATURAL = 5|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: MORI = 6|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: FAIR = 7|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FilterType;<br>Method or attribute name: PINK = 8|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: BeautyType;<br>Method or attribute name: AUTO = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: BeautyType;<br>Method or attribute name: SKIN_SMOOTH = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: BeautyType;<br>Method or attribute name: FACE_SLENDER = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: BeautyType;<br>Method or attribute name: SKIN_TONE = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getSupportedFilters(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getFilter(): number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setFilter(filter: number): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getSupportedBeautyTypes(): Array\<BeautyType>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getSupportedBeautyRange(type: BeautyType): Array\<number>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getBeauty(type: BeautyType): number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setBeauty(type: BeautyType, value: number): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraMode;<br>Method or attribute name: PORTRAIT = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ModeManager;<br>Method or attribute name: getSupportedModes(device: CameraDevice): Array\<CameraMode>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ModeManager;<br>Method or attribute name: getSupportedOutputCapability(device: CameraDevice, mode: CameraMode): CameraOutputCapability;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ModeManager;<br>Method or attribute name: createCaptureSession(mode: CameraMode): CaptureSession;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PortraitEffect;<br>Method or attribute name: OFF = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PortraitEffect;<br>Method or attribute name: CIRCLES = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PortraitSession;<br>Method or attribute name: getSupportedPortraitEffects(): Array\<PortraitEffect>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PortraitSession;<br>Method or attribute name: getPortraitEffect(): PortraitEffect;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PortraitSession;<br>Method or attribute name: setPortraitEffect(effect: PortraitEffect): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: off(type: 'frameStart', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: off(type: 'frameStart', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: off(type: 'frameEnd', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: off(type: 'frameEnd', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: off(type: 'captureStart', callback?: AsyncCallback\<number>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject>>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: getDelayTimeList(): Promise\<Array\<number>>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createSoundPool(<br>    maxStreams: number,<br>    audioRenderInfo: audio.AudioRendererInfo,<br>    callback: AsyncCallback\<SoundPool><br>  ): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: type SoundPool = _SoundPool;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: type PlayParameters = _PlayParameters;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: RingtonePlayer;<br>Method or attribute name: off(type: 'audioInterrupt'): void|ringtonePlayer.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: loop?: number;|soundPool.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: rate?: number;|soundPool.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: leftVolume?: number;|soundPool.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: rightVolume?: number;|soundPool.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: priority?: number;|soundPool.d.ts|
|Added|NA|Class name: PlayParameters;<br>Method or attribute name: parallelPlayFlag?: boolean;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: load(uri: string, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: load(uri: string): Promise\<number>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: load(fd: number, offset: number, length: number): Promise\<number>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: play(soundID: number, params: PlayParameters, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: play(soundID: number, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: play(soundID: number, params?: PlayParameters): Promise\<number>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: stop(streamID: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: stop(streamID: number): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setLoop(streamID: number, loop: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setLoop(streamID: number, loop: number): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setPriority(streamID: number, priority: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setPriority(streamID: number, priority: number): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setRate(streamID: number, rate: audio.AudioRendererRate): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: unload(soundID: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: unload(soundID: number): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: release(): Promise\<void>;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: on(type: 'loadComplete', callback: Callback\<number>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: on(type: 'playFinished', callback: Callback\<void>): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: off(type: 'loadComplete'): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: off(type: 'playFinished'): void;|soundPool.d.ts|
|Added|NA|Class name: SoundPool;<br>Method or attribute name: off(type: 'error'): void;|soundPool.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: enum ContentType<br>Old version information: |Class name: ContentType;<br>Method or attribute name: enum ContentType<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_UNKNOWN = 0<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_UNKNOWN = 0<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_UNKNOWN|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_SPEECH = 1<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_SPEECH = 1<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_MUSIC = 2<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_MUSIC = 2<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MUSIC|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_MOVIE = 3<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_MOVIE = 3<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MOVIE|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_SONIFICATION = 4<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_SONIFICATION = 4<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_NOTIFICATION|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_RINGTONE = 5<br>Old version information: |Class name: ContentType;<br>Method or attribute name: CONTENT_TYPE_RINGTONE = 5<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_RINGTONE|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: StreamUsage;<br>Method or attribute name: STREAM_USAGE_MEDIA = 1<br>Old version information: |Class name: StreamUsage;<br>Method or attribute name: STREAM_USAGE_MEDIA = 1<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MUSIC|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: StreamUsage;<br>Method or attribute name: STREAM_USAGE_NOTIFICATION_RINGTONE = 6<br>Old version information: |Class name: StreamUsage;<br>Method or attribute name: STREAM_USAGE_NOTIFICATION_RINGTONE = 6<br>New version information: 10<br>Substitute API: ohos.multimedia.audio.StreamUsage.STREAM_USAGE_RINGTONE|@ohos.multimedia.audio.d.ts|
|Error code added|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>Old version information: |Class name: AudioRoutingManager;<br>Method or attribute name: getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>New version information: 401,6800101,6800301|@ohos.multimedia.audio.d.ts|
|Error code added|Class name: AudioRoutingManager;<br>Method or attribute name: getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;<br>Old version information: |Class name: AudioRoutingManager;<br>Method or attribute name: getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;<br>New version information: 401,6800101,6800301|@ohos.multimedia.audio.d.ts|
|Error code added|Class name: AudioRenderer;<br>Method or attribute name: setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;<br>Old version information: |Class name: AudioRenderer;<br>Method or attribute name: setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;<br>New version information: 401,6800101|@ohos.multimedia.audio.d.ts|
|Error code added|Class name: AudioRenderer;<br>Method or attribute name: setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;<br>Old version information: |Class name: AudioRenderer;<br>Method or attribute name: setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;<br>New version information: 401,6800101|@ohos.multimedia.audio.d.ts|
|Error code added|Class name: avSession;<br>Method or attribute name: function startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void;<br>Old version information: |Class name: avSession;<br>Method or attribute name: function startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void;<br>New version information: 401|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: avSession;<br>Method or attribute name: function startCastDeviceDiscovery(filter?: number): Promise\<void>;<br>Old version information: |Class name: avSession;<br>Method or attribute name: function startCastDeviceDiscovery(filter?: number): Promise\<void>;<br>New version information: 401|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: avSession;<br>Method or attribute name: function setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void;<br>Old version information: |Class name: avSession;<br>Method or attribute name: function setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void;<br>New version information: 401|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: avSession;<br>Method or attribute name: function setDiscoverable(enable: boolean): Promise\<void>;<br>Old version information: |Class name: avSession;<br>Method or attribute name: function setDiscoverable(enable: boolean): Promise\<void>;<br>New version information: 401|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: on(type: 'playNext', callback: Callback\<void>): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: on(type: 'playNext', callback: Callback\<void>): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: on(type: 'playPrevious', callback: Callback\<void>): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: on(type: 'playPrevious', callback: Callback\<void>): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: on(type: 'seekDone', callback: Callback\<number>): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: on(type: 'seekDone', callback: Callback\<number>): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: off(type: 'mediaItemChange'): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: off(type: 'mediaItemChange'): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: off(type: 'playNext'): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: off(type: 'playNext'): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: off(type: 'playPrevious'): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: off(type: 'playPrevious'): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: off(type: 'seekDone'): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: off(type: 'seekDone'): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: AVCastController;<br>Method or attribute name: off(type: 'videoSizeChange'): void;<br>Old version information: |Class name: AVCastController;<br>Method or attribute name: off(type: 'videoSizeChange'): void;<br>New version information: 401,6600101|@ohos.multimedia.avsession.d.ts|
|Error code added|Class name: PixelMap;<br>Method or attribute name: getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>Old version information: |Class name: PixelMap;<br>Method or attribute name: getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>New version information: 62980101,62980103,62980115|@ohos.multimedia.image.d.ts|
|Error code added|Class name: PixelMap;<br>Method or attribute name: setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>Old version information: |Class name: PixelMap;<br>Method or attribute name: setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>New version information: 62980111,62980115|@ohos.multimedia.image.d.ts|
|Error code added|Class name: ImageSource;<br>Method or attribute name: createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>Old version information: |Class name: ImageSource;<br>Method or attribute name: createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>New version information: 62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|Error code added|Class name: ImageSource;<br>Method or attribute name: createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>Old version information: |Class name: ImageSource;<br>Method or attribute name: createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>New version information: 62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|Error code added|Class name: ImageSource;<br>Method or attribute name: createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>Old version information: |Class name: ImageSource;<br>Method or attribute name: createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>New version information: 62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|Error code added|Class name: ImageSource;<br>Method or attribute name: getFrameCount(): Promise\<number>;<br>Old version information: |Class name: ImageSource;<br>Method or attribute name: getFrameCount(): Promise\<number>;<br>New version information: 62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
|Error code added|Class name: ImageSource;<br>Method or attribute name: getFrameCount(callback: AsyncCallback\<number>): void;<br>Old version information: |Class name: ImageSource;<br>Method or attribute name: getFrameCount(callback: AsyncCallback\<number>): void;<br>New version information: 62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
|Error code changed|Class name: avSession;<br>Method or attribute name: function getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void;<br>Old version information: 201,6600101,6600102|Class name: avSession;<br>Method or attribute name: function getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void;<br>New version information: 201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: avSession;<br>Method or attribute name: function getAVCastController(sessionId: string): Promise\<AVCastController>;<br>Old version information: 201,6600101,6600102|Class name: avSession;<br>Method or attribute name: function getAVCastController(sessionId: string): Promise\<AVCastController>;<br>New version information: 201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: avSession;<br>Method or attribute name: function stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void;<br>Old version information: 6600109|Class name: avSession;<br>Method or attribute name: function stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void;<br>New version information: 401,6600109|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: avSession;<br>Method or attribute name: function stopCasting(session: SessionToken): Promise\<void>;<br>Old version information: 6600109|Class name: avSession;<br>Method or attribute name: function stopCasting(session: SessionToken): Promise\<void>;<br>New version information: 401,6600109|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVCastController;<br>Method or attribute name: setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>Old version information: 6600109|Class name: AVCastController;<br>Method or attribute name: setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>New version information: 401,6600109|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVCastController;<br>Method or attribute name: setDisplaySurface(surfaceId: string): Promise\<void>;<br>Old version information: 6600109|Class name: AVCastController;<br>Method or attribute name: setDisplaySurface(surfaceId: string): Promise\<void>;<br>New version information: 401,6600109|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVCastController;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>Old version information: 5400101,5400102,5400103,5400104,5400105,5400106|Class name: AVCastController;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>New version information: 401,5400101,5400102,5400103,5400104,5400105,5400106,6600101|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVCastController;<br>Method or attribute name: off(type: 'error'): void;<br>Old version information: 5400101,5400102,5400103,5400104,5400105,5400106|Class name: AVCastController;<br>Method or attribute name: off(type: 'error'): void;<br>New version information: 401,5400101,5400102,5400103,5400104,5400105,5400106,6600101|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVSessionController;<br>Method or attribute name: skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;<br>Old version information: 6600101,6600102,6600103|Class name: AVSessionController;<br>Method or attribute name: skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;<br>New version information: 401,6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|Error code changed|Class name: AVSessionController;<br>Method or attribute name: skipToQueueItem(itemId: number): Promise\<void>;<br>Old version information: 6600101,6600102,6600103|Class name: AVSessionController;<br>Method or attribute name: skipToQueueItem(itemId: number): Promise\<void>;<br>New version information: 401,6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|Function changed|Class name: AVCastControlCommand;<br>Method or attribute name: parameter?: media.PlaybackSpeed \| number;|Class name: AVCastControlCommand;<br>Method or attribute name: parameter?: media.PlaybackSpeed \| number \| string \| LoopMode;|@ohos.multimedia.avsession.d.ts|
|Function changed|Class name: DeviceInfo;<br>Method or attribute name: castCategory: number;|Class name: DeviceInfo;<br>Method or attribute name: castCategory: AVCastCategory;|@ohos.multimedia.avsession.d.ts|
|Cross-platform capability changed|Class name: ImageFormat;<br>Method or attribute name: enum ImageFormat<br>Old version information: crossplatform|Class name: ImageFormat;<br>Method or attribute name: enum ImageFormat<br>New version information: |@ohos.multimedia.image.d.ts|
|Cross-platform capability changed|Class name: ImageFormat;<br>Method or attribute name: YCBCR_422_SP = 1000<br>Old version information: crossplatform|Class name: ImageFormat;<br>Method or attribute name: YCBCR_422_SP = 1000<br>New version information: |@ohos.multimedia.image.d.ts|
|Cross-platform capability changed|Class name: ImageFormat;<br>Method or attribute name: JPEG = 2000<br>Old version information: crossplatform|Class name: ImageFormat;<br>Method or attribute name: JPEG = 2000<br>New version information: |@ohos.multimedia.image.d.ts|
