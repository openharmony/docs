| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: AudioDeviceInfo;<br>Method or attribute name: audioDeviceList: Array\<AudioDevice>;|NA|@ohos.telephony.call.d.ts|
|Deleted|Class name: AudioDeviceInfo;<br>Method or attribute name: currentAudioDevice: AudioDevice;|NA|@ohos.telephony.call.d.ts|
|Deleted|Class name: AudioDeviceInfo;<br>Method or attribute name: isMuted: boolean;|NA|@ohos.telephony.call.d.ts|
|Added|NA|Class name: AudioDeviceCallbackInfo;<br>Method or attribute name: audioDeviceList: Array\<AudioDevice>;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: AudioDeviceCallbackInfo;<br>Method or attribute name: currentAudioDevice: AudioDevice;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: AudioDeviceCallbackInfo;<br>Method or attribute name: isMuted: boolean;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: call;<br>Method or attribute name: function hasCallSync(): boolean;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: call;<br>Method or attribute name: function getCallStateSync(): CallState;|@ohos.telephony.call.d.ts|
|Added|NA|Class name: radio;<br>Method or attribute name: function getISOCountryCodeForNetworkSync(slotId: number): string;|@ohos.telephony.radio.d.ts|
|Added|NA|Class name: radio;<br>Method or attribute name: function getSignalInformationSync(slotId: number): Array\<SignalInformation>;|@ohos.telephony.radio.d.ts|
|Added|NA|Class name: radio;<br>Method or attribute name: function getOperatorNameSync(slotId: number): string;|@ohos.telephony.radio.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function isSimActiveSync(slotId: number): boolean;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getISOCountryCodeForSimSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getSimOperatorNumericSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getSimSpnSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getSimStateSync(slotId: number): SimState;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getCardTypeSync(slotId: number): CardType;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function hasSimCardSync(slotId: number): boolean;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getOpKeySync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|Added|NA|Class name: sim;<br>Method or attribute name: function getOpNameSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: export interface IccAccountInfo<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: export interface IccAccountInfo<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: simId: number;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: simId: number;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: slotIndex: number;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: slotIndex: number;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: isEsim: boolean;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: isEsim: boolean;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: isActive: boolean;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: isActive: boolean;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: iccId: string;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: iccId: string;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: showName: string;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: showName: string;<br>New version information: |@ohos.telephony.sim.d.ts|
|Access level changed|Class name: IccAccountInfo;<br>Method or attribute name: showNumber: string;<br>Old version information: systemapi|Class name: IccAccountInfo;<br>Method or attribute name: showNumber: string;<br>New version information: |@ohos.telephony.sim.d.ts|
|Permission changed|Class name: sim;<br>Method or attribute name: function getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>Old version information: ohos.permission.GET_TELEPHONY_STATE|Class name: sim;<br>Method or attribute name: function getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>New version information: ohos.permission.GET_PHONE_NUMBERS|@ohos.telephony.sim.d.ts|
|Permission changed|Class name: sim;<br>Method or attribute name: function getSimTelephoneNumber(slotId: number): Promise\<string>;<br>Old version information: ohos.permission.GET_TELEPHONY_STATE|Class name: sim;<br>Method or attribute name: function getSimTelephoneNumber(slotId: number): Promise\<string>;<br>New version information: ohos.permission.GET_PHONE_NUMBERS|@ohos.telephony.sim.d.ts|
|Function changed|Class name: call;<br>Method or attribute name: function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceInfo>): void;|Class name: call;<br>Method or attribute name: function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceCallbackInfo>): void;|@ohos.telephony.call.d.ts|
|Function changed|Class name: call;<br>Method or attribute name: function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceInfo>): void;|Class name: call;<br>Method or attribute name: function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceCallbackInfo>): void;|@ohos.telephony.call.d.ts|
