| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API模型切换|类名：global；<br>API声明： declare namespace common<br>差异内容：StageModelOnly|类名：global；<br>API声明： declare namespace common<br>差异内容：NA|api/@ohos.app.ability.common.d.ts|
|API模型切换|类名：common；<br>API声明：export type PacMap = _PacMap;<br>差异内容：StageModelOnly|类名：common；<br>API声明：export type PacMap = _PacMap;<br>差异内容：NA|api/@ohos.app.ability.common.d.ts|
|API模型切换|类名：global；<br>API声明： declare namespace ability<br>差异内容：FAModelOnly|类名：global；<br>API声明： declare namespace ability<br>差异内容：NA|api/@ohos.ability.ability.d.ts|
|API模型切换|类名：ability；<br>API声明：export type PacMap = _PacMap;<br>差异内容：FAModelOnly|类名：ability；<br>API声明：export type PacMap = _PacMap;<br>差异内容：NA|api/@ohos.ability.ability.d.ts|
|API模型切换|类名：global；<br>API声明： export interface PacMap<br>差异内容：FAModelOnly|类名：global；<br>API声明： export interface PacMap<br>差异内容：NA|api/ability/dataAbilityHelper.d.ts|
|syscap变更|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：NA|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：SystemCapability.Ability.AbilityRuntime.Core|api/@ohos.net.vpn.d.ts|
|API废弃版本变更|类名：WantAgentInfo；<br>API声明：operationType: wantAgent.OperationType;<br>差异内容：NA|类名：WantAgentInfo；<br>API声明：operationType?: wantAgent.OperationType;<br>差异内容：11|api/wantAgent/wantAgentInfo.d.ts|
|API废弃版本变更|类名：WantAgentInfo；<br>API声明：wantAgentFlags?: Array\<wantAgent.WantAgentFlags>;<br>差异内容：NA|类名：WantAgentInfo；<br>API声明：wantAgentFlags?: Array\<wantAgent.WantAgentFlags>;<br>差异内容：11|api/wantAgent/wantAgentInfo.d.ts|
|权限变更|类名：appManager；<br>API声明：function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;<br>差异内容：ohos.permission.GET_RUNNING_INFO|类名：appManager；<br>API声明：function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;<br>差异内容：NA|api/@ohos.app.ability.appManager.d.ts|
|权限变更|类名：appManager；<br>API声明：function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;<br>差异内容：ohos.permission.GET_RUNNING_INFO|类名：appManager；<br>API声明：function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;<br>差异内容：NA|api/@ohos.app.ability.appManager.d.ts|
|权限变更|类名：UIAbilityContext；<br>API声明：startAbilityByCall(want: Want): Promise\<Caller>;<br>差异内容：ohos.permission.ABILITY_BACKGROUND_COMMUNICATION|类名：UIAbilityContext；<br>API声明：startAbilityByCall(want: Want): Promise\<Caller>;<br>差异内容：ohos.permission.DISTRIBUTED_DATASYNC|api/application/UIAbilityContext.d.ts|
|函数变更|类名：LifecycleForm；<br>API声明：onVisibilityChange?(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>差异内容：newStatus: {<br>        [key: string]: number;<br>    }|类名：LifecycleForm；<br>API声明：onVisibilityChange?(newStatus: Record\<string, number>): void;<br>差异内容：newStatus: Record\<string, number>|api/@internal/full/lifecycle.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onContinue(wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnContinueResult;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onContinue(wantParam: Record\<string, Object>): AbilityConstant.OnContinueResult;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onSaveState(reason: AbilityConstant.StateType, wantParam: {<br>        [key: string]: Object;<br>    }): AbilityConstant.OnSaveResult;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onSaveState(reason: AbilityConstant.StateType, wantParam: Record\<string, Object>): AbilityConstant.OnSaveResult;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：UIAbility；<br>API声明：onShare(wantParam: {<br>        [key: string]: Object;<br>    }): void;<br>差异内容：wantParam: {<br>        [key: string]: Object;<br>    }|类名：UIAbility；<br>API声明：onShare(wantParam: Record\<string, Object>): void;<br>差异内容：wantParam: Record\<string, Object>|api/@ohos.app.ability.UIAbility.d.ts|
|函数变更|类名：FormExtensionAbility；<br>API声明：onChangeFormVisibility(newStatus: {<br>        [key: string]: number;<br>    }): void;<br>差异内容：newStatus: {<br>        [key: string]: number;<br>    }|类名：FormExtensionAbility；<br>API声明：onChangeFormVisibility(newStatus: Record\<string, number>): void;<br>差异内容：newStatus: Record\<string, number>|api/@ohos.app.form.FormExtensionAbility.d.ts|
|属性变更|类名：WantAgentInfo；<br>API声明：operationType: wantAgent.OperationType;<br>差异内容：operationType: wantAgent.OperationType;|类名：WantAgentInfo；<br>API声明：operationType?: wantAgent.OperationType;<br>差异内容：operationType?: wantAgent.OperationType;|api/wantAgent/wantAgentInfo.d.ts|
|属性变更|类名：Want；<br>API声明：parameters?: {<br>        [key: string]: Object;<br>    };<br>差异内容：{<br>        [key: string]: Object;<br>    }|类名：Want；<br>API声明：parameters?: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/@ohos.app.ability.Want.d.ts|
|属性变更|类名：CompleteData；<br>API声明：extraInfo?: {<br>            [key: string]: Object;<br>        };<br>差异内容：{<br>            [key: string]: Object;<br>        }|类名：CompleteData；<br>API声明：extraInfo?: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/@ohos.app.ability.wantAgent.d.ts|
|属性变更|类名：FormInfo；<br>API声明：customizeData: {<br>            [key: string]: [<br>                value: string<br>            ];<br>        };<br>差异内容：{<br>            [key: string]: [<br>                value: string<br>            ];<br>        }|类名：FormInfo；<br>API声明：customizeData: Record\<string, string>;<br>差异内容：Record\<string, string>|api/@ohos.app.form.formInfo.d.ts|
|属性变更|类名：AbilityDelegatorArgs；<br>API声明：parameters: {<br>        [key: string]: string;<br>    };<br>差异内容：{<br>        [key: string]: string;<br>    }|类名：AbilityDelegatorArgs；<br>API声明：parameters: Record\<string, string>;<br>差异内容：Record\<string, string>|api/application/abilityDelegatorArgs.d.ts|
|属性变更|类名：ContinuationExtraParams；<br>API声明：authInfo?: {<br>        [key: string]: any;<br>    };<br>差异内容：{<br>        [key: string]: any;<br>    }|类名：ContinuationExtraParams；<br>API声明：authInfo?: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/continuation/continuationExtraParams.d.ts|
|新增API|NA|类名：LaunchReason；<br>API声明：AUTO_STARTUP = 8<br>差异内容：AUTO_STARTUP = 8|api/@ohos.app.ability.AbilityConstant.d.ts|
|新增API|NA|类名：LaunchReason；<br>API声明：INSIGHT_INTENT = 9<br>差异内容：INSIGHT_INTENT = 9|api/@ohos.app.ability.AbilityConstant.d.ts|
|新增API|NA|类名：AbilityStage；<br>API声明：onNewProcessRequest(want: Want): string;<br>差异内容：onNewProcessRequest(want: Want): string;|api/@ohos.app.ability.AbilityStage.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace autoFillManager<br>差异内容： declare namespace autoFillManager|api/@ohos.app.ability.autoFillManager.d.ts|
|新增API|NA|类名：autoFillManager；<br>API声明： export interface AutoSaveCallback<br>差异内容： export interface AutoSaveCallback|api/@ohos.app.ability.autoFillManager.d.ts|
|新增API|NA|类名：AutoSaveCallback；<br>API声明：onSuccess(): void;<br>差异内容：onSuccess(): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|新增API|NA|类名：AutoSaveCallback；<br>API声明：onFailure(): void;<br>差异内容：onFailure(): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|新增API|NA|类名：autoFillManager；<br>API声明：export function requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void;<br>差异内容：export function requestAutoSave(context: UIContext, callback?: AutoSaveCallback): void;|api/@ohos.app.ability.autoFillManager.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class ChildProcess<br>差异内容： export default class ChildProcess|api/@ohos.app.ability.ChildProcess.d.ts|
|新增API|NA|类名：ChildProcess；<br>API声明：onStart(): void;<br>差异内容：onStart(): void;|api/@ohos.app.ability.ChildProcess.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace childProcessManager<br>差异内容： declare namespace childProcessManager|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：childProcessManager；<br>API声明： export const enum StartMode<br>差异内容： export const enum StartMode|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：StartMode；<br>API声明：SELF_FORK = 0<br>差异内容：SELF_FORK = 0|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：StartMode；<br>API声明：APP_SPAWN_FORK = 1<br>差异内容：APP_SPAWN_FORK = 1|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：childProcessManager；<br>API声明：function startChildProcess(srcEntry: string, startMode: StartMode): Promise\<number>;<br>差异内容：function startChildProcess(srcEntry: string, startMode: StartMode): Promise\<number>;|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：childProcessManager；<br>API声明：function startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback\<number>): void;<br>差异内容：function startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback\<number>): void;|api/@ohos.app.ability.childProcessManager.d.ts|
|新增API|NA|类名：common；<br>API声明：export type AbilityStartCallback = _AbilityStartCallback;<br>差异内容：export type AbilityStartCallback = _AbilityStartCallback;|api/@ohos.app.ability.common.d.ts|
|新增API|NA|类名：common；<br>API声明：export type VpnExtensionContext = _VpnExtensionContext.default;<br>差异内容：export type VpnExtensionContext = _VpnExtensionContext.default;|api/@ohos.app.ability.common.d.ts|
|新增API|NA|类名：AreaMode；<br>API声明：EL3 = 2<br>差异内容：EL3 = 2|api/@ohos.app.ability.contextConstant.d.ts|
|新增API|NA|类名：AreaMode；<br>API声明：EL4 = 3<br>差异内容：EL4 = 3|api/@ohos.app.ability.contextConstant.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace insightIntent<br>差异内容： declare namespace insightIntent|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：insightIntent；<br>API声明： enum ExecuteMode<br>差异内容： enum ExecuteMode|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：ExecuteMode；<br>API声明：UI_ABILITY_FOREGROUND = 0<br>差异内容：UI_ABILITY_FOREGROUND = 0|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：ExecuteMode；<br>API声明：UI_ABILITY_BACKGROUND = 1<br>差异内容：UI_ABILITY_BACKGROUND = 1|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：ExecuteMode；<br>API声明：UI_EXTENSION_ABILITY = 2<br>差异内容：UI_EXTENSION_ABILITY = 2|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：insightIntent；<br>API声明： interface ExecuteResult<br>差异内容： interface ExecuteResult|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：ExecuteResult；<br>API声明：code: number;<br>差异内容：code: number;|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：ExecuteResult；<br>API声明：result?: Record\<string, Object>;<br>差异内容：result?: Record\<string, Object>;|api/@ohos.app.ability.insightIntent.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class InsightIntentContext<br>差异内容： export default class InsightIntentContext|api/@ohos.app.ability.InsightIntentContext.d.ts|
|新增API|NA|类名：InsightIntentContext；<br>API声明：startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>差异内容：startAbility(want: Want, callback: AsyncCallback\<void>): void;|api/@ohos.app.ability.InsightIntentContext.d.ts|
|新增API|NA|类名：InsightIntentContext；<br>API声明：startAbility(want: Want): Promise\<void>;<br>差异内容：startAbility(want: Want): Promise\<void>;|api/@ohos.app.ability.InsightIntentContext.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class InsightIntentExecutor<br>差异内容： export default class InsightIntentExecutor|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：InsightIntentExecutor；<br>API声明：context: InsightIntentContext;<br>差异内容：context: InsightIntentContext;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：InsightIntentExecutor；<br>API声明：onExecuteInUIAbilityForegroundMode(name: string, param: Record\<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>差异内容：onExecuteInUIAbilityForegroundMode(name: string, param: Record\<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：InsightIntentExecutor；<br>API声明：onExecuteInUIAbilityBackgroundMode(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>差异内容：onExecuteInUIAbilityBackgroundMode(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：InsightIntentExecutor；<br>API声明：onExecuteInUIExtensionAbility(name: string, param: Record\<string, Object>, pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>差异内容：onExecuteInUIExtensionAbility(name: string, param: Record\<string, Object>, pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：InsightIntentExecutor；<br>API声明：onExecuteInServiceExtensionAbility(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;<br>差异内容：onExecuteInServiceExtensionAbility(name: string, param: Record\<string, Object>): insightIntent.ExecuteResult \| Promise\<insightIntent.ExecuteResult>;|api/@ohos.app.ability.InsightIntentExecutor.d.ts|
|新增API|NA|类名：StartOptions；<br>API声明：withAnimation?: boolean;<br>差异内容：withAnimation?: boolean;|api/@ohos.app.ability.StartOptions.d.ts|
|新增API|NA|类名：StartOptions；<br>API声明：windowLeft?: number;<br>差异内容：windowLeft?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|新增API|NA|类名：StartOptions；<br>API声明：windowTop?: number;<br>差异内容：windowTop?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|新增API|NA|类名：StartOptions；<br>API声明：windowWidth?: number;<br>差异内容：windowWidth?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|新增API|NA|类名：StartOptions；<br>API声明：windowHeight?: number;<br>差异内容：windowHeight?: number;|api/@ohos.app.ability.StartOptions.d.ts|
|新增API|NA|类名：UIExtensionContentSession；<br>API声明：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;<br>差异内容：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增API|NA|类名：UIExtensionContentSession；<br>API声明：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;<br>差异内容：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class VpnExtensionAbility<br>差异内容： export default class VpnExtensionAbility|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：context: VpnExtensionContext;<br>差异内容：context: VpnExtensionContext;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：onCreate(want: Want): void;<br>差异内容：onCreate(want: Want): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：VpnExtensionAbility；<br>API声明：onDestroy(): void;<br>差异内容：onDestroy(): void;|api/@ohos.app.ability.VpnExtensionAbility.d.ts|
|新增API|NA|类名：Flags；<br>API声明：FLAG_START_WITHOUT_TIPS = 0x40000000<br>差异内容：FLAG_START_WITHOUT_TIPS = 0x40000000|api/@ohos.app.ability.wantConstant.d.ts|
|新增API|NA|类名：FormInfo；<br>API声明：displayName: string;<br>差异内容：displayName: string;|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：FormInfo；<br>API声明：displayNameId: number;<br>差异内容：displayNameId: number;|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：FormInfo；<br>API声明：transparencyEnabled: boolean;<br>差异内容：transparencyEnabled: boolean;|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：FormParam；<br>API声明：FORM_RENDERING_MODE_KEY = 'ohos.extra.param.key.form_rendering_mode'<br>差异内容：FORM_RENDERING_MODE_KEY = 'ohos.extra.param.key.form_rendering_mode'|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：FormDimension；<br>API声明：DIMENSION_1_1<br>差异内容：DIMENSION_1_1|api/@ohos.app.form.formInfo.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：export type VpnExtensionContext = _VpnExtensionContext;<br>差异内容：export type VpnExtensionContext = _VpnExtensionContext;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：function startVpnExtensionAbility(want: Want): Promise\<void>;<br>差异内容：function startVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：vpnExtension；<br>API声明：function stopVpnExtensionAbility(want: Want): Promise\<void>;<br>差异内容：function stopVpnExtensionAbility(want: Want): Promise\<void>;|api/@ohos.net.vpnExtension.d.ts|
|新增API|NA|类名：StartAbilityParameter；<br>API声明：abilityStartSettings?: Record\<string, Object>;<br>差异内容：abilityStartSettings?: Record\<string, Object>;|api/ability/startAbilityParameter.d.ts|
|新增API|NA|类名：AbilityDelegator；<br>API声明：setMockList(mockList: Record\<string, string>): void;<br>差异内容：setMockList(mockList: Record\<string, string>): void;|api/application/AbilityDelegator.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class AbilityStartCallback<br>差异内容： export default class AbilityStartCallback|api/application/AbilityStartCallback.d.ts|
|新增API|NA|类名：AbilityStartCallback；<br>API声明：onError(code: number, name: string, message: string): void;<br>差异内容：onError(code: number, name: string, message: string): void;|api/application/AbilityStartCallback.d.ts|
|新增API|NA|类名：ApplicationContext；<br>API声明：setColorMode(colorMode: ConfigurationConstant.ColorMode): void;<br>差异内容：setColorMode(colorMode: ConfigurationConstant.ColorMode): void;|api/application/ApplicationContext.d.ts|
|新增API|NA|类名：ApplicationContext；<br>API声明：setLanguage(language: string): void;<br>差异内容：setLanguage(language: string): void;|api/application/ApplicationContext.d.ts|
|新增API|NA|类名：ApplicationContext；<br>API声明：clearUpApplicationData(): Promise\<void>;<br>差异内容：clearUpApplicationData(): Promise\<void>;|api/application/ApplicationContext.d.ts|
|新增API|NA|类名：ApplicationContext；<br>API声明：clearUpApplicationData(callback: AsyncCallback\<void>): void;<br>差异内容：clearUpApplicationData(callback: AsyncCallback\<void>): void;|api/application/ApplicationContext.d.ts|
|新增API|NA|类名：Context；<br>API声明：resourceDir: string;<br>差异内容：resourceDir: string;|api/application/Context.d.ts|
|新增API|NA|类名：UIAbilityContext；<br>API声明：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;<br>差异内容：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>): void;|api/application/UIAbilityContext.d.ts|
|新增API|NA|类名：UIAbilityContext；<br>API声明：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;<br>差异内容：startAbilityByType(type: string, wantParam: Record\<string, Object>, abilityStartCallback: AbilityStartCallback): Promise\<void>;|api/application/UIAbilityContext.d.ts|
|新增API|NA|类名：global；<br>API声明： export default class VpnExtensionContext<br>差异内容： export default class VpnExtensionContext|api/application/VpnExtensionContext.d.ts|
|新增API|NA|类名：TriggerInfo；<br>API声明：extraInfos?: Record\<string, Object>;<br>差异内容：extraInfos?: Record\<string, Object>;|api/wantAgent/triggerInfo.d.ts|
|新增API|NA|类名：WantAgentInfo；<br>API声明：actionType?: abilityWantAgent.OperationType;<br>差异内容：actionType?: abilityWantAgent.OperationType;|api/wantAgent/wantAgentInfo.d.ts|
|新增API|NA|类名：WantAgentInfo；<br>API声明：actionFlags?: Array\<abilityWantAgent.WantAgentFlags>;<br>差异内容：actionFlags?: Array\<abilityWantAgent.WantAgentFlags>;|api/wantAgent/wantAgentInfo.d.ts|
|新增API|NA|类名：WantAgentInfo；<br>API声明：extraInfos?: Record\<string, Object>;<br>差异内容：extraInfos?: Record\<string, Object>;|api/wantAgent/wantAgentInfo.d.ts|
|删除API|类名：common；<br>API声明：export type ServiceExtensionContext = _ServiceExtensionContext.default;<br>差异内容：export type ServiceExtensionContext = _ServiceExtensionContext.default;|NA|api/@ohos.app.ability.common.d.ts|
|起始版本有变化|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：NA|类名：vpn；<br>API声明：export type AbilityContext = _AbilityContext;<br>差异内容：10|api/@ohos.net.vpn.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.ability.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.dataUriUtils.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.errorCode.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.featureAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.particleAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.ability.wantConstant.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.Ability.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.AbilityConstant.d.ts|
|kit变更|NA|TestKit|api/@ohos.app.ability.abilityDelegatorRegistry.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.AbilityLifecycleCallback.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.AbilityStage.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.ActionExtensionAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.ApplicationStateChangeCallback.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.appManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.appRecovery.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.common.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.Configuration.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.ConfigurationConstant.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.contextConstant.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.dataUriUtils.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.dialogRequest.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.EnvironmentCallback.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.errorManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.ExtensionAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.ShareExtensionAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.StartOptions.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.UIAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.UIExtensionAbility.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.UIExtensionContentSession.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.Want.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.wantAgent.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.app.ability.wantConstant.d.ts|
|kit变更|NA|FormKit|api/@ohos.app.form.formBindingData.d.ts|
|kit变更|NA|FormKit|api/@ohos.app.form.FormExtensionAbility.d.ts|
|kit变更|NA|FormKit|api/@ohos.app.form.formInfo.d.ts|
|kit变更|NA|FormKit|api/@ohos.app.form.formProvider.d.ts|
|kit变更|NA|TestKit|api/@ohos.application.abilityDelegatorRegistry.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.application.appManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.application.Configuration.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.application.ConfigurationConstant.d.ts|
|kit变更|NA|FormKit|api/@ohos.application.formBindingData.d.ts|
|kit变更|NA|FormKit|api/@ohos.application.formError.d.ts|
|kit变更|NA|FormKit|api/@ohos.application.formInfo.d.ts|
|kit变更|NA|FormKit|api/@ohos.application.formProvider.d.ts|
|kit变更|NA|TestKit|api/@ohos.application.testRunner.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.application.uriPermissionManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.application.Want.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.continuation.continuationManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.wantAgent.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.wifiManagerExt.d.ts|
