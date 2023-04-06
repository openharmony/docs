# 包管理子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，包管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| abilityInfo | AbilityInfo | readonly minWindowHeight: number; | 新增 |
| abilityInfo | AbilityInfo | readonly maxWindowHeight: number; | 新增 |
| abilityInfo | AbilityInfo | readonly minWindowWidth: number; | 新增 |
| abilityInfo | AbilityInfo | readonly maxWindowWidth: number; | 新增 |
| abilityInfo | AbilityInfo | readonly minWindowRatio: number; | 新增 |
| abilityInfo | AbilityInfo | readonly maxWindowRatio: number; | 新增 |
| abilityInfo | AbilityInfo | readonly supportWindowMode: Array\<bundle.SupportWindowMode>; | 新增 |
| bundleInstaller | InstallParam | crowdtestDeadline?: number; | 新增 |
| bundleInstaller | InstallParam | hashParams?: Array\<HashParam>; | 新增 |
| bundleInstaller | HashParam | hashValue: string; | 新增 |
| bundleInstaller | HashParam | moduleName: string; | 新增 |
| dispatchInfo | DispatchInfo | readonly dispatchAPI: string; | 新增 |
| dispatchInfo | DispatchInfo | readonly verison: string; | 新增 |
| hapModuleInfo | HapModuleInfo | readonly hashValue: string; | 新增 |
| ohos.bundle | bundle | getDisposedStatus(bundleName: string, callback: AsyncCallback\<number>): void;<br>getDisposedStatus(bundleName: string): Promise\<number>; | 新增 |
| ohos.bundle | bundle | setDisposedStatus(bundleName: string, status: number, callback: AsyncCallback\<void>): void;<br>setDisposedStatus(bundleName: string, status: number): Promise\<void>; | 新增 |
| ohos.bundle | bundle | getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string>>; | 新增 |
| ohos.bundle | bundle | getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string>>; | 新增 |
| ohos.bundle | bundle | getDispatcherVersion(callback: AsyncCallback\<DispatchInfo>): void;<br>getDispatcherVersion(): Promise\<DispatchInfo>; | 新增 |
| ohos.bundle | bundle | getBundlePackInfo(bundleName: string, bundlePackFlag: pack.BundlePackFlag, callback: AsyncCallback\<pack.BundlePackInfo>): void;<br>getBundlePackInfo(bundleName: string, bundlePackFlag: pack.BundlePackFlag): Promise\<pack.BundlePackInfo>; | 新增 |
| ohos.bundle | SupportWindowMode | FLOATING = 2 | 新增 |
| ohos.bundle | SupportWindowMode | SPLIT = 1 | 新增 |
| ohos.bundle | SupportWindowMode | FULL_SCREEN = 0 | 新增 |
| ohos.bundle | ExtensionAbilityType | ENTERPRISE_ADMIN = 11 | 新增 |
| ohos.bundle | DisplayOrientation | LOCKED | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_PORTRAIT_RESTRICTED | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_LANDSCAPE_RESTRICTED | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_RESTRICTED | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_PORTRAIT | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_LANDSCAPE | 新增 |
| ohos.bundle | DisplayOrientation | AUTO_ROTATION | 新增 |
| ohos.bundle | DisplayOrientation | PORTRAIT_INVERTED | 新增 |
| ohos.bundle | DisplayOrientation | LANDSCAPE_INVERTED | 新增 |
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_CERTIFICATE_FINGERPRINT = 0x00000400 | 新增 |
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_HASH_VALUE = 0x00000030 | 新增 |
| ohos.bundle.defaultAppManager | defaultAppManager | resetDefaultApplication(type: string, userId?: number): Promise\<void>;<br>resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>): void;<br>resetDefaultApplication(type: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.bundle.defaultAppManager | defaultAppManager | setDefaultApplication(type: string, elementName: ElementName, userId?: number): Promise\<void>;<br>setDefaultApplication(type: string, elementName: ElementName, userId: number, callback: AsyncCallback\<void>): void;<br>setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.bundle.defaultAppManager | defaultAppManager | getDefaultApplication(type: string, userId?: number): Promise\<BundleInfo>;<br>getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>): void;<br>getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>): void; | 新增 |
| ohos.bundle.defaultAppManager | defaultAppManager | isDefaultApplication(type: string): Promise\<boolean>;<br>isDefaultApplication(type: string, callback: AsyncCallback\<boolean>): void; | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | PPT = "PPT" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | EXCEL = "EXCEL" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | WORD = "WORD" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | PDF = "PDF" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | VIDEO = "VIDEO" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | AUDIO = "AUDIO" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | IMAGE = "IMAGE" | 新增 |
| ohos.bundle.defaultAppManager | ApplicationType | BROWSER = "BROWSER" | 新增 |
| packInfo | BundlePackFlag | GET_MODULE_SUMMARY = 0x00000004 | 新增 |
| packInfo | BundlePackFlag | GET_BUNDLE_SUMMARY = 0x00000002 | 新增 |
| packInfo | BundlePackFlag | GET_PACKAGES = 0x00000001 | 新增 |
| packInfo | BundlePackFlag | GET_PACK_INFO_ALL = 0x00000000 | 新增 |
| packInfo | ApiVersion | readonly target: number; | 新增 |
| packInfo | ApiVersion | readonly compatible: number; | 新增 |
| packInfo | ApiVersion | readonly releaseType: string; | 新增 |
| packInfo | Version | readonly code: number; | 新增 |
| packInfo | Version | readonly name: string; | 新增 |
| packInfo | Version | readonly minCompatibleVersionCode: number; | 新增 |
| packInfo | AbilityFormInfo | readonly defaultDimension: number; | 新增 |
| packInfo | AbilityFormInfo | readonly supportDimensions: Array\<number>; | 新增 |
| packInfo | AbilityFormInfo | readonly updateDuration: number; | 新增 |
| packInfo | AbilityFormInfo | readonly scheduledUpdateTime: string; | 新增 |
| packInfo | AbilityFormInfo | readonly updateEnabled: boolean; | 新增 |
| packInfo | AbilityFormInfo | readonly type: string; | 新增 |
| packInfo | AbilityFormInfo | readonly name: string; | 新增 |
| packInfo | ModuleAbilityInfo | readonly forms: Array\<AbilityFormInfo>; | 新增 |
| packInfo | ModuleAbilityInfo | readonly visible: boolean; | 新增 |
| packInfo | ModuleAbilityInfo | readonly label: string; | 新增 |
| packInfo | ModuleAbilityInfo | readonly name: string; | 新增 |
| packInfo | ModuleDistroInfo | readonly moduleType: string; | 新增 |
| packInfo | ModuleDistroInfo | readonly moduleName: string; | 新增 |
| packInfo | ModuleDistroInfo | readonly installationFree: boolean; | 新增 |
| packInfo | ModuleDistroInfo | readonly deliveryWithInstall: boolean; | 新增 |
| packInfo | ModuleDistroInfo | readonly mainAbility: string; | 新增 |
| packInfo | ModuleConfigInfo | readonly extensionAbilities: Array\<ExtensionAbilities>; | 新增 |
| packInfo | ModuleConfigInfo | readonly abilities: Array\<ModuleAbilityInfo>; | 新增 |
| packInfo | ModuleConfigInfo | readonly distro: ModuleDistroInfo; | 新增 |
| packInfo | ModuleConfigInfo | readonly deviceType: Array\<string>; | 新增 |
| packInfo | ModuleConfigInfo | readonly apiVersion: ApiVersion; | 新增 |
| packInfo | ExtensionAbilities | readonly forms: Array\<AbilityFormInfo>; | 新增 |
| packInfo | ExtensionAbilities | readonly name: string; | 新增 |
| packInfo | BundleConfigInfo | readonly version: Version; | 新增 |
| packInfo | BundleConfigInfo | readonly bundleName: string; | 新增 |
| packInfo | PackageSummary | readonly modules: Array\<ModuleConfigInfo>; | 新增 |
| packInfo | PackageSummary | readonly app: BundleConfigInfo; | 新增 |
| packInfo | PackageConfig | readonly deliveryWithInstall: boolean; | 新增 |
| packInfo | PackageConfig | readonly moduleType: string; | 新增 |
| packInfo | PackageConfig | readonly name: string; | 新增 |
| packInfo | PackageConfig | readonly deviceType: Array\<string>; | 新增 |
| packInfo | BundlePackInfo | readonly summary: PackageSummary; | 新增 |
| packInfo | BundlePackInfo | readonly packages: Array\<PackageConfig>; | 新增 |
| shortcutInfo | ShortcutInfo | readonly moduleName?: string; | 新增 |
| shortcutInfo | ShortcutWant | readonly targetModule: string; | 新增 |