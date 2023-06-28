| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceInfo>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceInfo>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function setAudioDevice(device: AudioDevice): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function closeUnfinishedUssd(slotId: number, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function closeUnfinishedUssd(slotId: number): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback\<boolean>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function setVoNRState(slotId: number, state: VoNRState): Promise\<boolean>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function getVoNRState(slotId: number, callback: AsyncCallback\<VoNRState>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function getVoNRState(slotId: number): Promise\<VoNRState>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function canSetCallTransferTime(slotId: number, callback: AsyncCallback\<boolean>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function canSetCallTransferTime(slotId: number): Promise\<boolean>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function inputDialerSpecialCode(inputCode: string, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: call<br>方法 or 属性: function inputDialerSpecialCode(inputCode: string): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: VoNRState|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: VoNRState<br>方法 or 属性: VONR_STATE_ON = 0|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceType|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceType<br>方法 or 属性: DEVICE_EARPIECE|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceType<br>方法 or 属性: DEVICE_SPEAKER|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceType<br>方法 or 属性: DEVICE_WIRED_HEADSET|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceType<br>方法 or 属性: DEVICE_BLUETOOTH_SCO|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceInfo|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceInfo<br>方法 or 属性: audioDeviceList: Array\<AudioDevice>;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceInfo<br>方法 or 属性: currentAudioDevice: AudioDevice;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: AudioDeviceInfo<br>方法 or 属性: isMuted: boolean;|@ohos.telephony.call.d.ts|
|新增|NA|类名：radio<br>方法or属性：function getBasebandVersion(slotId: number, callback: AsyncCallback\<String>): void;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：radio<br>方法or属性：function getBasebandVersion(slotId: number): Promise\<String>;|@ohos.telephony.radio.d.ts|
