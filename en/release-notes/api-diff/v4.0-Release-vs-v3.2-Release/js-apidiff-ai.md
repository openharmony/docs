| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: intelligentVoice;<br>Method or attribute name: function getIntelligentVoiceManager(): IntelligentVoiceManager;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: intelligentVoice;<br>Method or attribute name: function createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<EnrollIntelligentVoiceEngine>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: intelligentVoice;<br>Method or attribute name: function createEnrollIntelligentVoiceEngine(descriptor: EnrollIntelligentVoiceEngineDescriptor): Promise\<EnrollIntelligentVoiceEngine>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: intelligentVoice;<br>Method or attribute name: function createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor, callback: AsyncCallback\<WakeupIntelligentVoiceEngine>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: intelligentVoice;<br>Method or attribute name: function createWakeupIntelligentVoiceEngine(descriptor: WakeupIntelligentVoiceEngineDescriptor): Promise\<WakeupIntelligentVoiceEngine>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceManager;<br>Method or attribute name: getCapabilityInfo(): Array\<IntelligentVoiceEngineType>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceManager;<br>Method or attribute name: on(type: 'serviceChange', callback: Callback\<ServiceChangeType>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceManager;<br>Method or attribute name: off(type: 'serviceChange', callback?: Callback\<ServiceChangeType>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: ServiceChangeType;<br>Method or attribute name: SERVICE_UNAVAILABLE = 0|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceEngineType;<br>Method or attribute name: ENROLL_ENGINE_TYPE = 0|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceEngineType;<br>Method or attribute name: WAKEUP_ENGINE_TYPE = 1|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceEngineType;<br>Method or attribute name: UPDATE_ENGINE_TYPE = 2|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngineDescriptor;<br>Method or attribute name: wakeupPhrase: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngineDescriptor;<br>Method or attribute name: wakeupPhrase: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngineDescriptor;<br>Method or attribute name: needReconfirm: boolean;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollEngineConfig;<br>Method or attribute name: language: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollEngineConfig;<br>Method or attribute name: region: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: SensibilityType;<br>Method or attribute name: LOW_SENSIBILITY = 1|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: SensibilityType;<br>Method or attribute name: MIDDLE_SENSIBILITY = 2|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: SensibilityType;<br>Method or attribute name: HIGH_SENSIBILITY = 3|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupHapInfo;<br>Method or attribute name: bundleName: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupHapInfo;<br>Method or attribute name: abilityName: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEventType;<br>Method or attribute name: INTELLIGENT_VOICE_EVENT_WAKEUP_NONE = 0|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEventType;<br>Method or attribute name: INTELLIGENT_VOICE_EVENT_RECOGNIZE_COMPLETE = 1|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceErrorCode;<br>Method or attribute name: INTELLIGENT_VOICE_NO_MEMORY = 22700101|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceErrorCode;<br>Method or attribute name: INTELLIGENT_VOICE_INVALID_PARAM = 22700102|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceErrorCode;<br>Method or attribute name: INTELLIGENT_VOICE_INIT_FAILED = 22700103|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: IntelligentVoiceErrorCode;<br>Method or attribute name: INTELLIGENT_VOICE_COMMIT_ENROLL_FAILED = 22700104|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: SUCCESS = 0|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: VPR_TRAIN_FAILED = -1|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: WAKEUP_PHRASE_NOT_MATCH = -2|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: TOO_NOISY = -3|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: TOO_LOUD = -4|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: INTERVAL_LARGE = -5|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: DIFFERENT_PERSON = -6|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollResult;<br>Method or attribute name: UNKNOWN_ERROR = -100|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollCallbackInfo;<br>Method or attribute name: result: EnrollResult;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollCallbackInfo;<br>Method or attribute name: context: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngineCallbackInfo;<br>Method or attribute name: context: string;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngineCallbackInfo;<br>Method or attribute name: eventId: WakeupIntelligentVoiceEventType;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngineCallbackInfo;<br>Method or attribute name: isSuccess: boolean;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: getSupportedRegions(callback: AsyncCallback\<Array\<string>>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: getSupportedRegions(): Promise\<Array\<string>>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: getSupportedRegions(): Promise\<Array\<string>>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: init(config: EnrollEngineConfig, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: init(config: EnrollEngineConfig): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: enrollForResult(isLast: boolean, callback: AsyncCallback\<EnrollCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: enrollForResult(isLast: boolean): Promise\<EnrollCallbackInfo>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: stop(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: stop(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: commit(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: commit(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setWakeupHapInfo(info: WakeupHapInfo, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setWakeupHapInfo(info: WakeupHapInfo): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setSensibility(sensibility: SensibilityType, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setSensibility(sensibility: SensibilityType): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setSensibility(sensibility: SensibilityType): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setParameter(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setParameter(key: string, value: string, callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: setParameter(key: string, value: string): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: setParameter(key: string, value: string): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: getParameter(key: string, callback: AsyncCallback\<string>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: getParameter(key: string, callback: AsyncCallback\<string>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: getParameter(key: string): Promise\<string>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: getParameter(key: string): Promise\<string>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: release(callback: AsyncCallback\<void>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: EnrollIntelligentVoiceEngine;<br>Method or attribute name: release(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: release(): Promise\<void>;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: on(type: 'wakeupIntelligentVoiceEvent', callback: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: WakeupIntelligentVoiceEngine;<br>Method or attribute name: off(type: 'wakeupIntelligentVoiceEvent', callback?: Callback\<WakeupIntelligentVoiceEngineCallbackInfo>): void;|@ohos.ai.intelligentVoice.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: getInputs(): MSTensor[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: predict(inputs: MSTensor[], callback: Callback\<MSTensor[]>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: predict(inputs: MSTensor[]): Promise\<MSTensor[]>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: resize(inputs: MSTensor[], dims: Array\<Array\<number>>): boolean;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: target?: string[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: cpu?: CpuDevice;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: nnrt?: NNRTDevice;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadNum?: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadAffinityMode?: ThreadAffinityMode;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadAffinityCoreList?: number[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: precisionMode?: string;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: NO_AFFINITIES = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: BIG_CORES_FIRST = 1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: LITTLE_CORES_FIRST = 2|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: name: string;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: shape: number[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: elementNum: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: dataSize: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: dtype: DataType;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: format: Format;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: getData(): ArrayBuffer;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: setData(inputArray: ArrayBuffer): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT8 = 32|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT16 = 33|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT32 = 34|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT64 = 35|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT8 = 37|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT16 = 38|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT32 = 39|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT64 = 40|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT16 = 42|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT32 = 43|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT64 = 44|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: DEFAULT_FORMAT = -1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NCHW = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NHWC = 1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NHWC4 = 2|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: HWKC = 3|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: HWCK = 4|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: KCHW = 5|@ohos.ai.mindSporeLite.d.ts|
