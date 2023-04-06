# JS API Changes of the Ability Framework

The table below lists the APIs changes of the ability framework in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| AbilityContext | AbilityContext | restoreWindowStage(localStorage: LocalStorage) : void; | Added|
| AbilityContext | AbilityContext | requestPermissionsFromUser(permissions: Array\<string>, requestCallback: AsyncCallback\<PermissionRequestResult>) : void;<br>requestPermissionsFromUser(permissions: Array\<string>) : Promise\<PermissionRequestResult>; | Added|
| AbilityContext | AbilityContext | setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;<br>setMissionIcon(icon: image.PixelMap): Promise\<void>; | Added|
| AbilityContext | AbilityContext | setMissionLabel(label: string, callback:AsyncCallback\<void>): void;<br>setMissionLabel(label: string): Promise\<void>; | Added|
| AbilityContext | AbilityContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | Added|
| AbilityContext | AbilityContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | Added|
| AbilityContext | AbilityContext | connectAbility(want: Want, options: ConnectOptions): number; | Added|
| AbilityContext | AbilityContext | terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void;<br>terminateSelfWithResult(parameter: AbilityResult): Promise\<void>; | Added|
| AbilityContext | AbilityContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | Added|
| AbilityContext | AbilityContext | startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>; | Added|
| AbilityContext | AbilityContext | startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void;<br>startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>; | Added|
| AbilityContext | AbilityContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | Added|
| AbilityContext | AbilityContext | startAbilityByCall(want: Want): Promise\<Caller>; | Added|
| AbilityContext | AbilityContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | Added|
| AbilityContext | AbilityContext | config: Configuration; | Added|
| AbilityContext | AbilityContext | currentHapModuleInfo: HapModuleInfo; | Added|
| AbilityContext | AbilityContext | abilityInfo: AbilityInfo; | Added|
| abilityDelegator | AbilityDelegator | doAbilityBackground(ability: Ability, callback: AsyncCallback\<boolean>): void;<br>doAbilityBackground(ability: Ability): Promise\<boolean>; | Added|
| abilityDelegator | AbilityDelegator | doAbilityForeground(ability: Ability, callback: AsyncCallback\<boolean>): void;<br>doAbilityForeground(ability: Ability): Promise\<boolean>; | Added|
| abilityDelegator | AbilityDelegator | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want): Promise\<void>; | Added|
| abilityDelegator | AbilityDelegator | getCurrentTopAbility(callback: AsyncCallback\<Ability>): void;<br>getCurrentTopAbility(): Promise\<Ability> | Added|
| abilityDelegator | AbilityDelegator | getAbilityState(ability: Ability): number; | Added|
| abilityDelegator | AbilityDelegator | getAppContext(): Context; | Added|
| abilityDelegator | AbilityDelegator | waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<Ability>): void;<br>waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<Ability>; | Added|
| abilityDelegator | AbilityDelegator | removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | Added|
| abilityDelegator | AbilityDelegator | addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;<br>addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>; | Added|
| abilityMonitor | AbilityMonitor | onWindowStageDestroy?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onWindowStageRestore?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onWindowStageCreate?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onAbilityDestroy?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onAbilityBackground?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onAbilityForeground?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | onAbilityCreate?:(data: Ability) => void; | Added|
| abilityMonitor | AbilityMonitor | abilityName: string; | Added|
| AbilityStageContext | AbilityStageContext | config: Configuration; | Added|
| AbilityStageContext | AbilityStageContext | currentHapModuleInfo: HapModuleInfo; | Added|
| AbilityStateData | AbilityStateData | moduleName: string; | Added|
| ApplicationContext | ApplicationContext | unregisterAbilityLifecycleCallback(callbackId: number,  callback: AsyncCallback\<void>): void;<br>unregisterAbilityLifecycleCallback(callbackId: number): Promise\<void>; | Added|
| ApplicationContext | ApplicationContext | registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): number; | Added|
| context | AreaMode | EL2 = 1 | Added|
| context | AreaMode | EL1 = 0 | Added|
| context | Context | createBundleContext(bundleName: string): Context; | Added|
| context | Context | area: AreaMode; | Added|
| context | Context | eventHub: EventHub; | Added|
| context | Context | distributedFilesDir: string; | Added|
| context | Context | bundleCodeDir : string; | Added|
| context | Context | preferencesDir : string; | Added|
| context | Context | databaseDir : string; | Added|
| context | Context | filesDir : string; | Added|
| context | Context | tempDir: string; | Added|
| context | Context | cacheDir: string; | Added|
| context | Context | applicationInfo: ApplicationInfo; | Added|
| context | Context | resourceManager: resmgr.ResourceManager; | Added|
| EventHub | EventHub | emit(event: string, ...args: Object[]): void | Added|
| EventHub | EventHub | off(event: string, callback?: Function): void | Added|
| EventHub | EventHub | on(event: string, callback: Function): void | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly writePermission: string; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly readPermission: string; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly enabled: boolean; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly metadata: Array\<Metadata>; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly applicationInfo: ApplicationInfo; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly permissions: Array\<string>; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly extensionAbilityType: bundle.ExtensionAbilityType; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly isVisible: boolean; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly iconId: number; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly descriptionId: number; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly labelId: number; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly name: string; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly moduleName: string; | Added|
| extensionAbilityInfo | ExtensionAbilityInfo | readonly bundleName: string; | Added|
| ExtensionContext | ExtensionContext | config: Configuration; | Added|
| ExtensionContext | ExtensionContext | currentHapModuleInfo: HapModuleInfo; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | type: bundle.ExtensionAbilityType; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | clientPackage: Array\<String>; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | startTime: number; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | processName: string; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | uid: number; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | pid: number; | Added|
| ExtensionRunningInfo | ExtensionRunningInfo | extension: ElementName; | Added|
| FormExtensionContext | FormExtensionContext | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | Added|
| MissionListener | MissionListener | onMissionIconUpdated(mission: number, icon: image.PixelMap): void; | Added|
| ohos.application.Ability | Ability | dump(params: Array\<string>): Array\<string>; | Added|
| ohos.application.Ability | Ability | onConfigurationUpdated(config: Configuration): void; | Added|
| ohos.application.Ability | Ability | onNewWant(want: Want): void; | Added|
| ohos.application.Ability | Ability | onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult; | Added|
| ohos.application.Ability | Ability | onBackground(): void; | Added|
| ohos.application.Ability | Ability | onForeground(): void; | Added|
| ohos.application.Ability | Ability | onDestroy(): void; | Added|
| ohos.application.Ability | Ability | onWindowStageRestore(windowStage: window.WindowStage): void; | Added|
| ohos.application.Ability | Ability | onWindowStageDestroy(): void; | Added|
| ohos.application.Ability | Ability | onWindowStageCreate(windowStage: window.WindowStage): void; | Added|
| ohos.application.Ability | Ability | onCreate(want: Want, param: AbilityConstant.LaunchParam): void; | Added|
| ohos.application.Ability | Ability | callee: Callee; | Added|
| ohos.application.Ability | Ability | lastRequestWant: Want; | Added|
| ohos.application.Ability | Ability | launchWant: Want; | Added|
| ohos.application.Ability | Ability | context: AbilityContext; | Added|
| ohos.application.Ability | Callee | off(method: string): void; | Added|
| ohos.application.Ability | Callee | on(method: string, callback: CaleeCallBack): void; | Added|
| ohos.application.Ability | Caller | onRelease(callback: OnReleaseCallBack): void; | Added|
| ohos.application.Ability | Caller | release(): void; | Added|
| ohos.application.Ability | Caller | callWithResult(method: string, data: rpc.Sequenceable): Promise<rpc.MessageParcel>; | Added|
| ohos.application.Ability | Caller | call(method: string, data: rpc.Sequenceable): Promise\<void>; | Added|
| ohos.application.Ability | CaleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | Added|
| ohos.application.Ability | OnReleaseCallBack | (msg: string): void; | Added|
| ohos.application.AbilityConstant | OnContinueResult | MISMATCH = 2 | Added|
| ohos.application.AbilityConstant | OnContinueResult | REJECT = 1 | Added|
| ohos.application.AbilityConstant | OnContinueResult | AGREE = 0 | Added|
| ohos.application.AbilityConstant | LastExitReason | NORMAL = 2 | Added|
| ohos.application.AbilityConstant | LastExitReason | ABILITY_NOT_RESPONDING = 1 | Added|
| ohos.application.AbilityConstant | LastExitReason | UNKNOWN = 0 | Added|
| ohos.application.AbilityConstant | LaunchReason | CONTINUATION = 3 | Added|
| ohos.application.AbilityConstant | LaunchReason | CALL = 2 | Added|
| ohos.application.AbilityConstant | LaunchReason | START_ABILITY = 1 | Added|
| ohos.application.AbilityConstant | LaunchReason | UNKNOWN = 0 | Added|
| ohos.application.AbilityConstant | LaunchParam | lastExitReason: LastExitReason; | Added|
| ohos.application.AbilityConstant | LaunchParam | launchReason: LaunchReason; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityContinue(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityBackground(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityForeground(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityDestroy(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityWindowStageDestroy(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityWindowStageCreate(ability: Ability): void; | Added|
| ohos.application.AbilityLifecycleCallback | AbilityLifecycleCallback | onAbilityCreate(ability: Ability): void; | Added|
| ohos.application.abilityManager | abilityManager | function getTopAbility(): Promise\<ElementName>;<br>function getTopAbility(callback: AsyncCallback\<ElementName>): void; | Added|
| ohos.application.abilityManager | abilityManager | function getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>;<br>function getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void; | Added|
| ohos.application.AbilityStage | AbilityStage | onConfigurationUpdated(config: Configuration): void; | Added|
| ohos.application.AbilityStage | AbilityStage | onAcceptWant(want: Want): string; | Added|
| ohos.application.AbilityStage | AbilityStage | onCreate(): void; | Added|
| ohos.application.AbilityStage | AbilityStage | context: AbilityStageContext; | Added|
| ohos.application.Configuration | Configuration | displayId?: number; | Added|
| ohos.application.Configuration | Configuration | screenDensity?: ConfigurationConstant.ScreenDensity; | Added|
| ohos.application.Configuration | Configuration | direction?: ConfigurationConstant.Direction; | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XXXLDPI = 640 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XXLDPI = 480 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_XLDPI = 320 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_LDPI = 240 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_MDPI = 160 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_SDPI = 120 | Added|
| ohos.application.ConfigurationConstant | ScreenDensity | SCREEN_DENSITY_NOT_SET = 0 | Added|
| ohos.application.ConfigurationConstant | Direction | DIRECTION_HORIZONTAL = 1 | Added|
| ohos.application.ConfigurationConstant | Direction | DIRECTION_VERTICAL = 0 | Added|
| ohos.application.ConfigurationConstant | Direction | DIRECTION_NOT_SET = -1 | Added|
| ohos.application.FormExtension | FormExtension | onAcquireFormState?(want: Want): formInfo.FormState; | Added|
| ohos.application.FormExtension | FormExtension | onConfigurationUpdated(config: Configuration): void; | Added|
| ohos.application.FormExtension | FormExtension | onDestroy(formId: string): void; | Added|
| ohos.application.FormExtension | FormExtension | onEvent(formId: string, message: string): void; | Added|
| ohos.application.FormExtension | FormExtension | onVisibilityChange(newStatus: { [key: string]: number }): void; | Added|
| ohos.application.FormExtension | FormExtension | onUpdate(formId: string): void; | Added|
| ohos.application.FormExtension | FormExtension | onCastToNormal(formId: string): void; | Added|
| ohos.application.FormExtension | FormExtension | onCreate(want: Want): formBindingData.FormBindingData; | Added|
| ohos.application.FormExtension | FormExtension | context: FormExtensionContext; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | dump(params: Array\<string>): Array\<string>; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onConfigurationUpdated(config: Configuration): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onReconnect(want: Want): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onDisconnect(want: Want): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onConnect(want: Want): rpc.RemoteObject; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onRequest(want: Want, startId: number): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onDestroy(): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | onCreate(want: Want): void; | Added|
| ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | context: ServiceExtensionContext; | Added|
| ohos.application.StartOptions | StartOptions | displayId?: number; | Added|
| ohos.application.StartOptions | StartOptions | windowMode?: number; | Added|
| ohos.application.StaticSubscriberExtensionAbility | StaticSubscriberExtensionAbility | onReceiveEvent(event: CommonEventData): void; | Added|
| ohos.application.uriPermissionManager | uriPermissionManager | function verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback\<number>): void;<br>function verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise\<number>; | Added|
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onWindowReady(window: Window): void; | Added|
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onDisconnect(want: Want): void; | Added|
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | onConnect(want: Want): rpc.RemoteObject; | Added|
| ohos.application.WindowExtensionAbility | WindowExtensionAbility | context: ExtensionContext; | Added|
| ohos.wantAgent | wantAgent | function getOperationType(agent: WantAgent, callback: AsyncCallback\<number>): void;<br>function getOperationType(agent: WantAgent): Promise\<number>; | Added|
| PermissionRequestResult | PermissionRequestResult | authResults: Array\<number>; | Added|
| PermissionRequestResult | PermissionRequestResult | permissions: Array\<string>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;<br>disconnectAbility(connection: number): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number; | Added|
| ServiceExtensionContext | ServiceExtensionContext | connectAbility(want: Want, options: ConnectOptions): number; | Added|
| ServiceExtensionContext | ServiceExtensionContext | terminateSelf(callback: AsyncCallback\<void>): void;<br>terminateSelf(): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want, options?: StartOptions): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | Added|
