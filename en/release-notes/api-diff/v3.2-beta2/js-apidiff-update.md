# JS API Changes of the Update Subsystem

The table below lists the APIs changes of the update subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.update | EventId | EVENT_UPGRADE_FAIL | Added|
| ohos.update | EventId | EVENT_UPGRADE_SUCCESS | Added|
| ohos.update | EventId | EVENT_APPLY_START | Added|
| ohos.update | EventId | EVENT_APPLY_WAIT | Added|
| ohos.update | EventId | EVENT_UPGRADE_UPDATE | Added|
| ohos.update | EventId | EVENT_UPGRADE_START | Added|
| ohos.update | EventId | EVENT_UPGRADE_WAIT | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_FAIL | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_SUCCESS | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_RESUME | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_PAUSE | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_UPDATE | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_START | Added|
| ohos.update | EventId | EVENT_DOWNLOAD_WAIT | Added|
| ohos.update | EventId | EVENT_TASK_CANCEL | Added|
| ohos.update | EventId | EVENT_TASK_RECEIVE | Added|
| ohos.update | EventId | EVENT_TASK_BASE = EventClassify.TASK | Added|
| ohos.update | EventClassify | TASK = 0x01000000 | Added|
| ohos.update | UpgradeStatus | UPGRADE_FAIL = 51 | Added|
| ohos.update | UpgradeStatus | UPGRADE_SUCCESS = 50 | Added|
| ohos.update | UpgradeStatus | APPLYING = 41 | Added|
| ohos.update | UpgradeStatus | WAITING_APPLY = 40 | Added|
| ohos.update | UpgradeStatus | UPDATING = 31 | Added|
| ohos.update | UpgradeStatus | WAITING_INSTALL = 30 | Added|
| ohos.update | UpgradeStatus | DOWNLOAD_FAIL = 23 | Added|
| ohos.update | UpgradeStatus | DOWNLOAD_PAUSED = 22 | Added|
| ohos.update | UpgradeStatus | DOWNLOADING = 21 | Added|
| ohos.update | UpgradeStatus | WAITING_DOWNLOAD = 20 | Added|
| ohos.update | Order | APPLY = 4 | Added|
| ohos.update | Order | INSTALL = 2 | Added|
| ohos.update | Order | DOWNLOAD = 1 | Added|
| ohos.update | NetType | NOT_METERED_WIFI = 4 | Added|
| ohos.update | NetType | METERED_WIFI = 2 | Added|
| ohos.update | NetType | CELLULAR = 1 | Added|
| ohos.update | DescriptionType | URI = 1 | Added|
| ohos.update | DescriptionType | CONTENT = 0 | Added|
| ohos.update | EffectiveMode | LIVE_AND_COLD = 3 | Added|
| ohos.update | EffectiveMode | LIVE = 2 | Added|
| ohos.update | EffectiveMode | COLD = 1 | Added|
| ohos.update | UpgradeAction | RECOVERY = "recovery" | Added|
| ohos.update | UpgradeAction | UPGRADE = "upgrade" | Added|
| ohos.update | ComponentType | OTA = 1 | Added|
| ohos.update | BusinessSubType | PARAM = 2 | Added|
| ohos.update | BusinessSubType | FIRMWARE = 1 | Added|
| ohos.update | BusinessVendor | PUBLIC = "public" | Added|
| ohos.update | UpgradeTaskCallback | (eventInfo: EventInfo): void; | Added|
| ohos.update | UpgradeFile | filePath: string; | Added|
| ohos.update | UpgradeFile | fileType: ComponentType; | Added|
| ohos.update | EventClassifyInfo | extraInfo: string; | Added|
| ohos.update | EventClassifyInfo | eventClassify: EventClassify; | Added|
| ohos.update | ErrorMessage | errorMessage: string; | Added|
| ohos.update | ErrorMessage | errorCode: number; | Added|
| ohos.update | TaskBody | versionComponents: Array\<VersionComponent>; | Added|
| ohos.update | TaskBody | errorMessages: Array\<ErrorMessage>; | Added|
| ohos.update | TaskBody | installMode: number; | Added|
| ohos.update | TaskBody | progress: number; | Added|
| ohos.update | TaskBody | subStatus: number; | Added|
| ohos.update | TaskBody | status: UpgradeStatus; | Added|
| ohos.update | TaskBody | versionDigestInfo: VersionDigestInfo; | Added|
| ohos.update | EventInfo | taskBody: TaskBody; | Added|
| ohos.update | EventInfo | eventId: EventId; | Added|
| ohos.update | TaskInfo | taskBody: TaskBody; | Added|
| ohos.update | TaskInfo | existTask: boolean; | Added|
| ohos.update | UpgradePeriod | end: number; | Added|
| ohos.update | UpgradePeriod | start: number; | Added|
| ohos.update | UpgradePolicy | autoUpgradePeriods: Array\<UpgradePeriod>; | Added|
| ohos.update | UpgradePolicy | autoUpgradeStrategy: boolean; | Added|
| ohos.update | UpgradePolicy | downloadStrategy: boolean; | Added|
| ohos.update | ClearOptions | status: UpgradeStatus; | Added|
| ohos.update | UpgradeOptions | order: Order; | Added|
| ohos.update | PauseDownloadOptions | isAllowAutoResume: boolean; | Added|
| ohos.update | ResumeDownloadOptions | allowNetwork: NetType; | Added|
| ohos.update | DownloadOptions | order: Order; | Added|
| ohos.update | DownloadOptions | allowNetwork: NetType; | Added|
| ohos.update | CurrentVersionInfo | versionComponents: Array\<VersionComponent>; | Added|
| ohos.update | CurrentVersionInfo | deviceName: string; | Added|
| ohos.update | CurrentVersionInfo | osVersion: string; | Added|
| ohos.update | DescriptionInfo | descriptionType: DescriptionType; | Added|
| ohos.update | VersionComponent | descriptionInfo: DescriptionInfo; | Added|
| ohos.update | VersionComponent | effectiveMode: EffectiveMode; | Added|
| ohos.update | VersionComponent | size: number; | Added|
| ohos.update | VersionComponent | innerVersion: string; | Added|
| ohos.update | VersionComponent | displayVersion: string; | Added|
| ohos.update | VersionComponent | upgradeAction: UpgradeAction; | Added|
| ohos.update | VersionComponent | componentType: ComponentType; | Added|
| ohos.update | VersionDigestInfo | versionDigest: string; | Added|
| ohos.update | NewVersionInfo | versionComponents: Array\<VersionComponent>; | Added|
| ohos.update | NewVersionInfo | versionDigestInfo: VersionDigestInfo; | Added|
| ohos.update | CheckResult | newVersionInfo: NewVersionInfo; | Added|
| ohos.update | CheckResult | isExistNewVersion: boolean; | Added|
| ohos.update | BusinessType | subType: BusinessSubType; | Added|
| ohos.update | BusinessType | vendor: BusinessVendor; | Added|
| ohos.update | UpgradeInfo | businessType: BusinessType; | Added|
| ohos.update | UpgradeInfo | upgradeApp: string; | Added|
| ohos.update | LocalUpdater | off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void; | Added|
| ohos.update | LocalUpdater | on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void; | Added|
| ohos.update | LocalUpdater | applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;<br>applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>; | Added|
| ohos.update | LocalUpdater | verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<number>): void;<br>verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<number>; | Added|
| ohos.update | Restorer | factoryReset(callback: AsyncCallback\<void>): void;<br>factoryReset(): Promise\<void>; | Added|
| ohos.update | Updater | off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void; | Added|
| ohos.update | Updater | on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void; | Added|
| ohos.update | Updater | terminateUpgrade(callback: AsyncCallback\<void>): void;<br>terminateUpgrade(): Promise\<void>; | Added|
| ohos.update | Updater | setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<number>): void;<br>setUpgradePolicy(policy: UpgradePolicy): Promise\<number>; | Added|
| ohos.update | Updater | getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;<br>getUpgradePolicy(): Promise\<UpgradePolicy>; | Added|
| ohos.update | Updater | clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;<br>clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>; | Added|
| ohos.update | Updater | pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void;<br>pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>; | Added|
| ohos.update | Updater | resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void;<br>resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>; | Added|
| ohos.update | Updater | getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;<br>getTaskInfo(): Promise\<TaskInfo>; | Added|
| ohos.update | Updater | getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;<br>getCurrentVersionInfo(): Promise\<CurrentVersionInfo>; | Added|
| ohos.update | update | getLocalUpdater(): LocalUpdater; | Added|
| ohos.update | update | getRestorer(): Restorer; | Added|
| ohos.update | update | getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater; | Added|
| ohos.update | update | getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater; | Deleted|
| ohos.update | update | getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater; | Deleted|
| ohos.update | update | getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater; | Deleted|
| ohos.update | Updater | cancel(): void; | Deleted|
| ohos.update | Updater | verifyUpdatePackage(upgradeFile: string, certsFile: string): void; | Deleted|
| ohos.update | Updater | rebootAndCleanUserData(callback: AsyncCallback\<number>): void;<br>rebootAndCleanUserData(): Promise\<number>; | Deleted|
| ohos.update | Updater | rebootAndCleanCache(callback: AsyncCallback\<number>): void;<br>rebootAndCleanCache(): Promise\<number>; | Deleted|
| ohos.update | Updater | applyNewVersion(callback: AsyncCallback\<number>): void;<br>applyNewVersion(): Promise\<number>; | Deleted|
| ohos.update | Updater | setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;<br>setUpdatePolicy(policy: UpdatePolicy): Promise\<number>; | Deleted|
| ohos.update | Updater | getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;<br>getUpdatePolicy(): Promise\<UpdatePolicy>; | Deleted|
| ohos.update | UpdateProgressCallback | (progress: Progress): void; | Deleted|
| ohos.update | UpdatePolicy | autoUpgradeInterval: Array\<number>; | Deleted|
| ohos.update | UpdatePolicy | installMode: INSTALL_MODE; | Deleted|
| ohos.update | UpdatePolicy | autoDownload: boolean; | Deleted|
| ohos.update | InstallMode | INSTALL_MODE_AUTO | Deleted|
| ohos.update | InstallMode | INSTALL_MODE_NIGHT | Deleted|
| ohos.update | InstallMode | INSTALL_MODE_NORMAL | Deleted|
| ohos.update | Progress | endReason: string; | Deleted|
| ohos.update | Progress | status: UpdateState; | Deleted|
| ohos.update | Progress | percent: number; | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_UPDATE_ON = 90 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_INSTALL_ON = 80 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_PACKAGE_TRANS_ON = 70 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_VERIFY_ON = 30 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_CANCEL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_PAUSE | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_DOWNLOAD_ON = 20 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_SUCCESS | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_FAIL | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_CHECK_VERSION_ON = 10 | Deleted|
| ohos.update | UpdateState | UPDATE_STATE_INIT = 0 | Deleted|
| ohos.update | NewVersionInfo | descriptionInfo: Array\<DescriptionInfo>; | Deleted|
| ohos.update | NewVersionInfo | checkResults: Array\<CheckResult>; | Deleted|
| ohos.update | NewVersionInfo | errMsg: string; | Deleted|
| ohos.update | NewVersionInfo | status: NewVersionStatus; | Deleted|
| ohos.update | NewVersionStatus | VERSION_STATUS_BUSY = 2 | Deleted|
| ohos.update | NewVersionStatus | VERSION_STATUS_NONE = 1 | Deleted|
| ohos.update | NewVersionStatus | VERSION_STATUS_NEW = 0 | Deleted|
| ohos.update | NewVersionStatus | VERSION_STATUS_ERR = -1 | Deleted|
| ohos.update | DescriptionInfo | descriptionId: string; | Deleted|
| ohos.update | CheckResult | descriptionId: string; | Deleted|
| ohos.update | CheckResult | packageType: PackageTypes; | Deleted|
| ohos.update | CheckResult | verifyInfo: string; | Deleted|
| ohos.update | CheckResult | size: number; | Deleted|
| ohos.update | CheckResult | versionCode: string; | Deleted|
| ohos.update | CheckResult | versionName: number; | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_PATCH = 7 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_VERSION = 6 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_COTA = 5 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_PRELOAD = 4 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_CUST = 3 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_BASE = 2 | Deleted|
| ohos.update | PackageTypes | PACKAGE_TYPE_NORMAL = 1 | Deleted|
