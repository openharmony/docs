| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.app.ability.abilityManager<br>类名: AbilityState<br>方法 or 属性: FOCUS = 2|@ohos.app.ability.abilityManager.d.ts|
|新增|NA|类名：appManager<br>方法or属性：function getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：appManager<br>方法or属性：function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：RestartFlag<br>方法or属性：RESTART_WHEN_JS_CRASH = 0x0001|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|类名：RestartFlag<br>方法or属性：RESTART_WHEN_APP_FREEZE = 0x0002|@ohos.app.ability.appRecovery.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: dialogRequest|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: RequestInfo|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: ResultCode|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: ResultCode<br>方法 or 属性: RESULT_OK = 0|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: ResultCode<br>方法 or 属性: RESULT_CANCEL = 1|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: RequestResult|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: RequestResult<br>方法 or 属性: result: ResultCode;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: RequestCallback|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: RequestCallback<br>方法 or 属性: setRequestResult(result: RequestResult): void;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: dialogRequest<br>方法 or 属性: function getRequestInfo(want: Want): RequestInfo;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|模块名: ohos.app.ability.dialogRequest<br>类名: dialogRequest<br>方法 or 属性: function getRequestCallback(want: Want): RequestCallback;|@ohos.app.ability.dialogRequest.d.ts|
|新增|NA|类名：Want<br>方法or属性：parameters?: {[key: string]: Object};|@ohos.app.ability.Want.d.ts|
|新增|NA|类名：CompleteData<br>方法or属性：extraInfo?: { [key: string]: Object };|@ohos.app.ability.wantAgent.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：DLP_PARAMS_SANDBOX = "ohos.dlp.params.sandbox"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：DLP_PARAMS_SANDBOX = "ohos.dlp.params.sandbox"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：DLP_PARAMS_BUNDLE_NAME = "ohos.dlp.params.bundleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：DLP_PARAMS_BUNDLE_NAME = "ohos.dlp.params.bundleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：DLP_PARAMS_MODULE_NAME = "ohos.dlp.params.moduleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：DLP_PARAMS_MODULE_NAME = "ohos.dlp.params.moduleName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：DLP_PARAMS_ABILITY_NAME = "ohos.dlp.params.abilityName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：DLP_PARAMS_ABILITY_NAME = "ohos.dlp.params.abilityName"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：DLP_PARAMS_INDEX = "ohos.dlp.params.index"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：DLP_PARAMS_INDEX = "ohos.dlp.params.index"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|模块名: ohos.app.ability.wantConstant<br>类名: Params<br>方法 or 属性：ABILITY_BACK_TO_OTHER_MISSION_STACK = "ability.params.backToOtherMissionStack"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：Params<br>方法or属性：ABILITY_BACK_TO_OTHER_MISSION_STACK = "ability.params.backToOtherMissionStack"|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：continuationManager<br>方法or属性：function on(type: "deviceSelected", token: number, callback: Callback\<Array\<ContinuationResult>>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager<br>方法or属性：function off(type: "deviceSelected", token: number): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager<br>方法or属性：function on(type: "deviceUnselected", token: number, callback: Callback\<Array\<ContinuationResult>>): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager<br>方法or属性：function off(type: "deviceUnselected", token: number): void;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: getAppContext(): Context;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: getAbilityState(ability: UIAbility): number;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: getCurrentTopAbility(): Promise\<UIAbility>|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: startAbility(want: Want, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: startAbility(want: Want): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: doAbilityForeground(ability: UIAbility): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: doAbilityBackground(ability: UIAbility): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: print(msg: string, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: print(msg: string): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: printSync(msg: string): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性: finishTest(msg: string, code: number): Promise\<void>;|AbilityDelegator.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: abilityName: string;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: moduleName?: string;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onAbilityCreate?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onAbilityForeground?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onAbilityBackground?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onAbilityDestroy?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onWindowStageCreate?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onWindowStageRestore?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性: onWindowStageDestroy?:(ability: UIAbility) => void;|AbilityMonitor.d.ts|
|新增|NA|模块名: AbilityStageMonitor<br>类名: AbilityStageMonitor|AbilityStageMonitor.d.ts|
|新增|NA|模块名: AbilityStageMonitor<br>类名: AbilityStageMonitor<br>方法 or 属性: moduleName: string;|AbilityStageMonitor.d.ts|
|新增|NA|模块名: AbilityStageMonitor<br>类名: AbilityStageMonitor<br>方法 or 属性: srcEntrance: string;|AbilityStageMonitor.d.ts|
|新增|NA|类名：ApplicationContext<br>方法or属性：getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext<br>方法or属性：getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext<br>方法or属性：killAllProcesses(): Promise\<void>;|ApplicationContext.d.ts|
|新增|NA|类名：ApplicationContext<br>方法or属性：killAllProcesses(callback: AsyncCallback\<void>);|ApplicationContext.d.ts|
|新增|NA|类名：Context<br>方法or属性：area: contextConstant.AreaMode;|Context.d.ts|
|新增|NA|模块名: ProcessInformation<br>类名: ProcessInformation|ProcessInformation.d.ts|
|新增|NA|模块名: ProcessInformation<br>类名: ProcessInformation<br>方法 or 属性: pid: number;|ProcessInformation.d.ts|
|新增|NA|模块名: ProcessInformation<br>类名: ProcessInformation<br>方法 or 属性: uid: number;|ProcessInformation.d.ts|
|新增|NA|模块名: ProcessInformation<br>类名: ProcessInformation<br>方法 or 属性: processName: string;|ProcessInformation.d.ts|
|新增|NA|模块名: ProcessInformation<br>类名: ProcessInformation<br>方法 or 属性: bundleNames: Array\<string>;|ProcessInformation.d.ts|
|新增|NA|类名：ServiceExtensionContext<br>方法or属性：startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext<br>方法or属性：startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|ServiceExtensionContext.d.ts|
|新增|NA|类名：ServiceExtensionContext<br>方法or属性：startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;|ServiceExtensionContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：startRecentAbility(want: Want, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：startRecentAbility(want: Want, options?: StartOptions): Promise\<void>;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：requestDialogService(want: Want, result: AsyncCallback\<dialogRequest.RequestResult>): void;|UIAbilityContext.d.ts|
|新增|NA|类名：UIAbilityContext<br>方法or属性：requestDialogService(want: Want): Promise\<dialogRequest.RequestResult>;|UIAbilityContext.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_APP_ACCOUNT_AUTH = "ohos.appAccount.action.auth"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_MARKET_DOWNLOAD = "ohos.want.action.marketDownload"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_MARKET_CROWDTEST = "ohos.want.action.marketCrowdTest"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_SANDBOX = "ohos.dlp.params.sandbox"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_BUNDLE_NAME = "ohos.dlp.params.bundleName"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_MODULE_NAME = "ohos.dlp.params.moduleName"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_ABILITY_NAME = "ohos.dlp.params.abilityName"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名: ohos.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_INDEX = "ohos.dlp.params.index"|NA|@ohos.ability.wantConstant.d.ts|
|删除|模块名：ohos.app.ability.appManager<br>类名:appManager<br>方法 or 属性:function getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;|NA|@ohos.app.ability.appManager.d.ts|
|删除|模块名：ohos.app.ability.appManager<br>类名:appManager<br>方法 or 属性:function getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void;|NA|@ohos.app.ability.appManager.d.ts|
|删除|模块名：ohos.app.ability.appRecovery<br>类名:RestartFlag<br>方法 or 属性:CPP_CRASH_NO_RESTART = 0x0001|NA|@ohos.app.ability.appRecovery.d.ts|
|删除|模块名：ohos.app.ability.appRecovery<br>类名:RestartFlag<br>方法 or 属性:JS_CRASH_NO_RESTART = 0x0002|NA|@ohos.app.ability.appRecovery.d.ts|
|删除|模块名：ohos.app.ability.appRecovery<br>类名:RestartFlag<br>方法 or 属性:APP_FREEZE_NO_RESTART = 0x0004|NA|@ohos.app.ability.appRecovery.d.ts|
|删除|模块名: ohos.app.ability.common<br>类名: AreaMode|NA|@ohos.app.ability.common.d.ts|
|删除|模块名: ohos.app.ability.common<br>类名: AreaMode<br>方法 or 属性：EL1 = 0|NA|@ohos.app.ability.common.d.ts|
|删除|模块名: ohos.app.ability.common<br>类名: AreaMode<br>方法 or 属性：EL2 = 1|NA|@ohos.app.ability.common.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_HOME = "ohos.want.action.home"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_DIAL = "ohos.want.action.dial"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SEARCH = "ohos.want.action.search"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_WIRELESS_SETTINGS = "ohos.settings.wireless"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_MANAGE_APPLICATIONS_SETTINGS = "ohos.settings.manage.applications"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_APPLICATION_DETAILS_SETTINGS = "ohos.settings.application.details"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SET_ALARM = "ohos.want.action.setAlarm"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SHOW_ALARMS = "ohos.want.action.showAlarms"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SNOOZE_ALARM = "ohos.want.action.snoozeAlarm"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_DISMISS_ALARM = "ohos.want.action.dismissAlarm"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_DISMISS_TIMER = "ohos.want.action.dismissTimer"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SEND_SMS = "ohos.want.action.sendSms"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_CHOOSE = "ohos.want.action.choose"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_IMAGE_CAPTURE = "ohos.want.action.imageCapture"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_VIDEO_CAPTURE = "ohos.want.action.videoCapture"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SELECT = "ohos.want.action.select"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SEND_DATA = "ohos.want.action.sendData"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SEND_MULTIPLE_DATA = "ohos.want.action.sendMultipleData"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_SCAN_MEDIA_FILE = "ohos.want.action.scanMediaFile"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_VIEW_DATA = "ohos.want.action.viewData"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_EDIT_DATA = "ohos.want.action.editData"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：INTENT_PARAMS_INTENT = "ability.want.params.INTENT"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：INTENT_PARAMS_TITLE = "ability.want.params.TITLE"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_FILE_SELECT = "ohos.action.fileSelect"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：PARAMS_STREAM = "ability.params.stream"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_APP_ACCOUNT_AUTH = "ohos.appAccount.action.auth"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_MARKET_DOWNLOAD = "ohos.want.action.marketDownload"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：ACTION_MARKET_CROWDTEST = "ohos.want.action.marketCrowdTest"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_SANDBOX = "ohos.dlp.params.sandbox"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_BUNDLE_NAME = "ohos.dlp.params.bundleName"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_MODULE_NAME = "ohos.dlp.params.moduleName"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_ABILITY_NAME = "ohos.dlp.params.abilityName"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Action<br>方法 or 属性：DLP_PARAMS_INDEX = "ohos.dlp.params.index"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity<br>方法 or 属性：ENTITY_DEFAULT = "entity.system.default"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity<br>方法 or 属性：ENTITY_HOME = "entity.system.home"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity<br>方法 or 属性：ENTITY_VOICE = "entity.system.voice"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity<br>方法 or 属性：ENTITY_BROWSABLE = "entity.system.browsable"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Entity<br>方法 or 属性：ENTITY_VIDEO = "entity.system.video"|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_FORWARD_RESULT = 0x00000004|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_CONTINUATION = 0x00000008|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_NOT_OHOS_COMPONENT = 0x00000010|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_FORM_ENABLED = 0x00000020|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_AUTH_PERSISTABLE_URI_PERMISSION = 0x00000040|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_AUTH_PREFIX_URI_PERMISSION = 0x00000080|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITYSLICE_MULTI_DEVICE = 0x00000100|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_START_FOREGROUND_ABILITY = 0x00000200|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_CONTINUATION_REVERSIBLE = 0x00000400|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_INSTALL_WITH_BACKGROUND_MODE = 0x80000000|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_CLEAR_MISSION = 0x00008000|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_NEW_MISSION = 0x10000000|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.ability.wantConstant<br>类名: Flags<br>方法 or 属性：FLAG_ABILITY_MISSION_TOP = 0x20000000|NA|@ohos.app.ability.wantConstant.d.ts|
|删除|模块名: ohos.app.form.formInfo<br>类名: FormInfo<br>方法 or 属性：relatedBundleName: string;|NA|@ohos.app.form.formInfo.d.ts|
|删除|模块名：ohos.continuation.continuationManager<br>类名:continuationManager<br>方法 or 属性:function on(type: "deviceConnect", token: number, callback: Callback\<Array\<ContinuationResult>>): void;|NA|@ohos.continuation.continuationManager.d.ts|
|删除|模块名：ohos.continuation.continuationManager<br>类名:continuationManager<br>方法 or 属性:function off(type: "deviceConnect", token: number): void;|NA|@ohos.continuation.continuationManager.d.ts|
|删除|模块名：ohos.continuation.continuationManager<br>类名:continuationManager<br>方法 or 属性:function on(type: "deviceDisconnect", token: number, callback: Callback\<Array\<string>>): void;|NA|@ohos.continuation.continuationManager.d.ts|
|删除|模块名：ohos.continuation.continuationManager<br>类名:continuationManager<br>方法 or 属性:function off(type: "deviceDisconnect", token: number): void;|NA|@ohos.continuation.continuationManager.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：getAppContext(): Context;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：getAbilityState(ability: UIAbility): number;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：getCurrentTopAbility(): Promise\<UIAbility>|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：startAbility(want: Want): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：doAbilityForeground(ability: UIAbility): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：doAbilityBackground(ability: UIAbility): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：print(msg: string, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：print(msg: string): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：printSync(msg: string): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityDelegator<br>类名: AbilityDelegator<br>方法 or 属性：finishTest(msg: string, code: number): Promise\<void>;|NA|abilityDelegator.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：abilityName: string;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：moduleName?: string;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onAbilityCreate?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onAbilityForeground?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onAbilityBackground?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onAbilityDestroy?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onWindowStageCreate?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onWindowStageRestore?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityMonitor<br>类名: AbilityMonitor<br>方法 or 属性：onWindowStageDestroy?:(ability: UIAbility) => void;|NA|abilityMonitor.d.ts|
|删除|模块名: abilityStageMonitor<br>类名: AbilityStageMonitor|NA|abilityStageMonitor.d.ts|
|删除|模块名: abilityStageMonitor<br>类名: AbilityStageMonitor<br>方法 or 属性：moduleName: string;|NA|abilityStageMonitor.d.ts|
|删除|模块名: abilityStageMonitor<br>类名: AbilityStageMonitor<br>方法 or 属性：srcEntrance: string;|NA|abilityStageMonitor.d.ts|
|删除|模块名：ApplicationContext<br>类名:ApplicationContext<br>方法 or 属性:getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;|NA|ApplicationContext.d.ts|
|删除|模块名：ApplicationContext<br>类名:ApplicationContext<br>方法 or 属性:getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void;|NA|ApplicationContext.d.ts|
|删除|模块名：ApplicationContext<br>类名:ApplicationContext<br>方法 or 属性:killProcessesBySelf(): Promise\<void>;|NA|ApplicationContext.d.ts|
|删除|模块名：ApplicationContext<br>类名:ApplicationContext<br>方法 or 属性:killProcessesBySelf(callback: AsyncCallback\<void>);|NA|ApplicationContext.d.ts|
|删除|模块名: Context<br>类名: AreaMode|NA|Context.d.ts|
|删除|模块名: Context<br>类名: AreaMode<br>方法 or 属性：EL1 = 0|NA|Context.d.ts|
|删除|模块名: Context<br>类名: AreaMode<br>方法 or 属性：EL2 = 1|NA|Context.d.ts|
|删除|模块名: ProcessRunningInformation<br>类名: ProcessRunningInformation|NA|ProcessRunningInformation.d.ts|
|删除|模块名: ProcessRunningInformation<br>类名: ProcessRunningInformation<br>方法 or 属性：pid: number;|NA|ProcessRunningInformation.d.ts|
|删除|模块名: ProcessRunningInformation<br>类名: ProcessRunningInformation<br>方法 or 属性：uid: number;|NA|ProcessRunningInformation.d.ts|
|删除|模块名: ProcessRunningInformation<br>类名: ProcessRunningInformation<br>方法 or 属性：processName: string;|NA|ProcessRunningInformation.d.ts|
|删除|模块名: ProcessRunningInformation<br>类名: ProcessRunningInformation<br>方法 or 属性：bundleNames: Array\<string>;|NA|ProcessRunningInformation.d.ts|
|访问级别有变化|类名：WindowMode<br>访问级别：公开API|类名：WindowMode<br>访问级别：系统API|@ohos.app.ability.AbilityConstant.d.ts|
|访问级别有变化|类名：StartOptions<br>方法 or 属性：windowMode?: number;<br>访问级别：公开API|类名：StartOptions<br>方法 or 属性：windowMode?: number;<br>访问级别：系统API|@ohos.app.ability.StartOptions.d.ts|
|访问级别有变化|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|ServiceExtensionContext.d.ts|
|访问级别有变化|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|ServiceExtensionContext.d.ts|
|访问级别有变化|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;<br>访问级别：系统API|类名：ServiceExtensionContext<br>方法 or 属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;<br>访问级别：公开API|ServiceExtensionContext.d.ts|
|访问级别有变化|类名：ServiceExtensionContext<br>方法 or 属性：terminateSelf(callback: AsyncCallback\<void>): void;<br>访问级别：系统API|类名：ServiceExtensionContext<br>方法 or 属性：terminateSelf(callback: AsyncCallback\<void>): void;<br>访问级别：公开API|ServiceExtensionContext.d.ts|
|访问级别有变化|类名：ServiceExtensionContext<br>方法 or 属性：terminateSelf(): Promise\<void>;<br>访问级别：系统API|类名：ServiceExtensionContext<br>方法 or 属性：terminateSelf(): Promise\<void>;<br>访问级别：公开API|ServiceExtensionContext.d.ts|
|访问级别有变化|类名：UIAbilityContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise\<Caller>;<br>访问级别：系统API|类名：UIAbilityContext<br>方法 or 属性：startAbilityByCall(want: Want): Promise\<Caller>;<br>访问级别：公开API|UIAbilityContext.d.ts|
|权限有变化|类名：distributedMissionManager<br>方法 or 属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.MANAGE_MISSIONS|类名：distributedMissionManager<br>方法 or 属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC|@ohos.distributedMissionManager.d.ts|
|权限有变化|类名：distributedMissionManager<br>方法 or 属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise\<void>;<br>权限:ohos.permission.MANAGE_MISSIONS|类名：distributedMissionManager<br>方法 or 属性：function continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise\<void>;<br>权限:ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC|@ohos.distributedMissionManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function registerContinuation(callback: AsyncCallback\<number>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function registerContinuation(callback: AsyncCallback\<number>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function registerContinuation(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function registerContinuation(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function registerContinuation(options?: ContinuationExtraParams): Promise\<number>;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function registerContinuation(options?: ContinuationExtraParams): Promise\<number>;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function unregisterContinuation(token: number, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function unregisterContinuation(token: number, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function unregisterContinuation(token: number): Promise\<void>;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function unregisterContinuation(token: number): Promise\<void>;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|新增(权限)|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;<br>权限:N/A|类名：continuationManager<br>方法 or 属性：function startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;<br>权限:ohos.permission.DISTRIBUTED_DATASYNC|@ohos.continuation.continuationManager.d.ts|
|函数有变化|类名：CalleeCallback<br>方法 or 属性：(indata: rpc.MessageParcel): rpc.Sequenceable;<br>|类名：CalleeCallback<br>方法 or 属性：(indata: rpc.MessageSequence): rpc.Parcelable;<br>|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：Caller<br>方法 or 属性：call(method: string, data: rpc.Sequenceable): Promise\<void>;<br>|类名：Caller<br>方法 or 属性：call(method: string, data: rpc.Parcelable): Promise\<void>;<br>|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：Caller<br>方法 or 属性：callWithResult(method: string, data: rpc.Sequenceable): Promise\<rpc.MessageParcel>;<br>|类名：Caller<br>方法 or 属性：callWithResult(method: string, data: rpc.Parcelable): Promise\<rpc.MessageSequence>;<br>|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：UIAbility<br>方法 or 属性：onContinue(wantParam: { [key: string]: any }): AbilityConstant.OnContinueResult;<br>|类名：UIAbility<br>方法 or 属性：onContinue(wantParam: { [key: string]: Object }): AbilityConstant.OnContinueResult;<br>|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：UIAbility<br>方法 or 属性：onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: any}): AbilityConstant.OnSaveResult;<br>|类名：UIAbility<br>方法 or 属性：onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: Object}): AbilityConstant.OnSaveResult;<br>|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：FormExtensionAbility<br>方法 or 属性：onShareForm?(formId: string): { [key: string]: any };<br>|类名：FormExtensionAbility<br>方法 or 属性：onShareForm?(formId: string): { [key: string]: Object };<br>|@ohos.app.form.FormExtensionAbility.d.ts|
