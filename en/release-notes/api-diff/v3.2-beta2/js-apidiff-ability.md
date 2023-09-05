# JS API Changes of the Ability Framework

The table below lists the APIs changes of the ability framework in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| AbilityContext | AbilityContext | isTerminating(): boolean; | Added|
| AbilityContext | AbilityContext | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | Added|
| AbilityContext | AbilityContext | stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbility(want: Want): Promise\<void>; | Added|
| AbilityContext | AbilityContext | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | Added|
| AbilityContext | AbilityContext | startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbility(want: Want): Promise\<void>; | Added|
| abilityDelegator | AbilityDelegator | printSync(msg: string): void; | Added|
| ApplicationContext | ApplicationContext | unregisterEnvironmentCallback(callbackId: number,  callback: AsyncCallback\<void>): void;<br>unregisterEnvironmentCallback(callbackId: number): Promise\<void>; | Added|
| ApplicationContext | ApplicationContext | registerEnvironmentCallback(callback: EnvironmentCallback): number; | Added|
| applicationInfo | ApplicationInfo | readonly appProvisionType: string; | Added|
| applicationInfo | ApplicationInfo | readonly appDistributionType: string; | Added|
| applicationInfo | ApplicationInfo | readonly descriptionResource: Resource; | Added|
| applicationInfo | ApplicationInfo | readonly labelResource: Resource; | Added|
| applicationInfo | ApplicationInfo | readonly iconResource: Resource; | Added|
| applicationInfo | ApplicationInfo | readonly fingerprint: string; | Added|
| context | Context | createModuleContext(moduleName: string): Context;<br>createModuleContext(bundleName: string, moduleName: string): Context; | Added|
| ErrorObserver | ErrorObserver | onUnhandledException(errMsg: string): void; | Added|
| ExtensionContext | ExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | Added|
| FormExtensionContext | FormExtensionContext | startAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startAbility(want: Want): Promise\<void>; | Added|
| MissionCallbacks | MissionCallback | notifyNetDisconnect(deviceId: string, state: number): void; | Added|
| MissionCallbacks | MissionCallback | notifySnapshot(deviceId: string, mission: number): void; | Added|
| MissionCallbacks | MissionCallback | notifyMissionsChanged(deviceId: string): void; | Added|
| MissionDeviceInfo | MissionDeviceInfo | deviceId: string; | Added|
| MissionParameter | MissionParameter | tag: number; | Added|
| MissionParameter | MissionParameter | fixConflict: boolean; | Added|
| MissionParameter | MissionParameter | deviceId: string; | Added|
| ohos.ability.wantConstant | Action | ACTION_MARKER_DOWNLOAD = "ohos.want.action.marketDownload" | Added|
| ohos.abilityAccessCtrl | AtManager | verifyAccessTokenSync(tokenID: number, permissionName: string): GrantStatus; | Added|
| ohos.application.Ability | CalleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | Added|
| ohos.application.appManager | appManager | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;<br>getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | normalizeUri?(uri: string, callback: AsyncCallback\<string>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | batchInsert?(uri: string, valueBuckets: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getType?(uri: string, callback: AsyncCallback\<string>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array\<string>, callback: AsyncCallback\<Object>): void;" | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | "update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void;" | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | openFile?(uri: string, mode: string, callback: AsyncCallback\<number>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | onCreate?(want: Want, callback: AsyncCallback\<void>): void; | Added|
| ohos.application.DataShareExtensionAbility | DataShareExtensionAbility | context?: ExtensionContext; | Added|
| ohos.application.EnvironmentCallback | EnvironmentCallback | onConfigurationUpdated(config: Configuration): void; | Added|
| ohos.application.errorManager | errorManager | unregisterErrorObserver(observerId: number,  callback: AsyncCallback\<void>): void;<br>unregisterErrorObserver(observerId: number): Promise\<void>; | Added|
| ohos.application.errorManager | errorManager | registerErrorObserver(observer: ErrorObserver): number; | Added|
| ohos.application.formInfo | FormInfoFilter | moduleName?: string; | Added|
| ohos.application.formProvider | formProvider | isRequestPublishFormSupported(callback: AsyncCallback\<boolean>): void;<br>isRequestPublishFormSupported(): Promise\<boolean>; | Added|
| ohos.application.formProvider | formProvider | requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void;<br>requestPublishForm(want: Want, callback: AsyncCallback\<string>): void;<br>requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise\<string>; | Added|
| ohos.application.formProvider | formProvider | getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>getFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void;<br>getFormsInfo(filter?: formInfo.FormInfoFilter): Promise\<Array\<formInfo.FormInfo>>; | Added|
| ohos.application.missionManager | missionManager | getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void;<br>getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>; | Added|
| ohos.application.Want | Want | moduleName?: string; | Added|
| ohos.distributedMissionManager | distributedMissionManager | unRegisterMissionListener(parameter: MissionDeviceInfo, callback:AsyncCallback\<void>): void;<br>unRegisterMissionListener(parameter: MissionDeviceInfo): Promise\<void>; | Added|
| ohos.distributedMissionManager | distributedMissionManager | registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback\<void>): void;<br>registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise\<void>; | Added|
| ohos.distributedMissionManager | distributedMissionManager | stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void;<br>stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise\<void>; | Added|
| ohos.distributedMissionManager | distributedMissionManager | startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback\<void>): void;<br>startSyncRemoteMissions(parameter: MissionParameter): Promise\<void>; | Added|
| ProcessRunningInformation | ProcessRunningInformation | bundleNames: Array\<string>; | Added|
| ProcessRunningInformation | ProcessRunningInformation | processName: string; | Added|
| ProcessRunningInformation | ProcessRunningInformation | uid: number; | Added|
| ProcessRunningInformation | ProcessRunningInformation | pid: number; | Added|
| ServiceExtensionContext | ServiceExtensionContext | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>stopServiceExtensionAbility(want: Want): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>; | Added|
| ServiceExtensionContext | ServiceExtensionContext | startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;<br>startServiceExtensionAbility(want: Want): Promise\<void>; | Added|
| ohos.application.Ability | CaleeCallBack | (indata: rpc.MessageParcel): rpc.Sequenceable; | Deleted|
| ohos.application.uriPermissionManager | uriPermissionManager | verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback\<number>): void;<br>verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise\<number>; | Deleted|
| FormExtensionContext | FormExtensionContext | updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void;<br>updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>; | Deleted|
| ServiceExtensionContext | ServiceExtensionContext | extensionAbilityInfo: ExtensionAbilityInfo; | Deleted|
| ohos.application.appManager | appManager | getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;<br>getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void; | Deprecated|
| ohos.application.Ability | Ability | old : onNewWant(want: Want): void;<br>new : onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void; | Updated|
| ohos.application.Ability | Callee | old : on(method: string, callback: CaleeCallBack): void;<br>new : on(method: string, callback: CalleeCallBack): void; | Updated|