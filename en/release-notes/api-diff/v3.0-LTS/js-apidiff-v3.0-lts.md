# JS API Differences
This document describes the changes of APIs in OpenHarmony 3.0 LTS when compared with OpenHarmony 2.2 Beta2.
## Standard System API Changes

| Module | API | Change Type | Change Description |
|  --------  |  --------  |  --------  |  --------  |
|Multi - language Runtime - worker|postMessage(obj):void|Added|Used by the host thread to transfer data to the worker.|
|Multi - language Runtime - worker|postMessage(message: Object, options?: PostMessageOptions):void|Added|Used by the host thread to transfer the data control permission of the array buffer to the worker.|
|Multi - language Runtime - worker|terminate():void|Added|Used by the host thread to proactively terminate the worker.|
|Multi - language Runtime - worker|on(type: string, listener: EventListener): void|Added|Adds a callback for the worker.|
|Multi - language Runtime - worker|once(type: string, listener: EventListener): void|Added|Adds a one - shot callback for the worker.|
|Multi - language Runtime - worker|off(type: string, listener?: EventListener): void|Added|Deletes a callback added for the worker.|
|Multi - language Runtime - worker|addEventListener(type: string, listener: EventListener): void|Added|Adds a callback for the worker.|
|Multi - language Runtime - worker|removeEventListener(type: string, listener?: EventListener): void|Added|Deletes a callback added for the worker.|
|Multi - language Runtime - worker|removeAllListener(): void|Added|Deletes all callbacks added for the worker.|
|Multi - language Runtime - worker|dispatchEvent(event: Event): boolean|Added|Dispatches a specific event to the worker.|
|Multi - language Runtime - parentPort|postMessage(obj):void|Added|Used by the worker to transfer data to the host thread.|
|Multi - language Runtime - parentPort|postMessage(message: Object, options?: PostMessageOptions):void|Added|Used by the worker to transfer the data control permission of the array buffer to the host thread.|
|Multi - language Runtime - parentPort|close(): void|Added|Used by the worker to proactively terminate itself.|
|Multi - language Runtime - Util|printf(format: string, ...args: Object[]): string|Added|-|
|Multi - language Runtime - Util|getErrorString(errno: number): string|Added|-|
|Multi - language Runtime - Util|callbackWrapper(original: Function): (err: Object, value: Object) => void|Added|-|
|Multi - language Runtime - Util|promiseWrapper(original: (err: Object, value: Object) => void): Object|Added|-|
|Multi - language Runtime - Util|new TextDecoder([encoding[, options]])|Added|-|
|Multi - language Runtime - Util|decode([input[, options]]):string|Added|-|
|Multi - language Runtime - Util|new TextEncoder()|Added|-|
|Multi - language Runtime - Util|encode(input?: string): Uint8Array;|Added|-|
|Multi - language Runtime - Util|"encodeInto(input: string,dest: Uint8Array,): { read: number; written: number };"|Added|-|
|Multi - language Runtime - Util|readonly encoding: string;|Added|-|
|Multi - language Runtime - Util|readonly fatal: boolean;|Added|-|
|Multi - language Runtime - Util|readonly ignoreBOM = false;|Added|-|
|Multi - language Runtime - Util|readonly encoding = "utf-8";|Added|-|
|Multi - language Runtime - URL|new URL(url: string, base?: string/URL)|Added|-|
|Multi - language Runtime - URL|toString(): string;|Added|-|
|Multi - language Runtime - URL|toJSON(): string;|Added|-|
|Multi - language Runtime - URL|new URSearchParams()|Added|-|
|Multi - language Runtime - URL|new URSearchParams(string)|Added|-|
|Multi - language Runtime - URL|new URSearchParams(obj)|Added|-|
|Multi - language Runtime - URL|new URSearchParams(iterable)|Added|-|
|Multi - language Runtime - URL|append(name: string, value: string): void;|Added|-|
|Multi - language Runtime - URL|delete(name: string): void;|Added|-|
|Multi - language Runtime - URL|entries(): IterableIterator\<[string, string]>;|Added|-|
|Multi - language Runtime - URL|forEach(callbackfn: (value: string, key: string, parent: this) => void, thisArg?: any,): void;|Added|-|
|Multi - language Runtime - URL|get(name: string): string / null;|Added|-|
|Multi - language Runtime - URL|getAll(name: string): string[];|Added|-|
|Multi - language Runtime - URL|has(name: string): boolean;|Added|-|
|Multi - language Runtime - URL|keys(): IterableIterator\<string>;|Added|-|
|Multi - language Runtime - URL|set(name: string, value: string): void;|Added|-|
|Multi - language Runtime - URL|sort():void;|Added|-|
|Multi - language Runtime - URL|toString():string|Added|-|
|Multi - language Runtime - URL|values(): IterableIterator\<string>;|Added|-|
|Multi - language Runtime - URL|URSearchParams\[Symbol.iterator]()|Added|-|
|Multi - language Runtime - URL|hash: string;|Added|-|
|Multi - language Runtime - URL|host: string;|Added|-|
|Multi - language Runtime - URL|hostname: string;|Added|-|
|Multi - language Runtime - URL|href: string;|Added|-|
|Multi - language Runtime - URL|readonly origin: string;|Added|-|
|Multi - language Runtime - URL|password: string;|Added|-|
|Multi - language Runtime - URL|pathname: string;|Added|-|
|Multi - language Runtime - URL|port: string;|Added|-|
|Multi - language Runtime - URL|protocol: string;|Added|-|
|Multi - language Runtime - URL|search: string;|Added|-|
|Multi - language Runtime - URL|readonly searchParams: URLSearchParams;|Added|-|
|Multi - language Runtime - URL|username: string;|Added|-|
|Multi - language Runtime - ChildProcess|readonly pid: number;|Added|-|
|Multi - language Runtime - ChildProcess|readonly ppid: number;|Added|-|
|Multi - language Runtime - ChildProcess|readonly exitCode: number;|Added|-|
|Multi - language Runtime - ChildProcess|readonly killed: boolean;|Added|-|
|Multi - language Runtime - ChildProcess|wait(): Promise\<number>;|Added|-|
|Multi - language Runtime - ChildProcess|getOutput(): Promise\<Uint8Array>;|Added|-|
|Multi - language Runtime - ChildProcess|getErrorOutput(): Promise\<Uint8Array>;|Added|-|
|Multi - language Runtime - ChildProcess|close(): void;|Added|-|
|Multi - language Runtime - ChildProcess|kill(signal: number): void;|Added|-|
|Multi - language Runtime - process|runCmd(command: string,options?: { timeout : number, killSignal : number string, maxBuffer : number }): ChildProcess;|Added|-|
|Multi - language Runtime - process|getPid(): number;|Added|-|
|Multi - language Runtime - process|getPpid(): number;|Added|-|
|Multi - language Runtime - process|abort(): void;|Added|-|
|Multi - language Runtime - process|on(type: string, listener: EventListener): void;|Added|-|
|Multi - language Runtime - process|exit(code?:number): void;|Added|-|
|Multi - language Runtime - process|cwd(): string;|Added|-|
|Multi - language Runtime - process|chdir(dir: string): void;|Added|-|
|Multi - language Runtime - process|getEgid(): number;|Added|-|
|Multi - language Runtime - process|getEuid(): number;|Added|-|
|Multi - language Runtime - process|getGid(): number|Added|-|
|Multi - language Runtime - process|getUid(): number;|Added|-|
|Multi - language Runtime - process|uptime(): number;|Added|-|
|Multi - language Runtime - process|getGroups(): number[];|Added|-|
|Multi - language Runtime - process|kill(signal?: number, pid?: number): boolean;|Added|-|
|Update Subsystem - Updater|checkNewVersion(): Promise\<NewVersionInfo>;|Added|    -|
|Update Subsystem - Updater|rebootAndCleanUserData(callback: AsyncCallback\<number>): void;|Added|    -|
|Update Subsystem - Updater|rebootAndCleanCache(): Promise\<number>;|Added|    -|
|Update Subsystem - Updater|getUpdaterFromOther(device: string, updateType?: UpdateTypes): Updater;|Added|    -|
|Update Subsystem - Updater|cancel(): void;|Added|    -|
|Update Subsystem - Updater|upgrade(): void;|Added|    -|
|Update Subsystem - Updater|off(eventType: 'downloadProgress', callback?: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;|Added|    -|
|Update Subsystem - Updater|getUpdaterForOther(device: string, updateType?: UpdateTypes): Updater;|Added|    -|
|Update Subsystem - Updater|setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;|Added|    -|
|Update Subsystem - Updater|getNewVersionInfo(): Promise\<NewVersionInfo>;|Added|    -|
|Update Subsystem - Updater|getUpdater(updateType?: UpdateTypes): Updater;|Added|    -|
|Update Subsystem - Updater|applyNewVersion(callback: AsyncCallback\<number>): void;|Added|    -|
|Update Subsystem - Updater|rebootAndCleanUserData(): Promise\<number>;|Added|    -|
|Update Subsystem - Updater|off(eventType: 'verifyProgress', callback?: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|on(eventType: 'upgradeProgress', callback: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void;|Added|    -|
|Update Subsystem - Updater|on(eventType: 'downloadProgress', callback: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|getUpdatePolicy(): Promise\<UpdatePolicy>;|Added|    -|
|Update Subsystem - Updater|download(): void;|Added|    -|
|Update Subsystem - Updater|off(eventType: 'upgradeProgress', callback?: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;|Added|    -|
|Update Subsystem - Updater|on(eventType: 'verifyProgress', callback: UpdateProgressCallback): void;|Added|    -|
|Update Subsystem - Updater|verifyUpdatePackage(upgradeFile: string, certsFile: string): void;|Added|    -|
|Update Subsystem - Updater|setUpdatePolicy(policy: UpdatePolicy): Promise\<number>;|Added|    -|
|Update Subsystem - Updater|rebootAndCleanCache(callback: AsyncCallback\<number>): void;|Added|    -|
|Update Subsystem - Updater|applyNewVersion(): Promise\<number>;|Added|    -|
|Globalization Subsystem - I18n|getSystemLanguages(): Array\<string>;|Added|    -|
|Globalization Subsystem - I18n|getSystemCountries(language: string): Array\<string>;|Added|    -|
|Globalization Subsystem - I18n|isSuggested(language: string, region?: string): boolean;|Added|    -|
|Globalization Subsystem - I18n|getSystemLanguage(): string;|Added|    -|
|Globalization Subsystem - I18n|setSystemLanguage(language: string);|Added|    -|
|Globalization Subsystem - I18n|getSystemRegion(): string;|Added|    -|
|Globalization Subsystem - I18n|setSystemRegion(region: string);|Added|    -|
|Globalization Subsystem - I18n|"getDisplayCountry(locale: string, displayLocale: string,sentenceCase?: boolean): string;"|Added|    -|
|Globalization Subsystem - I18n|getSystemLocale(): string;|Added|    -|
|Globalization Subsystem - I18n|setSystemLocale(locale: string);|Added|    -|
|Globalization Subsystem - I18n|"getDisplayLanguage(locale: string, displayLocale: string,sentenceCase?: boolean): string;"|Added|    -|
|Telephony Subsystem - radio|getNetworkState(callback: AsyncCallback\<NetworkState>): void;<br>getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void;<br>getNetworkState(slotId?: number): Promise\<NetworkState>;|Added| -|
|Telephony Subsystem - sim|getSimAccountInfo(slotId: number, callback: AsyncCallback\<IccAccountInfo>): void;<br>getSimAccountInfo(slotId: number): Promise\<IccAccountInfo>;|Added| -|
|Telephony Subsystem - sim|getDefaultVoiceSlotId(callback: AsyncCallback\<number>): void;<br>getDefaultVoiceSlotId(): Promise\<number>;|Added| -|
|Telephony Subsystem - sim|getSimSpn(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimSpn(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void;<br>getISOCountryCodeForSim(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getSimIccId(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimIccId(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getSimGid1(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimGid1(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void;<br>getISOCountryCodeForSim(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getSimOperatorNumeric(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimOperatorNumeric(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getSimSpn(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimSpn(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getSimIccId(slotId: number, callback: AsyncCallback\<string>): void;<br>getSimIccId(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sim|getIMSI(slotId: number, callback: AsyncCallback\<string>): void;<br>getIMSI(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - call|combineConference(callId: number, callback: AsyncCallback\<void>): void;<br>combineConference(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|startDTMF(callId: number, character: string, callback: AsyncCallback\<void>): void;<br>startDTMF(callId: number, character: string): Promise\<void>;|Added| -|
|Telephony Subsystem - call|stopDTMF(callId: number, callback: AsyncCallback\<void>): void;<br>stopDTMF(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - sim|setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>setDefaultVoiceSlotId(slotId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - sim|unlockPin(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>unlockPin(slotId: number, pin: string): Promise\<LockStatusResponse>;|Added| -|
|Telephony Subsystem - sim|alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br>alterPin(slotId: number, newPin: string, oldPin: string): Promise\<LockStatusResponse>;|Added| -|
|Telephony Subsystem - sim|setLockState(slotId: number, pin: string, enable: number, callback: AsyncCallback\<LockStatusResponse>): void;<br>setLockState(slotId: number, pin: string, enable: number): Promise\<LockStatusResponse>;|Added| -|
|Telephony Subsystem - sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br>getSimState(slotId: number): Promise\<SimState>;|Added| -|
|Telephony Subsystem - sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br>getSimState(slotId: number): Promise\<SimState>;|Added| -|
|Telephony Subsystem - sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br>getSimState(slotId: number): Promise\<SimState>;|Added| -|
|Telephony Subsystem - sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br>getSimState(slotId: number): Promise\<SimState>;|Added| -|
|Telephony Subsystem - call|isEmergencyPhoneNumber(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br>isEmergencyPhoneNumber(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback\<boolean>): void;<br>isEmergencyPhoneNumber(phoneNumber: string, options?: EmergencyNumberOptions): Promise\<boolean>;|Added| -|
|Telephony Subsystem - sms|createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void;<br>createMessage(pdu: Array\<number>, specification: string): Promise\<ShortMessage>;|Added| -|
|Telephony Subsystem - call|hasCall(callback: AsyncCallback\<boolean>): void;<br>hasCall(): Promise\<boolean>;|Added| -|
|Telephony Subsystem - sms|sendMessage(options: SendMessageOptions): void;|Added| -|
|Telephony Subsystem - call|dial(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br>dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean>): void;<br>dial(phoneNumber: string, options?: DialOptions): Promise\<boolean>;|Added| -|
|Telephony Subsystem - call|interface DialOptions {extras?: boolean;  }|Added| -|
|Telephony Subsystem - sms|sendMessage(options: SendMessageOptions): void;|Added| -|
|Telephony Subsystem - sms|getDefaultSmsSlotId(callback: AsyncCallback\<number>): void;<br>getDefaultSmsSlotId(): Promise\<number>;|Added| -|
|Telephony Subsystem - call|formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void;<br>formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void;<br>formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>;|Added| -|
|Telephony Subsystem - call|formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void;<br>formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void;<br>formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>;|Added| -|
|Telephony Subsystem - call|formatPhoneNumberToE164(phoneNumber: string, countryCode: string, callback: AsyncCallback\<string>): void;<br>formatPhoneNumberToE164(phoneNumber: string, countryCode: string): Promise\<string>;|Added| -|
|Telephony Subsystem - sms|setDefaultSmsSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br>setDefaultSmsSlotId(slotId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|getCallState(callback: AsyncCallback\<CallState>): void;<br>getCallState(): Promise\<CallState>;|Added| -|
|Telephony Subsystem - sms|setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void>): void;<br>setSmscAddr(slotId: number, smscAddr: string): Promise\<void>;|Added| -|
|Telephony Subsystem - sms|getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void;<br>getSmscAddr(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sms|addSimMessage(options: SimMessageOptions, callback: AsyncCallback\<void>): void;<br>addSimMessage(options: SimMessageOptions): Promise\<void>;|Added| -|
|Telephony Subsystem - sms|delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback\<void>): void;<br>delSimMessage(slotId: number, msgIndex: number): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void;<br>getISOCountryCodeForNetwork(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sms|updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback\<void>): void;<br>updateSimMessage(options: UpdateSimMessageOptions): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void;<br>getISOCountryCodeForNetwork(slotId: number): Promise\<string>;|Added| -|
|Telephony Subsystem - sms|getAllSimMessages(slotId: number, callback: AsyncCallback\<Array\<SimShortMessage>>): void;<br>getAllSimMessages(slotId: number): Promise\<Array\<SimShortMessage>>;|Added| -|
|Telephony Subsystem - call|isInEmergencyCall(callback: AsyncCallback\<boolean>): void;<br>isInEmergencyCall(): Promise\<boolean>;|Added| -|
|Telephony Subsystem - sms|setCBConfig(options: CBConfigOptions, callback: AsyncCallback\<void>): void;<br>setCBConfig(options: CBConfigOptions): Promise\<void>;|Added| -|
|Telephony Subsystem - call|answer(callId: number, callback: AsyncCallback\<void>): void;<br>answer(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|hangup(callId: number, callback: AsyncCallback\<void>): void;<br>hangup(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|reject(callId: number, callback: AsyncCallback\<void>): void;<br>reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void>): void;<br>reject(callId: number, options?: RejectMessageOptions): Promise\<void>;|Added| -|
|Telephony Subsystem - call|holdCall(callId: number, callback: AsyncCallback\<void>): void;<br>holdCall(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|unHoldCall(callId: number, callback: AsyncCallback\<void>): void;<br>unHoldCall(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - call|switchCall(callId: number, callback: AsyncCallback\<void>): void;<br>switchCall(callId: number): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|setNetworkSelectionMode(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void>): void;<br>setNetworkSelectionMode(options: NetworkSelectionModeOptions): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|getNetworkSearchInformation(slotId: number, callback: AsyncCallback\<NetworkSearchResult>): void;<br>getNetworkSearchInformation(slotId: number): Promise\<NetworkSearchResult>;|Added| -|
|Telephony Subsystem - radio|getNetworkSelectionMode(slotId: number, callback: AsyncCallback\<NetworkSelectionMode>): void;<br>getNetworkSelectionMode(slotId: number): Promise\<NetworkSelectionMode>;|Added| -|
|Telephony Subsystem - radio|isRadioOn(callback: AsyncCallback\<boolean>): void;<br>isRadioOn(): Promise\<boolean>;|Added| -|
|Telephony Subsystem - radio|turnOnRadio(callback: AsyncCallback\<void>): void;<br>turnOnRadio(): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|turnOffRadio(callback: AsyncCallback\<void>): void;<br>turnOffRadio(): Promise\<void>;|Added| -|
|Telephony Subsystem - radio|getSignalInformation(slotId: number, callback: AsyncCallback\<Array\<SignalInformation>>): void;<br>getSignalInformation(slotId: number): Promise\<Array\<SignalInformation>>;|Added| -|
|Telephony Subsystem - radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|Added| -|
|Telephony Subsystem - radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|Added| -|
|Telephony Subsystem - radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|Added| -|
|Data Management - distributeddata|put(key:string, value:Uint8Array / string / boolean / number, callback: AsyncCallback\<void>):void put(key:string, value:Uint8Array / string / boolean / number):Promise\<void>|Added| -|
|Data Management - distributeddata|delete(key: string, callback: AsyncCallback\<void>): void delete(key: string): Promise\<void>|Added| -|
|Data Management - distributeddata|on(event:'dataChange', subType: SubscribeType, observer: Callback\<ChangeNotification>): void|Added| -|
|Data Management - distributeddata|get(key:string, callback:AsyncCallback\<Uint8Array / string / boolean / number>):void get(key:string):Promise\<Uint8Array / string / boolean / number>|Added| -|
|Data Management - distributeddata|sync(deviceIdList:string[], mode:SyncMode, allowedDelayMs?:number):void|Added| -|
|Data Management - distributeddata|createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager>): void;<br>createKVManager(config: KVManagerConfig): Promise\<KVManager>;|Added| -|
|Data Management - distributeddata|getKVStore\<T extends KVStore>(options: Options, storeId: string): Promise\<T>;<br>getKVStore\<T extends KVStore>(options: Options, storeId: string, callback: AsyncCallback\<T>): void;|Added| -|
|Data Management - distributeddata|on(event:'syncComplete', syncCallback: Callback\<Array\<[string, number]>>):void|Added| -|
|Data Management - rdb|type ValueType = number / string / boolean;|Added| -|
|Data Management - rdb|type ValuesBucket = { [key: string]: ValueType / Uint8Array / null; }|Added| -|
|Data Management - rdb|name: string;|Added| -|
|Data Management - rdb|constructor(name: string)|Added| -|
|Data Management - rdb|equalTo(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|notEqualTo(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|beginWrap(): RdbPredicates;|Added| -|
|Data Management - rdb|endWrap(): RdbPredicates;|Added| -|
|Data Management - rdb|getRdbStore(config: StoreConfig, version: number, callback: AsyncCallback\<RdbStore>): void;<br>getRdbStore(config: StoreConfig, version: number): Promise\<RdbStore>;|Added| -|
|Data Management - rdb|deleteRdbStore(name: string, callback: AsyncCallback\<void>): void;<br>deleteRdbStore(name: string): Promise\<void>;|Added| -|
|Data Management - rdb|insert(name: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br>insert(name: string, values: ValuesBucket): Promise\<number>;|Added| -|
|Data Management - rdb|update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>update(values: ValuesBucket, rdbPredicates: RdbPredicates): Promise\<number>;|Added| -|
|Data Management - rdb|delete(rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br>delete(rdbPredicates: RdbPredicates): Promise\<number>;|Added| -|
|Data Management - rdb|query(rdbPredicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br>query(rdbPredicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>;|Added| -|
|Data Management - rdb|executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br>executeSql(sql: string, bindArgs: Array\<ValueType>): Promise\<void>;|Added| -|
|Data Management - rdb|like(field: string, value: string): RdbPredicates;|Added| -|
|Data Management - rdb|glob(field: string, value: string): RdbPredicates;|Added| -|
|Data Management - rdb|between(field: string, low: ValueType, high: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|greaterThan(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|lessThan(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|Added| -|
|Data Management - rdb|or(): RdbPredicates;|Added| -|
|Data Management - rdb|and(): RdbPredicates;|Added| -|
|Data Management - rdb|contains(field: string, value: string): RdbPredicates;|Added| -|
|Data Management - rdb|beginsWith(field: string, value: string): RdbPredicates;|Added| -|
|Data Management - rdb|endsWith(field: string, value: string): RdbPredicates;|Added| -|
|Data Management - rdb|isNull(field: string): RdbPredicates;|Added| -|
|Data Management - rdb|isNotNull(field: string): RdbPredicates;|Added| -|
|Data Management - rdb|isEnded: boolean;|Added| -|
|Data Management - rdb|isStarted: boolean;|Added| -|
|Data Management - rdb|isClosed: boolean;|Added| -|
|Data Management - rdb|getColumnIndex(columnName: string): number;|Added| -|
|Data Management - rdb|getColumnName(columnIndex: number): string;|Added| -|
|Data Management - rdb|goTo(offset: number): boolean;|Added| -|
|Data Management - rdb|goToRow(position: number): boolean;|Added| -|
|Data Management - rdb|goToFirstRow(): boolean;|Added| -|
|Data Management - rdb|goToLastRow(): boolean;|Added| -|
|Data Management - rdb|goToNextRow(): boolean;|Added| -|
|Data Management - rdb|goToPreviousRow(): boolean;|Added| -|
|Data Management - rdb|getBlob(columnIndex: number): Uint8Array;|Added| -|
|Data Management - rdb|getString(columnIndex: number): string;|Added| -|
|Data Management - rdb|getLong(columnIndex: number): number;|Added| -|
|Data Management - rdb|getDouble(columnIndex: number): number;|Added| -|
|Data Management - dataAbility|orderByDesc(field: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|distinct(): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|limitAs(value: number): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|offsetAs(rowOffset: number): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|groupBy(fields: Array\<string>): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|indexedBy(field: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|in(field: string, value: Array\<ValueType>): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|notIn(field: string, value: Array\<ValueType>): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|glob(field: string, value: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|greaterThan(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|lessThan(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|orderByAsc(field: string): DataAbilityPredicates;|Added| -|
|Data Management - rdb|isColumnNull(columnIndex: number): boolean;|Added| -|
|Data Management - rdb|close(): void;|Added| -|
|Data Management - dataAbility|createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates;|Added| -|
|Data Management - dataAbility|equalTo(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|notEqualTo(field: string, value: ValueType): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|beginWrap():DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|endWrap(): DataAbilityPredicates;|Added| -|
|Data Management - rdb|orderByAsc(field: string): RdbPredicates;|Added| -|
|Data Management - rdb|orderByDesc(field: string): RdbPredicates;|Added| -|
|Data Management - rdb|distinct(): RdbPredicates;|Added| -|
|Data Management - rdb|limitAs(value: number): RdbPredicates;|Added| -|
|Data Management - rdb|offsetAs(rowOffset: number): RdbPredicates;|Added| -|
|Data Management - rdb|groupBy(fields: Array\<string>): RdbPredicates;|Added| -|
|Data Management - rdb|indexedBy(field: string): RdbPredicates;|Added| -|
|Data Management - dataAbility|or(): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|and(): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|contains(field: string, value: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|beginsWith(field: string, value: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|endsWith(field: string, value: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|isNull(field: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|isNotNull(field: string): DataAbilityPredicates;|Added| -|
|Data Management - dataAbility|like(field: string, value: string): DataAbilityPredicates;|Added| -|
|Data Management - rdb|in(field: string, value: Array\<ValueType>): RdbPredicates;|Added| -|
|Data Management - rdb|notIn(field: string, value: Array\<ValueType>): RdbPredicates;|Added| -|
|Data Management - rdb|columnNames: Array\<string>;|Added| -|
|Data Management - rdb|columnCount: number;|Added| -|
|Data Management - rdb|rowCount: number;|Added| -|
|Data Management - rdb|rowIndex: number;|Added| -|
|Data Management - rdb|isAtFirstRow: boolean;|Added| -|
|Data Management - rdb|isAtLastRow: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|title: string;|Added| -|
|Common Event and Notification Subsystem - notification|sound?: string;|Added| -|
|Common Event and Notification Subsystem - notification|text: string;|Added| -|
|Common Event and Notification Subsystem - notification|vibrationValues?: Array\<number>;|Added| -|
|Common Event and Notification Subsystem - wantAgent|want?: Want;|Added| -|
|Common Event and Notification Subsystem - notification|vibrationEnabled?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|badgeFlag?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|type: notification.SlotType;|Added| -|
|Common Event and Notification Subsystem - wantAgent|code: number;|Added| -|
|Common Event and Notification Subsystem - notification|contentType: ContentType;|Added| -|
|Common Event and Notification Subsystem - notification|picture: image.PixelMap;|Added| -|
|Common Event and Notification Subsystem - notification|briefText: string;|Added| -|
|Common Event and Notification Subsystem - notification|briefText: string;|Added| -|
|Common Event and Notification Subsystem - notification|briefText: string;|Added| -|
|Common Event and Notification Subsystem - notification|bypassDnd?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|additionalText?: string;|Added| -|
|Common Event and Notification Subsystem - wantAgent|cancel(info: WantAgentInfo, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - wantAgent|enum OperationType|Added| -|
|Common Event and Notification Subsystem - wantAgent|enum WantAgentFlags|Added| -|
|Common Event and Notification Subsystem - wantAgent|permission?: string;|Added| -|
|Common Event and Notification Subsystem - notification|picture?: NotificationPictureContent;|Added| -|
|Common Event and Notification Subsystem - notification|normal?: NotificationBasicContent;|Added| -|
|Common Event and Notification Subsystem - notification|expandedTitle: string;|Added| -|
|Common Event and Notification Subsystem - notification|expandedTitle: string;|Added| -|
|Common Event and Notification Subsystem - wantAgent|trigger(info: WantAgentInfo, triggerInfo: TriggerInfo, callback: AsyncCallback\<CompleteData>): void;|Added| -|
|Common Event and Notification Subsystem - wantAgent|extraInfo?: {[key: string]: any};|Added| -|
|Common Event and Notification Subsystem - notification|multiLine?: NotificationMultiLineContent;|Added| -|
|Common Event and Notification Subsystem - notification|level?: notification.SlotLevel;|Added| -|
|Common Event and Notification Subsystem - notification|lightColor?: number;|Added| -|
|Common Event and Notification Subsystem - notification|lightEnabled?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|lines: Array\<string>;|Added| -|
|Common Event and Notification Subsystem - notification|lockscreenVisibility?: number;|Added| -|
|Common Event and Notification Subsystem - notification|longText: string;|Added| -|
|Common Event and Notification Subsystem - wantAgent|getBundleName(info: WantAgentInfo, callback: AsyncCallback\<string>): void;|Added| -|
|Common Event and Notification Subsystem - notification|longText?: NotificationLongTextContent;|Added| -|
|Common Event and Notification Subsystem - notification|longTitle: string;|Added| -|
|Common Event and Notification Subsystem - wantAgent|judgeEquality(info: WantAgentInfo, info2: WantAgentInfo, callback: AsyncCallback\<boolean>): void;|Added| -|
|Common Event and Notification Subsystem - wantAgent|getUid(info: WantAgentInfo, callback: AsyncCallback\<number>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL = common.event.IVI_TEMPERATURE_ABNORMAL,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_VOLTAGE_RECOVERY = common.event.IVI_VOLTAGE_RECOVERY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_TEMPERATURE_RECOVERY = common.event.IVI_TEMPERATURE_RECOVERY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_ACTIVE = common.event.IVI_ACTIVE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USB_DEVICE_ATTACHED = usual.event.hardware.usb.action.USB_DEVICE_ATTACHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USB_DEVICE_DETACHED = usual.event.hardware.usb.action.USB_DEVICE_DETACHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_PAUSE = common.event.IVI_PAUSE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_STANDBY = common.event.IVI_STANDBY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_LASTMODE_SAVE = common.event.IVI_LASTMODE_SAVE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_VOLTAGE_ABNORMAL = common.event.IVI_VOLTAGE_ABNORMAL,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_HIGH_TEMPERATURE = common.event.IVI_HIGH_TEMPERATURE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_EXTREME_TEMPERATURE = common.event.IVI_EXTREME_TEMPERATURE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_UNMOUNTABLE = usual.event.data.DISK_UNMOUNTABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_EJECT = usual.event.data.DISK_EJECT,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED = usual.event.data.VISIBLE_ACCOUNTS_UPDATED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_ACCOUNT_DELETED = usual.event.data.ACCOUNT_DELETED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_FOUNDATION_READY = common.event.FOUNDATION_READY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_AIRPLANE_MODE_CHANGED = usual.event.AIRPLANE_MODE|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USB_ACCESSORY_ATTACHED = usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USB_ACCESSORY_DETACHED = usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_REMOVED = usual.event.data.DISK_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_UNMOUNTED = usual.event.data.DISK_UNMOUNTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_MOUNTED = usual.event.data.DISK_MOUNTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISK_BAD_REMOVAL = usual.event.data.DISK_BAD_REMOVAL,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = usual.event.nfc.action.RF_FIELD_OFF_DETECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DISCHARGING = usual.event.DISCHARGING,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_CHARGING = usual.event.CHARGING,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = usual.event.DEVICE_IDLE_MODE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_POWER_SAVE_MODE_CHANGED = usual.event.POWER_SAVE_MODE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_ADDED = usual.event.USER_ADDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_REMOVED = usual.event.USER_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_ABILITY_ADDED = common.event.ABILITY_ADDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_ABILITY_REMOVED = common.event.ABILITY_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_ABILITY_UPDATED = common.event.ABILITY_UPDATED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_LOCATION_MODE_STATE_CHANGED = usual.event.location.MODE_STATE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_IVI_SLEEP = common.event.IVI_SLEEP,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE = usual.event.bluetooth.host.NAME_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE = usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE = usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = usual.event.nfc.action.ADAPTER_STATE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = usual.event.nfc.action.RF_FIELD_ON_DETECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE = usual.event.bluetooth.host.REQ_ENABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE = usual.event.bluetooth.host.REQ_DISABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE = usual.event.bluetooth.host.SCAN_MODE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED = usual.event.bluetooth.host.DISCOVERY_STARTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED = usual.event.bluetooth.host.DISCOVERY_FINISHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_CONN_STATE = usual.event.wifi.p2p.CONN_STATE_CHANGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_STATE_CHANGED = usual.event.wifi.p2p.STATE_CHANGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = usual.event.wifi.p2p.DEVICES_CHANGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED = usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = usual.event.wifi.p2p.GROUP_STATE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE = usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE = usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE = usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE = usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_RSSI_VALUE = usual.event.wifi.RSSI_VALUE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_CONN_STATE = usual.event.wifi.CONN_STATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_HOTSPOT_STATE = usual.event.wifi.HOTSPOT_STATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_AP_STA_JOIN = usual.event.wifi.WIFI_HS_STA_JOIN,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_AP_STA_LEAVE = usual.event.wifi.WIFI_HS_STA_LEAVE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = usual.event.wifi.mplink.STATE_CHANGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_HWID_LOGOUT = common.event.HWID_LOGOUT,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_HWID_TOKEN_INVALID = common.event.HWID_TOKEN_INVALID,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_HWID_LOGOFF = common.event.HWID_LOGOFF,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_POWER_STATE = usual.event.wifi.POWER_STATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_SCAN_FINISHED = usual.event.wifi.SCAN_FINISHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|clearAbortCommonEvent(): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|bundleName?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|code?: number;|Added| -|
|Common Event and Notification Subsystem - commonEvent|data?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|subscriberPermissions?: Array\<string>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|isOrdered?: boolean;|Added| -|
|Common Event and Notification Subsystem - commonEvent|isSticky?: boolean;|Added| -|
|Common Event and Notification Subsystem - commonEvent|abortCommonEvent(callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|abortCommonEvent(): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|isOrderedCommonEvent(): Promise\<boolean>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BOOT_COMPLETED = usual.event.BOOT_COMPLETED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_LOCKED_BOOT_COMPLETED = usual.event.LOCKED_BOOT_COMPLETED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_SHUTDOWN = usual.event.SHUTDOWN,|Added| -|
|Common Event and Notification Subsystem - commonEvent|isStickyCommonEvent(): Promise\<boolean>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|getData(callback: AsyncCallback\<string>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|getData(): Promise\<string>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|publish(event: string, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|event: string|Added| -|
|Common Event and Notification Subsystem - commonEvent|bundleName?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|code?: number;|Added| -|
|Common Event and Notification Subsystem - commonEvent|data?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|setCode(code: number, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DRIVE_MODE = common.event.DRIVE_MODE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_HOME_MODE = common.event.HOME_MODE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_OFFICE_MODE = common.event.OFFICE_MODE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_STARTED = usual.event.USER_STARTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_BACKGROUND = usual.event.USER_BACKGROUND,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_FOREGROUND = usual.event.USER_FOREGROUND,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_SWITCHED = usual.event.USER_SWITCHED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_STARTING = usual.event.USER_STARTING,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_UNLOCKED = usual.event.USER_UNLOCKED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_STOPPING = usual.event.USER_STOPPING,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_STOPPED = usual.event.USER_STOPPED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_HWID_LOGIN = common.event.HWID_LOGIN,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_VERIFIED = usual.event.PACKAGE_VERIFIED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE = usual.event.EXTERNAL_APPLICATIONS_AVAILABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE = usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_CONFIGURATION_CHANGED = usual.event.CONFIGURATION_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_LOCALE_CHANGED = usual.event.LOCALE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_MANAGE_PACKAGE_STORAGE = usual.event.MANAGE_PACKAGE_STORAGE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGES_UNSUSPENDED = usual.event.PACKAGES_UNSUSPENDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_MY_PACKAGE_SUSPENDED = usual.event.MY_PACKAGE_SUSPENDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = usual.event.MY_PACKAGE_UNSUSPENDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_UID_REMOVED = usual.event.UID_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_FIRST_LAUNCH = usual.event.PACKAGE_FIRST_LAUNCH,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION = usual.event.PACKAGE_NEEDS_VERIFICATION,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_SCREEN_OFF = usual.event.SCREEN_OFF,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_SCREEN_ON = usual.event.SCREEN_ON,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_USER_PRESENT = usual.event.USER_PRESENT,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_TIME_TICK = usual.event.TIME_TICK,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_TIME_CHANGED = usual.event.TIME_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_DATE_CHANGED = usual.event.DATE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BATTERY_CHANGED = usual.event.BATTERY_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BATTERY_LOW = usual.event.BATTERY_LOW,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BATTERY_OKAY = usual.event.BATTERY_OKAY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_POWER_CONNECTED = usual.event.POWER_CONNECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_POWER_DISCONNECTED = usual.event.POWER_DISCONNECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED = usual.event.bluetooth.remotedevice.ACL_CONNECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED = usual.event.bluetooth.remotedevice.ACL_DISCONNECTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|getAbortCommonEvent(callback: AsyncCallback\<boolean>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE = usual.event.bluetooth.remotedevice.NAME_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|getAbortCommonEvent(): Promise\<boolean>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE = usual.event.bluetooth.remotedevice.PAIR_STATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|getCode(callback: AsyncCallback\<number>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|setCode(code: number): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE = usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|getCode(): Promise\<number>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT = usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT,|Added| -|
|Common Event and Notification Subsystem - commonEvent|setCodeAndData(code: number, data: string, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT = usual.event.bluetooth.remotedevice.SDP_RESULT,|Added| -|
|Common Event and Notification Subsystem - commonEvent|isStickyCommonEvent(callback: AsyncCallback\<boolean>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|setCodeAndData(code: number, data: string): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|events: Array\<string>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE = usual.event.bluetooth.host.STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE = usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|setData(data: string, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE = usual.event.bluetooth.host.REQ_DISCOVERABLE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|publisherPermission?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|setData(data: string): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE = usual.event.bluetooth.remotedevice.UUID_VALUE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|publisherDeviceId?: string;|Added| -|
|Common Event and Notification Subsystem - commonEvent|clearAbortCommonEvent(callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - commonEvent|userId?: number;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_TIMEZONE_CHANGED = usual.event.TIMEZONE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ = usual.event.bluetooth.remotedevice.PAIRING_REQ,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED = usual.event.bluetooth.remotedevice.DISCOVERED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|priority?: number;|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BUNDLE_REMOVED = usual.event.BUNDLE_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE = usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL = usual.event.bluetooth.remotedevice.PAIRING_CANCEL,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_CLOSE_SYSTEM_DIALOGS = usual.event.CLOSE_SYSTEM_DIALOGS,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_ADDED = usual.event.PACKAGE_ADDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ = usual.event.bluetooth.remotedevice.CONNECT_REQ,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_FULLY_REMOVED = usual.event.PACKAGE_FULLY_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_REPLACED = usual.event.PACKAGE_REPLACED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY = usual.event.bluetooth.remotedevice.CONNECT_REPLY,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_MY_PACKAGE_REPLACED = usual.event.MY_PACKAGE_REPLACED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_CHANGED = usual.event.PACKAGE_CHANGED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL = usual.event.bluetooth.remotedevice.CONNECT_CANCEL,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_REMOVED = usual.event.PACKAGE_REMOVED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_RESTARTED = usual.event.PACKAGE_RESTARTED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGE_DATA_CLEARED = usual.event.PACKAGE_DATA_CLEARED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_PACKAGES_SUSPENDED = usual.event.PACKAGES_SUSPENDED,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE = usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE,|Added| -|
|Common Event and Notification Subsystem - commonEvent|COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED = usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE,|Added| -|
|Common Event and Notification Subsystem - notification|LEVEL_NONE = 0,|Added| -|
|Common Event and Notification Subsystem - notification|LEVEL_MIN = 1,|Added| -|
|Common Event and Notification Subsystem - notification|LEVEL_LOW = 2,|Added| -|
|Common Event and Notification Subsystem - notification|LEVEL_DEFAULT = 3,|Added| -|
|Common Event and Notification Subsystem - notification|label?: string;|Added| -|
|Common Event and Notification Subsystem - notification|bundle: string;|Added| -|
|Common Event and Notification Subsystem - notification|uid?: number;|Added| -|
|Common Event and Notification Subsystem - notification|NOTIFICATION_CONTENT_MULTILINE,|Added| -|
|Common Event and Notification Subsystem - notification|UNKNOWN_TYPE = 0,|Added| -|
|Common Event and Notification Subsystem - notification|SOCIAL_COMMUNICATION = 1,|Added| -|
|Common Event and Notification Subsystem - notification|LEVEL_HIGH = 4,|Added| -|
|Common Event and Notification Subsystem - notification|NOTIFICATION_CONTENT_BASIC_TEXT,|Added| -|
|Common Event and Notification Subsystem - notification|NOTIFICATION_CONTENT_LONG_TEXT,|Added| -|
|Common Event and Notification Subsystem - notification|NOTIFICATION_CONTENT_PICTURE,|Added| -|
|Common Event and Notification Subsystem - notification|isFloatingIcon?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|label?: string;|Added| -|
|Common Event and Notification Subsystem - notification|badgeIconStyle?: number;|Added| -|
|Common Event and Notification Subsystem - notification|showDeliveryTime?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|isAlertOnce?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void;|Added| -|
|Common Event and Notification Subsystem - notification|isStopwatch?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|isCountDown?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|getActiveNotifications(): Promise\<Array\<NotificationRequest>>;|Added| -|
|Common Event and Notification Subsystem - notification|getActiveNotificationCount(callback: AsyncCallback\<number>): void;|Added| -|
|Common Event and Notification Subsystem - notification|readonly creatorUid?: number;|Added| -|
|Common Event and Notification Subsystem - notification|getActiveNotificationCount(): Promise\<number>;|Added| -|
|Common Event and Notification Subsystem - notification|readonly creatorPid?: number;|Added| -|
|Common Event and Notification Subsystem - notification|cancel(id: number, label?: string): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - notification|classification?: string;|Added| -|
|Common Event and Notification Subsystem - notification|readonly hashCode?: string;|Added| -|
|Common Event and Notification Subsystem - notification|cancelAll(callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|actionButtons?: Array\<NotificationActionButton>;|Added| -|
|Common Event and Notification Subsystem - notification|cancelAll(): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - notification|smallIcon?: image.PixelMap;|Added| -|
|Common Event and Notification Subsystem - notification|isUnremovable?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|largeIcon?: image.PixelMap;|Added| -|
|Common Event and Notification Subsystem - notification|deliveryTime?: number;|Added| -|
|Common Event and Notification Subsystem - notification|readonly creatorBundleName?: string;|Added| -|
|Common Event and Notification Subsystem - notification|tapDismissed?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|publish(request: NotificationRequest): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - notification|autoDeletedTime?: number;|Added| -|
|Common Event and Notification Subsystem - notification|cancel(id: number, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|content: NotificationContent;|Added| -|
|Common Event and Notification Subsystem - notification|wantAgent?: WantAgentInfo;|Added| -|
|Common Event and Notification Subsystem - notification|cancel(id: number, label: string, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot>): void;|Added| -|
|Common Event and Notification Subsystem - notification|extraInfo?: {[key: string]: any};|Added| -|
|Common Event and Notification Subsystem - notification|getSlot(slotType: SlotType): Promise\<NotificationSlot>;|Added| -|
|Common Event and Notification Subsystem - notification|SERVICE_INFORMATION = 2,|Added| -|
|Common Event and Notification Subsystem - notification|color?: number;|Added| -|
|Common Event and Notification Subsystem - notification|id?: number;|Added| -|
|Common Event and Notification Subsystem - notification|getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void;|Added| -|
|Common Event and Notification Subsystem - notification|CONTENT_INFORMATION = 3,|Added| -|
|Common Event and Notification Subsystem - notification|slotType?: notification.SlotType;|Added| -|
|Common Event and Notification Subsystem - notification|colorEnabled?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|OTHER_TYPES = 0xFFFF,|Added| -|
|Common Event and Notification Subsystem - notification|isOngoing?: boolean;|Added| -|
|Common Event and Notification Subsystem - notification|addSlot(type: SlotType, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|id: number;|Added| -|
|Common Event and Notification Subsystem - notification|addSlot(type: SlotType): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - notification|desc?: string;|Added| -|
|Common Event and Notification Subsystem - notification|publish(request: NotificationRequest, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|removeAllSlots(callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|removeAllSlots(): Promise\<void>;|Added| -|
|Common Event and Notification Subsystem - notification|getSlots(): Promise\<Array\<NotificationSlot>>;|Added| -|
|Common Event and Notification Subsystem - notification|removeSlot(slotType: SlotType, callback: AsyncCallback\<void>): void;|Added| -|
|Common Event and Notification Subsystem - notification|removeSlot(slotType: SlotType): Promise\<void>;|Added| -|
|Globalization Subsystem - resourceManager|getString(resId: number, callback: AsyncCallback\<string>);<br>getString(resId: number): Promise\<string>;|Added| -|
|Globalization Subsystem - resourceManager|getStringArray(resId: number, callback: AsyncCallback\<Array\<string>>);<br>getStringArray(resId: number): Promise\<Array\<string>>;|Added| -|
|Globalization Subsystem - resourceManager|getConfiguration(callback: AsyncCallback\<Configuration>);<br>getConfiguration(): Promise\<Configuration>;|Added| -|
|Globalization Subsystem - resourceManager|getDeviceCapability(callback: AsyncCallback\<DeviceCapability>);<br>getDeviceCapability(): Promise\<DeviceCapability>;|Added| -|
|Globalization Subsystem - resourceManager|getMedia(resId: number, callback: AsyncCallback\<Uint8Array>);<br>getMedia(resId: number): Promise\<Uint8Array>;<br>getMediaBase64(resId: number, callback: AsyncCallback\<string>);<br>getMediaBase64(resId: number): Promise\<string>;|Added| -|
|Globalization Subsystem - resourceManager|"getPluralString(resId: number, num: number, callback: AsyncCallback\<string>);<br>getPluralString(resId: number, num: number): Promise\<string>;"|Added| -|
|Globalization Subsystem - resourceManager|DeviceCapability|Added| -|
|Globalization Subsystem - resourceManager|"getMediaBase64(resId: number, callback: AsyncCallback\<Uint8Array>);<br>getMediaBase64(resId: number): Promise\<Uint9Array>;"|Added| -|
|Globalization Subsystem - resourceManager|"getResourceManager(callback: AsyncCallback\<ResourceManager>);<br>getResourceManager(bundleName: string, callback: AsyncCallback\<ResourceManager>);<br>getResourceManager(): Promise\<ResourceManager>;<br>getResourceManager(bundleName: string): Promise\<ResourceManager>;"|Added| -|
|Globalization Subsystem - resourceManager|DeviceType|Added| -|
|Globalization Subsystem - resourceManager|Direction|Added| -|
|Globalization Subsystem - resourceManager|Configuration|Added| -|
|Globalization Subsystem - resourceManager|ScreenDensity|Added| -|
|Globalization Subsystem - resourceManager|deviceType|Added| -|
|Globalization Subsystem - resourceManager|locale|Added| -|
|Globalization Subsystem - resourceManager|direction|Added| -|
|Globalization Subsystem - resourceManager|screenDensity|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const batterySOC: number;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const technology: string;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const isBatteryPresent: boolean;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const batteryTemperature: number;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const pluggedType: BatteryPluggedType;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const chargingStatus: BatteryChargeState;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const healthStatus: BatteryHealthState;|Added| -|
|Power Management Subsystem - batteryInfo|batteryInfo:const voltage: number;|Added| -|
|Power Management Subsystem - batteryInfo|BatteryChargeState:NONE|Added| -|
|Power Management Subsystem - batteryInfo|BatteryChargeState:DISABLE|Added| -|
|Power Management Subsystem - batteryInfo|BatteryChargeState:ENABLE,|Added| -|
|Power Management Subsystem - batteryInfo|BatteryChargeState:FULL|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:COLD|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:OVERHEAT|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:OVERVOLTAGE|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:DEAD|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:UNKNOWN|Added| -|
|Power Management Subsystem - batteryInfo|BatteryHealthState:GOOD|Added| -|
|Power Management Subsystem - batteryInfo|BatteryPluggedType:WIRELESS|Added| -|
|Power Management Subsystem - batteryInfo|BatteryPluggedType:NONE|Added| -|
|Power Management Subsystem - batteryInfo|BatteryPluggedType:AC|Added| -|
|Power Management Subsystem - batteryInfo|BatteryPluggedType:USB|Added| -|
|Power Management Subsystem - runningLock|RunningLock:unlock()|Added| -|
|Power Management Subsystem - runningLock|runningLock:isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void;|Added| -|
|Power Management Subsystem - runningLock|runningLock:createRunningLock(name: string, type: runningLockType): RunningLock|Added| -|
|Power Management Subsystem - runningLock|RunningLock:lock(timeout: number)|Added| -|
|Power Management Subsystem - runningLock|RunningLock:isUsed(): boolean|Added| -|
|Power Management Subsystem - runningLock|RunningLockType:BACKGROUND|Added| -|
|Power Management Subsystem - runningLock|RunningLockType:PROXIMITY_SCREEN_CONTROL|Added| -|
|Power Management Subsystem - power|power:rebootDevice(reason ?: string)|Added| -|
|Power Management Subsystem - power|power:isScreenOn(callback: AsyncCallback\<boolean>): void;|Added| -|
