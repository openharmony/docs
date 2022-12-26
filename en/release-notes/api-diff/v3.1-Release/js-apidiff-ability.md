# JS API Changes of the Ability Framework

The table below lists the APIs changes of the ability framework in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| featureability | FeatureAbility | static getDeviceList(flag: number): Promise\<Result>; | Added|
| customizeData | CustomizeData | extra: string; | Added|
| applicationInfo | ApplicationInfo | readonly entityType: string; | Added|
| applicationInfo | ApplicationInfo | readonly uid: number; | Added|
| applicationInfo | ApplicationInfo | readonly accessTokenId: number; | Added|
| applicationInfo | ApplicationInfo | readonly removable: boolean; | Added|
| applicationInfo | ApplicationInfo | readonly metaData: Map\<string, Array\<CustomizeData>>; | Added|
| applicationInfo | ApplicationInfo | readonly codePath: string; | Added|
| applicationInfo | ApplicationInfo | readonly moduleInfos: Array\<ModuleInfo>; | Added|
| shellCmdResult | ShellCmdResult | exitCode: number; | Added|
| shellCmdResult | ShellCmdResult | stdResult: String; | Added|
| ProcessRunningInfo | ProcessRunningInfo | bundleNames: Array\<string>; | Added|
| ProcessRunningInfo | ProcessRunningInfo | processName: string; | Added|
| ProcessRunningInfo | ProcessRunningInfo | uid: number; | Added|
| ProcessRunningInfo | ProcessRunningInfo | pid: number; | Added|
| BaseContext | BaseContext | stageMode: boolean; | Added|
| abilityDelegatorArgs | AbilityDelegatorArgs | testRunnerClassName: string; | Added|
| abilityDelegatorArgs | AbilityDelegatorArgs | testCaseNames: string; | Added|
| abilityDelegatorArgs | AbilityDelegatorArgs | parameters: {[key: string]: string}; | Added|
| abilityDelegatorArgs | AbilityDelegatorArgs | bundleName: string; | Added|
| abilityDelegator | AbilityDelegator | executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;<br>executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;<br>executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>; | Added|
| abilityDelegator | AbilityDelegator | print(msg: string, callback: AsyncCallback\<void>): void;<br>print(msg: string): Promise\<void>; | Added|
| context | Context | printDrawnCompleted(callback: AsyncCallback\<void>): void;<br>printDrawnCompleted(): Promise\<void>; | Added|
| context | Context | isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void;<br>isUpdatingConfigurations(): Promise\<boolean>; | Added|
| context | Context | getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void<br>getAbilityInfo(): Promise\<AbilityInfo>; | Added|
| context | Context | getApplicationContext(): Context; | Added|
| context | Context | getAppVersionInfo(callback: AsyncCallback\<AppVersionInfo>): void<br>getAppVersionInfo(): Promise\<AppVersionInfo>; | Added|
| context | Context | getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void<br>getHapModuleInfo(): Promise\<HapModuleInfo>; | Added|
| context | Context | getAppType(callback: AsyncCallback\<string>): void<br>getAppType(): Promise\<string>; | Added|
| context | Context | getOrCreateDistributedDir(): Promise\<string>;<br>getOrCreateDistributedDir(callback: AsyncCallback\<string>): void; | Added|
| context | Context | getCacheDir(callback: AsyncCallback\<string>): void;<br>getCacheDir(): Promise\<string>; | Added|
| context | Context | getFilesDir(callback: AsyncCallback\<string>): void;<br>getFilesDir(): Promise\<string>; | Added|
| context | Context | setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback\<void>): void<br>setWakeUpScreen(wakeUp: boolean): Promise\<void>; | Added|
| context | Context | setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void<br>setShowOnLockScreen(show: boolean): Promise\<void>; | Added|
| context | Context | setDisplayOrientation(orientation: DisplayOrientation, callback: AsyncCallback\<void>): void<br>setDisplayOrientation(orientation: DisplayOrientation): Promise\<void>; | Added|
| context | Context | getDisplayOrientation(callback: AsyncCallback\<DisplayOrientation>): void<br>getDisplayOrientation(): Promise\<DisplayOrientation>; | Added|
| appVersionInfo | AppVersionInfo | readonly versionName: string; | Added|
| appVersionInfo | AppVersionInfo | readonly versionCode: number; | Added|
| appVersionInfo | AppVersionInfo | readonly appName: string; | Added|
| dataAbilityHelper | PacMap | [key: string]: number \| string \| boolean \| Array\<string \| number \| boolean> \| null; | Added|
| dataAbilityHelper | DataAbilityHelper | executeBatch(uri: string, operations: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void;<br>executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>; | Added|
| dataAbilityHelper | DataAbilityHelper | call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void;<br>call(uri: string, method: string, arg: string, extras: PacMap): Promise\<PacMap>; | Added|
| ohos.application.Want | Want | entities?: Array\<string>; | Added|
| ohos.application.Want | Want | parameters?: {[key: string]: any}; | Added|
| ohos.application.Want | Want | action?: string; | Added|
| ohos.application.Want | Want | flags?: number; | Added|
| ohos.application.Want | Want | type?: string; | Added|
| ohos.application.Want | Want | uri?: string; | Added|
| ohos.application.Want | Want | abilityName?: string; | Added|
| ohos.application.Want | Want | bundleName?: string; | Added|
| ohos.application.Want | Want | deviceId?: string; | Added|
| ohos.application.testRunner | TestRunner | onRun(): void; | Added|
| ohos.application.testRunner | TestRunner | onPrepare(): void; | Added|
| ohos.application.formProvider | formProvider | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | Added|
| ohos.application.formProvider | formProvider | setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void;<br>setFormNextRefreshTime(formId: string, minute: number): Promise\<void>; | Added|
| ohos.application.formInfo | FormParam | TEMPORARY_KEY = "ohos.extra.param.key.form_temporary" | Added|
| ohos.application.formInfo | FormParam | HEIGHT_KEY = "ohos.extra.param.key.form_height" | Added|
| ohos.application.formInfo | FormParam | WIDTH_KEY = "ohos.extra.param.key.form_width" | Added|
| ohos.application.formInfo | FormParam | MODULE_NAME_KEY = "ohos.extra.param.key.module_name" | Added|
| ohos.application.formInfo | FormParam | NAME_KEY = "ohos.extra.param.key.form_name" | Added|
| ohos.application.formInfo | FormParam | DIMENSION_KEY = "ohos.extra.param.key.form_dimension" | Added|
| ohos.application.formInfo | FormState | READY = 1 | Added|
| ohos.application.formInfo | FormState | DEFAULT = 0 | Added|
| ohos.application.formInfo | FormState | UNKNOWN = -1 | Added|
| ohos.application.formInfo | FormStateInfo | want: Want; | Added|
| ohos.application.formInfo | FormStateInfo | formState: FormState; | Added|
| ohos.application.formInfo | ColorMode | MODE_LIGHT = 1 | Added|
| ohos.application.formInfo | ColorMode | MODE_DARK = 0 | Added|
| ohos.application.formInfo | ColorMode | MODE_AUTO = -1 | Added|
| ohos.application.formInfo | FormType | JS = 1 | Added|
| ohos.application.formInfo | FormInfo | customizeData: {[key: string]: [value: string]}; | Added|
| ohos.application.formInfo | FormInfo | supportDimensions: Array\<number>; | Added|
| ohos.application.formInfo | FormInfo | defaultDimension: number; | Added|
| ohos.application.formInfo | FormInfo | updateDuration: number; | Added|
| ohos.application.formInfo | FormInfo | formConfigAbility: string; | Added|
| ohos.application.formInfo | FormInfo | scheduledUpdateTime: string; | Added|
| ohos.application.formInfo | FormInfo | relatedBundleName: string; | Added|
| ohos.application.formInfo | FormInfo | formVisibleNotify: boolean; | Added|
| ohos.application.formInfo | FormInfo | updateEnabled: boolean; | Added|
| ohos.application.formInfo | FormInfo | isDefault: boolean; | Added|
| ohos.application.formInfo | FormInfo | colorMode: ColorMode; | Added|
| ohos.application.formInfo | FormInfo | jsComponentName: string; | Added|
| ohos.application.formInfo | FormInfo | type: FormType; | Added|
| ohos.application.formInfo | FormInfo | description: string; | Added|
| ohos.application.formInfo | FormInfo | name: string; | Added|
| ohos.application.formInfo | FormInfo | abilityName: string; | Added|
| ohos.application.formInfo | FormInfo | moduleName: string; | Added|
| ohos.application.formInfo | FormInfo | bundleName: string; | Added|
| ohos.application.formError | FormError | ERR_IN_RECOVERY = 36 | Added|
| ohos.application.formError | FormError | ERR_FORM_DUPLICATE_ADDED = 31 | Added|
| ohos.application.formError | FormError | ERR_SYSTEM_RESPONSES_FAILED = 30 | Added|
| ohos.application.formError | FormError | ERR_FORM_FA_NOT_INSTALLED = 20 | Added|
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_DIMENSION = 19 | Added|
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_ABILITY = 18 | Added|
| ohos.application.formError | FormError | ERR_FORM_NO_SUCH_MODULE = 17 | Added|
| ohos.application.formError | FormError | ERR_MAX_SYSTEM_TEMP_FORMS = 16 | Added|
| ohos.application.formError | FormError | ERR_MAX_FORMS_PER_CLIENT = 15 | Added|
| ohos.application.formError | FormError | ERR_PROVIDER_DEL_FAIL = 14 | Added|
| ohos.application.formError | FormError | ERR_OPERATION_FORM_NOT_SELF = 13 | Added|
| ohos.application.formError | FormError | ERR_MAX_INSTANCES_PER_FORM = 12 | Added|
| ohos.application.formError | FormError | ERR_MAX_SYSTEM_FORMS = 11 | Added|
| ohos.application.formError | FormError | ERR_BIND_PROVIDER_FAILED = 10 | Added|
| ohos.application.formError | FormError | ERR_NOT_EXIST_ID = 9 | Added|
| ohos.application.formError | FormError | ERR_CFG_NOT_MATCH_ID = 8 | Added|
| ohos.application.formError | FormError | ERR_ADD_INVALID_PARAM = 7 | Added|
| ohos.application.formError | FormError | ERR_GET_LAYOUT_FAILED = 6 | Added|
| ohos.application.formError | FormError | ERR_GET_BUNDLE_FAILED = 5 | Added|
| ohos.application.formError | FormError | ERR_GET_INFO_FAILED = 4 | Added|
| ohos.application.formError | FormError | ERR_PERMISSION_DENY = 2 | Added|
| ohos.application.formError | FormError | ERR_COMMON = 1 | Added|
| ohos.application.formBindingData | FormBindingData | data: Object | Added|
| ohos.application.formBindingData | formBindingData | createFormBindingData(obj?: Object \| string): FormBindingData; | Added|
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_LIGHT = 1 | Added|
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_DARK = 0 | Added|
| ohos.application.ConfigurationConstant | ColorMode | COLOR_MODE_NOT_SET = -1 | Added|
| ohos.application.Configuration | Configuration | colorMode: ConfigurationConstant.ColorMode; | Added|
| ohos.application.Configuration | Configuration | language: string; | Added|
| ohos.application.appManager | appManager | getAppMemorySize(): Promise\<number>;<br>getAppMemorySize(callback: AsyncCallback\<number>): void; | Added|
| ohos.application.appManager | appManager | isRamConstrainedDevice(): Promise\<boolean>;<br>isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void; | Added|
| ohos.application.appManager | appManager | getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void; | Added|
| ohos.application.appManager | appManager | isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void;<br>isRunningInStabilityTest(): Promise\<boolean>; | Added|
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | DESTROY | Added|
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | BACKGROUND | Added|
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | FOREGROUND | Added|
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | CREATE | Added|
| ohos.application.abilityDelegatorRegistry | AbilityLifecycleState | UNINITIALIZED | Added|
| ohos.application.abilityDelegatorRegistry | abilityDelegatorRegistry | getArguments(): AbilityDelegatorArgs; | Added|
| ohos.application.abilityDelegatorRegistry | abilityDelegatorRegistry | getAbilityDelegator(): AbilityDelegator; | Added|
| ohos.abilityAccessCtrl | GrantStatus | PERMISSION_GRANTED = 0 | Added|
| ohos.abilityAccessCtrl | GrantStatus | PERMISSION_DENIED = -1 | Added|
| ohos.abilityAccessCtrl | AtManager | verifyAccessToken(tokenID: number, permissionName: string): Promise\<GrantStatus>; | Added|
| ohos.abilityAccessCtrl | abilityAccessCtrl | createAtManager(): AtManager; | Added|
| ohos.ability.wantConstant | Action | ACTION_APP_ACCOUNT_OAUTH = "ohos.account.appAccount.action.oauth" | Added|
| ohos.ability.wantConstant | Action | ACTION_VIDEO_CAPTURE = "ohos.want.action.videoCapture" | Added|
| ohos.ability.wantConstant | Action | ACTION_IMAGE_CAPTURE = "ohos.want.action.imageCapture" | Added|
| ohos.ability.particleAbility | ErrorCode | INVALID_PARAMETER = -1 | Added|
| ohos.ability.particleAbility | particleAbility | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | Added|
| ohos.ability.particleAbility | particleAbility | connectAbility(request: Want, options:ConnectOptions): number; | Added|
| ohos.ability.particleAbility | particleAbility | cancelBackgroundRunning(callback: AsyncCallback\<void>): void;<br>cancelBackgroundRunning(): Promise\<void>; | Added|
| ohos.ability.particleAbility | particleAbility | startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>; | Added|
| ohos.ability.featureAbility | featureAbility | getWindow(callback: AsyncCallback\<window.Window>): void;<br>getWindow(): Promise\<window.Window>; | Added|
| ohos.ability.errorCode | ErrorCode | NO_ERROR = 0 | Added|
| ohos.ability.errorCode | ErrorCode | INVALID_PARAMETER = -1 | Added|
| ohos.ability.errorCode | ErrorCode | ABILITY_NOT_FOUND = -2 | Added|
| ohos.ability.errorCode | ErrorCode | PERMISSION_DENY = -3 | Added|
| lifecycle | LifecycleData | call?(method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void; | Added|
| lifecycle | LifecycleData | executeBatch?(ops: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void; | Added|
| lifecycle | LifecycleService | onReconnect?(want: Want): void; | Added|
| lifecycle | LifecycleApp | onMemoryLevel?(level: number): void; | Added|
| lifecycle | LifecycleApp | onNewWant?(want: Want): void; | Added|
| lifecycle | LifecycleApp | onActive?(): void; | Added|
| lifecycle | LifecycleApp | onInactive?(): void; | Added|
| lifecycle | LifecycleApp | onRestoreAbilityState?(inState: PacMap): void; | Added|
| lifecycle | LifecycleApp | onSaveAbilityState?(outState: PacMap): void; | Added|
| lifecycle | LifecycleForm | onAcquireFormState?(want: Want): formInfo.FormState; | Added|
| lifecycle | LifecycleForm | onDestroy?(formId: string): void; | Added|
| lifecycle | LifecycleForm | onEvent?(formId: string, message: string): void; | Added|
| lifecycle | LifecycleForm | onVisibilityChange?(newStatus: { [key: string]: number }): void; | Added|
| lifecycle | LifecycleForm | onUpdate?(formId: string): void; | Added|
| lifecycle | LifecycleForm | onCastToNormal?(formId: string): void; | Added|
| lifecycle | LifecycleForm | onCreate?(want: Want): formBindingData.FormBindingData; | Added|
