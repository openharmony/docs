# Ability Subsystem ChangeLog

## cl.ability.1 System API Usage Rule Change

System application verification is not performed for system APIs provided by the ability when they are called. The APIs can be used by a third-party application using the full SDK, which brings security risks. Therefore, application identity verification is added to OpenHarmony 4.0.2.1 and later versions.

**Change Impacts**

System APIs are available to only system applications. When a third-party application tries to use a system API, the **202** error will be returned via either an exception or asynchronous callback.

**Key API/Component Changes**

Below are the system APIs.

| Module                                | API                                                        | Error Code Return Mode|
| -------------------------------------- | ------------------------------------------------------------ | -------------- |
| @ohos.app.ability.abilityManager.d.ts  | updateConfiguration(config: Configuration, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | updateConfiguration(config: Configuration): Promise<void>    | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | getAbilityRunningInfos(): Promise<Array<AbilityRunningInfo>> | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | getAbilityRunningInfos(callback: AsyncCallback<Array<AbilityRunningInfo>>): void | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | getExtensionRunningInfos(upperLimit: number): Promise<Array<ExtensionRunningInfo>> | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback<Array<ExtensionRunningInfo>>): void | Asynchronous callback      |
| @ohos.app.ability.abilityManager.d.ts  | getTopAbility(): Promise<ElementName>                        | Exception        |
| @ohos.app.ability.abilityManager.d.ts  | getTopAbility(callback: AsyncCallback<ElementName>): void    | Exception        |
| @ohos.app.ability.appManager.d.ts      | on(type: "applicationState", observer: ApplicationStateObserver): number | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | on(type: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array<string>): number | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | off(type: "applicationState", observerId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | off(type: "applicationState", observerId: number): Promise<void> | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | getForegroundApplications(callback: AsyncCallback<Array<AppStateData>>): void | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | getForegroundApplications(): Promise<Array<AppStateData>>    | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | killProcessWithAccount(bundleName: string, accountId: number): Promise<void> | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | killProcessesByBundleName(bundleName: string): Promise<void> | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | killProcessesByBundleName(bundleName: string, callback: AsyncCallback<void>) | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | clearUpApplicationData(bundleName: string): Promise<void>    | Asynchronous callback      |
| @ohos.app.ability.appManager.d.ts      | clearUpApplicationData(bundleName: string, callback: AsyncCallback<void>) | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | on(type: "mission", listener: MissionListener): number       | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | off(type: "mission", listenerId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | off(type: "mission", listenerId: number): Promise<void>      | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback<MissionInfo>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionInfo(deviceId: string, missionId: number): Promise<MissionInfo> | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback<Array<MissionInfo>>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionInfos(deviceId: string, numMax: number): Promise<Array<MissionInfo>> | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot> | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot> | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | lockMission(missionId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | lockMission(missionId: number): Promise<void>                | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | unlockMission(missionId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | unlockMission(missionId: number): Promise<void>              | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | clearMission(missionId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | clearMission(missionId: number): Promise<void>               | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | clearAllMissions(callback: AsyncCallback<void>): void        | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | clearAllMissions(): Promise<void>                            | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | moveMissionToFront(missionId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.missionManager.d.ts  | moveMissionToFront(missionId: number, options?: StartOptions): Promise<void> | Asynchronous callback      |
| @ohos.app.ability.quickFixManager.d.ts | applyQuickFix(hapModuleQuickFixFiles: Array<string>, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.ability.quickFixManager.d.ts | applyQuickFix(hapModuleQuickFixFiles: Array<string>): Promise<void> | Asynchronous callback      |
| @ohos.app.ability.quickFixManager.d.ts | getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback<ApplicationQuickFixInfo>): void | Asynchronous callback      |
| @ohos.app.ability.quickFixManager.d.ts | getApplicationQuickFixInfo(bundleName: string): Promise<ApplicationQuickFixInfo> | Asynchronous callback      |
| @ohos.app.ability.wantAgent.d.ts       | getWant(agent: WantAgent, callback: AsyncCallback<Want>): void | Asynchronous callback      |
| @ohos.app.ability.wantAgent.d.ts       | getWant(agent: WantAgent): Promise<Want>                     | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | deleteForm(formId: string, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | deleteForm(formId: string): Promise<void>                    | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | releaseForm(formId: string, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | releaseForm(formId: string, isReleaseCache?: boolean): Promise<void> | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | requestForm(formId: string, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | requestForm(formId: string): Promise<void>                   | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | castToNormalForm(formId: string, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | castToNormalForm(formId: string): Promise<void>              | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyVisibleForms(formIds: Array<string>, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyVisibleForms(formIds: Array<string>): Promise<void>    | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyInvisibleForms(formIds: Array<string>, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyInvisibleForms(formIds: Array<string>): Promise<void>  | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | enableFormsUpdate(formIds: Array<string>, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | enableFormsUpdate(formIds: Array<string>): Promise<void>     | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | disableFormsUpdate(formIds: Array<string>, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | disableFormsUpdate(formIds: Array<string>): Promise<void>    | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | isSystemReady(callback: AsyncCallback<void>): void           | Exception        |
| @ohos.app.form.formHost.d.ts           | isSystemReady(): Promise<void>                               | Exception        |
| @ohos.app.form.formHost.d.ts           | getAllFormsInfo(callback: AsyncCallback<Array<formInfo.FormInfo>>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | getAllFormsInfo(): Promise<Array<formInfo.FormInfo>>         | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | getFormsInfo(bundleName: string, callback: AsyncCallback<Array<formInfo.FormInfo>>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback<Array<formInfo.FormInfo>>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | getFormsInfo(bundleName: string, moduleName?: string): Promise<Array<formInfo.FormInfo>> | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | deleteInvalidForms(formIds: Array<string>, callback: AsyncCallback<number>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | deleteInvalidForms(formIds: Array<string>): Promise<number>  | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | acquireFormState(want: Want, callback: AsyncCallback<formInfo.FormStateInfo>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | acquireFormState(want: Want): Promise<formInfo.FormStateInfo> | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | on(type: "formUninstall", callback: Callback<string>): void  | Exception        |
| @ohos.app.form.formHost.d.ts           | off(type: "formUninstall", callback?: Callback<string>): void | Exception        |
| @ohos.app.form.formHost.d.ts           | notifyFormsVisible(formIds: Array<string>, isVisible: boolean, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyFormsVisible(formIds: Array<string>, isVisible: boolean): Promise<void> | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyFormsEnableUpdate(formIds: Array<string>, isEnableUpdate: boolean, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyFormsEnableUpdate(formIds: Array<string>, isEnableUpdate: boolean): Promise<void> | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | shareForm(formId: string, deviceId: string, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | shareForm(formId: string, deviceId: string): Promise<void>   | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean, callback: AsyncCallback<void>): void | Asynchronous callback      |
| @ohos.app.form.formHost.d.ts           | notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean): Promise<void> | Asynchronous callback      |
| @ohos.app.form.formProvider.d.ts       | requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback<string>): void | Asynchronous callback      |
| @ohos.app.form.formProvider.d.ts       | requestPublishForm(want: Want, callback: AsyncCallback<string>): void | Asynchronous callback      |
| @ohos.app.form.formProvider.d.ts       | requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise<string> | Asynchronous callback      |
| @ohos.app.form.formProvider.d.ts       | isRequestPublishFormSupported(callback: AsyncCallback<boolean>): void | Exception        |
| @ohos.app.form.formProvider.d.ts       | isRequestPublishFormSupported(): Promise<boolean>            | Exception        |
| UIAbilityContext.d.ts                  | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void> | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void | Exception        |
| UIAbilityContext.d.ts                  | startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<AbilityResult>): void | Exception        |
| UIAbilityContext.d.ts                  | startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult> | Exception        |
| UIAbilityContext.d.ts                  | startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startServiceExtensionAbility(want: Want): Promise<void>      | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void> | Asynchronous callback      |
| UIAbilityContext.d.ts                  | stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | stopServiceExtensionAbility(want: Want): Promise<void>       | Asynchronous callback      |
| UIAbilityContext.d.ts                  | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void> | Asynchronous callback      |
| UIAbilityContext.d.ts                  | connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number | Asynchronous callback      |
| UIAbilityContext.d.ts                  | setMissionIcon(icon: image.PixelMap, callback: AsyncCallback<void>): void | Asynchronous callback      |
| UIAbilityContext.d.ts                  | setMissionIcon(icon: image.PixelMap): Promise<void>          | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void> | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startServiceExtensionAbility(want: Want): Promise<void>      | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void> | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | stopServiceExtensionAbility(want: Want): Promise<void>       | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void> | Asynchronous callback      |
| ServiceExtensionContext.d.ts           | connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number | Asynchronous callback      |
| Context.d.ts                           | createBundleContext(bundleName: string): Context             | Exception        |
| Context.d.ts                           | createModuleContext(bundleName: string, moduleName: string): Context | Exception        |
| FormExtensionContext.d.ts              | startAbility(want: Want, callback: AsyncCallback<void>): void | Asynchronous callback      |
| FormExtensionContext.d.ts              | startAbility(want: Want): Promise<void>                      | Asynchronous callback      |
