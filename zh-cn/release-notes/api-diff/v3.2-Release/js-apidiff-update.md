| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：update;<br>方法or属性：export type UpdateTypes =<br>        'OTA' \|<br>        'patch';|NA|@ohos.update.d.ts|
|删除|类名：update;<br>方法or属性：function getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|删除|类名：update;<br>方法or属性：function getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|删除|类名：update;<br>方法or属性：function getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater;|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_NORMAL = 1|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_BASE = 2|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_CUST = 3|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_PRELOAD = 4|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_COTA = 5|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_VERSION = 6|NA|@ohos.update.d.ts|
|删除|类名：PackageTypes;<br>方法or属性：PACKAGE_TYPE_PATCH = 7|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：versionName: number;|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：versionCode: string;|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：size: number;|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：verifyInfo: string;|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：packageType: PackageTypes;|NA|@ohos.update.d.ts|
|删除|类名：CheckResult;<br>方法or属性：descriptionId: string;|NA|@ohos.update.d.ts|
|删除|类名：DescriptionInfo;<br>方法or属性：descriptionId: string;|NA|@ohos.update.d.ts|
|删除|类名：NewVersionStatus;<br>方法or属性：VERSION_STATUS_ERR = -1|NA|@ohos.update.d.ts|
|删除|类名：NewVersionStatus;<br>方法or属性：VERSION_STATUS_NEW = 0|NA|@ohos.update.d.ts|
|删除|类名：NewVersionStatus;<br>方法or属性：VERSION_STATUS_NONE = 1|NA|@ohos.update.d.ts|
|删除|类名：NewVersionStatus;<br>方法or属性：VERSION_STATUS_BUSY = 2|NA|@ohos.update.d.ts|
|删除|类名：NewVersionInfo;<br>方法or属性：status: NewVersionStatus;|NA|@ohos.update.d.ts|
|删除|类名：NewVersionInfo;<br>方法or属性：errMsg: string;|NA|@ohos.update.d.ts|
|删除|类名：NewVersionInfo;<br>方法or属性：checkResults: Array\<CheckResult>;|NA|@ohos.update.d.ts|
|删除|类名：NewVersionInfo;<br>方法or属性：descriptionInfo: Array\<DescriptionInfo>;|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_INIT = 0|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_CHECK_VERSION_ON = 10|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_CHECK_VERSION_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_CHECK_VERSION_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_DOWNLOAD_ON = 20|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_DOWNLOAD_PAUSE|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_DOWNLOAD_CANCEL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_DOWNLOAD_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_DOWNLOAD_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_VERIFY_ON = 30|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_VERIFY_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_VERIFY_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_PACKAGE_TRANS_ON = 70|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_PACKAGE_TRANS_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_PACKAGE_TRANS_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_INSTALL_ON = 80|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_INSTALL_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_INSTALL_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_UPDATE_ON = 90|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_UPDATE_FAIL|NA|@ohos.update.d.ts|
|删除|类名：UpdateState;<br>方法or属性：UPDATE_STATE_UPDATE_SUCCESS|NA|@ohos.update.d.ts|
|删除|类名：Progress;<br>方法or属性：percent: number;|NA|@ohos.update.d.ts|
|删除|类名：Progress;<br>方法or属性：status: UpdateState;|NA|@ohos.update.d.ts|
|删除|类名：Progress;<br>方法or属性：endReason: string;|NA|@ohos.update.d.ts|
|删除|类名：InstallMode;<br>方法or属性：INSTALL_MODE_NORMAL|NA|@ohos.update.d.ts|
|删除|类名：InstallMode;<br>方法or属性：INSTALL_MODE_NIGHT|NA|@ohos.update.d.ts|
|删除|类名：InstallMode;<br>方法or属性：INSTALL_MODE_AUTO|NA|@ohos.update.d.ts|
|删除|类名：UpdatePolicy;<br>方法or属性：autoDownload: boolean;|NA|@ohos.update.d.ts|
|删除|类名：UpdatePolicy;<br>方法or属性：installMode: INSTALL_MODE;|NA|@ohos.update.d.ts|
|删除|类名：UpdatePolicy;<br>方法or属性：autoUpgradeInterval: Array\<number>;|NA|@ohos.update.d.ts|
|删除|类名：UpdateProgressCallback;<br>方法or属性：(progress: Progress): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：getUpdatePolicy(): Promise\<UpdatePolicy>;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：setUpdatePolicy(policy: UpdatePolicy): Promise\<number>;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：applyNewVersion(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：applyNewVersion(): Promise\<number>;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：rebootAndCleanCache(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：rebootAndCleanCache(): Promise\<number>;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：rebootAndCleanUserData(callback: AsyncCallback\<number>): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：rebootAndCleanUserData(): Promise\<number>;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：verifyUpdatePackage(upgradeFile: string, certsFile: string): void;|NA|@ohos.update.d.ts|
|删除|类名：Updater;<br>方法or属性：cancel(): void;|NA|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：size: number;|@ohos.update.d.ts|
|新增|NA|类名：update;<br>方法or属性：function getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater;|@ohos.update.d.ts|
|新增|NA|类名：update;<br>方法or属性：function getRestorer(): Restorer;|@ohos.update.d.ts|
|新增|NA|类名：update;<br>方法or属性：function getLocalUpdater(): LocalUpdater;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getNewVersionDescription(versionDigestInfo: VersionDigestInfo, descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getCurrentVersionInfo(): Promise\<CurrentVersionInfo>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getCurrentVersionDescription(descriptionOptions: DescriptionOptions, callback: AsyncCallback\<Array\<ComponentDescription>>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<TaskInfo>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getTaskInfo(): Promise\<TaskInfo>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：getUpgradePolicy(): Promise\<UpgradePolicy>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：setUpgradePolicy(policy: UpgradePolicy): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：terminateUpgrade(callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Updater;<br>方法or属性：terminateUpgrade(): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：Restorer;<br>方法or属性：factoryReset(callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：Restorer;<br>方法or属性：factoryReset(): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|新增|NA|类名：LocalUpdater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeInfo;<br>方法or属性：upgradeApp: string;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeInfo;<br>方法or属性：businessType: BusinessType;|@ohos.update.d.ts|
|新增|NA|类名：BusinessType;<br>方法or属性：vendor: BusinessVendor;|@ohos.update.d.ts|
|新增|NA|类名：BusinessType;<br>方法or属性：subType: BusinessSubType;|@ohos.update.d.ts|
|新增|NA|类名：CheckResult;<br>方法or属性：isExistNewVersion: boolean;|@ohos.update.d.ts|
|新增|NA|类名：CheckResult;<br>方法or属性：newVersionInfo: NewVersionInfo;|@ohos.update.d.ts|
|新增|NA|类名：NewVersionInfo;<br>方法or属性：versionDigestInfo: VersionDigestInfo;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：versionDigestInfo: VersionDigestInfo;|@ohos.update.d.ts|
|新增|NA|类名：NewVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|新增|NA|类名：CurrentVersionInfo;<br>方法or属性：versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：versionComponents: Array\<VersionComponent>;|@ohos.update.d.ts|
|新增|NA|类名：VersionDigestInfo;<br>方法or属性：versionDigest: string;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：componentId: string;|@ohos.update.d.ts|
|新增|NA|类名：ComponentDescription;<br>方法or属性：componentId: string;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：componentType: ComponentType;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：upgradeAction: UpgradeAction;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：displayVersion: string;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：innerVersion: string;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：effectiveMode: EffectiveMode;|@ohos.update.d.ts|
|新增|NA|类名：VersionComponent;<br>方法or属性：descriptionInfo: DescriptionInfo;|@ohos.update.d.ts|
|新增|NA|类名：ComponentDescription;<br>方法or属性：descriptionInfo: DescriptionInfo;|@ohos.update.d.ts|
|新增|NA|类名：DescriptionOptions;<br>方法or属性：format: DescriptionFormat;|@ohos.update.d.ts|
|新增|NA|类名：DescriptionOptions;<br>方法or属性：language: string;|@ohos.update.d.ts|
|新增|NA|类名：DescriptionInfo;<br>方法or属性：descriptionType: DescriptionType;|@ohos.update.d.ts|
|新增|NA|类名：CurrentVersionInfo;<br>方法or属性：osVersion: string;|@ohos.update.d.ts|
|新增|NA|类名：CurrentVersionInfo;<br>方法or属性：deviceName: string;|@ohos.update.d.ts|
|新增|NA|类名：DownloadOptions;<br>方法or属性：allowNetwork: NetType;|@ohos.update.d.ts|
|新增|NA|类名：ResumeDownloadOptions;<br>方法or属性：allowNetwork: NetType;|@ohos.update.d.ts|
|新增|NA|类名：DownloadOptions;<br>方法or属性：order: Order;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeOptions;<br>方法or属性：order: Order;|@ohos.update.d.ts|
|新增|NA|类名：PauseDownloadOptions;<br>方法or属性：isAllowAutoResume: boolean;|@ohos.update.d.ts|
|新增|NA|类名：ClearOptions;<br>方法or属性：status: UpgradeStatus;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：status: UpgradeStatus;|@ohos.update.d.ts|
|新增|NA|类名：UpgradePolicy;<br>方法or属性：downloadStrategy: boolean;|@ohos.update.d.ts|
|新增|NA|类名：UpgradePolicy;<br>方法or属性：autoUpgradeStrategy: boolean;|@ohos.update.d.ts|
|新增|NA|类名：UpgradePolicy;<br>方法or属性：autoUpgradePeriods: Array\<UpgradePeriod>;|@ohos.update.d.ts|
|新增|NA|类名：UpgradePeriod;<br>方法or属性：start: number;|@ohos.update.d.ts|
|新增|NA|类名：UpgradePeriod;<br>方法or属性：end: number;|@ohos.update.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：existTask: boolean;|@ohos.update.d.ts|
|新增|NA|类名：TaskInfo;<br>方法or属性：taskBody: TaskBody;|@ohos.update.d.ts|
|新增|NA|类名：EventInfo;<br>方法or属性：taskBody: TaskBody;|@ohos.update.d.ts|
|新增|NA|类名：EventInfo;<br>方法or属性：eventId: EventId;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：subStatus: number;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：progress: number;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：installMode: number;|@ohos.update.d.ts|
|新增|NA|类名：TaskBody;<br>方法or属性：errorMessages: Array\<ErrorMessage>;|@ohos.update.d.ts|
|新增|NA|类名：ErrorMessage;<br>方法or属性：errorCode: number;|@ohos.update.d.ts|
|新增|NA|类名：ErrorMessage;<br>方法or属性：errorMessage: string;|@ohos.update.d.ts|
|新增|NA|类名：EventClassifyInfo;<br>方法or属性：eventClassify: EventClassify;|@ohos.update.d.ts|
|新增|NA|类名：EventClassifyInfo;<br>方法or属性：extraInfo: string;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeFile;<br>方法or属性：fileType: ComponentType;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeFile;<br>方法or属性：filePath: string;|@ohos.update.d.ts|
|新增|NA|类名：UpgradeTaskCallback;<br>方法or属性：(eventInfo: EventInfo): void;|@ohos.update.d.ts|
|新增|NA|类名：BusinessVendor;<br>方法or属性：PUBLIC = "public"|@ohos.update.d.ts|
|新增|NA|类名：BusinessSubType;<br>方法or属性：FIRMWARE = 1|@ohos.update.d.ts|
|新增|NA|类名：ComponentType;<br>方法or属性：OTA = 1|@ohos.update.d.ts|
|新增|NA|类名：UpgradeAction;<br>方法or属性：UPGRADE = "upgrade"|@ohos.update.d.ts|
|新增|NA|类名：UpgradeAction;<br>方法or属性：RECOVERY = "recovery"|@ohos.update.d.ts|
|新增|NA|类名：EffectiveMode;<br>方法or属性：COLD = 1|@ohos.update.d.ts|
|新增|NA|类名：EffectiveMode;<br>方法or属性：LIVE = 2|@ohos.update.d.ts|
|新增|NA|类名：EffectiveMode;<br>方法or属性：LIVE_AND_COLD = 3|@ohos.update.d.ts|
|新增|NA|类名：DescriptionType;<br>方法or属性：CONTENT = 0|@ohos.update.d.ts|
|新增|NA|类名：DescriptionType;<br>方法or属性：URI = 1|@ohos.update.d.ts|
|新增|NA|类名：DescriptionFormat;<br>方法or属性：STANDARD = 0|@ohos.update.d.ts|
|新增|NA|类名：DescriptionFormat;<br>方法or属性：SIMPLIFIED = 1|@ohos.update.d.ts|
|新增|NA|类名：NetType;<br>方法or属性：CELLULAR = 1|@ohos.update.d.ts|
|新增|NA|类名：NetType;<br>方法or属性：METERED_WIFI = 2|@ohos.update.d.ts|
|新增|NA|类名：NetType;<br>方法or属性：NOT_METERED_WIFI = 4|@ohos.update.d.ts|
|新增|NA|类名：NetType;<br>方法or属性：WIFI = 6|@ohos.update.d.ts|
|新增|NA|类名：NetType;<br>方法or属性：CELLULAR_AND_WIFI = 7|@ohos.update.d.ts|
|新增|NA|类名：Order;<br>方法or属性：DOWNLOAD = 1|@ohos.update.d.ts|
|新增|NA|类名：Order;<br>方法or属性：INSTALL = 2|@ohos.update.d.ts|
|新增|NA|类名：Order;<br>方法or属性：DOWNLOAD_AND_INSTALL = 3|@ohos.update.d.ts|
|新增|NA|类名：Order;<br>方法or属性：APPLY = 4|@ohos.update.d.ts|
|新增|NA|类名：Order;<br>方法or属性：INSTALL_AND_APPLY = 6|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：WAITING_DOWNLOAD = 20|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：DOWNLOADING = 21|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_PAUSED = 22|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：DOWNLOAD_FAIL = 23|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：WAITING_INSTALL = 30|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：UPDATING = 31|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：WAITING_APPLY = 40|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：APPLYING = 41|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：UPGRADE_SUCCESS = 50|@ohos.update.d.ts|
|新增|NA|类名：UpgradeStatus;<br>方法or属性：UPGRADE_FAIL = 51|@ohos.update.d.ts|
|新增|NA|类名：EventClassify;<br>方法or属性：TASK = 0x01000000|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_TASK_BASE = EventClassify.TASK|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_TASK_RECEIVE|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_TASK_CANCEL|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_WAIT|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_START|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_UPDATE|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_PAUSE|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_RESUME|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_SUCCESS|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_DOWNLOAD_FAIL|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_UPGRADE_WAIT|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_UPGRADE_START|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_UPGRADE_UPDATE|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_APPLY_WAIT|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_APPLY_START|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_UPGRADE_SUCCESS|@ohos.update.d.ts|
|新增|NA|类名：EventId;<br>方法or属性：EVENT_UPGRADE_FAIL|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>新版本信息：201,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>新版本信息：201,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>新版本信息：201,401,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>新版本信息：201,401,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>新版本信息：201,11500104|@ohos.update.d.ts|
|新增(错误码)|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>新版本信息：201,11500104|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>旧版本信息：|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>旧版本信息：|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|权限有变化|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>旧版本信息：|类名：Updater;<br>方法or属性：getNewVersionInfo(): Promise\<NewVersionInfo>;<br>新版本信息：ohos.permission.UPDATE_SYSTEM|@ohos.update.d.ts|
|type有变化|类名：DescriptionInfo;<br>方法or属性：content: string;<br>旧版本信息：|类名：DescriptionInfo;<br>方法or属性：content: string;<br>新版本信息：string|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void;|类名：Updater;<br>方法or属性：checkNewVersion(callback: AsyncCallback\<CheckResult>): void;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<NewVersionInfo>;|类名：Updater;<br>方法or属性：checkNewVersion(): Promise\<CheckResult>;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：download(): void;|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：download(): void;|类名：Updater;<br>方法or属性：download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：upgrade(): void;|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：upgrade(): void;|类名：Updater;<br>方法or属性：upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：on(eventType: 'downloadProgress', callback: UpdateProgressCallback): void;|类名：Updater;<br>方法or属性：on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void;|@ohos.update.d.ts|
|函数有变化|类名：Updater;<br>方法or属性：off(eventType: 'downloadProgress', callback?: UpdateProgressCallback): void;|类名：Updater;<br>方法or属性：off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void;|@ohos.update.d.ts|
