| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|SysCap changed|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: NA|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: SystemCapability.Ability.AbilityRuntime.Core|api/@ohos.net.vpn.d.ts|
|Permission changed|Class name: UIAbilityContext;<br>API declaration: startAbilityByCall(want: Want): Promise\<Caller>;<br>Differences: NA|Class name: UIAbilityContext;<br>API declaration: startAbilityByCall(want: Want): Promise\<Caller>;<br>Differences: ohos.permission.DISTRIBUTED_DATASYNC|api/application/UIAbilityContext.d.ts|
|Function changed|Class name: LifecycleForm;<br>API declaration: onVisibilityChange?(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>Differences: newStatus: {<br>        [key: string]: number;<br>    }|Class name: LifecycleForm;<br>API declaration: onVisibilityChange?(newStatus: Record\<string, number>): void;<br>Differences: newStatus: Record\<string, number>|api/@internal/full/lifecycle.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onContinue(wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnContinueResult;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onContinue(wantParam: Record\<string, Object>): AbilityConstant.OnContinueResult;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onSaveState(reason: AbilityConstant.StateType, wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnSaveResult;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onSaveState(reason: AbilityConstant.StateType, wantParam: Record\<string, Object>): AbilityConstant.OnSaveResult;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onShare(wantParam: {<br>        [key: string]: Object;<br>    }): void;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onShare(wantParam: Record\<string, Object>): void;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: FormExtensionAbility;<br>API declaration: onChangeFormVisibility(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>Differences: newStatus: {<br>        [key: string]: number;<br>    }|Class name: FormExtensionAbility;<br>API declaration: onChangeFormVisibility(newStatus: Record\<string, number>): void;<br>Differences: newStatus: Record\<string, number>|api/@ohos.app.form.FormExtensionAbility.d.ts|
|Function changed|Class name: AbilityDelegator;<br>API declaration: setMockList(mockList: {<br>        [key: string]: string;<br>    }): void;<br>Differences: mockList: {<br>        [key: string]: string;<br>    }|Class name: AbilityDelegator;<br>API declaration: setMockList(mockList: Record\<string, string>): void;<br>Differences: mockList: Record\<string, string>|api/application/AbilityDelegator.d.ts|
|Attribute changed|Class name: Want;<br>API declaration: parameters?: {<br>        [key: string]: Object;<br>    };<br>Differences: {<br>        [key: string]: Object;<br>    }|Class name: Want;<br>API declaration: parameters?: Record\<string, Object>;<br>Differences: Record\<string, Object>|api/@ohos.app.ability.Want.d.ts|
|Attribute changed|Class name: CompleteData;<br>API declaration: extraInfo?: {<br>            [key: string]: Object;<br>        };<br>Differences: {<br>            [key: string]: Object;<br>        }|Class name: CompleteData;<br>API declaration: extraInfo?: Record\<string, Object>;<br>Differences: Record\<string, Object>|api/@ohos.app.ability.wantAgent.d.ts|
|Attribute changed|Class name: FormInfo;<br>API declaration: customizeData: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        };<br>Differences: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        }|Class name: FormInfo;<br>API declaration: customizeData: Record\<string, string>;<br>Differences: Record\<string, string>|api/@ohos.app.form.formInfo.d.ts|
|Attribute changed|Class name: AbilityDelegatorArgs;<br>API declaration: parameters: {<br>        [key: string]: string;<br>    };<br>Differences: {<br>        [key: string]: string;<br>    }|Class name: AbilityDelegatorArgs;<br>API declaration: parameters: Record\<string, string>;<br>Differences: Record\<string, string>|api/application/abilityDelegatorArgs.d.ts|
|API added|NA|Class name: common;<br>API declaration: export type VpnExtensionContext = _VpnExtensionContext.default;<br>Differences: export type VpnExtensionContext = _VpnExtensionContext.default;|api/@ohos.app.ability.common.d.ts|
|API added|NA|Class name: global;<br>API declaration:  export default class VpnExtensionAbility<br>Differences:  export default class VpnExtensionAbility|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: context: VpnExtensionContext;<br>Differences: context: VpnExtensionContext;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: onCreate(want: Want): void;<br>Differences: onCreate(want: Want): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: onDestroy(): void;<br>Differences: onDestroy(): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: FormInfo;<br>API declaration: displayName: string;<br>Differences: displayName: string;|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: FormInfo;<br>API declaration: displayNameId: number;<br>Differences: displayNameId: number;|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: export type VpnExtensionContext = _VpnExtensionContext;<br>Differences: export type VpnExtensionContext = _VpnExtensionContext;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: function startVpnExtensionAbility(want: Want): Promise\<void>;<br>Differences: function startVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: function stopVpnExtensionAbility(want: Want): Promise\<void>;<br>Differences: function stopVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: StartAbilityParameter;<br>API declaration: abilityStartSettings?: Record\<string, Object>;<br>Differences: abilityStartSettings?: Record\<string, Object>;|api/ability/startAbilityParameter.d.ts|
|API added|NA|Class name: global;<br>API declaration:  export default class VpnExtensionContext<br>Differences:  export default class VpnExtensionContext|api/application/VpnExtensionContext.d.ts|
|API added|NA|Class name: TriggerInfo;<br>API declaration: extraInfos?: Record\<string, Object>;<br>Differences: extraInfos?: Record\<string, Object>;|api/wantAgent/triggerInfo.d.ts|
|API added|NA|Class name: WantAgentInfo;<br>API declaration: extraInfos?: Record\<string, Object>;<br>Differences: extraInfos?: Record\<string, Object>;|api/wantAgent/wantAgentInfo.d.ts|
|API deleted|Class name: common;<br>API declaration: export type ServiceExtensionContext = _ServiceExtensionContext.default;<br>Differences: export type ServiceExtensionContext = _ServiceExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|API deleted|Class name: common;<br>API declaration: export type AutoFillExtensionContext = _AutoFillExtensionContext.default;<br>Differences: export type AutoFillExtensionContext = _AutoFillExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;<br>Differences: on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;<br>Differences: off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;<br>Differences: setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: setAutoStartup(info: AutoStartupInfo): Promise\<void>;<br>Differences: setAutoStartup(info: AutoStartupInfo): Promise\<void>;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;<br>Differences: cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: cancelAutoStartup(info: AutoStartupInfo): Promise\<void>;<br>Differences: cancelAutoStartup(info: AutoStartupInfo): Promise\<void>;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<boolean>): void;<br>Differences: isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<boolean>): void;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: ApplicationContext;<br>API declaration: isAutoStartup(info: AutoStartupInfo): Promise\<boolean>;<br>Differences: isAutoStartup(info: AutoStartupInfo): Promise\<boolean>;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: global;<br>API declaration: export type AutoStartupInfo = _AutoStartupInfo;<br>Differences: export type AutoStartupInfo = _AutoStartupInfo;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: global;<br>API declaration: export type AutoStartupCallback = _AutoStartupCallback;<br>Differences: export type AutoStartupCallback = _AutoStartupCallback;|NA|api/application/ApplicationContext.d.ts|
|API deleted|Class name: global;<br>API declaration:  export interface AutoStartupCallback<br>Differences:  export interface AutoStartupCallback|NA|api/application/AutoStartupCallback.d.ts|
|API deleted|Class name: AutoStartupCallback;<br>API declaration: onAutoStartupOn(info: AutoStartupInfo): void;<br>Differences: onAutoStartupOn(info: AutoStartupInfo): void;|NA|api/application/AutoStartupCallback.d.ts|
|API deleted|Class name: AutoStartupCallback;<br>API declaration: onAutoStartupOff(info: AutoStartupInfo): void;<br>Differences: onAutoStartupOff(info: AutoStartupInfo): void;|NA|api/application/AutoStartupCallback.d.ts|
|API deleted|Class name: global;<br>API declaration:  export interface AutoStartupInfo<br>Differences:  export interface AutoStartupInfo|NA|api/application/AutoStartupInfo.d.ts|
|API deleted|Class name: AutoStartupInfo;<br>API declaration: bundleName: string;<br>Differences: bundleName: string;|NA|api/application/AutoStartupInfo.d.ts|
|API deleted|Class name: AutoStartupInfo;<br>API declaration: moduleName?: string;<br>Differences: moduleName?: string;|NA|api/application/AutoStartupInfo.d.ts|
|API deleted|Class name: AutoStartupInfo;<br>API declaration: abilityName: string;<br>Differences: abilityName: string;|NA|api/application/AutoStartupInfo.d.ts|
|API deleted|Class name: AutoStartupInfo;<br>API declaration: abilityTypeName?: string;<br>Differences: abilityTypeName?: string;|NA|api/application/AutoStartupInfo.d.ts|
|Initial version changed|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: NA|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: 10|api/@ohos.net.vpn.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.ability.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.dataUriUtils.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.errorCode.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.featureAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.particleAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.ability.wantConstant.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.Ability.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityConstant.d.ts|
|Kit changed|Test Kit|TestKit|api/@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityStage.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ActionExtensionAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ApplicationStateChangeCallback.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.appManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.appRecovery.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.autoFillManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ChildProcess.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.childProcessManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.common.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.Configuration.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ConfigurationConstant.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.contextConstant.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.dataUriUtils.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.dialogRequest.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.EnvironmentCallback.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.errorManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ExtensionAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.insightIntent.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.InsightIntentContext.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.ShareExtensionAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.StartOptions.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.UIAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.UIExtensionAbility.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.Want.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.wantAgent.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.app.ability.wantConstant.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.app.form.formBindingData.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.app.form.FormExtensionAbility.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.app.form.formInfo.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.app.form.formProvider.d.ts|
|Kit changed|Test Kit|TestKit|api/@ohos.application.abilityDelegatorRegistry.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.application.appManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.application.Configuration.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.application.ConfigurationConstant.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.application.formBindingData.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.application.formError.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.application.formInfo.d.ts|
|Kit changed|Form Kit|FormKit|api/@ohos.application.formProvider.d.ts|
|Kit changed|Test Kit|TestKit|api/@ohos.application.testRunner.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.application.uriPermissionManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.application.Want.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.continuation.continuationManager.d.ts|
|Kit changed|Ability Kit|AbilityKit|api/@ohos.wantAgent.d.ts|
|Kit changed|Connectivity Kit|ConnectivityKit|api/@ohos.wifiManagerExt.d.ts|
