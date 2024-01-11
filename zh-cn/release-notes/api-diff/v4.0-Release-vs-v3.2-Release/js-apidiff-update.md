| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|访问级别有变化|类名：update;<br>方法or属性：function getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater;<br>旧版本信息：|类名：update;<br>方法or属性：function getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：update;<br>方法or属性：function getRestorer(): Restorer;<br>旧版本信息：|类名：update;<br>方法or属性：function getRestorer(): Restorer;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：update;<br>方法or属性：function getLocalUpdater(): LocalUpdater;<br>旧版本信息：|类名：update;<br>方法or属性：function getLocalUpdater(): LocalUpdater;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getNewVersionDescription(<br>      versionDigestInfo: VersionDigestInfo,<br>      descriptionOptions: DescriptionOptions,<br>      callback: AsyncCallback\<Array\<ComponentDescription>><br>    ): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionDescription(<br>      versionDigestInfo: VersionDigestInfo,<br>      descriptionOptions: DescriptionOptions,<br>      callback: AsyncCallback\<Array\<ComponentDescription>><br>    ): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getNewVersionDescription(<br>      versionDigestInfo: VersionDigestInfo,<br>      descriptionOptions: DescriptionOptions<br>    ): Promise\<Array\<ComponentDescription>>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionDescription(<br>      versionDigestInfo: VersionDigestInfo,<br>      descriptionOptions: DescriptionOptions<br>    ): Promise\<Array\<ComponentDescription>>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getCurrentVersionInfo(): Promise\<CurrentVersionInfo>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getCurrentVersionInfo(): Promise\<CurrentVersionInfo>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getCurrentVersionDescription(<br>      descriptionOptions: DescriptionOptions,<br>      callback: AsyncCallback\<Array\<ComponentDescription>><br>    ): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getCurrentVersionDescription(<br>      descriptionOptions: DescriptionOptions,<br>      callback: AsyncCallback\<Array\<ComponentDescription>><br>    ): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getTaskInfo(): Promise\<TaskInfo>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getTaskInfo(): Promise\<TaskInfo>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：download(<br>      versionDigestInfo: VersionDigestInfo,<br>      downloadOptions: DownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(<br>      versionDigestInfo: VersionDigestInfo,<br>      downloadOptions: DownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：resumeDownload(<br>      versionDigestInfo: VersionDigestInfo,<br>      resumeDownloadOptions: ResumeDownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：resumeDownload(<br>      versionDigestInfo: VersionDigestInfo,<br>      resumeDownloadOptions: ResumeDownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：pauseDownload(<br>      versionDigestInfo: VersionDigestInfo,<br>      pauseDownloadOptions: PauseDownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：pauseDownload(<br>      versionDigestInfo: VersionDigestInfo,<br>      pauseDownloadOptions: PauseDownloadOptions,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：getUpgradePolicy(): Promise\<UpgradePolicy>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getUpgradePolicy(): Promise\<UpgradePolicy>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：terminateUpgrade(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：terminateUpgrade(callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：terminateUpgrade(): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：terminateUpgrade(): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Updater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Restorer;<br>方法or属性：factoryReset(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Restorer;<br>方法or属性：factoryReset(callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Restorer;<br>方法or属性：factoryReset(): Promise\<void>;<br>旧版本信息：|类名：Restorer;<br>方法or属性：factoryReset(): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>;<br>旧版本信息：|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeInfo;<br>方法or属性：export interface UpgradeInfo<br>旧版本信息：|类名：UpgradeInfo;<br>方法or属性：export interface UpgradeInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeInfo;<br>方法or属性：upgradeApp: string;<br>旧版本信息：|类名：UpgradeInfo;<br>方法or属性：upgradeApp: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeInfo;<br>方法or属性：businessType: BusinessType;<br>旧版本信息：|类名：UpgradeInfo;<br>方法or属性：businessType: BusinessType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessType;<br>方法or属性：export interface BusinessType<br>旧版本信息：|类名：BusinessType;<br>方法or属性：export interface BusinessType<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessType;<br>方法or属性：vendor: BusinessVendor;<br>旧版本信息：|类名：BusinessType;<br>方法or属性：vendor: BusinessVendor;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessType;<br>方法or属性：subType: BusinessSubType;<br>旧版本信息：|类名：BusinessType;<br>方法or属性：subType: BusinessSubType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CheckResult;<br>方法or属性：export interface CheckResult<br>旧版本信息：|类名：CheckResult;<br>方法or属性：export interface CheckResult<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CheckResult;<br>方法or属性：isExistNewVersion: boolean;<br>旧版本信息：|类名：CheckResult;<br>方法or属性：isExistNewVersion: boolean;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CheckResult;<br>方法or属性：newVersionInfo: NewVersionInfo;<br>旧版本信息：|类名：CheckResult;<br>方法or属性：newVersionInfo: NewVersionInfo;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NewVersionInfo;<br>方法or属性：export interface NewVersionInfo<br>旧版本信息：|类名：NewVersionInfo;<br>方法or属性：export interface NewVersionInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NewVersionInfo;<br>方法or属性：versionDigestInfo: VersionDigestInfo;<br>旧版本信息：|类名：NewVersionInfo;<br>方法or属性：versionDigestInfo: VersionDigestInfo;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：versionDigestInfo: VersionDigestInfo;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：versionDigestInfo: VersionDigestInfo;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NewVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>旧版本信息：|类名：NewVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CurrentVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>旧版本信息：|类名：CurrentVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：versionComponents: Array\<VersionComponent>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionDigestInfo;<br>方法or属性：export interface VersionDigestInfo<br>旧版本信息：|类名：VersionDigestInfo;<br>方法or属性：export interface VersionDigestInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionDigestInfo;<br>方法or属性：versionDigest: string;<br>旧版本信息：|类名：VersionDigestInfo;<br>方法or属性：versionDigest: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：export interface VersionComponent<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：export interface VersionComponent<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：componentId: string;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：componentId: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ComponentDescription;<br>方法or属性：componentId: string;<br>旧版本信息：|类名：ComponentDescription;<br>方法or属性：componentId: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：componentType: ComponentType;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：componentType: ComponentType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：upgradeAction: UpgradeAction;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：upgradeAction: UpgradeAction;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：displayVersion: string;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：displayVersion: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：innerVersion: string;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：innerVersion: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：size: number;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：size: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：effectiveMode: EffectiveMode;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：effectiveMode: EffectiveMode;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：VersionComponent;<br>方法or属性：descriptionInfo: DescriptionInfo;<br>旧版本信息：|类名：VersionComponent;<br>方法or属性：descriptionInfo: DescriptionInfo;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ComponentDescription;<br>方法or属性：descriptionInfo: DescriptionInfo;<br>旧版本信息：|类名：ComponentDescription;<br>方法or属性：descriptionInfo: DescriptionInfo;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionOptions;<br>方法or属性：export interface DescriptionOptions<br>旧版本信息：|类名：DescriptionOptions;<br>方法or属性：export interface DescriptionOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionOptions;<br>方法or属性：format: DescriptionFormat;<br>旧版本信息：|类名：DescriptionOptions;<br>方法or属性：format: DescriptionFormat;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionOptions;<br>方法or属性：language: string;<br>旧版本信息：|类名：DescriptionOptions;<br>方法or属性：language: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ComponentDescription;<br>方法or属性：export interface ComponentDescription<br>旧版本信息：|类名：ComponentDescription;<br>方法or属性：export interface ComponentDescription<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionInfo;<br>方法or属性：export interface DescriptionInfo<br>旧版本信息：|类名：DescriptionInfo;<br>方法or属性：export interface DescriptionInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionInfo;<br>方法or属性：descriptionType: DescriptionType;<br>旧版本信息：|类名：DescriptionInfo;<br>方法or属性：descriptionType: DescriptionType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionInfo;<br>方法or属性：content: string;<br>旧版本信息：|类名：DescriptionInfo;<br>方法or属性：content: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CurrentVersionInfo;<br>方法or属性：export interface CurrentVersionInfo<br>旧版本信息：|类名：CurrentVersionInfo;<br>方法or属性：export interface CurrentVersionInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CurrentVersionInfo;<br>方法or属性：osVersion: string;<br>旧版本信息：|类名：CurrentVersionInfo;<br>方法or属性：osVersion: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：CurrentVersionInfo;<br>方法or属性：deviceName: string;<br>旧版本信息：|类名：CurrentVersionInfo;<br>方法or属性：deviceName: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DownloadOptions;<br>方法or属性：export interface DownloadOptions<br>旧版本信息：|类名：DownloadOptions;<br>方法or属性：export interface DownloadOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DownloadOptions;<br>方法or属性：allowNetwork: NetType;<br>旧版本信息：|类名：DownloadOptions;<br>方法or属性：allowNetwork: NetType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ResumeDownloadOptions;<br>方法or属性：allowNetwork: NetType;<br>旧版本信息：|类名：ResumeDownloadOptions;<br>方法or属性：allowNetwork: NetType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DownloadOptions;<br>方法or属性：order: Order;<br>旧版本信息：|类名：DownloadOptions;<br>方法or属性：order: Order;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeOptions;<br>方法or属性：order: Order;<br>旧版本信息：|类名：UpgradeOptions;<br>方法or属性：order: Order;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ResumeDownloadOptions;<br>方法or属性：export interface ResumeDownloadOptions<br>旧版本信息：|类名：ResumeDownloadOptions;<br>方法or属性：export interface ResumeDownloadOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：PauseDownloadOptions;<br>方法or属性：export interface PauseDownloadOptions<br>旧版本信息：|类名：PauseDownloadOptions;<br>方法or属性：export interface PauseDownloadOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：PauseDownloadOptions;<br>方法or属性：isAllowAutoResume: boolean;<br>旧版本信息：|类名：PauseDownloadOptions;<br>方法or属性：isAllowAutoResume: boolean;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeOptions;<br>方法or属性：export interface UpgradeOptions<br>旧版本信息：|类名：UpgradeOptions;<br>方法or属性：export interface UpgradeOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ClearOptions;<br>方法or属性：export interface ClearOptions<br>旧版本信息：|类名：ClearOptions;<br>方法or属性：export interface ClearOptions<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ClearOptions;<br>方法or属性：status: UpgradeStatus;<br>旧版本信息：|类名：ClearOptions;<br>方法or属性：status: UpgradeStatus;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：status: UpgradeStatus;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：status: UpgradeStatus;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePolicy;<br>方法or属性：export interface UpgradePolicy<br>旧版本信息：|类名：UpgradePolicy;<br>方法or属性：export interface UpgradePolicy<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePolicy;<br>方法or属性：downloadStrategy: boolean;<br>旧版本信息：|类名：UpgradePolicy;<br>方法or属性：downloadStrategy: boolean;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePolicy;<br>方法or属性：autoUpgradeStrategy: boolean;<br>旧版本信息：|类名：UpgradePolicy;<br>方法or属性：autoUpgradeStrategy: boolean;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePolicy;<br>方法or属性：autoUpgradePeriods: Array\<UpgradePeriod>;<br>旧版本信息：|类名：UpgradePolicy;<br>方法or属性：autoUpgradePeriods: Array\<UpgradePeriod>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePeriod;<br>方法or属性：export interface UpgradePeriod<br>旧版本信息：|类名：UpgradePeriod;<br>方法or属性：export interface UpgradePeriod<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePeriod;<br>方法or属性：start: number;<br>旧版本信息：|类名：UpgradePeriod;<br>方法or属性：start: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradePeriod;<br>方法or属性：end: number;<br>旧版本信息：|类名：UpgradePeriod;<br>方法or属性：end: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskInfo;<br>方法or属性：export interface TaskInfo<br>旧版本信息：|类名：TaskInfo;<br>方法or属性：export interface TaskInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskInfo;<br>方法or属性：existTask: boolean;<br>旧版本信息：|类名：TaskInfo;<br>方法or属性：existTask: boolean;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskInfo;<br>方法or属性：taskBody: TaskBody;<br>旧版本信息：|类名：TaskInfo;<br>方法or属性：taskBody: TaskBody;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventInfo;<br>方法or属性：taskBody: TaskBody;<br>旧版本信息：|类名：EventInfo;<br>方法or属性：taskBody: TaskBody;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventInfo;<br>方法or属性：export interface EventInfo<br>旧版本信息：|类名：EventInfo;<br>方法or属性：export interface EventInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventInfo;<br>方法or属性：eventId: EventId;<br>旧版本信息：|类名：EventInfo;<br>方法or属性：eventId: EventId;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：export interface TaskBody<br>旧版本信息：|类名：TaskBody;<br>方法or属性：export interface TaskBody<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：subStatus: number;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：subStatus: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：progress: number;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：progress: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：installMode: number;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：installMode: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：TaskBody;<br>方法or属性：errorMessages: Array\<ErrorMessage>;<br>旧版本信息：|类名：TaskBody;<br>方法or属性：errorMessages: Array\<ErrorMessage>;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ErrorMessage;<br>方法or属性：export interface ErrorMessage<br>旧版本信息：|类名：ErrorMessage;<br>方法or属性：export interface ErrorMessage<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ErrorMessage;<br>方法or属性：errorCode: number;<br>旧版本信息：|类名：ErrorMessage;<br>方法or属性：errorCode: number;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ErrorMessage;<br>方法or属性：errorMessage: string;<br>旧版本信息：|类名：ErrorMessage;<br>方法or属性：errorMessage: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventClassifyInfo;<br>方法or属性：export interface EventClassifyInfo<br>旧版本信息：|类名：EventClassifyInfo;<br>方法or属性：export interface EventClassifyInfo<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventClassifyInfo;<br>方法or属性：eventClassify: EventClassify;<br>旧版本信息：|类名：EventClassifyInfo;<br>方法or属性：eventClassify: EventClassify;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventClassifyInfo;<br>方法or属性：extraInfo: string;<br>旧版本信息：|类名：EventClassifyInfo;<br>方法or属性：extraInfo: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeFile;<br>方法or属性：export interface UpgradeFile<br>旧版本信息：|类名：UpgradeFile;<br>方法or属性：export interface UpgradeFile<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeFile;<br>方法or属性：fileType: ComponentType;<br>旧版本信息：|类名：UpgradeFile;<br>方法or属性：fileType: ComponentType;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeFile;<br>方法or属性：filePath: string;<br>旧版本信息：|类名：UpgradeFile;<br>方法or属性：filePath: string;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeTaskCallback;<br>方法or属性：export interface UpgradeTaskCallback<br>旧版本信息：|类名：UpgradeTaskCallback;<br>方法or属性：export interface UpgradeTaskCallback<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeTaskCallback;<br>方法or属性：(eventInfo: EventInfo): void;<br>旧版本信息：|类名：UpgradeTaskCallback;<br>方法or属性：(eventInfo: EventInfo): void;<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessVendor;<br>方法or属性：export enum BusinessVendor<br>旧版本信息：|类名：BusinessVendor;<br>方法or属性：export enum BusinessVendor<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessVendor;<br>方法or属性：PUBLIC = 'public'<br>旧版本信息：|类名：BusinessVendor;<br>方法or属性：PUBLIC = 'public'<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessSubType;<br>方法or属性：export enum BusinessSubType<br>旧版本信息：|类名：BusinessSubType;<br>方法or属性：export enum BusinessSubType<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：BusinessSubType;<br>方法or属性：FIRMWARE = 1<br>旧版本信息：|类名：BusinessSubType;<br>方法or属性：FIRMWARE = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ComponentType;<br>方法or属性：export enum ComponentType<br>旧版本信息：|类名：ComponentType;<br>方法or属性：export enum ComponentType<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：ComponentType;<br>方法or属性：OTA = 1<br>旧版本信息：|类名：ComponentType;<br>方法or属性：OTA = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeAction;<br>方法or属性：export enum UpgradeAction<br>旧版本信息：|类名：UpgradeAction;<br>方法or属性：export enum UpgradeAction<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeAction;<br>方法or属性：UPGRADE = 'upgrade'<br>旧版本信息：|类名：UpgradeAction;<br>方法or属性：UPGRADE = 'upgrade'<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeAction;<br>方法or属性：RECOVERY = 'recovery'<br>旧版本信息：|类名：UpgradeAction;<br>方法or属性：RECOVERY = 'recovery'<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EffectiveMode;<br>方法or属性：export enum EffectiveMode<br>旧版本信息：|类名：EffectiveMode;<br>方法or属性：export enum EffectiveMode<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EffectiveMode;<br>方法or属性：COLD = 1<br>旧版本信息：|类名：EffectiveMode;<br>方法or属性：COLD = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EffectiveMode;<br>方法or属性：LIVE = 2<br>旧版本信息：|类名：EffectiveMode;<br>方法or属性：LIVE = 2<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EffectiveMode;<br>方法or属性：LIVE_AND_COLD = 3<br>旧版本信息：|类名：EffectiveMode;<br>方法or属性：LIVE_AND_COLD = 3<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionType;<br>方法or属性：export enum DescriptionType<br>旧版本信息：|类名：DescriptionType;<br>方法or属性：export enum DescriptionType<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionType;<br>方法or属性：CONTENT = 0<br>旧版本信息：|类名：DescriptionType;<br>方法or属性：CONTENT = 0<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionType;<br>方法or属性：URI = 1<br>旧版本信息：|类名：DescriptionType;<br>方法or属性：URI = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionFormat;<br>方法or属性：export enum DescriptionFormat<br>旧版本信息：|类名：DescriptionFormat;<br>方法or属性：export enum DescriptionFormat<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionFormat;<br>方法or属性：STANDARD = 0<br>旧版本信息：|类名：DescriptionFormat;<br>方法or属性：STANDARD = 0<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：DescriptionFormat;<br>方法or属性：SIMPLIFIED = 1<br>旧版本信息：|类名：DescriptionFormat;<br>方法or属性：SIMPLIFIED = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：export enum NetType<br>旧版本信息：|类名：NetType;<br>方法or属性：export enum NetType<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：CELLULAR = 1<br>旧版本信息：|类名：NetType;<br>方法or属性：CELLULAR = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：METERED_WIFI = 2<br>旧版本信息：|类名：NetType;<br>方法or属性：METERED_WIFI = 2<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：NOT_METERED_WIFI = 4<br>旧版本信息：|类名：NetType;<br>方法or属性：NOT_METERED_WIFI = 4<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：WIFI = 6<br>旧版本信息：|类名：NetType;<br>方法or属性：WIFI = 6<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：NetType;<br>方法or属性：CELLULAR_AND_WIFI = 7<br>旧版本信息：|类名：NetType;<br>方法or属性：CELLULAR_AND_WIFI = 7<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：export enum Order<br>旧版本信息：|类名：Order;<br>方法or属性：export enum Order<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：DOWNLOAD = 1<br>旧版本信息：|类名：Order;<br>方法or属性：DOWNLOAD = 1<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：INSTALL = 2<br>旧版本信息：|类名：Order;<br>方法or属性：INSTALL = 2<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：DOWNLOAD_AND_INSTALL = 3<br>旧版本信息：|类名：Order;<br>方法or属性：DOWNLOAD_AND_INSTALL = 3<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：APPLY = 4<br>旧版本信息：|类名：Order;<br>方法or属性：APPLY = 4<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：Order;<br>方法or属性：INSTALL_AND_APPLY = 6<br>旧版本信息：|类名：Order;<br>方法or属性：INSTALL_AND_APPLY = 6<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：export enum UpgradeStatus<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：export enum UpgradeStatus<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：WAITING_DOWNLOAD = 20<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：WAITING_DOWNLOAD = 20<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：DOWNLOADING = 21<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：DOWNLOADING = 21<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_PAUSED = 22<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_PAUSED = 22<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_FAIL = 23<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_FAIL = 23<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：WAITING_INSTALL = 30<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：WAITING_INSTALL = 30<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：UPDATING = 31<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：UPDATING = 31<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：WAITING_APPLY = 40<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：WAITING_APPLY = 40<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：APPLYING = 41<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：APPLYING = 41<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：UPGRADE_SUCCESS = 50<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：UPGRADE_SUCCESS = 50<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：UpgradeStatus;<br>方法or属性：UPGRADE_FAIL = 51<br>旧版本信息：|类名：UpgradeStatus;<br>方法or属性：UPGRADE_FAIL = 51<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventClassify;<br>方法or属性：export enum EventClassify<br>旧版本信息：|类名：EventClassify;<br>方法or属性：export enum EventClassify<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventClassify;<br>方法or属性：TASK = 0x01000000<br>旧版本信息：|类名：EventClassify;<br>方法or属性：TASK = 0x01000000<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：export enum EventId<br>旧版本信息：|类名：EventId;<br>方法or属性：export enum EventId<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_TASK_BASE = EventClassify.TASK<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_TASK_BASE = EventClassify.TASK<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_TASK_RECEIVE<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_TASK_RECEIVE<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_TASK_CANCEL<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_TASK_CANCEL<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_WAIT<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_WAIT<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_START<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_START<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_UPDATE<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_UPDATE<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_PAUSE<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_PAUSE<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_RESUME<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_RESUME<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_SUCCESS<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_SUCCESS<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_FAIL<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_FAIL<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_UPGRADE_WAIT<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_UPGRADE_WAIT<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_UPGRADE_START<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_UPGRADE_START<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_UPGRADE_UPDATE<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_UPGRADE_UPDATE<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_APPLY_WAIT<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_APPLY_WAIT<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_APPLY_START<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_APPLY_START<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_UPGRADE_SUCCESS<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_UPGRADE_SUCCESS<br>新版本信息：systemapi|@ohos.update.d.ts|
|访问级别有变化|类名：EventId;<br>方法or属性：EVENT_UPGRADE_FAIL<br>旧版本信息：|类名：EventId;<br>方法or属性：EVENT_UPGRADE_FAIL<br>新版本信息：systemapi|@ohos.update.d.ts|
