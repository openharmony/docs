# 元能力子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，元能力子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| AbilityContext | AbilityContext | restoreWindowStage(localStorage: LocalStorage) : void; | 新增 |
| AbilityContext | AbilityContext | requestPermissionsFromUser(permissions: Array\<string>, requestCallback: AsyncCallback\<PermissionRequestResult>) : void;<br>requestPermissionsFromUser(permissions: Array\<string>) : Promise\<PermissionRequestResult>; | 新增 |
| AbilityContext | AbilityContext | setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;<br>setMissionIcon(icon: image.PixelMap): Promise\<void>; | 新增 |
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
| abilityDelegator | AbilityDelegator | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want): Promise\<void>; | 新增 |
| abilityDelegator | AbilityDelegator | getCurrentTopAbility(callback: AsyncCallback\<Ability>): void;<br>getCurrentTopAbility(): Promise\<Ability> | 新增 |
| abilityDelegator | AbilityDelegator | getAbilityState(ability: Ability): number; | 新增 |
| abilityDelegator | AbilityDelegator | getAppContext(): Context; | 新增 |
| abilityDelegator | AbilityDelegator | waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<Ability>; | 新增 |
| abilityDelegator | AbilityDelegator | removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | 新增 |
| abilityDelegator | AbilityDelegator | addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageDestroy?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageRestore?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onWindowStageCreate?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityDestroy?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityBackground?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityForeground?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | onAbilityCreate?:(data: Ability) => void; | 新增 |
| abilityMonitor | AbilityMonitor | abilityName: string; | 新增 |
| AbilityStageContext | AbilityStageContext | config: Configuration; | 新增 |
| AbilityStageContext | AbilityStageContext | currentHapModuleInfo: HapModuleInfo; | 新增 |
| AbilityStateData | AbilityStateData | moduleName: string; | 新增 |
| ApplicationContext | ApplicationContext | unregisterAbilityLifecycleCallback(callbackId: number,  callback: AsyncCallback\<void>): void;<br>unregisterAbilityLifecycleCallback(callbackId: number): Promise\<void>; | 新增 |
| ApplicationContext | ApplicationContext | registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): number; | 新增 |
| context | AreaMode | EL2 = 1 | 新增 |
| context | AreaMode | EL1 = 0 | 新增 |
| context | Context | createBundleContext(bundleName: string): Context; | 新增 |
| context | Context | area: AreaMode; | 新增 |
| context | Context | eventHub: EventHub; | 新增 |
| context | Context | distributedFilesDir: string; | 新增 |
| context | Context | bundleCodeDir : string; | 新增 |
| context | Context | preferencesDir : string; | 新增 |
| context | Context | databaseDir : string; | 新增 |
| context | Context | filesDir : string; | 新增 |
| context | Context | tempDir: string; | 新增 |
| context | Context | cacheDir: string; | 新增 |
| context | Context | applicationInfo: ApplicationInfo; | 新增 |
| context | Context | resourceManager: resmgr.ResourceManager; | 新增 |
| EventHub | EventHub | emit(event: string, ...args: Object[]): void | 新增 |
| EventHub | EventHub | off(event: string, callback?: Function): void | 新增 |
| EventHub | EventHub | on(event: string, callback: Function): void | 新增 |
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
| MissionListener | MissionListener | onMissionIconUpdated(mission: number, icon: image.PixelMap): void; | 新增 |
| ohos.application.Ability | Ability | dump(params: Array\<string>): Array\<string>; | 新增 |
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
| ohos.application.Ability | Callee | on(method: string, callback: CaleeCallBack): void; | 新增 |
| ohos.application.Ability | Caller | onRelease(callback: OnReleaseCallBack): void; | 新增 |
| ohos.application.Ability | Caller | release(): void; | 新增 |
| ohos.application.Ability | Caller | callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>; | 新增 |
| ohos.application.Ability | Caller | call(method: string, data: rpc.Sequenceable): Promise\<void>; | 新增 |
| ohos.application.Ability | CaleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | 新增 |
| ohos.application.Ability | OnReleaseCallBack | (msg: string): void; | 新增 |
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
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityContinue(ability: Ability): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityBackground(ability: Ability): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityForeground(ability: Ability): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityDestroy(ability: Ability): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onWindowStageCreate(ability: Ability, windowStage: window.WindowStage): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onWindowStageActive(ability: Ability, windowStage: window.WindowStage): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onWindowStageInactive(ability: Ability, windowStage: window.WindowStage): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onWindowStageDestroy(ability: Ability, windowStage: window.WindowStage): void; | 新增 |
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityCreate(ability: Ability): void; | 新增 |
| ohos.application.abilityManager | abilityManager | function getTopAbility(): Promise\<ElementName>;<br>function getTopAbility(callback: AsyncCallback\<ElementName>): void; | 新增 |
| ohos.application.abilityManager | abilityManager | function getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>;<br>function getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void; | 新增 |
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
| ohos.application.FormExtension | FormExtension | onAcquireFormState?(want: Want): formInfo.FormState; | 新增 |
| ohos.application.FormExtension | FormExtension | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onDestroy(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onEvent(formId: string, message: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onVisibilityChange(newStatus: { [key: string]: number }): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onUpdate(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onCastToNormal(formId: string): void; | 新增 |
| ohos.application.FormExtension | FormExtension | onCreate(want: Want): formBindingData.FormBindingData; | 新增 |
| ohos.application.FormExtension | FormExtension | context: FormExtensionContext; | 新增 |
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | dump(params: Array\<string>): Array\<string>; | 新增 |
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
| ohos.application.StaticSubscriberExtensionAbility | StaticSubscriberExtensionAbility | onReceiveEvent(event: CommonEventData): void; | 新增 |
| ohos.application.uriPermissionManager | uriPermissionManager | function verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback\<number>): void;<br>function verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise\<number>; | 新增 |
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onWindowReady(window: Window): void; | 新增 |
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onDisconnect(want: Want): void; | 新增 |
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onConnect(want: Want): rpc.RemoteObject; | 新增 |
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | context: ExtensionContext; | 新增 |
| ohos.wantAgent | wantAgent | function getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;<br>function getOperationType(agent: WantAgent): Promise\<number>; | 新增 |
| PermissionRequestResult | PermissionRequestResult | authResults: Array\<number>; | 新增 |
| PermissionRequestResult | PermissionRequestResult | permissions: Array\<string>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | connectAbility(want: Want, options: ConnectOptions): number; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | 新增 |

