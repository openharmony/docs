| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：AbilityDelegator;<br>方法or属性：print(msg: string, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：print(msg: string): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|类名：AbilityDelegator;<br>方法or属性：finishTest(msg: string, code: number): Promise\<void>;|NA|abilityDelegator.d.ts|
|新增|NA|类名：LifecycleForm;<br>方法or属性：onShare?(formId: string): {[key: string]: any};|lifecycle.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type DataAbilityHelper = _DataAbilityHelper|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type PacMap = _PacMap|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type DataAbilityOperation = _DataAbilityOperation|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type DataAbilityResult = _DataAbilityResult|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type AbilityResult = _AbilityResult|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type ConnectOptions = _ConnectOptions|@ohos.ability.ability.d.ts|
|新增|NA|类名：ability;<br>方法or属性：export type StartAbilityParameter = _StartAbilityParameter|@ohos.ability.ability.d.ts|
|新增|NA|类名：featureAbility;<br>方法or属性：export type Context = _Context|@ohos.ability.featureAbility.d.ts|
|新增|NA|类名：featureAbility;<br>方法or属性：export type AppVersionInfo = _AppVersionInfo|@ohos.ability.featureAbility.d.ts|
|新增|NA|类名：featureAbility;<br>方法or属性：export type ProcessInfo = _ProcessInfo|@ohos.ability.featureAbility.d.ts|
|新增|NA|类名：Ability;<br>方法or属性：onConfigurationUpdate(newConfig: Configuration): void;|@ohos.app.ability.Ability.d.ts|
|新增|NA|类名：Ability;<br>方法or属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|@ohos.app.ability.Ability.d.ts|
|新增|NA|类名：LaunchParam;<br>方法or属性：launchReason: LaunchReason;|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchParam;<br>方法or属性：lastExitReason: LastExitReason;|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchReason;<br>方法or属性：UNKNOWN = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LastExitReason;<br>方法or属性：UNKNOWN = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchReason;<br>方法or属性：START_ABILITY = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchReason;<br>方法or属性：CALL = 2|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchReason;<br>方法or属性：CONTINUATION = 3|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LaunchReason;<br>方法or属性：APP_RECOVERY = 4|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LastExitReason;<br>方法or属性：ABILITY_NOT_RESPONDING = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：LastExitReason;<br>方法or属性：NORMAL = 2|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnContinueResult;<br>方法or属性：AGREE = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnContinueResult;<br>方法or属性：REJECT = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnContinueResult;<br>方法or属性：MISMATCH = 2|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：MemoryLevel;<br>方法or属性：MEMORY_LEVEL_MODERATE = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：MemoryLevel;<br>方法or属性：MEMORY_LEVEL_LOW = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：MemoryLevel;<br>方法or属性：MEMORY_LEVEL_CRITICAL = 2|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：WINDOW_MODE_UNDEFINED = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：WINDOW_MODE_FULLSCREEN = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：WINDOW_MODE_SPLIT_PRIMARY = 100|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：WINDOW_MODE_SPLIT_SECONDARY = 101|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：WINDOW_MODE_FLOATING = 102|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：ALL_AGREE = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：CONTINUATION_REJECT = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：CONTINUATION_MISMATCH = 2|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：RECOVERY_AGREE = 3|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：RECOVERY_REJECT = 4|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：OnSaveResult;<br>方法or属性：ALL_REJECT|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：StateType;<br>方法or属性：CONTINUATION = 0|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：StateType;<br>方法or属性：APP_RECOVERY = 1|@ohos.app.ability.AbilityConstant.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：function getAbilityDelegator(): AbilityDelegator;|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：function getArguments(): AbilityDelegatorArgs;|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：export type AbilityDelegator = _AbilityDelegator|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：export type AbilityDelegatorArgs = _AbilityDelegatorArgs|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：export type AbilityMonitor = _AbilityMonitor|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：abilityDelegatorRegistry;<br>方法or属性：export type ShellCmdResult = _ShellCmdResult|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleState;<br>方法or属性：UNINITIALIZED|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleState;<br>方法or属性：CREATE|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleState;<br>方法or属性：FOREGROUND|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleState;<br>方法or属性：BACKGROUND|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleState;<br>方法or属性：DESTROY|@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onAbilityCreate(ability: UIAbility): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onAbilityDestroy(ability: UIAbility): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onAbilityForeground(ability: UIAbility): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onAbilityBackground(ability: UIAbility): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：AbilityLifecycleCallback;<br>方法or属性：onAbilityContinue(ability: UIAbility): void;|@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration): Promise\<void>;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getTopAbility(): Promise\<ElementName>;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：function getTopAbility(callback: AsyncCallback\<ElementName>): void;|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：export type AbilityRunningInfo = _AbilityRunningInfo|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：abilityManager;<br>方法or属性：export type ExtensionRunningInfo = _ExtensionRunningInfo|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：INITIAL = 0|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：FOCUS = 2|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：FOREGROUND = 9|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：BACKGROUND = 10|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：FOREGROUNDING = 11|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityState;<br>方法or属性：BACKGROUNDING = 12|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：AbilityStage;<br>方法or属性：context: AbilityStageContext;|@ohos.app.ability.AbilityStage.d.ts|
|新增|NA|类名：AbilityStage;<br>方法or属性：onCreate(): void;|@ohos.app.ability.AbilityStage.d.ts|
|新增|NA|类名：AbilityStage;<br>方法or属性：onAcceptWant(want: Want): string;|@ohos.app.ability.AbilityStage.d.ts|
|新增|NA|类名：AbilityStage;<br>方法or属性：onConfigurationUpdate(newConfig: Configuration): void;|@ohos.app.ability.AbilityStage.d.ts|
|新增|NA|类名：AbilityStage;<br>方法or属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|@ohos.app.ability.AbilityStage.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function on(type: "applicationState", observer: ApplicationStateObserver): number;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function on(type: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array\<string>): number;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function off(type: "applicationState", observerId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function off(type: "applicationState", observerId: number): Promise\<void>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getForegroundApplications(): Promise\<Array\<AppStateData>>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number): Promise\<void>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(): Promise\<boolean>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string): Promise\<void>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string): Promise\<void>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(): Promise\<boolean>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getAppMemorySize(): Promise\<number>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getAppMemorySize(callback: AsyncCallback\<number>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：export type AbilityStateData = _AbilityStateData.default|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：export type AppStateData = _AppStateData.default|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：export type ApplicationStateObserver = _ApplicationStateObserver.default|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：export type ProcessInformation = _ProcessInformation|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ApplicationState;<br>方法or属性：STATE_CREATE|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ProcessState;<br>方法or属性：STATE_CREATE|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ApplicationState;<br>方法or属性：STATE_FOREGROUND|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ProcessState;<br>方法or属性：STATE_FOREGROUND|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ApplicationState;<br>方法or属性：STATE_ACTIVE|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ProcessState;<br>方法or属性：STATE_ACTIVE|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ApplicationState;<br>方法or属性：STATE_BACKGROUND|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ProcessState;<br>方法or属性：STATE_BACKGROUND|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ApplicationState;<br>方法or属性：STATE_DESTROY|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：ProcessState;<br>方法or属性：STATE_DESTROY|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appRecovery;<br>方法or属性：function enableAppRecovery(restart?: RestartFlag, saveOccasion?: SaveOccasionFlag, saveMode?: SaveModeFlag) : void;|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：appRecovery;<br>方法or属性：function restartApp(): void;|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：appRecovery;<br>方法or属性：function saveAppState(): boolean;|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：RestartFlag;<br>方法or属性：ALWAYS_RESTART = 0|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：RestartFlag;<br>方法or属性：RESTART_WHEN_JS_CRASH = 0x0001|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：RestartFlag;<br>方法or属性：RESTART_WHEN_APP_FREEZE = 0x0002|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：RestartFlag;<br>方法or属性：NO_RESTART = 0xFFFF|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：SaveOccasionFlag;<br>方法or属性：SAVE_WHEN_ERROR = 0x0001|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：SaveOccasionFlag;<br>方法or属性：SAVE_WHEN_BACKGROUND = 0x0002|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：SaveModeFlag;<br>方法or属性：SAVE_WITH_FILE = 0x0001|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：SaveModeFlag;<br>方法or属性：SAVE_WITH_SHARED_MEMORY = 0x0002|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type UIAbilityContext = _UIAbilityContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type AbilityStageContext = _AbilityStageContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type ApplicationContext = _ApplicationContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type BaseContext = _BaseContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type Context = _Context.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type ExtensionContext = _ExtensionContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type FormExtensionContext = _FormExtensionContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type ServiceExtensionContext = _ServiceExtensionContext.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type EventHub = _EventHub.default|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type PacMap = _PacMap|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type AbilityResult = _AbilityResult|@ohos.app.ability.common.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type ConnectOptions = _ConnectOptions|@ohos.app.ability.common.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：language?: string;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：colorMode?: ConfigurationConstant.ColorMode;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：direction?: ConfigurationConstant.Direction;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：screenDensity?: ConfigurationConstant.ScreenDensity;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：displayId?: number;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：hasPointerDevice?: boolean;|@ohos.app.ability.Configuration.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：COLOR_MODE_NOT_SET = -1|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：COLOR_MODE_DARK = 0|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：COLOR_MODE_LIGHT = 1|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：DIRECTION_NOT_SET = -1|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：DIRECTION_VERTICAL = 0|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：DIRECTION_HORIZONTAL = 1|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_NOT_SET = 0|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_SDPI = 120|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_MDPI = 160|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_LDPI = 240|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_XLDPI = 320|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_XXLDPI = 480|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：ScreenDensity;<br>方法or属性：SCREEN_DENSITY_XXXLDPI = 640|@ohos.app.ability.ConfigurationConstant.d.ts|
|新增|NA|类名：AreaMode;<br>方法or属性：EL1 = 0|@ohos.app.ability.contextConstant.d.ts|
|新增|NA|类名：AreaMode;<br>方法or属性：EL2 = 1|@ohos.app.ability.contextConstant.d.ts|
|新增|NA|类名：dataUriUtils;<br>方法or属性：function getId(uri: string): number|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|类名：dataUriUtils;<br>方法or属性：function attachId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|类名：dataUriUtils;<br>方法or属性：function deleteId(uri: string): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|类名：dataUriUtils;<br>方法or属性：function updateId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|类名：dialogRequest;<br>方法or属性：function getRequestInfo(want: Want): RequestInfo;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：dialogRequest;<br>方法or属性：function getRequestCallback(want: Want): RequestCallback;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：ResultCode;<br>方法or属性：RESULT_OK = 0|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：ResultCode;<br>方法or属性：RESULT_CANCEL = 1|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：RequestResult;<br>方法or属性：result: ResultCode;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：RequestCallback;<br>方法or属性：setRequestResult(result: RequestResult): void;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：EnvironmentCallback;<br>方法or属性：onConfigurationUpdated(config: Configuration): void;|@ohos.app.ability.EnvironmentCallback.d.ts|
|新增|NA|类名：EnvironmentCallback;<br>方法or属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|@ohos.app.ability.EnvironmentCallback.d.ts|
|新增|NA|类名：errorManager;<br>方法or属性：function on(type: "error", observer: ErrorObserver): number;|@ohos.app.ability.errorManager.d.ts|
|新增|NA|类名：errorManager;<br>方法or属性：function off(type: "error", observerId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.errorManager.d.ts|
|新增|NA|类名：errorManager;<br>方法or属性：function off(type: "error", observerId: number): Promise\<void>;|@ohos.app.ability.errorManager.d.ts|
|新增|NA|类名：errorManager;<br>方法or属性：export type ErrorObserver = _ErrorObserver.default|@ohos.app.ability.errorManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function on(type: "mission", listener: MissionListener): number;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function off(type: "mission", listenerId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function off(type: "mission", listenerId: number): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback\<MissionInfo>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number): Promise\<MissionInfo>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback\<Array\<MissionInfo>>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number): Promise\<Array\<MissionInfo>>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function lockMission(missionId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function lockMission(missionId: number): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function clearMission(missionId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function clearMission(missionId: number): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function clearAllMissions(callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function clearAllMissions(): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback\<void>): void;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options?: StartOptions): Promise\<void>;|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：export type MissionInfo = _MissionInfo|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：export type MissionListener = _MissionListener|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：missionManager;<br>方法or属性：export type MissionSnapshot = _MissionSnapshot|@ohos.app.ability.missionManager.d.ts|
|新增|NA|类名：quickFixManager;<br>方法or属性：function applyQuickFix(hapModuleQuickFixFiles: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：quickFixManager;<br>方法or属性：function applyQuickFix(hapModuleQuickFixFiles: Array\<string>): Promise\<void>;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：quickFixManager;<br>方法or属性：function getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback\<ApplicationQuickFixInfo>): void;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：quickFixManager;<br>方法or属性：function getApplicationQuickFixInfo(bundleName: string): Promise\<ApplicationQuickFixInfo>;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：HapModuleQuickFixInfo;<br>方法or属性：readonly moduleName: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：HapModuleQuickFixInfo;<br>方法or属性：readonly originHapHash: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：HapModuleQuickFixInfo;<br>方法or属性：readonly quickFixFilePath: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly bundleName: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly bundleVersionCode: number;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly bundleVersionName: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly quickFixVersionCode: number;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly quickFixVersionName: string;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ApplicationQuickFixInfo;<br>方法or属性：readonly hapModuleQuickFixInfo: Array\<HapModuleQuickFixInfo>;|@ohos.app.ability.quickFixManager.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：context: ServiceExtensionContext;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onCreate(want: Want): void;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onDestroy(): void;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onRequest(want: Want, startId: number): void;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onConnect(want: Want): rpc.RemoteObject \| Promise\<rpc.RemoteObject>;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onDisconnect(want: Want): void \| Promise\<void>;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onReconnect(want: Want): void;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onConfigurationUpdate(newConfig: Configuration): void;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：ServiceExtensionAbility;<br>方法or属性：onDump(params: Array\<string>): Array\<string>;|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|新增|NA|类名：StartOptions;<br>方法or属性：windowMode?: number;|@ohos.app.ability.StartOptions.d.ts|
|新增|NA|类名：StartOptions;<br>方法or属性：displayId?: number;|@ohos.app.ability.StartOptions.d.ts|
|新增|NA|类名：OnReleaseCallback;<br>方法or属性：(msg: string): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：CalleeCallback;<br>方法or属性：(indata: rpc.MessageSequence): rpc.Parcelable;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：call(method: string, data: rpc.Parcelable): Promise\<void>;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：callWithResult(method: string, data: rpc.Parcelable): Promise\<rpc.MessageSequence>;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：release(): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：onRelease(callback: OnReleaseCallback): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：on(type: "release", callback: OnReleaseCallback): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：off(type: "release", callback: OnReleaseCallback): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Caller;<br>方法or属性：off(type: "release"): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Callee;<br>方法or属性：on(method: string, callback: CalleeCallback): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Callee;<br>方法or属性：off(method: string): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：context: UIAbilityContext;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：launchWant: Want;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：lastRequestWant: Want;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：callee: Callee;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onCreate(want: Want, param: AbilityConstant.LaunchParam): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onWindowStageCreate(windowStage: window.WindowStage): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onWindowStageDestroy(): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onWindowStageRestore(windowStage: window.WindowStage): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onDestroy(): void \| Promise\<void>;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onForeground(): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onBackground(): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onContinue(wantParam: { [key: string]: Object }): AbilityConstant.OnContinueResult;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onDump(params: Array\<string>): Array\<string>;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：UIAbility;<br>方法or属性：onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: Object}): AbilityConstant.OnSaveResult;|@ohos.app.ability.UIAbility.d.ts|
|新增|NA|类名：Want;<br>方法or属性：bundleName?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：abilityName?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：deviceId?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：uri?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：type?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：flags?: number;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：action?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：parameters?: {[key: string]: Object};|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：entities?: Array\<string>;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：Want;<br>方法or属性：moduleName?: string;|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type WantAgent = object;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent, callback: AsyncCallback\<string>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent): Promise\<string>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent, callback: AsyncCallback\<number>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent): Promise\<number>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent, callback: AsyncCallback\<Want>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent): Promise\<Want>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent, callback: AsyncCallback\<void>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent): Promise\<void>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback\<CompleteData>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo): Promise\<WantAgent>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：function getOperationType(agent: WantAgent): Promise\<number>;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：export type TriggerInfo = _TriggerInfo|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：wantAgent;<br>方法or属性：export type WantAgentInfo = _WantAgentInfo|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：ONE_TIME_FLAG = 0|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：NO_BUILD_FLAG|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：CANCEL_PRESENT_FLAG|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：UPDATE_PRESENT_FLAG|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：CONSTANT_FLAG|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：REPLACE_ELEMENT|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：REPLACE_ACTION|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：REPLACE_URI|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：REPLACE_ENTITIES|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：WantAgentFlags;<br>方法or属性：REPLACE_BUNDLE|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：OperationType;<br>方法or属性：UNKNOWN_TYPE = 0|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：OperationType;<br>方法or属性：START_ABILITY|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：OperationType;<br>方法or属性：START_ABILITIES|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：OperationType;<br>方法or属性：START_SERVICE|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：OperationType;<br>方法or属性：SEND_COMMON_EVENT|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：CompleteData;<br>方法or属性：info: WantAgent;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：CompleteData;<br>方法or属性：want: Want;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：CompleteData;<br>方法or属性：finalCode: number;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：CompleteData;<br>方法or属性：finalData: string;|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：CompleteData;<br>方法or属性：extraInfo?: { [key: string]: Object };|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|类名：Params;<br>方法or属性：DLP_PARAMS_SANDBOX = "ohos.dlp.params.sandbox"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params;<br>方法or属性：DLP_PARAMS_BUNDLE_NAME = "ohos.dlp.params.bundleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params;<br>方法or属性：DLP_PARAMS_MODULE_NAME = "ohos.dlp.params.moduleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params;<br>方法or属性：DLP_PARAMS_ABILITY_NAME = "ohos.dlp.params.abilityName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params;<br>方法or属性：DLP_PARAMS_INDEX = "ohos.dlp.params.index"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params;<br>方法or属性：ABILITY_BACK_TO_OTHER_MISSION_STACK = "ability.params.backToOtherMissionStack"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Flags;<br>方法or属性：FLAG_AUTH_READ_URI_PERMISSION = 0x00000001|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Flags;<br>方法or属性：FLAG_AUTH_WRITE_URI_PERMISSION = 0x00000002|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Flags;<br>方法or属性：FLAG_INSTALL_ON_DEMAND = 0x00000800|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：formBindingData;<br>方法or属性：function createFormBindingData(obj?: Object \| string): FormBindingData;|@ohos.app.form.formBindingData.d.ts|
|新增|NA|类名：FormBindingData;<br>方法or属性：data: Object|@ohos.app.form.formBindingData.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：context: FormExtensionContext;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onAddForm(want: Want): formBindingData.FormBindingData;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onCastToNormalForm(formId: string): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onUpdateForm(formId: string): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onChangeFormVisibility(newStatus: { [key: string]: number }): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onFormEvent(formId: string, message: string): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onRemoveForm(formId: string): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onConfigurationUpdate(newConfig: Configuration): void;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onAcquireFormState?(want: Want): formInfo.FormState;|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：FormExtensionAbility;<br>方法or属性：onShareForm?(formId: string): { [key: string]: Object };|@ohos.app.form.FormExtensionAbility.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function deleteForm(formId: string, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function deleteForm(formId: string): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function releaseForm(formId: string, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache?: boolean): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function requestForm(formId: string, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function requestForm(formId: string): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function castToNormalForm(formId: string, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function castToNormalForm(formId: string): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function isSystemReady(callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function isSystemReady(): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function getAllFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function getAllFormsInfo(): Promise\<Array\<formInfo.FormInfo>>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName?: string): Promise\<Array\<formInfo.FormInfo>>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>, callback: AsyncCallback\<number>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>): Promise\<number>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function on(type: "formUninstall", callback: Callback\<string>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function off(type: "formUninstall", callback?: Callback\<string>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function shareForm(formId: string, deviceId: string, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function shareForm(formId: string, deviceId: string): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean, callback: AsyncCallback\<void>): void;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：formHost;<br>方法or属性：function notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean): Promise\<void>;|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：bundleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：moduleName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：abilityName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：name: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：description: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：type: FormType;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：jsComponentName: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：colorMode: ColorMode;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：isDefault: boolean;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：updateEnabled: boolean;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：formVisibleNotify: boolean;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：scheduledUpdateTime: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：formConfigAbility: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：updateDuration: number;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：defaultDimension: number;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：supportDimensions: Array\<number>;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfo;<br>方法or属性：customizeData: {[key: string]: [value: string]};|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormType;<br>方法or属性：JS = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormType;<br>方法or属性：eTS = 2|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：MODE_AUTO = -1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：MODE_DARK = 0|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：ColorMode;<br>方法or属性：MODE_LIGHT = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormStateInfo;<br>方法or属性：formState: FormState;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormStateInfo;<br>方法or属性：want: Want;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormState;<br>方法or属性：UNKNOWN = -1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormState;<br>方法or属性：DEFAULT = 0|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormState;<br>方法or属性：READY = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：DIMENSION_KEY = "ohos.extra.param.key.form_dimension"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：NAME_KEY = "ohos.extra.param.key.form_name"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：MODULE_NAME_KEY = "ohos.extra.param.key.module_name"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：WIDTH_KEY = "ohos.extra.param.key.form_width"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：HEIGHT_KEY = "ohos.extra.param.key.form_height"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：TEMPORARY_KEY = "ohos.extra.param.key.form_temporary"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：BUNDLE_NAME_KEY = "ohos.extra.param.key.bundle_name"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：ABILITY_NAME_KEY = "ohos.extra.param.key.ability_name"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormParam;<br>方法or属性：DEVICE_ID_KEY = "ohos.extra.param.key.device_id"|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormInfoFilter;<br>方法or属性：moduleName?: string;|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormDimension;<br>方法or属性：Dimension_1_2 = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormDimension;<br>方法or属性：Dimension_2_2|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormDimension;<br>方法or属性：Dimension_2_4|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormDimension;<br>方法or属性：Dimension_4_4|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：FormDimension;<br>方法or属性：Dimension_2_1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：VisibilityType;<br>方法or属性：FORM_VISIBLE = 1|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：VisibilityType;<br>方法or属性：FORM_INVISIBLE|@ohos.app.form.formInfo.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number): Promise\<void>;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function getFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function getFormsInfo(filter?: formInfo.FormInfoFilter): Promise\<Array\<formInfo.FormInfo>>;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function requestPublishForm(want: Want, callback: AsyncCallback\<string>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise\<string>;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function isRequestPublishFormSupported(callback: AsyncCallback\<boolean>): void;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：formProvider;<br>方法or属性：function isRequestPublishFormSupported(): Promise\<boolean>;|@ohos.app.form.formProvider.d.ts|
|新增|NA|类名：FormError;<br>方法or属性：ERR_DISTRIBUTED_SCHEDULE_FAILED = 37|@ohos.application.formError.d.ts|
|新增|NA|类名：StaticSubscriberExtensionAbility;<br>方法or属性：onReceiveEvent(event: CommonEventData): void;|@ohos.application.StaticSubscriberExtensionAbility.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function on(type: "deviceSelected", token: number, callback: Callback\<Array\<ContinuationResult>>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function on(type: "deviceUnselected", token: number, callback: Callback\<Array\<ContinuationResult>>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function off(type: "deviceSelected", token: number): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function off(type: "deviceUnselected", token: number): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function registerContinuation(callback: AsyncCallback\<number>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function registerContinuation(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function registerContinuation(options?: ContinuationExtraParams): Promise\<number>;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function unregisterContinuation(token: number, callback: AsyncCallback\<void>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function unregisterContinuation(token: number): Promise\<void>;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function startContinuationDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：function startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback\<void>): void;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function startSyncRemoteMissions(parameter: MissionParameter): Promise\<void>;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise\<void>;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback\<void>): void;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise\<void>;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function unRegisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function unRegisterMissionListener(parameter: MissionDeviceInfo): Promise\<void>;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback\<void>): void;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise\<void>;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：Context;<br>方法or属性：getExternalCacheDir(callback: AsyncCallback\<string>): void|context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：getExternalCacheDir(): Promise\<string>;|context.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：getAppContext(): Context;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：getAbilityState(ability: UIAbility): number;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：getCurrentTopAbility(): Promise\<UIAbility>|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：startAbility(want: Want): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：doAbilityForeground(ability: UIAbility): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：doAbilityBackground(ability: UIAbility): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：print(msg: string, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：print(msg: string): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：printSync(msg: string): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：finishTest(msg: string, code: number): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：abilityName: string;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：moduleName?: string;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onAbilityCreate?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onAbilityForeground?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onAbilityBackground?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onAbilityDestroy?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onWindowStageCreate?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onWindowStageRestore?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityMonitor;<br>方法or属性：onWindowStageDestroy?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|类名：AbilityStageContext;<br>方法or属性：currentHapModuleInfo: HapModuleInfo;|AbilityStageContext.d.ts|
|新增|NA|类名：AbilityStageContext;<br>方法or属性：config: Configuration;|AbilityStageContext.d.ts|
|新增|NA|类名：AbilityStageMonitor;<br>方法or属性：moduleName: string;|AbilityStageMonitor.d.ts|
|新增|NA|类名：AbilityStageMonitor;<br>方法or属性：srcEntrance: string;|AbilityStageMonitor.d.ts|
|新增|NA|类名：AbilityStateData;<br>方法or属性：moduleName: string;|AbilityStateData.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：on(type: "abilityLifecycle", callback: AbilityLifecycleCallback): number;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：on(type: "environment", callback: EnvironmentCallback): number;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：off(type: "abilityLifecycle", callbackId: number, callback: AsyncCallback\<void>): void;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：off(type: "abilityLifecycle", callbackId: number): Promise\<void>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：off(type: "environment", callbackId: number, callback: AsyncCallback\<void>): void;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：off(type: "environment", callbackId: number): Promise\<void>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：killAllProcesses(): Promise\<void>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext;<br>方法or属性：killAllProcesses(callback: AsyncCallback\<void>);|ApplicationContext.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type ProcessData = _ProcessData.default|ApplicationStateObserver.d.ts|
|新增|NA|类名：ApplicationStateObserver;<br>方法or属性：onProcessStateChanged(processData: ProcessData): void;|ApplicationStateObserver.d.ts|
|新增|NA|类名：Context;<br>方法or属性：resourceManager: resmgr.ResourceManager;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：applicationInfo: ApplicationInfo;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：cacheDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：tempDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：filesDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：databaseDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：preferencesDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：bundleCodeDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：distributedFilesDir: string;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：eventHub: EventHub;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：area: contextConstant.AreaMode;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：createBundleContext(bundleName: string): Context;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：createModuleContext(moduleName: string): Context;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：createModuleContext(bundleName: string, moduleName: string): Context;|Context.d.ts|
|新增|NA|类名：Context;<br>方法or属性：getApplicationContext(): ApplicationContext;|Context.d.ts|
|新增|NA|类名：ContinueCallback;<br>方法or属性：onContinueDone(result: number): void;|ContinueCallback.d.ts|
|新增|NA|类名：ContinueDeviceInfo;<br>方法or属性：srcDeviceId: string;|ContinueDeviceInfo.d.ts|
|新增|NA|类名：ContinueDeviceInfo;<br>方法or属性：dstDeviceId: string;|ContinueDeviceInfo.d.ts|
|新增|NA|类名：ContinueDeviceInfo;<br>方法or属性：missionId: number;|ContinueDeviceInfo.d.ts|
|新增|NA|类名：ContinueDeviceInfo;<br>方法or属性：wantParam: {[key: string]: any};|ContinueDeviceInfo.d.ts|
|新增|NA|类名：ErrorObserver;<br>方法or属性：onUnhandledException(errMsg: string): void;|ErrorObserver.d.ts|
|新增|NA|类名：EventHub;<br>方法or属性：on(event: string, callback: Function): void|EventHub.d.ts|
|新增|NA|类名：EventHub;<br>方法or属性：off(event: string, callback?: Function): void|EventHub.d.ts|
|新增|NA|类名：EventHub;<br>方法or属性：emit(event: string, ...args: Object[]): void|EventHub.d.ts|
|新增|NA|类名：ExtensionContext;<br>方法or属性：currentHapModuleInfo: HapModuleInfo;|ExtensionContext.d.ts|
|新增|NA|类名：ExtensionContext;<br>方法or属性：config: Configuration;|ExtensionContext.d.ts|
|新增|NA|类名：ExtensionContext;<br>方法or属性：extensionAbilityInfo: ExtensionAbilityInfo;|ExtensionContext.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：extension: ElementName;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：pid: number;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：uid: number;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：processName: string;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：startTime: number;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：clientPackage: Array\<String>;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：ExtensionRunningInfo;<br>方法or属性：type: bundle.ExtensionAbilityType;|ExtensionRunningInfo.d.ts|
|新增|NA|类名：FormExtensionContext;<br>方法or属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|FormExtensionContext.d.ts|
|新增|NA|类名：FormExtensionContext;<br>方法or属性：startAbility(want: Want): Promise\<void>;|FormExtensionContext.d.ts|
|新增|NA|类名：MissionCallback;<br>方法or属性：notifyMissionsChanged(deviceId: string): void;|MissionCallbacks.d.ts|
|新增|NA|类名：MissionCallback;<br>方法or属性：notifySnapshot(deviceId: string, mission: number): void;|MissionCallbacks.d.ts|
|新增|NA|类名：MissionCallback;<br>方法or属性：notifyNetDisconnect(deviceId: string, state: number): void;|MissionCallbacks.d.ts|
|新增|NA|类名：MissionDeviceInfo;<br>方法or属性：deviceId: string;|MissionDeviceInfo.d.ts|
|新增|NA|类名：MissionListener;<br>方法or属性：onMissionLabelUpdated(mission: number): void;|MissionListener.d.ts|
|新增|NA|类名：MissionListener;<br>方法or属性：onMissionIconUpdated(mission: number, icon: image.PixelMap): void;|MissionListener.d.ts|
|新增|NA|类名：MissionListener;<br>方法or属性：onMissionClosed(mission: number): void;|MissionListener.d.ts|
|新增|NA|类名：MissionParameter;<br>方法or属性：deviceId: string;|MissionParameter.d.ts|
|新增|NA|类名：MissionParameter;<br>方法or属性：fixConflict: boolean;|MissionParameter.d.ts|
|新增|NA|类名：MissionParameter;<br>方法or属性：tag: number;|MissionParameter.d.ts|
|新增|NA|类名：ProcessData;<br>方法or属性：state: number;|ProcessData.d.ts|
|新增|NA|类名：ProcessData;<br>方法or属性：isContinuousTask: boolean;|ProcessData.d.ts|
|新增|NA|类名：ProcessData;<br>方法or属性：isKeepAlive: boolean;|ProcessData.d.ts|
|新增|NA|类名：ProcessInformation;<br>方法or属性：pid: number;|ProcessInformation.d.ts|
|新增|NA|类名：ProcessInformation;<br>方法or属性：uid: number;|ProcessInformation.d.ts|
|新增|NA|类名：ProcessInformation;<br>方法or属性：processName: string;|ProcessInformation.d.ts|
|新增|NA|类名：ProcessInformation;<br>方法or属性：bundleNames: Array\<string>;|ProcessInformation.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startServiceExtensionAbility(want: Want): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：stopServiceExtensionAbility(want: Want): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：terminateSelf(callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：terminateSelf(): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startAbilityByCall(want: Want): Promise\<Caller>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext;<br>方法or属性：startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：abilityInfo: AbilityInfo;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：currentHapModuleInfo: HapModuleInfo;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：config: Configuration;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityByCall(want: Want): Promise\<Caller>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startServiceExtensionAbility(want: Want): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：stopServiceExtensionAbility(want: Want): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：terminateSelf(callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：terminateSelf(): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：terminateSelfWithResult(parameter: AbilityResult): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：setMissionLabel(label: string, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：setMissionLabel(label: string): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：setMissionIcon(icon: image.PixelMap, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：setMissionIcon(icon: image.PixelMap): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：restoreWindowStage(localStorage: LocalStorage): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：isTerminating(): boolean;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：requestDialogService(want: Want, result: AsyncCallback\<dialogRequest.RequestResult>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext;<br>方法or属性：requestDialogService(want: Want): Promise\<dialogRequest.RequestResult>;|UIAbilityContext.d.ts|
|废弃版本有变化|类名：dataUriUtils;<br>方法or属性：declare dataUriUtils<br>旧版本信息：|类名：dataUriUtils;<br>方法or属性：declare dataUriUtils<br>新版本信息：9<br>代替接口： @ohos.app.ability.dataUriUtils.d.ts|@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：dataUriUtils;<br>方法or属性：function getId(uri: string): number<br>旧版本信息：|类名：dataUriUtils;<br>方法or属性：function getId(uri: string): number<br>新版本信息：9<br>代替接口： @ohos.app.ability.dataUriUtils.d.ts|@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：dataUriUtils;<br>方法or属性：function attachId(uri: string, id: number): string<br>旧版本信息：|类名：dataUriUtils;<br>方法or属性：function attachId(uri: string, id: number): string<br>新版本信息：9<br>代替接口： @ohos.app.ability.dataUriUtils.d.ts|@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：dataUriUtils;<br>方法or属性：function deleteId(uri: string): string<br>旧版本信息：|类名：dataUriUtils;<br>方法or属性：function deleteId(uri: string): string<br>新版本信息：9<br>代替接口： @ohos.app.ability.dataUriUtils.d.ts|@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：dataUriUtils;<br>方法or属性：function updateId(uri: string, id: number): string<br>旧版本信息：|类名：dataUriUtils;<br>方法or属性：function updateId(uri: string, id: number): string<br>新版本信息：9<br>代替接口： @ohos.app.ability.dataUriUtils.d.ts|@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：wantConstant;<br>方法or属性：declare wantConstant<br>旧版本信息：|类名：wantConstant;<br>方法or属性：declare wantConstant<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：export enum Action<br>旧版本信息：|类名：Action;<br>方法or属性：export enum Action<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_HOME = "ohos.want.action.home"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_HOME = "ohos.want.action.home"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_DIAL = "ohos.want.action.dial"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_DIAL = "ohos.want.action.dial"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SEARCH = "ohos.want.action.search"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SEARCH = "ohos.want.action.search"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_WIRELESS_SETTINGS = "ohos.settings.wireless"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_WIRELESS_SETTINGS = "ohos.settings.wireless"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_MANAGE_APPLICATIONS_SETTINGS = "ohos.settings.manage.applications"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_MANAGE_APPLICATIONS_SETTINGS = "ohos.settings.manage.applications"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_APPLICATION_DETAILS_SETTINGS = "ohos.settings.application.details"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_APPLICATION_DETAILS_SETTINGS = "ohos.settings.application.details"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SET_ALARM = "ohos.want.action.setAlarm"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SET_ALARM = "ohos.want.action.setAlarm"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SHOW_ALARMS = "ohos.want.action.showAlarms"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SHOW_ALARMS = "ohos.want.action.showAlarms"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SNOOZE_ALARM = "ohos.want.action.snoozeAlarm"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SNOOZE_ALARM = "ohos.want.action.snoozeAlarm"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_DISMISS_ALARM = "ohos.want.action.dismissAlarm"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_DISMISS_ALARM = "ohos.want.action.dismissAlarm"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_DISMISS_TIMER = "ohos.want.action.dismissTimer"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_DISMISS_TIMER = "ohos.want.action.dismissTimer"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SEND_SMS = "ohos.want.action.sendSms"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SEND_SMS = "ohos.want.action.sendSms"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_CHOOSE = "ohos.want.action.choose"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_CHOOSE = "ohos.want.action.choose"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_IMAGE_CAPTURE = "ohos.want.action.imageCapture"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_IMAGE_CAPTURE = "ohos.want.action.imageCapture"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_VIDEO_CAPTURE = "ohos.want.action.videoCapture"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_VIDEO_CAPTURE = "ohos.want.action.videoCapture"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SELECT = "ohos.want.action.select"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SELECT = "ohos.want.action.select"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SEND_DATA = "ohos.want.action.sendData"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SEND_DATA = "ohos.want.action.sendData"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SEND_MULTIPLE_DATA = "ohos.want.action.sendMultipleData"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SEND_MULTIPLE_DATA = "ohos.want.action.sendMultipleData"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_SCAN_MEDIA_FILE = "ohos.want.action.scanMediaFile"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_SCAN_MEDIA_FILE = "ohos.want.action.scanMediaFile"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_VIEW_DATA = "ohos.want.action.viewData"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_VIEW_DATA = "ohos.want.action.viewData"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_EDIT_DATA = "ohos.want.action.editData"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_EDIT_DATA = "ohos.want.action.editData"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：INTENT_PARAMS_INTENT = "ability.want.params.INTENT"<br>旧版本信息：|类名：Action;<br>方法or属性：INTENT_PARAMS_INTENT = "ability.want.params.INTENT"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：INTENT_PARAMS_TITLE = "ability.want.params.TITLE"<br>旧版本信息：|类名：Action;<br>方法or属性：INTENT_PARAMS_TITLE = "ability.want.params.TITLE"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_FILE_SELECT = "ohos.action.fileSelect"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_FILE_SELECT = "ohos.action.fileSelect"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：PARAMS_STREAM = "ability.params.stream"<br>旧版本信息：|类名：Action;<br>方法or属性：PARAMS_STREAM = "ability.params.stream"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Action;<br>方法or属性：ACTION_APP_ACCOUNT_OAUTH = "ohos.account.appAccount.action.oauth"<br>旧版本信息：|类名：Action;<br>方法or属性：ACTION_APP_ACCOUNT_OAUTH = "ohos.account.appAccount.action.oauth"<br>新版本信息：9<br>代替接口： wantConstant.Action#ACTION_APP_ACCOUNT_AUTH|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：export enum Entity<br>旧版本信息：|类名：Entity;<br>方法or属性：export enum Entity<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：ENTITY_DEFAULT = "entity.system.default"<br>旧版本信息：|类名：Entity;<br>方法or属性：ENTITY_DEFAULT = "entity.system.default"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：ENTITY_HOME = "entity.system.home"<br>旧版本信息：|类名：Entity;<br>方法or属性：ENTITY_HOME = "entity.system.home"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：ENTITY_VOICE = "entity.system.voice"<br>旧版本信息：|类名：Entity;<br>方法or属性：ENTITY_VOICE = "entity.system.voice"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：ENTITY_BROWSABLE = "entity.system.browsable"<br>旧版本信息：|类名：Entity;<br>方法or属性：ENTITY_BROWSABLE = "entity.system.browsable"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Entity;<br>方法or属性：ENTITY_VIDEO = "entity.system.video"<br>旧版本信息：|类名：Entity;<br>方法or属性：ENTITY_VIDEO = "entity.system.video"<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：export enum Flags<br>旧版本信息：|类名：Flags;<br>方法or属性：export enum Flags<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_AUTH_READ_URI_PERMISSION = 0x00000001<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_AUTH_READ_URI_PERMISSION = 0x00000001<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_AUTH_WRITE_URI_PERMISSION = 0x00000002<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_AUTH_WRITE_URI_PERMISSION = 0x00000002<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_FORWARD_RESULT = 0x00000004<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_FORWARD_RESULT = 0x00000004<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_CONTINUATION = 0x00000008<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_CONTINUATION = 0x00000008<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_NOT_OHOS_COMPONENT = 0x00000010<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_NOT_OHOS_COMPONENT = 0x00000010<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_FORM_ENABLED = 0x00000020<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_FORM_ENABLED = 0x00000020<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_AUTH_PERSISTABLE_URI_PERMISSION = 0x00000040<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_AUTH_PERSISTABLE_URI_PERMISSION = 0x00000040<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_AUTH_PREFIX_URI_PERMISSION = 0x00000080<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_AUTH_PREFIX_URI_PERMISSION = 0x00000080<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITYSLICE_MULTI_DEVICE = 0x00000100<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITYSLICE_MULTI_DEVICE = 0x00000100<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_START_FOREGROUND_ABILITY = 0x00000200<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_START_FOREGROUND_ABILITY = 0x00000200<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_CONTINUATION_REVERSIBLE = 0x00000400<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_CONTINUATION_REVERSIBLE = 0x00000400<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_INSTALL_ON_DEMAND = 0x00000800<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_INSTALL_ON_DEMAND = 0x00000800<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_INSTALL_WITH_BACKGROUND_MODE = 0x80000000<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_INSTALL_WITH_BACKGROUND_MODE = 0x80000000<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_CLEAR_MISSION = 0x00008000<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_CLEAR_MISSION = 0x00008000<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_NEW_MISSION = 0x10000000<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_NEW_MISSION = 0x10000000<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：Flags;<br>方法or属性：FLAG_ABILITY_MISSION_TOP = 0x20000000<br>旧版本信息：|类名：Flags;<br>方法or属性：FLAG_ABILITY_MISSION_TOP = 0x20000000<br>新版本信息：9<br>代替接口： ohos.app.ability.wantConstant|@ohos.ability.wantConstant.d.ts|
|废弃版本有变化|类名：abilityDelegatorRegistry;<br>方法or属性：declare abilityDelegatorRegistry<br>旧版本信息：|类名：abilityDelegatorRegistry;<br>方法or属性：declare abilityDelegatorRegistry<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：abilityDelegatorRegistry;<br>方法or属性：function getAbilityDelegator(): AbilityDelegator;<br>旧版本信息：|类名：abilityDelegatorRegistry;<br>方法or属性：function getAbilityDelegator(): AbilityDelegator;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：abilityDelegatorRegistry;<br>方法or属性：function getArguments(): AbilityDelegatorArgs;<br>旧版本信息：|类名：abilityDelegatorRegistry;<br>方法or属性：function getArguments(): AbilityDelegatorArgs;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：export enum AbilityLifecycleState<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：export enum AbilityLifecycleState<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：UNINITIALIZED<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：UNINITIALIZED<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：CREATE<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：CREATE<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：FOREGROUND<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：FOREGROUND<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：BACKGROUND<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：BACKGROUND<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：AbilityLifecycleState;<br>方法or属性：DESTROY<br>旧版本信息：|类名：AbilityLifecycleState;<br>方法or属性：DESTROY<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityDelegatorRegistry|@ohos.application.abilityDelegatorRegistry.d.ts|
|废弃版本有变化|类名：abilityManager;<br>方法or属性：declare abilityManager<br>旧版本信息：|类名：abilityManager;<br>方法or属性：declare abilityManager<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration): Promise\<void>;<br>旧版本信息：|类名：abilityManager;<br>方法or属性：function updateConfiguration(config: Configuration): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>;<br>旧版本信息：|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void;<br>旧版本信息：|类名：abilityManager;<br>方法or属性：function getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：export enum AbilityState<br>旧版本信息：|类名：AbilityState;<br>方法or属性：export enum AbilityState<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：INITIAL = 0<br>旧版本信息：|类名：AbilityState;<br>方法or属性：INITIAL = 0<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：FOREGROUND = 9<br>旧版本信息：|类名：AbilityState;<br>方法or属性：FOREGROUND = 9<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：BACKGROUND = 10<br>旧版本信息：|类名：AbilityState;<br>方法or属性：BACKGROUND = 10<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：FOREGROUNDING = 11<br>旧版本信息：|类名：AbilityState;<br>方法or属性：FOREGROUNDING = 11<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：AbilityState;<br>方法or属性：BACKGROUNDING = 12<br>旧版本信息：|类名：AbilityState;<br>方法or属性：BACKGROUNDING = 12<br>新版本信息：9<br>代替接口： ohos.app.ability.abilityManager|@ohos.application.abilityManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：declare appManager<br>旧版本信息：|类名：appManager;<br>方法or属性：declare appManager<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function registerApplicationStateObserver(observer: ApplicationStateObserver): number;<br>旧版本信息：|类名：appManager;<br>方法or属性：function registerApplicationStateObserver(observer: ApplicationStateObserver): number;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function unregisterApplicationStateObserver(observerId: number): Promise\<void>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function unregisterApplicationStateObserver(observerId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getForegroundApplications(): Promise\<Array\<AppStateData>>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getForegroundApplications(): Promise\<Array\<AppStateData>>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number): Promise\<void>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(): Promise\<boolean>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function isRunningInStabilityTest(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager#getRunningProcessInformation|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager#getRunningProcessInformation|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string): Promise\<void>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);<br>旧版本信息：|类名：appManager;<br>方法or属性：function killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string): Promise\<void>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);<br>旧版本信息：|类名：appManager;<br>方法or属性：function clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(): Promise\<boolean>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getAppMemorySize(): Promise\<number>;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getAppMemorySize(): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：appManager;<br>方法or属性：function getAppMemorySize(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：appManager;<br>方法or属性：function getAppMemorySize(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.appManager|@ohos.application.appManager.d.ts|
|废弃版本有变化|类名：Configuration;<br>方法or属性：export interface Configuration<br>旧版本信息：|类名：Configuration;<br>方法or属性：export interface Configuration<br>新版本信息：9<br>代替接口： ohos.app.ability.Configuration|@ohos.application.Configuration.d.ts|
|废弃版本有变化|类名：Configuration;<br>方法or属性：language?: string;<br>旧版本信息：|类名：Configuration;<br>方法or属性：language?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Configuration|@ohos.application.Configuration.d.ts|
|废弃版本有变化|类名：Configuration;<br>方法or属性：colorMode?: ConfigurationConstant.ColorMode;<br>旧版本信息：|类名：Configuration;<br>方法or属性：colorMode?: ConfigurationConstant.ColorMode;<br>新版本信息：9<br>代替接口： ohos.app.ability.Configuration|@ohos.application.Configuration.d.ts|
|废弃版本有变化|类名：ConfigurationConstant;<br>方法or属性：declare ConfigurationConstant<br>旧版本信息：|类名：ConfigurationConstant;<br>方法or属性：declare ConfigurationConstant<br>新版本信息：9<br>代替接口： ohos.app.ability.ConfigurationConstant|@ohos.application.ConfigurationConstant.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：export enum ColorMode<br>旧版本信息：|类名：ColorMode;<br>方法or属性：export enum ColorMode<br>新版本信息：9<br>代替接口： ohos.app.ability.ConfigurationConstant|@ohos.application.ConfigurationConstant.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：COLOR_MODE_NOT_SET = -1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：COLOR_MODE_NOT_SET = -1<br>新版本信息：9<br>代替接口： ohos.app.ability.ConfigurationConstant|@ohos.application.ConfigurationConstant.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：COLOR_MODE_DARK = 0<br>旧版本信息：|类名：ColorMode;<br>方法or属性：COLOR_MODE_DARK = 0<br>新版本信息：9<br>代替接口： ohos.app.ability.ConfigurationConstant|@ohos.application.ConfigurationConstant.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：COLOR_MODE_LIGHT = 1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：COLOR_MODE_LIGHT = 1<br>新版本信息：9<br>代替接口： ohos.app.ability.ConfigurationConstant|@ohos.application.ConfigurationConstant.d.ts|
|废弃版本有变化|类名：formBindingData;<br>方法or属性：declare formBindingData<br>旧版本信息：|类名：formBindingData;<br>方法or属性：declare formBindingData<br>新版本信息：9<br>代替接口： ohos.app.form.formBindingData|@ohos.application.formBindingData.d.ts|
|废弃版本有变化|类名：formBindingData;<br>方法or属性：function createFormBindingData(obj?: Object \| string): FormBindingData;<br>旧版本信息：|类名：formBindingData;<br>方法or属性：function createFormBindingData(obj?: Object \| string): FormBindingData;<br>新版本信息：9<br>代替接口： ohos.app.form.formBindingData|@ohos.application.formBindingData.d.ts|
|废弃版本有变化|类名：FormBindingData;<br>方法or属性：interface FormBindingData<br>旧版本信息：|类名：FormBindingData;<br>方法or属性：interface FormBindingData<br>新版本信息：9<br>代替接口： ohos.app.form.formBindingData|@ohos.application.formBindingData.d.ts|
|废弃版本有变化|类名：FormBindingData;<br>方法or属性：data: Object<br>旧版本信息：|类名：FormBindingData;<br>方法or属性：data: Object<br>新版本信息：9<br>代替接口： ohos.app.form.formBindingData|@ohos.application.formBindingData.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：declare formHost<br>旧版本信息：|类名：formHost;<br>方法or属性：declare formHost<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function deleteForm(formId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function deleteForm(formId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function deleteForm(formId: string): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function deleteForm(formId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function releaseForm(formId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function releaseForm(formId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache?: boolean): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function releaseForm(formId: string, isReleaseCache?: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function requestForm(formId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function requestForm(formId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function requestForm(formId: string): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function requestForm(formId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function castTempForm(formId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function castTempForm(formId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function castTempForm(formId: string): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function castTempForm(formId: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyVisibleForms(formIds: Array\<string>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyInvisibleForms(formIds: Array\<string>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function enableFormsUpdate(formIds: Array\<string>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function disableFormsUpdate(formIds: Array\<string>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function isSystemReady(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function isSystemReady(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function isSystemReady(): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function isSystemReady(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function getAllFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function getAllFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function getAllFormsInfo(): Promise\<Array\<formInfo.FormInfo>>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function getAllFormsInfo(): Promise\<Array\<formInfo.FormInfo>>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName?: string): Promise\<Array\<formInfo.FormInfo>>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function getFormsInfo(bundleName: string, moduleName?: string): Promise\<Array\<formInfo.FormInfo>>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>): Promise\<number>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function deleteInvalidForms(formIds: Array\<string>): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function on(type: "formUninstall", callback: Callback\<string>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function on(type: "formUninstall", callback: Callback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function off(type: "formUninstall", callback?: Callback\<string>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function off(type: "formUninstall", callback?: Callback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyFormsVisible(formIds: Array\<string>, isVisible: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean): Promise\<void>;<br>旧版本信息：|类名：formHost;<br>方法or属性：function notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formHost|@ohos.application.formHost.d.ts|
|废弃版本有变化|类名：formInfo;<br>方法or属性：declare formInfo<br>旧版本信息：|类名：formInfo;<br>方法or属性：declare formInfo<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：interface FormInfo<br>旧版本信息：|类名：FormInfo;<br>方法or属性：interface FormInfo<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：bundleName: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：moduleName: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：moduleName: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：abilityName: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：abilityName: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：description: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：description: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：type: FormType;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：type: FormType;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：jsComponentName: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：jsComponentName: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：colorMode: ColorMode;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：colorMode: ColorMode;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：isDefault: boolean;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：isDefault: boolean;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：updateEnabled: boolean;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：updateEnabled: boolean;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：formVisibleNotify: boolean;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：formVisibleNotify: boolean;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：relatedBundleName: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：relatedBundleName: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：scheduledUpdateTime: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：scheduledUpdateTime: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：formConfigAbility: string;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：formConfigAbility: string;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：updateDuration: number;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：updateDuration: number;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：defaultDimension: number;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：defaultDimension: number;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：supportDimensions: Array\<number>;<br>旧版本信息：|类名：FormInfo;<br>方法or属性：supportDimensions: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormInfo;<br>方法or属性：customizeData: {[key: string]: [value: string]};<br>旧版本信息：|类名：FormInfo;<br>方法or属性：customizeData: {[key: string]: [value: string]};<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormType;<br>方法or属性：enum FormType<br>旧版本信息：|类名：FormType;<br>方法or属性：enum FormType<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormType;<br>方法or属性：JS = 1<br>旧版本信息：|类名：FormType;<br>方法or属性：JS = 1<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：enum ColorMode<br>旧版本信息：|类名：ColorMode;<br>方法or属性：enum ColorMode<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：MODE_AUTO = -1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：MODE_AUTO = -1<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：MODE_DARK = 0<br>旧版本信息：|类名：ColorMode;<br>方法or属性：MODE_DARK = 0<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：MODE_LIGHT = 1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：MODE_LIGHT = 1<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormStateInfo;<br>方法or属性：interface FormStateInfo<br>旧版本信息：|类名：FormStateInfo;<br>方法or属性：interface FormStateInfo<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormStateInfo;<br>方法or属性：formState: FormState;<br>旧版本信息：|类名：FormStateInfo;<br>方法or属性：formState: FormState;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormStateInfo;<br>方法or属性：want: Want;<br>旧版本信息：|类名：FormStateInfo;<br>方法or属性：want: Want;<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormState;<br>方法or属性：enum FormState<br>旧版本信息：|类名：FormState;<br>方法or属性：enum FormState<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormState;<br>方法or属性：UNKNOWN = -1<br>旧版本信息：|类名：FormState;<br>方法or属性：UNKNOWN = -1<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormState;<br>方法or属性：DEFAULT = 0<br>旧版本信息：|类名：FormState;<br>方法or属性：DEFAULT = 0<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormState;<br>方法or属性：READY = 1<br>旧版本信息：|类名：FormState;<br>方法or属性：READY = 1<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：enum FormParam<br>旧版本信息：|类名：FormParam;<br>方法or属性：enum FormParam<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>旧版本信息：|类名：FormParam;<br>方法or属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：DIMENSION_KEY = "ohos.extra.param.key.form_dimension"<br>旧版本信息：|类名：FormParam;<br>方法or属性：DIMENSION_KEY = "ohos.extra.param.key.form_dimension"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：NAME_KEY = "ohos.extra.param.key.form_name"<br>旧版本信息：|类名：FormParam;<br>方法or属性：NAME_KEY = "ohos.extra.param.key.form_name"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：MODULE_NAME_KEY = "ohos.extra.param.key.module_name"<br>旧版本信息：|类名：FormParam;<br>方法or属性：MODULE_NAME_KEY = "ohos.extra.param.key.module_name"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：WIDTH_KEY = "ohos.extra.param.key.form_width"<br>旧版本信息：|类名：FormParam;<br>方法or属性：WIDTH_KEY = "ohos.extra.param.key.form_width"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：HEIGHT_KEY = "ohos.extra.param.key.form_height"<br>旧版本信息：|类名：FormParam;<br>方法or属性：HEIGHT_KEY = "ohos.extra.param.key.form_height"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：FormParam;<br>方法or属性：TEMPORARY_KEY = "ohos.extra.param.key.form_temporary"<br>旧版本信息：|类名：FormParam;<br>方法or属性：TEMPORARY_KEY = "ohos.extra.param.key.form_temporary"<br>新版本信息：9<br>代替接口： ohos.app.form.formInfo|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：formProvider;<br>方法or属性：declare formProvider<br>旧版本信息：|类名：formProvider;<br>方法or属性：declare formProvider<br>新版本信息：9<br>代替接口： ohos.app.form.formProvider|@ohos.application.formProvider.d.ts|
|废弃版本有变化|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formProvider|@ohos.application.formProvider.d.ts|
|废弃版本有变化|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number): Promise\<void>;<br>旧版本信息：|类名：formProvider;<br>方法or属性：function setFormNextRefreshTime(formId: string, minute: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formProvider|@ohos.application.formProvider.d.ts|
|废弃版本有变化|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData,<br><br>        callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData,<br><br>        callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.form.formProvider|@ohos.application.formProvider.d.ts|
|废弃版本有变化|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>;<br>旧版本信息：|类名：formProvider;<br>方法or属性：function updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.form.formProvider|@ohos.application.formProvider.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：declare missionManager<br>旧版本信息：|类名：missionManager;<br>方法or属性：declare missionManager<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function registerMissionListener(listener: MissionListener): number;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function registerMissionListener(listener: MissionListener): number;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function unregisterMissionListener(listenerId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function unregisterMissionListener(listenerId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function unregisterMissionListener(listenerId: number): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function unregisterMissionListener(listenerId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback\<MissionInfo>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback\<MissionInfo>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number): Promise\<MissionInfo>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionInfo(deviceId: string, missionId: number): Promise\<MissionInfo>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback\<Array\<MissionInfo>>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback\<Array\<MissionInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number): Promise\<Array\<MissionInfo>>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionInfos(deviceId: string, numMax: number): Promise\<Array\<MissionInfo>>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function getMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function lockMission(missionId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function lockMission(missionId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function lockMission(missionId: number): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function lockMission(missionId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function unlockMission(missionId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function clearMission(missionId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function clearMission(missionId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function clearMission(missionId: number): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function clearMission(missionId: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function clearAllMissions(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function clearAllMissions(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function clearAllMissions(): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function clearAllMissions(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options?: StartOptions): Promise\<void>;<br>旧版本信息：|类名：missionManager;<br>方法or属性：function moveMissionToFront(missionId: number, options?: StartOptions): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.missionManager|@ohos.application.missionManager.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：export default class Want<br>旧版本信息：|类名：Want;<br>方法or属性：export default class Want<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：deviceId?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：bundleName?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：abilityName?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：abilityName?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：uri?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：uri?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：type?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：type?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：flags?: number;<br>旧版本信息：|类名：Want;<br>方法or属性：flags?: number;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：action?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：action?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：parameters?: {[key: string]: any};<br>旧版本信息：|类名：Want;<br>方法or属性：parameters?: {[key: string]: any};<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：entities?: Array\<string>;<br>旧版本信息：|类名：Want;<br>方法or属性：entities?: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|@ohos.application.Want.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#on/off(type:|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function on(type: "deviceDisconnect", callback: Callback\<string>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function on(type: "deviceDisconnect", callback: Callback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#on/off(type:|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function register(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function register(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#registerContinuation|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#registerContinuation|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function register(options?: ContinuationExtraParams): Promise\<number>;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function register(options?: ContinuationExtraParams): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#registerContinuation|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function unregister(token: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function unregister(token: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#unregisterContinuation|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function unregister(token: number): Promise\<void>;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function unregister(token: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#unregisterContinuation|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#updateContinuationState|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#updateContinuationState|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#startContinuationDeviceManager|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#startContinuationDeviceManager|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;<br>旧版本信息：|类名：continuationManager;<br>方法or属性：function startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.continuation.continuationManager.continuationManager#startContinuationDeviceManager|@ohos.continuation.continuationManager.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：declare wantAgent<br>旧版本信息：|类名：wantAgent;<br>方法or属性：declare wantAgent<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent): Promise\<string>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getBundleName(agent: WantAgent): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent): Promise\<number>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getUid(agent: WantAgent): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent, callback: AsyncCallback\<Want>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent, callback: AsyncCallback\<Want>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent): Promise\<Want>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getWant(agent: WantAgent): Promise\<Want>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent): Promise\<void>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function cancel(agent: WantAgent): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent>): void;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent>): void;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo): Promise\<WantAgent>;<br>旧版本信息：|类名：wantAgent;<br>方法or属性：function getWantAgent(info: WantAgentInfo): Promise\<WantAgent>;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：export enum WantAgentFlags<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：export enum WantAgentFlags<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：ONE_TIME_FLAG = 0<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：ONE_TIME_FLAG = 0<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：NO_BUILD_FLAG<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：NO_BUILD_FLAG<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：CANCEL_PRESENT_FLAG<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：CANCEL_PRESENT_FLAG<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：UPDATE_PRESENT_FLAG<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：UPDATE_PRESENT_FLAG<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：CONSTANT_FLAG<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：CONSTANT_FLAG<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：REPLACE_ELEMENT<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：REPLACE_ELEMENT<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：REPLACE_ACTION<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：REPLACE_ACTION<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：REPLACE_URI<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：REPLACE_URI<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：REPLACE_ENTITIES<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：REPLACE_ENTITIES<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：WantAgentFlags;<br>方法or属性：REPLACE_BUNDLE<br>旧版本信息：|类名：WantAgentFlags;<br>方法or属性：REPLACE_BUNDLE<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：export enum OperationType<br>旧版本信息：|类名：OperationType;<br>方法or属性：export enum OperationType<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：UNKNOWN_TYPE = 0<br>旧版本信息：|类名：OperationType;<br>方法or属性：UNKNOWN_TYPE = 0<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：START_ABILITY<br>旧版本信息：|类名：OperationType;<br>方法or属性：START_ABILITY<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：START_ABILITIES<br>旧版本信息：|类名：OperationType;<br>方法or属性：START_ABILITIES<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：START_SERVICE<br>旧版本信息：|类名：OperationType;<br>方法or属性：START_SERVICE<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：OperationType;<br>方法or属性：SEND_COMMON_EVENT<br>旧版本信息：|类名：OperationType;<br>方法or属性：SEND_COMMON_EVENT<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：export interface CompleteData<br>旧版本信息：|类名：CompleteData;<br>方法or属性：export interface CompleteData<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：info: WantAgent;<br>旧版本信息：|类名：CompleteData;<br>方法or属性：info: WantAgent;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：want: Want;<br>旧版本信息：|类名：CompleteData;<br>方法or属性：want: Want;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：finalCode: number;<br>旧版本信息：|类名：CompleteData;<br>方法or属性：finalCode: number;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：finalData: string;<br>旧版本信息：|类名：CompleteData;<br>方法or属性：finalData: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：CompleteData;<br>方法or属性：extraInfo?: {[key: string]: any};<br>旧版本信息：|类名：CompleteData;<br>方法or属性：extraInfo?: {[key: string]: any};<br>新版本信息：9<br>代替接口： ohos.app.ability.wantAgent|@ohos.wantAgent.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：export declare interface Want<br>旧版本信息：|类名：Want;<br>方法or属性：export declare interface Want<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：deviceId?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：bundleName?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：abilityName?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：abilityName?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：uri?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：uri?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：type?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：type?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：flags?: number;<br>旧版本信息：|类名：Want;<br>方法or属性：flags?: number;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：action?: string;<br>旧版本信息：|类名：Want;<br>方法or属性：action?: string;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：parameters?: {[key: string]: any};<br>旧版本信息：|类名：Want;<br>方法or属性：parameters?: {[key: string]: any};<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Want;<br>方法or属性：entities?: Array\<string>;<br>旧版本信息：|类名：Want;<br>方法or属性：entities?: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.app.ability.Want|want.d.ts|
|废弃版本有变化|类名：Context;<br>方法or属性：setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void<br>旧版本信息：|类名：Context;<br>方法or属性：setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void<br>新版本信息：9<br>代替接口： ohos.window#setShowOnLockScreen|context.d.ts|
|废弃版本有变化|类名：ProcessRunningInfo;<br>方法or属性：export interface ProcessRunningInfo<br>旧版本信息：|类名：ProcessRunningInfo;<br>方法or属性：export interface ProcessRunningInfo<br>新版本信息：9<br>代替接口： ProcessInformation|ProcessRunningInfo.d.ts|
|废弃版本有变化|类名：ProcessRunningInfo;<br>方法or属性：pid: number;<br>旧版本信息：|类名：ProcessRunningInfo;<br>方法or属性：pid: number;<br>新版本信息：9<br>代替接口： ProcessInformation.pid|ProcessRunningInfo.d.ts|
|废弃版本有变化|类名：ProcessRunningInfo;<br>方法or属性：uid: number;<br>旧版本信息：|类名：ProcessRunningInfo;<br>方法or属性：uid: number;<br>新版本信息：9<br>代替接口： ProcessInformation.uid|ProcessRunningInfo.d.ts|
|废弃版本有变化|类名：ProcessRunningInfo;<br>方法or属性：processName: string;<br>旧版本信息：|类名：ProcessRunningInfo;<br>方法or属性：processName: string;<br>新版本信息：9<br>代替接口： ProcessInformation.processName|ProcessRunningInfo.d.ts|
|废弃版本有变化|类名：ProcessRunningInfo;<br>方法or属性：bundleNames: Array\<string>;<br>旧版本信息：|类名：ProcessRunningInfo;<br>方法or属性：bundleNames: Array\<string>;<br>新版本信息：9<br>代替接口： ProcessInformation.bundleNames|ProcessRunningInfo.d.ts|
|访问级别有变化|类名：abilityManager;<br>方法or属性：declare abilityManager<br>旧版本信息：|类名：abilityManager;<br>方法or属性：declare abilityManager<br>新版本信息：systemapi|@ohos.application.abilityManager.d.ts|
|权限有变化|类名：formHost;<br>方法or属性：function acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void;<br>旧版本信息：ohos.permission.GET_BUNDLE_INFO,ohos.permission.GET_BUNDLE_INFO_PRIVILEGED|类名：formHost;<br>方法or属性：function acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void;<br>新版本信息：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED,ohos.permission.REQUIRE_FORM|@ohos.application.formHost.d.ts|
|权限有变化|类名：formHost;<br>方法or属性：function acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>;<br>旧版本信息：ohos.permission.GET_BUNDLE_INFO,ohos.permission.GET_BUNDLE_INFO_PRIVILEGED|类名：formHost;<br>方法or属性：function acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>;<br>新版本信息：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED,ohos.permission.REQUIRE_FORM|@ohos.application.formHost.d.ts|
|函数有变化|类名：ShellCmdResult;<br>方法or属性：stdResult: String;|类名：ShellCmdResult;<br>方法or属性：stdResult: string;|shellCmdResult.d.ts|
