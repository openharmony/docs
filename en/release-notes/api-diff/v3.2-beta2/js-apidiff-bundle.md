# JS API Changes of the Bundle Management Framework

The table below lists the APIs changes of the bundle management framework in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| abilityInfo | AbilityInfo | readonly minWindowHeight: number; | Added|
| abilityInfo | AbilityInfo | readonly maxWindowHeight: number; | Added|
| abilityInfo | AbilityInfo | readonly minWindowWidth: number; | Added|
| abilityInfo | AbilityInfo | readonly maxWindowWidth: number; | Added|
| abilityInfo | AbilityInfo | readonly minWindowRatio: number; | Added|
| abilityInfo | AbilityInfo | readonly maxWindowRatio: number; | Added|
| abilityInfo | AbilityInfo | readonly supportWindowMode: Array\<bundle.SupportWindowMode>; | Added|
| bundleInstaller | InstallParam | crowdtestDeadline?: number; | Added|
| bundleInstaller | InstallParam | hashParams?: Array\<HashParam>; | Added|
| bundleInstaller | HashParam | hashValue: string; | Added|
| bundleInstaller | HashParam | moduleName: string; | Added|
| dispatchInfo | DispatchInfo | readonly dispatchAPI: string; | Added|
| dispatchInfo | DispatchInfo | readonly verison: string; | Added|
| hapModuleInfo | HapModuleInfo | readonly hashValue: string; | Added|
| ohos.bundle | bundle | getDisposedStatus(bundleName: string, callback: AsyncCallback\<number>): void;<br>getDisposedStatus(bundleName: string): Promise\<number>; | Added|
| ohos.bundle | bundle | setDisposedStatus(bundleName: string, status: number, callback: AsyncCallback\<void>): void;<br>setDisposedStatus(bundleName: string, status: number): Promise\<void>; | Added|
| ohos.bundle | bundle | getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string>>; | Added|
| ohos.bundle | bundle | getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string>>; | Added|
| ohos.bundle | bundle | getDispatcherVersion(callback: AsyncCallback\<DispatchInfo>): void;<br>getDispatcherVersion(): Promise\<DispatchInfo>; | Added|
| ohos.bundle | bundle | getBundlePackInfo(bundleName: string, bundlePackFlag: pack.BundlePackFlag, callback: AsyncCallback\<pack.BundlePackInfo>): void;<br>getBundlePackInfo(bundleName: string, bundlePackFlag: pack.BundlePackFlag): Promise\<pack.BundlePackInfo>; | Added|
| ohos.bundle | SupportWindowMode | FLOATING = 2 | Added|
| ohos.bundle | SupportWindowMode | SPLIT = 1 | Added|
| ohos.bundle | SupportWindowMode | FULL_SCREEN = 0 | Added|
| ohos.bundle | ExtensionAbilityType | ENTERPRISE_ADMIN = 11 | Added|
| ohos.bundle | DisplayOrientation | LOCKED | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_PORTRAIT_RESTRICTED | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_LANDSCAPE_RESTRICTED | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_RESTRICTED | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_PORTRAIT | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION_LANDSCAPE | Added|
| ohos.bundle | DisplayOrientation | AUTO_ROTATION | Added|
| ohos.bundle | DisplayOrientation | PORTRAIT_INVERTED | Added|
| ohos.bundle | DisplayOrientation | LANDSCAPE_INVERTED | Added|
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_CERTIFICATE_FINGERPRINT = 0x00000400 | Added|
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_HASH_VALUE = 0x00000030 | Added|
| ohos.bundle.defaultAppManager | defaultAppManager | resetDefaultApplication(type: string, userId?: number): Promise\<void>;<br>resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>): void;<br>resetDefaultApplication(type: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.bundle.defaultAppManager | defaultAppManager | setDefaultApplication(type: string, elementName: ElementName, userId?: number): Promise\<void>;<br>setDefaultApplication(type: string, elementName: ElementName, userId: number, callback: AsyncCallback\<void>): void;<br>setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>): void; | Added|
| ohos.bundle.defaultAppManager | defaultAppManager | getDefaultApplication(type: string, userId?: number): Promise\<BundleInfo>;<br>getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>): void;<br>getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>): void; | Added|
| ohos.bundle.defaultAppManager | defaultAppManager | isDefaultApplication(type: string): Promise\<boolean>;<br>isDefaultApplication(type: string, callback: AsyncCallback\<boolean>): void; | Added|
| ohos.bundle.defaultAppManager | ApplicationType | PPT = "PPT" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | EXCEL = "EXCEL" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | WORD = "WORD" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | PDF = "PDF" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | VIDEO = "VIDEO" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | AUDIO = "AUDIO" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | IMAGE = "IMAGE" | Added|
| ohos.bundle.defaultAppManager | ApplicationType | BROWSER = "BROWSER" | Added|
| packInfo | BundlePackFlag | GET_MODULE_SUMMARY = 0x00000004 | Added|
| packInfo | BundlePackFlag | GET_BUNDLE_SUMMARY = 0x00000002 | Added|
| packInfo | BundlePackFlag | GET_PACKAGES = 0x00000001 | Added|
| packInfo | BundlePackFlag | GET_PACK_INFO_ALL = 0x00000000 | Added|
| packInfo | ApiVersion | readonly target: number; | Added|
| packInfo | ApiVersion | readonly compatible: number; | Added|
| packInfo | ApiVersion | readonly releaseType: string; | Added|
| packInfo | Version | readonly code: number; | Added|
| packInfo | Version | readonly name: string; | Added|
| packInfo | Version | readonly minCompatibleVersionCode: number; | Added|
| packInfo | AbilityFormInfo | readonly defaultDimension: number; | Added|
| packInfo | AbilityFormInfo | readonly supportDimensions: Array\<number>; | Added|
| packInfo | AbilityFormInfo | readonly updateDuration: number; | Added|
| packInfo | AbilityFormInfo | readonly scheduledUpdateTime: string; | Added|
| packInfo | AbilityFormInfo | readonly updateEnabled: boolean; | Added|
| packInfo | AbilityFormInfo | readonly type: string; | Added|
| packInfo | AbilityFormInfo | readonly name: string; | Added|
| packInfo | ModuleAbilityInfo | readonly forms: Array\<AbilityFormInfo>; | Added|
| packInfo | ModuleAbilityInfo | readonly visible: boolean; | Added|
| packInfo | ModuleAbilityInfo | readonly label: string; | Added|
| packInfo | ModuleAbilityInfo | readonly name: string; | Added|
| packInfo | ModuleDistroInfo | readonly moduleType: string; | Added|
| packInfo | ModuleDistroInfo | readonly moduleName: string; | Added|
| packInfo | ModuleDistroInfo | readonly installationFree: boolean; | Added|
| packInfo | ModuleDistroInfo | readonly deliveryWithInstall: boolean; | Added|
| packInfo | ModuleDistroInfo | readonly mainAbility: string; | Added|
| packInfo | ModuleConfigInfo | readonly extensionAbilities: Array\<ExtensionAbilities>; | Added|
| packInfo | ModuleConfigInfo | readonly abilities: Array\<ModuleAbilityInfo>; | Added|
| packInfo | ModuleConfigInfo | readonly distro: ModuleDistroInfo; | Added|
| packInfo | ModuleConfigInfo | readonly deviceType: Array\<string>; | Added|
| packInfo | ModuleConfigInfo | readonly apiVersion: ApiVersion; | Added|
| packInfo | ExtensionAbilities | readonly forms: Array\<AbilityFormInfo>; | Added|
| packInfo | ExtensionAbilities | readonly name: string; | Added|
| packInfo | BundleConfigInfo | readonly version: Version; | Added|
| packInfo | BundleConfigInfo | readonly bundleName: string; | Added|
| packInfo | PackageSummary | readonly modules: Array\<ModuleConfigInfo>; | Added|
| packInfo | PackageSummary | readonly app: BundleConfigInfo; | Added|
| packInfo | PackageConfig | readonly deliveryWithInstall: boolean; | Added|
| packInfo | PackageConfig | readonly moduleType: string; | Added|
| packInfo | PackageConfig | readonly name: string; | Added|
| packInfo | PackageConfig | readonly deviceType: Array\<string>; | Added|
| packInfo | BundlePackInfo | readonly summary: PackageSummary; | Added|
| packInfo | BundlePackInfo | readonly packages: Array\<PackageConfig>; | Added|
| shortcutInfo | ShortcutInfo | readonly moduleName?: string; | Added|
| shortcutInfo | ShortcutWant | readonly targetModule: string; | Added|
