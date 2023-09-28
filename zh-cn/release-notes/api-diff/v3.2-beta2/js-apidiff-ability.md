# 元能力子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，元能力子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| AbilityContext | AbilityContext | isTerminating(): boolean; | 新增 |
| AbilityContext | AbilityContext | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbility(want: Want): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | 新增 |
| AbilityContext | AbilityContext | startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbility(want: Want): Promise\<void>; | 新增 |
| abilityDelegator | AbilityDelegator | printSync(msg: string): void; | 新增 |
| ApplicationContext | ApplicationContext | unregisterEnvironmentCallback(callbackId: number,  callback: AsyncCallback\<void>): void;<br>unregisterEnvironmentCallback(callbackId: number): Promise\<void>; | 新增 |
| ApplicationContext | ApplicationContext | registerEnvironmentCallback(callback: EnvironmentCallback): number; | 新增 |
| applicationInfo | ApplicationInfo | readonly appProvisionType: string; | 新增 |
| applicationInfo | ApplicationInfo | readonly appDistributionType: string; | 新增 |
| applicationInfo | ApplicationInfo | readonly descriptionResource: Resource; | 新增 |
| applicationInfo | ApplicationInfo | readonly labelResource: Resource; | 新增 |
| applicationInfo | ApplicationInfo | readonly iconResource: Resource; | 新增 |
| applicationInfo | ApplicationInfo | readonly fingerprint: string; | 新增 |
| context | Context | createModuleContext(moduleName: string): Context;<br>createModuleContext(bundleName: string, moduleName: string): Context; | 新增 |
| ErrorObserver | ErrorObserver | onUnhandledException(errMsg: string): void; | 新增 |
| ExtensionContext | ExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | 新增 |
| FormExtensionContext | FormExtensionContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want): Promise\<void>; | 新增 |
| MissionCallbacks | MissionCallback | notifyNetDisconnect(deviceId: string, state: number): void; | 新增 |
| MissionCallbacks | MissionCallback | notifySnapshot(deviceId: string, mission: number): void; | 新增 |
| MissionCallbacks | MissionCallback | notifyMissionsChanged(deviceId: string): void; | 新增 |
| MissionDeviceInfo | MissionDeviceInfo | deviceId: string; | 新增 |
| MissionParameter | MissionParameter | tag: number; | 新增 |
| MissionParameter | MissionParameter | fixConflict: boolean; | 新增 |
| MissionParameter | MissionParameter | deviceId: string; | 新增 |
| ohos.ability.wantConstant | Action | ACTION_MARKER_DOWNLOAD = "ohos.want.action.marketDownload" | 新增 |
| ohos.abilityAccessCtrl | AtManager | verifyAccessTokenSync(tokenID: number, permissionName: string): GrantStatus; | 新增 |
| ohos.application.Ability | CalleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | 新增 |
| ohos.application.appManager | appManager | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;<br>getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | normalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | batchInsert?(uri: string, valueBuckets: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getType?(uri: string, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>, callback: AsyncCallback\<Object>): void;" | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void;" | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | openFile?(uri: string, mode: string, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | onCreate?(want: Want, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | context?: ExtensionContext; | 新增 |
| ohos.application.EnvironmentCallback | EnvironmentCallback | onConfigurationUpdated(config: Configuration): void; | 新增 |
| ohos.application.errorManager | errorManager | unregisterErrorObserver(observerId: number,  callback: AsyncCallback\<void>): void;<br>unregisterErrorObserver(observerId: number): Promise\<void>; | 新增 |
| ohos.application.errorManager | errorManager | registerErrorObserver(observer: ErrorObserver): number; | 新增 |
| ohos.application.formInfo | FormInfoFilter | moduleName?: string; | 新增 |
| ohos.application.formProvider | formProvider | isRequestPublishFormSupported(callback: AsyncCallback\<boolean>): void;<br>isRequestPublishFormSupported(): Promise\<boolean>; | 新增 |
| ohos.application.formProvider | formProvider | requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void;<br>requestPublishForm(want: Want, callback: AsyncCallback\<string>): void;<br>requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise\<string>; | 新增 |
| ohos.application.formProvider | formProvider | getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>getFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>getFormsInfo(filter?: formInfo.FormInfoFilter): Promise\<Array\<formInfo.FormInfo>>; | 新增 |
| ohos.application.missionManager | missionManager | getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;<br>getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>; | 新增 |
| ohos.application.Want | Want | moduleName?: string; | 新增 |
| ohos.distributedMissionManager | distributedMissionManager | unRegisterMissionListener(parameter: MissionDeviceInfo, callback:AsyncCallback\<void>): void;<br>unRegisterMissionListener(parameter: MissionDeviceInfo): Promise\<void>; | 新增 |
| ohos.distributedMissionManager | distributedMissionManager | registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback\<void>): void;<br>registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise\<void>; | 新增 |
| ohos.distributedMissionManager | distributedMissionManager | stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void;<br>stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise\<void>; | 新增 |
| ohos.distributedMissionManager | distributedMissionManager | startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback\<void>): void;<br>startSyncRemoteMissions(parameter: MissionParameter): Promise\<void>; | 新增 |
| ProcessRunningInformation | ProcessRunningInformation | bundleNames: Array\<string>; | 新增 |
| ProcessRunningInformation | ProcessRunningInformation | processName: string; | 新增 |
| ProcessRunningInformation | ProcessRunningInformation | uid: number; | 新增 |
| ProcessRunningInformation | ProcessRunningInformation | pid: number; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbility(want: Want): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | 新增 |
| ServiceExtensionContext | ServiceExtensionContext | startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbility(want: Want): Promise\<void>; | 新增 |
| ohos.application.Ability | CaleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | 删除 |
| ohos.application.uriPermissionManager | uriPermissionManager | verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback\<number>): void;<br>verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise\<number>; | 删除 |
| FormExtensionContext | FormExtensionContext | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | 删除 |
| ServiceExtensionContext | ServiceExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | 删除 |
| ohos.application.appManager | appManager | getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void; | 废弃 |
| ohos.application.Ability | Ability | old : onNewWant(want: Want): void;<br>new : onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void; | 变更 |
| ohos.application.Ability | Callee | old : on(method: string, callback: CaleeCallBack): void;<br>new : on(method: string, callback: CalleeCallBack): void; | 变更 |