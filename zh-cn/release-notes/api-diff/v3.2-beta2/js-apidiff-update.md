# 升级服务子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，升级服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.update | EventId | EVENT_UPGRADE_FAIL | 新增 |
| ohos.update | EventId | EVENT_UPGRADE_SUCCESS | 新增 |
| ohos.update | EventId | EVENT_APPLY_START | 新增 |
| ohos.update | EventId | EVENT_APPLY_WAIT | 新增 |
| ohos.update | EventId | EVENT_UPGRADE_UPDATE | 新增 |
| ohos.update | EventId | EVENT_UPGRADE_START | 新增 |
| ohos.update | EventId | EVENT_UPGRADE_WAIT | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_FAIL | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_SUCCESS | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_RESUME | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_PAUSE | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_UPDATE | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_START | 新增 |
| ohos.update | EventId | EVENT_DOWNLOAD_WAIT | 新增 |
| ohos.update | EventId | EVENT_TASK_CANCEL | 新增 |
| ohos.update | EventId | EVENT_TASK_RECEIVE | 新增 |
| ohos.update | EventId | EVENT_TASK_BASE = EventClassify.TASK | 新增 |
| ohos.update | EventClassify | TASK = 0x01000000 | 新增 |
| ohos.update | UpgradeStatus | UPGRADE_FAIL = 51 | 新增 |
| ohos.update | UpgradeStatus | UPGRADE_SUCCESS = 50 | 新增 |
| ohos.update | UpgradeStatus | APPLYING = 41 | 新增 |
| ohos.update | UpgradeStatus | WAITING_APPLY = 40 | 新增 |
| ohos.update | UpgradeStatus | UPDATING = 31 | 新增 |
| ohos.update | UpgradeStatus | WAITING_INSTALL = 30 | 新增 |
| ohos.update | UpgradeStatus | DOWNLOAD_FAIL = 23 | 新增 |
| ohos.update | UpgradeStatus | DOWNLOAD_PAUSED = 22 | 新增 |
| ohos.update | UpgradeStatus | DOWNLOADING = 21 | 新增 |
| ohos.update | UpgradeStatus | WAITING_DOWNLOAD = 20 | 新增 |
| ohos.update | Order | APPLY = 4 | 新增 |
| ohos.update | Order | INSTALL = 2 | 新增 |
| ohos.update | Order | DOWNLOAD = 1 | 新增 |
| ohos.update | NetType | NOT_METERED_WIFI = 4 | 新增 |
| ohos.update | NetType | METERED_WIFI = 2 | 新增 |
| ohos.update | NetType | CELLULAR = 1 | 新增 |
| ohos.update | DescriptionType | URI = 1 | 新增 |
| ohos.update | DescriptionType | CONTENT = 0 | 新增 |
| ohos.update | EffectiveMode | LIVE_AND_COLD = 3 | 新增 |
| ohos.update | EffectiveMode | LIVE = 2 | 新增 |
| ohos.update | EffectiveMode | COLD = 1 | 新增 |
| ohos.update | UpgradeAction | RECOVERY = "recovery" | 新增 |
| ohos.update | UpgradeAction | UPGRADE = "upgrade" | 新增 |
| ohos.update | ComponentType | OTA = 1 | 新增 |
| ohos.update | BusinessSubType | PARAM = 2 | 新增 |
| ohos.update | BusinessSubType | FIRMWARE = 1 | 新增 |
| ohos.update | BusinessVendor | PUBLIC = "public" | 新增 |
| ohos.update | UpgradeTaskCallback | (eventInfo: EventInfo): void; | 新增 |
| ohos.update | UpgradeFile | filePath: string; | 新增 |
| ohos.update | UpgradeFile | fileType: ComponentType; | 新增 |
| ohos.update | EventClassifyInfo | extraInfo: string; | 新增 |
| ohos.update | EventClassifyInfo | eventClassify: EventClassify; | 新增 |
| ohos.update | ErrorMessage | errorMessage: string; | 新增 |
| ohos.update | ErrorMessage | errorCode: number; | 新增 |
| ohos.update | TaskBody | versionComponents: Array\<VersionComponent>; | 新增 |
| ohos.update | TaskBody | errorMessages: Array\<ErrorMessage>; | 新增 |
| ohos.update | TaskBody | installMode: number; | 新增 |
| ohos.update | TaskBody | progress: number; | 新增 |
| ohos.update | TaskBody | subStatus: number; | 新增 |
| ohos.update | TaskBody | status: UpgradeStatus; | 新增 |
| ohos.update | TaskBody | versionDigestInfo: VersionDigestInfo; | 新增 |
| ohos.update | EventInfo | taskBody: TaskBody; | 新增 |
| ohos.update | EventInfo | eventId: EventId; | 新增 |
| ohos.update | TaskInfo | taskBody: TaskBody; | 新增 |
| ohos.update | TaskInfo | existTask: boolean; | 新增 |
| ohos.update | UpgradePeriod | end: number; | 新增 |
| ohos.update | UpgradePeriod | start: number; | 新增 |
| ohos.update | UpgradePolicy | autoUpgradePeriods: Array\<UpgradePeriod>; | 新增 |
| ohos.update | UpgradePolicy | autoUpgradeStrategy: boolean; | 新增 |
| ohos.update | UpgradePolicy | downloadStrategy: boolean; | 新增 |
| ohos.update | ClearOptions | status: UpgradeStatus; | 新增 |
| ohos.update | UpgradeOptions | order: Order; | 新增 |
| ohos.update | PauseDownloadOptions | isAllowAutoResume: boolean; | 新增 |
| ohos.update | ResumeDownloadOptions | allowNetwork: NetType; | 新增 |
| ohos.update | DownloadOptions | order: Order; | 新增 |
| ohos.update | DownloadOptions | allowNetwork: NetType; | 新增 |
| ohos.update | CurrentVersionInfo | versionComponents: Array\<VersionComponent>; | 新增 |
| ohos.update | CurrentVersionInfo | deviceName: string; | 新增 |
| ohos.update | CurrentVersionInfo | osVersion: string; | 新增 |
| ohos.update | DescriptionInfo | descriptionType: DescriptionType; | 新增 |
| ohos.update | VersionComponent | descriptionInfo: DescriptionInfo; | 新增 |
| ohos.update | VersionComponent | effectiveMode: EffectiveMode; | 新增 |
| ohos.update | VersionComponent | size: number; | 新增 |
| ohos.update | VersionComponent | innerVersion: string; | 新增 |
| ohos.update | VersionComponent | displayVersion: string; | 新增 |
| ohos.update | VersionComponent | upgradeAction: UpgradeAction; | 新增 |
| ohos.update | VersionComponent | componentType: ComponentType; | 新增 |
| ohos.update | VersionDigestInfo | versionDigest: string; | 新增 |
| ohos.update | NewVersionInfo | versionComponents: Array\<VersionComponent>; | 新增 |
| ohos.update | NewVersionInfo | versionDigestInfo: VersionDigestInfo; | 新增 |
| ohos.update | CheckResult | newVersionInfo: NewVersionInfo; | 新增 |
| ohos.update | CheckResult | isExistNewVersion: boolean; | 新增 |
| ohos.update | BusinessType | subType: BusinessSubType; | 新增 |
| ohos.update | BusinessType | vendor: BusinessVendor; | 新增 |
| ohos.update | UpgradeInfo | businessType: BusinessType; | 新增 |
| ohos.update | UpgradeInfo | upgradeApp: string; | 新增 |
| ohos.update | LocalUpdater | off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void; | 新增 |
| ohos.update | LocalUpdater | on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void; | 新增 |
| ohos.update | LocalUpdater | applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;<br>applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>; | 新增 |
| ohos.update | LocalUpdater | verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<number>): void;<br>verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<number>; | 新增 |
| ohos.update | Restorer | factoryReset(callback: AsyncCallback\<void>): void;<br>factoryReset(): Promise\<void>; | 新增 |
| ohos.update | Updater | off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void; | 新增 |
| ohos.update | Updater | on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void; | 新增 |
| ohos.update | Updater | terminateUpgrade(callback: AsyncCallback\<void>): void;<br>terminateUpgrade(): Promise\<void>; | 新增 |
| ohos.update | Updater | setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<number>): void;<br>setUpgradePolicy(policy: UpgradePolicy): Promise\<number>; | 新增 |
| ohos.update | Updater | getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;<br>getUpgradePolicy(): Promise\<UpgradePolicy>; | 新增 |
| ohos.update | Updater | clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;<br>clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>; | 新增 |
| ohos.update | Updater | pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void;<br>pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>; | 新增 |
| ohos.update | Updater | resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void;<br>resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>; | 新增 |
| ohos.update | Updater | getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;<br>getTaskInfo(): Promise\<TaskInfo>; | 新增 |
| ohos.update | Updater | getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;<br>getCurrentVersionInfo(): Promise\<CurrentVersionInfo>; | 新增 |
| ohos.update | update | getLocalUpdater(): LocalUpdater; | 新增 |
| ohos.update | update | getRestorer(): Restorer; | 新增 |
| ohos.update | update | getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater; | 新增 |
| ohos.update | update | getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater; | 删除 |
| ohos.update | update | getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater; | 删除 |
| ohos.update | update | getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater; | 删除 |
| ohos.update | Updater | cancel(): void; | 删除 |
| ohos.update | Updater | verifyUpdatePackage(upgradeFile: string, certsFile: string): void; | 删除 |
| ohos.update | Updater | rebootAndCleanUserData(callback: AsyncCallback\<number>): void;<br>rebootAndCleanUserData(): Promise\<number>; | 删除 |
| ohos.update | Updater | rebootAndCleanCache(callback: AsyncCallback\<number>): void;<br>rebootAndCleanCache(): Promise\<number>; | 删除 |
| ohos.update | Updater | applyNewVersion(callback: AsyncCallback\<number>): void;<br>applyNewVersion(): Promise\<number>; | 删除 |
| ohos.update | Updater | setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;<br>setUpdatePolicy(policy: UpdatePolicy): Promise\<number>; | 删除 |
| ohos.update | Updater | getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;<br>getUpdatePolicy(): Promise\<UpdatePolicy>; | 删除 |
| ohos.update | UpdateProgressCallback | (progress: Progress): void; | 删除 |
| ohos.update | UpdatePolicy | autoUpgradeInterval: Array\<number>; | 删除 |
| ohos.update | UpdatePolicy | installMode: INSTALL_MODE; | 删除 |
| ohos.update | UpdatePolicy | autoDownload: boolean; | 删除 |
| ohos.update | InstallMode | INSTALL_MODE_AUTO | 删除 |
| ohos.update | InstallMode | INSTALL_MODE_NIGHT | 删除 |
| ohos.update | InstallMode | INSTALL_MODE_NORMAL | 删除 |
| ohos.update | Progress | endReason: string; | 删除 |
| ohos.update | Progress | status: UpdateState; | 删除 |
| ohos.update | Progress | percent: number; | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_ON = 90 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_ON = 80 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_ON = 70 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_ON = 30 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_CANCEL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_PAUSE | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_ON = 20 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_SUCCESS | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_FAIL | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_ON = 10 | 删除 |
| ohos.update | UpdateState | UPDATE_STATE_INIT = 0 | 删除 |
| ohos.update | NewVersionInfo | descriptionInfo: Array\<DescriptionInfo>; | 删除 |
| ohos.update | NewVersionInfo | checkResults: Array\<CheckResult>; | 删除 |
| ohos.update | NewVersionInfo | errMsg: string; | 删除 |
| ohos.update | NewVersionInfo | status: NewVersionStatus; | 删除 |
| ohos.update | NewVersionStatus | VERSION_STATUS_BUSY = 2 | 删除 |
| ohos.update | NewVersionStatus | VERSION_STATUS_NONE = 1 | 删除 |
| ohos.update | NewVersionStatus | VERSION_STATUS_NEW = 0 | 删除 |
| ohos.update | NewVersionStatus | VERSION_STATUS_ERR = -1 | 删除 |
| ohos.update | DescriptionInfo | descriptionId: string; | 删除 |
| ohos.update | CheckResult | descriptionId: string; | 删除 |
| ohos.update | CheckResult | packageType: PackageTypes; | 删除 |
| ohos.update | CheckResult | verifyInfo: string; | 删除 |
| ohos.update | CheckResult | size: number; | 删除 |
| ohos.update | CheckResult | versionCode: string; | 删除 |
| ohos.update | CheckResult | versionName: number; | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_PATCH = 7 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_VERSION = 6 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_COTA = 5 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_PRELOAD = 4 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_CUST = 3 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_BASE = 2 | 删除 |
| ohos.update | PackageTypes | PACKAGE_TYPE_NORMAL = 1 | 删除 |
