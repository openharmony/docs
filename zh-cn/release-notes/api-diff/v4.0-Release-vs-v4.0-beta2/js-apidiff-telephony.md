| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：AudioDeviceInfo;<br>方法or属性：audioDeviceList: Array\<AudioDevice>;|NA|@ohos.telephony.call.d.ts|
|删除|类名：AudioDeviceInfo;<br>方法or属性：currentAudioDevice: AudioDevice;|NA|@ohos.telephony.call.d.ts|
|删除|类名：AudioDeviceInfo;<br>方法or属性：isMuted: boolean;|NA|@ohos.telephony.call.d.ts|
|新增|NA|类名：AudioDeviceCallbackInfo;<br>方法or属性：audioDeviceList: Array\<AudioDevice>;|@ohos.telephony.call.d.ts|
|新增|NA|类名：AudioDeviceCallbackInfo;<br>方法or属性：currentAudioDevice: AudioDevice;|@ohos.telephony.call.d.ts|
|新增|NA|类名：AudioDeviceCallbackInfo;<br>方法or属性：isMuted: boolean;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call;<br>方法or属性：function hasCallSync(): boolean;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call;<br>方法or属性：function getCallStateSync(): CallState;|@ohos.telephony.call.d.ts|
|新增|NA|类名：radio;<br>方法or属性：function getISOCountryCodeForNetworkSync(slotId: number): string;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：radio;<br>方法or属性：function getSignalInformationSync(slotId: number): Array\<SignalInformation>;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：radio;<br>方法or属性：function getOperatorNameSync(slotId: number): string;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function isSimActiveSync(slotId: number): boolean;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getISOCountryCodeForSimSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getSimOperatorNumericSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getSimSpnSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getSimStateSync(slotId: number): SimState;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getCardTypeSync(slotId: number): CardType;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function hasSimCardSync(slotId: number): boolean;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getOpKeySync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|新增|NA|类名：sim;<br>方法or属性：function getOpNameSync(slotId: number): string;|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：export interface IccAccountInfo<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：export interface IccAccountInfo<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：simId: number;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：simId: number;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：slotIndex: number;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：slotIndex: number;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：isEsim: boolean;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：isEsim: boolean;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：isActive: boolean;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：isActive: boolean;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：iccId: string;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：iccId: string;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：showName: string;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：showName: string;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|访问级别有变化|类名：IccAccountInfo;<br>方法or属性：showNumber: string;<br>旧版本信息：systemapi|类名：IccAccountInfo;<br>方法or属性：showNumber: string;<br>新版本信息：|@ohos.telephony.sim.d.ts|
|权限有变化|类名：sim;<br>方法or属性：function getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>旧版本信息：ohos.permission.GET_TELEPHONY_STATE|类名：sim;<br>方法or属性：function getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.GET_PHONE_NUMBERS|@ohos.telephony.sim.d.ts|
|权限有变化|类名：sim;<br>方法or属性：function getSimTelephoneNumber(slotId: number): Promise\<string>;<br>旧版本信息：ohos.permission.GET_TELEPHONY_STATE|类名：sim;<br>方法or属性：function getSimTelephoneNumber(slotId: number): Promise\<string>;<br>新版本信息：ohos.permission.GET_PHONE_NUMBERS|@ohos.telephony.sim.d.ts|
|函数有变化|类名：call;<br>方法or属性：function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceInfo>): void;|类名：call;<br>方法or属性：function on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceCallbackInfo>): void;|@ohos.telephony.call.d.ts|
|函数有变化|类名：call;<br>方法or属性：function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceInfo>): void;|类名：call;<br>方法or属性：function off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceCallbackInfo>): void;|@ohos.telephony.call.d.ts|
