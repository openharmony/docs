| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfos(callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>, hostBundleName?: string): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfos(hostBundleName?: string): Promise\<Array\<formInfo.RunningFormInfo>>;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function on(type: 'formAdd', observerCallback: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function on(type: 'formRemove', observerCallback: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function on(<br>    type: 'notifyVisible',<br>    observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>,<br>    hostBundleName?: string<br>  ): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function on(<br>    type: 'notifyInvisible',<br>    observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>,<br>    hostBundleName?: string<br>  ): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function off(type: 'formAdd', observerCallback?: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function off(type: 'formRemove', observerCallback?: Callback\<formInfo.RunningFormInfo>, bundleName?: string): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function off(<br>    type: 'notifyVisible',<br>    observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>>,<br>    hostBundleName?: string<br>  ): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function off(<br>    type: 'notifyInvisible',<br>    observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>>,<br>    hostBundleName?: string<br>  ): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfosByFilter(<br>    formProviderFilter: formInfo.FormProviderFilter<br>  ): Promise\<Array\<formInfo.RunningFormInfo>>;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfosByFilter(<br>    formProviderFilter: formInfo.FormProviderFilter,<br>    callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>><br>  ): void;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfoById(formId: string): Promise\<formInfo.RunningFormInfo>;|NA|@ohos.app.form.formHost.d.ts|
|删除|类名：formHost;<br>方法or属性：function getRunningFormInfoById(formId: string, callback: AsyncCallback\<formInfo.RunningFormInfo>): void;|NA|@ohos.app.form.formHost.d.ts|
|新增|NA|类名：appManager;<br>方法or属性：export type ProcessData = _ProcessData.default;|@ohos.app.ability.appManager.d.ts|
|新增|NA|类名：common;<br>方法or属性：export type UIExtensionContext = _UIExtensionContext.default;|@ohos.app.ability.common.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbility(want: Want, callback: AsyncCallback\<void>): void;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：UIExtensionContentSession;<br>方法or属性：startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>;|@ohos.app.ability.UIExtensionContentSession.d.ts|
|新增|NA|类名：Flags;<br>方法or属性：FLAG_AUTH_PERSISTABLE_URI_PERMISSION = 0x00000040|@ohos.app.ability.wantConstant.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'formAdd', observerCallback: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'formAdd', hostBundleName: string, observerCallback: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'formRemove', observerCallback: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'formRemove', hostBundleName: string, observerCallback: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'notifyVisible', observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(<br>    type: 'notifyVisible',<br>    hostBundleName: string,<br>    observerCallback: Callback\<Array\<formInfo.RunningFormInfo>><br>  ): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(type: 'notifyInvisible', observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function on(<br>    type: 'notifyInvisible',<br>    hostBundleName: string,<br>    observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>,<br>  ): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function off(type: 'formAdd', hostBundleName?: string, observerCallback?: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function off(type: 'formRemove', hostBundleName?: string, observerCallback?: Callback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function off(<br>    type: 'notifyVisible',<br>    hostBundleName?: string,<br>    observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>><br>  ): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function off(<br>    type: 'notifyInvisible',<br>    hostBundleName?: string,<br>    observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>><br>  ): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfos(callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>, hostBundleName?: string): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfos(hostBundleName?: string): Promise\<Array\<formInfo.RunningFormInfo>>;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfosByFilter(<br>    formProviderFilter: formInfo.FormProviderFilter<br>  ): Promise\<Array\<formInfo.RunningFormInfo>>;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfosByFilter(<br>    formProviderFilter: formInfo.FormProviderFilter,<br>    callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>><br>  ): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfoById(formId: string): Promise\<formInfo.RunningFormInfo>;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：formObserver;<br>方法or属性：function getRunningFormInfoById(formId: string, callback: AsyncCallback\<formInfo.RunningFormInfo>): void;|@ohos.app.form.formObserver.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：export type ContinuationResult = _ContinuationResult;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：continuationManager;<br>方法or属性：export type ContinuationExtraParams = _ContinuationExtraParams;|@ohos.continuation.continuationManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：export type ContinueCallback = _ContinueCallback;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：export type ContinueDeviceInfo = _ContinueDeviceInfo;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：export type MissionCallback = _MissionCallback;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：export type MissionDeviceInfo = _MissionDeviceInfo;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：distributedMissionManager;<br>方法or属性：export type MissionParameter = _MissionParameter;|@ohos.distributedMissionManager.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityMonitorSync(monitor: AbilityMonitor): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：addAbilityStageMonitorSync(monitor: AbilityStageMonitor): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityMonitorSync(monitor: AbilityMonitor): void;|AbilityDelegator.d.ts|
|新增|NA|类名：AbilityDelegator;<br>方法or属性：removeAbilityStageMonitorSync(monitor: AbilityStageMonitor): void;|AbilityDelegator.d.ts|
|新增|NA|类名：UIExtensionContext;<br>方法or属性：connectServiceExtensionAbility(want: Want, options: ConnectOptions): number;|UIExtensionContext.d.ts|
|新增|NA|类名：UIExtensionContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void;|UIExtensionContext.d.ts|
|新增|NA|类名：UIExtensionContext;<br>方法or属性：disconnectServiceExtensionAbility(connection: number): Promise\<void>;|UIExtensionContext.d.ts|
|错误码有变化|类名：UIExtensionContentSession;<br>方法or属性：sendData(data: { [key: string]: Object }): void;<br>旧版本信息：401,16000050|类名：UIExtensionContentSession;<br>方法or属性：sendData(data: { [key: string]: Object }): void;<br>新版本信息：202,401,16000050|@ohos.app.ability.UIExtensionContentSession.d.ts|
|错误码有变化|类名：UIExtensionContentSession;<br>方法or属性：setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void;<br>旧版本信息：401,16000050|类名：UIExtensionContentSession;<br>方法or属性：setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void;<br>新版本信息：202,401,16000050|@ohos.app.ability.UIExtensionContentSession.d.ts|
|错误码有变化|类名：UIExtensionContentSession;<br>方法or属性：setWindowBackgroundColor(color: string): void;<br>旧版本信息：401,16000050|类名：UIExtensionContentSession;<br>方法or属性：setWindowBackgroundColor(color: string): void;<br>新版本信息：202,401,16000050|@ohos.app.ability.UIExtensionContentSession.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：export enum ProcessState<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：export enum ProcessState<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：STATE_CREATE<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：STATE_CREATE<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：STATE_FOREGROUND<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：STATE_FOREGROUND<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：STATE_ACTIVE<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：STATE_ACTIVE<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：STATE_BACKGROUND<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：STATE_BACKGROUND<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|访问级别有变化|类名：ProcessState;<br>方法or属性：STATE_DESTROY<br>旧版本信息：systemapi|类名：ProcessState;<br>方法or属性：STATE_DESTROY<br>新版本信息：|@ohos.app.ability.appManager.d.ts|
|model有变化|类名：common;<br>方法or属性：export type BaseContext = _BaseContext.default;<br>旧版本信息：|类名：common;<br>方法or属性：export type BaseContext = _BaseContext.default;<br>新版本信息：StageModelOnly|@ohos.app.ability.common.d.ts|
|model有变化|类名：AreaMode;<br>方法or属性：EL1 = 0<br>旧版本信息：|类名：AreaMode;<br>方法or属性：EL1 = 0<br>新版本信息：StageModelOnly|@ohos.app.ability.contextConstant.d.ts|
|model有变化|类名：AreaMode;<br>方法or属性：EL2 = 1<br>旧版本信息：|类名：AreaMode;<br>方法or属性：EL2 = 1<br>新版本信息：StageModelOnly|@ohos.app.ability.contextConstant.d.ts|
|model有变化|类名：ExtensionContext;<br>方法or属性：extensionAbilityInfo: ExtensionAbilityInfo;<br>旧版本信息：|类名：ExtensionContext;<br>方法or属性：extensionAbilityInfo: ExtensionAbilityInfo;<br>新版本信息：StageModelOnly|ExtensionContext.d.ts|
|type有变化|类名：ContinueMissionInfo;<br>方法or属性：srcDeviceId: string;<br>旧版本信息：|类名：ContinueMissionInfo;<br>方法or属性：srcDeviceId: string;<br>新版本信息：string|ContinueMissionInfo.d.ts|
|type有变化|类名：ContinueMissionInfo;<br>方法or属性：dstDeviceId: string;<br>旧版本信息：|类名：ContinueMissionInfo;<br>方法or属性：dstDeviceId: string;<br>新版本信息：string|ContinueMissionInfo.d.ts|
|type有变化|类名：ContinueMissionInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：ContinueMissionInfo;<br>方法or属性：bundleName: string;<br>新版本信息：string|ContinueMissionInfo.d.ts|
|type有变化|类名：ContinueMissionInfo;<br>方法or属性：wantParam: { [key: string]: Object };<br>旧版本信息：|类名：ContinueMissionInfo;<br>方法or属性：wantParam: { [key: string]: Object };<br>新版本信息：object|ContinueMissionInfo.d.ts|
|函数有变化|类名：UIAbility;<br>方法or属性：onCreate(want: Want, param: AbilityConstant.LaunchParam): void;|类名：UIAbility;<br>方法or属性：onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void;|@ohos.app.ability.UIAbility.d.ts|
|函数有变化|类名：UIAbility;<br>方法or属性：onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void;|类名：UIAbility;<br>方法or属性：onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void;|@ohos.app.ability.UIAbility.d.ts|
