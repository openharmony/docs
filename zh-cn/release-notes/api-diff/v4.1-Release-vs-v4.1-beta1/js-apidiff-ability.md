| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：NA|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：SystemCapability.Ability.AbilityRuntime.Core|api/@ohos.net.vpn.d.ts|
|权限变更|类名：UIAbilityContext；<br>API声明：startAbilityByCall(want: Want): Promise\<Caller>;<br>差异内容：NA|类名：UIAbilityContext；<br>API声明：startAbilityByCall(want: Want): Promise\<Caller>;<br>差异内容：ohos.permission.DISTRIBUTED_DATASYNC|api/application/UIAbilityContext.d.ts|
|函数变更|类名：LifecycleForm；<br>API声明：onVisibilityChange?(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>差异内容：newStatus: {<br>        [key: string]: number;<br>    }|类名：LifecycleForm；<br>API声明：onVisibilityChange?(newStatus: Record\<string, number>): void;<br>差异内容：newStatus: Record\<string, number>|api/@internal/full/lifecycle.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onContinue(wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnContinueResult;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onContinue(wantParam: Record\<string, Object>): AbilityConstant.OnContinueResult;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onSaveState(reason: AbilityConstant.StateType, wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnSaveResult;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onSaveState(reason: AbilityConstant.StateType, wantParam: Record\<string, Object>): AbilityConstant.OnSaveResult;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onShare(wantParam: {<br>        [key: string]: Object;<br>    }): void;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onShare(wantParam: Record\<string, Object>): void;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：FormExtensionAbility；<br>API声明：onChangeFormVisibility(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>差异内容：newStatus: {<br>        [key: string]: number;<br>    }|类名：FormExtensionAbility；<br>API声明：onChangeFormVisibility(newStatus: Record\<string, number>): void;<br>差异内容：newStatus: Record\<string, number>|api/@ohos.app.form.FormExtensionAbility.d.ts|
|函数变更|类名：AbilityDelegator；<br>API声明：setMockList(mockList: {<br>        [key: string]: string;<br>    }): void;<br>差异内容：mockList: {<br>        [key: string]: string;<br>    }|类名：AbilityDelegator；<br>API声明：setMockList(mockList: Record\<string, string>): void;<br>差异内容：mockList: Record\<string, string>|api/application/AbilityDelegator.d.ts|
|属性变更|类名：Want；<br>API声明：parameters?: {<br>        [key: string]: Object;<br>    };<br>差异内容：{<br>        [key: string]: Object;<br>    }|类名：Want；<br>API声明：parameters?: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/@ohos.app.ability.Want.d.ts|
|属性变更|类名：CompleteData；<br>API声明：extraInfo?: {<br>            [key: string]: Object;<br>        };<br>差异内容：{<br>            [key: string]: Object;<br>        }|类名：CompleteData；<br>API声明：extraInfo?: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/@ohos.app.ability.wantAgent.d.ts|
|属性变更|类名：FormInfo；<br>API声明：customizeData: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        };<br>差异内容：{<br>            [key: string]: [<br>                value: string<br>            ];<br>        }|类名：FormInfo；<br>API声明：customizeData: Record\<string, string>;<br>差异内容：Record\<string, string>|api/@ohos.app.form.formInfo.d.ts|
|属性变更|类名：AbilityDelegatorArgs；<br>API声明：parameters: {<br>        [key: string]: string;<br>    };<br>差异内容：{<br>        [key: string]: string;<br>    }|类名：AbilityDelegatorArgs；<br>API声明：parameters: Record\<string, string>;<br>差异内容：Record\<string, string>|api/application/abilityDelegatorArgs.d.ts|
|新增API|NA|类名：common；<br>API声明：export type VpnExtensionContext = _VpnExtensionContext.default;<br>差异内容：export type VpnExtensionContext = _VpnExtensionContext.default;|api/@ohos.app.ability.common.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class VpnExtensionAbility<br>差异内容： export default class VpnExtensionAbility|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：context: VpnExtensionContext;<br>差异内容：context: VpnExtensionContext;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：onCreate(want: Want): void;<br>差异内容：onCreate(want: Want): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：onDestroy(): void;<br>差异内容：onDestroy(): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：FormInfo；<br>API声明：displayName: string;<br>差异内容：displayName: string;|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：FormInfo；<br>API声明：displayNameId: number;<br>差异内容：displayNameId: number;|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：export type VpnExtensionContext = _VpnExtensionContext;<br>差异内容：export type VpnExtensionContext = _VpnExtensionContext;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：function startVpnExtensionAbility(want: Want): Promise\<void>;<br>差异内容：function startVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：function stopVpnExtensionAbility(want: Want): Promise\<void>;<br>差异内容：function stopVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：StartAbilityParameter；<br>API声明：abilityStartSettings?: Record\<string, Object>;<br>差异内容：abilityStartSettings?: Record\<string, Object>;|api/ability/startAbilityParameter.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class VpnExtensionContext<br>差异内容： export default class VpnExtensionContext|api/application/VpnExtensionContext.d.ts|
|新增API|NA|类名：TriggerInfo；<br>API声明：extraInfos?: Record\<string, Object>;<br>差异内容：extraInfos?: Record\<string, Object>;|api/wantAgent/triggerInfo.d.ts|
|新增API|NA|类名：WantAgentInfo；<br>API声明：extraInfos?: Record\<string, Object>;<br>差异内容：extraInfos?: Record\<string, Object>;|api/wantAgent/wantAgentInfo.d.ts|
|删除API|类名：common；<br>API声明：export type ServiceExtensionContext = _ServiceExtensionContext.default;<br>差异内容：export type ServiceExtensionContext = _ServiceExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|删除API|类名：common；<br>API声明：export type AutoFillExtensionContext = _AutoFillExtensionContext.default;<br>差异内容：export type AutoFillExtensionContext = _AutoFillExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;<br>差异内容：on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;<br>差异内容：off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;<br>差异内容：setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：setAutoStartup(info: AutoStartupInfo): Promise\<void>;<br>差异内容：setAutoStartup(info: AutoStartupInfo): Promise\<void>;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;<br>差异内容：cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void>): void;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：cancelAutoStartup(info: AutoStartupInfo): Promise\<void>;<br>差异内容：cancelAutoStartup(info: AutoStartupInfo): Promise\<void>;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<boolean>): void;<br>差异内容：isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<boolean>): void;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：ApplicationContext；<br>API声明：isAutoStartup(info: AutoStartupInfo): Promise\<boolean>;<br>差异内容：isAutoStartup(info: AutoStartupInfo): Promise\<boolean>;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：global；<br>API声明：export type AutoStartupInfo = _AutoStartupInfo;<br>差异内容：export type AutoStartupInfo = _AutoStartupInfo;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：global；<br>API声明：export type AutoStartupCallback = _AutoStartupCallback;<br>差异内容：export type AutoStartupCallback = _AutoStartupCallback;|NA|api/application/ApplicationContext.d.ts|
|删除API|类名：global；<br>API声明： export interface AutoStartupCallback<br>差异内容： export interface AutoStartupCallback|NA|api/application/AutoStartupCallback.d.ts|
|删除API|类名：AutoStartupCallback；<br>API声明：onAutoStartupOn(info: AutoStartupInfo): void;<br>差异内容：onAutoStartupOn(info: AutoStartupInfo): void;|NA|api/application/AutoStartupCallback.d.ts|
|删除API|类名：AutoStartupCallback；<br>API声明：onAutoStartupOff(info: AutoStartupInfo): void;<br>差异内容：onAutoStartupOff(info: AutoStartupInfo): void;|NA|api/application/AutoStartupCallback.d.ts|
|删除API|类名：global；<br>API声明： export interface AutoStartupInfo<br>差异内容： export interface AutoStartupInfo|NA|api/application/AutoStartupInfo.d.ts|
|删除API|类名：AutoStartupInfo；<br>API声明：bundleName: string;<br>差异内容：bundleName: string;|NA|api/application/AutoStartupInfo.d.ts|
|删除API|类名：AutoStartupInfo；<br>API声明：moduleName?: string;<br>差异内容：moduleName?: string;|NA|api/application/AutoStartupInfo.d.ts|
|删除API|类名：AutoStartupInfo；<br>API声明：abilityName: string;<br>差异内容：abilityName: string;|NA|api/application/AutoStartupInfo.d.ts|
|删除API|类名：AutoStartupInfo；<br>API声明：abilityTypeName?: string;<br>差异内容：abilityTypeName?: string;|NA|api/application/AutoStartupInfo.d.ts|
|起始版本有变化|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：NA|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：10|api/@ohos.net.vpn.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.ability.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.dataUriUtils.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.errorCode.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.featureAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.particleAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.ability.wantConstant.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.Ability.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityConstant.d.ts|
|kit变更|Test Kit|TestKit|api/@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.AbilityStage.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ActionExtensionAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ApplicationStateChangeCallback.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.appManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.appRecovery.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.autoFillManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ChildProcess.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.childProcessManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.common.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.Configuration.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ConfigurationConstant.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.contextConstant.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.dataUriUtils.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.dialogRequest.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.EnvironmentCallback.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.errorManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ExtensionAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.insightIntent.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.InsightIntentContext.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.ShareExtensionAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.StartOptions.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.UIAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.UIExtensionAbility.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.Want.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.wantAgent.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.app.ability.wantConstant.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.app.form.formBindingData.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.app.form.FormExtensionAbility.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.app.form.formInfo.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.app.form.formProvider.d.ts|
|kit变更|Test Kit|TestKit|api/@ohos.application.abilityDelegatorRegistry.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.application.appManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.application.Configuration.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.application.ConfigurationConstant.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.application.formBindingData.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.application.formError.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.application.formInfo.d.ts|
|kit变更|Form Kit|FormKit|api/@ohos.application.formProvider.d.ts|
|kit变更|Test Kit|TestKit|api/@ohos.application.testRunner.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.application.uriPermissionManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.application.Want.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.continuation.continuationManager.d.ts|
|kit变更|Ability Kit|AbilityKit|api/@ohos.wantAgent.d.ts|
|kit变更|Connectivity Kit|ConnectivityKit|api/@ohos.wifiManagerExt.d.ts|
