| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.effectKit<br>类名: ColorPicker<br>方法 or 属性：getLargestProportionColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker<br>方法or属性：getLargestProportionColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|模块名: ohos.effectKit<br>类名: ColorPicker<br>方法 or 属性：getHighestSaturationColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker<br>方法or属性：getHighestSaturationColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|模块名: ohos.effectKit<br>类名: ColorPicker<br>方法 or 属性：getAverageColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker<br>方法or属性：getAverageColor(): Color;|@ohos.effectKit.d.ts|
|新增|NA|模块名: ohos.effectKit<br>类名: ColorPicker<br>方法 or 属性：isBlackOrWhiteOrGrayColor(color: number): boolean;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker<br>方法or属性：isBlackOrWhiteOrGrayColor(color: number): boolean;|@ohos.effectKit.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioVolumeType<br>方法 or 属性：ALARM = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioVolumeType<br>方法 or 属性：ACCESSIBILITY = 5|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioVolumeType<br>方法 or 属性：ULTRASONIC = 10|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: ContentType<br>方法 or 属性：CONTENT_TYPE_ULTRASONIC = 9|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: StreamUsage<br>方法 or 属性：STREAM_USAGE_ALARM = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: StreamUsage<br>方法 or 属性：STREAM_USAGE_ACCESSIBILITY = 8|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: StreamUsage<br>方法 or 属性：STREAM_USAGE_SYSTEM = 9|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererFilter<br>方法or属性：uid?: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioRoutingManager<br>方法 or 属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioRoutingManager<br>方法 or 属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager<br>方法or属性：getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioRoutingManager<br>方法 or 属性：on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager<br>方法or属性：on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioRoutingManager<br>方法 or 属性：off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager<br>方法or属性：off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioDeviceDescriptor<br>方法 or 属性：readonly displayName: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor<br>方法or属性：readonly displayName: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|模块名: ohos.multimedia.audio<br>类名: AudioCapturer<br>方法 or 属性：on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer<br>方法or属性：on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：avSession<br>方法or属性：function getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession<br>方法or属性：function getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：dispatchSessionEvent(event: string, args: { [key: string]: Object }, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：dispatchSessionEvent(event: string, args: { [key: string]: Object }): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setAVQueueTitle(title: string): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：setExtras(extras: {[key: string]: Object}): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：on(type: 'commonCommand', callback: (command: string, args: { [key: string]: Object }) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：off(type: 'commonCommand', callback?: (command: string, args: { [key: string]: Object }) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：on(type: 'skipToQueueItem', callback: (itemId: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession<br>方法or属性：off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：mediaId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：title?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：subtitle?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：description?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：icon?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：iconUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：extras?: { [key: string]: Object };|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVMediaDescription<br>方法 or 属性：mediaUri?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVQueueItem|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVQueueItem<br>方法 or 属性：itemId: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|模块名: ohos.multimedia.avsession<br>类名: AVQueueItem<br>方法 or 属性：description?: AVMediaDescription;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState<br>方法or属性：activeItemId?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState<br>方法or属性：extras?: {[key: string]: Object};|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getAVQueueTitle(callback: AsyncCallback\<string>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getAVQueueTitle(): Promise\<string>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getAVQueueItems(): Promise\<Array\<AVQueueItem>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：skipToQueueItem(itemId: number): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：sendCommonCommand(command: string, args: { [key: string]: Object }, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：sendCommonCommand(command: string, args: { [key: string]: Object }): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：getExtras(): Promise\<{[key: string]: Object}>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：on(type: 'sessionEvent', callback: (sessionEvent: string, args: { [key: string]: Object }) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：off(type: 'sessionEvent', callback?: (sessionEvent: string, args: { [key: string]: Object }) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：on(type: 'queueItemsChange', callback: (items: Array\<AVQueueItem>) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：off(type: 'queueItemsChange', callback?: (items: Array\<AVQueueItem>) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：on(type: 'queueTitleChange', callback: (title: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：off(type: 'queueTitleChange', callback?: (title: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController<br>方法or属性：off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：BITS_PER_SAMPLE = 'BitsPerSample'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：ORIENTATION = 'Orientation'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：IMAGE_LENGTH = 'ImageLength'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：IMAGE_WIDTH = 'ImageWidth'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：GPS_LATITUDE = 'GPSLatitude'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：GPS_LONGITUDE = 'GPSLongitude'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：GPS_LATITUDE_REF = 'GPSLatitudeRef'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：GPS_LONGITUDE_REF = 'GPSLongitudeRef'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：DATE_TIME_ORIGINAL = 'DateTimeOriginal'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：EXPOSURE_TIME = 'ExposureTime'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：SCENE_TYPE = 'SceneType'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：ISO_SPEED_RATINGS = 'ISOSpeedRatings'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey<br>方法or属性：F_NUMBER = 'FNumber'|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：createPixelMapList(options?: DecodingOptions): Promise\<Array\<PixelMap>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：createPixelMapList(callback: AsyncCallback\<Array\<PixelMap>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：createPixelMapList(options: DecodingOptions, callback: AsyncCallback\<Array\<PixelMap>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：getDelayTime(): Promise\<Array\<number>>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：getDelayTime(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：getFrameCount(): Promise\<number>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource<br>方法or属性：getFrameCount(callback: AsyncCallback\<number>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：dataSrc?: AVDataSrcDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer<br>方法or属性：audioRendererInfo?: audio.AudioRendererInfo;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVDataSrcDescriptor|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVDataSrcDescriptor<br>方法 or 属性：fileSize: number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.media<br>类名: AVDataSrcDescriptor<br>方法 or 属性：callback: (buffer: ArrayBuffer, length: number, pos?: number) => number;|@ohos.multimedia.media.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: systemSoundManager|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: RingtoneType|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: RingtoneType<br>方法 or 属性: RINGTONE_TYPE_DEFAULT = 0|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: RingtoneType<br>方法 or 属性: RINGTONE_TYPE_MULTISIM = 1|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: systemSoundManager<br>方法 or 属性: function getSystemSoundManager(): SystemSoundManager;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: setSystemRingtoneUri(context: Context, uri: string, type: RingtoneType): Promise\<void>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: getSystemRingtoneUri(context: Context, type: RingtoneType, callback: AsyncCallback\<string>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: getSystemRingtoneUri(context: Context, type: RingtoneType): Promise\<string>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: getSystemRingtonePlayer(context: Context, type: RingtoneType, callback: AsyncCallback\<RingtonePlayer>): void;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ohos.multimedia.systemSoundManager<br>类名: SystemSoundManager<br>方法 or 属性: getSystemRingtonePlayer(context: Context, type: RingtoneType): Promise\<RingtonePlayer>;|@ohos.multimedia.systemSoundManager.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtoneOptions|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtoneOptions<br>方法 or 属性: volume: number;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtoneOptions<br>方法 or 属性: loop: boolean;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: readonly state: media.AVPlayerState;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: getTitle(callback: AsyncCallback\<string>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: getTitle(): Promise\<string>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: getAudioRendererInfo(callback: AsyncCallback\<audio.AudioRendererInfo>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: getAudioRendererInfo(): Promise\<audio.AudioRendererInfo>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: configure(options: RingtoneOptions, callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: configure(options: RingtoneOptions): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: start(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: start(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: stop(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: stop(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: release(callback: AsyncCallback\<void>): void;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: release(): Promise\<void>;|ringtonePlayer.d.ts|
|新增|NA|模块名: ringtonePlayer<br>类名: RingtonePlayer<br>方法 or 属性: on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void;|ringtonePlayer.d.ts|
|访问级别有变化|类名：VolumeEvent<br/>访问级别：公开API|类名：VolumeEvent<br/>访问级别：系统API|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent<br>方法 or 属性：volumeType: AudioVolumeType;;<br>访问级别：公开API|类名：VolumeEvent<br>方法 or 属性：volumeType: AudioVolumeType;;<br>访问级别：系统API|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent<br>方法 or 属性：volume: number;<br>访问级别：公开API|类名：VolumeEvent<br>方法 or 属性：volume: number;<br>访问级别：系统API|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：VolumeEvent<br/>方法 or 属性：updateUi: boolean;<br/>访问级别：公开API|类名：VolumeEvent<br/>方法 or 属性：updateUi: boolean;;<br/>访问级别：系统API|@ohos.multimedia.audio.d.ts|
|访问级别有变化|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：系统API|类名：AVSessionType<br>方法 or 属性：type AVSessionType = 'audio' \| 'video';<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>访问级别：系统API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;<br>访问级别：系统API|类名：avSession<br>方法 or 属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>访问级别：系统API|类名：AVSession<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setAVMetadata(data: AVMetadata): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setAVPlaybackState(state: AVPlaybackState): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：setLaunchAbility(ability: WantAgent): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：getController(callback: AsyncCallback\<AVSessionController>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getController(): Promise\<AVSessionController>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：getController(): Promise\<AVSessionController>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback?: () => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback?: () => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'seek', callback: (time: number) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'setSpeed', callback: (speed: number) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：activate(callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：activate(): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：activate(): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：deactivate(callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：deactivate(): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：deactivate(): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：destroy(callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSession<br>方法 or 属性：destroy(): Promise\<void>;<br>访问级别：系统API|类名：AVSession<br>方法 or 属性：destroy(): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br>访问级别：系统API|类名：AVMetadata<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：assetId: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：assetId: string;;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：title?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：title?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：artist?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：artist?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：author?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：author?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：album?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：album?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：writer?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：writer?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：composer?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：composer?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：duration?: number;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：duration?: number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：mediaImage?: image.PixelMap \|string;;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：mediaImage?: image.PixelMap \|string;;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：publishDate?: Date;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：publishDate?: Date;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：subtitle?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：subtitle?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：description?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：description?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：lyric?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：lyric?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：previousAssetId?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：previousAssetId?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVMetadata<br/>方法 or 属性：nextAssetId?: string;<br/>访问级别：系统API|类名：AVMetadata<br/>方法 or 属性：nextAssetId?: string;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>访问级别：系统API|类名：AVPlaybackState<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：state?: PlaybackState;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：state?: PlaybackState;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：speed?: number;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：speed?: number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：position?: PlaybackPosition;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：position?: PlaybackPosition;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：bufferedTime?: number;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：bufferedTime?: number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：loopMode?: LoopMode;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：loopMode?: LoopMode;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVPlaybackState<br>方法 or 属性：isFavorite?: boolean;<br/>访问级别：系统API|类名：AVPlaybackState<br>方法 or 属性：isFavorite?: boolean;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition<br>访问级别：系统API|类名：PlaybackPosition<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition<br>方法 or 属性：elapsedTime: number;<br/>访问级别：系统API|类名：PlaybackPosition<br>方法 or 属性：elapsedTime: number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackPosition<br>方法 or 属性：updateTime: number;<br/>访问级别：系统API|类名：PlaybackPosition<br>方法 or 属性：updateTime: number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>访问级别：系统API|类名：OutputDeviceInfo<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>方法 or 属性：  isRemote: boolean;<br/>访问级别：系统API|类名：OutputDeviceInfo<br>方法 or 属性：  isRemote: boolean;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>方法 or 属性：audioDeviceId: Array\<number>;<br/>访问级别：系统API|类名：OutputDeviceInfo<br>方法 or 属性：audioDeviceId: Array\<number>;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：OutputDeviceInfo<br>方法 or 属性：deviceName: Array\<string>;<br/>访问级别：系统API|类名：OutputDeviceInfo<br>方法 or 属性：deviceName: Array\<string>;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>访问级别：系统API|类名：LoopMode<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SEQUENCE = 0,<br/>访问级别：系统API|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SEQUENCE = 0,;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SINGLE = 1,<br/>访问级别：系统API|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SINGLE = 1,<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>方法 or 属性：LOOP_MODE_LIST = 2,<br/>访问级别：系统API|类名：LoopMode<br>方法 or 属性：LOOP_MODE_LIST = 2,<string>;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SHUFFLE = 3,<br/>访问级别：系统API|类名：LoopMode<br>方法 or 属性：LOOP_MODE_SHUFFLE = 3,<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>访问级别：系统API|类名：PlaybackState<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_INITIAL = 0<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_INITIAL = 0<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PREPARE = 1<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PREPARE = 1<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PLAY = 2<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PLAY = 2<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PAUSE = 3<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_PAUSE = 3<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_FAST_FORWARD = 4<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_FAST_FORWARD = 4<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_REWIND = 5<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_REWIND = 5<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_STOP = 6<br>访问级别：系统API|类名：PlaybackState<br>方法 or 属性：PLAYBACK_STATE_STOP = 6<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>访问级别：系统API|类名：AVSessionController<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：readonly sessionId: string;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise\<AVPlaybackState>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getAVPlaybackState(): Promise\<AVPlaybackState>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise\<AVMetadata>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getAVMetadata(): Promise\<AVMetadata>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getOutputDevice(): Promise\<OutputDeviceInfo>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise\<void>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：sendAVKeyEvent(event: KeyEvent): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise\<WantAgent>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getLaunchAbility(): Promise\<WantAgent>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getRealPlaybackPositionSync(): number;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback\<boolean>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：isActive(callback: AsyncCallback\<boolean>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：isActive(): Promise\<boolean>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：isActive(): Promise\<boolean>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：destroy(callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：destroy(): Promise\<void>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：destroy(): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise\<Array\<AVControlCommandType>>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：getValidCommands(): Promise\<Array\<AVControlCommandType>>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise\<void>;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：sendControlCommand(command: AVControlCommand): Promise\<void>;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'sessionDestroy', callback: () => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'sessionDestroy', callback?: () => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'sessionDestroy', callback?: () => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionController<br>方法 or 属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;<br>访问级别：系统API|类名：AVSessionController<br>方法 or 属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand<br>访问级别：系统API|类名：AVControlCommand<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand<br>方法 or 属性：command: AVControlCommandType;<br>访问级别：系统API|类名：AVControlCommand<br/>方法 or 属性：command: AVControlCommandType;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVControlCommand<br>方法 or 属性：parameter?: LoopMode \|string\|number;<br>访问级别：系统API|类名：AVControlCommand<br/>方法 or 属性：parameter?: LoopMode \|string\|number;<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode<br>访问级别：系统API|类名：AVSessionErrorCode<br>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SERVICE_EXCEPTION = 6600101<br>访问级别：系统API|类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SERVICE_EXCEPTION = 6600101,<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
|访问级别有变化|类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_NOT_EXIST = 6600102<br>访问级别：系统API|类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_NOT_EXIST = 6600102<br/>访问级别：公开API|@ohos.multimedia.avsession.d.ts|
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_NOT_EXIST = 6600102<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_NOT_EXIST = 6600102<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_CONTROLLER_NOT_EXIST = 6600103<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_NOT_EXIST = 6600103<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_REMOTE_CONNECTION_ERR = 6600104<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_REMOTE_CONNECTION_ERR = 6600104<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_COMMAND_INVALID = 6600105<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_COMMAND_INVALID = 6600105<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_INACTIVE = 6600106<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_SESSION_INACTIVE = 6600106<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |
| 访问级别有变化 | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_MESSAGE_OVERLOAD = 6600107<br>访问级别：系统API | 类名：AVSessionErrorCode<br>方法 or 属性：ERR_CODE_MESSAGE_OVERLOAD = 6600107<br/>访问级别：公开API | @ohos.multimedia.avsession.d.ts          |

