| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|API model changed|Class name: global;<br>API declaration: declare namespace common<br>Differences: StageModelOnly|Class name: global;<br>API declaration: declare namespace common<br>Differences: NA|api/@ohos.app.ability.common.d.ts|
|API model changed|Class name: common;<br>API declaration: export type PacMap = _PacMap;<br>Differences: StageModelOnly|Class name: common;<br>API declaration: export type PacMap = _PacMap;<br>Differences: NA|api/@ohos.app.ability.common.d.ts|
|API model changed|Class name: global;<br>API declaration: declare namespace ability<br>Differences: FAModelOnly|Class name: global;<br>API declaration: declare namespace ability<br>Differences: NA|api/@ohos.ability.ability.d.ts|
|API model changed|Class name: ability;<br>API declaration: export type PacMap = _PacMap;<br>Differences: FAModelOnly|Class name: ability;<br>API declaration: export type PacMap = _PacMap;<br>Differences: NA|api/@ohos.ability.ability.d.ts|
|API model changed|Class name: global;<br>API declaration: export interface PacMap<br>Differences: FAModelOnly|Class name: global;<br>API declaration: export interface PacMap<br>Differences: NA|api/ability/dataAbilityHelper.d.ts|
|SysCap changed|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: NA|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: SystemCapability.Ability.AbilityRuntime.Core|api/@ohos.net.vpn.d.ts|
|Deprecated version changed|Class name: WantAgentInfo;<br>API declaration: operationType: wantAgent.OperationType;<br>Differences: NA|Class name: WantAgentInfo;<br>API declaration: operationType?: wantAgent.OperationType;<br>Differences: 11|api/wantAgent/wantAgentInfo.d.ts|
|Deprecated version changed|Class name: WantAgentInfo;<br>API declaration: wantAgentFlags?: Array\<wantAgent.WantAgentFlags>;<br>Differences: NA|Class name: WantAgentInfo;<br>API declaration: wantAgentFlags?: Array\<wantAgent.WantAgentFlags>;<br>Differences: 11|api/wantAgent/wantAgentInfo.d.ts|
|Permission changed|Class name: appManager;<br>API declaration: function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;<br>Differences: ohos.permission.GET_RUNNING_INFO|Class name: appManager;<br>API declaration: function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;<br>Differences: NA|api/@ohos.app.ability.appManager.d.ts|
|Permission changed|Class name: appManager;<br>API declaration: function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;<br>Differences: ohos.permission.GET_RUNNING_INFO|Class name: appManager;<br>API declaration: function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;<br>Differences: NA|api/@ohos.app.ability.appManager.d.ts|
|Permission changed|Class name: UIAbilityContext;<br>API declaration: startAbilityByCall(want: Want): Promise\<Caller>;<br>Differences: ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|Class name: UIAbilityContext;<br>API declaration: startAbilityByCall(want: Want): Promise\<Caller>;<br>Differences: ohos.permission.DISTRIBUTED_DATASYNC|api/application/UIAbilityContext.d.ts|
|Function changed|Class name: LifecycleForm;<br>API declaration: onVisibilityChange?(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>Differences: newStatus: {<br>        [key: string]: number;<br>    }|Class name: LifecycleForm;<br>API declaration: onVisibilityChange?(newStatus: Record\<string, number>): void;<br>Differences: newStatus: Record\<string, number>|api/@internal/full/lifecycle.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onContinue(wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnContinueResult;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onContinue(wantParam: Record\<string, Object>): AbilityConstant.OnContinueResult;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onSaveState(reason: AbilityConstant.StateType, wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnSaveResult;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onSaveState(reason: AbilityConstant.StateType, wantParam: Record\<string, Object>): AbilityConstant.OnSaveResult;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: UIAbility;<br>API declaration: onShare(wantParam: {<br>        [key: string]: Object;<br>    }): void;<br>Differences: wantParam: {<br>        [key: string]: Object;<br>    }|Class name: UIAbility;<br>API declaration: onShare(wantParam: Record\<string, Object>): void;<br>Differences: wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|Function changed|Class name: FormExtensionAbility;<br>API declaration: onChangeFormVisibility(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>Differences: newStatus: {<br>        [key: string]: number;<br>    }|Class name: FormExtensionAbility;<br>API declaration: onChangeFormVisibility(newStatus: Record\<string, number>): void;<br>Differences: newStatus: Record\<string, number>|api/@ohos.app.form.FormExtensionAbility.d.ts|
|Attribute changed|Class name: WantAgentInfo;<br>API declaration: operationType: wantAgent.OperationType;<br>Differences: operationType: wantAgent.OperationType;|Class name: WantAgentInfo;<br>API declaration: operationType?: wantAgent.OperationType;<br>Differences: operationType?: wantAgent.OperationType;|api/wantAgent/wantAgentInfo.d.ts|
|Attribute changed|Class name: Want;<br>API declaration: parameters?: {<br>        [key: string]: Object;<br>    };<br>Differences: {<br>        [key: string]: Object;<br>    }|Class name: Want;<br>API declaration: parameters?: Record\<string, Object>;<br>Differences: Record\<string, Object>|api/@ohos.app.ability.Want.d.ts|
|Attribute changed|Class name: CompleteData;<br>API declaration: extraInfo?: {<br>            [key: string]: Object;<br>        };<br>Differences: {<br>            [key: string]: Object;<br>        }|Class name: CompleteData;<br>API declaration: extraInfo?: Record\<string, Object>;<br>Differences: Record\<string, Object>|api/@ohos.app.ability.wantAgent.d.ts|
|Attribute changed|Class name: FormInfo;<br>API declaration: customizeData: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        };<br>Differences: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        }|Class name: FormInfo;<br>API declaration: customizeData: Record\<string, string>;<br>Differences: Record\<string, string>|api/@ohos.app.form.formInfo.d.ts|
|Attribute changed|Class name: AbilityDelegatorArgs;<br>API declaration: parameters: {<br>        [key: string]: string;<br>    };<br>Differences: {<br>        [key: string]: string;<br>    }|Class name: AbilityDelegatorArgs;<br>API declaration: parameters: Record\<string, string>;<br>Differences: Record\<string, string>|api/application/abilityDelegatorArgs.d.ts|
|Attribute changed|Class name: ContinuationExtraParams;<br>API declaration: authInfo?: {<br>        [key: string]: any;<br>    };<br>Differences: {<br>        [key: string]: any;<br>    }|Class name: ContinuationExtraParams;<br>API declaration: authInfo?: Record\<string, Object>;<br>Differences: Record\<string, Object>|api/continuation/continuationExtraParams.d.ts|
|API added|NA|Class name: LaunchReason;<br>API declaration: AUTO_STARTUP = 8<br>Differences: AUTO_STARTUP = 8|api/@ohos.app.ability.AbilityConstant.d.ts|
|API added|NA|Class name: LaunchReason;<br>API declaration: INSIGHT_INTENT = 9<br>Differences: INSIGHT_INTENT = 9|api/@ohos.app.ability.AbilityConstant.d.ts|
|API added|NA|Class name: AbilityStage;<br>API declaration: onNewProcessRequest(want: Want): string;<br>Differences: onNewProcessRequest(want: Want): string;|api/@ohos.app.ability.AbilityStage.d.ts|
|API added|NA|Class name: global;<br>API declaration: declare namespace autoFillManager<br>Differences:  declare namespace autoFillManager|api/@ohos.app.ability.autoFillManager.d.ts|
|API added|NA|Class name: autoFillManager;<br>API declaration: export interface AutoSaveCallback<br>Differences:  export interface AutoSaveCallback|api/@ohos.app.ability.autoFillManager.d.ts|
|API added|NA|Class name: AutoSaveCallback;<br>API declaration: onSuccess(): void;<br>Differences: onSuccess(): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|API added|NA|Class name: AutoSaveCallback;<br>API declaration: onFailure(): void;<br>Differences: onFailure(): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|API added|NA|Class name: autoFillManager;<br>API declaration: export function requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void;<br>Differences: export function requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class ChildProcess<br>Differences:  export default class ChildProcess|api/@ohos.app.ability.ChildProcess.d.ts|
|API added|NA|Class name: ChildProcess;<br>API declaration: onStart(): void;<br>Differences: onStart(): void;|api/@ohos.app.ability.ChildProcess.d.ts|
|API added|NA|Class name: global;<br>API declaration: declare namespace childProcessManager<br>Differences:  declare namespace childProcessManager|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: childProcessManager;<br>API declaration: export const enum StartMode<br>Differences:  export const enum StartMode|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: StartMode;<br>API declaration: SELF_FORK = 0<br>Differences: SELF_FORK = 0|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: StartMode;<br>API declaration: APP_SPAWN_FORK = 1<br>Differences: APP_SPAWN_FORK = 1|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: childProcessManager;<br>API declaration: function startChildProcess(srcEntry: string, startMode: StartMode): Promise\<number>;<br>Differences: function startChildProcess(srcEntry: string, startMode: StartMode): Promise\<number>;|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: childProcessManager;<br>API declaration: function startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback\<number>): void;<br>Differences: function startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback\<number>): void;|api/@ohos.app.ability.childProcessManager.d.ts|
|API added|NA|Class name: common;<br>API declaration: export type AbilityStartCallback = _AbilityStartCallback;<br>Differences: export type AbilityStartCallback = _AbilityStartCallback;|api/@ohos.app.ability.common.d.ts|
|API added|NA|Class name: common;<br>API declaration: export type VpnExtensionContext = _VpnExtensionContext.default;<br>Differences: export type VpnExtensionContext = _VpnExtensionContext.default;|api/@ohos.app.ability.common.d.ts|
|API added|NA|Class name: AreaMode;<br>API declaration: EL3 = 2<br>Differences: EL3 = 2|api/@ohos.app.ability.contextConstant.d.ts|
|API added|NA|Class name: AreaMode;<br>API declaration: EL4 = 3<br>Differences: EL4 = 3|api/@ohos.app.ability.contextConstant.d.ts|
|API added|NA|Class name: global;<br>API declaration: declare namespace insightIntent<br>Differences:  declare namespace insightIntent|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: insightIntent;<br>API declaration: enum ExecuteMode<br>Differences:  enum ExecuteMode|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: ExecuteMode;<br>API declaration: UI_ABILITY_FOREGROUND = 0<br>Differences: UI_ABILITY_FOREGROUND = 0|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: ExecuteMode;<br>API declaration: UI_ABILITY_BACKGROUND = 1<br>Differences: UI_ABILITY_BACKGROUND = 1|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: ExecuteMode;<br>API declaration: UI_EXTENSION_ABILITY = 2<br>Differences: UI_EXTENSION_ABILITY = 2|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: insightIntent;<br>API declaration: interface ExecuteResult<br>Differences:  interface ExecuteResult|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: ExecuteResult;<br>API declaration: code: number;<br>Differences: code: number;|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: ExecuteResult;<br>API declaration: result?: Record\<string, Object>;<br>Differences: result?: Record\<string, Object>;|api/@ohos.app.ability.insightIntent.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class InsightIntentContext<br>Differences:  export default class InsightIntentContext|api/@ohos.app.ability.InsightIntentContext.d.ts|
|API added|NA|Class name: InsightIntentContext;<br>API declaration: startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>Differences: startAbility(want: Want, callback: AsyncCallback\<void>): void;|api/@ohos.app.ability.InsightIntentContext.d.ts|
|API added|NA|Class name: InsightIntentContext;<br>API declaration: startAbility(want: Want): Promise\<void>;<br>Differences: startAbility(want: Want): Promise\<void>;|api/@ohos.app.ability.InsightIntentContext.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class InsightIntentExecutor<br>Differences:  export default class InsightIntentExecutor|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: InsightIntentExecutor;<br>API declaration: context: InsightIntentContext;<br>Differences: context: InsightIntentContext;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: InsightIntentExecutor;<br>API declaration: onExecuteInUIAbilityForegroundMode(name: string, param: Record\<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>Differences: onExecuteInUIAbilityForegroundMode(name: string, param: Record\<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: InsightIntentExecutor;<br>API declaration: onExecuteInUIAbilityBackgroundMode(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>Differences: onExecuteInUIAbilityBackgroundMode(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: InsightIntentExecutor;<br>API declaration: onExecuteInUIExtensionAbility(name: string, param: Record\<string, Object>, pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>Differences: onExecuteInUIExtensionAbility(name: string, param: Record\<string, Object>, pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: InsightIntentExecutor;<br>API declaration: onExecuteInServiceExtensionAbility(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>Differences: onExecuteInServiceExtensionAbility(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|API added|NA|Class name: StartOptions;<br>API declaration: withAnimation?: boolean;<br>Differences: withAnimation?: boolean;|api/@ohos.app.ability.StartOptions.d.ts|
|API added|NA|Class name: StartOptions;<br>API declaration: windowLeft?: number;<br>Differences: windowLeft?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|API added|NA|Class name: StartOptions;<br>API declaration: windowTop?: number;<br>Differences: windowTop?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|API added|NA|Class name: StartOptions;<br>API declaration: windowWidth?: number;<br>Differences: windowWidth?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|API added|NA|Class name: StartOptions;<br>API declaration: windowHeight?: number;<br>Differences: windowHeight?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|API added|NA|Class name: UIExtensionContentSession;<br>API declaration: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;<br>Differences: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|API added|NA|Class name: UIExtensionContentSession;<br>API declaration: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;<br>Differences: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class VpnExtensionAbility<br>Differences:  export default class VpnExtensionAbility|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: context: VpnExtensionContext;<br>Differences: context: VpnExtensionContext;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: onCreate(want: Want): void;<br>Differences: onCreate(want: Want): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: VpnExtensionAbility;<br>API declaration: onDestroy(): void;<br>Differences: onDestroy(): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|API added|NA|Class name: Flags;<br>API declaration: FLAG_START_WITHOUT_TIPS = 0x40000000<br>Differences: FLAG_START_WITHOUT_TIPS = 0x40000000|api/@ohos.app.ability.wantConstant.d.ts|
|API added|NA|Class name: FormInfo;<br>API declaration: displayName: string;<br>Differences: displayName: string;|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: FormInfo;<br>API declaration: displayNameId: number;<br>Differences: displayNameId: number;|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: FormInfo;<br>API declaration: transparencyEnabled: boolean;<br>Differences: transparencyEnabled: boolean;|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: FormParam;<br>API declaration: FORM_RENDERING_MODE_KEY = 'ohos.extra.param.key.form_rendering_mode'<br>Differences: FORM_RENDERING_MODE_KEY = 'ohos.extra.param.key.form_rendering_mode'|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: FormDimension;<br>API declaration: DIMENSION_1_1<br>Differences: DIMENSION_1_1|api/@ohos.app.form.formInfo.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: export type VpnExtensionContext = _VpnExtensionContext;<br>Differences: export type VpnExtensionContext = _VpnExtensionContext;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: function startVpnExtensionAbility(want: Want): Promise\<void>;<br>Differences: function startVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: vpnExtension;<br>API declaration: function stopVpnExtensionAbility(want: Want): Promise\<void>;<br>Differences: function stopVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|API added|NA|Class name: StartAbilityParameter;<br>API declaration: abilityStartSettings?: Record\<string, Object>;<br>Differences: abilityStartSettings?: Record\<string, Object>;|api/ability/startAbilityParameter.d.ts|
|API added|NA|Class name: AbilityDelegator;<br>API declaration: setMockList(mockList: Record\<string, string>): void;<br>Differences: setMockList(mockList: Record\<string, string>): void;|api/application/AbilityDelegator.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class AbilityStartCallback<br>Differences:  export default class AbilityStartCallback|api/application/AbilityStartCallback.d.ts|
|API added|NA|Class name: AbilityStartCallback;<br>API declaration: onError(code: number, name: string, message: string): void;<br>Differences: onError(code: number, name: string, message: string): void;|api/application/AbilityStartCallback.d.ts|
|API added|NA|Class name: ApplicationContext;<br>API declaration: setColorMode(colorMode: ConfigurationConstant.ColorMode): void;<br>Differences: setColorMode(colorMode: ConfigurationConstant.ColorMode): void;|api/application/ApplicationContext.d.ts|
|API added|NA|Class name: ApplicationContext;<br>API declaration: setLanguage(language: string): void;<br>Differences: setLanguage(language: string): void;|api/application/ApplicationContext.d.ts|
|API added|NA|Class name: ApplicationContext;<br>API declaration: clearUpApplicationData(): Promise\<void>;<br>Differences: clearUpApplicationData(): Promise\<void>;|api/application/ApplicationContext.d.ts|
|API added|NA|Class name: ApplicationContext;<br>API declaration: clearUpApplicationData(callback: AsyncCallback\<void>): void;<br>Differences: clearUpApplicationData(callback: AsyncCallback\<void>): void;|api/application/ApplicationContext.d.ts|
|API added|NA|Class name: Context;<br>API declaration: resourceDir: string;<br>Differences: resourceDir: string;|api/application/Context.d.ts|
|API added|NA|Class name: UIAbilityContext;<br>API declaration: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;<br>Differences: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;|api/application/UIAbilityContext.d.ts|
|API added|NA|Class name: UIAbilityContext;<br>API declaration: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;<br>Differences: startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;|api/application/UIAbilityContext.d.ts|
|API added|NA|Class name: global;<br>API declaration: export default class VpnExtensionContext<br>Differences:  export default class VpnExtensionContext|api/application/VpnExtensionContext.d.ts|
|API added|NA|Class name: TriggerInfo;<br>API declaration: extraInfos?: Record\<string, Object>;<br>Differences: extraInfos?: Record\<string, Object>;|api/wantAgent/triggerInfo.d.ts|
|API added|NA|Class name: WantAgentInfo;<br>API declaration: actionType?: abilityWantAgent.OperationType;<br>Differences: actionType?: abilityWantAgent.OperationType;|api/wantAgent/wantAgentInfo.d.ts|
|API added|NA|Class name: WantAgentInfo;<br>API declaration: actionFlags?: Array\<abilityWantAgent.WantAgentFlags>;<br>Differences: actionFlags?: Array\<abilityWantAgent.WantAgentFlags>;|api/wantAgent/wantAgentInfo.d.ts|
|API added|NA|Class name: WantAgentInfo;<br>API declaration: extraInfos?: Record\<string, Object>;<br>Differences: extraInfos?: Record\<string, Object>;|api/wantAgent/wantAgentInfo.d.ts|
|API deleted|Class name: common;<br>API declaration: export type ServiceExtensionContext = _ServiceExtensionContext.default;<br>Differences: export type ServiceExtensionContext = _ServiceExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|Initial version changed|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: NA|Class name: vpn;<br>API declaration: export type AbilityContext = _AbilityContext;<br>Differences: 10|api/@ohos.net.vpn.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.ability.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.dataUriUtils.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.errorCode.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.featureAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.particleAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.ability.wantConstant.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.Ability.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.AbilityConstant.d.ts|
|Kit changed|NA|TestKit|api/@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.AbilityStage.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.ActionExtensionAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.ApplicationStateChangeCallback.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.appManager.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.appRecovery.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.common.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.Configuration.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.ConfigurationConstant.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.contextConstant.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.dataUriUtils.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.dialogRequest.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.EnvironmentCallback.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.errorManager.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.ExtensionAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.ShareExtensionAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.StartOptions.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.UIAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.UIExtensionAbility.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.Want.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.wantAgent.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.app.ability.wantConstant.d.ts|
|Kit changed|NA|FormKit|api/@ohos.app.form.formBindingData.d.ts|
|Kit changed|NA|FormKit|api/@ohos.app.form.FormExtensionAbility.d.ts|
|Kit changed|NA|FormKit|api/@ohos.app.form.formInfo.d.ts|
|Kit changed|NA|FormKit|api/@ohos.app.form.formProvider.d.ts|
|Kit changed|NA|TestKit|api/@ohos.application.abilityDelegatorRegistry.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.application.appManager.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.application.Configuration.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.application.ConfigurationConstant.d.ts|
|Kit changed|NA|FormKit|api/@ohos.application.formBindingData.d.ts|
|Kit changed|NA|FormKit|api/@ohos.application.formError.d.ts|
|Kit changed|NA|FormKit|api/@ohos.application.formInfo.d.ts|
|Kit changed|NA|FormKit|api/@ohos.application.formProvider.d.ts|
|Kit changed|NA|TestKit|api/@ohos.application.testRunner.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.application.uriPermissionManager.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.application.Want.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.continuation.continuationManager.d.ts|
|Kit changed|NA|AbilityKit|api/@ohos.wantAgent.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.wifiManagerExt.d.ts|
