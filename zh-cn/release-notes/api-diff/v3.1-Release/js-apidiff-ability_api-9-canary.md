# 元能力子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，元能力子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| AbilityContext | AbilityContext | restoreWindowStage(contentStorage: ContentStorage) : void; | 新增 |
| AbilityContext | AbilityContext | requestPermissionsFromUser(permissions: Array\<string>, requestCallback: AsyncCallback\<PermissionRequestResult>) : void;<br>requestPermissionsFromUser(permissions: Array\<string>) : Promise\<PermissionRequestResult>; | 新增 |
| AbilityContext | AbilityContext | setMissionLabel(label: string, callback:AsyncCallback\<void>): void;<br>setMissionLabel(label: string): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | 新增 |
| AbilityContext | AbilityContext | connectAbility(want: Want, options: ConnectOptions): number; | 新增 |
| AbilityContext | AbilityContext | terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void;<br>terminateSelfWithResult(parameter: AbilityResult): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>; | 新增 |
| AbilityContext | AbilityContext | startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>; | 新增 |
| AbilityContext | AbilityContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | startAbilityByCall(want: Want): Promise\<Caller>; | 新增 |
| AbilityContext | AbilityContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | config: Configuration; | 新增 |
| AbilityContext | AbilityContext | currentHapModuleInfo: HapModuleInfo; | 新增 |
| AbilityContext | AbilityContext | abilityInfo: AbilityInfo; | 新增 |
| abilityDelegator | AbilityDelegator | doAbilityBackground(ability: Ability, callback: AsyncCallback\<boolean>): void;<br>doAbilityBackground(ability: Ability): Promise\<boolean>; | 新增 |
| abilityDelegator | AbilityDelegator | doAbilityForeground(ability: Ability, callback: AsyncCallback\<boolean>): void;<br>doAbilityForeground(ability: Ability): Promise\<boolean>; | 新增 |
| abilityDelegator | AbilityDelegator | getCurrentTopAbility(callback: AsyncCallback\<Ability>): void;<br>getCurrentTopAbility(): Promise\<Ability> | 新增 |
| abilityDelegator | AbilityDelegator | getAbilityState(ability: Ability): number; | 新增 |
| abilityDelegator | AbilityDelegator | getAppContext(): Context; | 新增 |
| abilityDelegator | AbilityDelegator | waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<Ability>; | 新增 |
| abilityDelegator | AbilityDelegator | removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | 新增 |
| abilityDelegator | AbilityDelegator | addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageDestroy?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageRestore?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageCreate?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityDestroy?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityBackground?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityForeground?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityCreate?:() => void; | 新增 |
| abilityMonitor | AbilityMonitor | abilityName: string; | 新增 |
| AbilityStageContext | AbilityStageContext | config: Configuration; | 新增 |
| AbilityStageContext | AbilityStageContext | currentHapModuleInfo: HapModuleInfo; | 新增 |
| context | AreaMode | EL2 = 1 | 新增 |
| context | AreaMode | EL1 = 0 | 新增 |
| context | Context | switchArea(mode: AreaMode): void; | 新增 |
| context | Context | createBundleContext(bundleName: string): Context; | 新增 |
| context | Context | eventHub: EventHub; | 新增 |
| context | Context | distributedFilesDir: string; | 新增 |
| context | Context | bundleCodeDir : string; | 新增 |
| context | Context | storageDir : string; | 新增 |
| context | Context | databaseDir : string; | 新增 |
| context | Context | filesDir : string; | 新增 |
| context | Context | tempDir: string; | 新增 |
| context | Context | cacheDir: string; | 新增 |
| context | Context | applicationInfo: ApplicationInfo; | 新增 |
| context | Context | resourceManager: resmgr.ResourceManager; | 新增 |
| EventHub | EventHub | emit(event: string, ...args: Object[]): void | 新增 |
| EventHub | EventHub | off(event: string, callback?: Function): void | 新增 |
| EventHub | EventHub | on(event: string, callback: Function): void | 新增 |
| ExtAbilityContext | ExtAbilityContext | currentHapModuleInfo: HapModuleInfo; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly writePermission: string; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly readPermission: string; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly enabled: boolean; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly metadata: Array\<Metadata>; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly applicationInfo: ApplicationInfo; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly permissions: Array\<string>; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly extensionAbilityType: bundle.ExtensionAbilityType; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly isVisible: boolean; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly iconId: number; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly descriptionId: number; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly labelId: number; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly name: string; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly moduleName: string; | 新增 |
| extensionAbilityInfo | ExtensionAbilityInfo | readonly bundleName: string; | 新增 |
| ExtensionContext | ExtensionContext | config: Configuration; | 新增 |
| ExtensionContext | ExtensionContext | currentHapModuleInfo: HapModuleInfo; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | type: bundle.ExtensionAbilityType; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | clientPackage: Array\<String>; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | startTime: number; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | processName: string; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | uid: number; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | pid: number; | 新增 |
| ExtensionRunningInfo | ExtensionRunningInfo | extension: ElementName; | 新增 |
| FormExtensionContext | FormExtensionContext | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | 新增 |
| ohos.application.Ability | Ability | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.Ability | Ability | onNewWant(want: Want): void; | 新增 |
| ohos.application.Ability | Ability | onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult; | 新增 |
| ohos.application.Ability | Ability | onBackground(): void; | 新增 |
| ohos.application.Ability | Ability | onForeground(): void; | 新增 |
| ohos.application.Ability | Ability | onDestroy(): void; | 新增 |
| ohos.application.Ability | Ability | onWindowStageRestore(windowStage: window.WindowStage): void; | 新增 |
| ohos.application.Ability | Ability | onWindowStageDestroy(): void; | 新增 |
| ohos.application.Ability | Ability | onWindowStageCreate(windowStage: window.WindowStage): void; | 新增 |
| ohos.application.Ability | Ability | onCreate(want: Want, param: AbilityConstant.LaunchParam): void; | 新增 |
| ohos.application.Ability | Ability | callee: Callee; | 新增 |
| ohos.application.Ability | Ability | lastRequestWant: Want; | 新增 |
| ohos.application.Ability | Ability | launchWant: Want; | 新增 |
| ohos.application.Ability | Ability | context: AbilityContext; | 新增 |
| ohos.application.Ability | Callee | off(method: string): void; | 新增 |
| ohos.application.Ability | Callee | on(method: string, callback: function): void; | 新增 |
| ohos.application.Ability | Caller | onRelease(callback: function): void; | 新增 |
| ohos.application.Ability | Caller | release(): void; | 新增 |
| ohos.application.Ability | Caller | callWithResult(method: string, data: rpc.Sequenceable): Promise\<rpc.MessageParcel>; | 新增 |
| ohos.application.Ability | Caller | call(method: string, data: rpc.Sequenceable): Promise\<void>; | 新增 |
| ohos.application.AbilityConstant | OnContinueResult | MISMATCH = 2 | 新增 |
| ohos.application.AbilityConstant | OnContinueResult | REJECT = 1 | 新增 |
| ohos.application.AbilityConstant | OnContinueResult | AGREE = 0 | 新增 |
| ohos.application.AbilityConstant | LastExitReason | NORMAL = 2 | 新增 |
| ohos.application.AbilityConstant | LastExitReason | ABILITY_NOT_RESPONDING = 1 | 新增 |
| ohos.application.AbilityConstant | LastExitReason | UNKNOWN = 0 | 新增 |
| ohos.application.AbilityConstant | LaunchReason | CONTINUATION = 3 | 新增 |
| ohos.application.AbilityConstant | LaunchReason | CALL = 2 | 新增 |
| ohos.application.AbilityConstant | LaunchReason | START_ABILITY = 1 | 新增 |
| ohos.application.AbilityConstant | LaunchReason | UNKNOWN = 0 | 新增 |
| ohos.application.AbilityConstant | LaunchParam | lastExitReason: LastExitReason; | 新增 |
| ohos.application.AbilityConstant | LaunchParam | launchReason: LaunchReason; | 新增 |
| ohos.application.abilityManager | abilityManager | getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>;<br>getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void; | 新增 |
| ohos.application.AbilityStage | AbilityStage | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.AbilityStage | AbilityStage | onAcceptWant(want: Want): string; | 新增 |
| ohos.application.AbilityStage | AbilityStage | onCreate(): void; | 新增 |
| ohos.application.AbilityStage | AbilityStage | context: AbilityStageContext; | 新增 |
| ohos.application.Configuration | Configuration | displayId?: number; | 新增 |
| ohos.application.Configuration | Configuration | screenDensity?: ConfigurationConstant.ScreenDensity; | 新增 |
| ohos.application.Configuration | Configuration | direction?: ConfigurationConstant.Direction; | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XXXLDPI = 640 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XXLDPI = 480 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XLDPI = 320 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_LDPI = 240 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_MDPI = 160 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_SDPI = 120 | 新增 |
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_NOT_SET = 0 | 新增 |
| ohos.application.ConfigurationConstant | Direction | DIRECTION_HORIZONTAL = 1 | 新增 |
| ohos.application.ConfigurationConstant | Direction | DIRECTION_VERTICAL = 0 | 新增 |
| ohos.application.ConfigurationConstant | Direction | DIRECTION_NOT_SET = -1 | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | normalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | batchInsert?(uri: string, valueBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getType?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "query?(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates,  callback: AsyncCallback\<ResultSet>): void;" | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | delete?(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "update?(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void;" | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | insert?(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | onCreate?(want: Want): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | context?: ExtensionContext; | 新增 |
| ohos.application.FormExtension | FormExtension | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onDestroy(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onEvent(formId: string, message: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onVisibilityChange(newStatus: { [key: string]: number }): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onUpdate(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onCastToNormal(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onCreate(want: Want): formBindingData.FormBindingData; | 新增 |
| ohos.application.FormExtension | FormExtension | context: FormExtensionContext; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onReconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onDisconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onConnect(want: Want): rpc.RemoteObject; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onRequest(want: Want, startId: number): void; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onDestroy(): void; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | onCreate(want: Want): void; | 新增 |
| ohos.application.ServiceExtAbility | ServiceExtAbility | context: ServiceExtAbilityContext; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onReconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onDisconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onConnect(want: Want): rpc.RemoteObject; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onRequest(want: Want, startId: number): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onDestroy(): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | onCreate(want: Want): void; | 新增 |
| ohos.application.ServiceExtension | ServiceExtension | context: ServiceExtensionContext; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onReconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onDisconnect(want: Want): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onConnect(want: Want): rpc.RemoteObject; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onRequest(want: Want, startId: number): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onDestroy(): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onCreate(want: Want): void; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | context: ServiceExtensionContext; | 新增 |
| ohos.application.StartOptions | StartOptions | displayId?: number; | 新增 |
| ohos.application.StartOptions | StartOptions | windowMode?: number; | 新增 |
| ohos.application.uriPermissionManager | uriPermissionManager | verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback\<number>): void;<br>verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise\<number>; | 新增 |
| ohos.wantAgent | wantAgent | getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;<br>getOperationType(agent: WantAgent): Promise\<number>; | 新增 |
| PermissionRequestResult | PermissionRequestResult | authResults: Array\<number>; | 新增 |
| PermissionRequestResult | PermissionRequestResult | permissions: Array\<string>; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | connectAbility(want: Want, options: ConnectOptions): number; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtAbilityContext | ServiceExtAbilityContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | connectAbility(want: Want, options: ConnectOptions): number; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | 新增 |
| want | Want | extensionAbilityType?: number; | 新增 |
| want | Want | extensionAbilityName?: string; | 新增 |
