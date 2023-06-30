| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceInfo>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceInfo>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function setAudioDevice(device: AudioDevice): Promise\<void>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function closeUnfinishedUssd(slotId: number, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function closeUnfinishedUssd(slotId: number): Promise\<void>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback\<boolean>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function setVoNRState(slotId: number, state: VoNRState): Promise\<boolean>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function getVoNRState(slotId: number, callback: AsyncCallback\<VoNRState>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function getVoNRState(slotId: number): Promise\<VoNRState>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function canSetCallTransferTime(slotId: number, callback: AsyncCallback\<boolean>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function canSetCallTransferTime(slotId: number): Promise\<boolean>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function inputDialerSpecialCode(inputCode: string, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: call<br>Method or attribute name: function inputDialerSpecialCode(inputCode: string): Promise\<void>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: VoNRState|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: VoNRState<br>Method or attribute name: VONR_STATE_ON = 0|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceType|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceType<br>Method or attribute name: DEVICE_EARPIECE|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceType<br>Method or attribute name: DEVICE_SPEAKER|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceType<br>Method or attribute name: DEVICE_WIRED_HEADSET|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceType<br>Method or attribute name: DEVICE_BLUETOOTH_SCO|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceInfo|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceInfo<br>Method or attribute name: audioDeviceList: Array\<AudioDevice>;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceInfo<br>Method or attribute name: currentAudioDevice: AudioDevice;|@ohos.telephony.call.d.ts|
|Added|NA|Module name: ohos.telephony.call<br>Class name: AudioDeviceInfo<br>Method or attribute name: isMuted: boolean;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: radio<br>Method or attribute name: function getBasebandVersion(slotId: number, callback: AsyncCallback\<String>): void;|@ohos.telephony.radio.d.ts|
|Added|NA|Class name: radio<br>Method or attribute name: function getBasebandVersion(slotId: number): Promise\<String>;|@ohos.telephony.radio.d.ts|
