# 元能力子系统ChangeLog

## cl.ability.1 SystemAPI使用规则变更

目前元能力提供的system-api在调用时未做系统应用校验，三方应用使用Full版本的SDK就可以使用这些system-api，存在安全隐患，因此在OpenHarmony 4.0.2.1版本开始增加应用身份校验。

**变更影响**

只有系统应用允许使用system-api，三方应用使用system-api将返回202错误，返回202错误的方式有两种：1.抛异常；2.异步回调

**关键接口/组件变更**

system-api列表如下所示。

| 模块名                                     | 方法                                                                               |  返回错误码方式 |
| ------------------------------------------ | --------------------------------------------------------------------------------- | -------------- |
| @ohos.app.ability.abilityManager.d.ts      | updateConfiguration(config: Configuration, callback: AsyncCallback<void>): void   | 异步回调        |
| @ohos.app.ability.abilityManager.d.ts      | updateConfiguration(config: Configuration): Promise<void>                         | 异步回调        |
| @ohos.app.ability.abilityManager.d.ts      | getAbilityRunningInfos(): Promise<Array<AbilityRunningInfo>>                      | 异步回调        |
| @ohos.app.ability.abilityManager.d.ts      | getAbilityRunningInfos(callback: AsyncCallback<Array<AbilityRunningInfo>>): void  | 异步回调        |
| @ohos.app.ability.abilityManager.d.ts      | getExtensionRunningInfos(upperLimit: number): Promise<Array<ExtensionRunningInfo>>  | 异步回调        |
| @ohos.app.ability.abilityManager.d.ts      | getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback<Array<ExtensionRunningInfo>>): void  | 异步回调 |
| @ohos.app.ability.abilityManager.d.ts      | getTopAbility(): Promise<ElementName>                                             | 抛异常        |
| @ohos.app.ability.abilityManager.d.ts      | getTopAbility(callback: AsyncCallback<ElementName>): void                         | 抛异常        |
| @ohos.app.ability.appManager.d.ts          | on(type: "applicationState", observer: ApplicationStateObserver): number          | 异步回调        |
| @ohos.app.ability.appManager.d.ts          | on(type: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array<string>): number   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | off(type: "applicationState", observerId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | off(type: "applicationState", observerId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | getForegroundApplications(callback: AsyncCallback<Array<AppStateData>>): void   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | getForegroundApplications(): Promise<Array<AppStateData>>   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | killProcessWithAccount(bundleName: string, accountId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | killProcessesByBundleName(bundleName: string): Promise<void>   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | killProcessesByBundleName(bundleName: string, callback: AsyncCallback<void>)   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | clearUpApplicationData(bundleName: string): Promise<void>   | 异步回调 |
| @ohos.app.ability.appManager.d.ts          | clearUpApplicationData(bundleName: string, callback: AsyncCallback<void>)   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | on(type: "mission", listener: MissionListener): number   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | off(type: "mission", listenerId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | off(type: "mission", listenerId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback<MissionInfo>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionInfo(deviceId: string, missionId: number): Promise<MissionInfo>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback<Array<MissionInfo>>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionInfos(deviceId: string, numMax: number): Promise<Array<MissionInfo>>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getLowResolutionMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback<MissionSnapshot>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise<MissionSnapshot>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | lockMission(missionId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | lockMission(missionId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | unlockMission(missionId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | unlockMission(missionId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | clearMission(missionId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | clearMission(missionId: number): Promise<void>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | clearAllMissions(callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | clearAllMissions(): Promise<void>   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | moveMissionToFront(missionId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.missionManager.d.ts      | moveMissionToFront(missionId: number, options?: StartOptions): Promise<void>   | 异步回调 |
| @ohos.app.ability.quickFixManager.d.ts     | applyQuickFix(hapModuleQuickFixFiles: Array<string>, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.ability.quickFixManager.d.ts     | applyQuickFix(hapModuleQuickFixFiles: Array<string>): Promise<void>   | 异步回调 |
| @ohos.app.ability.quickFixManager.d.ts     | getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback<ApplicationQuickFixInfo>): void   | 异步回调 |
| @ohos.app.ability.quickFixManager.d.ts     | getApplicationQuickFixInfo(bundleName: string): Promise<ApplicationQuickFixInfo>   | 异步回调 |
| @ohos.app.ability.wantAgent.d.ts           | getWant(agent: WantAgent, callback: AsyncCallback<Want>): void   | 异步回调 |
| @ohos.app.ability.wantAgent.d.ts           | getWant(agent: WantAgent): Promise<Want>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | deleteForm(formId: string, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | deleteForm(formId: string): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | releaseForm(formId: string, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | releaseForm(formId: string, isReleaseCache?: boolean): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | requestForm(formId: string, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | requestForm(formId: string): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | castToNormalForm(formId: string, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | castToNormalForm(formId: string): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyVisibleForms(formIds: Array<string>, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyVisibleForms(formIds: Array<string>): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyInvisibleForms(formIds: Array<string>, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyInvisibleForms(formIds: Array<string>): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | enableFormsUpdate(formIds: Array<string>, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | enableFormsUpdate(formIds: Array<string>): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | disableFormsUpdate(formIds: Array<string>, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | disableFormsUpdate(formIds: Array<string>): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | isSystemReady(callback: AsyncCallback<void>): void   | 抛异常 |
| @ohos.app.form.formHost.d.ts               | isSystemReady(): Promise<void>   | 抛异常 |
| @ohos.app.form.formHost.d.ts               | getAllFormsInfo(callback: AsyncCallback<Array<formInfo.FormInfo>>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | getAllFormsInfo(): Promise<Array<formInfo.FormInfo>>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | getFormsInfo(bundleName: string, callback: AsyncCallback<Array<formInfo.FormInfo>>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback<Array<formInfo.FormInfo>>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | getFormsInfo(bundleName: string, moduleName?: string): Promise<Array<formInfo.FormInfo>>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | deleteInvalidForms(formIds: Array<string>, callback: AsyncCallback<number>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | deleteInvalidForms(formIds: Array<string>): Promise<number>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | acquireFormState(want: Want, callback: AsyncCallback<formInfo.FormStateInfo>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | acquireFormState(want: Want): Promise<formInfo.FormStateInfo>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | on(type: "formUninstall", callback: Callback<string>): void   | 抛异常 |
| @ohos.app.form.formHost.d.ts               | off(type: "formUninstall", callback?: Callback<string>): void   | 抛异常 |
| @ohos.app.form.formHost.d.ts               | notifyFormsVisible(formIds: Array<string>, isVisible: boolean, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyFormsVisible(formIds: Array<string>, isVisible: boolean): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyFormsEnableUpdate(formIds: Array<string>, isEnableUpdate: boolean, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyFormsEnableUpdate(formIds: Array<string>, isEnableUpdate: boolean): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | shareForm(formId: string, deviceId: string, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | shareForm(formId: string, deviceId: string): Promise<void>   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean, callback: AsyncCallback<void>): void   | 异步回调 |
| @ohos.app.form.formHost.d.ts               | notifyFormsPrivacyProtected(formIds: Array<string>, isProtected: boolean): Promise<void>   | 异步回调 |
| @ohos.app.form.formProvider.d.ts           | requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback<string>): void   | 异步回调 |
| @ohos.app.form.formProvider.d.ts           | requestPublishForm(want: Want, callback: AsyncCallback<string>): void   | 异步回调 |
| @ohos.app.form.formProvider.d.ts           | requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise<string>   | 异步回调 |
| @ohos.app.form.formProvider.d.ts           | isRequestPublishFormSupported(callback: AsyncCallback<boolean>): void   | 抛异常 |
| @ohos.app.form.formProvider.d.ts           | isRequestPublishFormSupported(): Promise<boolean>   | 抛异常 |
| UIAbilityContext.d.ts                      | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>   | 异步回调 |
| UIAbilityContext.d.ts                      | startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void   | 抛异常 |
| UIAbilityContext.d.ts                      | startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<AbilityResult>): void   | 抛异常 |
| UIAbilityContext.d.ts                      | startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult>   | 抛异常 |
| UIAbilityContext.d.ts                      | startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | startServiceExtensionAbility(want: Want): Promise<void>   | 异步回调 |
| UIAbilityContext.d.ts                      | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>   | 异步回调 |
| UIAbilityContext.d.ts                      | stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | stopServiceExtensionAbility(want: Want): Promise<void>   | 异步回调 |
| UIAbilityContext.d.ts                      | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>   | 异步回调 |
| UIAbilityContext.d.ts                      | connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number   | 异步回调 |
| UIAbilityContext.d.ts                      | setMissionIcon(icon: image.PixelMap, callback: AsyncCallback<void>): void   | 异步回调 |
| UIAbilityContext.d.ts                      | setMissionIcon(icon: image.PixelMap): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | startServiceExtensionAbility(want: Want): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | stopServiceExtensionAbility(want: Want): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void   | 异步回调 |
| ServiceExtensionContext.d.ts               | stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>   | 异步回调 |
| ServiceExtensionContext.d.ts               | connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number   | 异步回调 |
| Context.d.ts                               | createBundleContext(bundleName: string): Context   | 抛异常 |
| Context.d.ts                               | createModuleContext(bundleName: string, moduleName: string): Context   | 抛异常 |
| FormExtensionContext.d.ts                  | startAbility(want: Want, callback: AsyncCallback<void>): void   | 异步回调 |
| FormExtensionContext.d.ts                  | startAbility(want: Want): Promise<void>   | 异步回调 |
