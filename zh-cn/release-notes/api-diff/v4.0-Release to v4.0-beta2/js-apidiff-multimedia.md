| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：ContentType;<br>方法or属性：CONTENT_TYPE_ULTRASONIC = 9|NA|@ohos.multimedia.audio.d.ts|
|删除|类名：AVMediaDescription;<br>方法or属性：mediaId: string;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVMediaDescription;<br>方法or属性：icon?: image.PixelMap;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVMediaDescription;<br>方法or属性：iconUri?: string;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：ImageSource;<br>方法or属性：getDelayTime(): Promise\<Array\<number>>;|NA|@ohos.multimedia.image.d.ts|
|删除|类名：ImageSource;<br>方法or属性：getDelayTime(callback: AsyncCallback\<Array\<number>>): void;|NA|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AudioManager;<br>方法or属性：getAudioSceneSync(): AudioScene;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：on(type: 'preferredInputDeviceChangeForCapturerInfo', capturerInfo: AudioCapturerInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：off(type: 'preferredInputDeviceChangeForCapturerInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：isCommunicationDeviceActiveSync(deviceType: CommunicationDeviceType): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredOutputDeviceForRendererInfoSync(rendererInfo: AudioRendererInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfoSync(capturerInfo: AudioCapturerInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioRendererInfoArraySync(): AudioRendererChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioCapturerInfoArraySync(): AudioCapturerChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getAudioEffectInfoArraySync(usage: StreamUsage): AudioEffectInfoArray;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：isActiveSync(volumeType: AudioVolumeType): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupInfosSync(networkId: string): VolumeGroupInfos;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupManagerSync(groupId: number): AudioVolumeGroupManager;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMinVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMaxVolumeSync(volumeType: AudioVolumeType): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMuteSync(volumeType: AudioVolumeType): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getRingerModeSync(): AudioRingMode;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMicrophoneMuteSync(): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getRendererInfoSync(): AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getRenderRateSync(): AudioRendererRate;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setInterruptModeSync(mode: InterruptMode): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCountSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevicesSync(): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：SOURCE_TYPE_WAKEUP = 3|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getCapturerInfoSync(): AudioCapturerInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：assetId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaImage?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVPlaybackStateSync(): AVPlaybackState;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVMetadataSync(): AVMetadata;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueTitleSync(): string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueItemsSync(): Array\<AVQueueItem>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：isActiveSync(): boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getValidCommandsSync(): Array\<AVControlCommandType>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：camera;<br>方法or属性：function getModeManager(context: Context): ModeManager;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：off(type: 'cameraMute', callback?: AsyncCallback\<boolean>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：NONE = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：CLASSIC = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：DAWN = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：PURE = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：GREY = 4|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：NATURAL = 5|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：MORI = 6|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：FAIR = 7|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FilterType;<br>方法or属性：PINK = 8|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：BeautyType;<br>方法or属性：AUTO = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：BeautyType;<br>方法or属性：SKIN_SMOOTH = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：BeautyType;<br>方法or属性：FACE_SLENDER = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：BeautyType;<br>方法or属性：SKIN_TONE = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getSupportedFilters(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getFilter(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setFilter(filter: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getSupportedBeautyTypes(): Array\<BeautyType>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getSupportedBeautyRange(type: BeautyType): Array\<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getBeauty(type: BeautyType): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setBeauty(type: BeautyType, value: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraMode;<br>方法or属性：PORTRAIT = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ModeManager;<br>方法or属性：getSupportedModes(device: CameraDevice): Array\<CameraMode>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ModeManager;<br>方法or属性：getSupportedOutputCapability(device: CameraDevice, mode: CameraMode): CameraOutputCapability;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ModeManager;<br>方法or属性：createCaptureSession(mode: CameraMode): CaptureSession;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PortraitEffect;<br>方法or属性：OFF = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PortraitEffect;<br>方法or属性：CIRCLES = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PortraitSession;<br>方法or属性：getSupportedPortraitEffects(): Array\<PortraitEffect>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PortraitSession;<br>方法or属性：getPortraitEffect(): PortraitEffect;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PortraitSession;<br>方法or属性：setPortraitEffect(effect: PortraitEffect): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：off(type: 'frameStart', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：off(type: 'frameStart', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：off(type: 'frameEnd', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：off(type: 'frameEnd', callback?: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'captureStart', callback?: AsyncCallback\<number>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject>>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(): Promise\<Array\<number>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createSoundPool(<br>    maxStreams: number,<br>    audioRenderInfo: audio.AudioRendererInfo,<br>    callback: AsyncCallback\<SoundPool><br>  ): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type SoundPool = _SoundPool;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type PlayParameters = _PlayParameters;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：off(type: 'audioInterrupt'): void|ringtonePlayer.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：loop?: number;|soundPool.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：rate?: number;|soundPool.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：leftVolume?: number;|soundPool.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：rightVolume?: number;|soundPool.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：priority?: number;|soundPool.d.ts|
|新增|NA|类名：PlayParameters;<br>方法or属性：parallelPlayFlag?: boolean;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：load(uri: string, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：load(uri: string): Promise\<number>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：load(fd: number, offset: number, length: number): Promise\<number>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：play(soundID: number, params: PlayParameters, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：play(soundID: number, callback: AsyncCallback\<number>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：play(soundID: number, params?: PlayParameters): Promise\<number>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：stop(streamID: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：stop(streamID: number): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setLoop(streamID: number, loop: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setLoop(streamID: number, loop: number): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setPriority(streamID: number, priority: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setPriority(streamID: number, priority: number): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setRate(streamID: number, rate: audio.AudioRendererRate): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：unload(soundID: number, callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：unload(soundID: number): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：release(): Promise\<void>;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：on(type: 'loadComplete', callback: Callback\<number>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：on(type: 'playFinished', callback: Callback\<void>): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：off(type: 'loadComplete'): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：off(type: 'playFinished'): void;|soundPool.d.ts|
|新增|NA|类名：SoundPool;<br>方法or属性：off(type: 'error'): void;|soundPool.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：enum ContentType<br>旧版本信息：|类名：ContentType;<br>方法or属性：enum ContentType<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_UNKNOWN = 0<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_UNKNOWN = 0<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_UNKNOWN|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_SPEECH = 1<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_SPEECH = 1<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_MUSIC = 2<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_MUSIC = 2<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MUSIC|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_MOVIE = 3<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_MOVIE = 3<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MOVIE|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_SONIFICATION = 4<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_SONIFICATION = 4<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_NOTIFICATION|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ContentType;<br>方法or属性：CONTENT_TYPE_RINGTONE = 5<br>旧版本信息：|类名：ContentType;<br>方法or属性：CONTENT_TYPE_RINGTONE = 5<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_RINGTONE|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_MEDIA = 1<br>旧版本信息：|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_MEDIA = 1<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_MUSIC|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_NOTIFICATION_RINGTONE = 6<br>旧版本信息：|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_NOTIFICATION_RINGTONE = 6<br>新版本信息：10<br>代替接口： ohos.multimedia.audio.StreamUsage.STREAM_USAGE_RINGTONE|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>旧版本信息：|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>新版本信息：401,6800101,6800301|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;<br>旧版本信息：|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;<br>新版本信息：401,6800101,6800301|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6800101|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;<br>旧版本信息：|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;<br>新版本信息：401,6800101|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void;<br>新版本信息：401|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter?: number): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter?: number): Promise\<void>;<br>新版本信息：401|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：401|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean): Promise\<void>;<br>新版本信息：401|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：on(type: 'playNext', callback: Callback\<void>): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：on(type: 'playNext', callback: Callback\<void>): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：on(type: 'playPrevious', callback: Callback\<void>): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：on(type: 'playPrevious', callback: Callback\<void>): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：on(type: 'seekDone', callback: Callback\<number>): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：on(type: 'seekDone', callback: Callback\<number>): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：off(type: 'mediaItemChange'): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：off(type: 'mediaItemChange'): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：off(type: 'playNext'): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：off(type: 'playNext'): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：off(type: 'playPrevious'): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：off(type: 'playPrevious'): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：off(type: 'seekDone'): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：off(type: 'seekDone'): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVCastController;<br>方法or属性：off(type: 'videoSizeChange'): void;<br>旧版本信息：|类名：AVCastController;<br>方法or属性：off(type: 'videoSizeChange'): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：PixelMap;<br>方法or属性：getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getColorSpace(): colorSpaceManager.ColorSpaceManager;<br>新版本信息：62980101,62980103,62980115|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：PixelMap;<br>方法or属性：setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;<br>新版本信息：62980111,62980115|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：getFrameCount(): Promise\<number>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getFrameCount(): Promise\<number>;<br>新版本信息：62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;<br>新版本信息：62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void;<br>旧版本信息：201,6600101,6600102|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void;<br>新版本信息：201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string): Promise\<AVCastController>;<br>旧版本信息：201,6600101,6600102|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string): Promise\<AVCastController>;<br>新版本信息：201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void;<br>旧版本信息：6600109|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600109|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken): Promise\<void>;<br>旧版本信息：6600109|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken): Promise\<void>;<br>新版本信息：401,6600109|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：6600109|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600109|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string): Promise\<void>;<br>旧版本信息：6600109|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string): Promise\<void>;<br>新版本信息：401,6600109|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVCastController;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：5400101,5400102,5400103,5400104,5400105,5400106|类名：AVCastController;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：401,5400101,5400102,5400103,5400104,5400105,5400106,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVCastController;<br>方法or属性：off(type: 'error'): void;<br>旧版本信息：5400101,5400102,5400103,5400104,5400105,5400106|类名：AVCastController;<br>方法or属性：off(type: 'error'): void;<br>新版本信息：401,5400101,5400102,5400103,5400104,5400105,5400106,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：6600101,6600102,6600103|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number): Promise\<void>;<br>旧版本信息：6600101,6600102,6600103|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number): Promise\<void>;<br>新版本信息：401,6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：AVCastControlCommand;<br>方法or属性：parameter?: media.PlaybackSpeed \| number;|类名：AVCastControlCommand;<br>方法or属性：parameter?: media.PlaybackSpeed \| number \| string \| LoopMode;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：DeviceInfo;<br>方法or属性：castCategory: number;|类名：DeviceInfo;<br>方法or属性：castCategory: AVCastCategory;|@ohos.multimedia.avsession.d.ts|
|跨平台能力有变化|类名：ImageFormat;<br>方法or属性：enum ImageFormat<br>旧版本信息：crossplatform|类名：ImageFormat;<br>方法or属性：enum ImageFormat<br>新版本信息：|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageFormat;<br>方法or属性：YCBCR_422_SP = 1000<br>旧版本信息：crossplatform|类名：ImageFormat;<br>方法or属性：YCBCR_422_SP = 1000<br>新版本信息：|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageFormat;<br>方法or属性：JPEG = 2000<br>旧版本信息：crossplatform|类名：ImageFormat;<br>方法or属性：JPEG = 2000<br>新版本信息：|@ohos.multimedia.image.d.ts|
