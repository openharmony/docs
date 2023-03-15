# 元能力子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，元能力子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| featureability | FeatureAbility | static getDeviceList(flag: number): Promise\<Result>; | 新增 |
| customizeData | CustomizeData | extra: string; | 新增 |
| applicationInfo | ApplicationInfo | readonly entityType: string; | 新增 |
| applicationInfo | ApplicationInfo | readonly uid: number; | 新增 |
| applicationInfo | ApplicationInfo | readonly accessTokenId: number; | 新增 |
| applicationInfo | ApplicationInfo | readonly removable: boolean; | 新增 |
| applicationInfo | ApplicationInfo | readonly metaData: Map\<string, Array\<CustomizeData>>; | 新增 |
| applicationInfo | ApplicationInfo | readonly codePath: string; | 新增 |
| applicationInfo | ApplicationInfo | readonly moduleInfos: Array\<ModuleInfo>; | 新增 |
| shellCmdResult | ShellCmdResult | exitCode: number; | 新增 |
| shellCmdResult | ShellCmdResult | stdResult: String; | 新增 |
| ProcessRunningInfo | ProcessRunningInfo | bundleNames: Array\<string>; | 新增 |
| ProcessRunningInfo | ProcessRunningInfo | processName: string; | 新增 |
| ProcessRunningInfo | ProcessRunningInfo | uid: number; | 新增 |
| ProcessRunningInfo | ProcessRunningInfo | pid: number; | 新增 |
| BaseContext | BaseContext | stageMode: boolean; | 新增 |
| abilityDelegatorArgs | AbilityDelegatorArgs | testRunnerClassName: string; | 新增 |
| abilityDelegatorArgs | AbilityDelegatorArgs | testCaseNames: string; | 新增 |
| abilityDelegatorArgs | AbilityDelegatorArgs | parameters: {[key: string]: string}; | 新增 |
| abilityDelegatorArgs | AbilityDelegatorArgs | bundleName: string; | 新增 |
| abilityDelegator | AbilityDelegator | executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;<br>executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;<br>executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>; | 新增 |
| abilityDelegator | AbilityDelegator | print(msg: string, callback: AsyncCallback\<void>): void;<br>print(msg: string): Promise\<void>; | 新增 |
| context | Context | printDrawnCompleted(callback: AsyncCallback\<void>): void;<br>printDrawnCompleted(): Promise\<void>; | 新增 |
| context | Context | isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void;<br>isUpdatingConfigurations(): Promise\<boolean>; | 新增 |
| context | Context | getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void<br>getAbilityInfo(): Promise\<AbilityInfo>; | 新增 |
| context | Context | getApplicationContext(): Context; | 新增 |
| context | Context | getAppVersionInfo(callback: AsyncCallback\<AppVersionInfo>): void<br>getAppVersionInfo(): Promise\<AppVersionInfo>; | 新增 |
| context | Context | getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void<br>getHapModuleInfo(): Promise\<HapModuleInfo>; | 新增 |
| context | Context | getAppType(callback: AsyncCallback\<string>): void<br>getAppType(): Promise\<string>; | 新增 |
| context | Context | getOrCreateDistributedDir(): Promise\<string>;<br>getOrCreateDistributedDir(callback: AsyncCallback\<string>): void; | 新增 |
| context | Context | getCacheDir(callback: AsyncCallback\<string>): void;<br>getCacheDir(): Promise\<string>; | 新增 |
| context | Context | getFilesDir(callback: AsyncCallback\<string>): void;<br>getFilesDir(): Promise\<string>; | 新增 |
| context | Context | setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback\<void>): void<br>setWakeUpScreen(wakeUp: boolean): Promise\<void>; | 新增 |
| context | Context | setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void<br>setShowOnLockScreen(show: boolean): Promise\<void>; | 新增 |
| context | Context | setDisplayOrientation(orientation: DisplayOrientation, callback: AsyncCallback\<void>): void<br>setDisplayOrientation(orientation: DisplayOrientation): Promise\<void>; | 新增 |
| context | Context | getDisplayOrientation(callback: AsyncCallback\<DisplayOrientation>): void<br>getDisplayOrientation(): Promise\<DisplayOrientation>; | 新增 |
| appVersionInfo | AppVersionInfo | readonly versionName: string; | 新增 |
| appVersionInfo | AppVersionInfo | readonly versionCode: number; | 新增 |
| appVersionInfo | AppVersionInfo | readonly appName: string; | 新增 |
| dataAbilityHelper | PacMap | [key: string]: number \| string \| boolean \| Array\<string \| number \| boolean> \| null; | 新增 |
| dataAbilityHelper | DataAbilityHelper | executeBatch(uri: string, operations: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void;<br>executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>; | 新增 |
| dataAbilityHelper | DataAbilityHelper | call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void;<br>call(uri: string, method: string, arg: string, extras: PacMap): Promise\<PacMap>; | 新增 |
| ohos.application.Want | Want | entities?: Array\<string>; | 新增 |
| ohos.application.Want | Want | parameters?: {[key: string]: any}; | 新增 |
| ohos.application.Want | Want | action?: string; | 新增 |
| ohos.application.Want | Want | flags?: number; | 新增 |
| ohos.application.Want | Want | type?: string; | 新增 |
| ohos.application.Want | Want | uri?: string; | 新增 |
| ohos.application.Want | Want | abilityName?: string; | 新增 |
| ohos.application.Want | Want | bundleName?: string; | 新增 |
| ohos.application.Want | Want | deviceId?: string; | 新增 |
| ohos.application.testRunner | TestRunner | onRun(): void; | 新增 |
| ohos.application.testRunner | TestRunner | onPrepare(): void; | 新增 |
| ohos.application.formProvider | formProvider | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | 新增 |
| ohos.application.formProvider | formProvider | setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void;<br>setFormNextRefreshTime(formId: string, minute: number): Promise\<void>; | 新增 |
| ohos.application.formInfo | FormParam | TEMPORARY_KEY = "ohos.extra.param.key.form_temporary" | 新增 |
| ohos.application.formInfo | FormParam | HEIGHT_KEY = "ohos.extra.param.key.form_height" | 新增 |
| ohos.application.formInfo | FormParam | WIDTH_KEY = "ohos.extra.param.key.form_width" | 新增 |
| ohos.application.formInfo | FormParam | MODULE_NAME_KEY = "ohos.extra.param.key.module_name" | 新增 |
| ohos.application.formInfo | FormParam | NAME_KEY = "ohos.extra.param.key.form_name" | 新增 |
| ohos.application.formInfo | FormParam | DIMENSION_KEY = "ohos.extra.param.key.form_dimension" | 新增 |
| ohos.application.formInfo | FormState | READY = 1 | 新增 |
| ohos.application.formInfo | FormState | DEFAULT = 0 | 新增 |
| ohos.application.formInfo | FormState | UNKNOWN = -1 | 新增 |
| ohos.application.formInfo | FormStateInfo | want: Want; | 新增 |
| ohos.application.formInfo | FormStateInfo | formState: FormState; | 新增 |
| ohos.application.formInfo | ColorMode | MODE_LIGHT = 1 | 新增 |
| ohos.application.formInfo | ColorMode | MODE_DARK = 0 | 新增 |
| ohos.application.formInfo | ColorMode | MODE_AUTO = -1 | 新增 |
| ohos.application.formInfo | FormType | JS = 1 | 新增 |
| ohos.application.formInfo | FormInfo | customizeData: {[key: string]: [value: string]}; | 新增 |
| ohos.application.formInfo | FormInfo | supportDimensions: Array\<number>; | 新增 |
| ohos.application.formInfo | FormInfo | defaultDimension: number; | 新增 |
| ohos.application.formInfo | FormInfo | updateDuration: number; | 新增 |
| ohos.application.formInfo | FormInfo | formConfigAbility: string; | 新增 |
| ohos.application.formInfo | FormInfo | scheduledUpdateTime: string; | 新增 |
| ohos.application.formInfo | FormInfo | relatedBundleName: string; | 新增 |
| ohos.application.formInfo | FormInfo | formVisibleNotify: boolean; | 新增 |
| ohos.application.formInfo | FormInfo | updateEnabled: boolean; | 新增 |
| ohos.application.formInfo | FormInfo | isDefault: boolean; | 新增 |
| ohos.application.formInfo | FormInfo | colorMode: ColorMode; | 新增 |
| ohos.application.formInfo | FormInfo | jsComponentName: string; | 新增 |
| ohos.application.formInfo | FormInfo | type: FormType; | 新增 |
| ohos.application.formInfo | FormInfo | description: string; | 新增 |
| ohos.application.formInfo | FormInfo | name: string; | 新增 |
| ohos.application.formInfo | FormInfo | abilityName: string; | 新增 |
| ohos.application.formInfo | FormInfo | moduleName: string; | 新增 |
| ohos.application.formInfo | FormInfo | bundleName: string; | 新增 |
| ohos.application.formError | FormError | ERR_IN_RECOVERY = 36 | 新增 |
| ohos.application.formError | FormError | ERR_FORM_DUPLICATE_ADDED = 31 | 新增 |
| ohos.application.formError | FormError | ERR_SYSTEM_RESPONSES_FAILED = 30 | 新增 |
| ohos.application.formError | FormError | ERR_FORM_FA_NOT_INSTALLED = 20 | 新增 |
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_DIMENSION = 19 | 新增 |
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_ABILITY = 18 | 新增 |
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_MODULE = 17 | 新增 |
| ohos.application.formError | FormError | ERR_MAX_SYSTEM_TEMP_FORMS = 16 | 新增 |
| ohos.application.formError | FormError | ERR_MAX_FORMS_PER_CLIENT = 15 | 新增 |
| ohos.application.formError | FormError | ERR_PROVIDER_DEL_FAIL = 14 | 新增 |
| ohos.application.formError | FormError | ERR_OPERATION_FORM_NOT_SELF = 13 | 新增 |
| ohos.application.formError | FormError | ERR_MAX_INSTANCES_PER_FORM = 12 | 新增 |
| ohos.application.formError | FormError | ERR_MAX_SYSTEM_FORMS = 11 | 新增 |
| ohos.application.formError | FormError | ERR_BIND_PROVIDER_FAILED = 10 | 新增 |
| ohos.application.formError | FormError | ERR_NOT_EXIST_ID = 9 | 新增 |
| ohos.application.formError | FormError | ERR_CFG_NOT_MATCH_ID = 8 | 新增 |
| ohos.application.formError | FormError | ERR_ADD_INVALID_PARAM = 7 | 新增 |
| ohos.application.formError | FormError | ERR_GET_LAYOUT_FAILED = 6 | 新增 |
| ohos.application.formError | FormError | ERR_GET_BUNDLE_FAILED = 5 | 新增 |
| ohos.application.formError | FormError | ERR_GET_INFO_FAILED = 4 | 新增 |
| ohos.application.formError | FormError | ERR_PERMISSION_DENY = 2 | 新增 |
| ohos.application.formError | FormError | ERR_COMMON = 1 | 新增 |
| ohos.application.formBindingData | FormBindingData | data: Object | 新增 |
| ohos.application.formBindingData | formBindingData | createFormBindingData(obj?: Object \| string): FormBindingData; | 新增 |
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_LIGHT = 1 | 新增 |
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_DARK = 0 | 新增 |
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_NOT_SET = -1 | 新增 |
| ohos.application.Configuration | Configuration | colorMode: ConfigurationConstant.ColorMode; | 新增 |
| ohos.application.Configuration | Configuration | language: string; | 新增 |
| ohos.application.appManager | appManager | getAppMemorySize(): Promise\<number>;<br>getAppMemorySize(callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.appManager | appManager | isRamConstrainedDevice(): Promise\<boolean>;<br>isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void; | 新增 |
| ohos.application.appManager | appManager | getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void; | 新增 |
| ohos.application.appManager | appManager | isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void;<br>isRunningInStabilityTest(): Promise\<boolean>; | 新增 |
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | DESTROY | 新增 |
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | BACKGROUND | 新增 |
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | FOREGROUND | 新增 |
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | CREATE | 新增 |
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | UNINITIALIZED | 新增 |
| ohos.application.abilityDelegatorRegistry | abilityDelegatorRegistry | getArguments(): AbilityDelegatorArgs; | 新增 |
| ohos.application.abilityDelegatorRegistry | abilityDelegatorRegistry | getAbilityDelegator(): AbilityDelegator; | 新增 |
| ohos.abilityAccessCtrl | GrantStatus | PERMISSION_GRANTED = 0 | 新增 |
| ohos.abilityAccessCtrl | GrantStatus | PERMISSION_DENIED = -1 | 新增 |
| ohos.abilityAccessCtrl | AtManager | verifyAccessToken(tokenID: number, permissionName: string): Promise\<GrantStatus>; | 新增 |
| ohos.abilityAccessCtrl | abilityAccessCtrl | createAtManager(): AtManager; | 新增 |
| ohos.ability.wantConstant | Action | ACTION_APP_ACCOUNT_OAUTH = "ohos.account.appAccount.action.oauth" | 新增 |
| ohos.ability.wantConstant | Action | ACTION_VIDEO_CAPTURE = "ohos.want.action.videoCapture" | 新增 |
| ohos.ability.wantConstant | Action | ACTION_IMAGE_CAPTURE = "ohos.want.action.imageCapture" | 新增 |
| ohos.ability.particleAbility | ErrorCode | INVALID_PARAMETER = -1 | 新增 |
| ohos.ability.particleAbility | particleAbility | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | 新增 |
| ohos.ability.particleAbility | particleAbility | connectAbility(request: Want, options:ConnectOptions): number; | 新增 |
| ohos.ability.particleAbility | particleAbility | cancelBackgroundRunning(callback: AsyncCallback\<void>): void;<br>cancelBackgroundRunning(): Promise\<void>; | 新增 |
| ohos.ability.particleAbility | particleAbility | startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>; | 新增 |
| ohos.ability.featureAbility | featureAbility | getWindow(callback: AsyncCallback\<window.Window>): void;<br>getWindow(): Promise\<window.Window>; | 新增 |
| ohos.ability.errorCode | ErrorCode | NO_ERROR = 0 | 新增 |
| ohos.ability.errorCode | ErrorCode | INVALID_PARAMETER = -1 | 新增 |
| ohos.ability.errorCode | ErrorCode | ABILITY_NOT_FOUND = -2 | 新增 |
| ohos.ability.errorCode | ErrorCode | PERMISSION_DENY = -3 | 新增 |
| lifecycle | LifecycleData | call?(method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void; | 新增 |
| lifecycle | LifecycleData | executeBatch?(ops: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void; | 新增 |
| lifecycle | LifecycleService | onReconnect?(want: Want): void; | 新增 |
| lifecycle | LifecycleApp | onMemoryLevel?(level: number): void; | 新增 |
| lifecycle | LifecycleApp | onNewWant?(want: Want): void; | 新增 |
| lifecycle | LifecycleApp | onActive?(): void; | 新增 |
| lifecycle | LifecycleApp | onInactive?(): void; | 新增 |
| lifecycle | LifecycleApp | onRestoreAbilityState?(inState: PacMap): void; | 新增 |
| lifecycle | LifecycleApp | onSaveAbilityState?(outState: PacMap): void; | 新增 |
| lifecycle | LifecycleForm | onAcquireFormState?(want: Want): formInfo.FormState; | 新增 |
| lifecycle | LifecycleForm | onDestroy?(formId: string): void; | 新增 |
| lifecycle | LifecycleForm | onEvent?(formId: string, message: string): void; | 新增 |
| lifecycle | LifecycleForm | onVisibilityChange?(newStatus: { [key: string]: number }): void; | 新增 |
| lifecycle | LifecycleForm | onUpdate?(formId: string): void; | 新增 |
| lifecycle | LifecycleForm | onCastToNormal?(formId: string): void; | 新增 |
| lifecycle | LifecycleForm | onCreate?(want: Want): formBindingData.FormBindingData; | 新增 |
