| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：AudioRenderer;<br>方法or属性：on(type: "markReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|删除|类名：AudioCapturer;<br>方法or属性：on(type: "markReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|删除|类名：AudioRenderer;<br>方法or属性：on(type: "periodReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|删除|类名：AudioCapturer;<br>方法or属性：on(type: "periodReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：CommunicationDeviceType;<br>方法or属性：SPEAKER = 2|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMute(volumeType: AudioVolumeType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：isActive(volumeType: AudioVolumeType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setMicrophoneMute(mute: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMicrophoneMute(callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：isMicrophoneMute(): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：setRingerMode(mode: AudioRingMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：getRingerMode(): Promise\<AudioRingMode>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：getTrackDescription() : Promise\<Array\<MediaDescription>>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'timeUpdate', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：loop: boolean;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：readonly currentTime: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：readonly duration: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：audioSampleRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：location?: Location;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：location?: Location;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：prepare(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：prepare(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：play(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：play(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：url: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：url: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：readonly width: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：readonly height: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'startRenderFrame', callback: Callback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createEffect(source: image.PixelMap): Filter;|@ohos.effectKit.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;|@ohos.effectKit.d.ts|
|新增|NA|类名：effectKit;<br>方法or属性：function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void;|@ohos.effectKit.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：blur(radius:number): Filter;|@ohos.effectKit.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：brightness(bright:number): Filter;|@ohos.effectKit.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：grayscale(): Filter;|@ohos.effectKit.d.ts|
|新增|NA|类名：Filter;<br>方法or属性：getPixelMap(): image.PixelMap;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：getMainColor(): Promise\<Color>;|@ohos.effectKit.d.ts|
|新增|NA|类名：ColorPicker;<br>方法or属性：getMainColorSync(): Color;|@ohos.effectKit.d.ts|
|新增|NA|类名：Color;<br>方法or属性：red: number;|@ohos.effectKit.d.ts|
|新增|NA|类名：Color;<br>方法or属性：green: number;|@ohos.effectKit.d.ts|
|新增|NA|类名：Color;<br>方法or属性：blue: number;|@ohos.effectKit.d.ts|
|新增|NA|类名：Color;<br>方法or属性：alpha: number;|@ohos.effectKit.d.ts|
|新增|NA|类名：audio;<br>方法or属性：function createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback\<TonePlayer>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：audio;<br>方法or属性：function createTonePlayer(options: AudioRendererInfo): Promise\<TonePlayer>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：audio;<br>方法or属性：type VolumeGroupInfos = Array\<Readonly\<VolumeGroupInfo>>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：audio;<br>方法or属性：type AudioRendererChangeInfoArray = Array\<Readonly\<AudioRendererChangeInfo>>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：audio;<br>方法or属性：type AudioCapturerChangeInfoArray = Array\<Readonly\<AudioCapturerChangeInfo>>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_INVALID_PARAM = 6800101|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_NO_MEMORY     = 6800102|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_ILLEGAL_STATE = 6800103|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_UNSUPPORTED   = 6800104|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_TIMEOUT       = 6800105|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_STREAM_LIMIT  = 6800201|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioErrors;<br>方法or属性：ERROR_SYSTEM        = 6800301|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeType;<br>方法or属性：ALL = 100|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：DeviceFlag;<br>方法or属性：NONE_DEVICES_FLAG = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：DeviceFlag;<br>方法or属性：DISTRIBUTED_OUTPUT_DEVICES_FLAG = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：DeviceFlag;<br>方法or属性：DISTRIBUTED_INPUT_DEVICES_FLAG = 8|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：DeviceFlag;<br>方法or属性：ALL_DISTRIBUTED_DEVICES_FLAG = 12|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：DeviceType;<br>方法or属性：DEFAULT = 1000|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioSampleFormat;<br>方法or属性：SAMPLE_FORMAT_F32LE = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：StreamUsage;<br>方法or属性：STREAM_USAGE_VOICE_ASSISTANT = 3|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptRequestType;<br>方法or属性：INTERRUPT_REQUEST_TYPE_DEFAULT = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererFilter;<br>方法or属性：uid: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererFilter;<br>方法or属性：rendererInfo?: AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererFilter;<br>方法or属性：rendererId?: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptMode;<br>方法or属性：SHARE_MODE = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptMode;<br>方法or属性：INDEPENDENT_MODE = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptForceType;<br>方法or属性：INTERRUPT_FORCE = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptForceType;<br>方法or属性：INTERRUPT_SHARE = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptEvent;<br>方法or属性：eventType: InterruptType;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptEvent;<br>方法or属性：forceType: InterruptForceType;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptEvent;<br>方法or属性：hintType: InterruptHint;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioManager;<br>方法or属性：getVolumeManager(): AudioVolumeManager;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioManager;<br>方法or属性：getStreamManager(): AudioStreamManager;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioManager;<br>方法or属性：getRoutingManager(): AudioRoutingManager;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptRequestResultType;<br>方法or属性：INTERRUPT_REQUEST_GRANT = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptRequestResultType;<br>方法or属性：INTERRUPT_REQUEST_REJECT = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptResult;<br>方法or属性：requestResult: InterruptRequestResultType;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：InterruptResult;<br>方法or属性：interruptNode: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback\<DeviceChangeAction>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRoutingManager;<br>方法or属性：selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioRendererInfoArray(callback: AsyncCallback\<AudioRendererChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioRendererInfoArray(): Promise\<AudioRendererChangeInfoArray>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioCapturerInfoArray(callback: AsyncCallback\<AudioCapturerChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：getCurrentAudioCapturerInfoArray(): Promise\<AudioCapturerChangeInfoArray>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：on(type: "audioRendererChange", callback: Callback\<AudioRendererChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：on(type: "audioCapturerChange", callback: Callback\<AudioCapturerChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：off(type: "audioRendererChange"): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioStreamManager;<br>方法or属性：off(type: "audioCapturerChange"): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupInfos(networkId: string, callback: AsyncCallback\<VolumeGroupInfos>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupInfos(networkId: string): Promise\<VolumeGroupInfos>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupManager(groupId: number, callback: AsyncCallback\<AudioVolumeGroupManager>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：getVolumeGroupManager(groupId: number): Promise\<AudioVolumeGroupManager>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeManager;<br>方法or属性：on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioVolumeGroupManager;<br>方法or属性：on(type: 'micStateChange', callback: Callback\<MicStateChangeEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_LOCAL = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ConnectType;<br>方法or属性：CONNECT_TYPE_DISTRIBUTED = 2|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeGroupInfo;<br>方法or属性：readonly networkId: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly networkId: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeGroupInfo;<br>方法or属性：readonly groupId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeGroupInfo;<br>方法or属性：readonly mappingId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeGroupInfo;<br>方法or属性：readonly groupName: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeGroupInfo;<br>方法or属性：readonly type: ConnectType;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererChangeInfo;<br>方法or属性：readonly streamId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerChangeInfo;<br>方法or属性：readonly streamId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererChangeInfo;<br>方法or属性：readonly clientUid: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerChangeInfo;<br>方法or属性：readonly clientUid: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererChangeInfo;<br>方法or属性：readonly rendererInfo: AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererChangeInfo;<br>方法or属性：readonly rendererState: AudioState;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRendererChangeInfo;<br>方法or属性：readonly deviceDescriptors: AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerChangeInfo;<br>方法or属性：readonly deviceDescriptors: AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerChangeInfo;<br>方法or属性：readonly capturerInfo: AudioCapturerInfo;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturerChangeInfo;<br>方法or属性：readonly capturerState: AudioState;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly id: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly name: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly address: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly sampleRates: Array\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly channelCounts: Array\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly channelMasks: Array\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly interruptGroupId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioDeviceDescriptor;<br>方法or属性：readonly volumeGroupId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeEvent;<br>方法or属性：volumeGroupId: number;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：VolumeEvent;<br>方法or属性：networkId: string;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：MicStateChangeEvent;<br>方法or属性：mute: boolean;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioStreamId(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioStreamId(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：getAudioStreamId(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：getAudioStreamId(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setInterruptMode(mode: InterruptMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setVolume(volume: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：setVolume(volume: number): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：on(type: "markReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：on(type: "markReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioRenderer;<br>方法or属性：on(type: "periodReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：AudioCapturer;<br>方法or属性：on(type: "periodReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：SOURCE_TYPE_VOICE_RECOGNITION = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_0 = 0|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_1 = 1|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_2 = 2|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_3 = 3|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_4 = 4|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_5 = 5|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_6 = 6|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_7 = 7|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_8 = 8|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_9 = 9|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_S = 10|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_P = 11|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_A = 12|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_B = 13|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_C = 14|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_DIAL_D = 15|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_DIAL = 100|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_BUSY = 101|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CONGESTION = 102|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK = 103|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE = 104|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING = 106|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_SUPERVISORY_RINGTONE = 107|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_BEEP = 200|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_ACK = 201|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_PROMPT = 203|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：ToneType;<br>方法or属性：TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP = 204|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：load(type: ToneType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：load(type: ToneType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：TonePlayer;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function createController(sessionId: string): Promise\<AVSessionController>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function on(type: 'sessionServiceDie', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function off(type: 'sessionServiceDie', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：type AVSessionType = 'audio' \| 'video';|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：avSession;<br>方法or属性：type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：SessionToken;<br>方法or属性：sessionId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：sessionId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：SessionToken;<br>方法or属性：pid: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：SessionToken;<br>方法or属性：uid: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：readonly sessionId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：readonly sessionId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVMetadata(data: AVMetadata): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setAVPlaybackState(state: AVPlaybackState): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：setLaunchAbility(ability: WantAgent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getController(callback: AsyncCallback\<AVSessionController>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getController(): Promise\<AVSessionController>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getOutputDevice(): Promise\<OutputDeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'seek', callback: (time: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'setSpeed', callback: (speed: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'toggleFavorite', callback: (assetId: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'seek', callback?: (time: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'setSpeed', callback?: (speed: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：activate(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：activate(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：deactivate(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：deactivate(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSession;<br>方法or属性：destroy(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：destroy(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：assetId: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：title?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：artist?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：author?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：album?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：writer?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：composer?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：duration?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：mediaImage?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：publishDate?: Date;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：subtitle?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：description?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：lyric?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：previousAssetId?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVMetadata;<br>方法or属性：nextAssetId?: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：state?: PlaybackState;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：speed?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：position?: PlaybackPosition;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：bufferedTime?: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：loopMode?: LoopMode;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVPlaybackState;<br>方法or属性：isFavorite?: boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackPosition;<br>方法or属性：elapsedTime: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackPosition;<br>方法or属性：updateTime: number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：OutputDeviceInfo;<br>方法or属性：isRemote: boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：OutputDeviceInfo;<br>方法or属性：audioDeviceId: Array\<number>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：OutputDeviceInfo;<br>方法or属性：deviceName: Array\<string>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：LoopMode;<br>方法or属性：LOOP_MODE_SEQUENCE = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：LoopMode;<br>方法or属性：LOOP_MODE_SINGLE = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：LoopMode;<br>方法or属性：LOOP_MODE_LIST = 2|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：LoopMode;<br>方法or属性：LOOP_MODE_SHUFFLE = 3|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_INITIAL = 0|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_PREPARE = 1|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_PLAY = 2|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_PAUSE = 3|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_FAST_FORWARD = 4|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_REWIND = 5|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：PlaybackState;<br>方法or属性：PLAYBACK_STATE_STOP = 6|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：type: AVSessionType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：sessionTag: string;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：elementName: ElementName;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：isActive: boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：isTopSession: boolean;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionDescriptor;<br>方法or属性：outputDevice: OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVPlaybackState(): Promise\<AVPlaybackState>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getAVMetadata(): Promise\<AVMetadata>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendAVKeyEvent(event: KeyEvent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getLaunchAbility(): Promise\<WantAgent>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getRealPlaybackPositionSync(): number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：isActive(callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：isActive(): Promise\<boolean>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：getValidCommands(): Promise\<Array\<AVControlCommandType>>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：sendControlCommand(command: AVControlCommand): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'sessionDestroy', callback: () => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'activeStateChange', callback: (isActive: boolean) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'metadataChange', callback?: (data: AVMetadata) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'sessionDestroy', callback?: () => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'activeStateChange', callback?: (isActive: boolean) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionController;<br>方法or属性：off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVControlCommand;<br>方法or属性：command: AVControlCommandType;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVControlCommand;<br>方法or属性：parameter?: LoopMode \| string \| number;|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_SERVICE_EXCEPTION = 6600101|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_SESSION_NOT_EXIST = 6600102|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_CONTROLLER_NOT_EXIST = 6600103|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_REMOTE_CONNECTION_ERR = 6600104|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_COMMAND_INVALID = 6600105|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_SESSION_INACTIVE = 6600106|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：AVSessionErrorCode;<br>方法or属性：ERR_CODE_MESSAGE_OVERLOAD = 6600107|@ohos.multimedia.avsession.d.ts|
|新增|NA|类名：camera;<br>方法or属性：function getCameraManager(context: Context): CameraManager;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatus;<br>方法or属性：CAMERA_STATUS_APPEAR = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatus;<br>方法or属性：CAMERA_STATUS_DISAPPEAR = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatus;<br>方法or属性：CAMERA_STATUS_AVAILABLE = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatus;<br>方法or属性：CAMERA_STATUS_UNAVAILABLE = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Profile;<br>方法or属性：readonly format: CameraFormat;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Profile;<br>方法or属性：readonly size: Size;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FrameRateRange;<br>方法or属性：readonly min: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FrameRateRange;<br>方法or属性：readonly max: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoProfile;<br>方法or属性：readonly frameRateRange: FrameRateRange;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutputCapability;<br>方法or属性：readonly previewProfiles: Array\<Profile>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutputCapability;<br>方法or属性：readonly photoProfiles: Array\<Profile>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutputCapability;<br>方法or属性：readonly videoProfiles: Array\<VideoProfile>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutputCapability;<br>方法or属性：readonly supportedMetadataObjectTypes: Array\<MetadataObjectType>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：INVALID_ARGUMENT = 7400101|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：OPERATION_NOT_ALLOWED = 7400102|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：SESSION_NOT_CONFIG = 7400103|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：SESSION_NOT_RUNNING = 7400104|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：SESSION_CONFIG_LOCKED = 7400105|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：DEVICE_SETTING_LOCKED = 7400106|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：CONFILICT_CAMERA = 7400107|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：DEVICE_DISABLED = 7400108|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraErrorCode;<br>方法or属性：SERVICE_FATAL_ERROR = 7400201|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：getSupportedCameras(): Array\<CameraDevice>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：isCameraMuted(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：isCameraMuteSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：muteCamera(mute: boolean): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createCameraInput(camera: CameraDevice): CameraInput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createCameraInput(position: CameraPosition, type: CameraType): CameraInput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType>): MetadataOutput;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：createCaptureSession(): CaptureSession;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraManager;<br>方法or属性：on(type: 'cameraMute', callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatusInfo;<br>方法or属性：camera: CameraDevice;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraStatusInfo;<br>方法or属性：status: CameraStatus;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraPosition;<br>方法or属性：CAMERA_POSITION_UNSPECIFIED = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraPosition;<br>方法or属性：CAMERA_POSITION_BACK = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraPosition;<br>方法or属性：CAMERA_POSITION_FRONT = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType;<br>方法or属性：CAMERA_TYPE_DEFAULT = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType;<br>方法or属性：CAMERA_TYPE_WIDE_ANGLE = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType;<br>方法or属性：CAMERA_TYPE_ULTRA_WIDE = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType;<br>方法or属性：CAMERA_TYPE_TELEPHOTO = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraType;<br>方法or属性：CAMERA_TYPE_TRUE_DEPTH = 4|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ConnectionType;<br>方法or属性：CAMERA_CONNECTION_BUILT_IN = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ConnectionType;<br>方法or属性：CAMERA_CONNECTION_USB_PLUGIN = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ConnectionType;<br>方法or属性：CAMERA_CONNECTION_REMOTE = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly cameraId: string;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly cameraPosition: CameraPosition;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly cameraType: CameraType;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraDevice;<br>方法or属性：readonly connectionType: ConnectionType;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Size;<br>方法or属性：height: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：height: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Size;<br>方法or属性：width: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：width: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Point;<br>方法or属性：x: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Point;<br>方法or属性：y: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：open(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：open(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：close(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraInput;<br>方法or属性：on(type: 'error', camera: CameraDevice, callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraFormat;<br>方法or属性：CAMERA_FORMAT_RGBA_8888 = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraFormat;<br>方法or属性：CAMERA_FORMAT_YUV_420_SP = 1003|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraFormat;<br>方法or属性：CAMERA_FORMAT_JPEG = 2000|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FlashMode;<br>方法or属性：FLASH_MODE_CLOSE = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FlashMode;<br>方法or属性：FLASH_MODE_OPEN = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FlashMode;<br>方法or属性：FLASH_MODE_AUTO = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FlashMode;<br>方法or属性：FLASH_MODE_ALWAYS_OPEN = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ExposureMode;<br>方法or属性：EXPOSURE_MODE_LOCKED = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ExposureMode;<br>方法or属性：EXPOSURE_MODE_AUTO = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ExposureMode;<br>方法or属性：EXPOSURE_MODE_CONTINUOUS_AUTO = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusMode;<br>方法or属性：FOCUS_MODE_MANUAL = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusMode;<br>方法or属性：FOCUS_MODE_CONTINUOUS_AUTO = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusMode;<br>方法or属性：FOCUS_MODE_AUTO = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusMode;<br>方法or属性：FOCUS_MODE_LOCKED = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusState;<br>方法or属性：FOCUS_STATE_SCAN = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusState;<br>方法or属性：FOCUS_STATE_FOCUSED = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FocusState;<br>方法or属性：FOCUS_STATE_UNFOCUSED = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoStabilizationMode;<br>方法or属性：OFF = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoStabilizationMode;<br>方法or属性：LOW = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoStabilizationMode;<br>方法or属性：MIDDLE = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoStabilizationMode;<br>方法or属性：HIGH = 3|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoStabilizationMode;<br>方法or属性：AUTO = 4|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：beginConfig(): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：commitConfig(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：commitConfig(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：addInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：removeInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：addOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：removeOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutput;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CameraOutput;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：hasFlash(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：isFlashModeSupported(flashMode: FlashMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getFlashMode(): FlashMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setFlashMode(flashMode: FlashMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：isExposureModeSupported(aeMode: ExposureMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getExposureMode(): ExposureMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setExposureMode(aeMode: ExposureMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getMeteringPoint(): Point;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setMeteringPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getExposureBiasRange(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setExposureBias(exposureBias: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getExposureValue(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：isFocusModeSupported(afMode: FocusMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getFocusMode(): FocusMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setFocusMode(afMode: FocusMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setFocusPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getFocusPoint(): Point;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getFocalLength(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getZoomRatioRange(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getZoomRatio(): number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setZoomRatio(zoomRatio: number): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：getActiveVideoStabilizationMode(): VideoStabilizationMode;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：setVideoStabilizationMode(mode: VideoStabilizationMode): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureSession;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：on(type: 'frameStart', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：on(type: 'frameStart', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PreviewOutput;<br>方法or属性：on(type: 'frameEnd', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：VideoOutput;<br>方法or属性：on(type: 'frameEnd', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ImageRotation;<br>方法or属性：ROTATION_0 = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ImageRotation;<br>方法or属性：ROTATION_90 = 90|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ImageRotation;<br>方法or属性：ROTATION_180 = 180|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：ImageRotation;<br>方法or属性：ROTATION_270 = 270|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Location;<br>方法or属性：latitude: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Location;<br>方法or属性：longitude: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Location;<br>方法or属性：altitude: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：QualityLevel;<br>方法or属性：QUALITY_LEVEL_HIGH = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：QualityLevel;<br>方法or属性：QUALITY_LEVEL_MEDIUM = 1|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：QualityLevel;<br>方法or属性：QUALITY_LEVEL_LOW = 2|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoCaptureSetting;<br>方法or属性：quality?: QualityLevel;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoCaptureSetting;<br>方法or属性：rotation?: ImageRotation;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoCaptureSetting;<br>方法or属性：location?: Location;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoCaptureSetting;<br>方法or属性：mirror?: boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：capture(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：capture(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：capture(setting?: PhotoCaptureSetting): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：isMirrorSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'captureStart', callback: AsyncCallback\<number>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：PhotoOutput;<br>方法or属性：on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FrameShutterInfo;<br>方法or属性：captureId: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureEndInfo;<br>方法or属性：captureId: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：FrameShutterInfo;<br>方法or属性：timestamp: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：CaptureEndInfo;<br>方法or属性：frameCount: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObjectType;<br>方法or属性：FACE_DETECTION = 0|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：topLeftX: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：topLeftY: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject;<br>方法or属性：readonly type: MetadataObjectType;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject;<br>方法or属性：readonly timestamp: number;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataObject;<br>方法or属性：readonly boundingBox: Rect;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：MetadataOutput;<br>方法or属性：on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject>>): void;|@ohos.multimedia.camera.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageSource(uri: string, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageSource(fd: number, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：image;<br>方法or属性：function createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：BGRA_8888 = 4|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：RGB_888 = 5|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：ALPHA_8 = 6|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：RGBA_F16 = 7|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：NV21 = 8|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMapFormat;<br>方法or属性：NV12 = 9|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：DATE_TIME_ORIGINAL = "DateTimeOriginal"|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：EXPOSURE_TIME = "ExposureTime"|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：SCENE_TYPE = "SceneType"|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：ISO_SPEED_RATINGS = "ISOSpeedRatings"|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PropertyKey;<br>方法or属性：F_NUMBER = "FNumber"|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageFormat;<br>方法or属性：YCBCR_422_SP = 1000|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageFormat;<br>方法or属性：JPEG = 2000|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AlphaType;<br>方法or属性：UNKNOWN = 0|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AlphaType;<br>方法or属性：OPAQUE = 1|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AlphaType;<br>方法or属性：PREMUL = 2|@ohos.multimedia.image.d.ts|
|新增|NA|类名：AlphaType;<br>方法or属性：UNPREMUL = 3|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ScaleMode;<br>方法or属性：FIT_TARGET_SIZE = 0|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ScaleMode;<br>方法or属性：CENTER_CROP = 1|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ComponentType;<br>方法or属性：YUV_Y = 1|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ComponentType;<br>方法or属性：YUV_U = 2|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ComponentType;<br>方法or属性：YUV_V = 3|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ComponentType;<br>方法or属性：JPEG = 4|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageInfo;<br>方法or属性：density: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PackingOption;<br>方法or属性：bufferSize?: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：DecodingOptions;<br>方法or属性：fitDensity?: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Component;<br>方法or属性：readonly componentType: ComponentType;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Component;<br>方法or属性：readonly rowStride: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Component;<br>方法or属性：readonly pixelStride: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Component;<br>方法or属性：readonly byteBuffer: ArrayBuffer;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：InitializationOptions;<br>方法or属性：alphaType?: AlphaType;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：InitializationOptions;<br>方法or属性：scaleMode?: ScaleMode;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：SourceOptions;<br>方法or属性：sourceDensity: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：SourceOptions;<br>方法or属性：sourcePixelFormat?: PixelMapFormat;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：SourceOptions;<br>方法or属性：sourceSize?: Size;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：getDensity():number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：opacity(rate: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：opacity(rate: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(): Promise\<PixelMap>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：scale(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：scale(x: number, y: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：translate(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：translate(x: number, y: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：rotate(angle: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：rotate(angle: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：flip(horizontal: boolean, vertical: boolean): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：crop(region: Region, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：PixelMap;<br>方法or属性：crop(region: Region): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageSource;<br>方法or属性：updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：clipRect: Region;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：readonly size: Size;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readonly size: Size;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：readonly format: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：getComponent(componentType: ComponentType): Promise\<Component>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：Image;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readonly capacity: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：readonly capacity: number;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readonly format: ImageFormat;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：readonly format: ImageFormat;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：getReceivingSurfaceId(callback: AsyncCallback\<string>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：getReceivingSurfaceId(): Promise\<string>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readLatestImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readLatestImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readNextImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：readNextImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageReceiver;<br>方法or属性：on(type: 'imageArrival', callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：dequeueImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：dequeueImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：queueImage(interface: Image, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：queueImage(interface: Image): Promise\<void>;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：ImageCreator;<br>方法or属性：on(type: 'imageRelease', callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createAVPlayer(callback: AsyncCallback\<AVPlayer>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createAVPlayer() : Promise\<AVPlayer>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createAVRecorder(callback: AsyncCallback\<AVRecorder>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createAVRecorder() : Promise\<AVRecorder>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：function createVideoRecorder(): Promise\<VideoRecorder>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：media;<br>方法or属性：type VideoRecordState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';|@ohos.multimedia.media.d.ts|
|新增|NA|类名：StateChangeReason;<br>方法or属性：USER = 1|@ohos.multimedia.media.d.ts|
|新增|NA|类名：StateChangeReason;<br>方法or属性：BACKGROUND = 2|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_OK = 0|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_NO_PERMISSION = 201|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_INVALID_PARAMETER = 401|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_UNSUPPORT_CAPABILITY = 801|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_NO_MEMORY = 5400101|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_OPERATE_NOT_PERMIT = 5400102|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_IO = 5400103|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_TIMEOUT = 5400104|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_SERVICE_DIED = 5400105|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVErrorCode;<br>方法or属性：AVERR_UNSUPPORT_FORMAT = 5400106|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：seek(timeMs: number, mode?:SeekMode): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：setVolume(volume: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：url ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：fdSrc ?: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AudioPlayer;<br>方法or属性：audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoPlayer;<br>方法or属性：audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：readonly state: AVPlayerState;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：surfaceId ?: string;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoPlayer;<br>方法or属性：videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：setSpeed(speed: PlaybackSpeed): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：setBitrate(bitrate: number): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'volumeChange', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'endOfStream', callback: Callback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'seekDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'speedDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'bitrateDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'durationUpdate', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AudioPlayer;<br>方法or属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoPlayer;<br>方法or属性：on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'volumeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'endOfStream'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'seekDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'speedDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'bitrateDone'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'timeUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'durationUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'bufferingUpdate'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'startRenderFrame'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'videoSizeChange'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'audioInterrupt'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'availableBitrates'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVPlayer;<br>方法or属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVFileDescriptor;<br>方法or属性：fd: number|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVFileDescriptor;<br>方法or属性：offset?: number|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVFileDescriptor;<br>方法or属性：length?: number|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AudioPlayer;<br>方法or属性：fdSrc: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoPlayer;<br>方法or属性：fdSrc: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：prepare(config: AVRecorderConfig): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：getInputSurface(callback: AsyncCallback\<string>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：getInputSurface(callback: AsyncCallback\<string>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：getInputSurface(): Promise\<string>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：getInputSurface(): Promise\<string>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：start(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：resume(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：resume(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：resume(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：resume(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：readonly state: AVRecorderState;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorder;<br>方法or属性：on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：prepare(config: VideoRecorderConfig): Promise\<void>;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorder;<br>方法or属性：readonly state: VideoRecordState;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoScaleType;<br>方法or属性：VIDEO_SCALE_TYPE_FIT = 0|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoScaleType;<br>方法or属性：VIDEO_SCALE_TYPE_FIT_CROP = 1|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly audioBitrate: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly audioChannels: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly audioCodec: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly audioSampleRate: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly videoBitrate: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly videoCodec: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly videoFrameWidth: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly videoFrameHeight: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderProfile;<br>方法or属性：readonly videoFrameRate: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AudioSourceType;<br>方法or属性：AUDIO_SOURCE_TYPE_DEFAULT = 0|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AudioSourceType;<br>方法or属性：AUDIO_SOURCE_TYPE_MIC = 1|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoSourceType;<br>方法or属性：VIDEO_SOURCE_TYPE_SURFACE_YUV = 0|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoSourceType;<br>方法or属性：VIDEO_SOURCE_TYPE_SURFACE_ES = 1|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：videoSourceType: VideoSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：profile: VideoRecorderProfile;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：VideoRecorderConfig;<br>方法or属性：rotation?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：rotation?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：audioBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：audioChannels?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：audioCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：videoBitrate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：videoCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：videoFrameWidth?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：videoFrameHeight?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderProfile;<br>方法or属性：videoFrameRate?: number;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：videoSourceType?: VideoSourceType;|@ohos.multimedia.media.d.ts|
|新增|NA|类名：AVRecorderConfig;<br>方法or属性：profile: AVRecorderProfile;|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：ActiveDeviceType;<br>方法or属性：enum ActiveDeviceType<br>旧版本信息：|类名：ActiveDeviceType;<br>方法or属性：enum ActiveDeviceType<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.CommunicationDeviceType|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ActiveDeviceType;<br>方法or属性：SPEAKER = 2<br>旧版本信息：|类名：ActiveDeviceType;<br>方法or属性：SPEAKER = 2<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.CommunicationDeviceType.SPEAKER|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：ActiveDeviceType;<br>方法or属性：BLUETOOTH_SCO = 7<br>旧版本信息：|类名：ActiveDeviceType;<br>方法or属性：BLUETOOTH_SCO = 7<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.CommunicationDeviceType|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptActionType;<br>方法or属性：enum InterruptActionType<br>旧版本信息：|类名：InterruptActionType;<br>方法or属性：enum InterruptActionType<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptActionType;<br>方法or属性：TYPE_ACTIVATED = 0<br>旧版本信息：|类名：InterruptActionType;<br>方法or属性：TYPE_ACTIVATED = 0<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptActionType;<br>方法or属性：TYPE_INTERRUPT = 1<br>旧版本信息：|类名：InterruptActionType;<br>方法or属性：TYPE_INTERRUPT = 1<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType): Promise\<number>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getVolume(volumeType: AudioVolumeType): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType): Promise\<number>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getMinVolume(volumeType: AudioVolumeType): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#getDevices|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#getDevices|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#mute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#mute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#isMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isMute(volumeType: AudioVolumeType): Promise\<boolean>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isMute(volumeType: AudioVolumeType): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#isMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioStreamManager#isActive|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isActive(volumeType: AudioVolumeType): Promise\<boolean>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isActive(volumeType: AudioVolumeType): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioStreamManager#isActive|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setMicrophoneMute(mute: boolean): Promise\<void>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setMicrophoneMute(mute: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isMicrophoneMute(): Promise\<boolean>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isMicrophoneMute(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setRingerMode(mode: AudioRingMode): Promise\<void>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setRingerMode(mode: AudioRingMode): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：getRingerMode(): Promise\<AudioRingMode>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：getRingerMode(): Promise\<AudioRingMode>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioVolumeGroupManager#event:ringerModeChange|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#event:deviceChange|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioManager;<br>方法or属性：off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;<br>旧版本信息：|类名：AudioManager;<br>方法or属性：off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.AudioRoutingManager#event:deviceChange|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptAction;<br>方法or属性：interface InterruptAction<br>旧版本信息：|类名：InterruptAction;<br>方法or属性：interface InterruptAction<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptAction;<br>方法or属性：actionType: InterruptActionType;<br>旧版本信息：|类名：InterruptAction;<br>方法or属性：actionType: InterruptActionType;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptAction;<br>方法or属性：type?: InterruptType;<br>旧版本信息：|类名：InterruptAction;<br>方法or属性：type?: InterruptType;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptAction;<br>方法or属性：hint?: InterruptHint;<br>旧版本信息：|类名：InterruptAction;<br>方法or属性：hint?: InterruptHint;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：InterruptAction;<br>方法or属性：activated?: boolean;<br>旧版本信息：|类名：InterruptAction;<br>方法or属性：activated?: boolean;<br>新版本信息：9<br>代替接口： ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioInterrupt;<br>方法or属性：interface AudioInterrupt<br>旧版本信息：|类名：AudioInterrupt;<br>方法or属性：interface AudioInterrupt<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioInterrupt;<br>方法or属性：streamUsage: StreamUsage;<br>旧版本信息：|类名：AudioInterrupt;<br>方法or属性：streamUsage: StreamUsage;<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioInterrupt;<br>方法or属性：contentType: ContentType;<br>旧版本信息：|类名：AudioInterrupt;<br>方法or属性：contentType: ContentType;<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：AudioInterrupt;<br>方法or属性：pauseWhenDucked: boolean;<br>旧版本信息：|类名：AudioInterrupt;<br>方法or属性：pauseWhenDucked: boolean;<br>新版本信息：9<br>代替接口：|@ohos.multimedia.audio.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：function createAudioPlayer(): AudioPlayer;<br>旧版本信息：|类名：media;<br>方法or属性：function createAudioPlayer(): AudioPlayer;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：function createAudioRecorder(): AudioRecorder;<br>旧版本信息：|类名：media;<br>方法or属性：function createAudioRecorder(): AudioRecorder;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media#createAVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：function createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>旧版本信息：|类名：media;<br>方法or属性：function createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：function createVideoPlayer() : Promise\<VideoPlayer>;<br>旧版本信息：|类名：media;<br>方法or属性：function createVideoPlayer() : Promise\<VideoPlayer>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>旧版本信息：|类名：media;<br>方法or属性：type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayerState|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：media;<br>方法or属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>旧版本信息：|类名：media;<br>方法or属性：type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayerState|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：interface AudioPlayer<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：interface AudioPlayer<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：play(): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：play(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：pause(): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：pause(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：pause(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：pause(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#pause|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：stop(): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：stop(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：stop(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：stop(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#stop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：reset(): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：reset(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：reset(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：reset(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#reset|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：seek(timeMs: number): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：seek(timeMs: number): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：setVolume(vol: number): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：setVolume(vol: number): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：release(): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：release(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：release(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：release(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#release|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:stateChange|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：on(type: 'timeUpdate', callback: Callback\<number>): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：on(type: 'timeUpdate', callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:timeUpdate|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:error|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#on|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:error|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：src: string;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：src: string;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#url|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：loop: boolean;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：loop: boolean;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#loop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：loop: boolean;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：loop: boolean;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#loop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：readonly currentTime: number;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：readonly currentTime: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#currentTime|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：readonly currentTime: number;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：readonly currentTime: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#currentTime|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：readonly duration: number;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：readonly duration: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#duration|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：readonly duration: number;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：readonly duration: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#duration|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioPlayer;<br>方法or属性：readonly state: AudioState;<br>旧版本信息：|类名：AudioPlayer;<br>方法or属性：readonly state: AudioState;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#state|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：interface AudioRecorderConfig<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：interface AudioRecorderConfig<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：audioEncodeBitRate?: number;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：audioEncodeBitRate?: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：audioSampleRate?: number;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：audioSampleRate?: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：numberOfChannels?: number;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：numberOfChannels?: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：uri: string;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：uri: string;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：location?: Location;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：location?: Location;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：audioEncoderMime?: CodecMimeType;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：audioEncoderMime?: CodecMimeType;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorderConfig;<br>方法or属性：fileFormat?: ContainerFormatType;<br>旧版本信息：|类名：AudioRecorderConfig;<br>方法or属性：fileFormat?: ContainerFormatType;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：interface AudioRecorder<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：interface AudioRecorder<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：prepare(config: AudioRecorderConfig): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：prepare(config: AudioRecorderConfig): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#prepare|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：start(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：start(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#start|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：resume(): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：resume(): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#resume|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：AudioRecorder;<br>方法or属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>旧版本信息：|类名：AudioRecorder;<br>方法or属性：on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVRecorder#on|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：interface VideoPlayer<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：interface VideoPlayer<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#surfaceId|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setDisplaySurface(surfaceId: string): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setDisplaySurface(surfaceId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#surfaceId|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：prepare(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：prepare(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#prepare|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：prepare(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：prepare(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#prepare|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：play(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：play(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：play(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：play(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：pause(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：pause(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：stop(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：stop(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：reset(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：reset(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：reset(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：reset(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, mode?:SeekMode): Promise\<number>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：seek(timeMs: number, mode?:SeekMode): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setVolume(vol: number): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setVolume(vol: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：url: string;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：url: string;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#url|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：readonly state: VideoPlayState;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：readonly state: VideoPlayState;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#state|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：readonly width: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#width|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：readonly height: number;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#height|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#setSpeed|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：setSpeed(speed:number): Promise\<number>;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：setSpeed(speed:number): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#setSpeed|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：on(type: 'playbackCompleted', callback: Callback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：on(type: 'playbackCompleted', callback: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:stateChange|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：on(type: 'startRenderFrame', callback: Callback\<void>): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：on(type: 'startRenderFrame', callback: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:startRenderFrame|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：VideoPlayer;<br>方法or属性：on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>旧版本信息：|类名：VideoPlayer;<br>方法or属性：on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>新版本信息：9<br>代替接口： ohos.multimedia.media/media.AVPlayer#event:videoSizeChange|@ohos.multimedia.media.d.ts|
|废弃版本有变化|类名：mediaLibrary;<br>方法or属性：declare mediaLibrary<br>旧版本信息：|类名：mediaLibrary;<br>方法or属性：declare mediaLibrary<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：mediaLibrary;<br>方法or属性：function getMediaLibrary(): MediaLibrary;<br>旧版本信息：|类名：mediaLibrary;<br>方法or属性：function getMediaLibrary(): MediaLibrary;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：mediaLibrary;<br>方法or属性：function getMediaLibrary(context: Context): MediaLibrary;<br>旧版本信息：|类名：mediaLibrary;<br>方法or属性：function getMediaLibrary(context: Context): MediaLibrary;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaType;<br>方法or属性：enum MediaType<br>旧版本信息：|类名：MediaType;<br>方法or属性：enum MediaType<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaType;<br>方法or属性：FILE = 0<br>旧版本信息：|类名：MediaType;<br>方法or属性：FILE = 0<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaType;<br>方法or属性：IMAGE<br>旧版本信息：|类名：MediaType;<br>方法or属性：IMAGE<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaType;<br>方法or属性：VIDEO<br>旧版本信息：|类名：MediaType;<br>方法or属性：VIDEO<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaType;<br>方法or属性：AUDIO<br>旧版本信息：|类名：MediaType;<br>方法or属性：AUDIO<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaAssetOption;<br>方法or属性：interface MediaAssetOption<br>旧版本信息：|类名：MediaAssetOption;<br>方法or属性：interface MediaAssetOption<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaAssetOption;<br>方法or属性：src: string;<br>旧版本信息：|类名：MediaAssetOption;<br>方法or属性：src: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaAssetOption;<br>方法or属性：mimeType: string;<br>旧版本信息：|类名：MediaAssetOption;<br>方法or属性：mimeType: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaAssetOption;<br>方法or属性：relativePath?: string;<br>旧版本信息：|类名：MediaAssetOption;<br>方法or属性：relativePath?: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaSelectOption;<br>方法or属性：interface MediaSelectOption<br>旧版本信息：|类名：MediaSelectOption;<br>方法or属性：interface MediaSelectOption<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaSelectOption;<br>方法or属性：type: 'image' \| 'video' \| 'media';<br>旧版本信息：|类名：MediaSelectOption;<br>方法or属性：type: 'image' \| 'video' \| 'media';<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaSelectOption;<br>方法or属性：count: number;<br>旧版本信息：|类名：MediaSelectOption;<br>方法or属性：count: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：interface FileAsset<br>旧版本信息：|类名：FileAsset;<br>方法or属性：interface FileAsset<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly id: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly id: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly uri: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly uri: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly mimeType: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly mimeType: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly mediaType: MediaType;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly mediaType: MediaType;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：displayName: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：displayName: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：title: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：title: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：relativePath: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：relativePath: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly parent: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly parent: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly size: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly size: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly dateAdded: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly dateAdded: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly dateModified: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly dateModified: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly dateModified: number;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly dateModified: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly dateTaken: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly dateTaken: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly artist: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly artist: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly audioAlbum: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly audioAlbum: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly width: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly height: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：orientation: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：orientation: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly duration: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly duration: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly albumId: number;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly albumId: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly albumId: number;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly albumId: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly albumUri: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly albumUri: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly albumUri: string;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly albumUri: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：readonly albumName: string;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：readonly albumName: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isDirectory(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isDirectory(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isDirectory():Promise\<boolean>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isDirectory():Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Album;<br>方法or属性：commitModify(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：commitModify(): Promise\<void>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：commitModify(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：commitModify(): Promise\<void>;<br>旧版本信息：|类名：Album;<br>方法or属性：commitModify(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：open(mode: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：open(mode: string, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：open(mode: string): Promise\<number>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：open(mode: string): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：close(fd: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：close(fd: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：close(fd: number): Promise\<void>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：close(fd: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：getThumbnail(size?: Size): Promise\<image.PixelMap>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：getThumbnail(size?: Size): Promise\<image.PixelMap>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：favorite(isFavorite: boolean): Promise\<void>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：favorite(isFavorite: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isFavorite(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isFavorite(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isFavorite():Promise\<boolean>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isFavorite():Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：trash(isTrash: boolean): Promise\<void>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：trash(isTrash: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isTrash(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isTrash(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileAsset;<br>方法or属性：isTrash():Promise\<boolean>;<br>旧版本信息：|类名：FileAsset;<br>方法or属性：isTrash():Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：enum FileKey<br>旧版本信息：|类名：FileKey;<br>方法or属性：enum FileKey<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：ID = "file_id"<br>旧版本信息：|类名：FileKey;<br>方法or属性：ID = "file_id"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：RELATIVE_PATH = "relative_path"<br>旧版本信息：|类名：FileKey;<br>方法or属性：RELATIVE_PATH = "relative_path"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：DISPLAY_NAME = "display_name"<br>旧版本信息：|类名：FileKey;<br>方法or属性：DISPLAY_NAME = "display_name"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：PARENT = "parent"<br>旧版本信息：|类名：FileKey;<br>方法or属性：PARENT = "parent"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：MIME_TYPE = "mime_type"<br>旧版本信息：|类名：FileKey;<br>方法or属性：MIME_TYPE = "mime_type"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：MEDIA_TYPE = "media_type"<br>旧版本信息：|类名：FileKey;<br>方法or属性：MEDIA_TYPE = "media_type"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：SIZE = "size"<br>旧版本信息：|类名：FileKey;<br>方法or属性：SIZE = "size"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：DATE_ADDED = "date_added"<br>旧版本信息：|类名：FileKey;<br>方法or属性：DATE_ADDED = "date_added"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：DATE_MODIFIED = "date_modified"<br>旧版本信息：|类名：FileKey;<br>方法or属性：DATE_MODIFIED = "date_modified"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：DATE_TAKEN = "date_taken"<br>旧版本信息：|类名：FileKey;<br>方法or属性：DATE_TAKEN = "date_taken"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：TITLE = "title"<br>旧版本信息：|类名：FileKey;<br>方法or属性：TITLE = "title"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：ARTIST = "artist"<br>旧版本信息：|类名：FileKey;<br>方法or属性：ARTIST = "artist"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：AUDIOALBUM = "audio_album"<br>旧版本信息：|类名：FileKey;<br>方法or属性：AUDIOALBUM = "audio_album"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：DURATION = "duration"<br>旧版本信息：|类名：FileKey;<br>方法or属性：DURATION = "duration"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：WIDTH = "width"<br>旧版本信息：|类名：FileKey;<br>方法or属性：WIDTH = "width"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：HEIGHT = "height"<br>旧版本信息：|类名：FileKey;<br>方法or属性：HEIGHT = "height"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：ORIENTATION = "orientation"<br>旧版本信息：|类名：FileKey;<br>方法or属性：ORIENTATION = "orientation"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：ALBUM_ID = "bucket_id"<br>旧版本信息：|类名：FileKey;<br>方法or属性：ALBUM_ID = "bucket_id"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FileKey;<br>方法or属性：ALBUM_NAME = "bucket_display_name"<br>旧版本信息：|类名：FileKey;<br>方法or属性：ALBUM_NAME = "bucket_display_name"<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：interface MediaFetchOptions<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：interface MediaFetchOptions<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：selections: string;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：selections: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：selectionArgs: Array\<string>;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：selectionArgs: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：order?: string;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：order?: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：uri?: string;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：uri?: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：networkId?: string;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：networkId?: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaFetchOptions;<br>方法or属性：extendArgs?: string;<br>旧版本信息：|类名：MediaFetchOptions;<br>方法or属性：extendArgs?: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：interface FetchFileResult<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：interface FetchFileResult<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getCount(): number;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getCount(): number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：isAfterLast(): boolean;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：isAfterLast(): boolean;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：close(): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：close(): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getFirstObject(): Promise\<FileAsset>;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getFirstObject(): Promise\<FileAsset>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getNextObject(): Promise\<FileAsset>;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getNextObject(): Promise\<FileAsset>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getLastObject(): Promise\<FileAsset>;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getLastObject(): Promise\<FileAsset>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getPositionObject(index: number): Promise\<FileAsset>;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getPositionObject(index: number): Promise\<FileAsset>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：FetchFileResult;<br>方法or属性：getAllObject(): Promise\<Array\<FileAsset>>;<br>旧版本信息：|类名：FetchFileResult;<br>方法or属性：getAllObject(): Promise\<Array\<FileAsset>>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：interface Album<br>旧版本信息：|类名：Album;<br>方法or属性：interface Album<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：albumName: string;<br>旧版本信息：|类名：Album;<br>方法or属性：albumName: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly count: number;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly count: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly relativePath: string;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly relativePath: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：readonly coverUri: string;<br>旧版本信息：|类名：Album;<br>方法or属性：readonly coverUri: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>旧版本信息：|类名：Album;<br>方法or属性：getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>旧版本信息：|类名：Album;<br>方法or属性：getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Album;<br>方法or属性：getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>;<br>旧版本信息：|类名：Album;<br>方法or属性：getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：enum DirectoryType<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：enum DirectoryType<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_CAMERA = 0<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_CAMERA = 0<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_VIDEO<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_VIDEO<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_IMAGE<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_IMAGE<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_AUDIO<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_AUDIO<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_DOCUMENTS<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_DOCUMENTS<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DirectoryType;<br>方法or属性：DIR_DOWNLOAD<br>旧版本信息：|类名：DirectoryType;<br>方法or属性：DIR_DOWNLOAD<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：interface MediaLibrary<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：interface MediaLibrary<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getPublicDirectory(type: DirectoryType): Promise\<string>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getPublicDirectory(type: DirectoryType): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：deleteAsset(uri: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：deleteAsset(uri: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：deleteAsset(uri: string): Promise\<void>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：deleteAsset(uri: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：storeMediaAsset(option: MediaAssetOption): Promise\<string>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：storeMediaAsset(option: MediaAssetOption): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, index?: number): Promise\<void>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：startImagePreview(images: Array\<string>, index?: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getActivePeers(): Promise\<Array\<PeerInfo>>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getActivePeers(): Promise\<Array\<PeerInfo>>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：getAllPeers(): Promise\<Array\<PeerInfo>>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：getAllPeers(): Promise\<Array\<PeerInfo>>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：release(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：MediaLibrary;<br>方法or属性：release(): Promise\<void>;<br>旧版本信息：|类名：MediaLibrary;<br>方法or属性：release(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Size;<br>方法or属性：interface Size<br>旧版本信息：|类名：Size;<br>方法or属性：interface Size<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：PeerInfo;<br>方法or属性：interface PeerInfo<br>旧版本信息：|类名：PeerInfo;<br>方法or属性：interface PeerInfo<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：PeerInfo;<br>方法or属性：readonly deviceName: string;<br>旧版本信息：|类名：PeerInfo;<br>方法or属性：readonly deviceName: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：PeerInfo;<br>方法or属性：readonly networkId: string;<br>旧版本信息：|类名：PeerInfo;<br>方法or属性：readonly networkId: string;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：PeerInfo;<br>方法or属性：readonly deviceType: DeviceType;<br>旧版本信息：|类名：PeerInfo;<br>方法or属性：readonly deviceType: DeviceType;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：PeerInfo;<br>方法or属性：readonly isOnline: boolean;<br>旧版本信息：|类名：PeerInfo;<br>方法or属性：readonly isOnline: boolean;<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：enum DeviceType<br>旧版本信息：|类名：DeviceType;<br>方法or属性：enum DeviceType<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_UNKNOWN = 0<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_UNKNOWN = 0<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_LAPTOP<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_LAPTOP<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_PHONE<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_PHONE<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_TABLET<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_TABLET<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_WATCH<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_WATCH<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_CAR<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_CAR<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|废弃版本有变化|类名：DeviceType;<br>方法or属性：TYPE_TV<br>旧版本信息：|类名：DeviceType;<br>方法or属性：TYPE_TV<br>新版本信息：9<br>代替接口： ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|访问级别有变化|类名：VolumeEvent;<br>方法or属性：interface VolumeEvent<br>旧版本信息：systemapi|类名：VolumeEvent;<br>方法or属性：interface VolumeEvent<br>新版本信息：|@ohos.multimedia.audio.d.ts|
|权限有变化|类名：VideoPlayer;<br>方法or属性：prepare(callback: AsyncCallback\<void>): void;<br>旧版本信息：ohos.permission.MICROPHONE|类名：VideoPlayer;<br>方法or属性：prepare(callback: AsyncCallback\<void>): void;<br>新版本信息：|@ohos.multimedia.media.d.ts|
|权限有变化|类名：VideoPlayer;<br>方法or属性：prepare(): Promise\<void>;<br>旧版本信息：ohos.permission.MICROPHONE|类名：VideoPlayer;<br>方法or属性：prepare(): Promise\<void>;<br>新版本信息：|@ohos.multimedia.media.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_NEW|类名：AudioState;<br>方法or属性：STATE_NEW = 0|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_PREPARED|类名：AudioState;<br>方法or属性：STATE_PREPARED = 1|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_RUNNING|类名：AudioState;<br>方法or属性：STATE_RUNNING = 2|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_STOPPED|类名：AudioState;<br>方法or属性：STATE_STOPPED = 3|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_RELEASED|类名：AudioState;<br>方法or属性：STATE_RELEASED = 4|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioState;<br>方法or属性：STATE_PAUSED|类名：AudioState;<br>方法or属性：STATE_PAUSED = 5|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_RINGING|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_RINGING = 1|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_PHONE_CALL|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_PHONE_CALL = 2|@ohos.multimedia.audio.d.ts|
|函数有变化|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_VOICE_CHAT|类名：AudioScene;<br>方法or属性：AUDIO_SCENE_VOICE_CHAT = 3|@ohos.multimedia.audio.d.ts|
