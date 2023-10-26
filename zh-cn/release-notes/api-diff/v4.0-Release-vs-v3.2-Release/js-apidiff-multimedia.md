| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：avSession;<br>方法or属性：function on(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：avSession;<br>方法or属性：function off(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSession;<br>方法or属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSession;<br>方法or属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSessionController;<br>方法or属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSession;<br>方法or属性：off(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback?: () => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSession;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：AVSessionController;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：OutputDeviceInfo;<br>方法or属性：isRemote: boolean;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：OutputDeviceInfo;<br>方法or属性：audioDeviceId: Array\<number>;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：OutputDeviceInfo;<br>方法or属性：deviceName: Array\<string>;|NA|@ohos.multimedia.avsession.d.ts|
|删除|类名：CameraErrorCode;<br>方法or属性：CONFILICT_CAMERA = 7400107|NA|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：assetId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：title?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：artist?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：duration?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：subtitle?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：description?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getAVPlaybackState(): Promise\<AVPlaybackState>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap, region: Array\<number>): Promise\<ColorPicker>;|@ohos.effectKit.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap, region: Array\<number>, callback: AsyncCallback\<ColorPicker>): void;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：getLargestProportionColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：getHighestSaturationColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：getAverageColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：isBlackOrWhiteOrGrayColor(color: number): boolean;|@ohos.effectKit.d.ts|
|新增|NA|类名：audio;<br>方法or属性：type AudioEffectInfoArray = Array\<Readonly\<AudioEffectMode>>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeType;<br>方法or属性：ALARM = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeType;<br>方法or属性：ACCESSIBILITY = 5|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeType;<br>方法or属性：ULTRASONIC = 10|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_MUSIC = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_ALARM = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_VOICE_MESSAGE = 5|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_RINGTONE = 6|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_NOTIFICATION = 7|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_ACCESSIBILITY = 8|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_SYSTEM = 9|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_MOVIE = 10|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_GAME = 11|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_AUDIOBOOK = 12|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_NAVIGATION = 13|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_DTMF = 14|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_ENFORCED_TONE = 15|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_ULTRASONIC = 16|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererOptions;<br>方法or属性：privacyType?: AudioPrivacyType;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioPrivacyType;<br>方法or属性：PRIVACY_TYPE_PUBLIC = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioPrivacyType;<br>方法or属性：PRIVACY_TYPE_PRIVATE = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeAdjustType;<br>方法or属性：VOLUME_UP = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeAdjustType;<br>方法or属性：VOLUME_DOWN = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioManager;<br>方法or属性：getAudioSceneSync(): AudioScene;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：on(type: 'preferredInputDeviceChangeForCapturerInfo', capturerInfo: AudioCapturerInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：off(type: 'preferredInputDeviceChangeForCapturerInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：isCommunicationDeviceActiveSync(deviceType: CommunicationDeviceType): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredOutputDeviceForRendererInfoSync(rendererInfo: AudioRendererInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getPreferredInputDeviceForCapturerInfoSync(capturerInfo: AudioCapturerInfo): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioRendererInfoArraySync(): AudioRendererChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioCapturerInfoArraySync(): AudioCapturerChangeInfoArray;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback\<AudioEffectInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getAudioEffectInfoArray(usage: StreamUsage): Promise\<AudioEffectInfoArray>;|@ohos.multimedia.audio.d.ts|
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
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isVolumeUnadjustable(): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustVolumeByStep(adjustType: VolumeAdjustType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly displayName: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getRendererInfoSync(): AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getStreamInfoSync(): AudioStreamInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioStreamIdSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioEffectMode(callback: AsyncCallback\<AudioEffectMode>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioEffectMode(): Promise\<AudioEffectMode>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioTimeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getBufferSizeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getRenderRateSync(): AudioRendererRate;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setInterruptModeSync(mode: InterruptMode): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolume(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolume(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolume(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolume(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolumeSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCount(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCount(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCountSync(): number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevices(callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevices(): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevicesSync(): AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：on(type: 'outputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：off(type: 'outputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：SOURCE_TYPE_PLAYBACK_CAPTURE = 2|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：SOURCE_TYPE_WAKEUP = 3|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerOptions;<br>方法or属性：playbackCaptureConfig?: AudioPlaybackCaptureConfig;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：CaptureFilterOptions;<br>方法or属性：usages: Array\<StreamUsage>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioPlaybackCaptureConfig;<br>方法or属性：filterOptions: CaptureFilterOptions;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getCapturerInfoSync(): AudioCapturerInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：off(type: 'audioInterrupt'): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioEffectMode;<br>方法or属性：EFFECT_NONE = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioEffectMode;<br>方法or属性：EFFECT_DEFAULT = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'sessionCreate', callback: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'sessionDestroy', callback: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'deviceAvailable', callback: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'sessionCreate', callback?: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'sessionDestroy', callback?: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'deviceAvailable', callback?: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function startCastDeviceDiscovery(filter?: number): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function stopCastDeviceDiscovery(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function stopCastDeviceDiscovery(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function setDiscoverable(enable: boolean): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getAVCastController(sessionId: string): Promise\<AVCastController>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function startCasting(session: SessionToken, device: OutputDeviceInfo, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function startCasting(session: SessionToken, device: OutputDeviceInfo): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function stopCasting(session: SessionToken): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：type AVCastControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>  'seek' \| 'setVolume' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ProtocolType;<br>方法or属性：TYPE_LOCAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ProtocolType;<br>方法or属性：TYPE_CAST_PLUS_MIRROR = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ProtocolType;<br>方法or属性：TYPE_CAST_PLUS_STREAM = 2|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：readonly sessionType: AVSessionType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVQueueTitle(title: string): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getAVCastController(callback: AsyncCallback\<AVCastController>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getAVCastController(): Promise\<AVCastController>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getOutputDeviceSync(): OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'play', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'pause', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'stop', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'playNext', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'playPrevious', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'fastForward', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'rewind', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'skipToQueueItem', callback: (itemId: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'play', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'pause', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'stop', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'playNext', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'playPrevious', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'fastForward', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'rewind', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'commonCommand', callback?: (command: string, args: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：stopCasting(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：stopCasting(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastControlCommand;<br>方法or属性：command: AVCastControlCommandType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastControlCommand;<br>方法or属性：parameter?: media.PlaybackSpeed \| number \| string \| LoopMode;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：setDisplaySurface(surfaceId: string): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：sendControlCommand(command: AVCastControlCommand): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：start(item: AVQueueItem, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：start(item: AVQueueItem): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：prepare(item: AVQueueItem): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getCurrentItem(): Promise\<AVQueueItem>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'playNext', callback: Callback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'playPrevious', callback: Callback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'seekDone', callback: Callback\<number>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'mediaItemChange'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'playNext'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'playPrevious'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'seekDone'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'videoSizeChange'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：off(type: 'error'): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ConnectionState;<br>方法or属性：STATE_CONNECTING = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ConnectionState;<br>方法or属性：STATE_CONNECTED = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：ConnectionState;<br>方法or属性：STATE_DISCONNECTED = 6|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaImage?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：extras?: {[key: string]: Object};|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：extras?: {[key: string]: Object};|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaType?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaSize?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：albumTitle?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：albumCoverUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：lyricContent?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：lyricUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：fdSrc?: media.AVFileDescriptor;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：startPosition?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：creditsPosition?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：appName?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVQueueItem;<br>方法or属性：itemId: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVQueueItem;<br>方法or属性：description?: AVMediaDescription;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：activeItemId?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：volume?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastCategory;<br>方法or属性：CATEGORY_LOCAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastCategory;<br>方法or属性：CATEGORY_REMOTE = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_LOCAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_TV = 2|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_SMART_SPEAKER = 3|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_BLUETOOTH = 10|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：castCategory: AVCastCategory;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceName: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceType: DeviceType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：ipAddress?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：providerId?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：OutputDeviceInfo;<br>方法or属性：devices: Array\<DeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_COMPLETED = 7|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_RELEASED = 8|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_ERROR = 9|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVPlaybackStateSync(): AVPlaybackState;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVMetadataSync(): AVMetadata;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueTitle(callback: AsyncCallback\<string>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueTitle(): Promise\<string>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueTitleSync(): string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueItems(): Promise\<Array\<AVQueueItem>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVQueueItemsSync(): Array\<AVQueueItem>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：skipToQueueItem(itemId: number): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：isActiveSync(): boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getValidCommandsSync(): Array\<AVControlCommandType>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getExtras(): Promise\<{[key: string]: Object}>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'queueItemsChange', callback: (items: Array\<AVQueueItem>) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'queueTitleChange', callback: (title: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'queueItemsChange', callback?: (items: Array\<AVQueueItem>) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'queueTitleChange', callback?: (title: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_DEVICE_CONNECTION_FAILED = 6600108|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_REMOTE_CONNECTION_NOT_EXIST = 6600109|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：camera;<br>方法or属性：function getModeManager(context: Context): ModeManager;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：CONFLICT_CAMERA = 7400107|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：DEVICE_PREEMPTED = 7400109|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PrelaunchConfig;<br>方法or属性：cameraDevice: CameraDevice;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：off(type: 'cameraMute', callback?: AsyncCallback\<boolean>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：isPrelaunchSupported(camera: CameraDevice): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：prelaunch(): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createDeferredPreviewOutput(profile: Profile): PreviewOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：HostDeviceType;<br>方法or属性：UNKNOWN_TYPE = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：HostDeviceType;<br>方法or属性：PHONE = 0x0E|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：HostDeviceType;<br>方法or属性：TABLET = 0x11|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly hostDeviceName: string;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly hostDeviceType: HostDeviceType;|@ohos.multimedia.camera.d.ts|
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
|新增|NA|类名：PreviewOutput;<br>方法or属性：addDeferredSurface(surfaceId: string): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'captureStart', callback?: AsyncCallback\<number>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：isQuickThumbnailSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：enableQuickThumbnail(enabled: boolean): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject>>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：DATE_TIME = 'DateTime'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：GPS_TIME_STAMP = 'GPSTimeStamp'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：GPS_DATE_STAMP = 'GPSDateStamp'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：IMAGE_DESCRIPTION = 'ImageDescription'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：MAKE = 'Make'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：MODEL = 'Model'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：PHOTO_MODE = 'PhotoMode'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：SENSITIVITY_TYPE = 'SensitivityType'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：STANDARD_OUTPUT_SENSITIVITY = 'StandardOutputSensitivity'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：RECOMMENDED_EXPOSURE_INDEX = 'RecommendedExposureIndex'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：ISO_SPEED = 'ISOSpeedRatings'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：APERTURE_VALUE = 'ApertureValue'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：EXPOSURE_BIAS_VALUE = 'ExposureBiasValue'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：METERING_MODE = 'MeteringMode'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：LIGHT_SOURCE = 'LightSource'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：FLASH = 'Flash'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：FOCAL_LENGTH = 'FocalLength'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：USER_COMMENT = 'UserComment'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：PIXEL_X_DIMENSION = 'PixelXDimension'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：PIXEL_Y_DIMENSION = 'PixelYDimension'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：WHITE_BALANCE = 'WhiteBalance'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：FOCAL_LENGTH_IN_35_MM_FILM = 'FocalLengthIn35mmFilm'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：CAPTURE_MODE = 'HwMnoteCaptureMode'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：PHYSICAL_APERTURE = 'HwMnotePhysicalAperture'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：getColorSpace(): colorSpaceManager.ColorSpaceManager;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：marshalling(sequence: rpc.MessageSequence): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(): Promise\<Array\<number>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getFrameCount(): Promise\<number>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createSoundPool(<br>    maxStreams: number,<br>    audioRenderInfo: audio.AudioRendererInfo,<br>    callback: AsyncCallback\<SoundPool><br>  ): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type SoundPool = _SoundPool;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type PlayParameters = _PlayParameters;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：dataSrc?: AVDataSrcDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：audioRendererInfo?: audio.AudioRendererInfo;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：audioEffectMode ?: audio.AudioEffectMode;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVDataSrcDescriptor;<br>方法or属性：fileSize: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVDataSrcDescriptor;<br>方法or属性：callback: (buffer: ArrayBuffer, length: number, pos?: number) => number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：systemSoundManager;<br>方法or属性：function getSystemSoundManager(): SystemSoundManager;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：systemSoundManager;<br>方法or属性：type RingtonePlayer = _RingtonePlayer;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：systemSoundManager;<br>方法or属性：type RingtoneOptions = _RingtoneOptions;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：RingtoneType;<br>方法or属性：RINGTONE_TYPE_DEFAULT = 0|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：RingtoneType;<br>方法or属性：RINGTONE_TYPE_MULTISIM = 1|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise\<void>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback\<string>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：getSystemRingtoneUri(context: Context, type: RingtoneType): Promise\<string>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback\<RingtonePlayer>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：SystemSoundManager;<br>方法or属性：getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise\<RingtonePlayer>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|类名：RingtoneOptions;<br>方法or属性：volume: number;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtoneOptions;<br>方法or属性：loop: boolean;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：readonly state: media.AVPlayerState;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：getTitle(callback: AsyncCallback\<string>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：getTitle(): Promise\<string>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：getAudioRendererInfo(callback: AsyncCallback\<audio.AudioRendererInfo>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：getAudioRendererInfo(): Promise\<audio.AudioRendererInfo>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：configure(options: RingtoneOptions, callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：configure(options: RingtoneOptions): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：start(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：stop(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：release(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|类名：RingtonePlayer;<br>方法or属性：on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void;|ringtonePlayer.d.ts|
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
|废弃版本有变化|类名：AudioManager;<br>方法or属性：on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeManager#event:volumeChange|@ohos.multimedia.audio.d.ts|
|新增(错误码)|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;<br>旧版本信息：|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;<br>新版本信息：401|@ohos.effectKit.d.ts|
|新增(错误码)|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void;<br>旧版本信息：|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void;<br>新版本信息：401|@ohos.effectKit.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>新版本信息：201,6600101|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>新版本信息：201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>新版本信息：201,401,6600101,6600102,6600104|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>新版本信息：201,401,6600101,6600105|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>新版本信息：201,401,6600101,6600105,6600107|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata): Promise\<void>;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState): Promise\<void>;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent): Promise\<void>;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：getController(): Promise\<AVSessionController>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：getController(): Promise\<AVSessionController>;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>新版本信息：600101,600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：activate(): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：activate(): Promise\<void>;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：deactivate(): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：deactivate(): Promise\<void>;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSession;<br>方法or属性：destroy(): Promise\<void>;<br>旧版本信息：|类名：AVSession;<br>方法or属性：destroy(): Promise\<void>;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：destroy(): Promise\<void>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：destroy(): Promise\<void>;<br>新版本信息：6600101,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(): Promise\<AVPlaybackState>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(): Promise\<AVPlaybackState>;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：getAVMetadata(): Promise\<AVMetadata>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：getAVMetadata(): Promise\<AVMetadata>;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent): Promise\<void>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent): Promise\<void>;<br>新版本信息：401,600101,600102,600103,600105,600106|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：getLaunchAbility(): Promise\<WantAgent>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：getLaunchAbility(): Promise\<WantAgent>;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：isActive(): Promise\<boolean>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：isActive(): Promise\<boolean>;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：getValidCommands(): Promise\<Array\<AVControlCommandType>>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：getValidCommands(): Promise\<Array\<AVControlCommandType>>;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|新增(错误码)|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand): Promise\<void>;<br>旧版本信息：|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand): Promise\<void>;<br>新版本信息：401,6600101,6600102,6600103,6600105,6600106,6600107|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>旧版本信息：401,{@link|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>新版本信息：401,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;<br>旧版本信息：201,{@link|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;<br>新版本信息：201,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void;<br>旧版本信息：201,401,{@link,{@link|类名：avSession;<br>方法or属性：function createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void;<br>新版本信息：201,401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,{@link,{@link,{@link|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,6600101,6600102,6600104|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>旧版本信息：201,401,{@link|类名：avSession;<br>方法or属性：function on(type: 'sessionServiceDie', callback: () => void): void;<br>新版本信息：201,401,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function off(type: 'sessionServiceDie', callback?: () => void): void;<br>旧版本信息：201,401,{@link|类名：avSession;<br>方法or属性：function off(type: 'sessionServiceDie', callback?: () => void): void;<br>新版本信息：201,401,6600101|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,{@link,{@link|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,6600101,6600105|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,{@link,{@link,{@link|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,6600101,6600105,6600107|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>旧版本信息：{@link,{@link|类名：AVSession;<br>方法or属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>旧版本信息：{@link,{@link|类名：AVSession;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>旧版本信息：{@link,{@link|类名：AVSessionController;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>新版本信息：600101,600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：on(type: 'seek', callback: (time: number) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：on(type: 'seek', callback: (time: number) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：off(type: 'seek', callback?: (time: number) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：off(type: 'seek', callback?: (time: number) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：activate(callback: AsyncCallback\<void>): void;<br>旧版本信息：{@link,{@link|类名：AVSession;<br>方法or属性：activate(callback: AsyncCallback\<void>): void;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：deactivate(callback: AsyncCallback\<void>): void;<br>旧版本信息：{@link,{@link|类名：AVSession;<br>方法or属性：deactivate(callback: AsyncCallback\<void>): void;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>旧版本信息：{@link,{@link|类名：AVSession;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>新版本信息：6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>旧版本信息：{@link,{@link|类名：AVSessionController;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>新版本信息：6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>旧版本信息：{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>旧版本信息：{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link,{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>新版本信息：401,600101,600102,600103,600105,600106|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>旧版本信息：{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getRealPlaybackPositionSync(): number;<br>旧版本信息：{@link,{@link|类名：AVSessionController;<br>方法or属性：getRealPlaybackPositionSync(): number;<br>新版本信息：6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：isActive(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：isActive(callback: AsyncCallback\<boolean>): void;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>旧版本信息：{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>新版本信息：6600101,6600102,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link,{@link,{@link,{@link,{@link|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102,6600103,6600105,6600106,6600107|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'sessionDestroy', callback: () => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'sessionDestroy', callback: () => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_LOCAL = 1<br>旧版本信息：|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_LOCAL = 1<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_DISTRIBUTED = 2<br>旧版本信息：|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_DISTRIBUTED = 2<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly groupId: number;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly groupId: number;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly mappingId: number;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly mappingId: number;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly groupName: string;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly groupName: string;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly type: ConnectType;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly type: ConnectType;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_0 = 0<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_0 = 0<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_1 = 1<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_1 = 1<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_2 = 2<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_2 = 2<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_3 = 3<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_3 = 3<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_4 = 4<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_4 = 4<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_5 = 5<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_5 = 5<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_6 = 6<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_6 = 6<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_7 = 7<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_7 = 7<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_8 = 8<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_8 = 8<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_9 = 9<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_9 = 9<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_S = 10<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_S = 10<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_P = 11<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_P = 11<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_A = 12<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_A = 12<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_B = 13<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_B = 13<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_C = 14<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_C = 14<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_D = 15<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_D = 15<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_DIAL = 100<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_DIAL = 100<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_BUSY = 101<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_BUSY = 101<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CONGESTION = 102<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CONGESTION = 102<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK = 103<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK = 103<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE = 104<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE = 104<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING = 106<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING = 106<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RINGTONE = 107<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RINGTONE = 107<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_BEEP = 200<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_BEEP = 200<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_ACK = 201<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_ACK = 201<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_PROMPT = 203<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_PROMPT = 203<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP = 204<br>旧版本信息：|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP = 204<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：load(type: ToneType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：load(type: ToneType, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：load(type: ToneType): Promise\<void>;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：load(type: ToneType): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：start(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：start(callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：start(): Promise\<void>;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：start(): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：stop(): Promise\<void>;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：stop(): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：TonePlayer;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：TonePlayer;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>旧版本信息：systemapi|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：type AVSessionType = 'audio' \| 'video';<br>旧版本信息：systemapi|类名：avSession;<br>方法or属性：type AVSessionType = 'audio' \| 'video';<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>  'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>旧版本信息：systemapi|类名：avSession;<br>方法or属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>  'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：sessionId: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：pid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：pid?: number;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：uid?: number;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：interface AVSession<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：interface AVSession<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：readonly sessionId: string;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：readonly sessionId: string;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：readonly sessionId: string;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：readonly sessionId: string;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：on(type: 'seek', callback: (time: number) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：on(type: 'seek', callback: (time: number) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：off(type: 'seek', callback?: (time: number) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：off(type: 'seek', callback?: (time: number) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：activate(callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：activate(callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：deactivate(callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：deactivate(callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSession;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata;<br>方法or属性：interface AVMetadata<br>旧版本信息：systemapi|类名：AVMetadata;<br>方法or属性：interface AVMetadata<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState;<br>方法or属性：interface AVPlaybackState<br>旧版本信息：systemapi|类名：AVPlaybackState;<br>方法or属性：interface AVPlaybackState<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition;<br>方法or属性：interface PlaybackPosition<br>旧版本信息：systemapi|类名：PlaybackPosition;<br>方法or属性：interface PlaybackPosition<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo;<br>方法or属性：interface OutputDeviceInfo<br>旧版本信息：systemapi|类名：OutputDeviceInfo;<br>方法or属性：interface OutputDeviceInfo<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode;<br>方法or属性：enum LoopMode<br>旧版本信息：systemapi|类名：LoopMode;<br>方法or属性：enum LoopMode<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState;<br>方法or属性：enum PlaybackState<br>旧版本信息：systemapi|类名：PlaybackState;<br>方法or属性：enum PlaybackState<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：type: AVSessionType;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：type: AVSessionType;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：elementName: ElementName;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：elementName: ElementName;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：outputDevice: OutputDeviceInfo;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：outputDevice: OutputDeviceInfo;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：interface AVSessionController<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：interface AVSessionController<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getRealPlaybackPositionSync(): number;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getRealPlaybackPositionSync(): number;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：isActive(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：isActive(callback: AsyncCallback\<boolean>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：on(type: 'sessionDestroy', callback: () => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：on(type: 'sessionDestroy', callback: () => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>旧版本信息：systemapi|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand;<br>方法or属性：interface AVControlCommand<br>旧版本信息：systemapi|类名：AVControlCommand;<br>方法or属性：interface AVControlCommand<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode;<br>方法or属性：enum AVSessionErrorCode<br>旧版本信息：systemapi|类名：AVSessionErrorCode;<br>方法or属性：enum AVSessionErrorCode<br>新版本信息：|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：camera;<br>方法or属性：declare camera<br>旧版本信息：systemapi|类名：camera;<br>方法or属性：declare camera<br>新版本信息：|@ohos.multimedia.camera.d.ts|
|权限有变化|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：SessionToken;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：sessionId: string;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：SessionToken;<br>方法or属性：pid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：pid?: number;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|权限有变化|类名：SessionToken;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：uid?: number;<br>新版本信息：ohos.permission.MANAGE_MEDIA_RESOURCES|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AudioRendererInfo;<br>方法or属性：content?: ContentType;<br>旧版本信息：|类名：AudioRendererInfo;<br>方法or属性：content?: ContentType;<br>新版本信息：?ContentType|@ohos.multimedia.audio.d.ts|
|type有变化|类名：SessionToken;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：sessionId: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：SessionToken;<br>方法or属性：pid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：pid?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：SessionToken;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：uid?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：assetId: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：assetId: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：title?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：artist?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：artist?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：author?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：author?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：album?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：album?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：writer?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：writer?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：composer?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：composer?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：duration?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：publishDate?: Date;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：publishDate?: Date;<br>新版本信息：?Date|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：subtitle?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：subtitle?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：description?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：description?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：lyric?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：lyric?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：previousAssetId?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：previousAssetId?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：nextAssetId?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：nextAssetId?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：speed?: number;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：speed?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：bufferedTime?: number;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：bufferedTime?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：isFavorite?: boolean;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：isFavorite?: boolean;<br>新版本信息：?boolean|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：PlaybackPosition;<br>方法or属性：elapsedTime: number;<br>旧版本信息：|类名：PlaybackPosition;<br>方法or属性：elapsedTime: number;<br>新版本信息：number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：PlaybackPosition;<br>方法or属性：updateTime: number;<br>旧版本信息：|类名：PlaybackPosition;<br>方法or属性：updateTime: number;<br>新版本信息：number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>新版本信息：boolean|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>新版本信息：boolean|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：Profile;<br>方法or属性：readonly format: CameraFormat;<br>旧版本信息：|类名：Profile;<br>方法or属性：readonly format: CameraFormat;<br>新版本信息：CameraFormat|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Profile;<br>方法or属性：readonly size: Size;<br>旧版本信息：|类名：Profile;<br>方法or属性：readonly size: Size;<br>新版本信息：Size|@ohos.multimedia.camera.d.ts|
|type有变化|类名：FrameRateRange;<br>方法or属性：readonly min: number;<br>旧版本信息：|类名：FrameRateRange;<br>方法or属性：readonly min: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：FrameRateRange;<br>方法or属性：readonly max: number;<br>旧版本信息：|类名：FrameRateRange;<br>方法or属性：readonly max: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：VideoProfile;<br>方法or属性：readonly frameRateRange: FrameRateRange;<br>旧版本信息：|类名：VideoProfile;<br>方法or属性：readonly frameRateRange: FrameRateRange;<br>新版本信息：FrameRateRange|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraOutputCapability;<br>方法or属性：readonly previewProfiles: Array\<Profile>;<br>旧版本信息：|类名：CameraOutputCapability;<br>方法or属性：readonly previewProfiles: Array\<Profile>;<br>新版本信息：Array\<Profile>|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraOutputCapability;<br>方法or属性：readonly photoProfiles: Array\<Profile>;<br>旧版本信息：|类名：CameraOutputCapability;<br>方法or属性：readonly photoProfiles: Array\<Profile>;<br>新版本信息：Array\<Profile>|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraOutputCapability;<br>方法or属性：readonly videoProfiles: Array\<VideoProfile>;<br>旧版本信息：|类名：CameraOutputCapability;<br>方法or属性：readonly videoProfiles: Array\<VideoProfile>;<br>新版本信息：Array\<VideoProfile>|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraOutputCapability;<br>方法or属性：readonly supportedMetadataObjectTypes: Array\<MetadataObjectType>;<br>旧版本信息：|类名：CameraOutputCapability;<br>方法or属性：readonly supportedMetadataObjectTypes: Array\<MetadataObjectType>;<br>新版本信息：Array\<MetadataObjectType>|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraStatusInfo;<br>方法or属性：camera: CameraDevice;<br>旧版本信息：|类名：CameraStatusInfo;<br>方法or属性：camera: CameraDevice;<br>新版本信息：CameraDevice|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraStatusInfo;<br>方法or属性：status: CameraStatus;<br>旧版本信息：|类名：CameraStatusInfo;<br>方法or属性：status: CameraStatus;<br>新版本信息：CameraStatus|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraDevice;<br>方法or属性：readonly cameraId: string;<br>旧版本信息：|类名：CameraDevice;<br>方法or属性：readonly cameraId: string;<br>新版本信息：string|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraDevice;<br>方法or属性：readonly cameraPosition: CameraPosition;<br>旧版本信息：|类名：CameraDevice;<br>方法or属性：readonly cameraPosition: CameraPosition;<br>新版本信息：CameraPosition|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraDevice;<br>方法or属性：readonly cameraType: CameraType;<br>旧版本信息：|类名：CameraDevice;<br>方法or属性：readonly cameraType: CameraType;<br>新版本信息：CameraType|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CameraDevice;<br>方法or属性：readonly connectionType: ConnectionType;<br>旧版本信息：|类名：CameraDevice;<br>方法or属性：readonly connectionType: ConnectionType;<br>新版本信息：ConnectionType|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Rect;<br>方法or属性：height: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：height: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Rect;<br>方法or属性：width: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：width: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Point;<br>方法or属性：x: number;<br>旧版本信息：|类名：Point;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Point;<br>方法or属性：y: number;<br>旧版本信息：|类名：Point;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Location;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：latitude: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Location;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：longitude: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Location;<br>方法or属性：altitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：altitude: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：PhotoCaptureSetting;<br>方法or属性：quality?: QualityLevel;<br>旧版本信息：|类名：PhotoCaptureSetting;<br>方法or属性：quality?: QualityLevel;<br>新版本信息：?QualityLevel|@ohos.multimedia.camera.d.ts|
|type有变化|类名：PhotoCaptureSetting;<br>方法or属性：rotation?: ImageRotation;<br>旧版本信息：|类名：PhotoCaptureSetting;<br>方法or属性：rotation?: ImageRotation;<br>新版本信息：?ImageRotation|@ohos.multimedia.camera.d.ts|
|type有变化|类名：PhotoCaptureSetting;<br>方法or属性：location?: Location;<br>旧版本信息：|类名：PhotoCaptureSetting;<br>方法or属性：location?: Location;<br>新版本信息：?Location|@ohos.multimedia.camera.d.ts|
|type有变化|类名：PhotoCaptureSetting;<br>方法or属性：mirror?: boolean;<br>旧版本信息：|类名：PhotoCaptureSetting;<br>方法or属性：mirror?: boolean;<br>新版本信息：?boolean|@ohos.multimedia.camera.d.ts|
|type有变化|类名：FrameShutterInfo;<br>方法or属性：captureId: number;<br>旧版本信息：|类名：FrameShutterInfo;<br>方法or属性：captureId: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CaptureEndInfo;<br>方法or属性：captureId: number;<br>旧版本信息：|类名：CaptureEndInfo;<br>方法or属性：captureId: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：FrameShutterInfo;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：FrameShutterInfo;<br>方法or属性：timestamp: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：CaptureEndInfo;<br>方法or属性：frameCount: number;<br>旧版本信息：|类名：CaptureEndInfo;<br>方法or属性：frameCount: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Rect;<br>方法or属性：topLeftX: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：topLeftX: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Rect;<br>方法or属性：topLeftY: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：topLeftY: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：MetadataObject;<br>方法or属性：readonly type: MetadataObjectType;<br>旧版本信息：|类名：MetadataObject;<br>方法or属性：readonly type: MetadataObjectType;<br>新版本信息：MetadataObjectType|@ohos.multimedia.camera.d.ts|
|type有变化|类名：MetadataObject;<br>方法or属性：readonly timestamp: number;<br>旧版本信息：|类名：MetadataObject;<br>方法or属性：readonly timestamp: number;<br>新版本信息：number|@ohos.multimedia.camera.d.ts|
|type有变化|类名：MetadataObject;<br>方法or属性：readonly boundingBox: Rect;<br>旧版本信息：|类名：MetadataObject;<br>方法or属性：readonly boundingBox: Rect;<br>新版本信息：Rect|@ohos.multimedia.camera.d.ts|
|type有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Region;<br>方法or属性：size: Size;<br>旧版本信息：|类名：Region;<br>方法or属性：size: Size;<br>新版本信息：Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageInfo;<br>方法or属性：size: Size;<br>旧版本信息：|类名：ImageInfo;<br>方法or属性：size: Size;<br>新版本信息：Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：InitializationOptions;<br>方法or属性：size: Size;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：size: Size;<br>新版本信息：Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：Region;<br>方法or属性：x: number;<br>旧版本信息：|类名：Region;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Region;<br>方法or属性：y: number;<br>旧版本信息：|类名：Region;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：PositionArea;<br>方法or属性：pixels: ArrayBuffer;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：pixels: ArrayBuffer;<br>新版本信息：ArrayBuffer|@ohos.multimedia.image.d.ts|
|type有变化|类名：PositionArea;<br>方法or属性：offset: number;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：offset: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：PositionArea;<br>方法or属性：stride: number;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：stride: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：PositionArea;<br>方法or属性：region: Region;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：region: Region;<br>新版本信息：Region|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageInfo;<br>方法or属性：density: number;<br>旧版本信息：|类名：ImageInfo;<br>方法or属性：density: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：PackingOption;<br>方法or属性：format: string;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：format: string;<br>新版本信息：string|@ohos.multimedia.image.d.ts|
|type有变化|类名：PackingOption;<br>方法or属性：quality: number;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：quality: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：PackingOption;<br>方法or属性：bufferSize?: number;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：bufferSize?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：GetImagePropertyOptions;<br>方法or属性：index?: number;<br>旧版本信息：|类名：GetImagePropertyOptions;<br>方法or属性：index?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：index?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：index?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：GetImagePropertyOptions;<br>方法or属性：defaultValue?: string;<br>旧版本信息：|类名：GetImagePropertyOptions;<br>方法or属性：defaultValue?: string;<br>新版本信息：?string|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：sampleSize?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：sampleSize?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：rotate?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：rotate?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：editable?: boolean;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：editable?: boolean;<br>新版本信息：?boolean|@ohos.multimedia.image.d.ts|
|type有变化|类名：InitializationOptions;<br>方法or属性：editable?: boolean;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：editable?: boolean;<br>新版本信息：?boolean|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：desiredSize?: Size;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredSize?: Size;<br>新版本信息：?Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：desiredRegion?: Region;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredRegion?: Region;<br>新版本信息：?Region|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：desiredPixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredPixelFormat?: PixelMapFormat;<br>新版本信息：?PixelMapFormat|@ohos.multimedia.image.d.ts|
|type有变化|类名：DecodingOptions;<br>方法or属性：fitDensity?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：fitDensity?: number;<br>新版本信息：?number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Component;<br>方法or属性：readonly componentType: ComponentType;<br>旧版本信息：|类名：Component;<br>方法or属性：readonly componentType: ComponentType;<br>新版本信息：ComponentType|@ohos.multimedia.image.d.ts|
|type有变化|类名：Component;<br>方法or属性：readonly rowStride: number;<br>旧版本信息：|类名：Component;<br>方法or属性：readonly rowStride: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Component;<br>方法or属性：readonly pixelStride: number;<br>旧版本信息：|类名：Component;<br>方法or属性：readonly pixelStride: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：Component;<br>方法or属性：readonly byteBuffer: ArrayBuffer;<br>旧版本信息：|类名：Component;<br>方法or属性：readonly byteBuffer: ArrayBuffer;<br>新版本信息：ArrayBuffer|@ohos.multimedia.image.d.ts|
|type有变化|类名：InitializationOptions;<br>方法or属性：pixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：pixelFormat?: PixelMapFormat;<br>新版本信息：?PixelMapFormat|@ohos.multimedia.image.d.ts|
|type有变化|类名：InitializationOptions;<br>方法or属性：alphaType?: AlphaType;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：alphaType?: AlphaType;<br>新版本信息：?AlphaType|@ohos.multimedia.image.d.ts|
|type有变化|类名：InitializationOptions;<br>方法or属性：scaleMode?: ScaleMode;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：scaleMode?: ScaleMode;<br>新版本信息：?ScaleMode|@ohos.multimedia.image.d.ts|
|type有变化|类名：SourceOptions;<br>方法or属性：sourceDensity: number;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourceDensity: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：SourceOptions;<br>方法or属性：sourcePixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourcePixelFormat?: PixelMapFormat;<br>新版本信息：?PixelMapFormat|@ohos.multimedia.image.d.ts|
|type有变化|类名：SourceOptions;<br>方法or属性：sourceSize?: Size;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourceSize?: Size;<br>新版本信息：?Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：PixelMap;<br>方法or属性：readonly isEditable: boolean;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readonly isEditable: boolean;<br>新版本信息：boolean|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageSource;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>新版本信息：Array\<string>|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImagePacker;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>新版本信息：Array\<string>|@ohos.multimedia.image.d.ts|
|type有变化|类名：Image;<br>方法or属性：clipRect: Region;<br>旧版本信息：|类名：Image;<br>方法or属性：clipRect: Region;<br>新版本信息：Region|@ohos.multimedia.image.d.ts|
|type有变化|类名：Image;<br>方法or属性：readonly size: Size;<br>旧版本信息：|类名：Image;<br>方法or属性：readonly size: Size;<br>新版本信息：Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageReceiver;<br>方法or属性：readonly size: Size;<br>旧版本信息：|类名：ImageReceiver;<br>方法or属性：readonly size: Size;<br>新版本信息：Size|@ohos.multimedia.image.d.ts|
|type有变化|类名：Image;<br>方法or属性：readonly format: number;<br>旧版本信息：|类名：Image;<br>方法or属性：readonly format: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageReceiver;<br>方法or属性：readonly capacity: number;<br>旧版本信息：|类名：ImageReceiver;<br>方法or属性：readonly capacity: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageCreator;<br>方法or属性：readonly capacity: number;<br>旧版本信息：|类名：ImageCreator;<br>方法or属性：readonly capacity: number;<br>新版本信息：number|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageReceiver;<br>方法or属性：readonly format: ImageFormat;<br>旧版本信息：|类名：ImageReceiver;<br>方法or属性：readonly format: ImageFormat;<br>新版本信息：ImageFormat|@ohos.multimedia.image.d.ts|
|type有变化|类名：ImageCreator;<br>方法or属性：readonly format: ImageFormat;<br>旧版本信息：|类名：ImageCreator;<br>方法or属性：readonly format: ImageFormat;<br>新版本信息：ImageFormat|@ohos.multimedia.image.d.ts|
|函数有变化|类名：AudioRendererInfo;<br>方法or属性：content: ContentType;|类名：AudioRendererInfo;<br>方法or属性：content?: ContentType;|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioRendererFilter;<br>方法or属性：uid: number;|类名：AudioRendererFilter;<br>方法or属性：uid?: number;|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：SessionToken;<br>方法or属性：pid: number;|类名：SessionToken;<br>方法or属性：pid?: number;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：SessionToken;<br>方法or属性：uid: number;|类名：SessionToken;<br>方法or属性：uid?: number;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：CameraInput;<br>方法or属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback\<BusinessError>): void;|类名：CameraInput;<br>方法or属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：CaptureSession;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：CaptureSession;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PreviewOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：PreviewOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PhotoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：PhotoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：VideoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：VideoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：MetadataOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：MetadataOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void;<br>旧版本信息：|类名：image;<br>方法or属性：function createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>;<br>旧版本信息：|类名：image;<br>方法or属性：function createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(uri: string): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(uri: string): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(uri: string, options: SourceOptions): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(uri: string, options: SourceOptions): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(fd: number): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(fd: number): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(fd: number, options: SourceOptions): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(fd: number, options: SourceOptions): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource;<br>旧版本信息：|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：image;<br>方法or属性：function createImagePacker(): ImagePacker;<br>旧版本信息：|类名：image;<br>方法or属性：function createImagePacker(): ImagePacker;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：enum PixelMapFormat<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：enum PixelMapFormat<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：UNKNOWN = 0<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：UNKNOWN = 0<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：AlphaType;<br>方法or属性：UNKNOWN = 0<br>旧版本信息：|类名：AlphaType;<br>方法or属性：UNKNOWN = 0<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：RGB_565 = 2<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：RGB_565 = 2<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：RGBA_8888 = 3<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：RGBA_8888 = 3<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：BGRA_8888 = 4<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：BGRA_8888 = 4<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：RGB_888 = 5<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：RGB_888 = 5<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：ALPHA_8 = 6<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：ALPHA_8 = 6<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：RGBA_F16 = 7<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：RGBA_F16 = 7<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：NV21 = 8<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：NV21 = 8<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMapFormat;<br>方法or属性：NV12 = 9<br>旧版本信息：|类名：PixelMapFormat;<br>方法or属性：NV12 = 9<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：interface Size<br>旧版本信息：|类名：Size;<br>方法or属性：interface Size<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：enum PropertyKey<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：enum PropertyKey<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：BITS_PER_SAMPLE = 'BitsPerSample'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：BITS_PER_SAMPLE = 'BitsPerSample'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：ORIENTATION = 'Orientation'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：ORIENTATION = 'Orientation'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：IMAGE_LENGTH = 'ImageLength'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：IMAGE_LENGTH = 'ImageLength'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：IMAGE_WIDTH = 'ImageWidth'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：IMAGE_WIDTH = 'ImageWidth'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：GPS_LATITUDE = 'GPSLatitude'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：GPS_LATITUDE = 'GPSLatitude'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：GPS_LONGITUDE = 'GPSLongitude'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：GPS_LONGITUDE = 'GPSLongitude'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：GPS_LATITUDE_REF = 'GPSLatitudeRef'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：GPS_LATITUDE_REF = 'GPSLatitudeRef'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：GPS_LONGITUDE_REF = 'GPSLongitudeRef'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：GPS_LONGITUDE_REF = 'GPSLongitudeRef'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：DATE_TIME_ORIGINAL = 'DateTimeOriginal'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：DATE_TIME_ORIGINAL = 'DateTimeOriginal'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：EXPOSURE_TIME = 'ExposureTime'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：EXPOSURE_TIME = 'ExposureTime'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：SCENE_TYPE = 'SceneType'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：SCENE_TYPE = 'SceneType'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：ISO_SPEED_RATINGS = 'ISOSpeedRatings'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：ISO_SPEED_RATINGS = 'ISOSpeedRatings'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PropertyKey;<br>方法or属性：F_NUMBER = 'FNumber'<br>旧版本信息：|类名：PropertyKey;<br>方法or属性：F_NUMBER = 'FNumber'<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：AlphaType;<br>方法or属性：enum AlphaType<br>旧版本信息：|类名：AlphaType;<br>方法or属性：enum AlphaType<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：AlphaType;<br>方法or属性：OPAQUE = 1<br>旧版本信息：|类名：AlphaType;<br>方法or属性：OPAQUE = 1<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：AlphaType;<br>方法or属性：PREMUL = 2<br>旧版本信息：|类名：AlphaType;<br>方法or属性：PREMUL = 2<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：AlphaType;<br>方法or属性：UNPREMUL = 3<br>旧版本信息：|类名：AlphaType;<br>方法or属性：UNPREMUL = 3<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ScaleMode;<br>方法or属性：enum ScaleMode<br>旧版本信息：|类名：ScaleMode;<br>方法or属性：enum ScaleMode<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ScaleMode;<br>方法or属性：FIT_TARGET_SIZE = 0<br>旧版本信息：|类名：ScaleMode;<br>方法or属性：FIT_TARGET_SIZE = 0<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ScaleMode;<br>方法or属性：CENTER_CROP = 1<br>旧版本信息：|类名：ScaleMode;<br>方法or属性：CENTER_CROP = 1<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Region;<br>方法or属性：interface Region<br>旧版本信息：|类名：Region;<br>方法or属性：interface Region<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Region;<br>方法or属性：size: Size;<br>旧版本信息：|类名：Region;<br>方法or属性：size: Size;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageInfo;<br>方法or属性：size: Size;<br>旧版本信息：|类名：ImageInfo;<br>方法or属性：size: Size;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：size: Size;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：size: Size;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Region;<br>方法or属性：x: number;<br>旧版本信息：|类名：Region;<br>方法or属性：x: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：Region;<br>方法or属性：y: number;<br>旧版本信息：|类名：Region;<br>方法or属性：y: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PositionArea;<br>方法or属性：interface PositionArea<br>旧版本信息：|类名：PositionArea;<br>方法or属性：interface PositionArea<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PositionArea;<br>方法or属性：pixels: ArrayBuffer;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：pixels: ArrayBuffer;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PositionArea;<br>方法or属性：offset: number;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：offset: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PositionArea;<br>方法or属性：stride: number;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：stride: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PositionArea;<br>方法or属性：region: Region;<br>旧版本信息：|类名：PositionArea;<br>方法or属性：region: Region;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageInfo;<br>方法or属性：interface ImageInfo<br>旧版本信息：|类名：ImageInfo;<br>方法or属性：interface ImageInfo<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageInfo;<br>方法or属性：density: number;<br>旧版本信息：|类名：ImageInfo;<br>方法or属性：density: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PackingOption;<br>方法or属性：interface PackingOption<br>旧版本信息：|类名：PackingOption;<br>方法or属性：interface PackingOption<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PackingOption;<br>方法or属性：format: string;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：format: string;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PackingOption;<br>方法or属性：quality: number;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：quality: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PackingOption;<br>方法or属性：bufferSize?: number;<br>旧版本信息：|类名：PackingOption;<br>方法or属性：bufferSize?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：GetImagePropertyOptions;<br>方法or属性：interface GetImagePropertyOptions<br>旧版本信息：|类名：GetImagePropertyOptions;<br>方法or属性：interface GetImagePropertyOptions<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：GetImagePropertyOptions;<br>方法or属性：index?: number;<br>旧版本信息：|类名：GetImagePropertyOptions;<br>方法or属性：index?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：index?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：index?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：GetImagePropertyOptions;<br>方法or属性：defaultValue?: string;<br>旧版本信息：|类名：GetImagePropertyOptions;<br>方法or属性：defaultValue?: string;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：interface DecodingOptions<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：interface DecodingOptions<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：sampleSize?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：sampleSize?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：rotate?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：rotate?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：editable?: boolean;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：editable?: boolean;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：editable?: boolean;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：editable?: boolean;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：desiredSize?: Size;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredSize?: Size;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：desiredRegion?: Region;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredRegion?: Region;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：desiredPixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：desiredPixelFormat?: PixelMapFormat;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：DecodingOptions;<br>方法or属性：fitDensity?: number;<br>旧版本信息：|类名：DecodingOptions;<br>方法or属性：fitDensity?: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：interface InitializationOptions<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：interface InitializationOptions<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：pixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：pixelFormat?: PixelMapFormat;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：alphaType?: AlphaType;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：alphaType?: AlphaType;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：InitializationOptions;<br>方法or属性：scaleMode?: ScaleMode;<br>旧版本信息：|类名：InitializationOptions;<br>方法or属性：scaleMode?: ScaleMode;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：SourceOptions;<br>方法or属性：interface SourceOptions<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：interface SourceOptions<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：SourceOptions;<br>方法or属性：sourceDensity: number;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourceDensity: number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：SourceOptions;<br>方法or属性：sourcePixelFormat?: PixelMapFormat;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourcePixelFormat?: PixelMapFormat;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：SourceOptions;<br>方法or属性：sourceSize?: Size;<br>旧版本信息：|类名：SourceOptions;<br>方法or属性：sourceSize?: Size;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：interface PixelMap<br>旧版本信息：|类名：PixelMap;<br>方法or属性：interface PixelMap<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：readonly isEditable: boolean;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readonly isEditable: boolean;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：readPixels(area: PositionArea): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readPixels(area: PositionArea): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：readPixels(area: PositionArea, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：readPixels(area: PositionArea, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：writePixels(area: PositionArea): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：writePixels(area: PositionArea): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：writePixels(area: PositionArea, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：writePixels(area: PositionArea, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：writeBufferToPixels(src: ArrayBuffer): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：writeBufferToPixels(src: ArrayBuffer): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：getImageInfo(): Promise\<ImageInfo>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getImageInfo(): Promise\<ImageInfo>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：getBytesNumberPerRow(): number;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getBytesNumberPerRow(): number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：getPixelBytesNumber(): number;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getPixelBytesNumber(): number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：getDensity(): number;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：getDensity(): number;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：opacity(rate: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：opacity(rate: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：opacity(rate: number): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：opacity(rate: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(): Promise\<PixelMap>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(): Promise\<PixelMap>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：scale(x: number, y: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：scale(x: number, y: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：scale(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：scale(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：translate(x: number, y: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：translate(x: number, y: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：translate(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：translate(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：rotate(angle: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：rotate(angle: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：rotate(angle: number): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：rotate(angle: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：crop(region: Region, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：crop(region: Region, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：crop(region: Region): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：crop(region: Region): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：PixelMap;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：PixelMap;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：interface ImageSource<br>旧版本信息：|类名：ImageSource;<br>方法or属性：interface ImageSource<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageInfo(index?: number): Promise\<ImageInfo>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageInfo(index?: number): Promise\<ImageInfo>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：createPixelMap(options?: DecodingOptions): Promise\<PixelMap>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMap(options?: DecodingOptions): Promise\<PixelMap>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：createPixelMap(callback: AsyncCallback\<PixelMap>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMap(callback: AsyncCallback\<PixelMap>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, options?: GetImagePropertyOptions): Promise\<string>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, options?: GetImagePropertyOptions): Promise\<string>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, callback: AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getImageProperty(key: string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string): Promise\<void>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：updateData(<br><br>      buf: ArrayBuffer,<br><br>      isFinished: boolean,<br><br>      value: number,<br><br>      length: number,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：updateData(<br><br>      buf: ArrayBuffer,<br><br>      isFinished: boolean,<br><br>      value: number,<br><br>      length: number,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImageSource;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：readonly supportedFormats: Array\<string>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：interface ImagePacker<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：interface ImagePacker<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
|跨平台能力有变化|类名：ImagePacker;<br>方法or属性：packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>;<br>旧版本信息：|类名：ImagePacker;<br>方法or属性：packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>;<br>新版本信息：crossplatform|@ohos.multimedia.image.d.ts|
