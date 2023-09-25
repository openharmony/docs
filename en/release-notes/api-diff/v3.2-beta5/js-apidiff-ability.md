| Change Type | Old Version | New Version | .d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.app.ability.dataUriUtils<br>Class name: dataUriUtils|@ohos.app.ability.dataUriUtils.d.ts|
|Added|NA|Module name: ohos.app.ability.dataUriUtils<br>Class name: dataUriUtils<br>Method or attribute name: function getId(uri: string): number|@ohos.app.ability.dataUriUtils.d.ts|
|Added|NA|Module name: ohos.app.ability.dataUriUtils<br>Class name: dataUriUtils<br>Method or attribute name: function attachId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|Added|NA|Module name: ohos.app.ability.dataUriUtils<br>Class name: dataUriUtils<br>Method or attribute name: function deleteId(uri: string): string|@ohos.app.ability.dataUriUtils.d.ts|
|Added|NA|Module name: ohos.app.ability.dataUriUtils<br>Class name: dataUriUtils<br>Method or attribute name: function updateId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|Added|NA|Module name: ohos.app.ability.EnvironmentCallback<br>Class name: EnvironmentCallback<br>Method or attribute name: onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|@ohos.app.ability.EnvironmentCallback.d.ts|
|Deleted|Module name: ohos.app.ability.wantAgent<br>Class name: wantAgent<br>Method or attribute name: function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void;|NA|@ohos.app.ability.wantAgent.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: OnReleaseCallBack|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: OnReleaseCallBack<br>Method or attribute name: (msg: string): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: CalleeCallBack|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: CalleeCallBack<br>Method or attribute name: (indata: rpc.MessageParcel): rpc.Sequenceable;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Caller|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Caller<br>Method or attribute name: call(method: string, data: rpc.Sequenceable): Promise<void>;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Caller<br>Method or attribute name: callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Caller<br>Method or attribute name: release(): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Caller<br>Method or attribute name: onRelease(callback: OnReleaseCallBack): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Callee|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Callee<br>Method or attribute name: on(method: string, callback: CalleeCallBack): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Callee<br>Method or attribute name: off(method: string): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: context: AbilityContext;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: launchWant: Want;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: lastRequestWant: Want;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: callee: Callee;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onWindowStageCreate(windowStage: window.WindowStage): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onWindowStageDestroy(): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onWindowStageRestore(windowStage: window.WindowStage): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onDestroy(): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onForeground(): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onBackground(): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: dump(params: Array<string>): Array<string>;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.Ability<br>Class name: Ability<br>Method or attribute name: onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: any}): AbilityConstant.OnSaveResult;|NA|@ohos.application.Ability.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: AbilityConstant|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchParam|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchParam<br>Method or attribute name: launchReason: LaunchReason;|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchParam<br>Method or attribute name: lastExitReason: LastExitReason;|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason<br>Method or attribute name: UNKNOWN = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason<br>Method or attribute name: START_ABILITY = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason<br>Method or attribute name: CALL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason<br>Method or attribute name: CONTINUATION = 3|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LaunchReason<br>Method or attribute name: APP_RECOVERY = 4|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LastExitReason|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LastExitReason<br>Method or attribute name: UNKNOWN = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LastExitReason<br>Method or attribute name: ABILITY_NOT_RESPONDING = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: LastExitReason<br>Method or attribute name: NORMAL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnContinueResult|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnContinueResult<br>Method or attribute name: AGREE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnContinueResult<br>Method or attribute name: REJECT = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnContinueResult<br>Method or attribute name: MISMATCH = 2|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: MemoryLevel|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: MemoryLevel<br>Method or attribute name: MEMORY_LEVEL_MODERATE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: MemoryLevel<br>Method or attribute name: MEMORY_LEVEL_LOW = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: MemoryLevel<br>Method or attribute name: MEMORY_LEVEL_CRITICAL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode<br>Method or attribute name: WINDOW_MODE_UNDEFINED = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode<br>Method or attribute name: WINDOW_MODE_FULLSCREEN = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode<br>Method or attribute name: WINDOW_MODE_SPLIT_PRIMARY = 100|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode<br>Method or attribute name: WINDOW_MODE_SPLIT_SECONDARY = 101|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: WindowMode<br>Method or attribute name: WINDOW_MODE_FLOATING = 102|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: ALL_AGREE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: CONTINUATION_REJECT = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: CONTINUATION_MISMATCH = 2|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: RECOVERY_AGREE = 3|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: RECOVERY_REJECT = 4|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: OnSaveResult<br>Method or attribute name: ALL_REJECT|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: StateType|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: StateType<br>Method or attribute name: CONTINUATION = 0|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityConstant<br>Class name: StateType<br>Method or attribute name: APP_RECOVERY = 1|NA|@ohos.application.AbilityConstant.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onAbilityCreate(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onWindowStageCreate(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onWindowStageActive(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onWindowStageInactive(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onWindowStageDestroy(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onAbilityDestroy(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onAbilityForeground(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onAbilityBackground(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.AbilityLifecycleCallback<br>Class name: AbilityLifecycleCallback<br>Method or attribute name: onAbilityContinue(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|Deleted|Module name: ohos.application.abilityManager<br>Class name: abilityManager<br>Method or attribute name: function getExtensionRunningInfos(upperLimit: number): Promise<Array<ExtensionRunningInfo>>;|NA|@ohos.application.abilityManager.d.ts|
|Deleted|Module name: ohos.application.abilityManager<br>Class name: abilityManager<br>Method or attribute name: function getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback<Array<ExtensionRunningInfo>>): void;|NA|@ohos.application.abilityManager.d.ts|
|Deleted|Module name: ohos.application.abilityManager<br>Class name: abilityManager<br>Method or attribute name: function getTopAbility(): Promise<ElementName>;|NA|@ohos.application.abilityManager.d.ts|
|Deleted|Module name: ohos.application.abilityManager<br>Class name: abilityManager<br>Method or attribute name: function getTopAbility(callback: AsyncCallback<ElementName>): void;|NA|@ohos.application.abilityManager.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage<br>Method or attribute name: context: AbilityStageContext;|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage<br>Method or attribute name: onCreate(): void;|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage<br>Method or attribute name: onAcceptWant(want: Want): string;|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage<br>Method or attribute name: onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.AbilityStage<br>Class name: AbilityStage<br>Method or attribute name: onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.AbilityStage.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState<br>Method or attribute name: STATE_CREATE|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState<br>Method or attribute name: STATE_FOREGROUND|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState<br>Method or attribute name: STATE_ACTIVE|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState<br>Method or attribute name: STATE_BACKGROUND|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ApplicationState<br>Method or attribute name: STATE_DESTROY|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState<br>Method or attribute name: STATE_CREATE|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState<br>Method or attribute name: STATE_FOREGROUND|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState<br>Method or attribute name: STATE_ACTIVE|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState<br>Method or attribute name: STATE_BACKGROUND|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: ProcessState<br>Method or attribute name: STATE_DESTROY|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: appManager<br>Method or attribute name: function registerApplicationStateObserver(observer: ApplicationStateObserver, bundleNameList: Array<string>): number;|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: appManager<br>Method or attribute name: function getProcessRunningInformation(): Promise<Array<ProcessRunningInformation>>;|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.appManager<br>Class name: appManager<br>Method or attribute name: function getProcessRunningInformation(callback: AsyncCallback<Array<ProcessRunningInformation>>): void;|NA|@ohos.application.appManager.d.ts|
|Deleted|Module name: ohos.application.Configuration<br>Class name: Configuration<br>Method or attribute name: direction?: ConfigurationConstant.Direction;|NA|@ohos.application.Configuration.d.ts|
|Deleted|Module name: ohos.application.Configuration<br>Class name: Configuration<br>Method or attribute name: screenDensity?: ConfigurationConstant.ScreenDensity;|NA|@ohos.application.Configuration.d.ts|
|Deleted|Module name: ohos.application.Configuration<br>Class name: Configuration<br>Method or attribute name: displayId?: number;|NA|@ohos.application.Configuration.d.ts|
|Deleted|Module name: ohos.application.Configuration<br>Class name: Configuration<br>Method or attribute name: hasPointerDevice?: boolean;|NA|@ohos.application.Configuration.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: Direction|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: Direction<br>Method or attribute name: DIRECTION_NOT_SET = -1|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: Direction<br>Method or attribute name: DIRECTION_VERTICAL = 0|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: Direction<br>Method or attribute name: DIRECTION_HORIZONTAL = 1|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_NOT_SET = 0|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_SDPI = 120|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_MDPI = 160|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_LDPI = 240|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_XLDPI = 320|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_XXLDPI = 480|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.ConfigurationConstant<br>Class name: ScreenDensity<br>Method or attribute name: SCREEN_DENSITY_XXXLDPI = 640|NA|@ohos.application.ConfigurationConstant.d.ts|
|Deleted|Module name: ohos.application.context<br>Class name: context|NA|@ohos.application.context.d.ts|
|Deleted|Module name: ohos.application.EnvironmentCallback<br>Class name: EnvironmentCallback|NA|@ohos.application.EnvironmentCallback.d.ts|
|Deleted|Module name: ohos.application.EnvironmentCallback<br>Class name: EnvironmentCallback<br>Method or attribute name: onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.EnvironmentCallback.d.ts|
|Deleted|Module name: ohos.application.errorManager<br>Class name: errorManager|NA|@ohos.application.errorManager.d.ts|
|Deleted|Module name: ohos.application.errorManager<br>Class name: errorManager<br>Method or attribute name: function registerErrorObserver(observer: ErrorObserver): number;|NA|@ohos.application.errorManager.d.ts|
|Deleted|Module name: ohos.application.errorManager<br>Class name: errorManager<br>Method or attribute name: function unregisterErrorObserver(observerId: number,  callback: AsyncCallback<void>): void;|NA|@ohos.application.errorManager.d.ts|
|Deleted|Module name: ohos.application.errorManager<br>Class name: errorManager<br>Method or attribute name: function unregisterErrorObserver(observerId: number): Promise<void>;|NA|@ohos.application.errorManager.d.ts|
|Deleted|Module name: ohos.application.ExtensionAbility<br>Class name: ExtensionAbility|NA|@ohos.application.ExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ExtensionAbility<br>Class name: ExtensionAbility<br>Method or attribute name: onConfigurationUpdated(newConfig: Configuration): void;|NA|@ohos.application.ExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ExtensionAbility<br>Class name: ExtensionAbility<br>Method or attribute name: onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.ExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: context: FormExtensionContext;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onCreate(want: Want): formBindingData.FormBindingData;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onCastToNormal(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onUpdate(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onVisibilityChange(newStatus: { [key: string]: number }): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onEvent(formId: string, message: string): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onDestroy(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onAcquireFormState?(want: Want): formInfo.FormState;|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.FormExtension<br>Class name: FormExtension<br>Method or attribute name: onShare?(formId: string): {[key: string]: any};|NA|@ohos.application.FormExtension.d.ts|
|Deleted|Module name: ohos.application.formHost<br>Class name: formHost<br>Method or attribute name: function shareForm(formId: string, deviceId: string, callback: AsyncCallback<void>): void;|NA|@ohos.application.formHost.d.ts|
|Deleted|Module name: ohos.application.formHost<br>Class name: formHost<br>Method or attribute name: function shareForm(formId: string, deviceId: string): Promise<void>;|NA|@ohos.application.formHost.d.ts|
|Deleted|Module name: ohos.application.formHost<br>Class name: formHost<br>Method or attribute name: function notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean, callback: AsyncCallback<void>): void;|NA|@ohos.application.formHost.d.ts|
|Deleted|Module name: ohos.application.formHost<br>Class name: formHost<br>Method or attribute name: function notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean): Promise<void>;|NA|@ohos.application.formHost.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormType<br>Method or attribute name: eTS = 2|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormParam<br>Method or attribute name: BUNDLE_NAME_KEY = "ohos.extra.param.key.bundle_name"|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormParam<br>Method or attribute name: ABILITY_NAME_KEY = "ohos.extra.param.key.ability_name"|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormParam<br>Method or attribute name: DEVICE_ID_KEY = "ohos.extra.param.key.device_id"|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormInfoFilter|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormInfoFilter<br>Method or attribute name: moduleName?: string;|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension<br>Method or attribute name: Dimension_1_2 = 1|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension<br>Method or attribute name: Dimension_2_2|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension<br>Method or attribute name: Dimension_2_4|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension<br>Method or attribute name: Dimension_4_4|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: FormDimension<br>Method or attribute name: Dimension_2_1|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: VisibilityType|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: VisibilityType<br>Method or attribute name: FORM_VISIBLE = 1|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formInfo<br>Class name: VisibilityType<br>Method or attribute name: FORM_INVISIBLE|NA|@ohos.application.formInfo.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback<Array<formInfo.FormInfo>>): void;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function getFormsInfo(callback: AsyncCallback<Array<formInfo.FormInfo>>): void;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function getFormsInfo(filter?: formInfo.FormInfoFilter): Promise<Array<formInfo.FormInfo>>;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData,<br><br>        callback: AsyncCallback<string>): void;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function requestPublishForm(want: Want, callback: AsyncCallback<string>): void;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise<string>;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function isRequestPublishFormSupported(callback: AsyncCallback<boolean>): void;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.formProvider<br>Class name: formProvider<br>Method or attribute name: function isRequestPublishFormSupported(): Promise<boolean>;|NA|@ohos.application.formProvider.d.ts|
|Deleted|Module name: ohos.application.missionManager<br>Class name: missionManager<br>Method or attribute name: function getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void;|NA|@ohos.application.missionManager.d.ts|
|Deleted|Module name: ohos.application.missionManager<br>Class name: missionManager<br>Method or attribute name: function getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>;|NA|@ohos.application.missionManager.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: context: ServiceExtensionContext;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onCreate(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onDestroy(): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onRequest(want: Want, startId: number): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onConnect(want: Want): rpc.RemoteObject;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onDisconnect(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onReconnect(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.ServiceExtensionAbility<br>Class name: ServiceExtensionAbility<br>Method or attribute name: dump(params: Array<string>): Array<string>;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|Deleted|Module name: ohos.application.StartOptions<br>Class name: StartOptions|NA|@ohos.application.StartOptions.d.ts|
|Deleted|Module name: ohos.application.StartOptions<br>Class name: StartOptions<br>Method or attribute name: windowMode?: number;|NA|@ohos.application.StartOptions.d.ts|
|Deleted|Module name: ohos.application.StartOptions<br>Class name: StartOptions<br>Method or attribute name: displayId?: number;|NA|@ohos.application.StartOptions.d.ts|
|Deleted|Module name: ohos.application.Want<br>Class name: Want<br>Method or attribute name: moduleName?: string;|NA|@ohos.application.Want.d.ts|
|Deleted|Module name: ohos.wantAgent<br>Class name: wantAgent<br>Method or attribute name: function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void;|NA|@ohos.wantAgent.d.ts|
|Deleted|Module name: ohos.wantAgent<br>Class name: wantAgent<br>Method or attribute name: function getOperationType(agent: WantAgent, callback: AsyncCallback<number>): void;|NA|@ohos.wantAgent.d.ts|
|Deleted|Module name: ohos.wantAgent<br>Class name: wantAgent<br>Method or attribute name: function getOperationType(agent: WantAgent): Promise<number>;|NA|@ohos.wantAgent.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: abilityInfo: AbilityInfo;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: currentHapModuleInfo: HapModuleInfo;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: config: Configuration;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbility(want: Want, options?: StartOptions): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityByCall(want: Want): Promise<Caller>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResult(want: Want, options?: StartOptions): Promise<AbilityResult>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startServiceExtensionAbility(want: Want): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: stopServiceExtensionAbility(want: Want): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: terminateSelf(callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: terminateSelf(): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: terminateSelfWithResult(parameter: AbilityResult): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: connectAbility(want: Want, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: disconnectAbility(connection: number, callback:AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: disconnectAbility(connection: number): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: disconnectServiceExtensionAbility(connection: number): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: setMissionLabel(label: string, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: setMissionLabel(label: string): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: setMissionIcon(icon: image.PixelMap, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: setMissionIcon(icon: image.PixelMap): Promise<void>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: restoreWindowStage(localStorage: LocalStorage): void;|NA|AbilityContext.d.ts|
|Deleted|Module name: AbilityContext<br>Class name: AbilityContext<br>Method or attribute name: isTerminating(): boolean;|NA|AbilityContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): number;|NA|ApplicationContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: unregisterAbilityLifecycleCallback(callbackId: number,  callback: AsyncCallback<void>): void;|NA|ApplicationContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: unregisterAbilityLifecycleCallback(callbackId: number): Promise<void>;|NA|ApplicationContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: registerEnvironmentCallback(callback: EnvironmentCallback): number;|NA|ApplicationContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: unregisterEnvironmentCallback(callbackId: number,  callback: AsyncCallback<void>): void;|NA|ApplicationContext.d.ts|
|Deleted|Module name: ApplicationContext<br>Class name: ApplicationContext<br>Method or attribute name: unregisterEnvironmentCallback(callbackId: number): Promise<void>;|NA|ApplicationContext.d.ts|
|Deleted|Module name: PermissionRequestResult<br>Class name: PermissionRequestResult|NA|PermissionRequestResult.d.ts|
|Deleted|Module name: PermissionRequestResult<br>Class name: PermissionRequestResult<br>Method or attribute name: permissions: Array<string>;|NA|PermissionRequestResult.d.ts|
|Deleted|Module name: PermissionRequestResult<br>Class name: PermissionRequestResult<br>Method or attribute name: authResults: Array<number>;|NA|PermissionRequestResult.d.ts|
|Deleted|Module name: ServiceExtensionContext<br>Class name: ServiceExtensionContext<br>Method or attribute name: connectAbility(want: Want, options: ConnectOptions): number;|NA|ServiceExtensionContext.d.ts|
|Deleted|Module name: ServiceExtensionContext<br>Class name: ServiceExtensionContext<br>Method or attribute name: connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|ServiceExtensionContext.d.ts|
|Deleted|Module name: ServiceExtensionContext<br>Class name: ServiceExtensionContext<br>Method or attribute name: disconnectAbility(connection: number, callback:AsyncCallback<void>): void;|NA|ServiceExtensionContext.d.ts|
|Deleted|Module name: ServiceExtensionContext<br>Class name: ServiceExtensionContext<br>Method or attribute name: disconnectAbility(connection: number): Promise<void>;|NA|ServiceExtensionContext.d.ts|
|Deleted|Module name: UIAbilityContext<br>Class name: UIAbilityContext<br>Method or attribute name: requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void;|NA|UIAbilityContext.d.ts|
|Deleted|Module name: UIAbilityContext<br>Class name: UIAbilityContext<br>Method or attribute name: requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>;|NA|UIAbilityContext.d.ts|
|Access level changed|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Access level: public API|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Access level: system API|@ohos.application.formInfo.d.ts|
|Deprecated version changed|Class name: dataUriUtils<br>Deprecated version: N/A|Class name: dataUriUtils<br>Deprecated version: 9<br>Substitute API: @ohos.app.ability.dataUriUtils.d.ts |@ohos.ability.dataUriUtils.d.ts|
|Deprecated version changed|Class name: Context<br>Method or attribute name: setShowOnLockScreen(show: boolean, callback: AsyncCallback<void>): void<br>Deprecated version: N/A|Class name: Context<br>Method or attribute name: setShowOnLockScreen(show: boolean, callback: AsyncCallback<void>): void<br>Deprecated version: 9<br>Substitute API: ohos.window|context.d.ts|
|Deprecated version changed|Class name: Context<br>Method or attribute name: setShowOnLockScreen(show: boolean): Promise<void>;<br>Deprecated version: N/A|Class name: Context<br>Method or attribute name: setShowOnLockScreen(show: boolean): Promise<void>;<br>Deprecated version: 9|context.d.ts|
|Initial version changed|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Initial version: 9|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Initial version: 8|@ohos.application.formInfo.d.ts|
|Permission added|Class name: ServiceExtensionContext<br>Method or attribute name: startAbilityByCall(want: Want): Promise<Caller>;<br>Permission: N/A|Class name: ServiceExtensionContext<br>Method or attribute name: startAbilityByCall(want: Want): Promise<Caller>;<br>Permission: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|ServiceExtensionContext.d.ts|
|Permission added|Class name: UIAbilityContext<br>Method or attribute name: startAbilityByCall(want: Want): Promise<Caller>;<br>Permission: N/A|Class name: UIAbilityContext<br>Method or attribute name: startAbilityByCall(want: Want): Promise<Caller>;<br>Permission: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|UIAbilityContext.d.ts|
|Access level changed|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Access level: public API|Class name: FormParam<br>Method or attribute name: IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>Access level: system API|@ohos.application.formInfo.d.ts|
|Function changed|Class name: ServiceExtensionAbility<br>Method or attribute name: onConnect(want: Want): rpc.RemoteObject;<br>|Class name: ServiceExtensionAbility<br>Method or attribute name: onConnect(want: Want): rpc.RemoteObject \| Promise<rpc.RemoteObject>;<br>|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|Function changed|Class name: ServiceExtensionAbility<br>Method or attribute name: onDisconnect(want: Want): void;<br>|Class name: ServiceExtensionAbility<br>Method or attribute name: onDisconnect(want: Want): void \| Promise<void>;<br>|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|Function changed|Class name: UIAbility<br>Method or attribute name: onDestroy(): void;<br>|Class name: UIAbility<br>Method or attribute name: onDestroy(): void \| Promise<void>;<br>|@ohos.app.ability.UIAbility.d.ts|
