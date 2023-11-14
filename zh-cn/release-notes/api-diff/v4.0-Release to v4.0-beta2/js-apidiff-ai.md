| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：intelligentVoice;<br>方法or属性：function getIntelligentVoiceManager(): IntelligentVoiceManager;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：intelligentVoice;<br>方法or属性：function createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<EnrollIntelligentVoiceEngine>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：intelligentVoice;<br>方法or属性：function createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor): Promise\<EnrollIntelligentVoiceEngine>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：intelligentVoice;<br>方法or属性：function createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<WakeupIntelligentVoiceEngine>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：intelligentVoice;<br>方法or属性：function createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor): Promise\<WakeupIntelligentVoiceEngine>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceManager;<br>方法or属性：getCapabilityInfo(): Array\<IntelligentVoiceEngineType>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceManager;<br>方法or属性：on(type: 'serviceChange', callback: Callback\<ServiceChangeType>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceManager;<br>方法or属性：off(type: 'serviceChange', callback?: Callback\<ServiceChangeType>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：ServiceChangeType;<br>方法or属性：SERVICE_UNAVAILABLE = 0|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceEngineType;<br>方法or属性：ENROLL_ENGINE_TYPE = 0|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceEngineType;<br>方法or属性：WAKEUP_ENGINE_TYPE = 1|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceEngineType;<br>方法or属性：UPDATE_ENGINE_TYPE = 2|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngineDescriptor;<br>方法or属性：wakeupPhrase: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngineDescriptor;<br>方法or属性：wakeupPhrase: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngineDescriptor;<br>方法or属性：needReconfirm: boolean;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollEngineConfig;<br>方法or属性：language: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollEngineConfig;<br>方法or属性：region: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：SensibilityType;<br>方法or属性：LOW_SENSIBILITY = 1|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：SensibilityType;<br>方法or属性：MIDDLE_SENSIBILITY = 2|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：SensibilityType;<br>方法or属性：HIGH_SENSIBILITY = 3|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupHapInfo;<br>方法or属性：bundleName: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupHapInfo;<br>方法or属性：abilityName: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEventType;<br>方法or属性：INTELLIGENT_VOICE_EVENT_WAKEUP_NONE = 0|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEventType;<br>方法or属性：INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE = 1|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceErrorCode;<br>方法or属性：INTELLIGENT_VOICE_NO_MEMORY = 22700101|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceErrorCode;<br>方法or属性：INTELLIGENT_VOICE_INVALID_PARAM = 22700102|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceErrorCode;<br>方法or属性：INTELLIGENT_VOICE_INIT_FAILED = 22700103|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：IntelligentVoiceErrorCode;<br>方法or属性：INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED = 22700104|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：SUCCESS = 0|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：VPR_TRAIN_FAILED = -1|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：WAKEUP_PHRASE_NOT_MATCH = -2|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：TOO_NOISY = -3|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：TOO_LOUD = -4|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：INTERVAL_LARGE = -5|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：DIFFERENT_PERSON = -6|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollResult;<br>方法or属性：UNKNOWN_ERROR = -100|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollCallbackInfo;<br>方法or属性：result: EnrollResult;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollCallbackInfo;<br>方法or属性：context: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngineCallbackInfo;<br>方法or属性：context: string;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngineCallbackInfo;<br>方法or属性：eventId: WakeupIntelligentVoiceEventType;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngineCallbackInfo;<br>方法or属性：isSuccess: boolean;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：getSupportedRegions(): Promise\<Array\<string>>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：getSupportedRegions(): Promise\<Array\<string>>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：init(config: EnrollEngineConfig, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：init(config: EnrollEngineConfig): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：enrollForResult(isLast: boolean, callback: AsyncCallback\<EnrollCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：enrollForResult(isLast: boolean): Promise\<EnrollCallbackInfo>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：stop(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：stop(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：commit(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：commit(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setSensibility(sensibility: SensibilityType): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setSensibility(sensibility: SensibilityType): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setParameter(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setParameter(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：setParameter(key: string, value: string): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：setParameter(key: string, value: string): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：getParameter(key: string, callback: AsyncCallback\<string>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：getParameter(key: string, callback: AsyncCallback\<string>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：getParameter(key: string): Promise\<string>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：getParameter(key: string): Promise\<string>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：release(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：EnrollIntelligentVoiceEngine;<br>方法or属性：release(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：release(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：on(type: 'wakeupIntelligentVoiceEvent', callback: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
|新增|NA|类名：WakeupIntelligentVoiceEngine;<br>方法or属性：off(type: 'wakeupIntelligentVoiceEvent', callback?: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
