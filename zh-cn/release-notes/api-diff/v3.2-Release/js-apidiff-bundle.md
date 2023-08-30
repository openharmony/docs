| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：appControl;<br>方法or属性：function setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：appControl;<br>方法or属性：function setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：appControl;<br>方法or属性：function getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：appControl;<br>方法or属性：function getDisposedStatus(appId: string): Promise\<Want>;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：appControl;<br>方法or属性：function deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>): void;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：appControl;<br>方法or属性：function deleteDisposedStatus(appId: string): Promise\<void>;|@ohos.bundle.appControl.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfoForSelf(bundleFlags: number): Promise\<BundleInfo>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfoForSelf(bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getApplicationInfo(bundleName: string, appFlags: number, callback: AsyncCallback\<ApplicationInfo>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getApplicationInfo(bundleName: string, appFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getApplicationInfo(bundleName: string, appFlags: number, userId?: number): Promise\<ApplicationInfo>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllBundleInfo(bundleFlags: number, callback: AsyncCallback\<Array\<BundleInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllBundleInfo(bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<BundleInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllBundleInfo(bundleFlags: number, userId?: number): Promise\<Array\<BundleInfo>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllApplicationInfo(appFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllApplicationInfo(appFlags: number, userId: number, callback: AsyncCallback\<Array\<ApplicationInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAllApplicationInfo(appFlags: number, userId?: number): Promise\<Array\<ApplicationInfo>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryAbilityInfo(want: Want, abilityFlags: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryAbilityInfo(want: Want, abilityFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryAbilityInfo(want: Want, abilityFlags: number, userId?: number): Promise\<Array\<AbilityInfo>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Promise\<Array\<ExtensionAbilityInfo>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleNameByUid(uid: number): Promise\<string>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string,  bundleFlags: number): Promise\<BundleInfo>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string): Promise\<void>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnabled: boolean, callback: AsyncCallback\<void>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnabled: boolean): Promise\<void>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function isApplicationEnabled(bundleName: string): Promise\<boolean>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo): Promise\<boolean>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string>>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getPermissionDef(permissionName: string): Promise\<PermissionDef>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : ApplicationInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getApplicationInfoSync(bundleName: string, applicationFlags: number) : ApplicationInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type ApplicationInfo = _ApplicationInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type Metadata = _Metadata;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type BundleInfo = _BundleInfo.BundleInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type UsedScene = _BundleInfo.UsedScene;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type ReqPermissionDetail = _BundleInfo.ReqPermissionDetail;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type SignatureInfo = _BundleInfo.SignatureInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type HapModuleInfo = _HapModuleInfo.HapModuleInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type PreloadItem = _HapModuleInfo.PreloadItem;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type Dependency = _HapModuleInfo.Dependency;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type AbilityInfo = _AbilityInfo.AbilityInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type WindowSize = _AbilityInfo.WindowSize;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type ExtensionAbilityInfo = _ExtensionAbilityInfo.ExtensionAbilityInfo;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type PermissionDef = _PermissionDef;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：export type ElementName = _ElementName;|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_DEFAULT = 0x00000000|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_APPLICATION = 0x00000001|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_HAP_MODULE = 0x00000002|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_ABILITY = 0x00000004|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY = 0x00000008|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION = 0x00000010|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_METADATA = 0x00000020|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_DISABLE = 0x00000040|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_INFO_WITH_SIGNATURE_INFO = 0x00000080|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ApplicationFlag;<br>方法or属性：GET_APPLICATION_INFO_DEFAULT = 0x00000000|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ApplicationFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000001|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ApplicationFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_METADATA = 0x00000002|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ApplicationFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_DISABLE = 0x00000004|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_DEFAULT = 0x00000000|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000001|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000002|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_METADATA = 0x00000004|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_DISABLE = 0x00000008|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityFlag;<br>方法or属性：GET_ABILITY_INFO_ONLY_SYSTEM_APP = 0x00000010|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityFlag;<br>方法or属性：GET_EXTENSION_ABILITY_INFO_DEFAULT = 0x00000000|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityFlag;<br>方法or属性：GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION = 0x00000001|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityFlag;<br>方法or属性：GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION = 0x00000002|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityFlag;<br>方法or属性：GET_EXTENSION_ABILITY_INFO_WITH_METADATA = 0x00000004|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：FORM = 0|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：WORK_SCHEDULER = 1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：INPUT_METHOD = 2|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：SERVICE = 3|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：ACCESSIBILITY = 4|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：DATA_SHARE = 5|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：FILE_SHARE = 6|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：STATIC_SUBSCRIBER = 7|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：WALLPAPER = 8|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：BACKUP = 9|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：WINDOW = 10|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：ENTERPRISE_ADMIN = 11|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：THUMBNAIL = 13|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：PREVIEW = 14|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ExtensionAbilityType;<br>方法or属性：UNSPECIFIED = 255|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：PermissionGrantState;<br>方法or属性：PERMISSION_DENIED = -1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：PermissionGrantState;<br>方法or属性：PERMISSION_GRANTED = 0|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：SupportWindowMode;<br>方法or属性：FULL_SCREEN = 0|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：SupportWindowMode;<br>方法or属性：SPLIT = 1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：SupportWindowMode;<br>方法or属性：FLOATING = 2|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：LaunchType;<br>方法or属性：SINGLETON = 0|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：LaunchType;<br>方法or属性：MULTITON = 1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：LaunchType;<br>方法or属性：SPECIFIED = 2|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityType;<br>方法or属性：PAGE = 1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityType;<br>方法or属性：SERVICE = 2|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：AbilityType;<br>方法or属性：DATA = 3|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：UNSPECIFIED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：LANDSCAPE|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：PORTRAIT|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：FOLLOW_RECENT|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：LANDSCAPE_INVERTED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：PORTRAIT_INVERTED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION_LANDSCAPE|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION_PORTRAIT|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION_RESTRICTED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION_LANDSCAPE_RESTRICTED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：AUTO_ROTATION_PORTRAIT_RESTRICTED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：DisplayOrientation;<br>方法or属性：LOCKED|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ModuleType;<br>方法or属性：ENTRY = 1|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ModuleType;<br>方法or属性：FEATURE = 2|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：ModuleType;<br>方法or属性：SHARED = 3|@ohos.bundle.bundleManager.d.ts|
|新增|NA|类名：BundleType;<br>方法or属性：APP = 0|@ohos.bundle.bundleManager.d.ts|
| 新增 | NA   | 类名：BundleType; <br>方法or属性：ATOMIC_SERVICE = 1 | @ohos.bundle.bundleManager.d.ts |
|新增|NA|类名：bundleMonitor;<br>方法or属性：type BundleChangedEvent = 'add' \| 'update' \| 'remove';|@ohos.bundle.bundleMonitor.d.ts|
|新增|NA|类名：bundleMonitor;<br>方法or属性：function on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void;|@ohos.bundle.bundleMonitor.d.ts|
|新增|NA|类名：bundleMonitor;<br>方法or属性：function off(type: BundleChangedEvent, callback?: Callback\<BundleChangedInfo>): void;|@ohos.bundle.bundleMonitor.d.ts|
|新增|NA|类名：BundleChangedInfo;<br>方法or属性：readonly bundleName: string;|@ohos.bundle.bundleMonitor.d.ts|
|新增|NA|类名：BundleChangedInfo;<br>方法or属性：readonly userId: number;|@ohos.bundle.bundleMonitor.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function isDefaultApplication(type: string, callback: AsyncCallback\<boolean>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function isDefaultApplication(type: string) : Promise\<boolean>;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function getDefaultApplication(type: string, userId?: number) : Promise\<BundleInfo>;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function setDefaultApplication(type: string, elementName: ElementName, userId: number, callback: AsyncCallback\<void>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function setDefaultApplication(type: string, elementName: ElementName, userId?: number) : Promise\<void>;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function resetDefaultApplication(type: string, callback: AsyncCallback\<void>) : void;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：defaultAppManager;<br>方法or属性：function resetDefaultApplication(type: string, userId?: number) : Promise\<void>;|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：BROWSER = "Web Browser"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：IMAGE = "Image Gallery"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：AUDIO = "Audio Player"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：VIDEO = "Video Player"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：PDF = "PDF Viewer"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：WORD = "Word Viewer"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：EXCEL = "Excel Viewer"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：ApplicationType;<br>方法or属性：PPT = "PPT Viewer"|@ohos.bundle.defaultAppManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName, locale: string, callback: AsyncCallback\<RemoteAbilityInfo>): void;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise\<RemoteAbilityInfo>;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：function getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string): Promise\<Array\<RemoteAbilityInfo>>;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：distributedBundleManager;<br>方法or属性：export type RemoteAbilityInfo = _RemoteAbilityInfo;|@ohos.bundle.distributedBundleManager.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>) : void;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function isHapModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function isHapModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag, callback: AsyncCallback\<BundlePackInfo>): void;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag): Promise\<BundlePackInfo>;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function getDispatchInfo(callback: AsyncCallback\<DispatchInfo>): void;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：function getDispatchInfo(): Promise\<DispatchInfo>;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type DispatchInfo = _DispatchInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type BundlePackInfo = _PackInfo.BundlePackInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type PackageConfig = _PackInfo.PackageConfig;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type PackageSummary = _PackInfo.PackageSummary;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type BundleConfigInfo = _PackInfo.BundleConfigInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type ExtensionAbility = _PackInfo.ExtensionAbility;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type ModuleConfigInfo = _PackInfo.ModuleConfigInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type ModuleDistroInfo = _PackInfo.ModuleDistroInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type ModuleAbilityInfo = _PackInfo.ModuleAbilityInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type AbilityFormInfo = _PackInfo.AbilityFormInfo;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type Version = _PackInfo.Version;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：freeInstall;<br>方法or属性：export type ApiVersion = _PackInfo.ApiVersion;|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：UpgradeFlag;<br>方法or属性：NOT_UPGRADE = 0|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：UpgradeFlag;<br>方法or属性：SINGLE_UPGRADE = 1|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：UpgradeFlag;<br>方法or属性：RELATION_UPGRADE = 2|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：BundlePackFlag;<br>方法or属性：GET_PACK_INFO_ALL = 0x00000000|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：BundlePackFlag;<br>方法or属性：GET_PACKAGES = 0x00000001|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：BundlePackFlag;<br>方法or属性：GET_BUNDLE_SUMMARY = 0x00000002|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：BundlePackFlag;<br>方法or属性：GET_MODULE_SUMMARY = 0x00000004|@ohos.bundle.freeInstall.d.ts|
|新增|NA|类名：installer;<br>方法or属性：function getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void|@ohos.bundle.installer.d.ts|
|新增|NA|类名：installer;<br>方法or属性：function getBundleInstaller(): Promise\<BundleInstaller>;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：install(hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>) : void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：install(hapFilePaths: Array\<string>, callback: AsyncCallback\<void>) : void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：install(hapFilePaths: Array\<string>, installParam?: InstallParam) : Promise\<void>;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：uninstall(bundleName: string, installParam: InstallParam, callback : AsyncCallback\<void>) : void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：uninstall(bundleName: string, callback : AsyncCallback\<void>) : void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：uninstall(bundleName: string, installParam?: InstallParam) : Promise\<void>;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback\<void>): void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：recover(bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：BundleInstaller;<br>方法or属性：recover(bundleName: string, installParam?: InstallParam) : Promise\<void>;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：HashParam;<br>方法or属性：moduleName: string;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：HashParam;<br>方法or属性：hashValue: string;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：userId?: number;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：installFlag?: number;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：isKeepData?: boolean;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：hashParams?: Array\<HashParam>;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：crowdtestDeadline?: number;|@ohos.bundle.installer.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getLauncherAbilityInfo(bundleName: string, userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getLauncherAbilityInfo(bundleName: string, userId: number) : Promise\<Array\<LauncherAbilityInfo>>;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getAllLauncherAbilityInfo(userId: number) : Promise\<Array\<LauncherAbilityInfo>>;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getShortcutInfo(bundleName :string, callback: AsyncCallback\<Array\<ShortcutInfo>>) : void;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：function getShortcutInfo(bundleName : string) : Promise\<Array\<ShortcutInfo>>;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：export type LauncherAbilityInfo = _LauncherAbilityInfo;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：export type ShortcutInfo = _ShortcutInfo;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：launcherBundleManager;<br>方法or属性：export type ShortcutWant = _ShortcutWant;|@ohos.bundle.launcherBundleManager.d.ts|
|新增|NA|类名：zlib;<br>方法or属性：function compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;|@ohos.zlib.d.ts|
|新增|NA|类名：zlib;<br>方法or属性：function compressFile(inFile:string, outFile:string, options: Options): Promise\<void>;|@ohos.zlib.d.ts|
|新增|NA|类名：zlib;<br>方法or属性：function decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;|@ohos.zlib.d.ts|
|新增|NA|类名：zlib;<br>方法or属性：function decompressFile(inFile: string, outFile: string, options: Options): Promise\<void>;|@ohos.zlib.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly bundleName: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly moduleName: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly name: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly label: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly labelId: number;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly description: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly descriptionId: number;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly icon: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly iconId: number;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly process: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly exported: boolean;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly type: bundleManager.AbilityType;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly orientation: bundleManager.DisplayOrientation;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly launchType: bundleManager.LaunchType;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly permissions: Array\<string>;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly readPermission: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly writePermission: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly uri: string;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly metadata: Array\<Metadata>;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly enabled: boolean;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly supportWindowModes: Array\<bundleManager.SupportWindowMode>;|AbilityInfo.d.ts|
|新增|NA|类名：AbilityInfo;<br>方法or属性：readonly windowSize: WindowSize;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly maxWindowRatio: number;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly minWindowRatio: number;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly maxWindowWidth: number;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly minWindowWidth: number;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly maxWindowHeight: number;|AbilityInfo.d.ts|
|新增|NA|类名：WindowSize;<br>方法or属性：readonly minWindowHeight: number;|AbilityInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly name: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly description: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly descriptionId: number;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly enabled: boolean;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly label: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly labelId: number;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly icon: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly iconId: number;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly process: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly permissions: Array\<string>;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly codePath: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly metadata: Map\<string, Array\<Metadata>>;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly removable: boolean;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly accessTokenId: number;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly uid: number;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly iconResource: Resource;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly labelResource: Resource;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly descriptionResource: Resource;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly appDistributionType: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly appProvisionType: string;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly systemApp: boolean;|ApplicationInfo.d.ts|
|新增|NA|类名：ApplicationInfo;<br>方法or属性：readonly bundleType: bundleManager.BundleType;|ApplicationInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly name: string;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly vendor: string;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly versionCode: number;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly versionName: string;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly minCompatibleVersionCode: number;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly targetVersion: number;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly appInfo: ApplicationInfo;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly hapModulesInfo: Array\<HapModuleInfo>;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly reqPermissionDetails: Array\<ReqPermissionDetail>;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly permissionGrantStates: Array\<bundleManager.PermissionGrantState>;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly signatureInfo: SignatureInfo;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly installTime: number;|BundleInfo.d.ts|
|新增|NA|类名：BundleInfo;<br>方法or属性：readonly updateTime: number;|BundleInfo.d.ts|
|新增|NA|类名：ReqPermissionDetail;<br>方法or属性：name: string;|BundleInfo.d.ts|
|新增|NA|类名：ReqPermissionDetail;<br>方法or属性：reason: string;|BundleInfo.d.ts|
|新增|NA|类名：ReqPermissionDetail;<br>方法or属性：reasonId: number;|BundleInfo.d.ts|
|新增|NA|类名：ReqPermissionDetail;<br>方法or属性：usedScene: UsedScene;|BundleInfo.d.ts|
|新增|NA|类名：UsedScene;<br>方法or属性：abilities: Array\<string>;|BundleInfo.d.ts|
|新增|NA|类名：UsedScene;<br>方法or属性：when: string;|BundleInfo.d.ts|
|新增|NA|类名：SignatureInfo;<br>方法or属性：readonly appId: string;|BundleInfo.d.ts|
|新增|NA|类名：SignatureInfo;<br>方法or属性：readonly fingerprint: string;|BundleInfo.d.ts|
|新增|NA|类名：BundlePackInfo;<br>方法or属性：readonly packages: Array\<PackageConfig>;|BundlePackInfo.d.ts|
|新增|NA|类名：BundlePackInfo;<br>方法or属性：readonly summary: PackageSummary;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageConfig;<br>方法or属性：readonly deviceTypes: Array\<string>;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageConfig;<br>方法or属性：readonly name: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ExtensionAbility;<br>方法or属性：readonly name: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleAbilityInfo;<br>方法or属性：readonly name: string;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly name: string;|BundlePackInfo.d.ts|
|新增|NA|类名：Version;<br>方法or属性：readonly name: string;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageConfig;<br>方法or属性：readonly moduleType: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleDistroInfo;<br>方法or属性：readonly moduleType: string;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageConfig;<br>方法or属性：readonly deliveryWithInstall: boolean;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleDistroInfo;<br>方法or属性：readonly deliveryWithInstall: boolean;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageSummary;<br>方法or属性：readonly app: BundleConfigInfo;|BundlePackInfo.d.ts|
|新增|NA|类名：PackageSummary;<br>方法or属性：readonly modules: Array\<ModuleConfigInfo>;|BundlePackInfo.d.ts|
|新增|NA|类名：BundleConfigInfo;<br>方法or属性：readonly bundleName: string;|BundlePackInfo.d.ts|
|新增|NA|类名：BundleConfigInfo;<br>方法or属性：readonly version: Version;|BundlePackInfo.d.ts|
|新增|NA|类名：ExtensionAbility;<br>方法or属性：readonly forms: Array\<AbilityFormInfo>;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleAbilityInfo;<br>方法or属性：readonly forms: Array\<AbilityFormInfo>;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly mainAbility: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly apiVersion: ApiVersion;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly distro: ModuleDistroInfo;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly abilities: Array\<ModuleAbilityInfo>;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleConfigInfo;<br>方法or属性：readonly extensionAbilities: Array\<ExtensionAbility>;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleDistroInfo;<br>方法or属性：readonly installationFree: boolean;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleDistroInfo;<br>方法or属性：readonly moduleName: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleAbilityInfo;<br>方法or属性：readonly label: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ModuleAbilityInfo;<br>方法or属性：readonly exported: boolean;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly type: string;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly updateEnabled: boolean;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly scheduledUpdateTime: string;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly updateDuration: number;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly supportDimensions: Array\<string>;|BundlePackInfo.d.ts|
|新增|NA|类名：AbilityFormInfo;<br>方法or属性：readonly defaultDimension: string;|BundlePackInfo.d.ts|
|新增|NA|类名：Version;<br>方法or属性：readonly minCompatibleVersionCode: number;|BundlePackInfo.d.ts|
|新增|NA|类名：Version;<br>方法or属性：readonly code: number;|BundlePackInfo.d.ts|
|新增|NA|类名：ApiVersion;<br>方法or属性：readonly releaseType: string;|BundlePackInfo.d.ts|
|新增|NA|类名：ApiVersion;<br>方法or属性：readonly compatible: number;|BundlePackInfo.d.ts|
|新增|NA|类名：ApiVersion;<br>方法or属性：readonly target: number;|BundlePackInfo.d.ts|
|新增|NA|类名：DispatchInfo;<br>方法or属性：readonly version: string;|DispatchInfo.d.ts|
|新增|NA|类名：DispatchInfo;<br>方法or属性：readonly dispatchAPIVersion: string;|DispatchInfo.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：deviceId?: string;|ElementName.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：bundleName: string;|ElementName.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：moduleName?: string;|ElementName.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：abilityName: string;|ElementName.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：uri?: string;|ElementName.d.ts|
|新增|NA|类名：ElementName;<br>方法or属性：shortName?: string;|ElementName.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly bundleName: string;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly moduleName: string;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly name: string;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly labelId: number;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly descriptionId: number;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly iconId: number;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly exported: boolean;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly extensionAbilityType: bundleManager.ExtensionAbilityType;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly permissions: Array\<string>;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly metadata: Array\<Metadata>;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly enabled: boolean;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly readPermission: string;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：ExtensionAbilityInfo;<br>方法or属性：readonly writePermission: string;|ExtensionAbilityInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly name: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly icon: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly iconId: number;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly label: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly labelId: number;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly description: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly descriptionId: number;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly mainElementName: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly abilitiesInfo: Array\<AbilityInfo>;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly extensionAbilitiesInfo: Array\<ExtensionAbilityInfo>;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly metadata: Array\<Metadata>;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly installationFree: boolean;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly hashValue: string;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly type: bundleManager.ModuleType;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly dependencies: Array\<Dependency>;|HapModuleInfo.d.ts|
|新增|NA|类名：HapModuleInfo;<br>方法or属性：readonly preloads: Array\<PreloadItem>;|HapModuleInfo.d.ts|
|新增|NA|类名：Dependency;<br>方法or属性：readonly moduleName: string;|HapModuleInfo.d.ts|
|新增|NA|类名：PreloadItem;<br>方法or属性：readonly moduleName: string;|HapModuleInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly elementName : ElementName;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly labelId: number;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly iconId: number;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly userId: number;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：LauncherAbilityInfo;<br>方法or属性：readonly installTime : number;|LauncherAbilityInfo.d.ts|
|新增|NA|类名：Metadata;<br>方法or属性：name: string;|Metadata.d.ts|
|新增|NA|类名：Metadata;<br>方法or属性：value: string;|Metadata.d.ts|
|新增|NA|类名：Metadata;<br>方法or属性：resource: string;|Metadata.d.ts|
|新增|NA|类名：PermissionDef;<br>方法or属性：readonly permissionName: string;|PermissionDef.d.ts|
|新增|NA|类名：PermissionDef;<br>方法or属性：readonly grantMode: number;|PermissionDef.d.ts|
|新增|NA|类名：PermissionDef;<br>方法or属性：readonly labelId: number;|PermissionDef.d.ts|
|新增|NA|类名：PermissionDef;<br>方法or属性：readonly descriptionId: number;|PermissionDef.d.ts|
|新增|NA|类名：RemoteAbilityInfo;<br>方法or属性：readonly elementName: ElementName;|RemoteAbilityInfo.d.ts|
|新增|NA|类名：RemoteAbilityInfo;<br>方法or属性：readonly label: string;|RemoteAbilityInfo.d.ts|
|新增|NA|类名：RemoteAbilityInfo;<br>方法or属性：readonly icon: string;|RemoteAbilityInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly id: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly bundleName: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly moduleName: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly hostAbility: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly icon: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly iconId: number;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly label: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly labelId: number;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutInfo;<br>方法or属性：readonly wants: Array\<ShortcutWant>;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutWant;<br>方法or属性：readonly targetBundle: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutWant;<br>方法or属性：readonly targetModule: string;|ShortcutInfo.d.ts|
|新增|NA|类名：ShortcutWant;<br>方法or属性：readonly targetAbility: string;|ShortcutInfo.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：declare bundle<br>旧版本信息：|类名：bundle;<br>方法or属性：declare bundle<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.installer#getBundleInstaller|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleInstaller(): Promise\<BundleInstaller>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleInstaller(): Promise\<BundleInstaller>;<br>新版本信息：9<br>代替接口： ohos.bundle.installer#getBundleInstaller|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#queryAbilityInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#queryAbilityInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<ApplicationInfo>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<ApplicationInfo>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number) : Promise\<ApplicationInfo>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number) : Promise\<ApplicationInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#queryAbilityInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#queryAbilityInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, userId?:number): Promise\<Array\<AbilityInfo>>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function queryAbilityByWant(want: Want, bundleFlags: number, userId?:number): Promise\<Array\<AbilityInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#queryAbilityInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback\<Array\<BundleInfo>>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback\<Array\<BundleInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback\<Array\<BundleInfo>>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback\<Array\<BundleInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, userId?: number) : Promise\<Array\<BundleInfo>>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllBundleInfo(bundleFlag: BundleFlag, userId?: number) : Promise\<Array\<BundleInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllBundleInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<ApplicationInfo>>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<ApplicationInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo>>) : void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, userId?: number) : Promise\<Array\<ApplicationInfo>>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAllApplicationInfo(bundleFlags: number, userId?: number) : Promise\<Array\<ApplicationInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAllApplicationInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getNameForUid(uid: number, callback: AsyncCallback\<string>) : void<br>旧版本信息：|类名：bundle;<br>方法or属性：function getNameForUid(uid: number, callback: AsyncCallback\<string>) : void<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getNameForUid|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getNameForUid(uid: number) : Promise\<string>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getNameForUid(uid: number) : Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getNameForUid|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>) : void<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>) : void<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getBundleArchiveInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number) : Promise\<BundleInfo>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getBundleArchiveInfo(hapFilePath: string, bundleFlags: number) : Promise\<BundleInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getBundleArchiveInfo|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getLaunchWantForBundle|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getLaunchWantForBundle(bundleName: string): Promise\<Want>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getLaunchWantForBundle(bundleName: string): Promise\<Want>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getLaunchWantForBundle|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#cleanBundleCacheFiles|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string): Promise\<void>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function cleanBundleCacheFiles(bundleName: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#cleanBundleCacheFiles|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#setApplicationEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnable: boolean): Promise\<void>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function setApplicationEnabled(bundleName: string, isEnable: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#setApplicationEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#setAbilityEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise\<void>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#setAbilityEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getPermissionDef|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getPermissionDef(permissionName: string): Promise\<PermissionDef>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getPermissionDef(permissionName: string): Promise\<PermissionDef>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getPermissionDef|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAbilityLabel|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#getAbilityLabel|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager#getMediaContent|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>;<br>新版本信息：9<br>代替接口： ohos.resourceManager#getMediaContent|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#isAbilityEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo): Promise\<boolean>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function isAbilityEnabled(info: AbilityInfo): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#isAbilityEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：bundle;<br>方法or属性：function isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#isApplicationEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：bundle;<br>方法or属性：function isApplicationEnabled(bundleName: string): Promise\<boolean>;<br>旧版本信息：|类名：bundle;<br>方法or属性：function isApplicationEnabled(bundleName: string): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager#isApplicationEnabled|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：enum BundleFlag<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：enum BundleFlag<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_DEFAULT = 0x00000000<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_DEFAULT = 0x00000000<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_METADATA = 0x00000020<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_METADATA = 0x00000020<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_METADATA = 0x00000040<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_METADATA = 0x00000040<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_SYSTEMAPP_ONLY = 0x00000080<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_SYSTEMAPP_ONLY = 0x00000080<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_DISABLE = 0x00000100<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_ABILITY_INFO_WITH_DISABLE = 0x00000100<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_DISABLE = 0x00000200<br>旧版本信息：|类名：BundleFlag;<br>方法or属性：GET_APPLICATION_INFO_WITH_DISABLE = 0x00000200<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleFlag,|@ohos.bundle.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：export enum ColorMode<br>旧版本信息：|类名：ColorMode;<br>方法or属性：export enum ColorMode<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：AUTO_MODE = -1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：AUTO_MODE = -1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：DARK_MODE = 0<br>旧版本信息：|类名：ColorMode;<br>方法or属性：DARK_MODE = 0<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：ColorMode;<br>方法or属性：LIGHT_MODE = 1<br>旧版本信息：|类名：ColorMode;<br>方法or属性：LIGHT_MODE = 1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：GrantStatus;<br>方法or属性：export enum GrantStatus<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：export enum GrantStatus<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionGrantState|@ohos.bundle.d.ts|
|废弃版本有变化|类名：GrantStatus;<br>方法or属性：PERMISSION_DENIED = -1<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：PERMISSION_DENIED = -1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionGrantState|@ohos.bundle.d.ts|
|废弃版本有变化|类名：GrantStatus;<br>方法or属性：PERMISSION_GRANTED = 0<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：PERMISSION_GRANTED = 0<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionGrantState|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilityType;<br>方法or属性：export enum AbilityType<br>旧版本信息：|类名：AbilityType;<br>方法or属性：export enum AbilityType<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilityType;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：AbilityType;<br>方法or属性：UNKNOWN<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilityType;<br>方法or属性：PAGE<br>旧版本信息：|类名：AbilityType;<br>方法or属性：PAGE<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilityType;<br>方法or属性：SERVICE<br>旧版本信息：|类名：AbilityType;<br>方法or属性：SERVICE<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilityType;<br>方法or属性：DATA<br>旧版本信息：|类名：AbilityType;<br>方法or属性：DATA<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilitySubType;<br>方法or属性：export enum AbilitySubType<br>旧版本信息：|类名：AbilitySubType;<br>方法or属性：export enum AbilitySubType<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilitySubType;<br>方法or属性：UNSPECIFIED = 0<br>旧版本信息：|类名：AbilitySubType;<br>方法or属性：UNSPECIFIED = 0<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：AbilitySubType;<br>方法or属性：CA = 1<br>旧版本信息：|类名：AbilitySubType;<br>方法or属性：CA = 1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：DisplayOrientation;<br>方法or属性：export enum DisplayOrientation<br>旧版本信息：|类名：DisplayOrientation;<br>方法or属性：export enum DisplayOrientation<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.DisplayOrientation|@ohos.bundle.d.ts|
|废弃版本有变化|类名：DisplayOrientation;<br>方法or属性：UNSPECIFIED<br>旧版本信息：|类名：DisplayOrientation;<br>方法or属性：UNSPECIFIED<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.DisplayOrientation|@ohos.bundle.d.ts|
|废弃版本有变化|类名：DisplayOrientation;<br>方法or属性：LANDSCAPE<br>旧版本信息：|类名：DisplayOrientation;<br>方法or属性：LANDSCAPE<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.DisplayOrientation|@ohos.bundle.d.ts|
|废弃版本有变化|类名：DisplayOrientation;<br>方法or属性：PORTRAIT<br>旧版本信息：|类名：DisplayOrientation;<br>方法or属性：PORTRAIT<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.DisplayOrientation|@ohos.bundle.d.ts|
|废弃版本有变化|类名：DisplayOrientation;<br>方法or属性：FOLLOW_RECENT<br>旧版本信息：|类名：DisplayOrientation;<br>方法or属性：FOLLOW_RECENT<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.DisplayOrientation|@ohos.bundle.d.ts|
|废弃版本有变化|类名：LaunchMode;<br>方法or属性：export enum LaunchMode<br>旧版本信息：|类名：LaunchMode;<br>方法or属性：export enum LaunchMode<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LaunchType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：LaunchMode;<br>方法or属性：SINGLETON = 0<br>旧版本信息：|类名：LaunchMode;<br>方法or属性：SINGLETON = 0<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LaunchType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：LaunchMode;<br>方法or属性：STANDARD = 1<br>旧版本信息：|类名：LaunchMode;<br>方法or属性：STANDARD = 1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LaunchType|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleOptions;<br>方法or属性：export interface BundleOptions<br>旧版本信息：|类名：BundleOptions;<br>方法or属性：export interface BundleOptions<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：BundleOptions;<br>方法or属性：userId?: number;<br>旧版本信息：|类名：BundleOptions;<br>方法or属性：userId?: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：export enum InstallErrorCode<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：export enum InstallErrorCode<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：SUCCESS = 0<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：SUCCESS = 0<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE = 1<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE = 1<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_ABORTED = 2<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_ABORTED = 2<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_INVALID = 3<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_INVALID = 3<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_STORAGE = 5<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_STORAGE = 5<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE = 7<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE = 7<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_RECOVER_FAILURE_INVALID = 0x0D<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_RECOVER_FAILURE_INVALID = 0x0D<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_ABILITY_NOT_FOUND = 0x40<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_ABILITY_NOT_FOUND = 0x40<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_BMS_SERVICE_ERROR = 0x41<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_BMS_SERVICE_ERROR = 0x41<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_FAILED_NO_SPACE_LEFT = 0x42<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_FAILED_NO_SPACE_LEFT = 0x42<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_PERMISSION_DENIED = 0x44<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_INSTALL_PERMISSION_DENIED = 0x44<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_PERMISSION_DENIED = 0x45<br>旧版本信息：|类名：InstallErrorCode;<br>方法or属性：STATUS_UNINSTALL_PERMISSION_DENIED = 0x45<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager|@ohos.bundle.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：declare innerBundleManager<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：declare innerBundleManager<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getLauncherAbilityInfo|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getLauncherAbilityInfos(bundleName: string, userId: number) : Promise\<Array\<LauncherAbilityInfo>>;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getLauncherAbilityInfos(bundleName: string, userId: number) : Promise\<Array\<LauncherAbilityInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getLauncherAbilityInfo|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback\<string>) : void;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback\<string>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleMonitor#on|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback): Promise\<string>;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleMonitor#on|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function off(type:"BundleStatusChange", callback: AsyncCallback\<string>) : void;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function off(type:"BundleStatusChange", callback: AsyncCallback\<string>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleMonitor#off|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function off(type:"BundleStatusChange"): Promise\<string>;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function off(type:"BundleStatusChange"): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleMonitor#off|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getAllLauncherAbilityInfos|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getAllLauncherAbilityInfos(userId: number) : Promise\<Array\<LauncherAbilityInfo>>;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getAllLauncherAbilityInfos(userId: number) : Promise\<Array\<LauncherAbilityInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getAllLauncherAbilityInfos|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getShortcutInfos(bundleName :string, callback: AsyncCallback\<Array\<ShortcutInfo>>) : void;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getShortcutInfos(bundleName :string, callback: AsyncCallback\<Array\<ShortcutInfo>>) : void;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getShortcutInfo|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：innerBundleManager;<br>方法or属性：function getShortcutInfos(bundleName : string) : Promise\<Array\<ShortcutInfo>>;<br>旧版本信息：|类名：innerBundleManager;<br>方法or属性：function getShortcutInfos(bundleName : string) : Promise\<Array\<ShortcutInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager#getShortcutInfo|@ohos.bundle.innerBundleManager.d.ts|
|废弃版本有变化|类名：distributedBundle;<br>方法or属性：declare distributedBundle<br>旧版本信息：|类名：distributedBundle;<br>方法or属性：declare distributedBundle<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager|@ohos.distributedBundle.d.ts|
|废弃版本有变化|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void;<br>旧版本信息：|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager#getRemoteAbilityInfo|@ohos.distributedBundle.d.ts|
|废弃版本有变化|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>;<br>旧版本信息：|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager#getRemoteAbilityInfo|@ohos.distributedBundle.d.ts|
|废弃版本有变化|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfos(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;<br>旧版本信息：|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfos(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager#getRemoteAbilityInfo|@ohos.distributedBundle.d.ts|
|废弃版本有变化|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfos(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>;<br>旧版本信息：|类名：distributedBundle;<br>方法or属性：function getRemoteAbilityInfos(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager#getRemoteAbilityInfo|@ohos.distributedBundle.d.ts|
|废弃版本有变化|类名：zlib;<br>方法or属性：function zipFile(inFile:string, outFile:string, options: Options): Promise\<void>;<br>旧版本信息：|类名：zlib;<br>方法or属性：function zipFile(inFile:string, outFile:string, options: Options): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.zlib#compressFile|@ohos.zlib.d.ts|
|废弃版本有变化|类名：zlib;<br>方法or属性：function unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>;<br>旧版本信息：|类名：zlib;<br>方法or属性：function unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.zlib#decompressFile|@ohos.zlib.d.ts|
|废弃版本有变化|类名：ErrorCode;<br>方法or属性：export enum ErrorCode<br>旧版本信息：|类名：ErrorCode;<br>方法or属性：export enum ErrorCode<br>新版本信息：9<br>代替接口：|@ohos.zlib.d.ts|
|废弃版本有变化|类名：ErrorCode;<br>方法or属性：ERROR_CODE_OK = 0<br>旧版本信息：|类名：ErrorCode;<br>方法or属性：ERROR_CODE_OK = 0<br>新版本信息：9<br>代替接口：|@ohos.zlib.d.ts|
|废弃版本有变化|类名：ErrorCode;<br>方法or属性：ERROR_CODE_ERRNO = -1<br>旧版本信息：|类名：ErrorCode;<br>方法or属性：ERROR_CODE_ERRNO = -1<br>新版本信息：9<br>代替接口：|@ohos.zlib.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledResponse;<br>方法or属性：export interface CheckPackageHasInstalledResponse<br>旧版本信息：|类名：CheckPackageHasInstalledResponse;<br>方法or属性：export interface CheckPackageHasInstalledResponse<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledResponse;<br>方法or属性：result: boolean;<br>旧版本信息：|类名：CheckPackageHasInstalledResponse;<br>方法or属性：result: boolean;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledOptions;<br>方法or属性：export interface CheckPackageHasInstalledOptions<br>旧版本信息：|类名：CheckPackageHasInstalledOptions;<br>方法or属性：export interface CheckPackageHasInstalledOptions<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledOptions;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：CheckPackageHasInstalledOptions;<br>方法or属性：bundleName: string;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledOptions;<br>方法or属性：success?: (data: CheckPackageHasInstalledResponse) => void;<br>旧版本信息：|类名：CheckPackageHasInstalledOptions;<br>方法or属性：success?: (data: CheckPackageHasInstalledResponse) => void;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>旧版本信息：|类名：CheckPackageHasInstalledOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：CheckPackageHasInstalledOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：CheckPackageHasInstalledOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：Package;<br>方法or属性：export default class Package<br>旧版本信息：|类名：Package;<br>方法or属性：export default class Package<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：Package;<br>方法or属性：static hasInstalled(options: CheckPackageHasInstalledOptions): void;<br>旧版本信息：|类名：Package;<br>方法or属性：static hasInstalled(options: CheckPackageHasInstalledOptions): void;<br>新版本信息：9<br>代替接口：|@system.package.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：export interface AbilityInfo<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：export interface AbilityInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly bundleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly label: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly label: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly description: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly description: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly icon: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly icon: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly labelId: number;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly labelId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly descriptionId: number;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly descriptionId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly iconId: number;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly iconId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly moduleName: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly moduleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly process: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly process: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly targetAbility: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly targetAbility: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly backgroundModes: number;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly backgroundModes: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly isVisible: boolean;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly isVisible: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly formEnabled: boolean;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly formEnabled: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly type: bundle.AbilityType;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly type: bundle.AbilityType;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly subType: bundle.AbilitySubType;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly subType: bundle.AbilitySubType;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly orientation: bundle.DisplayOrientation;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly orientation: bundle.DisplayOrientation;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly launchMode: bundle.LaunchMode;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly launchMode: bundle.LaunchMode;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly permissions: Array\<string>;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly permissions: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly deviceCapabilities: Array\<string>;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly deviceCapabilities: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly readPermission: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly readPermission: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly writePermission: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly writePermission: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly uri: string;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly uri: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly metaData: Array\<CustomizeData>;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly metaData: Array\<CustomizeData>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：AbilityInfo;<br>方法or属性：readonly enabled: boolean;<br>旧版本信息：|类名：AbilityInfo;<br>方法or属性：readonly enabled: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.AbilityInfo|abilityInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：export interface ApplicationInfo<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：export interface ApplicationInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly description: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly description: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly descriptionId: number;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly descriptionId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly systemApp: boolean;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly systemApp: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly enabled: boolean;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly enabled: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly label: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly label: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly labelId: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly labelId: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo.labelIndex|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly icon: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly icon: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly iconId: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly iconId: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo.iconIndex|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly process: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly process: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly supportedModes: number;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly supportedModes: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly moduleSourceDirs: Array\<string>;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly moduleSourceDirs: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly permissions: Array\<string>;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly permissions: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly moduleInfos: Array\<ModuleInfo>;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly moduleInfos: Array\<ModuleInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly entryDir: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly entryDir: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly codePath: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly codePath: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly metaData: Map\<string, Array\<CustomizeData>>;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly metaData: Map\<string, Array\<CustomizeData>>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly removable: boolean;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly removable: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly accessTokenId: number;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly accessTokenId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly uid: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：ApplicationInfo;<br>方法or属性：readonly entityType: string;<br>旧版本信息：|类名：ApplicationInfo;<br>方法or属性：readonly entityType: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ApplicationInfo|applicationInfo.d.ts|
|废弃版本有变化|类名：UsedScene;<br>方法or属性：export interface UsedScene<br>旧版本信息：|类名：UsedScene;<br>方法or属性：export interface UsedScene<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.UsedScene|bundleInfo.d.ts|
|废弃版本有变化|类名：UsedScene;<br>方法or属性：abilities: Array\<string>;<br>旧版本信息：|类名：UsedScene;<br>方法or属性：abilities: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.UsedScene|bundleInfo.d.ts|
|废弃版本有变化|类名：UsedScene;<br>方法or属性：when: string;<br>旧版本信息：|类名：UsedScene;<br>方法or属性：when: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.UsedScene|bundleInfo.d.ts|
|废弃版本有变化|类名：ReqPermissionDetail;<br>方法or属性：export interface ReqPermissionDetail<br>旧版本信息：|类名：ReqPermissionDetail;<br>方法or属性：export interface ReqPermissionDetail<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ReqPermissionDetail|bundleInfo.d.ts|
|废弃版本有变化|类名：ReqPermissionDetail;<br>方法or属性：name: string;<br>旧版本信息：|类名：ReqPermissionDetail;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ReqPermissionDetail|bundleInfo.d.ts|
|废弃版本有变化|类名：ReqPermissionDetail;<br>方法or属性：reason: string;<br>旧版本信息：|类名：ReqPermissionDetail;<br>方法or属性：reason: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ReqPermissionDetail|bundleInfo.d.ts|
|废弃版本有变化|类名：ReqPermissionDetail;<br>方法or属性：usedScene: UsedScene;<br>旧版本信息：|类名：ReqPermissionDetail;<br>方法or属性：usedScene: UsedScene;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ReqPermissionDetail|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：export interface BundleInfo<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：export interface BundleInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly type: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly type: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly appId: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly appId: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly uid: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly installTime: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly installTime: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly updateTime: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly updateTime: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly appInfo: ApplicationInfo;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly appInfo: ApplicationInfo;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly abilityInfos: Array\<AbilityInfo>;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly abilityInfos: Array\<AbilityInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly reqPermissions: Array\<string>;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly reqPermissions: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly reqPermissionDetails: Array\<ReqPermissionDetail>;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly reqPermissionDetails: Array\<ReqPermissionDetail>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly vendor: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly vendor: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly versionCode: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly versionCode: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly versionName: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly versionName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly compatibleVersion: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly compatibleVersion: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly targetVersion: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly targetVersion: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly isCompressNativeLibs: boolean;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly isCompressNativeLibs: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly hapModuleInfos: Array\<HapModuleInfo>;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly hapModuleInfos: Array\<HapModuleInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly entryModuleName: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly entryModuleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly cpuAbi: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly cpuAbi: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly isSilentInstallation: string;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly isSilentInstallation: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly minCompatibleVersionCode: number;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly minCompatibleVersionCode: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly entryInstallationFree: boolean;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly entryInstallationFree: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：BundleInfo;<br>方法or属性：readonly reqPermissionStates: Array\<number>;<br>旧版本信息：|类名：BundleInfo;<br>方法or属性：readonly reqPermissionStates: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.BundleInfo|bundleInfo.d.ts|
|废弃版本有变化|类名：InstallParam;<br>方法or属性：export interface InstallParam<br>旧版本信息：|类名：InstallParam;<br>方法or属性：export interface InstallParam<br>新版本信息：9<br>代替接口： ohos.bundle.installer#InstallParam|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallParam;<br>方法or属性：userId: number;<br>旧版本信息：|类名：InstallParam;<br>方法or属性：userId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.InstallParam#userId|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallParam;<br>方法or属性：installFlag: number;<br>旧版本信息：|类名：InstallParam;<br>方法or属性：installFlag: number;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.InstallParam#installFlag|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallParam;<br>方法or属性：isKeepData: boolean;<br>旧版本信息：|类名：InstallParam;<br>方法or属性：isKeepData: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.InstallParam#isKeepData|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallStatus;<br>方法or属性：export interface InstallStatus<br>旧版本信息：|类名：InstallStatus;<br>方法or属性：export interface InstallStatus<br>新版本信息：9<br>代替接口：|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallStatus;<br>方法or属性：status: bundle.InstallErrorCode;<br>旧版本信息：|类名：InstallStatus;<br>方法or属性：status: bundle.InstallErrorCode;<br>新版本信息：9<br>代替接口：|bundleInstaller.d.ts|
|废弃版本有变化|类名：InstallStatus;<br>方法or属性：statusMessage: string;<br>旧版本信息：|类名：InstallStatus;<br>方法or属性：statusMessage: string;<br>新版本信息：9<br>代替接口：|bundleInstaller.d.ts|
|废弃版本有变化|类名：BundleInstaller;<br>方法or属性：export interface BundleInstaller<br>旧版本信息：|类名：BundleInstaller;<br>方法or属性：export interface BundleInstaller<br>新版本信息：9<br>代替接口： ohos.bundle.installer#BundleInstaller|bundleInstaller.d.ts|
|废弃版本有变化|类名：BundleInstaller;<br>方法or属性：install(bundleFilePaths: Array\<string>, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>旧版本信息：|类名：BundleInstaller;<br>方法or属性：install(bundleFilePaths: Array\<string>, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.BundleInstaller#install|bundleInstaller.d.ts|
|废弃版本有变化|类名：BundleInstaller;<br>方法or属性：uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>旧版本信息：|类名：BundleInstaller;<br>方法or属性：uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.BundleInstaller#uninstall|bundleInstaller.d.ts|
|废弃版本有变化|类名：BundleInstaller;<br>方法or属性：recover(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>旧版本信息：|类名：BundleInstaller;<br>方法or属性：recover(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void;<br>新版本信息：9<br>代替接口： ohos.bundle.installer.BundleInstaller#recover|bundleInstaller.d.ts|
|废弃版本有变化|类名：BundleStatusCallback;<br>方法or属性：export interface BundleStatusCallback<br>旧版本信息：|类名：BundleStatusCallback;<br>方法or属性：export interface BundleStatusCallback<br>新版本信息：9<br>代替接口：|bundleStatusCallback.d.ts|
|废弃版本有变化|类名：BundleStatusCallback;<br>方法or属性：add: (bundleName : string, userId: number) => void;<br>旧版本信息：|类名：BundleStatusCallback;<br>方法or属性：add: (bundleName : string, userId: number) => void;<br>新版本信息：9<br>代替接口：|bundleStatusCallback.d.ts|
|废弃版本有变化|类名：BundleStatusCallback;<br>方法or属性：update: (bundleName : string, userId: number) => void;<br>旧版本信息：|类名：BundleStatusCallback;<br>方法or属性：update: (bundleName : string, userId: number) => void;<br>新版本信息：9<br>代替接口：|bundleStatusCallback.d.ts|
|废弃版本有变化|类名：BundleStatusCallback;<br>方法or属性：remove: (bundleName : string, userId: number) => void;<br>旧版本信息：|类名：BundleStatusCallback;<br>方法or属性：remove: (bundleName : string, userId: number) => void;<br>新版本信息：9<br>代替接口：|bundleStatusCallback.d.ts|
|废弃版本有变化|类名：CustomizeData;<br>方法or属性：export interface CustomizeData<br>旧版本信息：|类名：CustomizeData;<br>方法or属性：export interface CustomizeData<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.Metadata|customizeData.d.ts|
|废弃版本有变化|类名：CustomizeData;<br>方法or属性：name: string;<br>旧版本信息：|类名：CustomizeData;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.Metadata|customizeData.d.ts|
|废弃版本有变化|类名：CustomizeData;<br>方法or属性：value: string;<br>旧版本信息：|类名：CustomizeData;<br>方法or属性：value: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.Metadata|customizeData.d.ts|
|废弃版本有变化|类名：CustomizeData;<br>方法or属性：extra: string;<br>旧版本信息：|类名：CustomizeData;<br>方法or属性：extra: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.Metadata|customizeData.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：export interface ElementName<br>旧版本信息：|类名：ElementName;<br>方法or属性：export interface ElementName<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：ElementName;<br>方法or属性：deviceId?: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：ElementName;<br>方法or属性：bundleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：abilityName: string;<br>旧版本信息：|类名：ElementName;<br>方法or属性：abilityName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：uri?: string;<br>旧版本信息：|类名：ElementName;<br>方法or属性：uri?: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：ElementName;<br>方法or属性：shortName?: string;<br>旧版本信息：|类名：ElementName;<br>方法or属性：shortName?: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.ElementName|elementName.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：export interface HapModuleInfo<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：export interface HapModuleInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly name: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly name: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly description: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly description: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly descriptionId: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly descriptionId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly icon: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly icon: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly label: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly label: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly labelId: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly labelId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly iconId: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly iconId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly backgroundImg: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly backgroundImg: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly supportedModes: number;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly supportedModes: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly reqCapabilities: Array\<string>;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly reqCapabilities: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly deviceTypes: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly abilityInfo: Array\<AbilityInfo>;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly abilityInfo: Array\<AbilityInfo>;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly moduleName: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly moduleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly mainAbilityName: string;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly mainAbilityName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：HapModuleInfo;<br>方法or属性：readonly installationFree: boolean;<br>旧版本信息：|类名：HapModuleInfo;<br>方法or属性：readonly installationFree: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|hapModuleInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：export interface LauncherAbilityInfo<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：export interface LauncherAbilityInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly applicationInfo: ApplicationInfo;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly elementName : ElementName;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly elementName : ElementName;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly labelId: number;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly labelId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly iconId: number;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly iconId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly userId: number;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly userId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：LauncherAbilityInfo;<br>方法or属性：readonly installTime : number;<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：readonly installTime : number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.LauncherAbilityInfo|launcherAbilityInfo.d.ts|
|废弃版本有变化|类名：ModuleInfo;<br>方法or属性：export interface ModuleInfo<br>旧版本信息：|类名：ModuleInfo;<br>方法or属性：export interface ModuleInfo<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|moduleInfo.d.ts|
|废弃版本有变化|类名：ModuleInfo;<br>方法or属性：readonly moduleName: string;<br>旧版本信息：|类名：ModuleInfo;<br>方法or属性：readonly moduleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|moduleInfo.d.ts|
|废弃版本有变化|类名：ModuleInfo;<br>方法or属性：readonly moduleSourceDir: string;<br>旧版本信息：|类名：ModuleInfo;<br>方法or属性：readonly moduleSourceDir: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.HapModuleInfo|moduleInfo.d.ts|
|废弃版本有变化|类名：PermissionDef;<br>方法or属性：export interface PermissionDef<br>旧版本信息：|类名：PermissionDef;<br>方法or属性：export interface PermissionDef<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionDef|PermissionDef.d.ts|
|废弃版本有变化|类名：PermissionDef;<br>方法or属性：permissionName: string;<br>旧版本信息：|类名：PermissionDef;<br>方法or属性：permissionName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionDef|PermissionDef.d.ts|
|废弃版本有变化|类名：PermissionDef;<br>方法or属性：grantMode: number;<br>旧版本信息：|类名：PermissionDef;<br>方法or属性：grantMode: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionDef|PermissionDef.d.ts|
|废弃版本有变化|类名：PermissionDef;<br>方法or属性：labelId: number;<br>旧版本信息：|类名：PermissionDef;<br>方法or属性：labelId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionDef|PermissionDef.d.ts|
|废弃版本有变化|类名：PermissionDef;<br>方法or属性：descriptionId: number;<br>旧版本信息：|类名：PermissionDef;<br>方法or属性：descriptionId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.bundleManager.PermissionDef|PermissionDef.d.ts|
|废弃版本有变化|类名：RemoteAbilityInfo;<br>方法or属性：export interface RemoteAbilityInfo<br>旧版本信息：|类名：RemoteAbilityInfo;<br>方法or属性：export interface RemoteAbilityInfo<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager.RemoteAbilityInfo|remoteAbilityInfo.d.ts|
|废弃版本有变化|类名：RemoteAbilityInfo;<br>方法or属性：readonly elementName: ElementName;<br>旧版本信息：|类名：RemoteAbilityInfo;<br>方法or属性：readonly elementName: ElementName;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager.RemoteAbilityInfo|remoteAbilityInfo.d.ts|
|废弃版本有变化|类名：RemoteAbilityInfo;<br>方法or属性：readonly label: string;<br>旧版本信息：|类名：RemoteAbilityInfo;<br>方法or属性：readonly label: string;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager.RemoteAbilityInfo|remoteAbilityInfo.d.ts|
|废弃版本有变化|类名：RemoteAbilityInfo;<br>方法or属性：readonly icon: string;<br>旧版本信息：|类名：RemoteAbilityInfo;<br>方法or属性：readonly icon: string;<br>新版本信息：9<br>代替接口： ohos.bundle.distributedBundleManager.RemoteAbilityInfo|remoteAbilityInfo.d.ts|
|废弃版本有变化|类名：ShortcutWant;<br>方法or属性：export interface ShortcutWant<br>旧版本信息：|类名：ShortcutWant;<br>方法or属性：export interface ShortcutWant<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutWant|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutWant;<br>方法or属性：readonly targetBundle: string;<br>旧版本信息：|类名：ShortcutWant;<br>方法or属性：readonly targetBundle: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutWant|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutWant;<br>方法or属性：readonly targetClass: string;<br>旧版本信息：|类名：ShortcutWant;<br>方法or属性：readonly targetClass: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutWant|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：export interface ShortcutInfo<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：export interface ShortcutInfo<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly id: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly id: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly bundleName: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly hostAbility: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly hostAbility: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly icon: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly icon: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly iconId: number;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly iconId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly label: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly label: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly labelId: number;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly labelId: number;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly disableMessage: string;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly disableMessage: string;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly wants: Array\<ShortcutWant>;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly wants: Array\<ShortcutWant>;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly isStatic?: boolean<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly isStatic?: boolean<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly isHomeShortcut?: boolean;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly isHomeShortcut?: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|废弃版本有变化|类名：ShortcutInfo;<br>方法or属性：readonly isEnabled?: boolean;<br>旧版本信息：|类名：ShortcutInfo;<br>方法or属性：readonly isEnabled?: boolean;<br>新版本信息：9<br>代替接口： ohos.bundle.launcherBundleManager.ShortcutInfo|shortcutInfo.d.ts|
|访问级别有变化|类名：LauncherAbilityInfo;<br>方法or属性：export interface LauncherAbilityInfo<br>旧版本信息：|类名：LauncherAbilityInfo;<br>方法or属性：export interface LauncherAbilityInfo<br>新版本信息：systemapi|launcherAbilityInfo.d.ts|
|model有变化|类名：AbilityInfo;<br>方法or属性：readonly orientation: bundle.DisplayOrientation;<br>旧版本信息：FAModelOnly|类名：AbilityInfo;<br>方法or属性：readonly orientation: bundle.DisplayOrientation;<br>新版本信息：|abilityInfo.d.ts|
