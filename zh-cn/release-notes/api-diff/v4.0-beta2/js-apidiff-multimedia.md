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
|删除|类名：ImageSource;<br>方法or属性：getDelayTime(): Promise\<Array\<number>>;|NA|@ohos.multimedia.image.d.ts|
|删除|类名：ImageSource;<br>方法or属性：getDelayTime(callback: AsyncCallback\<Array\<number>>): void;|NA|@ohos.multimedia.image.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap,region:Array\<number>):Promise\<ColorPicker>;|@ohos.effectKit.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap,region:Array\<number>,callback:AsyncCallback\<ColorPicker>):void;|@ohos.effectKit.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：artist?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：duration?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastController;<br>方法or属性：getAVPlaybackState(): Promise\<AVPlaybackState>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：audio;<br>方法or属性：type AudioEffectInfoArray = Array\<Readonly\<AudioEffectMode>>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_MUSIC = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_VOICE_MESSAGE = 5|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_RINGTONE = 6|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_NOTIFICATION = 7|@ohos.multimedia.audio.d.ts|
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
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback\<AudioEffectInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getAudioEffectInfoArray(usage: StreamUsage): Promise\<AudioEffectInfoArray>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isVolumeUnadjustable(): boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustVolumeByStep(adjustType: VolumeAdjustType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioEffectMode(callback: AsyncCallback\<AudioEffectMode>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioEffectMode(): Promise\<AudioEffectMode>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setAudioEffectMode(mode: AudioEffectMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolume(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMinStreamVolume(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolume(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getMaxStreamVolume(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCount(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getUnderflowCount(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevices(callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getCurrentOutputDevices(): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：on(type: 'outputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：off(type: 'outputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：SOURCE_TYPE_PLAYBACK_CAPTURE = 2|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerOptions;<br>方法or属性：playbackCaptureConfig?: AudioPlaybackCaptureConfig;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：CaptureFilterOptions;<br>方法or属性：usages: Array\<StreamUsage>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioPlaybackCaptureConfig;<br>方法or属性：filterOptions: CaptureFilterOptions;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：off(type: 'audioInterrupt'): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioEffectMode;<br>方法or属性：EFFECT_NONE = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioEffectMode;<br>方法or属性：EFFECT_DEFAULT = 1|@ohos.multimedia.audio.d.ts|
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
|新增|NA|类名：AVSession;<br>方法or属性：getAVCastController(callback: AsyncCallback\<AVCastController>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getAVCastController(): Promise\<AVCastController>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'play', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'pause', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'stop', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'playNext', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'playPrevious', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'fastForward', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'rewind', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'play', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'pause', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'stop', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'playNext', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'playPrevious', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'fastForward', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'rewind', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：stopCasting(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：stopCasting(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastControlCommand;<br>方法or属性：command: AVCastControlCommandType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastControlCommand;<br>方法or属性：parameter?: media.PlaybackSpeed \| number;|@ohos.multimedia.avsession.d.ts|
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
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaType?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：mediaSize?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：albumTitle?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：albumCoverUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：lyricContent?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：lyricUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：fdSrc?: media.AVFileDescriptor;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：startPosition?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：creditsPosition?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMediaDescription;<br>方法or属性：appName?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：volume?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastCategory;<br>方法or属性：CATEGORY_LOCAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVCastCategory;<br>方法or属性：CATEGORY_REMOTE = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_LOCAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_TV = 2|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_SMART_SPEAKER = 3|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_BLUETOOTH = 10|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：castCategory: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceName: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：deviceType: DeviceType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：ipAddress?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：DeviceInfo;<br>方法or属性：providerId?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：OutputDeviceInfo;<br>方法or属性：devices: Array\<DeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_COMPLETED = 7|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_RELEASED = 8|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_ERROR = 9|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_DEVICE_CONNECTION_FAILED = 6600108|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_REMOTE_CONNECTION_NOT_EXIST = 6600109|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PrelaunchConfig;<br>方法or属性：cameraDevice: CameraDevice;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：isPrelaunchSupported(camera: CameraDevice): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：prelaunch(): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createDeferredPreviewOutput(profile: Profile): PreviewOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：addDeferredSurface(surfaceId: string): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：isQuickThumbnailSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：enableQuickThumbnail(enabled: boolean): void;|@ohos.multimedia.camera.d.ts|
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
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(): Promise\<Array\<number>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：getDelayTimeList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：audioEffectMode ?: audio.AudioEffectMode;|@ohos.multimedia.media.d.ts|
|新增(错误码)|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap): Promise\<ColorPicker>;<br>旧版本信息：|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap): Promise\<ColorPicker>;<br>新版本信息：401|@ohos.effectKit.d.ts|
|新增(错误码)|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap,callback:AsyncCallback\<ColorPicker>):void;<br>旧版本信息：|类名：effectKit;<br>方法or属性：function createColorPicker(source:image.PixelMap,callback:AsyncCallback\<ColorPicker>):void;<br>新版本信息：401|@ohos.effectKit.d.ts|
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
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;<br>新版本信息：62980096,62980103,62980110,62980111,62980118|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：getFrameCount(): Promise\<number>;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getFrameCount(): Promise\<number>;<br>新版本信息：62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
|新增(错误码)|类名：ImageSource;<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：ImageSource;<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;<br>新版本信息：62980096,62980110,62980111,62980113,62980116,62980118,62980122|@ohos.multimedia.image.d.ts|
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
|错误码有变化|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}): Promise\<void>;<br>旧版本信息：401,{@link,{@link|类名：AVSession;<br>方法or属性：setExtras(extras: {[key: string]: Object}): Promise\<void>;<br>新版本信息：401,6600101,6600102|@ohos.multimedia.avsession.d.ts|
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
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key: string]: Object}) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key: string]: Object}) => void): void;<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void;<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key: string]: Object}) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key: string]: Object}) => void): void;<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|错误码有变化|类名：AVSessionController;<br>方法or属性：off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void;<br>旧版本信息：401,{@link,{@link|类名：AVSessionController;<br>方法or属性：off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void;<br>新版本信息：401,6600101,6600103|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_LOCAL = 1<br>旧版本信息：|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_LOCAL = 1<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_DISTRIBUTED = 2<br>旧版本信息：|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_DISTRIBUTED = 2<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly groupId: number;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly groupId: number;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly mappingId: number;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly mappingId: number;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly groupName: string;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly groupName: string;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeGroupInfo;<br>方法or属性：readonly type: ConnectType;<br>旧版本信息：|类名：VolumeGroupInfo;<br>方法or属性：readonly type: ConnectType;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent;<br>方法or属性：interface VolumeEvent<br>旧版本信息：systemapi|类名：VolumeEvent;<br>方法or属性：interface VolumeEvent<br>新版本信息：|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent;<br>方法or属性：volumeGroupId: number;<br>旧版本信息：|类名：VolumeEvent;<br>方法or属性：volumeGroupId: number;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent;<br>方法or属性：networkId: string;<br>旧版本信息：|类名：VolumeEvent;<br>方法or属性：networkId: string;<br>新版本信息：systemapi|@ohos.multimedia.audio.d.ts|
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
|访问级别有变化|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>旧版本信息：|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：sessionId: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：pid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：pid?: number;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：SessionToken;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：SessionToken;<br>方法or属性：uid?: number;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：type: AVSessionType;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：type: AVSessionType;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：elementName: ElementName;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：elementName: ElementName;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionDescriptor;<br>方法or属性：outputDevice: OutputDeviceInfo;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：outputDevice: OutputDeviceInfo;<br>新版本信息：systemapi|@ohos.multimedia.avsession.d.ts|
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
|type有变化|类名：AVMediaDescription;<br>方法or属性：title?: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：artist?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：artist?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：author?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：author?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：album?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：album?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：writer?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：writer?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：composer?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：composer?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：duration?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：publishDate?: Date;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：publishDate?: Date;<br>新版本信息：?Date|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：subtitle?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：subtitle?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMediaDescription;<br>方法or属性：subtitle?: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：subtitle?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：description?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：description?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMediaDescription;<br>方法or属性：description?: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：description?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：lyric?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：lyric?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：previousAssetId?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：previousAssetId?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMetadata;<br>方法or属性：nextAssetId?: string;<br>旧版本信息：|类名：AVMetadata;<br>方法or属性：nextAssetId?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMediaDescription;<br>方法or属性：mediaId: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：mediaId: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMediaDescription;<br>方法or属性：iconUri?: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：iconUri?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVMediaDescription;<br>方法or属性：mediaUri?: string;<br>旧版本信息：|类名：AVMediaDescription;<br>方法or属性：mediaUri?: string;<br>新版本信息：?string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVQueueItem;<br>方法or属性：itemId: number;<br>旧版本信息：|类名：AVQueueItem;<br>方法or属性：itemId: number;<br>新版本信息：number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：speed?: number;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：speed?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：bufferedTime?: number;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：bufferedTime?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：isFavorite?: boolean;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：isFavorite?: boolean;<br>新版本信息：?boolean|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVPlaybackState;<br>方法or属性：activeItemId?: number;<br>旧版本信息：|类名：AVPlaybackState;<br>方法or属性：activeItemId?: number;<br>新版本信息：?number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：PlaybackPosition;<br>方法or属性：elapsedTime: number;<br>旧版本信息：|类名：PlaybackPosition;<br>方法or属性：elapsedTime: number;<br>新版本信息：number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：PlaybackPosition;<br>方法or属性：updateTime: number;<br>旧版本信息：|类名：PlaybackPosition;<br>方法or属性：updateTime: number;<br>新版本信息：number|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;<br>新版本信息：string|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;<br>新版本信息：boolean|@ohos.multimedia.avsession.d.ts|
|type有变化|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>旧版本信息：|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;<br>新版本信息：boolean|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：AudioRendererInfo;<br>方法or属性：content: ContentType;|类名：AudioRendererInfo;<br>方法or属性：content?: ContentType;|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：SessionToken;<br>方法or属性：pid: number;|类名：SessionToken;<br>方法or属性：pid?: number;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：SessionToken;<br>方法or属性：uid: number;|类名：SessionToken;<br>方法or属性：uid?: number;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：AVMediaDescription;<br>方法or属性：icon?: image.PixelMap \| string;|类名：AVMediaDescription;<br>方法or属性：icon?: image.PixelMap;|@ohos.multimedia.avsession.d.ts|
|函数有变化|类名：CameraInput;<br>方法or属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback\<BusinessError>): void;|类名：CameraInput;<br>方法or属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：CaptureSession;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：CaptureSession;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PreviewOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：PreviewOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：PhotoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：PhotoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：VideoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：VideoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
|函数有变化|类名：MetadataOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|类名：MetadataOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.camera.d.ts|
