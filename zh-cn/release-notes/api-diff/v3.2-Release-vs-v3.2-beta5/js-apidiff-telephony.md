| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：call<br>方法or属性：function dialCall(phoneNumber: string, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function dialCall(phoneNumber: string, options: DialCallOptions, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function dialCall(phoneNumber: string, options?: DialCallOptions): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function answerCall(callId: number, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function answerCall(callId?: number): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function answerCall(callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function hangUpCall(callId: number, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function hangUpCall(callId?: number): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function hangUpCall(callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function rejectCall(callId: number, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function rejectCall(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function rejectCall(callId?: number, options?: RejectMessageOptions): Promise\<void>;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function rejectCall(callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|类名：call<br>方法or属性：function rejectCall(options: RejectMessageOptions, callback: AsyncCallback\<void>): void;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: DialCallOptions|@ohos.telephony.call.d.ts|
|新增|NA|类名：DialCallOptions<br>方法or属性：|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: DialCallOptions<br>方法 or 属性：accountId?: number;|@ohos.telephony.call.d.ts|
|新增|NA|类名：DialCallOptions<br>方法or属性：accountId?: number;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: DialCallOptions<br>方法 or 属性：videoState?: VideoStateType;|@ohos.telephony.call.d.ts|
|新增|NA|类名：DialCallOptions<br>方法or属性：videoState?: VideoStateType;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: DialCallOptions<br>方法 or 属性：dialScene?: DialScene;|@ohos.telephony.call.d.ts|
|新增|NA|类名：DialCallOptions<br>方法or属性：dialScene?: DialScene;|@ohos.telephony.call.d.ts|
|新增|NA|模块名: ohos.telephony.call<br>类名: DialCallOptions<br>方法 or 属性：dialType?: DialType;|@ohos.telephony.call.d.ts|
|新增|NA|类名：DialCallOptions<br>方法or属性：dialType?: DialType;|@ohos.telephony.call.d.ts|
|新增|NA|类名：radio<br>方法or属性：function isNRSupported(): boolean;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：radio<br>方法or属性：function isNRSupported(slotId: number): boolean;|@ohos.telephony.radio.d.ts|
|新增|NA|模块名: ohos.telephony.radio<br>类名: SignalInformation<br>方法 or 属性：dBm: number;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：SignalInformation<br>方法or属性：dBm: number;|@ohos.telephony.radio.d.ts|
|新增|NA|类名：OperatorConfigKey<br>方法or属性：KEY_IMS_CALL_DISCONNECT_REASON_INFO_MAPPING_STRING_ARRAY = "ims_call_disconnect_reason_info_mapping_string_array"|@ohos.telephony.sim.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function answer(callId: number, callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function answer(callId?: number): Promise\<void>;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function answer(callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function hangup(callId: number, callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function hangup(callId?: number): Promise\<void>;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function hangup(callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function reject(callId: number, callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function reject(callId?: number, options?: RejectMessageOptions): Promise\<void>;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function reject(callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.call<br>类名:call<br>方法 or 属性:function reject(options: RejectMessageOptions, callback: AsyncCallback\<void>): void;|NA|@ohos.telephony.call.d.ts|
|删除|模块名：ohos.telephony.sim<br>类名:OperatorConfigKey<br>方法 or 属性:KEY_IMS_CALL_DISCONNECT_REASONINFO_MAPPING_STRING_ARRAY = "ims_call_disconnect_reasoninfo_mapping_string_array"|NA|@ohos.telephony.sim.d.ts|
|废弃版本有变化|类名：call<br>方法 or 属性：function dial(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：call<br>方法 or 属性：function dial(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：telephony.call|@ohos.telephony.call.d.ts|
|废弃版本有变化|类名：call<br>方法 or 属性：function dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：call<br>方法 or 属性：function dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：telephony.call|@ohos.telephony.call.d.ts|
|废弃版本有变化|类名：call<br>方法 or 属性：function dial(phoneNumber: string, options?: DialOptions): Promise\<boolean>;<br>废弃版本：N/A|类名：call<br>方法 or 属性：function dial(phoneNumber: string, options?: DialOptions): Promise\<boolean>;<br>废弃版本：9<br>代替接口：telephony.call|@ohos.telephony.call.d.ts|
|废弃版本有变化|类名：radio<br>方法 or 属性：function isNrSupported(): boolean;<br>废弃版本：N/A|类名：radio<br>方法 or 属性：function isNrSupported(): boolean;<br>废弃版本：9<br>代替接口：telephony.radio|@ohos.telephony.radio.d.ts|
|废弃版本有变化|类名：radio<br>方法 or 属性：function isNrSupported(slotId: number): boolean;<br>废弃版本：N/A|类名：radio<br>方法 or 属性：function isNrSupported(slotId: number): boolean;<br>废弃版本：9<br>代替接口：telephony.radio|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function muteRinger(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function muteRinger(): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isEmergencyPhoneNumber(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isEmergencyPhoneNumber(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isEmergencyPhoneNumber(phoneNumber: string, options?: EmergencyNumberOptions): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function formatPhoneNumberToE164(phoneNumber: string, countryCode: string, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function formatPhoneNumberToE164(phoneNumber: string, countryCode: string): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function holdCall(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function holdCall(callId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function unHoldCall(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function unHoldCall(callId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function switchCall(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function switchCall(callId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function combineConference(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function combineConference(callId: number): Promise\<void>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getMainCallId(callId: number, callback: AsyncCallback\<number>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getMainCallId(callId: number): Promise\<number>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getSubCallIdList(callId: number, callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getSubCallIdList(callId: number): Promise\<Array\<string>>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallIdListForConference(callId: number, callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallIdListForConference(callId: number): Promise\<Array\<string>>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallWaitingStatus(slotId: number, callback: AsyncCallback\<CallWaitingStatus>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallWaitingStatus(slotId: number): Promise\<CallWaitingStatus>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallWaiting(slotId: number, activate: boolean, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallWaiting(slotId: number, activate: boolean): Promise\<void>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function startDTMF(callId: number, character: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function startDTMF(callId: number, character: string): Promise\<void>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function stopDTMF(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function stopDTMF(callId: number): Promise\<void>;<br>错误码内容: 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isInEmergencyCall(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isInEmergencyCall(): Promise\<boolean>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function on(type: 'callDetailsChange', callback: Callback\<CallAttributeOptions>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function off(type: 'callDetailsChange', callback?: Callback\<CallAttributeOptions>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function on(type: 'callEventChange', callback: Callback\<CallEventOptions>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function off(type: 'callEventChange', callback?: Callback\<CallEventOptions>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function on(type: 'callDisconnectedCause', callback: Callback\<DisconnectedDetails>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function off(type: 'callDisconnectedCause', callback?: Callback\<DisconnectedDetails>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isNewCallAllowed(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isNewCallAllowed(): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function separateConference(callId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function separateConference(callId: number): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallRestrictionStatus(slotId: number, type: CallRestrictionType, callback: AsyncCallback\<RestrictionStatus>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallRestrictionStatus(slotId: number, type: CallRestrictionType): Promise\<RestrictionStatus>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallRestriction(slotId: number, info: CallRestrictionInfo, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallRestriction(slotId: number, info: CallRestrictionInfo): Promise\<void>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallTransferInfo(slotId: number, type: CallTransferType, callback: AsyncCallback\<CallTransferResult>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function getCallTransferInfo(slotId: number, type: CallTransferType): Promise\<CallTransferResult>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallTransfer(slotId: number, info: CallTransferInfo, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setCallTransfer(slotId: number, info: CallTransferInfo): Promise\<void>;<br>错误码内容: 201, 401, 801, 8300001, 8300002, 8300003|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isRinging(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isRinging(): Promise\<boolean>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setMuted(callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setMuted(): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function cancelMuted(callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function cancelMuted(): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setAudioDevice(device: AudioDevice, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setAudioDevice(device: AudioDevice, options: AudioDeviceOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function setAudioDevice(device: AudioDevice, options?: AudioDeviceOptions): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function joinConference(mainCallId: number, callNumberList: Array\<string>, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function joinConference(mainCallId: number, callNumberList: Array\<string>): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function updateImsCallMode(callId: number, mode: ImsCallMode, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function updateImsCallMode(callId: number, mode: ImsCallMode): Promise\<void>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function enableImsSwitch(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function enableImsSwitch(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function disableImsSwitch(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function disableImsSwitch(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isImsSwitchEnabled(slotId: number, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：call<br>方法 or 属性：function isImsSwitchEnabled(slotId: number): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function setDefaultCellularDataSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301001|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function setDefaultCellularDataSlotId(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301001|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function isCellularDataEnabled(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function isCellularDataEnabled(): Promise\<boolean>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function enableCellularData(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function enableCellularData(): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function disableCellularData(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function disableCellularData(): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function isCellularDataRoamingEnabled(slotId: number): Promise\<boolean>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function enableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function enableCellularDataRoaming(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function disableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：data<br>方法 or 属性：function disableCellularDataRoaming(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.data.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'networkStateChange', callback: Callback\<NetworkState>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'networkStateChange', options: { slotId: number }, callback: Callback\<NetworkState>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'networkStateChange', callback?: Callback\<NetworkState>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'signalInfoChange', callback: Callback\<Array\<SignalInformation>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'signalInfoChange', options: { slotId: number },<br>    callback: Callback\<Array\<SignalInformation>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'signalInfoChange', callback?: Callback\<Array\<SignalInformation>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellInfoChange', callback: Callback\<Array\<CellInformation>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellInfoChange', options: { slotId: number },<br>    callback: Callback\<Array\<CellInformation>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'cellInfoChange', callback?: Callback\<Array\<CellInformation>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellularDataConnectionStateChange',<br>    callback: Callback\<{ state: DataConnectState, network: RatType }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellularDataConnectionStateChange', options: { slotId: number },<br>    callback: Callback\<{ state: DataConnectState, network: RatType }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'cellularDataConnectionStateChange',<br>    callback?: Callback\<{ state: DataConnectState, network: RatType }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'cellularDataFlowChange', options: { slotId: number },<br>    callback: Callback\<DataFlowType>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'callStateChange', callback: Callback\<{ state: CallState, number: string }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'callStateChange', options: { slotId: number },<br>    callback: Callback\<{ state: CallState, number: string }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'callStateChange', callback?: Callback\<{ state: CallState, number: string }>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'simStateChange', callback: Callback\<SimStateData>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function on(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：observer<br>方法 or 属性：function off(type: 'simStateChange', callback?: Callback\<SimStateData>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.observer.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getRadioTech(slotId: number,<br>    callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkState(callback: AsyncCallback\<NetworkState>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkState(slotId?: number): Promise\<NetworkState>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function sendUpdateCellLocationRequest(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function sendUpdateCellLocationRequest(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function sendUpdateCellLocationRequest(slotId?: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getCellInformation(callback: AsyncCallback\<Array\<CellInformation>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getCellInformation(slotId: number, callback: AsyncCallback\<Array\<CellInformation>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getCellInformation(slotId?: number): Promise\<Array\<CellInformation>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkSelectionMode(slotId: number, callback: AsyncCallback\<NetworkSelectionMode>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkSelectionMode(slotId: number): Promise\<NetworkSelectionMode>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setNetworkSelectionMode(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setNetworkSelectionMode(options: NetworkSelectionModeOptions): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkSearchInformation(slotId: number, callback: AsyncCallback\<NetworkSearchResult>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNetworkSearchInformation(slotId: number): Promise\<NetworkSearchResult>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getISOCountryCodeForNetwork(slotId: number): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNrOptionMode(callback: AsyncCallback\<NrOptionMode>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNrOptionMode(slotId: number, callback: AsyncCallback\<NrOptionMode>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getNrOptionMode(slotId?: number): Promise\<NrOptionMode>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getIMEI(callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getIMEI(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getIMEI(slotId?: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getMEID(callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getMEID(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getMEID(slotId?: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getUniqueDeviceId(callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getUniqueDeviceId(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getUniqueDeviceId(slotId?: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getPrimarySlotId(callback: AsyncCallback\<number>): void;<br>错误码内容: 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getPrimarySlotId(): Promise\<number>;<br>错误码内容: 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setPrimarySlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setPrimarySlotId(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getSignalInformation(slotId: number, callback: AsyncCallback\<Array\<SignalInformation>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getSignalInformation(slotId: number): Promise\<Array\<SignalInformation>>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function isRadioOn(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function isRadioOn(slotId: number, callback: AsyncCallback\<boolean>): void<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function isRadioOn(slotId?: number): Promise\<boolean>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOnRadio(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOnRadio(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOnRadio(slotId?: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOffRadio(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOffRadio(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function turnOffRadio(slotId?: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getOperatorName(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getOperatorName(slotId: number): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setPreferredNetwork(slotId: number, networkMode: PreferredNetworkMode, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function setPreferredNetwork(slotId: number, networkMode: PreferredNetworkMode): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getPreferredNetwork(slotId: number, callback: AsyncCallback\<PreferredNetworkMode>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：radio<br>方法 or 属性：function getPreferredNetwork(slotId: number): Promise\<PreferredNetworkMode>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.radio.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function hasOperatorPrivileges(slotId: number): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getISOCountryCodeForSim(slotId: number): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimOperatorNumeric(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimOperatorNumeric(slotId: number): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimSpn(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimSpn(slotId: number): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimState(slotId: number): Promise\<SimState>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getCardType(slotId: number, callback: AsyncCallback\<CardType>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getCardType(slotId: number): Promise\<CardType>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimIccId(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimIccId(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getVoiceMailIdentifier(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getVoiceMailIdentifier(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getVoiceMailNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getVoiceMailNumber(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimTelephoneNumber(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimGid1(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimGid1(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getIMSI(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getIMSI(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function hasSimCard(slotId: number, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function hasSimCard(slotId: number): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimAccountInfo(slotId: number, callback: AsyncCallback\<IccAccountInfo>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getSimAccountInfo(slotId: number): Promise\<IccAccountInfo>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getActiveSimAccountInfoList(callback: AsyncCallback\<Array\<IccAccountInfo>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getActiveSimAccountInfoList(): Promise\<Array\<IccAccountInfo>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301001|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setDefaultVoiceSlotId(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301001|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function activateSim(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function activateSim(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function deactivateSim(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function deactivateSim(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setShowName(slotId: number, name: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setShowName(slotId: number, name: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getShowName(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getShowName(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setShowNumber(slotId: number, number: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setShowNumber(slotId: number, number: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getShowNumber(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getShowNumber(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getOperatorConfigs(slotId: number, callback: AsyncCallback\<Array\<OperatorConfig>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getOperatorConfigs(slotId: number): Promise\<Array\<OperatorConfig>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPin(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPin(slotId: number, pin: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPuk(slotId: number, newPin: string, puk: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPuk(slotId: number, newPin: string, puk: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function alterPin(slotId: number, newPin: string, oldPin: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setLockState(slotId: number, options: LockInfo, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function setLockState(slotId: number, options: LockInfo): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPin2(slotId: number, pin2: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPin2(slotId: number, pin2: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPuk2(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockPuk2(slotId: number, newPin2: string, puk2: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function alterPin2(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function alterPin2(slotId: number, newPin2: string, oldPin2: string): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function queryIccDiallingNumbers(slotId: number, type: ContactType, callback: AsyncCallback\<Array\<DiallingNumbersInfo>>): void<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function queryIccDiallingNumbers(slotId: number, type: ContactType): Promise\<Array\<DiallingNumbersInfo>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getLockState(slotId: number, lockType: LockType, callback: AsyncCallback\<LockState>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function getLockState(slotId: number, lockType: LockType): Promise\<LockState>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function sendEnvelopeCmd(slotId: number, cmd: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function sendEnvelopeCmd(slotId: number, cmd: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function sendTerminalResponseCmd(slotId: number, cmd: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function sendTerminalResponseCmd(slotId: number, cmd: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockSimLock(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback\<LockStatusResponse>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sim<br>方法 or 属性：function unlockSimLock(slotId: number, lockInfo: PersoLockInfo): Promise\<LockStatusResponse>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999, 8301002|@ohos.telephony.sim.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function splitMessage(content: string, callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function splitMessage(content: string): Promise\<Array\<string>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function createMessage(pdu: Array\<number>, specification: string): Promise\<ShortMessage>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function sendMessage(options: SendMessageOptions): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setDefaultSmsSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setDefaultSmsSlotId(slotId: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300004, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setSmscAddr(slotId: number, smscAddr: string): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getSmscAddr(slotId: number): Promise\<string>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function addSimMessage(options: SimMessageOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function addSimMessage(options: SimMessageOptions): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function delSimMessage(slotId: number, msgIndex: number): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function updateSimMessage(options: UpdateSimMessageOptions): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getAllSimMessages(slotId: number, callback: AsyncCallback\<Array\<SimShortMessage>>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getAllSimMessages(slotId: number): Promise\<Array\<SimShortMessage>>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setCBConfig(options: CBConfigOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function setCBConfig(options: CBConfigOptions): Promise\<void>;<br>错误码内容: 201, 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean, callback: AsyncCallback\<SmsSegmentsInfo>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean): Promise\<SmsSegmentsInfo>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function isImsSmsSupported(slotId: number, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function isImsSmsSupported(slotId: number): Promise\<boolean>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getImsShortMessageFormat(callback: AsyncCallback\<string>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function getImsShortMessageFormat(): Promise\<string>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function decodeMms(mmsFilePathName: string \| Array\<number>, callback: AsyncCallback\<MmsInformation>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function decodeMms(mmsFilePathName: string \| Array\<number>): Promise\<MmsInformation>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function encodeMms(mms: MmsInformation, callback: AsyncCallback\<Array\<number>>): void;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
|新增(错误码)|NA|类名：sms<br>方法 or 属性：function encodeMms(mms: MmsInformation): Promise\<Array\<number>>;<br>错误码内容: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.sms.d.ts|
