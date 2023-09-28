| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: AudioRenderer;<br>Method or attribute name: on(type: "markReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|Deleted|Class name: AudioCapturer;<br>Method or attribute name: on(type: "markReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|Deleted|Class name: AudioRenderer;<br>Method or attribute name: on(type: "periodReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|Deleted|Class name: AudioCapturer;<br>Method or attribute name: on(type: "periodReach", frame: number, callback: (position: number) => {}): void;|NA|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: CommunicationDeviceType;<br>Method or attribute name: SPEAKER = 2|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMicrophoneMute(callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: isMicrophoneMute(): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: getRingerMode(): Promise\<AudioRingMode>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: getTrackDescription() : Promise\<Array\<MediaDescription>>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'timeUpdate', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: loop: boolean;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: readonly currentTime: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: readonly duration: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: audioSampleRate?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: location?: Location;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: location?: Location;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: prepare(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: prepare(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: play(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: play(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: pause(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: reset(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: reset(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: url: string;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: url: string;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: readonly width: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: readonly height: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'startRenderFrame', callback: Callback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: effectKit;<br>Method or attribute name: function createEffect(source: image.PixelMap): Filter;|@ohos.effectKit.d.ts|
|Added|NA|Class name: effectKit;<br>Method or attribute name: function createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;|@ohos.effectKit.d.ts|
|Added|NA|Class name: effectKit;<br>Method or attribute name: function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: blur(radius:number): Filter;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: brightness(bright:number): Filter;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: grayscale(): Filter;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Filter;<br>Method or attribute name: getPixelMap(): image.PixelMap;|@ohos.effectKit.d.ts|
|Added|NA|Class name: ColorPicker;<br>Method or attribute name: getMainColor(): Promise\<Color>;|@ohos.effectKit.d.ts|
|Added|NA|Class name: ColorPicker;<br>Method or attribute name: getMainColorSync(): Color;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Color;<br>Method or attribute name: red: number;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Color;<br>Method or attribute name: green: number;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Color;<br>Method or attribute name: blue: number;|@ohos.effectKit.d.ts|
|Added|NA|Class name: Color;<br>Method or attribute name: alpha: number;|@ohos.effectKit.d.ts|
|Added|NA|Class name: audio;<br>Method or attribute name: function createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback\<TonePlayer>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: audio;<br>Method or attribute name: function createTonePlayer(options: AudioRendererInfo): Promise\<TonePlayer>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: audio;<br>Method or attribute name: type VolumeGroupInfos = Array\<Readonly\<VolumeGroupInfo>>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: audio;<br>Method or attribute name: type AudioRendererChangeInfoArray = Array\<Readonly\<AudioRendererChangeInfo>>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: audio;<br>Method or attribute name: type AudioCapturerChangeInfoArray = Array\<Readonly\<AudioCapturerChangeInfo>>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_INVALID_PARAM = 6800101|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_NO_MEMORY     = 6800102|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_ILLEGAL_STATE = 6800103|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_UNSUPPORTED   = 6800104|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_TIMEOUT       = 6800105|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_STREAM_LIMIT  = 6800201|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioErrors;<br>Method or attribute name: ERROR_SYSTEM        = 6800301|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeType;<br>Method or attribute name: ALL = 100|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: DeviceFlag;<br>Method or attribute name: NONE_DEVICES_FLAG = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: DeviceFlag;<br>Method or attribute name: DISTRIBUTED_OUTPUT_DEVICES_FLAG = 4|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: DeviceFlag;<br>Method or attribute name: DISTRIBUTED_INPUT_DEVICES_FLAG = 8|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: DeviceFlag;<br>Method or attribute name: ALL_DISTRIBUTED_DEVICES_FLAG = 12|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: DeviceType;<br>Method or attribute name: DEFAULT = 1000|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioSampleFormat;<br>Method or attribute name: SAMPLE_FORMAT_F32LE = 4|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: StreamUsage;<br>Method or attribute name: STREAM_USAGE_VOICE_ASSISTANT = 3|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptRequestType;<br>Method or attribute name: INTERRUPT_REQUEST_TYPE_DEFAULT = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererFilter;<br>Method or attribute name: uid: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererFilter;<br>Method or attribute name: rendererInfo?: AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererFilter;<br>Method or attribute name: rendererId?: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptMode;<br>Method or attribute name: SHARE_MODE = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptMode;<br>Method or attribute name: INDEPENDENT_MODE = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptForceType;<br>Method or attribute name: INTERRUPT_FORCE = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptForceType;<br>Method or attribute name: INTERRUPT_SHARE = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptEvent;<br>Method or attribute name: eventType: InterruptType;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptEvent;<br>Method or attribute name: forceType: InterruptForceType;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptEvent;<br>Method or attribute name: hintType: InterruptHint;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioManager;<br>Method or attribute name: getVolumeManager(): AudioVolumeManager;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioManager;<br>Method or attribute name: getStreamManager(): AudioStreamManager;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioManager;<br>Method or attribute name: getRoutingManager(): AudioRoutingManager;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptRequestResultType;<br>Method or attribute name: INTERRUPT_REQUEST_GRANT = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptRequestResultType;<br>Method or attribute name: INTERRUPT_REQUEST_REJECT = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptResult;<br>Method or attribute name: requestResult: InterruptRequestResultType;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: InterruptResult;<br>Method or attribute name: interruptNode: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback\<DeviceChangeAction>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise\<boolean>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRoutingManager;<br>Method or attribute name: selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioRendererInfoArray(callback: AsyncCallback\<AudioRendererChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioRendererInfoArray(): Promise\<AudioRendererChangeInfoArray>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioCapturerInfoArray(callback: AsyncCallback\<AudioCapturerChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: getCurrentAudioCapturerInfoArray(): Promise\<AudioCapturerChangeInfoArray>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: on(type: "audioRendererChange", callback: Callback\<AudioRendererChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: on(type: "audioCapturerChange", callback: Callback\<AudioCapturerChangeInfoArray>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: off(type: "audioRendererChange"): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioStreamManager;<br>Method or attribute name: off(type: "audioCapturerChange"): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupInfos(networkId: string, callback: AsyncCallback\<VolumeGroupInfos>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupInfos(networkId: string): Promise\<VolumeGroupInfos>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupManager(groupId: number, callback: AsyncCallback\<AudioVolumeGroupManager>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: getVolumeGroupManager(groupId: number): Promise\<AudioVolumeGroupManager>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeManager;<br>Method or attribute name: on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioVolumeGroupManager;<br>Method or attribute name: on(type: 'micStateChange', callback: Callback\<MicStateChangeEvent>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ConnectType;<br>Method or attribute name: CONNECT_TYPE_LOCAL = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ConnectType;<br>Method or attribute name: CONNECT_TYPE_DISTRIBUTED = 2|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeGroupInfo;<br>Method or attribute name: readonly networkId: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly networkId: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeGroupInfo;<br>Method or attribute name: readonly groupId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeGroupInfo;<br>Method or attribute name: readonly mappingId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeGroupInfo;<br>Method or attribute name: readonly groupName: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeGroupInfo;<br>Method or attribute name: readonly type: ConnectType;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererChangeInfo;<br>Method or attribute name: readonly streamId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturerChangeInfo;<br>Method or attribute name: readonly streamId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererChangeInfo;<br>Method or attribute name: readonly clientUid: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturerChangeInfo;<br>Method or attribute name: readonly clientUid: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererChangeInfo;<br>Method or attribute name: readonly rendererInfo: AudioRendererInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererChangeInfo;<br>Method or attribute name: readonly rendererState: AudioState;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRendererChangeInfo;<br>Method or attribute name: readonly deviceDescriptors: AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturerChangeInfo;<br>Method or attribute name: readonly deviceDescriptors: AudioDeviceDescriptors;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturerChangeInfo;<br>Method or attribute name: readonly capturerInfo: AudioCapturerInfo;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturerChangeInfo;<br>Method or attribute name: readonly capturerState: AudioState;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly id: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly name: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly address: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly sampleRates: Array\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly channelCounts: Array\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly channelMasks: Array\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly interruptGroupId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioDeviceDescriptor;<br>Method or attribute name: readonly volumeGroupId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeEvent;<br>Method or attribute name: volumeGroupId: number;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: VolumeEvent;<br>Method or attribute name: networkId: string;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: MicStateChangeEvent;<br>Method or attribute name: mute: boolean;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getAudioStreamId(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getAudioStreamId(callback: AsyncCallback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: getAudioStreamId(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: getAudioStreamId(): Promise\<number>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: setInterruptMode(mode: InterruptMode): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: setVolume(volume: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: setVolume(volume: number): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: on(type: "markReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: on(type: "markReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioRenderer;<br>Method or attribute name: on(type: "periodReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: AudioCapturer;<br>Method or attribute name: on(type: "periodReach", frame: number, callback: Callback\<number>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: SourceType;<br>Method or attribute name: SOURCE_TYPE_VOICE_RECOGNITION = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_0 = 0|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_1 = 1|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_2 = 2|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_3 = 3|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_4 = 4|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_5 = 5|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_6 = 6|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_7 = 7|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_8 = 8|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_9 = 9|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_S = 10|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_P = 11|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_A = 12|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_B = 13|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_C = 14|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_DIAL_D = 15|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_DIAL = 100|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_BUSY = 101|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_CONGESTION = 102|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK = 103|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE = 104|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING = 106|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_SUPERVISORY_RINGTONE = 107|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_PROPRIETARY_BEEP = 200|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_PROPRIETARY_ACK = 201|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_PROPRIETARY_PROMPT = 203|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: ToneType;<br>Method or attribute name: TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP = 204|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: load(type: ToneType, callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: load(type: ToneType): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: TonePlayer;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.audio.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function createController(sessionId: string): Promise\<AVSessionController>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function castAudio(session: SessionToken \| 'all', audioDevices: Array\<audio.AudioDeviceDescriptor>): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function on(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function on(type: 'sessionServiceDie', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function off(type: 'sessionCreate' \| 'sessionDestroy' \| 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function off(type: 'sessionServiceDie', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: function sendSystemControlCommand(command: AVControlCommand): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: type AVSessionType = 'audio' \| 'video';|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: avSession;<br>Method or attribute name: type AVControlCommandType = 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind' \|<br>                              'seek' \| 'setSpeed' \| 'setLoopMode' \| 'toggleFavorite';|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: SessionToken;<br>Method or attribute name: sessionId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: sessionId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: SessionToken;<br>Method or attribute name: pid: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: SessionToken;<br>Method or attribute name: uid: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: readonly sessionId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: readonly sessionId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setAVMetadata(data: AVMetadata): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setAVPlaybackState(state: AVPlaybackState): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: setLaunchAbility(ability: WantAgent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: getController(callback: AsyncCallback\<AVSessionController>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: getController(): Promise\<AVSessionController>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: getOutputDevice(): Promise\<OutputDeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getOutputDevice(): Promise\<OutputDeviceInfo>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback: () => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'seek', callback: (time: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'setSpeed', callback: (speed: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'toggleFavorite', callback: (assetId: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'play' \| 'pause' \| 'stop' \| 'playNext' \| 'playPrevious' \| 'fastForward' \| 'rewind', callback?: () => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'seek', callback?: (time: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'setSpeed', callback?: (speed: number) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'toggleFavorite', callback?: (assetId: string) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: activate(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: activate(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: deactivate(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: deactivate(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: destroy(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: destroy(callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSession;<br>Method or attribute name: destroy(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: destroy(): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: assetId: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: title?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: artist?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: author?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: album?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: writer?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: composer?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: duration?: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: mediaImage?: image.PixelMap \| string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: publishDate?: Date;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: subtitle?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: description?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: lyric?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: previousAssetId?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVMetadata;<br>Method or attribute name: nextAssetId?: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: state?: PlaybackState;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: speed?: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: position?: PlaybackPosition;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: bufferedTime?: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: loopMode?: LoopMode;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVPlaybackState;<br>Method or attribute name: isFavorite?: boolean;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackPosition;<br>Method or attribute name: elapsedTime: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackPosition;<br>Method or attribute name: updateTime: number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: OutputDeviceInfo;<br>Method or attribute name: isRemote: boolean;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: OutputDeviceInfo;<br>Method or attribute name: audioDeviceId: Array\<number>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: OutputDeviceInfo;<br>Method or attribute name: deviceName: Array\<string>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: LoopMode;<br>Method or attribute name: LOOP_MODE_SEQUENCE = 0|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: LoopMode;<br>Method or attribute name: LOOP_MODE_SINGLE = 1|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: LoopMode;<br>Method or attribute name: LOOP_MODE_LIST = 2|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: LoopMode;<br>Method or attribute name: LOOP_MODE_SHUFFLE = 3|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_INITIAL = 0|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_PREPARE = 1|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_PLAY = 2|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_PAUSE = 3|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_FAST_FORWARD = 4|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_REWIND = 5|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: PlaybackState;<br>Method or attribute name: PLAYBACK_STATE_STOP = 6|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: type: AVSessionType;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: sessionTag: string;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: elementName: ElementName;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: isActive: boolean;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: isTopSession: boolean;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionDescriptor;<br>Method or attribute name: outputDevice: OutputDeviceInfo;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVPlaybackState(): Promise\<AVPlaybackState>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVMetadata(callback: AsyncCallback\<AVMetadata>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getAVMetadata(): Promise\<AVMetadata>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: sendAVKeyEvent(event: KeyEvent): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getLaunchAbility(callback: AsyncCallback\<WantAgent>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getLaunchAbility(): Promise\<WantAgent>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getRealPlaybackPositionSync(): number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: isActive(callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: isActive(): Promise\<boolean>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: getValidCommands(): Promise\<Array\<AVControlCommandType>>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: sendControlCommand(command: AVControlCommand): Promise\<void>;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'metadataChange', filter: Array\<keyof AVMetadata> \| 'all', callback: (data: AVMetadata) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> \| 'all', callback: (state: AVPlaybackState) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'sessionDestroy', callback: () => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'activeStateChange', callback: (isActive: boolean) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'metadataChange', callback?: (data: AVMetadata) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'sessionDestroy', callback?: () => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'activeStateChange', callback?: (isActive: boolean) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionController;<br>Method or attribute name: off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void);|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVControlCommand;<br>Method or attribute name: command: AVControlCommandType;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVControlCommand;<br>Method or attribute name: parameter?: LoopMode \| string \| number;|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_SERVICE_EXCEPTION = 6600101|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_SESSION_NOT_EXIST = 6600102|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_CONTROLLER_NOT_EXIST = 6600103|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_REMOTE_CONNECTION_ERR = 6600104|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_COMMAND_INVALID = 6600105|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_SESSION_INACTIVE = 6600106|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: AVSessionErrorCode;<br>Method or attribute name: ERR_CODE_MESSAGE_OVERLOAD = 6600107|@ohos.multimedia.avsession.d.ts|
|Added|NA|Class name: camera;<br>Method or attribute name: function getCameraManager(context: Context): CameraManager;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatus;<br>Method or attribute name: CAMERA_STATUS_APPEAR = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatus;<br>Method or attribute name: CAMERA_STATUS_DISAPPEAR = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatus;<br>Method or attribute name: CAMERA_STATUS_AVAILABLE = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatus;<br>Method or attribute name: CAMERA_STATUS_UNAVAILABLE = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Profile;<br>Method or attribute name: readonly format: CameraFormat;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Profile;<br>Method or attribute name: readonly size: Size;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FrameRateRange;<br>Method or attribute name: readonly min: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FrameRateRange;<br>Method or attribute name: readonly max: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoProfile;<br>Method or attribute name: readonly frameRateRange: FrameRateRange;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutputCapability;<br>Method or attribute name: readonly previewProfiles: Array\<Profile>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutputCapability;<br>Method or attribute name: readonly photoProfiles: Array\<Profile>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutputCapability;<br>Method or attribute name: readonly videoProfiles: Array\<VideoProfile>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutputCapability;<br>Method or attribute name: readonly supportedMetadataObjectTypes: Array\<MetadataObjectType>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: INVALID_ARGUMENT = 7400101|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: OPERATION_NOT_ALLOWED = 7400102|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: SESSION_NOT_CONFIG = 7400103|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: SESSION_NOT_RUNNING = 7400104|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: SESSION_CONFIG_LOCKED = 7400105|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: DEVICE_SETTING_LOCKED = 7400106|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: CONFILICT_CAMERA = 7400107|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: DEVICE_DISABLED = 7400108|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraErrorCode;<br>Method or attribute name: SERVICE_FATAL_ERROR = 7400201|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: getSupportedCameras(): Array\<CameraDevice>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: isCameraMuted(): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: isCameraMuteSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: muteCamera(mute: boolean): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createCameraInput(camera: CameraDevice): CameraInput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createCameraInput(position: CameraPosition, type: CameraType): CameraInput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType>): MetadataOutput;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: createCaptureSession(): CaptureSession;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraManager;<br>Method or attribute name: on(type: 'cameraMute', callback: AsyncCallback\<boolean>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatusInfo;<br>Method or attribute name: camera: CameraDevice;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraStatusInfo;<br>Method or attribute name: status: CameraStatus;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraPosition;<br>Method or attribute name: CAMERA_POSITION_UNSPECIFIED = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraPosition;<br>Method or attribute name: CAMERA_POSITION_BACK = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraPosition;<br>Method or attribute name: CAMERA_POSITION_FRONT = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraType;<br>Method or attribute name: CAMERA_TYPE_DEFAULT = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraType;<br>Method or attribute name: CAMERA_TYPE_WIDE_ANGLE = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraType;<br>Method or attribute name: CAMERA_TYPE_ULTRA_WIDE = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraType;<br>Method or attribute name: CAMERA_TYPE_TELEPHOTO = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraType;<br>Method or attribute name: CAMERA_TYPE_TRUE_DEPTH = 4|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ConnectionType;<br>Method or attribute name: CAMERA_CONNECTION_BUILT_IN = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ConnectionType;<br>Method or attribute name: CAMERA_CONNECTION_USB_PLUGIN = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ConnectionType;<br>Method or attribute name: CAMERA_CONNECTION_REMOTE = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraDevice;<br>Method or attribute name: readonly cameraId: string;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraDevice;<br>Method or attribute name: readonly cameraPosition: CameraPosition;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraDevice;<br>Method or attribute name: readonly cameraType: CameraType;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraDevice;<br>Method or attribute name: readonly connectionType: ConnectionType;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Size;<br>Method or attribute name: height: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: height: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Size;<br>Method or attribute name: width: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: width: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: x: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: y: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: open(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: open(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: close(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraInput;<br>Method or attribute name: on(type: 'error', camera: CameraDevice, callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraFormat;<br>Method or attribute name: CAMERA_FORMAT_RGBA_8888 = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraFormat;<br>Method or attribute name: CAMERA_FORMAT_YUV_420_SP = 1003|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraFormat;<br>Method or attribute name: CAMERA_FORMAT_JPEG = 2000|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FlashMode;<br>Method or attribute name: FLASH_MODE_CLOSE = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FlashMode;<br>Method or attribute name: FLASH_MODE_OPEN = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FlashMode;<br>Method or attribute name: FLASH_MODE_AUTO = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FlashMode;<br>Method or attribute name: FLASH_MODE_ALWAYS_OPEN = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ExposureMode;<br>Method or attribute name: EXPOSURE_MODE_LOCKED = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ExposureMode;<br>Method or attribute name: EXPOSURE_MODE_AUTO = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ExposureMode;<br>Method or attribute name: EXPOSURE_MODE_CONTINUOUS_AUTO = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusMode;<br>Method or attribute name: FOCUS_MODE_MANUAL = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusMode;<br>Method or attribute name: FOCUS_MODE_CONTINUOUS_AUTO = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusMode;<br>Method or attribute name: FOCUS_MODE_AUTO = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusMode;<br>Method or attribute name: FOCUS_MODE_LOCKED = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusState;<br>Method or attribute name: FOCUS_STATE_SCAN = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusState;<br>Method or attribute name: FOCUS_STATE_FOCUSED = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FocusState;<br>Method or attribute name: FOCUS_STATE_UNFOCUSED = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoStabilizationMode;<br>Method or attribute name: OFF = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoStabilizationMode;<br>Method or attribute name: LOW = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoStabilizationMode;<br>Method or attribute name: MIDDLE = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoStabilizationMode;<br>Method or attribute name: HIGH = 3|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoStabilizationMode;<br>Method or attribute name: AUTO = 4|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: beginConfig(): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: commitConfig(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: commitConfig(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: addInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: removeInput(cameraInput: CameraInput): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: addOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: removeOutput(cameraOutput: CameraOutput): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutput;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CameraOutput;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: hasFlash(): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: isFlashModeSupported(flashMode: FlashMode): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getFlashMode(): FlashMode;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setFlashMode(flashMode: FlashMode): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: isExposureModeSupported(aeMode: ExposureMode): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getExposureMode(): ExposureMode;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setExposureMode(aeMode: ExposureMode): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getMeteringPoint(): Point;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setMeteringPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getExposureBiasRange(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setExposureBias(exposureBias: number): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getExposureValue(): number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: isFocusModeSupported(afMode: FocusMode): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getFocusMode(): FocusMode;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setFocusMode(afMode: FocusMode): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setFocusPoint(point: Point): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getFocusPoint(): Point;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getFocalLength(): number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getZoomRatioRange(): Array\<number>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getZoomRatio(): number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setZoomRatio(zoomRatio: number): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: getActiveVideoStabilizationMode(): VideoStabilizationMode;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: setVideoStabilizationMode(mode: VideoStabilizationMode): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: on(type: 'focusStateChange', callback: AsyncCallback\<FocusState>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureSession;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback\<BusinessError>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: on(type: 'frameStart', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: on(type: 'frameStart', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PreviewOutput;<br>Method or attribute name: on(type: 'frameEnd', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: VideoOutput;<br>Method or attribute name: on(type: 'frameEnd', callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ImageRotation;<br>Method or attribute name: ROTATION_0 = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ImageRotation;<br>Method or attribute name: ROTATION_90 = 90|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ImageRotation;<br>Method or attribute name: ROTATION_180 = 180|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: ImageRotation;<br>Method or attribute name: ROTATION_270 = 270|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Location;<br>Method or attribute name: latitude: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Location;<br>Method or attribute name: longitude: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Location;<br>Method or attribute name: altitude: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: QualityLevel;<br>Method or attribute name: QUALITY_LEVEL_HIGH = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: QualityLevel;<br>Method or attribute name: QUALITY_LEVEL_MEDIUM = 1|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: QualityLevel;<br>Method or attribute name: QUALITY_LEVEL_LOW = 2|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoCaptureSetting;<br>Method or attribute name: quality?: QualityLevel;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoCaptureSetting;<br>Method or attribute name: rotation?: ImageRotation;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoCaptureSetting;<br>Method or attribute name: location?: Location;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoCaptureSetting;<br>Method or attribute name: mirror?: boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: capture(callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: capture(): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: capture(setting?: PhotoCaptureSetting): Promise\<void>;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: isMirrorSupported(): boolean;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: on(type: 'captureStart', callback: AsyncCallback\<number>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: PhotoOutput;<br>Method or attribute name: on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FrameShutterInfo;<br>Method or attribute name: captureId: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureEndInfo;<br>Method or attribute name: captureId: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: FrameShutterInfo;<br>Method or attribute name: timestamp: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: CaptureEndInfo;<br>Method or attribute name: frameCount: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataObjectType;<br>Method or attribute name: FACE_DETECTION = 0|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: topLeftX: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: topLeftY: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataObject;<br>Method or attribute name: readonly type: MetadataObjectType;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataObject;<br>Method or attribute name: readonly timestamp: number;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataObject;<br>Method or attribute name: readonly boundingBox: Rect;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: MetadataOutput;<br>Method or attribute name: on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject>>): void;|@ohos.multimedia.camera.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageSource(uri: string, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageSource(fd: number, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageSource(buf: ArrayBuffer): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function CreateIncrementalSource(buf: ArrayBuffer): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: image;<br>Method or attribute name: function createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: BGRA_8888 = 4|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: RGB_888 = 5|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: ALPHA_8 = 6|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: RGBA_F16 = 7|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: NV21 = 8|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMapFormat;<br>Method or attribute name: NV12 = 9|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PropertyKey;<br>Method or attribute name: DATE_TIME_ORIGINAL = "DateTimeOriginal"|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PropertyKey;<br>Method or attribute name: EXPOSURE_TIME = "ExposureTime"|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PropertyKey;<br>Method or attribute name: SCENE_TYPE = "SceneType"|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PropertyKey;<br>Method or attribute name: ISO_SPEED_RATINGS = "ISOSpeedRatings"|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PropertyKey;<br>Method or attribute name: F_NUMBER = "FNumber"|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageFormat;<br>Method or attribute name: YCBCR_422_SP = 1000|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageFormat;<br>Method or attribute name: JPEG = 2000|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: AlphaType;<br>Method or attribute name: UNKNOWN = 0|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: AlphaType;<br>Method or attribute name: OPAQUE = 1|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: AlphaType;<br>Method or attribute name: PREMUL = 2|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: AlphaType;<br>Method or attribute name: UNPREMUL = 3|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ScaleMode;<br>Method or attribute name: FIT_TARGET_SIZE = 0|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ScaleMode;<br>Method or attribute name: CENTER_CROP = 1|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ComponentType;<br>Method or attribute name: YUV_Y = 1|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ComponentType;<br>Method or attribute name: YUV_U = 2|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ComponentType;<br>Method or attribute name: YUV_V = 3|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ComponentType;<br>Method or attribute name: JPEG = 4|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageInfo;<br>Method or attribute name: density: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PackingOption;<br>Method or attribute name: bufferSize?: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: DecodingOptions;<br>Method or attribute name: fitDensity?: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: readonly componentType: ComponentType;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: readonly rowStride: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: readonly pixelStride: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: readonly byteBuffer: ArrayBuffer;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: InitializationOptions;<br>Method or attribute name: alphaType?: AlphaType;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: InitializationOptions;<br>Method or attribute name: scaleMode?: ScaleMode;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: SourceOptions;<br>Method or attribute name: sourceDensity: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: SourceOptions;<br>Method or attribute name: sourcePixelFormat?: PixelMapFormat;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: SourceOptions;<br>Method or attribute name: sourceSize?: Size;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: getDensity():number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: opacity(rate: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: opacity(rate: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: createAlphaPixelmap(): Promise\<PixelMap>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: scale(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: scale(x: number, y: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: translate(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: translate(x: number, y: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: rotate(angle: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: rotate(angle: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: flip(horizontal: boolean, vertical: boolean): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: crop(region: Region, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: PixelMap;<br>Method or attribute name: crop(region: Region): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: modifyImageProperty(key: string, value: string): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageSource;<br>Method or attribute name: updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: clipRect: Region;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: readonly size: Size;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readonly size: Size;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: readonly format: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: getComponent(componentType: ComponentType): Promise\<Component>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: Image;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: release(): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readonly capacity: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: readonly capacity: number;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readonly format: ImageFormat;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: readonly format: ImageFormat;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: getReceivingSurfaceId(callback: AsyncCallback\<string>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: getReceivingSurfaceId(): Promise\<string>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readLatestImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readLatestImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readNextImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: readNextImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageReceiver;<br>Method or attribute name: on(type: 'imageArrival', callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: dequeueImage(callback: AsyncCallback\<Image>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: dequeueImage(): Promise\<Image>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: queueImage(interface: Image, callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: queueImage(interface: Image): Promise\<void>;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: ImageCreator;<br>Method or attribute name: on(type: 'imageRelease', callback: AsyncCallback\<void>): void;|@ohos.multimedia.image.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createAVPlayer(callback: AsyncCallback\<AVPlayer>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createAVPlayer() : Promise\<AVPlayer>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createAVRecorder(callback: AsyncCallback\<AVRecorder>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createAVRecorder() : Promise\<AVRecorder>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: function createVideoRecorder(): Promise\<VideoRecorder>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: type AVPlayerState = 'idle' \| 'initialized' \| 'prepared' \| 'playing' \| 'paused' \| 'completed' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: type AVRecorderState = 'idle' \| 'prepared' \| 'started' \| 'paused' \| 'stopped' \| 'released' \| 'error';|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: media;<br>Method or attribute name: type VideoRecordState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: StateChangeReason;<br>Method or attribute name: USER = 1|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: StateChangeReason;<br>Method or attribute name: BACKGROUND = 2|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_OK = 0|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_NO_PERMISSION = 201|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_INVALID_PARAMETER = 401|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_UNSUPPORT_CAPABILITY = 801|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_NO_MEMORY = 5400101|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_OPERATE_NOT_PERMIT = 5400102|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_IO = 5400103|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_TIMEOUT = 5400104|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_SERVICE_DIED = 5400105|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVErrorCode;<br>Method or attribute name: AVERR_UNSUPPORT_FORMAT = 5400106|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: seek(timeMs: number, mode?:SeekMode): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: setVolume(volume: number): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: url ?: string;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: fdSrc ?: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AudioPlayer;<br>Method or attribute name: audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoPlayer;<br>Method or attribute name: audioInterruptMode ?: audio.InterruptMode;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: readonly state: AVPlayerState;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: surfaceId ?: string;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoPlayer;<br>Method or attribute name: videoScaleType ?: VideoScaleType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: setSpeed(speed: PlaybackSpeed): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: setBitrate(bitrate: number): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'volumeChange', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'endOfStream', callback: Callback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'seekDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'speedDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'bitrateDone', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'durationUpdate', callback: Callback\<number>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AudioPlayer;<br>Method or attribute name: on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: off(type: 'stateChange'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'volumeChange'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'endOfStream'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'seekDone'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'speedDone'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'bitrateDone'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'timeUpdate'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'durationUpdate'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'bufferingUpdate'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'startRenderFrame'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'videoSizeChange'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'audioInterrupt'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'availableBitrates'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVPlayer;<br>Method or attribute name: off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: off(type: 'error'): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVFileDescriptor;<br>Method or attribute name: fd: number|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVFileDescriptor;<br>Method or attribute name: offset?: number|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVFileDescriptor;<br>Method or attribute name: length?: number|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AudioPlayer;<br>Method or attribute name: fdSrc: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoPlayer;<br>Method or attribute name: fdSrc: AVFileDescriptor;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: prepare(config: AVRecorderConfig): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: getInputSurface(callback: AsyncCallback\<string>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: getInputSurface(callback: AsyncCallback\<string>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: getInputSurface(): Promise\<string>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: getInputSurface(): Promise\<string>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: start(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: start(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: resume(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: resume(callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: resume(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: resume(): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: readonly state: AVRecorderState;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorder;<br>Method or attribute name: on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: prepare(config: VideoRecorderConfig): Promise\<void>;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorder;<br>Method or attribute name: readonly state: VideoRecordState;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoScaleType;<br>Method or attribute name: VIDEO_SCALE_TYPE_FIT = 0|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoScaleType;<br>Method or attribute name: VIDEO_SCALE_TYPE_FIT_CROP = 1|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly audioBitrate: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly audioChannels: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly audioCodec: CodecMimeType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly audioSampleRate: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly videoBitrate: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly videoCodec: CodecMimeType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly videoFrameWidth: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly videoFrameHeight: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderProfile;<br>Method or attribute name: readonly videoFrameRate: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AudioSourceType;<br>Method or attribute name: AUDIO_SOURCE_TYPE_DEFAULT = 0|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AudioSourceType;<br>Method or attribute name: AUDIO_SOURCE_TYPE_MIC = 1|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoSourceType;<br>Method or attribute name: VIDEO_SOURCE_TYPE_SURFACE_YUV = 0|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoSourceType;<br>Method or attribute name: VIDEO_SOURCE_TYPE_SURFACE_ES = 1|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: audioSourceType?: AudioSourceType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: videoSourceType: VideoSourceType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: profile: VideoRecorderProfile;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: VideoRecorderConfig;<br>Method or attribute name: rotation?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: rotation?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: audioBitrate?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: audioChannels?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: audioCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: fileFormat: ContainerFormatType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: videoBitrate?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: videoCodec?: CodecMimeType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: videoFrameWidth?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: videoFrameHeight?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderProfile;<br>Method or attribute name: videoFrameRate?: number;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: videoSourceType?: VideoSourceType;|@ohos.multimedia.media.d.ts|
|Added|NA|Class name: AVRecorderConfig;<br>Method or attribute name: profile: AVRecorderProfile;|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: ActiveDeviceType;<br>Method or attribute name: enum ActiveDeviceType<br>Old version: |Class name: ActiveDeviceType;<br>Method or attribute name: enum ActiveDeviceType<br>New version: 9<br>Substitute API: ohos.multimedia.audio.CommunicationDeviceType|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ActiveDeviceType;<br>Method or attribute name: SPEAKER = 2<br>Old version: |Class name: ActiveDeviceType;<br>Method or attribute name: SPEAKER = 2<br>New version: 9<br>Substitute API: ohos.multimedia.audio.CommunicationDeviceType.SPEAKER|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: ActiveDeviceType;<br>Method or attribute name: BLUETOOTH_SCO = 7<br>Old version: |Class name: ActiveDeviceType;<br>Method or attribute name: BLUETOOTH_SCO = 7<br>New version: 9<br>Substitute API: ohos.multimedia.audio.CommunicationDeviceType|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptActionType;<br>Method or attribute name: enum InterruptActionType<br>Old version: |Class name: InterruptActionType;<br>Method or attribute name: enum InterruptActionType<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptActionType;<br>Method or attribute name: TYPE_ACTIVATED = 0<br>Old version: |Class name: InterruptActionType;<br>Method or attribute name: TYPE_ACTIVATED = 0<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptActionType;<br>Method or attribute name: TYPE_INTERRUPT = 1<br>Old version: |Class name: InterruptActionType;<br>Method or attribute name: TYPE_INTERRUPT = 1<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setVolume(volumeType: AudioVolumeType, volume: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType): Promise\<number>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getVolume(volumeType: AudioVolumeType): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType): Promise\<number>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getMinVolume(volumeType: AudioVolumeType): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getMinVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getMaxVolume(volumeType: AudioVolumeType): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getMaxVolume|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#getDevices|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#getDevices|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#mute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#mute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#isMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType): Promise\<boolean>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isMute(volumeType: AudioVolumeType): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#isMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioStreamManager#isActive|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType): Promise\<boolean>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isActive(volumeType: AudioVolumeType): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioStreamManager#isActive|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean): Promise\<void>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setMicrophoneMute(mute: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setMicrophoneMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isMicrophoneMute(): Promise\<boolean>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isMicrophoneMute(): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#isMicrophoneMute|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode): Promise\<void>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setRingerMode(mode: AudioRingMode): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#setRingerMode|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: getRingerMode(): Promise\<AudioRingMode>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: getRingerMode(): Promise\<AudioRingMode>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#getRingerMode|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#setCommunicationDevice|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#isCommunicationDeviceActive|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioVolumeGroupManager#event:ringerModeChange|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#event:deviceChange|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioManager;<br>Method or attribute name: off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;<br>Old version: |Class name: AudioManager;<br>Method or attribute name: off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.AudioRoutingManager#event:deviceChange|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptAction;<br>Method or attribute name: interface InterruptAction<br>Old version: |Class name: InterruptAction;<br>Method or attribute name: interface InterruptAction<br>New version: 9<br>Substitute API: ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptAction;<br>Method or attribute name: actionType: InterruptActionType;<br>Old version: |Class name: InterruptAction;<br>Method or attribute name: actionType: InterruptActionType;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptAction;<br>Method or attribute name: type?: InterruptType;<br>Old version: |Class name: InterruptAction;<br>Method or attribute name: type?: InterruptType;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptAction;<br>Method or attribute name: hint?: InterruptHint;<br>Old version: |Class name: InterruptAction;<br>Method or attribute name: hint?: InterruptHint;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: InterruptAction;<br>Method or attribute name: activated?: boolean;<br>Old version: |Class name: InterruptAction;<br>Method or attribute name: activated?: boolean;<br>New version: 9<br>Substitute API: ohos.multimedia.audio.InterruptEvent|@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioInterrupt;<br>Method or attribute name: interface AudioInterrupt<br>Old version: |Class name: AudioInterrupt;<br>Method or attribute name: interface AudioInterrupt<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioInterrupt;<br>Method or attribute name: streamUsage: StreamUsage;<br>Old version: |Class name: AudioInterrupt;<br>Method or attribute name: streamUsage: StreamUsage;<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioInterrupt;<br>Method or attribute name: contentType: ContentType;<br>Old version: |Class name: AudioInterrupt;<br>Method or attribute name: contentType: ContentType;<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: AudioInterrupt;<br>Method or attribute name: pauseWhenDucked: boolean;<br>Old version: |Class name: AudioInterrupt;<br>Method or attribute name: pauseWhenDucked: boolean;<br>New version: 9<br>Substitute API: |@ohos.multimedia.audio.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: function createAudioPlayer(): AudioPlayer;<br>Old version: |Class name: media;<br>Method or attribute name: function createAudioPlayer(): AudioPlayer;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: function createAudioRecorder(): AudioRecorder;<br>Old version: |Class name: media;<br>Method or attribute name: function createAudioRecorder(): AudioRecorder;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media#createAVRecorder|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: function createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>Old version: |Class name: media;<br>Method or attribute name: function createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: function createVideoPlayer() : Promise\<VideoPlayer>;<br>Old version: |Class name: media;<br>Method or attribute name: function createVideoPlayer() : Promise\<VideoPlayer>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media#createAVPlayer|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>Old version: |Class name: media;<br>Method or attribute name: type AudioState = 'idle' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayerState|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: media;<br>Method or attribute name: type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>Old version: |Class name: media;<br>Method or attribute name: type VideoPlayState = 'idle' \| 'prepared' \| 'playing' \| 'paused' \| 'stopped' \| 'error';<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayerState|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: interface AudioPlayer<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: interface AudioPlayer<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: play(): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: play(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: pause(): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: pause(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: pause(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: pause(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#pause|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: stop(): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: stop(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: stop(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: stop(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#stop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: reset(): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: reset(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: reset(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: reset(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#reset|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: seek(timeMs: number): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: seek(timeMs: number): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: setVolume(vol: number): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: setVolume(vol: number): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: release(): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: release(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: release(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: release(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#release|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: getTrackDescription() : Promise\<Array\<MediaDescription>>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#getTrackDescription|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:bufferingUpdate|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:stateChange|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: on(type: 'timeUpdate', callback: Callback\<number>): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: on(type: 'timeUpdate', callback: Callback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:timeUpdate|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:error|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#on|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:error|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: src: string;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: src: string;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#url|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: loop: boolean;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: loop: boolean;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#loop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: loop: boolean;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: loop: boolean;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#loop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: readonly currentTime: number;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: readonly currentTime: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#currentTime|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: readonly currentTime: number;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: readonly currentTime: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#currentTime|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: readonly duration: number;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: readonly duration: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#duration|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: readonly duration: number;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: readonly duration: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#duration|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioPlayer;<br>Method or attribute name: readonly state: AudioState;<br>Old version: |Class name: AudioPlayer;<br>Method or attribute name: readonly state: AudioState;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#state|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: interface AudioRecorderConfig<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: interface AudioRecorderConfig<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: audioEncodeBitRate?: number;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: audioEncodeBitRate?: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: audioSampleRate?: number;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: audioSampleRate?: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: numberOfChannels?: number;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: numberOfChannels?: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: uri: string;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: uri: string;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: location?: Location;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: location?: Location;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: audioEncoderMime?: CodecMimeType;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: audioEncoderMime?: CodecMimeType;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorderConfig;<br>Method or attribute name: fileFormat?: ContainerFormatType;<br>Old version: |Class name: AudioRecorderConfig;<br>Method or attribute name: fileFormat?: ContainerFormatType;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorderConfig|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: interface AudioRecorder<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: interface AudioRecorder<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: prepare(config: AudioRecorderConfig): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: prepare(config: AudioRecorderConfig): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#prepare|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: start(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: start(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#start|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: resume(): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: resume(): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#resume|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: AudioRecorder;<br>Method or attribute name: on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>Old version: |Class name: AudioRecorder;<br>Method or attribute name: on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVRecorder#on|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: interface VideoPlayer<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: interface VideoPlayer<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#surfaceId|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setDisplaySurface(surfaceId: string): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setDisplaySurface(surfaceId: string): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#surfaceId|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: prepare(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: prepare(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#prepare|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: prepare(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: prepare(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#prepare|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: play(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: play(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: play(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: play(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#play|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: pause(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: pause(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: pause(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#pause|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: stop(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: stop(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#stop|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: reset(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: reset(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: reset(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: reset(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#reset|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, mode?:SeekMode): Promise\<number>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: seek(timeMs: number, mode?:SeekMode): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#seek|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setVolume(vol: number): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setVolume(vol: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#setVolume|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: release(): Promise\<void>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: release(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#release|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: url: string;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: url: string;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#url|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: readonly state: VideoPlayState;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: readonly state: VideoPlayState;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#state|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: readonly width: number;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: readonly width: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#width|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: readonly height: number;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: readonly height: number;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#height|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#setSpeed|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: setSpeed(speed:number): Promise\<number>;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: setSpeed(speed:number): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#setSpeed|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'playbackCompleted', callback: Callback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: on(type: 'playbackCompleted', callback: Callback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:stateChange|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'startRenderFrame', callback: Callback\<void>): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: on(type: 'startRenderFrame', callback: Callback\<void>): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:startRenderFrame|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: VideoPlayer;<br>Method or attribute name: on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>Old version: |Class name: VideoPlayer;<br>Method or attribute name: on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void;<br>New version: 9<br>Substitute API: ohos.multimedia.media/media.AVPlayer#event:videoSizeChange|@ohos.multimedia.media.d.ts|
|Deprecated version changed|Class name: mediaLibrary;<br>Method or attribute name: declare mediaLibrary<br>Old version: |Class name: mediaLibrary;<br>Method or attribute name: declare mediaLibrary<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: mediaLibrary;<br>Method or attribute name: function getMediaLibrary(): MediaLibrary;<br>Old version: |Class name: mediaLibrary;<br>Method or attribute name: function getMediaLibrary(): MediaLibrary;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: mediaLibrary;<br>Method or attribute name: function getMediaLibrary(context: Context): MediaLibrary;<br>Old version: |Class name: mediaLibrary;<br>Method or attribute name: function getMediaLibrary(context: Context): MediaLibrary;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaType;<br>Method or attribute name: enum MediaType<br>Old version: |Class name: MediaType;<br>Method or attribute name: enum MediaType<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaType;<br>Method or attribute name: FILE = 0<br>Old version: |Class name: MediaType;<br>Method or attribute name: FILE = 0<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaType;<br>Method or attribute name: IMAGE<br>Old version: |Class name: MediaType;<br>Method or attribute name: IMAGE<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaType;<br>Method or attribute name: VIDEO<br>Old version: |Class name: MediaType;<br>Method or attribute name: VIDEO<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaType;<br>Method or attribute name: AUDIO<br>Old version: |Class name: MediaType;<br>Method or attribute name: AUDIO<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaAssetOption;<br>Method or attribute name: interface MediaAssetOption<br>Old version: |Class name: MediaAssetOption;<br>Method or attribute name: interface MediaAssetOption<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaAssetOption;<br>Method or attribute name: src: string;<br>Old version: |Class name: MediaAssetOption;<br>Method or attribute name: src: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaAssetOption;<br>Method or attribute name: mimeType: string;<br>Old version: |Class name: MediaAssetOption;<br>Method or attribute name: mimeType: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaAssetOption;<br>Method or attribute name: relativePath?: string;<br>Old version: |Class name: MediaAssetOption;<br>Method or attribute name: relativePath?: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaSelectOption;<br>Method or attribute name: interface MediaSelectOption<br>Old version: |Class name: MediaSelectOption;<br>Method or attribute name: interface MediaSelectOption<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaSelectOption;<br>Method or attribute name: type: 'image' \| 'video' \| 'media';<br>Old version: |Class name: MediaSelectOption;<br>Method or attribute name: type: 'image' \| 'video' \| 'media';<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaSelectOption;<br>Method or attribute name: count: number;<br>Old version: |Class name: MediaSelectOption;<br>Method or attribute name: count: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: interface FileAsset<br>Old version: |Class name: FileAsset;<br>Method or attribute name: interface FileAsset<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly id: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly id: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly uri: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly uri: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly mimeType: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly mimeType: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly mediaType: MediaType;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly mediaType: MediaType;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: displayName: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: displayName: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: title: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: title: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: relativePath: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: relativePath: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly parent: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly parent: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly size: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly size: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly dateAdded: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly dateAdded: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly dateModified: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly dateModified: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly dateModified: number;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly dateModified: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly dateTaken: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly dateTaken: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly artist: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly artist: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly audioAlbum: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly audioAlbum: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly width: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly width: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly height: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly height: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: orientation: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: orientation: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly duration: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly duration: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly albumId: number;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly albumId: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly albumId: number;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly albumId: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly albumUri: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly albumUri: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly albumUri: string;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly albumUri: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: readonly albumName: string;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: readonly albumName: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isDirectory(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isDirectory(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isDirectory():Promise\<boolean>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isDirectory():Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: commitModify(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: commitModify(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: commitModify(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Album;<br>Method or attribute name: commitModify(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: commitModify(): Promise\<void>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: commitModify(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: commitModify(): Promise\<void>;<br>Old version: |Class name: Album;<br>Method or attribute name: commitModify(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: open(mode: string, callback: AsyncCallback\<number>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: open(mode: string, callback: AsyncCallback\<number>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: open(mode: string): Promise\<number>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: open(mode: string): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: close(fd: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: close(fd: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: close(fd: number): Promise\<void>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: close(fd: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: getThumbnail(size?: Size): Promise\<image.PixelMap>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: getThumbnail(size?: Size): Promise\<image.PixelMap>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: favorite(isFavorite: boolean): Promise\<void>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: favorite(isFavorite: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isFavorite(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isFavorite(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isFavorite():Promise\<boolean>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isFavorite():Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: trash(isTrash: boolean): Promise\<void>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: trash(isTrash: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isTrash(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isTrash(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileAsset;<br>Method or attribute name: isTrash():Promise\<boolean>;<br>Old version: |Class name: FileAsset;<br>Method or attribute name: isTrash():Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: enum FileKey<br>Old version: |Class name: FileKey;<br>Method or attribute name: enum FileKey<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: ID = "file_id"<br>Old version: |Class name: FileKey;<br>Method or attribute name: ID = "file_id"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: RELATIVE_PATH = "relative_path"<br>Old version: |Class name: FileKey;<br>Method or attribute name: RELATIVE_PATH = "relative_path"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: DISPLAY_NAME = "display_name"<br>Old version: |Class name: FileKey;<br>Method or attribute name: DISPLAY_NAME = "display_name"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: PARENT = "parent"<br>Old version: |Class name: FileKey;<br>Method or attribute name: PARENT = "parent"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: MIME_TYPE = "mime_type"<br>Old version: |Class name: FileKey;<br>Method or attribute name: MIME_TYPE = "mime_type"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: MEDIA_TYPE = "media_type"<br>Old version: |Class name: FileKey;<br>Method or attribute name: MEDIA_TYPE = "media_type"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: SIZE = "size"<br>Old version: |Class name: FileKey;<br>Method or attribute name: SIZE = "size"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: DATE_ADDED = "date_added"<br>Old version: |Class name: FileKey;<br>Method or attribute name: DATE_ADDED = "date_added"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: DATE_MODIFIED = "date_modified"<br>Old version: |Class name: FileKey;<br>Method or attribute name: DATE_MODIFIED = "date_modified"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: DATE_TAKEN = "date_taken"<br>Old version: |Class name: FileKey;<br>Method or attribute name: DATE_TAKEN = "date_taken"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: TITLE = "title"<br>Old version: |Class name: FileKey;<br>Method or attribute name: TITLE = "title"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: ARTIST = "artist"<br>Old version: |Class name: FileKey;<br>Method or attribute name: ARTIST = "artist"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: AUDIOALBUM = "audio_album"<br>Old version: |Class name: FileKey;<br>Method or attribute name: AUDIOALBUM = "audio_album"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: DURATION = "duration"<br>Old version: |Class name: FileKey;<br>Method or attribute name: DURATION = "duration"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: WIDTH = "width"<br>Old version: |Class name: FileKey;<br>Method or attribute name: WIDTH = "width"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: HEIGHT = "height"<br>Old version: |Class name: FileKey;<br>Method or attribute name: HEIGHT = "height"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: ORIENTATION = "orientation"<br>Old version: |Class name: FileKey;<br>Method or attribute name: ORIENTATION = "orientation"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: ALBUM_ID = "bucket_id"<br>Old version: |Class name: FileKey;<br>Method or attribute name: ALBUM_ID = "bucket_id"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FileKey;<br>Method or attribute name: ALBUM_NAME = "bucket_display_name"<br>Old version: |Class name: FileKey;<br>Method or attribute name: ALBUM_NAME = "bucket_display_name"<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: interface MediaFetchOptions<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: interface MediaFetchOptions<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: selections: string;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: selections: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: selectionArgs: Array\<string>;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: selectionArgs: Array\<string>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: order?: string;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: order?: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: uri?: string;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: uri?: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: networkId?: string;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: networkId?: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaFetchOptions;<br>Method or attribute name: extendArgs?: string;<br>Old version: |Class name: MediaFetchOptions;<br>Method or attribute name: extendArgs?: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: interface FetchFileResult<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: interface FetchFileResult<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getCount(): number;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getCount(): number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: isAfterLast(): boolean;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: isAfterLast(): boolean;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: close(): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: close(): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getFirstObject(): Promise\<FileAsset>;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getFirstObject(): Promise\<FileAsset>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getNextObject(): Promise\<FileAsset>;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getNextObject(): Promise\<FileAsset>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getLastObject(): Promise\<FileAsset>;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getLastObject(): Promise\<FileAsset>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getPositionObject(index: number): Promise\<FileAsset>;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getPositionObject(index: number): Promise\<FileAsset>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: FetchFileResult;<br>Method or attribute name: getAllObject(): Promise\<Array\<FileAsset>>;<br>Old version: |Class name: FetchFileResult;<br>Method or attribute name: getAllObject(): Promise\<Array\<FileAsset>>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: interface Album<br>Old version: |Class name: Album;<br>Method or attribute name: interface Album<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: albumName: string;<br>Old version: |Class name: Album;<br>Method or attribute name: albumName: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly count: number;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly count: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly relativePath: string;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly relativePath: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: readonly coverUri: string;<br>Old version: |Class name: Album;<br>Method or attribute name: readonly coverUri: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>Old version: |Class name: Album;<br>Method or attribute name: getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>Old version: |Class name: Album;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Album;<br>Method or attribute name: getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>;<br>Old version: |Class name: Album;<br>Method or attribute name: getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: enum DirectoryType<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: enum DirectoryType<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_CAMERA = 0<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_CAMERA = 0<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_VIDEO<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_VIDEO<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_IMAGE<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_IMAGE<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_AUDIO<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_AUDIO<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_DOCUMENTS<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_DOCUMENTS<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DirectoryType;<br>Method or attribute name: DIR_DOWNLOAD<br>Old version: |Class name: DirectoryType;<br>Method or attribute name: DIR_DOWNLOAD<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: interface MediaLibrary<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: interface MediaLibrary<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getPublicDirectory(type: DirectoryType): Promise\<string>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getPublicDirectory(type: DirectoryType): Promise\<string>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: deleteAsset(uri: string, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: deleteAsset(uri: string, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: deleteAsset(uri: string): Promise\<void>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: deleteAsset(uri: string): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: storeMediaAsset(option: MediaAssetOption): Promise\<string>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: storeMediaAsset(option: MediaAssetOption): Promise\<string>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, index?: number): Promise\<void>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: startImagePreview(images: Array\<string>, index?: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getActivePeers(): Promise\<Array\<PeerInfo>>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getActivePeers(): Promise\<Array\<PeerInfo>>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: getAllPeers(): Promise\<Array\<PeerInfo>>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: getAllPeers(): Promise\<Array\<PeerInfo>>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: MediaLibrary;<br>Method or attribute name: release(): Promise\<void>;<br>Old version: |Class name: MediaLibrary;<br>Method or attribute name: release(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Size;<br>Method or attribute name: interface Size<br>Old version: |Class name: Size;<br>Method or attribute name: interface Size<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Size;<br>Method or attribute name: width: number;<br>Old version: |Class name: Size;<br>Method or attribute name: width: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: Size;<br>Method or attribute name: height: number;<br>Old version: |Class name: Size;<br>Method or attribute name: height: number;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: PeerInfo;<br>Method or attribute name: interface PeerInfo<br>Old version: |Class name: PeerInfo;<br>Method or attribute name: interface PeerInfo<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: PeerInfo;<br>Method or attribute name: readonly deviceName: string;<br>Old version: |Class name: PeerInfo;<br>Method or attribute name: readonly deviceName: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: PeerInfo;<br>Method or attribute name: readonly networkId: string;<br>Old version: |Class name: PeerInfo;<br>Method or attribute name: readonly networkId: string;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: PeerInfo;<br>Method or attribute name: readonly deviceType: DeviceType;<br>Old version: |Class name: PeerInfo;<br>Method or attribute name: readonly deviceType: DeviceType;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: PeerInfo;<br>Method or attribute name: readonly isOnline: boolean;<br>Old version: |Class name: PeerInfo;<br>Method or attribute name: readonly isOnline: boolean;<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: enum DeviceType<br>Old version: |Class name: DeviceType;<br>Method or attribute name: enum DeviceType<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_UNKNOWN = 0<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_UNKNOWN = 0<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_LAPTOP<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_LAPTOP<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_PHONE<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_PHONE<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_TABLET<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_TABLET<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_WATCH<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_WATCH<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_CAR<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_CAR<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Deprecated version changed|Class name: DeviceType;<br>Method or attribute name: TYPE_TV<br>Old version: |Class name: DeviceType;<br>Method or attribute name: TYPE_TV<br>New version: 9<br>Substitute API: ohos.file.picker|@ohos.multimedia.mediaLibrary.d.ts|
|Access level changed|Class name: VolumeEvent;<br>Method or attribute name: interface VolumeEvent<br>Old version: systemapi|Class name: VolumeEvent;<br>Method or attribute name: interface VolumeEvent<br>New version: |@ohos.multimedia.audio.d.ts|
|Permission changed|Class name: VideoPlayer;<br>Method or attribute name: prepare(callback: AsyncCallback\<void>): void;<br>Old version: ohos.permission.MICROPHONE|Class name: VideoPlayer;<br>Method or attribute name: prepare(callback: AsyncCallback\<void>): void;<br>New version: |@ohos.multimedia.media.d.ts|
|Permission changed|Class name: VideoPlayer;<br>Method or attribute name: prepare(): Promise\<void>;<br>Old version: ohos.permission.MICROPHONE|Class name: VideoPlayer;<br>Method or attribute name: prepare(): Promise\<void>;<br>New version: |@ohos.multimedia.media.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_NEW|Class name: AudioState;<br>Method or attribute name: STATE_NEW = 0|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_PREPARED|Class name: AudioState;<br>Method or attribute name: STATE_PREPARED = 1|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_RUNNING|Class name: AudioState;<br>Method or attribute name: STATE_RUNNING = 2|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_STOPPED|Class name: AudioState;<br>Method or attribute name: STATE_STOPPED = 3|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_RELEASED|Class name: AudioState;<br>Method or attribute name: STATE_RELEASED = 4|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioState;<br>Method or attribute name: STATE_PAUSED|Class name: AudioState;<br>Method or attribute name: STATE_PAUSED = 5|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_RINGING|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_RINGING = 1|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_PHONE_CALL|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_PHONE_CALL = 2|@ohos.multimedia.audio.d.ts|
|Function changed|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_VOICE_CHAT|Class name: AudioScene;<br>Method or attribute name: AUDIO_SCENE_VOICE_CHAT = 3|@ohos.multimedia.audio.d.ts|
