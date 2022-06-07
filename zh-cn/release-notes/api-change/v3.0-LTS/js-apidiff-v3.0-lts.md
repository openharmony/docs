# JS API 差异报告
OpenHarmony 3.0 LTS相较于OpenHarmony 2.2 Beta2版本的API变更如下:
## 标准系统接口变更

| 模块名称  | 接口名称  | 变更类型  | 变更说明  |
|  --------  |  --------  |  --------  |  --------  |
|语言编译器运行时-worker|postMessage(obj):void|新增|宿主线程与worker通信，传递数据|
|语言编译器运行时-worker|postMessage(message: Object, options?: PostMessageOptions):void|新增|宿主线程与worker通信，转移arrayBuffer的数据控制权|
|语言编译器运行时-worker|terminate():void|新增|宿主线程主动停止worker|
|语言编译器运行时-worker|on(type: string, listener: EventListener): void|新增|向worker添加回调接口|
|语言编译器运行时-worker|once(type: string, listener: EventListener): void|新增|向worker添加回调接口，并且在回调一次会释放回调|
|语言编译器运行时-worker|off(type: string, listener?: EventListener): void|新增|删除worker已添加的回调接口|
|语言编译器运行时-worker|addEventListener(type: string, listener: EventListener): void|新增|向worker添加回调接口|
|语言编译器运行时-worker|removeEventListener(type: string, listener?: EventListener): void|新增|删除worker已添加的回调接口|
|语言编译器运行时-worker|removeAllListener(): void|新增|删除worker所有的回调接口|
|语言编译器运行时-worker|dispatchEvent(event: Event): boolean|新增|向worker发送指定事件，触发回调接口|
|语言编译器运行时-parentPort|postMessage(obj):void|新增|worker与宿主线程通信，传递数据|
|语言编译器运行时-parentPort|postMessage(message: Object, options?: PostMessageOptions):void|新增|worker与宿主线程通信，转移arrayBuffer的数据控制权|
|语言编译器运行时-parentPort|close(): void|新增|worker主动终止|
|语言编译器运行时-Util|printf(format: string, ...args: Object[]): string|新增|-|
|语言编译器运行时-Util|getErrorString(errno: number): string|新增|-|
|语言编译器运行时-Util|callbackWrapper(original: Function): (err: Object, value: Object) => void|新增|-|
|语言编译器运行时-Util|promiseWrapper(original: (err: Object, value: Object) => void): Object|新增|-|
|语言编译器运行时-Util|new TextDecoder([encoding[, options]])|新增|-|
|语言编译器运行时-Util|decode([input[, options]]):string|新增|-|
|语言编译器运行时-Util|new TextEncoder()|新增|-|
|语言编译器运行时-Util|encode(input?: string): Uint8Array;|新增|-|
|语言编译器运行时-Util|"encodeInto(input: string,dest: Uint8Array,): { read: number; written: number };"|新增|-|
|语言编译器运行时-Util|readonly encoding: string;|新增|-|
|语言编译器运行时-Util|readonly fatal: boolean;|新增|-|
|语言编译器运行时-Util|readonly ignoreBOM = false;|新增|-|
|语言编译器运行时-Util|readonly encoding = "utf-8";|新增|-|
|语言编译器运行时-URL|new URL(url: string, base?: string/URL)|新增|-|
|语言编译器运行时-URL|toString(): string;|新增|-|
|语言编译器运行时-URL|toJSON(): string;|新增|-|
|语言编译器运行时-URL|new URSearchParams()|新增|-|
|语言编译器运行时-URL|new URSearchParams(string)|新增|-|
|语言编译器运行时-URL|new URSearchParams(obj)|新增|-|
|语言编译器运行时-URL|new URSearchParams(iterable)|新增|-|
|语言编译器运行时-URL|append(name: string, value: string): void;|新增|-|
|语言编译器运行时-URL|delete(name: string): void;|新增|-|
|语言编译器运行时-URL|entries(): IterableIterator\<[string, string]>;|新增|-|
|语言编译器运行时-URL|forEach(callbackfn: (value: string, key: string, parent: this) => void, thisArg?: any,): void;|新增|-|
|语言编译器运行时-URL|get(name: string): string / null;|新增|-|
|语言编译器运行时-URL|getAll(name: string): string[];|新增|-|
|语言编译器运行时-URL|has(name: string): boolean;|新增|-|
|语言编译器运行时-URL|keys(): IterableIterator\<string>;|新增|-|
|语言编译器运行时-URL|set(name: string, value: string): void;|新增|-|
|语言编译器运行时-URL|sort():void;|新增|-|
|语言编译器运行时-URL|toString():string|新增|-|
|语言编译器运行时-URL|values(): IterableIterator\<string>;|新增|-|
|语言编译器运行时-URL|URSearchParams\[Symbol.iterator]()|新增|-|
|语言编译器运行时-URL|hash: string;|新增|-|
|语言编译器运行时-URL|host: string;|新增|-|
|语言编译器运行时-URL|hostname: string;|新增|-|
|语言编译器运行时-URL|href: string;|新增|-|
|语言编译器运行时-URL|readonly origin: string;|新增|-|
|语言编译器运行时-URL|password: string;|新增|-|
|语言编译器运行时-URL|pathname: string;|新增|-|
|语言编译器运行时-URL|port: string;|新增|-|
|语言编译器运行时-URL|protocol: string;|新增|-|
|语言编译器运行时-URL|search: string;|新增|-|
|语言编译器运行时-URL|readonly searchParams: URLSearchParams;|新增|-|
|语言编译器运行时-URL|username: string;|新增|-|
|语言编译器运行时-ChildProcess|readonly pid: number;|新增|-|
|语言编译器运行时-ChildProcess|readonly ppid: number;|新增|-|
|语言编译器运行时-ChildProcess|readonly exitCode: number;|新增|-|
|语言编译器运行时-ChildProcess|readonly killed: boolean;|新增|-|
|语言编译器运行时-ChildProcess|wait(): Promise\<number>;|新增|-|
|语言编译器运行时-ChildProcess|getOutput(): Promise\<Uint8Array>;|新增|-|
|语言编译器运行时-ChildProcess|getErrorOutput(): Promise\<Uint8Array>;|新增|-|
|语言编译器运行时-ChildProcess|close(): void;|新增|-|
|语言编译器运行时-ChildProcess|kill(signal: number): void;|新增|-|
|语言编译器运行时-process|runCmd(command: string,options?: { timeout : number, killSignal : number string, maxBuffer : number }): ChildProcess;|新增|-|
|语言编译器运行时-process|getPid(): number;|新增|-|
|语言编译器运行时-process|getPpid(): number;|新增|-|
|语言编译器运行时-process|abort(): void;|新增|-|
|语言编译器运行时-process|on(type: string, listener: EventListener): void;|新增|-|
|语言编译器运行时-process|exit(code?:number): void;|新增|-|
|语言编译器运行时-process|cwd(): string;|新增|-|
|语言编译器运行时-process|chdir(dir: string): void;|新增|-|
|语言编译器运行时-process|getEgid(): number;|新增|-|
|语言编译器运行时-process|getEuid(): number;|新增|-|
|语言编译器运行时-process|getGid(): number|新增|-|
|语言编译器运行时-process|getUid(): number;|新增|-|
|语言编译器运行时-process|uptime(): number;|新增|-|
|语言编译器运行时-process|getGroups(): number[];|新增|-|
|语言编译器运行时-process|kill(signal?: number, pid?: number): boolean;|新增|-|
|升级服务子系统-Updater|checkNewVersion(): Promise\<NewVersionInfo>;|新增|    -|
|升级服务子系统-Updater|rebootAndCleanUserData(callback: AsyncCallback\<number>): void;|新增|    -|
|升级服务子系统-Updater|rebootAndCleanCache(): Promise\<number>;|新增|    -|
|升级服务子系统-Updater|getUpdaterFromOther(device: string, updateType?: UpdateTypes): Updater;|新增|    -|
|升级服务子系统-Updater|cancel(): void;|新增|    -|
|升级服务子系统-Updater|upgrade(): void;|新增|    -|
|升级服务子系统-Updater|off(eventType: 'downloadProgress', callback?: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;|新增|    -|
|升级服务子系统-Updater|getUpdaterForOther(device: string, updateType?: UpdateTypes): Updater;|新增|    -|
|升级服务子系统-Updater|setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;|新增|    -|
|升级服务子系统-Updater|getNewVersionInfo(): Promise\<NewVersionInfo>;|新增|    -|
|升级服务子系统-Updater|getUpdater(updateType?: UpdateTypes): Updater;|新增|    -|
|升级服务子系统-Updater|applyNewVersion(callback: AsyncCallback\<number>): void;|新增|    -|
|升级服务子系统-Updater|rebootAndCleanUserData(): Promise\<number>;|新增|    -|
|升级服务子系统-Updater|off(eventType: 'verifyProgress', callback?: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|on(eventType: 'upgradeProgress', callback: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void;|新增|    -|
|升级服务子系统-Updater|on(eventType: 'downloadProgress', callback: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|getUpdatePolicy(): Promise\<UpdatePolicy>;|新增|    -|
|升级服务子系统-Updater|download(): void;|新增|    -|
|升级服务子系统-Updater|off(eventType: 'upgradeProgress', callback?: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;|新增|    -|
|升级服务子系统-Updater|on(eventType: 'verifyProgress', callback: UpdateProgressCallback): void;|新增|    -|
|升级服务子系统-Updater|verifyUpdatePackage(upgradeFile: string, certsFile: string): void;|新增|    -|
|升级服务子系统-Updater|setUpdatePolicy(policy: UpdatePolicy): Promise\<number>;|新增|    -|
|升级服务子系统-Updater|rebootAndCleanCache(callback: AsyncCallback\<number>): void;|新增|    -|
|升级服务子系统-Updater|applyNewVersion(): Promise\<number>;|新增|    -|
|全球化子系统-I18n|getSystemLanguages(): Array\<string>;|新增|    -|
|全球化子系统-I18n|getSystemCountries(language: string): Array\<string>;|新增|    -|
|全球化子系统-I18n|isSuggested(language: string, region?: string): boolean;|新增|    -|
|全球化子系统-I18n|getSystemLanguage(): string;|新增|    -|
|全球化子系统-I18n|setSystemLanguage(language: string);|新增|    -|
|全球化子系统-I18n|getSystemRegion(): string;|新增|    -|
|全球化子系统-I18n|setSystemRegion(region: string);|新增|    -|
|全球化子系统-I18n|"getDisplayCountry(locale: string, displayLocale: string,sentenceCase?: boolean): string;"|新增|    -|
|全球化子系统-I18n|getSystemLocale(): string;|新增|    -|
|全球化子系统-I18n|setSystemLocale(locale: string);|新增|    -|
|全球化子系统-I18n|"getDisplayLanguage(locale: string, displayLocale: string,sentenceCase?: boolean): string;"|新增|    -|
|电话子系统-radio|getNetworkState(callback: AsyncCallback\<NetworkState>): void;<br>getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void;<br>getNetworkState(slotId?: number): Promise\<NetworkState>;|新增| -|
|电话子系统-sim|getSimAccountInfo(slotId: number, callback: AsyncCallback\<IccAccountInfo>): void;<br>getSimAccountInfo(slotId: number): Promise\<IccAccountInfo>;|新增| -|
|电话子系统-sim|getDefaultVoiceSlotId(callback: AsyncCallback\<number>): void;<br/>getDefaultVoiceSlotId(): Promise\<number>;|新增| -|
|电话子系统-sim|getSimSpn(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimSpn(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void;<br/>getISOCountryCodeForSim(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getSimIccId(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimIccId(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getSimGid1(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimGid1(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void;<br/>getISOCountryCodeForSim(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getSimOperatorNumeric(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimOperatorNumeric(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getSimSpn(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimSpn(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getSimIccId(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSimIccId(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sim|getIMSI(slotId: number, callback: AsyncCallback\<string>): void;<br/>getIMSI(slotId: number): Promise\<string>;|新增| -|
|电话子系统-call|combineConference(callId: number, callback: AsyncCallback\<void>): void;<br/>combineConference(callId: number): Promise\<void>;|新增| -|
|电话子系统-call|startDTMF(callId: number, character: string, callback: AsyncCallback\<void>): void;<br/>startDTMF(callId: number, character: string): Promise\<void>;|新增| -|
|电话子系统-call|stopDTMF(callId: number, callback: AsyncCallback\<void>): void;<br/>stopDTMF(callId: number): Promise\<void>;|新增| -|
|电话子系统-sim|setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br/>setDefaultVoiceSlotId(slotId: number): Promise\<void>;|新增| -|
|电话子系统-sim|unlockPin(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br/>unlockPin(slotId: number, pin: string): Promise\<LockStatusResponse>;|新增| -|
|电话子系统-sim|alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse>): void;<br/>alterPin(slotId: number, newPin: string, oldPin: string): Promise\<LockStatusResponse>;|新增| -|
|电话子系统-sim|setLockState(slotId: number, pin: string, enable: number, callback: AsyncCallback\<LockStatusResponse>): void;<br/>setLockState(slotId: number, pin: string, enable: number): Promise\<LockStatusResponse>;|新增| -|
|电话子系统-sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br/>getSimState(slotId: number): Promise\<SimState>;|新增| -|
|电话子系统-sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br/>getSimState(slotId: number): Promise\<SimState>;|新增| -|
|电话子系统-sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br/>getSimState(slotId: number): Promise\<SimState>;|新增| -|
|电话子系统-sim|getSimState(slotId: number, callback: AsyncCallback\<SimState>): void;<br/>getSimState(slotId: number): Promise\<SimState>;|新增| -|
|电话子系统-call|isEmergencyPhoneNumber(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br/>isEmergencyPhoneNumber(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback\<boolean>): void;<br/>isEmergencyPhoneNumber(phoneNumber: string, options?: EmergencyNumberOptions): Promise\<boolean>;|新增| -|
|电话子系统-sms|createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void;<br/>createMessage(pdu: Array\<number>, specification: string): Promise\<ShortMessage>;|新增| -|
|电话子系统-call|hasCall(callback: AsyncCallback\<boolean>): void;<br/>hasCall(): Promise\<boolean>;|新增| -|
|电话子系统-sms|sendMessage(options: SendMessageOptions): void;|新增| -|
|电话子系统-call|dial(phoneNumber: string, callback: AsyncCallback\<boolean>): void;<br/>dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean>): void;<br/>dial(phoneNumber: string, options?: DialOptions): Promise\<boolean>;|新增| -|
|电话子系统-call|interface DialOptions {extras?: boolean;  }|新增| -|
|电话子系统-sms|sendMessage(options: SendMessageOptions): void;|新增| -|
|电话子系统-sms|getDefaultSmsSlotId(callback: AsyncCallback\<number>): void;<br/>getDefaultSmsSlotId(): Promise\<number>;|新增| -|
|电话子系统-call|formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void;<br/>formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void;<br/>formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>;|新增| -|
|电话子系统-call|formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void;<br/>formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void;<br/>formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>;|新增| -|
|电话子系统-call|formatPhoneNumberToE164(phoneNumber: string, countryCode: string, callback: AsyncCallback\<string>): void;<br/>formatPhoneNumberToE164(phoneNumber: string, countryCode: string): Promise\<string>;|新增| -|
|电话子系统-sms|setDefaultSmsSlotId(slotId: number, callback: AsyncCallback\<void>): void;<br/>setDefaultSmsSlotId(slotId: number): Promise\<void>;|新增| -|
|电话子系统-call|getCallState(callback: AsyncCallback\<CallState>): void;<br/>getCallState(): Promise\<CallState>;|新增| -|
|电话子系统-sms|setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void>): void;<br/>setSmscAddr(slotId: number, smscAddr: string): Promise\<void>;|新增| -|
|电话子系统-sms|getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void;<br/>getSmscAddr(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sms|addSimMessage(options: SimMessageOptions, callback: AsyncCallback\<void>): void;<br/>addSimMessage(options: SimMessageOptions): Promise\<void>;|新增| -|
|电话子系统-sms|delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback\<void>): void;<br/>delSimMessage(slotId: number, msgIndex: number): Promise\<void>;|新增| -|
|电话子系统-radio|getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void;<br/>getISOCountryCodeForNetwork(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sms|updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback\<void>): void;<br/>updateSimMessage(options: UpdateSimMessageOptions): Promise\<void>;|新增| -|
|电话子系统-radio|getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void;<br/>getISOCountryCodeForNetwork(slotId: number): Promise\<string>;|新增| -|
|电话子系统-sms|getAllSimMessages(slotId: number, callback: AsyncCallback\<Array\<SimShortMessage>>): void;<br/>getAllSimMessages(slotId: number): Promise\<Array\<SimShortMessage>>;|新增| -|
|电话子系统-call|isInEmergencyCall(callback: AsyncCallback\<boolean>): void;<br/>isInEmergencyCall(): Promise\<boolean>;|新增| -|
|电话子系统-sms|setCBConfig(options: CBConfigOptions, callback: AsyncCallback\<void>): void;<br/>setCBConfig(options: CBConfigOptions): Promise\<void>;|新增| -|
|电话子系统-call|answer(callId: number, callback: AsyncCallback\<void>): void;<br/>answer(callId: number): Promise\<void>;|新增| -|
|电话子系统-call|hangup(callId: number, callback: AsyncCallback\<void>): void;<br/>hangup(callId: number): Promise\<void>;|新增| -|
|电话子系统-call|reject(callId: number, callback: AsyncCallback\<void>): void;<br/>reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void>): void;<br/>reject(callId: number, options?: RejectMessageOptions): Promise\<void>;|新增| -|
|电话子系统-call|holdCall(callId: number, callback: AsyncCallback\<void>): void;<br/>holdCall(callId: number): Promise\<void>;|新增| -|
|电话子系统-call|unHoldCall(callId: number, callback: AsyncCallback\<void>): void;<br/>unHoldCall(callId: number): Promise\<void>;|新增| -|
|电话子系统-call|switchCall(callId: number, callback: AsyncCallback\<void>): void;<br/>switchCall(callId: number): Promise\<void>;|新增| -|
|电话子系统-radio|setNetworkSelectionMode(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void>): void;<br/>setNetworkSelectionMode(options: NetworkSelectionModeOptions): Promise\<void>;|新增| -|
|电话子系统-radio|getNetworkSearchInformation(slotId: number, callback: AsyncCallback\<NetworkSearchResult>): void;<br/>getNetworkSearchInformation(slotId: number): Promise\<NetworkSearchResult>;|新增| -|
|电话子系统-radio|getNetworkSelectionMode(slotId: number, callback: AsyncCallback\<NetworkSelectionMode>): void;<br/>getNetworkSelectionMode(slotId: number): Promise\<NetworkSelectionMode>;|新增| -|
|电话子系统-radio|isRadioOn(callback: AsyncCallback\<boolean>): void;<br/>isRadioOn(): Promise\<boolean>;|新增| -|
|电话子系统-radio|turnOnRadio(callback: AsyncCallback\<void>): void;<br/>turnOnRadio(): Promise\<void>;|新增| -|
|电话子系统-radio|turnOffRadio(callback: AsyncCallback\<void>): void;<br/>turnOffRadio(): Promise\<void>;|新增| -|
|电话子系统-radio|getSignalInformation(slotId: number, callback: AsyncCallback\<Array\<SignalInformation>>): void;<br/>getSignalInformation(slotId: number): Promise\<Array\<SignalInformation>>;|新增| -|
|电话子系统-radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br/>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|新增| -|
|电话子系统-radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br/>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|新增| -|
|电话子系统-radio|getRadioTech(slotId: number, callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void;<br/>getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>;|新增| -|
|数据管理-distributeddata|put(key:string, value:Uint8Array / string / boolean / number, callback: AsyncCallback\<void>):void put(key:string, value:Uint8Array / string / boolean / number):Promise\<void>|新增| -|
|数据管理-distributeddata|delete(key: string, callback: AsyncCallback\<void>): void delete(key: string): Promise\<void>|新增| -|
|数据管理-distributeddata|on(event:'dataChange', subType: SubscribeType, observer: Callback\<ChangeNotification>): void|新增| -|
|数据管理-distributeddata|get(key:string, callback:AsyncCallback\<Uint8Array / string / boolean / number>):void get(key:string):Promise\<Uint8Array / string / boolean / number>|新增| -|
|数据管理-distributeddata|sync(deviceIdList:string[], mode:SyncMode, allowedDelayMs?:number):void|新增| -|
|数据管理-distributeddata|createKVManager(config: KVManagerConfig, callback: AsyncCallback\<KVManager>): void;<br/>createKVManager(config: KVManagerConfig): Promise\<KVManager>;|新增| -|
|数据管理-distributeddata|getKVStore\<T extends KVStore>(options: Options, storeId: string): Promise\<T>;<br/>getKVStore\<T extends KVStore>(options: Options, storeId: string, callback: AsyncCallback\<T>): void;|新增| -|
|数据管理-distributeddata|on(event:'syncComplete', syncCallback: Callback\<Array\<[string, number]>>):void|新增| -|
|数据管理-rdb|type ValueType = number / string / boolean;|新增| -|
|数据管理-rdb|type ValuesBucket = { [key: string]: ValueType / Uint8Array / null; }|新增| -|
|数据管理-rdb|name: string;|新增| -|
|数据管理-rdb|constructor(name: string)|新增| -|
|数据管理-rdb|equalTo(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|notEqualTo(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|beginWrap(): RdbPredicates;|新增| -|
|数据管理-rdb|endWrap(): RdbPredicates;|新增| -|
|数据管理-rdb|getRdbStore(config: StoreConfig, version: number, callback: AsyncCallback\<RdbStore>): void;<br/>getRdbStore(config: StoreConfig, version: number): Promise\<RdbStore>;|新增| -|
|数据管理-rdb|deleteRdbStore(name: string, callback: AsyncCallback\<void>): void;<br/>deleteRdbStore(name: string): Promise\<void>;|新增| -|
|数据管理-rdb|insert(name: string, values: ValuesBucket, callback: AsyncCallback\<number>): void;<br/>insert(name: string, values: ValuesBucket): Promise\<number>;|新增| -|
|数据管理-rdb|update(values: ValuesBucket, rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br/>update(values: ValuesBucket, rdbPredicates: RdbPredicates): Promise\<number>;|新增| -|
|数据管理-rdb|delete(rdbPredicates: RdbPredicates, callback: AsyncCallback\<number>): void;<br/>delete(rdbPredicates: RdbPredicates): Promise\<number>;|新增| -|
|数据管理-rdb|query(rdbPredicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void;<br/>query(rdbPredicates: RdbPredicates, columns: Array\<string>): Promise\<ResultSet>;|新增| -|
|数据管理-rdb|executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void;<br/>executeSql(sql: string, bindArgs: Array\<ValueType>): Promise\<void>;|新增| -|
|数据管理-rdb|like(field: string, value: string): RdbPredicates;|新增| -|
|数据管理-rdb|glob(field: string, value: string): RdbPredicates;|新增| -|
|数据管理-rdb|between(field: string, low: ValueType, high: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|greaterThan(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|lessThan(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates;|新增| -|
|数据管理-rdb|or(): RdbPredicates;|新增| -|
|数据管理-rdb|and(): RdbPredicates;|新增| -|
|数据管理-rdb|contains(field: string, value: string): RdbPredicates;|新增| -|
|数据管理-rdb|beginsWith(field: string, value: string): RdbPredicates;|新增| -|
|数据管理-rdb|endsWith(field: string, value: string): RdbPredicates;|新增| -|
|数据管理-rdb|isNull(field: string): RdbPredicates;|新增| -|
|数据管理-rdb|isNotNull(field: string): RdbPredicates;|新增| -|
|数据管理-rdb|isEnded: boolean;|新增| -|
|数据管理-rdb|isStarted: boolean;|新增| -|
|数据管理-rdb|isClosed: boolean;|新增| -|
|数据管理-rdb|getColumnIndex(columnName: string): number;|新增| -|
|数据管理-rdb|getColumnName(columnIndex: number): string;|新增| -|
|数据管理-rdb|goTo(offset: number): boolean;|新增| -|
|数据管理-rdb|goToRow(position: number): boolean;|新增| -|
|数据管理-rdb|goToFirstRow(): boolean;|新增| -|
|数据管理-rdb|goToLastRow(): boolean;|新增| -|
|数据管理-rdb|goToNextRow(): boolean;|新增| -|
|数据管理-rdb|goToPreviousRow(): boolean;|新增| -|
|数据管理-rdb|getBlob(columnIndex: number): Uint8Array;|新增| -|
|数据管理-rdb|getString(columnIndex: number): string;|新增| -|
|数据管理-rdb|getLong(columnIndex: number): number;|新增| -|
|数据管理-rdb|getDouble(columnIndex: number): number;|新增| -|
|数据管理-dataAbility|orderByDesc(field: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|distinct(): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|limitAs(value: number): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|offsetAs(rowOffset: number): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|groupBy(fields: Array\<string>): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|indexedBy(field: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|in(field: string, value: Array\<ValueType>): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|notIn(field: string, value: Array\<ValueType>): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|glob(field: string, value: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|between(field: string, low: ValueType, high: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|notBetween(field: string, low: ValueType, high: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|greaterThan(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|lessThan(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|greaterThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|lessThanOrEqualTo(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|orderByAsc(field: string): DataAbilityPredicates;|新增| -|
|数据管理-rdb|isColumnNull(columnIndex: number): boolean;|新增| -|
|数据管理-rdb|close(): void;|新增| -|
|数据管理-dataAbility|createRdbPredicates(name: string, dataAbilityPredicates: DataAbilityPredicates): rdb.RdbPredicates;|新增| -|
|数据管理-dataAbility|equalTo(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|notEqualTo(field: string, value: ValueType): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|beginWrap():DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|endWrap(): DataAbilityPredicates;|新增| -|
|数据管理-rdb|orderByAsc(field: string): RdbPredicates;|新增| -|
|数据管理-rdb|orderByDesc(field: string): RdbPredicates;|新增| -|
|数据管理-rdb|distinct(): RdbPredicates;|新增| -|
|数据管理-rdb|limitAs(value: number): RdbPredicates;|新增| -|
|数据管理-rdb|offsetAs(rowOffset: number): RdbPredicates;|新增| -|
|数据管理-rdb|groupBy(fields: Array\<string>): RdbPredicates;|新增| -|
|数据管理-rdb|indexedBy(field: string): RdbPredicates;|新增| -|
|数据管理-dataAbility|or(): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|and(): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|contains(field: string, value: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|beginsWith(field: string, value: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|endsWith(field: string, value: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|isNull(field: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|isNotNull(field: string): DataAbilityPredicates;|新增| -|
|数据管理-dataAbility|like(field: string, value: string): DataAbilityPredicates;|新增| -|
|数据管理-rdb|in(field: string, value: Array\<ValueType>): RdbPredicates;|新增| -|
|数据管理-rdb|notIn(field: string, value: Array\<ValueType>): RdbPredicates;|新增| -|
|数据管理-rdb|columnNames: Array\<string>;|新增| -|
|数据管理-rdb|columnCount: number;|新增| -|
|数据管理-rdb|rowCount: number;|新增| -|
|数据管理-rdb|rowIndex: number;|新增| -|
|数据管理-rdb|isAtFirstRow: boolean;|新增| -|
|数据管理-rdb|isAtLastRow: boolean;|新增| -|
|事件通知-notification|title: string;|新增| -|
|事件通知-notification|sound?: string;|新增| -|
|事件通知-notification|text: string;|新增| -|
|事件通知-notification|vibrationValues?: Array\<number>;|新增| -|
|事件通知-wantAgent|want?: Want;|新增| -|
|事件通知-notification|vibrationEnabled?: boolean;|新增| -|
|事件通知-notification|badgeFlag?: boolean;|新增| -|
|事件通知-notification|type: notification.SlotType;|新增| -|
|事件通知-wantAgent|code: number;|新增| -|
|事件通知-notification|contentType: ContentType;|新增| -|
|事件通知-notification|picture: image.PixelMap;|新增| -|
|事件通知-notification|briefText: string;|新增| -|
|事件通知-notification|briefText: string;|新增| -|
|事件通知-notification|briefText: string;|新增| -|
|事件通知-notification|bypassDnd?: boolean;|新增| -|
|事件通知-notification|additionalText?: string;|新增| -|
|事件通知-wantagent|cancel(info: WantAgentInfo, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-wantAgent|enum OperationType|新增| -|
|事件通知-wantAgent|enum WantAgentFlags|新增| -|
|事件通知-wantAgent|permission?: string;|新增| -|
|事件通知-notification|picture?: NotificationPictureContent;|新增| -|
|事件通知-notification|normal?: NotificationBasicContent;|新增| -|
|事件通知-notification|expandedTitle: string;|新增| -|
|事件通知-notification|expandedTitle: string;|新增| -|
|事件通知-wantAgent|trigger(info: WantAgentInfo, triggerInfo: TriggerInfo, callback: AsyncCallback\<CompleteData>): void;|新增| -|
|事件通知-wantAgent|extraInfo?: {[key: string]: any};|新增| -|
|事件通知-notification|multiLine?: NotificationMultiLineContent;|新增| -|
|事件通知-notification|level?: notification.SlotLevel;|新增| -|
|事件通知-notification|lightColor?: number;|新增| -|
|事件通知-notification|lightEnabled?: boolean;|新增| -|
|事件通知-notification|lines: Array\<string>;|新增| -|
|事件通知-notification|lockscreenVisibility?: number;|新增| -|
|事件通知-notification|longText: string;|新增| -|
|事件通知-wantAgent|getBundleName(info: WantAgentInfo, callback: AsyncCallback\<string>): void;|新增| -|
|事件通知-notification|longText?: NotificationLongTextContent;|新增| -|
|事件通知-notification|longTitle: string;|新增| -|
|事件通知-wantAgent|judgeEquality(info: WantAgentInfo, info2: WantAgentInfo, callback: AsyncCallback\<boolean>): void;|新增| -|
|事件通知-wantAgent|getUid(info: WantAgentInfo, callback: AsyncCallback\<number>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL = common.event.IVI_TEMPERATURE_ABNORMAL,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_VOLTAGE_RECOVERY = common.event.IVI_VOLTAGE_RECOVERY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_TEMPERATURE_RECOVERY = common.event.IVI_TEMPERATURE_RECOVERY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_ACTIVE = common.event.IVI_ACTIVE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USB_DEVICE_ATTACHED = usual.event.hardware.usb.action.USB_DEVICE_ATTACHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USB_DEVICE_DETACHED = usual.event.hardware.usb.action.USB_DEVICE_DETACHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_PAUSE = common.event.IVI_PAUSE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_STANDBY = common.event.IVI_STANDBY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_LASTMODE_SAVE = common.event.IVI_LASTMODE_SAVE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_VOLTAGE_ABNORMAL = common.event.IVI_VOLTAGE_ABNORMAL,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_HIGH_TEMPERATURE = common.event.IVI_HIGH_TEMPERATURE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_EXTREME_TEMPERATURE = common.event.IVI_EXTREME_TEMPERATURE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_UNMOUNTABLE = usual.event.data.DISK_UNMOUNTABLE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_EJECT = usual.event.data.DISK_EJECT,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED = usual.event.data.VISIBLE_ACCOUNTS_UPDATED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_ACCOUNT_DELETED = usual.event.data.ACCOUNT_DELETED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_FOUNDATION_READY = common.event.FOUNDATION_READY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_AIRPLANE_MODE_CHANGED = usual.event.AIRPLANE_MODE|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USB_ACCESSORY_ATTACHED = usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USB_ACCESSORY_DETACHED = usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_REMOVED = usual.event.data.DISK_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_UNMOUNTED = usual.event.data.DISK_UNMOUNTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_MOUNTED = usual.event.data.DISK_MOUNTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISK_BAD_REMOVAL = usual.event.data.DISK_BAD_REMOVAL,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = usual.event.nfc.action.RF_FIELD_OFF_DETECTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DISCHARGING = usual.event.DISCHARGING,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_CHARGING = usual.event.CHARGING,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = usual.event.DEVICE_IDLE_MODE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_POWER_SAVE_MODE_CHANGED = usual.event.POWER_SAVE_MODE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_ADDED = usual.event.USER_ADDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_REMOVED = usual.event.USER_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_ABILITY_ADDED = common.event.ABILITY_ADDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_ABILITY_REMOVED = common.event.ABILITY_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_ABILITY_UPDATED = common.event.ABILITY_UPDATED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_LOCATION_MODE_STATE_CHANGED = usual.event.location.MODE_STATE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_IVI_SLEEP = common.event.IVI_SLEEP,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE = usual.event.bluetooth.host.NAME_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE = usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE = usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = usual.event.nfc.action.ADAPTER_STATE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = usual.event.nfc.action.RF_FIELD_ON_DETECTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE = usual.event.bluetooth.host.REQ_ENABLE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE = usual.event.bluetooth.host.REQ_DISABLE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE = usual.event.bluetooth.host.SCAN_MODE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED = usual.event.bluetooth.host.DISCOVERY_STARTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED = usual.event.bluetooth.host.DISCOVERY_FINISHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_CONN_STATE = usual.event.wifi.p2p.CONN_STATE_CHANGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_STATE_CHANGED = usual.event.wifi.p2p.STATE_CHANGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = usual.event.wifi.p2p.DEVICES_CHANGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED = usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = usual.event.wifi.p2p.GROUP_STATE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE = usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE = usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE = usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE = usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_RSSI_VALUE = usual.event.wifi.RSSI_VALUE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_CONN_STATE = usual.event.wifi.CONN_STATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_HOTSPOT_STATE = usual.event.wifi.HOTSPOT_STATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_AP_STA_JOIN = usual.event.wifi.WIFI_HS_STA_JOIN,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_AP_STA_LEAVE = usual.event.wifi.WIFI_HS_STA_LEAVE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = usual.event.wifi.mplink.STATE_CHANGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_HWID_LOGOUT = common.event.HWID_LOGOUT,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_HWID_TOKEN_INVALID = common.event.HWID_TOKEN_INVALID,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_HWID_LOGOFF = common.event.HWID_LOGOFF,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_POWER_STATE = usual.event.wifi.POWER_STATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_SCAN_FINISHED = usual.event.wifi.SCAN_FINISHED,|新增| -|
|事件通知-commonEvent|clearAbortCommonEvent(): Promise\<void>;|新增| -|
|事件通知-commonEvent|bundleName?: string;|新增| -|
|事件通知-commonEvent|code?: number;|新增| -|
|事件通知-commonEvent|data?: string;|新增| -|
|事件通知-commonEvent|subscriberPermissions?: Array\<string>;|新增| -|
|事件通知-commonEvent|isOrdered?: boolean;|新增| -|
|事件通知-commonEvent|isSticky?: boolean;|新增| -|
|事件通知-commonEvent|abortCommonEvent(callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|abortCommonEvent(): Promise\<void>;|新增| -|
|事件通知-commonEvent|createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>;|新增| -|
|事件通知-commonEvent|createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void;|新增| -|
|事件通知-commonEvent|subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void;|新增| -|
|事件通知-commonEvent|publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void;|新增| -|
|事件通知-commonEvent|isOrderedCommonEvent(): Promise\<boolean>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BOOT_COMPLETED = usual.event.BOOT_COMPLETED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_LOCKED_BOOT_COMPLETED = usual.event.LOCKED_BOOT_COMPLETED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_SHUTDOWN = usual.event.SHUTDOWN,|新增| -|
|事件通知-commonEvent|isStickyCommonEvent(): Promise\<boolean>;|新增| -|
|事件通知-commonEvent|getData(callback: AsyncCallback\<string>): void;|新增| -|
|事件通知-commonEvent|getData(): Promise\<string>;|新增| -|
|事件通知-commonEvent|getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void;|新增| -|
|事件通知-commonEvent|getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>;|新增| -|
|事件通知-commonEvent|publish(event: string, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|event: string|新增| -|
|事件通知-commonEvent|bundleName?: string;|新增| -|
|事件通知-commonEvent|code?: number;|新增| -|
|事件通知-commonEvent|data?: string;|新增| -|
|事件通知-commonEvent|setCode(code: number, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DRIVE_MODE = common.event.DRIVE_MODE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_HOME_MODE = common.event.HOME_MODE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_OFFICE_MODE = common.event.OFFICE_MODE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_STARTED = usual.event.USER_STARTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_BACKGROUND = usual.event.USER_BACKGROUND,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_FOREGROUND = usual.event.USER_FOREGROUND,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_SWITCHED = usual.event.USER_SWITCHED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_STARTING = usual.event.USER_STARTING,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_UNLOCKED = usual.event.USER_UNLOCKED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_STOPPING = usual.event.USER_STOPPING,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_STOPPED = usual.event.USER_STOPPED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_HWID_LOGIN = common.event.HWID_LOGIN,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_VERIFIED = usual.event.PACKAGE_VERIFIED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE = usual.event.EXTERNAL_APPLICATIONS_AVAILABLE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE = usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_CONFIGURATION_CHANGED = usual.event.CONFIGURATION_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_LOCALE_CHANGED = usual.event.LOCALE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_MANAGE_PACKAGE_STORAGE = usual.event.MANAGE_PACKAGE_STORAGE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGES_UNSUSPENDED = usual.event.PACKAGES_UNSUSPENDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_MY_PACKAGE_SUSPENDED = usual.event.MY_PACKAGE_SUSPENDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = usual.event.MY_PACKAGE_UNSUSPENDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_UID_REMOVED = usual.event.UID_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_FIRST_LAUNCH = usual.event.PACKAGE_FIRST_LAUNCH,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION = usual.event.PACKAGE_NEEDS_VERIFICATION,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_SCREEN_OFF = usual.event.SCREEN_OFF,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_SCREEN_ON = usual.event.SCREEN_ON,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_USER_PRESENT = usual.event.USER_PRESENT,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_TIME_TICK = usual.event.TIME_TICK,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_TIME_CHANGED = usual.event.TIME_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_DATE_CHANGED = usual.event.DATE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BATTERY_CHANGED = usual.event.BATTERY_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BATTERY_LOW = usual.event.BATTERY_LOW,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BATTERY_OKAY = usual.event.BATTERY_OKAY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_POWER_CONNECTED = usual.event.POWER_CONNECTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_POWER_DISCONNECTED = usual.event.POWER_DISCONNECTED,|新增| -|
|事件通知-commonEvent|unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED = usual.event.bluetooth.remotedevice.ACL_CONNECTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED = usual.event.bluetooth.remotedevice.ACL_DISCONNECTED,|新增| -|
|事件通知-commonEvent|getAbortCommonEvent(callback: AsyncCallback\<boolean>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE = usual.event.bluetooth.remotedevice.NAME_UPDATE,|新增| -|
|事件通知-commonEvent|getAbortCommonEvent(): Promise\<boolean>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE = usual.event.bluetooth.remotedevice.PAIR_STATE,|新增| -|
|事件通知-commonEvent|getCode(callback: AsyncCallback\<number>): void;|新增| -|
|事件通知-commonEvent|setCode(code: number): Promise\<void>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE = usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE,|新增| -|
|事件通知-commonEvent|getCode(): Promise\<number>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT = usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT,|新增| -|
|事件通知-commonEvent|setCodeAndData(code: number, data: string, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT = usual.event.bluetooth.remotedevice.SDP_RESULT,|新增| -|
|事件通知-commonEvent|isStickyCommonEvent(callback: AsyncCallback\<boolean>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE = usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|setCodeAndData(code: number, data: string): Promise\<void>;|新增| -|
|事件通知-commonEvent|events: Array\<string>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE = usual.event.bluetooth.host.STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE = usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|setData(data: string, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE = usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE = usual.event.bluetooth.host.REQ_DISCOVERABLE,|新增| -|
|事件通知-commonEvent|publisherPermission?: string;|新增| -|
|事件通知-commonEvent|setData(data: string): Promise\<void>;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE = usual.event.bluetooth.remotedevice.UUID_VALUE,|新增| -|
|事件通知-commonEvent|publisherDeviceId?: string;|新增| -|
|事件通知-commonEvent|clearAbortCommonEvent(callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-commonEvent|userId?: number;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_TIMEZONE_CHANGED = usual.event.TIMEZONE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ = usual.event.bluetooth.remotedevice.PAIRING_REQ,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED = usual.event.bluetooth.remotedevice.DISCOVERED,|新增| -|
|事件通知-commonEvent|priority?: number;|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BUNDLE_REMOVED = usual.event.BUNDLE_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE = usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL = usual.event.bluetooth.remotedevice.PAIRING_CANCEL,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_CLOSE_SYSTEM_DIALOGS = usual.event.CLOSE_SYSTEM_DIALOGS,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_ADDED = usual.event.PACKAGE_ADDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ = usual.event.bluetooth.remotedevice.CONNECT_REQ,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_FULLY_REMOVED = usual.event.PACKAGE_FULLY_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_REPLACED = usual.event.PACKAGE_REPLACED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY = usual.event.bluetooth.remotedevice.CONNECT_REPLY,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_MY_PACKAGE_REPLACED = usual.event.MY_PACKAGE_REPLACED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_CHANGED = usual.event.PACKAGE_CHANGED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL = usual.event.bluetooth.remotedevice.CONNECT_CANCEL,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_REMOVED = usual.event.PACKAGE_REMOVED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_RESTARTED = usual.event.PACKAGE_RESTARTED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGE_DATA_CLEARED = usual.event.PACKAGE_DATA_CLEARED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_PACKAGES_SUSPENDED = usual.event.PACKAGES_SUSPENDED,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE = usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE,|新增| -|
|事件通知-commonEvent|COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED = usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE,|新增| -|
|事件通知-notification|LEVEL_NONE = 0,|新增| -|
|事件通知-notification|LEVEL_MIN = 1,|新增| -|
|事件通知-notification|LEVEL_LOW = 2,|新增| -|
|事件通知-notification|LEVEL_DEFAULT = 3,|新增| -|
|事件通知-notification|label?: string;|新增| -|
|事件通知-notification|bundle: string;|新增| -|
|事件通知-notification|uid?: number;|新增| -|
|事件通知-notification|NOTIFICATION_CONTENT_MULTILINE,|新增| -|
|事件通知-notification|UNKNOWN_TYPE = 0,|新增| -|
|事件通知-notification|SOCIAL_COMMUNICATION = 1,|新增| -|
|事件通知-notification|LEVEL_HIGH = 4,|新增| -|
|事件通知-notification|NOTIFICATION_CONTENT_BASIC_TEXT,|新增| -|
|事件通知-notification|NOTIFICATION_CONTENT_LONG_TEXT,|新增| -|
|事件通知-notification|NOTIFICATION_CONTENT_PICTURE,|新增| -|
|事件通知-notification|isFloatingIcon?: boolean;|新增| -|
|事件通知-notification|label?: string;|新增| -|
|事件通知-notification|badgeIconStyle?: number;|新增| -|
|事件通知-notification|showDeliveryTime?: boolean;|新增| -|
|事件通知-notification|isAlertOnce?: boolean;|新增| -|
|事件通知-notification|getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void;|新增| -|
|事件通知-notification|isStopwatch?: boolean;|新增| -|
|事件通知-notification|isCountDown?: boolean;|新增| -|
|事件通知-notification|getActiveNotifications(): Promise\<Array\<NotificationRequest>>;|新增| -|
|事件通知-notification|getActiveNotificationCount(callback: AsyncCallback\<number>): void;|新增| -|
|事件通知-notification|readonly creatorUid?: number;|新增| -|
|事件通知-notification|getActiveNotificationCount(): Promise\<number>;|新增| -|
|事件通知-notification|readonly creatorPid?: number;|新增| -|
|事件通知-notification|cancel(id: number, label?: string): Promise\<void>;|新增| -|
|事件通知-notification|classification?: string;|新增| -|
|事件通知-notification|readonly hashCode?: string;|新增| -|
|事件通知-notification|cancelAll(callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|actionButtons?: Array\<NotificationActionButton>;|新增| -|
|事件通知-notification|cancelAll(): Promise\<void>;|新增| -|
|事件通知-notification|smallIcon?: image.PixelMap;|新增| -|
|事件通知-notification|isUnremovable?: boolean;|新增| -|
|事件通知-notification|largeIcon?: image.PixelMap;|新增| -|
|事件通知-notification|deliveryTime?: number;|新增| -|
|事件通知-notification|readonly creatorBundleName?: string;|新增| -|
|事件通知-notification|tapDismissed?: boolean;|新增| -|
|事件通知-notification|publish(request: NotificationRequest): Promise\<void>;|新增| -|
|事件通知-notification|autoDeletedTime?: number;|新增| -|
|事件通知-notification|cancel(id: number, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|content: NotificationContent;|新增| -|
|事件通知-notification|wantAgent?: WantAgentInfo;|新增| -|
|事件通知-notification|cancel(id: number, label: string, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot>): void;|新增| -|
|事件通知-notification|extraInfo?: {[key: string]: any};|新增| -|
|事件通知-notification|getSlot(slotType: SlotType): Promise\<NotificationSlot>;|新增| -|
|事件通知-notification|SERVICE_INFORMATION = 2,|新增| -|
|事件通知-notification|color?: number;|新增| -|
|事件通知-notification|id?: number;|新增| -|
|事件通知-notification|getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void;|新增| -|
|事件通知-notification|CONTENT_INFORMATION = 3,|新增| -|
|事件通知-notification|slotType?: notification.SlotType;|新增| -|
|事件通知-notification|colorEnabled?: boolean;|新增| -|
|事件通知-notification|OTHER_TYPES = 0xFFFF,|新增| -|
|事件通知-notification|isOngoing?: boolean;|新增| -|
|事件通知-notification|addSlot(type: SlotType, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|id: number;|新增| -|
|事件通知-notification|addSlot(type: SlotType): Promise\<void>;|新增| -|
|事件通知-notification|desc?: string;|新增| -|
|事件通知-notification|publish(request: NotificationRequest, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|removeAllSlots(callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|removeAllSlots(): Promise\<void>;|新增| -|
|事件通知-notification|getSlots(): Promise\<Array\<NotificationSlot>>;|新增| -|
|事件通知-notification|removeSlot(slotType: SlotType, callback: AsyncCallback\<void>): void;|新增| -|
|事件通知-notification|removeSlot(slotType: SlotType): Promise\<void>;|新增| -|
|全球化-resourceManager|getString(resId: number, callback: AsyncCallback\<string>);<br/>getString(resId: number): Promise\<string>;|新增| -|
|全球化-resourceManager|getStringArray(resId: number, callback: AsyncCallback\<Array\<string>>);<br/>getStringArray(resId: number): Promise\<Array\<string>>;|新增| -|
|全球化-resourceManager|getConfiguration(callback: AsyncCallback\<Configuration>);<br/>getConfiguration(): Promise\<Configuration>;|新增| -|
|全球化-resourceManager|getDeviceCapability(callback: AsyncCallback\<DeviceCapability>);<br/>getDeviceCapability(): Promise\<DeviceCapability>;|新增| -|
|全球化-resourceManager|getMedia(resId: number, callback: AsyncCallback\<Uint8Array>);<br/>getMedia(resId: number): Promise\<Uint8Array>;<br/>getMediaBase64(resId: number, callback: AsyncCallback\<string>);<br/>getMediaBase64(resId: number): Promise\<string>;|新增| -|
|全球化-resourceManager|"getPluralString(resId: number, num: number, callback: AsyncCallback\<string>);<br/>getPluralString(resId: number, num: number): Promise\<string>;"|新增| -|
|全球化-resourceManager|DeviceCapability|新增| -|
|全球化-resourceManager|"getMediaBase64(resId: number, callback: AsyncCallback\<Uint8Array>);<br/>getMediaBase64(resId: number): Promise\<Uint9Array>;"|新增| -|
|全球化-resourceManager|"getResourceManager(callback: AsyncCallback\<ResourceManager>);<br/>getResourceManager(bundleName: string, callback: AsyncCallback\<ResourceManager>);<br/>getResourceManager(): Promise\<ResourceManager>;<br/>getResourceManager(bundleName: string): Promise\<ResourceManager>;"|新增| -|
|全球化-resourceManager|DeviceType|新增| -|
|全球化-resourceManager|Direction|新增| -|
|全球化-resourceManager|Configuration|新增| -|
|全球化-resourceManager|ScreenDensity|新增| -|
|全球化-resourceManager|deviceType|新增| -|
|全球化-resourceManager|locale|新增| -|
|全球化-resourceManager|direction|新增| -|
|全球化-resourceManager|screenDensity|新增| -|
|电源服务-batteryInfo|batteryInfo:const batterySOC: number;|新增| -|
|电源服务-batteryInfo|batteryInfo:const technology: string;|新增| -|
|电源服务-batteryInfo|batteryInfo:const isBatteryPresent: boolean;|新增| -|
|电源服务-batteryInfo|batteryInfo:const batteryTemperature: number;|新增| -|
|电源服务-batteryInfo|batteryInfo:const pluggedType: BatteryPluggedType;|新增| -|
|电源服务-batteryInfo|batteryInfo:const chargingStatus: BatteryChargeState;|新增| -|
|电源服务-batteryInfo|batteryInfo:const healthStatus: BatteryHealthState;|新增| -|
|电源服务-batteryInfo|batteryInfo:const voltage: number;|新增| -|
|电源服务-batteryInfo|BatteryChargeState:NONE|新增| -|
|电源服务-batteryInfo|BatteryChargeState:DISABLE|新增| -|
|电源服务-batteryInfo|BatteryChargeState:ENABLE,|新增| -|
|电源服务-batteryInfo|BatteryChargeState:FULL|新增| -|
|电源服务-batteryInfo|BatteryHealthState:COLD|新增| -|
|电源服务-batteryInfo|BatteryHealthState:OVERHEAT|新增| -|
|电源服务-batteryInfo|BatteryHealthState:OVERVOLTAGE|新增| -|
|电源服务-batteryInfo|BatteryHealthState:DEAD|新增| -|
|电源服务-batteryInfo|BatteryHealthState:UNKNOWN|新增| -|
|电源服务-batteryInfo|BatteryHealthState:GOOD|新增| -|
|电源服务-batteryInfo|BatteryPluggedType:WIRELESS|新增| -|
|电源服务-batteryInfo|BatteryPluggedType:NONE|新增| -|
|电源服务-batteryInfo|BatteryPluggedType:AC|新增| -|
|电源服务-batteryInfo|BatteryPluggedType:USB|新增| -|
|电源服务-runningLock|RunningLock:unlock()|新增| -|
|电源服务-runningLock|runningLock:isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void;|新增| -|
|电源服务-runningLock|runningLock:createRunningLock(name: string, type: runningLockType): RunningLock|新增| -|
|电源服务-runningLock|RunningLock:lock(timeout: number)|新增| -|
|电源服务-runningLock|RunningLock:isUsed(): boolean|新增| -|
|电源服务-runninglock|RunningLockType:BACKGROUND|新增| -|
|电源服务-runninglock|RunningLockType:PROXIMITY_SCREEN_CONTROL|新增| -|
|电源服务-power|power:rebootDevice(reason ?: string)|新增| -|
|电源服务-power|power:isScreenOn(callback: AsyncCallback\<boolean>): void;|新增| -|
