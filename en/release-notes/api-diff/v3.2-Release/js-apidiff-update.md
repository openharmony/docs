| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: update;<br>Method or attribute name: export type UpdateTypes =<br>        'OTA' \|<br>        'patch';|NA|@ohos.update.d.ts|
|Deleted|Class name: update;<br>Method or attribute name: function getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|Deleted|Class name: update;<br>Method or attribute name: function getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|Deleted|Class name: update;<br>Method or attribute name: function getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_NORMAL = 1|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_BASE = 2|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_CUST = 3|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_PRELOAD = 4|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_COTA = 5|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_VERSION = 6|NA|@ohos.update.d.ts|
|Deleted|Class name: PackageTypes;<br>Method or attribute name: PACKAGE_TYPE_PATCH = 7|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: versionName: number;|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: versionCode: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: size: number;|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: verifyInfo: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: packageType: PackageTypes;|NA|@ohos.update.d.ts|
|Deleted|Class name: CheckResult;<br>Method or attribute name: descriptionId: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: DescriptionInfo;<br>Method or attribute name: descriptionId: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionStatus;<br>Method or attribute name: VERSION_STATUS_ERR = -1|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionStatus;<br>Method or attribute name: VERSION_STATUS_NEW = 0|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionStatus;<br>Method or attribute name: VERSION_STATUS_NONE = 1|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionStatus;<br>Method or attribute name: VERSION_STATUS_BUSY = 2|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionInfo;<br>Method or attribute name: status: NewVersionStatus;|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionInfo;<br>Method or attribute name: errMsg: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionInfo;<br>Method or attribute name: checkResults: Array\<CheckResult>;|NA|@ohos.update.d.ts|
|Deleted|Class name: NewVersionInfo;<br>Method or attribute name: descriptionInfo: Array\<DescriptionInfo>;|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_INIT = 0|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_CHECK_VERSION_ON = 10|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_CHECK_VERSION_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_CHECK_VERSION_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_DOWNLOAD_ON = 20|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_DOWNLOAD_PAUSE|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_DOWNLOAD_CANCEL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_DOWNLOAD_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_DOWNLOAD_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_VERIFY_ON = 30|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_VERIFY_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_VERIFY_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_PACKAGE_TRANS_ON = 70|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_PACKAGE_TRANS_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_PACKAGE_TRANS_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_INSTALL_ON = 80|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_INSTALL_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_INSTALL_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_UPDATE_ON = 90|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_UPDATE_FAIL|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateState;<br>Method or attribute name: UPDATE_STATE_UPDATE_SUCCESS|NA|@ohos.update.d.ts|
|Deleted|Class name: Progress;<br>Method or attribute name: percent: number;|NA|@ohos.update.d.ts|
|Deleted|Class name: Progress;<br>Method or attribute name: status: UpdateState;|NA|@ohos.update.d.ts|
|Deleted|Class name: Progress;<br>Method or attribute name: endReason: string;|NA|@ohos.update.d.ts|
|Deleted|Class name: InstallMode;<br>Method or attribute name: INSTALL_MODE_NORMAL|NA|@ohos.update.d.ts|
|Deleted|Class name: InstallMode;<br>Method or attribute name: INSTALL_MODE_NIGHT|NA|@ohos.update.d.ts|
|Deleted|Class name: InstallMode;<br>Method or attribute name: INSTALL_MODE_AUTO|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdatePolicy;<br>Method or attribute name: autoDownload: boolean;|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdatePolicy;<br>Method or attribute name: installMode: INSTALL_MODE;|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdatePolicy;<br>Method or attribute name: autoUpgradeInterval: Array\<number>;|NA|@ohos.update.d.ts|
|Deleted|Class name: UpdateProgressCallback;<br>Method or attribute name: (progress: Progress): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: getUpdatePolicy(): Promise\<UpdatePolicy>;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: setUpdatePolicy(policy: UpdatePolicy): Promise\<number>;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: applyNewVersion(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: applyNewVersion(): Promise\<number>;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: rebootAndCleanCache(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: rebootAndCleanCache(): Promise\<number>;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: rebootAndCleanUserData(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: rebootAndCleanUserData(): Promise\<number>;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: verifyUpdatePackage(upgradeFile: string, certsFile: string): void;|NA|@ohos.update.d.ts|
|Deleted|Class name: Updater;<br>Method or attribute name: cancel(): void;|NA|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: size: number;|@ohos.update.d.ts|
|Added|NA|Class name: update;<br>Method or attribute name: function getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater;|@ohos.update.d.ts|
|Added|NA|Class name: update;<br>Method or attribute name: function getRestorer(): Restorer;|@ohos.update.d.ts|
|Added|NA|Class name: update;<br>Method or attribute name: function getLocalUpdater(): LocalUpdater;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getCurrentVersionInfo(): Promise\<CurrentVersionInfo>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getCurrentVersionDescription(descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getTaskInfo(): Promise\<TaskInfo>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: getUpgradePolicy(): Promise\<UpgradePolicy>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: setUpgradePolicy(policy: UpgradePolicy): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: terminateUpgrade(callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Updater;<br>Method or attribute name: terminateUpgrade(): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: Restorer;<br>Method or attribute name: factoryReset(callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: Restorer;<br>Method or attribute name: factoryReset(): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|Added|NA|Class name: LocalUpdater;<br>Method or attribute name: off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeInfo;<br>Method or attribute name: upgradeApp: string;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeInfo;<br>Method or attribute name: businessType: BusinessType;|@ohos.update.d.ts|
|Added|NA|Class name: BusinessType;<br>Method or attribute name: vendor: BusinessVendor;|@ohos.update.d.ts|
|Added|NA|Class name: BusinessType;<br>Method or attribute name: subType: BusinessSubType;|@ohos.update.d.ts|
|Added|NA|Class name: CheckResult;<br>Method or attribute name: isExistNewVersion: boolean;|@ohos.update.d.ts|
|Added|NA|Class name: CheckResult;<br>Method or attribute name: newVersionInfo: NewVersionInfo;|@ohos.update.d.ts|
|Added|NA|Class name: NewVersionInfo;<br>Method or attribute name: versionDigestInfo: VersionDigestInfo;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: versionDigestInfo: VersionDigestInfo;|@ohos.update.d.ts|
|Added|NA|Class name: NewVersionInfo;<br>Method or attribute name: versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|Added|NA|Class name: CurrentVersionInfo;<br>Method or attribute name: versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|Added|NA|Class name: VersionDigestInfo;<br>Method or attribute name: versionDigest: string;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: componentId: string;|@ohos.update.d.ts|
|Added|NA|Class name: ComponentDescription;<br>Method or attribute name: componentId: string;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: componentType: ComponentType;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: upgradeAction: UpgradeAction;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: displayVersion: string;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: innerVersion: string;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: effectiveMode: EffectiveMode;|@ohos.update.d.ts|
|Added|NA|Class name: VersionComponent;<br>Method or attribute name: descriptionInfo: DescriptionInfo;|@ohos.update.d.ts|
|Added|NA|Class name: ComponentDescription;<br>Method or attribute name: descriptionInfo: DescriptionInfo;|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionOptions;<br>Method or attribute name: format: DescriptionFormat;|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionOptions;<br>Method or attribute name: language: string;|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionInfo;<br>Method or attribute name: descriptionType: DescriptionType;|@ohos.update.d.ts|
|Added|NA|Class name: CurrentVersionInfo;<br>Method or attribute name: osVersion: string;|@ohos.update.d.ts|
|Added|NA|Class name: CurrentVersionInfo;<br>Method or attribute name: deviceName: string;|@ohos.update.d.ts|
|Added|NA|Class name: DownloadOptions;<br>Method or attribute name: allowNetwork: NetType;|@ohos.update.d.ts|
|Added|NA|Class name: ResumeDownloadOptions;<br>Method or attribute name: allowNetwork: NetType;|@ohos.update.d.ts|
|Added|NA|Class name: DownloadOptions;<br>Method or attribute name: order: Order;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeOptions;<br>Method or attribute name: order: Order;|@ohos.update.d.ts|
|Added|NA|Class name: PauseDownloadOptions;<br>Method or attribute name: isAllowAutoResume: boolean;|@ohos.update.d.ts|
|Added|NA|Class name: ClearOptions;<br>Method or attribute name: status: UpgradeStatus;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: status: UpgradeStatus;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradePolicy;<br>Method or attribute name: downloadStrategy: boolean;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradePolicy;<br>Method or attribute name: autoUpgradeStrategy: boolean;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradePolicy;<br>Method or attribute name: autoUpgradePeriods: Array\<UpgradePeriod>;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradePeriod;<br>Method or attribute name: start: number;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradePeriod;<br>Method or attribute name: end: number;|@ohos.update.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: existTask: boolean;|@ohos.update.d.ts|
|Added|NA|Class name: TaskInfo;<br>Method or attribute name: taskBody: TaskBody;|@ohos.update.d.ts|
|Added|NA|Class name: EventInfo;<br>Method or attribute name: taskBody: TaskBody;|@ohos.update.d.ts|
|Added|NA|Class name: EventInfo;<br>Method or attribute name: eventId: EventId;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: subStatus: number;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: progress: number;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: installMode: number;|@ohos.update.d.ts|
|Added|NA|Class name: TaskBody;<br>Method or attribute name: errorMessages: Array\<ErrorMessage>;|@ohos.update.d.ts|
|Added|NA|Class name: ErrorMessage;<br>Method or attribute name: errorCode: number;|@ohos.update.d.ts|
|Added|NA|Class name: ErrorMessage;<br>Method or attribute name: errorMessage: string;|@ohos.update.d.ts|
|Added|NA|Class name: EventClassifyInfo;<br>Method or attribute name: eventClassify: EventClassify;|@ohos.update.d.ts|
|Added|NA|Class name: EventClassifyInfo;<br>Method or attribute name: extraInfo: string;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeFile;<br>Method or attribute name: fileType: ComponentType;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeFile;<br>Method or attribute name: filePath: string;|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeTaskCallback;<br>Method or attribute name: (eventInfo: EventInfo): void;|@ohos.update.d.ts|
|Added|NA|Class name: BusinessVendor;<br>Method or attribute name: PUBLIC = "public"|@ohos.update.d.ts|
|Added|NA|Class name: BusinessSubType;<br>Method or attribute name: FIRMWARE = 1|@ohos.update.d.ts|
|Added|NA|Class name: ComponentType;<br>Method or attribute name: OTA = 1|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeAction;<br>Method or attribute name: UPGRADE = "upgrade"|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeAction;<br>Method or attribute name: RECOVERY = "recovery"|@ohos.update.d.ts|
|Added|NA|Class name: EffectiveMode;<br>Method or attribute name: COLD = 1|@ohos.update.d.ts|
|Added|NA|Class name: EffectiveMode;<br>Method or attribute name: LIVE = 2|@ohos.update.d.ts|
|Added|NA|Class name: EffectiveMode;<br>Method or attribute name: LIVE_AND_COLD = 3|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionType;<br>Method or attribute name: CONTENT = 0|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionType;<br>Method or attribute name: URI = 1|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionFormat;<br>Method or attribute name: STANDARD = 0|@ohos.update.d.ts|
|Added|NA|Class name: DescriptionFormat;<br>Method or attribute name: SIMPLIFIED = 1|@ohos.update.d.ts|
|Added|NA|Class name: NetType;<br>Method or attribute name: CELLULAR = 1|@ohos.update.d.ts|
|Added|NA|Class name: NetType;<br>Method or attribute name: METERED_WIFI = 2|@ohos.update.d.ts|
|Added|NA|Class name: NetType;<br>Method or attribute name: NOT_METERED_WIFI = 4|@ohos.update.d.ts|
|Added|NA|Class name: NetType;<br>Method or attribute name: WIFI = 6|@ohos.update.d.ts|
|Added|NA|Class name: NetType;<br>Method or attribute name: CELLULAR_AND_WIFI = 7|@ohos.update.d.ts|
|Added|NA|Class name: Order;<br>Method or attribute name: DOWNLOAD = 1|@ohos.update.d.ts|
|Added|NA|Class name: Order;<br>Method or attribute name: INSTALL = 2|@ohos.update.d.ts|
|Added|NA|Class name: Order;<br>Method or attribute name: DOWNLOAD_AND_INSTALL = 3|@ohos.update.d.ts|
|Added|NA|Class name: Order;<br>Method or attribute name: APPLY = 4|@ohos.update.d.ts|
|Added|NA|Class name: Order;<br>Method or attribute name: INSTALL_AND_APPLY = 6|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: WAITING_DOWNLOAD = 20|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: DOWNLOADING = 21|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: DOWNLOAD_PAUSED = 22|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: DOWNLOAD_FAIL = 23|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: WAITING_INSTALL = 30|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: UPDATING = 31|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: WAITING_APPLY = 40|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: APPLYING = 41|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: UPGRADE_SUCCESS = 50|@ohos.update.d.ts|
|Added|NA|Class name: UpgradeStatus;<br>Method or attribute name: UPGRADE_FAIL = 51|@ohos.update.d.ts|
|Added|NA|Class name: EventClassify;<br>Method or attribute name: TASK = 0x01000000|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_TASK_BASE = EventClassify.TASK|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_TASK_RECEIVE|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_TASK_CANCEL|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_WAIT|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_START|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_UPDATE|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_PAUSE|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_RESUME|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_SUCCESS|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_DOWNLOAD_FAIL|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_UPGRADE_WAIT|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_UPGRADE_START|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_UPGRADE_UPDATE|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_APPLY_WAIT|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_APPLY_START|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_UPGRADE_SUCCESS|@ohos.update.d.ts|
|Added|NA|Class name: EventId;<br>Method or attribute name: EVENT_UPGRADE_FAIL|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>New version: 201,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<CheckResult>;<br>Old version: |Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<CheckResult>;<br>New version: 201,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>New version: 201,401,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>Old version: |Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>New version: 201,401,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>New version: 201,401,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>Old version: |Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>New version: 201,401,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>New version: 201,11500104|@ohos.update.d.ts|
|Error code added|Class name: Updater;<br>Method or attribute name: getNewVersionInfo(): Promise\<NewVersionInfo>;<br>Old version: |Class name: Updater;<br>Method or attribute name: getNewVersionInfo(): Promise\<NewVersionInfo>;<br>New version: 201,11500104|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<CheckResult>;<br>Old version: |Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<CheckResult>;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>Old version: |Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>Old version: |Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>Old version: |Class name: Updater;<br>Method or attribute name: getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Permission changed|Class name: Updater;<br>Method or attribute name: getNewVersionInfo(): Promise\<NewVersionInfo>;<br>Old version: |Class name: Updater;<br>Method or attribute name: getNewVersionInfo(): Promise\<NewVersionInfo>;<br>New version: ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|Type changed|Class name: DescriptionInfo;<br>Method or attribute name: content: string;<br>Old version: |Class name: DescriptionInfo;<br>Method or attribute name: content: string;<br>New version: string|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void;|Class name: Updater;<br>Method or attribute name: checkNewVersion(callback: AsyncCallback\<CheckResult>): void;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<NewVersionInfo>;|Class name: Updater;<br>Method or attribute name: checkNewVersion(): Promise\<CheckResult>;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: download(): void;|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: download(): void;|Class name: Updater;<br>Method or attribute name: download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: upgrade(): void;|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: upgrade(): void;|Class name: Updater;<br>Method or attribute name: upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: on(eventType: 'downloadProgress', callback: UpdateProgressCallback): void;|Class name: Updater;<br>Method or attribute name: on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|Function changed|Class name: Updater;<br>Method or attribute name: off(eventType: 'downloadProgress', callback?: UpdateProgressCallback): void;|Class name: Updater;<br>Method or attribute name: off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;|@ohos.update.d.ts|
