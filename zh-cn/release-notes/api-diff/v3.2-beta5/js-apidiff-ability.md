| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.app.ability.dataUriUtils<br>类名: dataUriUtils|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|模块名: ohos.app.ability.dataUriUtils<br>类名: dataUriUtils<br>方法 or 属性: function getId(uri: string): number|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|模块名: ohos.app.ability.dataUriUtils<br>类名: dataUriUtils<br>方法 or 属性: function attachId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|模块名: ohos.app.ability.dataUriUtils<br>类名: dataUriUtils<br>方法 or 属性: function deleteId(uri: string): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|模块名: ohos.app.ability.dataUriUtils<br>类名: dataUriUtils<br>方法 or 属性: function updateId(uri: string, id: number): string|@ohos.app.ability.dataUriUtils.d.ts|
|新增|NA|模块名: ohos.app.ability.EnvironmentCallback<br>类名: EnvironmentCallback<br>方法 or 属性: onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|@ohos.app.ability.EnvironmentCallback.d.ts|
|删除|模块名: ohos.app.ability.wantAgent<br>类名: wantAgent<br>方法 or 属性：function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>): void;|NA|@ohos.app.ability.wantAgent.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: OnReleaseCallBack|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: OnReleaseCallBack<br>方法 or 属性：(msg: string): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: CalleeCallBack|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: CalleeCallBack<br>方法 or 属性：(indata: rpc.MessageParcel): rpc.Sequenceable;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Caller|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Caller<br>方法 or 属性：call(method: string, data: rpc.Sequenceable): Promise<void>;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Caller<br>方法 or 属性：callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Caller<br>方法 or 属性：release(): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Caller<br>方法 or 属性：onRelease(callback: OnReleaseCallBack): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Callee|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Callee<br>方法 or 属性：on(method: string, callback: CalleeCallBack): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Callee<br>方法 or 属性：off(method: string): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：context: AbilityContext;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：launchWant: Want;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：lastRequestWant: Want;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：callee: Callee;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onWindowStageCreate(windowStage: window.WindowStage): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onWindowStageDestroy(): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onWindowStageRestore(windowStage: window.WindowStage): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onDestroy(): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onForeground(): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onBackground(): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：dump(params: Array<string>): Array<string>;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.Ability<br>类名: Ability<br>方法 or 属性：onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: any}): AbilityConstant.OnSaveResult;|NA|@ohos.application.Ability.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: AbilityConstant|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchParam|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchParam<br>方法 or 属性：launchReason: LaunchReason;|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchParam<br>方法 or 属性：lastExitReason: LastExitReason;|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason<br>方法 or 属性：UNKNOWN = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason<br>方法 or 属性：START_ABILITY = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason<br>方法 or 属性：CALL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason<br>方法 or 属性：CONTINUATION = 3|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LaunchReason<br>方法 or 属性：APP_RECOVERY = 4|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LastExitReason|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LastExitReason<br>方法 or 属性：UNKNOWN = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LastExitReason<br>方法 or 属性：ABILITY_NOT_RESPONDING = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: LastExitReason<br>方法 or 属性：NORMAL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnContinueResult|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnContinueResult<br>方法 or 属性：AGREE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnContinueResult<br>方法 or 属性：REJECT = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnContinueResult<br>方法 or 属性：MISMATCH = 2|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: MemoryLevel|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: MemoryLevel<br>方法 or 属性：MEMORY_LEVEL_MODERATE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: MemoryLevel<br>方法 or 属性：MEMORY_LEVEL_LOW = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: MemoryLevel<br>方法 or 属性：MEMORY_LEVEL_CRITICAL = 2|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode<br>方法 or 属性：WINDOW_MODE_UNDEFINED = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode<br>方法 or 属性：WINDOW_MODE_FULLSCREEN = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode<br>方法 or 属性：WINDOW_MODE_SPLIT_PRIMARY = 100|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode<br>方法 or 属性：WINDOW_MODE_SPLIT_SECONDARY = 101|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: WindowMode<br>方法 or 属性：WINDOW_MODE_FLOATING = 102|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：ALL_AGREE = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：CONTINUATION_REJECT = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：CONTINUATION_MISMATCH = 2|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：RECOVERY_AGREE = 3|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：RECOVERY_REJECT = 4|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: OnSaveResult<br>方法 or 属性：ALL_REJECT|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: StateType|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: StateType<br>方法 or 属性：CONTINUATION = 0|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityConstant<br>类名: StateType<br>方法 or 属性：APP_RECOVERY = 1|NA|@ohos.application.AbilityConstant.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onAbilityCreate(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onWindowStageCreate(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onWindowStageActive(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onWindowStageInactive(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onWindowStageDestroy(ability: Ability, windowStage: window.WindowStage): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onAbilityDestroy(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onAbilityForeground(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onAbilityBackground(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.AbilityLifecycleCallback<br>类名: AbilityLifecycleCallback<br>方法 or 属性：onAbilityContinue(ability: Ability): void;|NA|@ohos.application.AbilityLifecycleCallback.d.ts|
|删除|模块名: ohos.application.abilityManager<br>类名: abilityManager<br>方法 or 属性：function getExtensionRunningInfos(upperLimit: number): Promise<Array<ExtensionRunningInfo>>;|NA|@ohos.application.abilityManager.d.ts|
|删除|模块名: ohos.application.abilityManager<br>类名: abilityManager<br>方法 or 属性：function getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback<Array<ExtensionRunningInfo>>): void;|NA|@ohos.application.abilityManager.d.ts|
|删除|模块名: ohos.application.abilityManager<br>类名: abilityManager<br>方法 or 属性：function getTopAbility(): Promise<ElementName>;|NA|@ohos.application.abilityManager.d.ts|
|删除|模块名: ohos.application.abilityManager<br>类名: abilityManager<br>方法 or 属性：function getTopAbility(callback: AsyncCallback<ElementName>): void;|NA|@ohos.application.abilityManager.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage<br>方法 or 属性：context: AbilityStageContext;|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage<br>方法 or 属性：onCreate(): void;|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage<br>方法 or 属性：onAcceptWant(want: Want): string;|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage<br>方法 or 属性：onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.AbilityStage<br>类名: AbilityStage<br>方法 or 属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.AbilityStage.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState<br>方法 or 属性：STATE_CREATE|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState<br>方法 or 属性：STATE_FOREGROUND|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState<br>方法 or 属性：STATE_ACTIVE|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState<br>方法 or 属性：STATE_BACKGROUND|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ApplicationState<br>方法 or 属性：STATE_DESTROY|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState<br>方法 or 属性：STATE_CREATE|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState<br>方法 or 属性：STATE_FOREGROUND|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState<br>方法 or 属性：STATE_ACTIVE|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState<br>方法 or 属性：STATE_BACKGROUND|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: ProcessState<br>方法 or 属性：STATE_DESTROY|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: appManager<br>方法 or 属性：function registerApplicationStateObserver(observer: ApplicationStateObserver, bundleNameList: Array<string>): number;|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: appManager<br>方法 or 属性：function getProcessRunningInformation(): Promise<Array<ProcessRunningInformation>>;|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.appManager<br>类名: appManager<br>方法 or 属性：function getProcessRunningInformation(callback: AsyncCallback<Array<ProcessRunningInformation>>): void;|NA|@ohos.application.appManager.d.ts|
|删除|模块名: ohos.application.Configuration<br>类名: Configuration<br>方法 or 属性：direction?: ConfigurationConstant.Direction;|NA|@ohos.application.Configuration.d.ts|
|删除|模块名: ohos.application.Configuration<br>类名: Configuration<br>方法 or 属性：screenDensity?: ConfigurationConstant.ScreenDensity;|NA|@ohos.application.Configuration.d.ts|
|删除|模块名: ohos.application.Configuration<br>类名: Configuration<br>方法 or 属性：displayId?: number;|NA|@ohos.application.Configuration.d.ts|
|删除|模块名: ohos.application.Configuration<br>类名: Configuration<br>方法 or 属性：hasPointerDevice?: boolean;|NA|@ohos.application.Configuration.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: Direction|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: Direction<br>方法 or 属性：DIRECTION_NOT_SET = -1|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: Direction<br>方法 or 属性：DIRECTION_VERTICAL = 0|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: Direction<br>方法 or 属性：DIRECTION_HORIZONTAL = 1|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_NOT_SET = 0|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_SDPI = 120|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_MDPI = 160|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_LDPI = 240|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_XLDPI = 320|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_XXLDPI = 480|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.ConfigurationConstant<br>类名: ScreenDensity<br>方法 or 属性：SCREEN_DENSITY_XXXLDPI = 640|NA|@ohos.application.ConfigurationConstant.d.ts|
|删除|模块名: ohos.application.context<br>类名: context|NA|@ohos.application.context.d.ts|
|删除|模块名: ohos.application.EnvironmentCallback<br>类名: EnvironmentCallback|NA|@ohos.application.EnvironmentCallback.d.ts|
|删除|模块名: ohos.application.EnvironmentCallback<br>类名: EnvironmentCallback<br>方法 or 属性：onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.EnvironmentCallback.d.ts|
|删除|模块名: ohos.application.errorManager<br>类名: errorManager|NA|@ohos.application.errorManager.d.ts|
|删除|模块名: ohos.application.errorManager<br>类名: errorManager<br>方法 or 属性：function registerErrorObserver(observer: ErrorObserver): number;|NA|@ohos.application.errorManager.d.ts|
|删除|模块名: ohos.application.errorManager<br>类名: errorManager<br>方法 or 属性：function unregisterErrorObserver(observerId: number,  callback: AsyncCallback<void>): void;|NA|@ohos.application.errorManager.d.ts|
|删除|模块名: ohos.application.errorManager<br>类名: errorManager<br>方法 or 属性：function unregisterErrorObserver(observerId: number): Promise<void>;|NA|@ohos.application.errorManager.d.ts|
|删除|模块名: ohos.application.ExtensionAbility<br>类名: ExtensionAbility|NA|@ohos.application.ExtensionAbility.d.ts|
|删除|模块名: ohos.application.ExtensionAbility<br>类名: ExtensionAbility<br>方法 or 属性：onConfigurationUpdated(newConfig: Configuration): void;|NA|@ohos.application.ExtensionAbility.d.ts|
|删除|模块名: ohos.application.ExtensionAbility<br>类名: ExtensionAbility<br>方法 or 属性：onMemoryLevel(level: AbilityConstant.MemoryLevel): void;|NA|@ohos.application.ExtensionAbility.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：context: FormExtensionContext;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onCreate(want: Want): formBindingData.FormBindingData;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onCastToNormal(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onUpdate(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onVisibilityChange(newStatus: { [key: string]: number }): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onEvent(formId: string, message: string): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onDestroy(formId: string): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onAcquireFormState?(want: Want): formInfo.FormState;|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.FormExtension<br>类名: FormExtension<br>方法 or 属性：onShare?(formId: string): {[key: string]: any};|NA|@ohos.application.FormExtension.d.ts|
|删除|模块名: ohos.application.formHost<br>类名: formHost<br>方法 or 属性：function shareForm(formId: string, deviceId: string, callback: AsyncCallback<void>): void;|NA|@ohos.application.formHost.d.ts|
|删除|模块名: ohos.application.formHost<br>类名: formHost<br>方法 or 属性：function shareForm(formId: string, deviceId: string): Promise<void>;|NA|@ohos.application.formHost.d.ts|
|删除|模块名: ohos.application.formHost<br>类名: formHost<br>方法 or 属性：function notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean, callback: AsyncCallback<void>): void;|NA|@ohos.application.formHost.d.ts|
|删除|模块名: ohos.application.formHost<br>类名: formHost<br>方法 or 属性：function notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean): Promise<void>;|NA|@ohos.application.formHost.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormType<br>方法 or 属性：eTS = 2|NA|@ohos.application.formInfo.d.ts|
|删除|模块名：ohos.application.formInfo<br>类名:FormParam<br>方法 or 属性:BUNDLE_NAME_KEY = "ohos.extra.param.key.bundle_name"|NA|@ohos.application.formInfo.d.ts|
|删除|模块名：ohos.application.formInfo<br>类名:FormParam<br>方法 or 属性:ABILITY_NAME_KEY = "ohos.extra.param.key.ability_name"|NA|@ohos.application.formInfo.d.ts|
|删除|模块名：ohos.application.formInfo<br>类名:FormParam<br>方法 or 属性:DEVICE_ID_KEY = "ohos.extra.param.key.device_id"|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormInfoFilter|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormInfoFilter<br>方法 or 属性：moduleName?: string;|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension<br>方法 or 属性：Dimension_1_2 = 1|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension<br>方法 or 属性：Dimension_2_2|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension<br>方法 or 属性：Dimension_2_4|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension<br>方法 or 属性：Dimension_4_4|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: FormDimension<br>方法 or 属性：Dimension_2_1|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: VisibilityType|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: VisibilityType<br>方法 or 属性：FORM_VISIBLE = 1|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formInfo<br>类名: VisibilityType<br>方法 or 属性：FORM_INVISIBLE|NA|@ohos.application.formInfo.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback<Array<formInfo.FormInfo>>): void;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function getFormsInfo(callback: AsyncCallback<Array<formInfo.FormInfo>>): void;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function getFormsInfo(filter?: formInfo.FormInfoFilter): Promise<Array<formInfo.FormInfo>>;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData,<br><br>        callback: AsyncCallback<string>): void;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function requestPublishForm(want: Want, callback: AsyncCallback<string>): void;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise<string>;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function isRequestPublishFormSupported(callback: AsyncCallback<boolean>): void;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.formProvider<br>类名: formProvider<br>方法 or 属性：function isRequestPublishFormSupported(): Promise<boolean>;|NA|@ohos.application.formProvider.d.ts|
|删除|模块名: ohos.application.missionManager<br>类名: missionManager<br>方法 or 属性：function getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void;|NA|@ohos.application.missionManager.d.ts|
|删除|模块名: ohos.application.missionManager<br>类名: missionManager<br>方法 or 属性：function getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>;|NA|@ohos.application.missionManager.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：context: ServiceExtensionContext;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onCreate(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onDestroy(): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onRequest(want: Want, startId: number): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onConnect(want: Want): rpc.RemoteObject;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onDisconnect(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onReconnect(want: Want): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：onConfigurationUpdated(config: Configuration): void;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.ServiceExtensionAbility<br>类名: ServiceExtensionAbility<br>方法 or 属性：dump(params: Array<string>): Array<string>;|NA|@ohos.application.ServiceExtensionAbility.d.ts|
|删除|模块名: ohos.application.StartOptions<br>类名: StartOptions|NA|@ohos.application.StartOptions.d.ts|
|删除|模块名: ohos.application.StartOptions<br>类名: StartOptions<br>方法 or 属性：windowMode?: number;|NA|@ohos.application.StartOptions.d.ts|
|删除|模块名: ohos.application.StartOptions<br>类名: StartOptions<br>方法 or 属性：displayId?: number;|NA|@ohos.application.StartOptions.d.ts|
|删除|模块名: ohos.application.Want<br>类名: Want<br>方法 or 属性：moduleName?: string;|NA|@ohos.application.Want.d.ts|
|删除|模块名: ohos.wantAgent<br>类名: wantAgent<br>方法 or 属性：function trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: AsyncCallback<CompleteData>): void;|NA|@ohos.wantAgent.d.ts|
|删除|模块名: ohos.wantAgent<br>类名: wantAgent<br>方法 or 属性：function getOperationType(agent: WantAgent, callback: AsyncCallback<number>): void;|NA|@ohos.wantAgent.d.ts|
|删除|模块名: ohos.wantAgent<br>类名: wantAgent<br>方法 or 属性：function getOperationType(agent: WantAgent): Promise<number>;|NA|@ohos.wantAgent.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：abilityInfo: AbilityInfo;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：currentHapModuleInfo: HapModuleInfo;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：config: Configuration;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbility(want: Want, options?: StartOptions): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise<Caller>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResult(want: Want, options?: StartOptions): Promise<AbilityResult>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startServiceExtensionAbility(want: Want): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：stopServiceExtensionAbility(want: Want): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：terminateSelf(callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：terminateSelf(): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：terminateSelfWithResult(parameter: AbilityResult): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：connectAbility(want: Want, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：disconnectAbility(connection: number, callback:AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：disconnectAbility(connection: number): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：disconnectServiceExtensionAbility(connection: number): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：setMissionLabel(label: string, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：setMissionLabel(label: string): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：setMissionIcon(icon: image.PixelMap, callback: AsyncCallback<void>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：setMissionIcon(icon: image.PixelMap): Promise<void>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：restoreWindowStage(localStorage: LocalStorage): void;|NA|AbilityContext.d.ts|
|删除|模块名: AbilityContext<br>类名: AbilityContext<br>方法 or 属性：isTerminating(): boolean;|NA|AbilityContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): number;|NA|ApplicationContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：unregisterAbilityLifecycleCallback(callbackId: number,  callback: AsyncCallback<void>): void;|NA|ApplicationContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：unregisterAbilityLifecycleCallback(callbackId: number): Promise<void>;|NA|ApplicationContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：registerEnvironmentCallback(callback: EnvironmentCallback): number;|NA|ApplicationContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：unregisterEnvironmentCallback(callbackId: number,  callback: AsyncCallback<void>): void;|NA|ApplicationContext.d.ts|
|删除|模块名: ApplicationContext<br>类名: ApplicationContext<br>方法 or 属性：unregisterEnvironmentCallback(callbackId: number): Promise<void>;|NA|ApplicationContext.d.ts|
|删除|模块名: PermissionRequestResult<br>类名: PermissionRequestResult|NA|PermissionRequestResult.d.ts|
|删除|模块名: PermissionRequestResult<br>类名: PermissionRequestResult<br>方法 or 属性：permissions: Array<string>;|NA|PermissionRequestResult.d.ts|
|删除|模块名: PermissionRequestResult<br>类名: PermissionRequestResult<br>方法 or 属性：authResults: Array<number>;|NA|PermissionRequestResult.d.ts|
|删除|模块名：ServiceExtensionContext<br>类名:ServiceExtensionContext<br>方法 or 属性:connectAbility(want: Want, options: ConnectOptions): number;|NA|ServiceExtensionContext.d.ts|
|删除|模块名：ServiceExtensionContext<br>类名:ServiceExtensionContext<br>方法 or 属性:connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;|NA|ServiceExtensionContext.d.ts|
|删除|模块名：ServiceExtensionContext<br>类名:ServiceExtensionContext<br>方法 or 属性:disconnectAbility(connection: number, callback:AsyncCallback<void>): void;|NA|ServiceExtensionContext.d.ts|
|删除|模块名：ServiceExtensionContext<br>类名:ServiceExtensionContext<br>方法 or 属性:disconnectAbility(connection: number): Promise<void>;|NA|ServiceExtensionContext.d.ts|
|删除|模块名：UIAbilityContext<br>类名:UIAbilityContext<br>方法 or 属性:requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void;|NA|UIAbilityContext.d.ts|
|删除|模块名：UIAbilityContext<br>类名:UIAbilityContext<br>方法 or 属性:requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>;|NA|UIAbilityContext.d.ts|
|访问级别有变化|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>访问级别：公开API|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>访问级别：系统API|@ohos.application.formInfo.d.ts|
|废弃版本有变化|类名：dataUriUtils<br>废弃版本：N/A|类名：dataUriUtils<br>废弃版本：9<br>代替接口：@ohos.app.ability.dataUriUtils.d.ts |@ohos.ability.dataUriUtils.d.ts|
|废弃版本有变化|类名：Context<br>方法 or 属性：setShowOnLockScreen(show: boolean, callback: AsyncCallback<void>): void<br>废弃版本：N/A|类名：Context<br>方法 or 属性：setShowOnLockScreen(show: boolean, callback: AsyncCallback<void>): void<br>废弃版本：9<br>代替接口：ohos.window|context.d.ts|
|废弃版本有变化|类名：Context<br>方法 or 属性：setShowOnLockScreen(show: boolean): Promise<void>;<br>废弃版本：N/A|类名：Context<br>方法 or 属性：setShowOnLockScreen(show: boolean): Promise<void>;<br>废弃版本：9|context.d.ts|
|起始版本有变化|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>起始版本：9|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>起始版本：8|@ohos.application.formInfo.d.ts|
|新增(权限)|类名：ServiceExtensionContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise<Caller>;<br>权限:N/A|类名：ServiceExtensionContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise<Caller>;<br>权限:ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|ServiceExtensionContext.d.ts|
|新增(权限)|类名：UIAbilityContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise<Caller>;<br>权限:N/A|类名：UIAbilityContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise<Caller>;<br>权限:ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|UIAbilityContext.d.ts|
|访问级别有变化|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>访问级别：公开API|类名：FormParam<br>方法 or 属性：IDENTITY_KEY = "ohos.extra.param.key.form_identity"<br>访问级别：系统API|@ohos.application.formInfo.d.ts|
|函数有变化|类名：ServiceExtensionAbility<br>方法 or 属性：onConnect(want: Want): rpc.RemoteObject;<br>|类名：ServiceExtensionAbility<br>方法 or 属性：onConnect(want: Want): rpc.RemoteObject \| Promise<rpc.RemoteObject>;<br>|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|函数有变化|类名：ServiceExtensionAbility<br>方法 or 属性：onDisconnect(want: Want): void;<br>|类名：ServiceExtensionAbility<br>方法 or 属性：onDisconnect(want: Want): void \| Promise<void>;<br>|@ohos.app.ability.ServiceExtensionAbility.d.ts|
|函数有变化|类名：UIAbility<br>方法 or 属性：onDestroy(): void;<br>|类名：UIAbility<br>方法 or 属性：onDestroy(): void \| Promise<void>;<br>|@ohos.app.ability.UIAbility.d.ts|
