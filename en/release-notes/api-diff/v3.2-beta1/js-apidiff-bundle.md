# JS API Changes of the Bundle Management Framework

The table below lists the APIs changes of the bundle management framework in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| bundleInfo | BundleInfo | readonly extensionAbilityInfo: Array\<ExtensionAbilityInfo>; | Added|
| bundleInfo | ReqPermissionDetail | reasonId: number; | Added|
| hapModuleInfo | HapModuleInfo | readonly metadata: Array\<Metadata>; | Added|
| hapModuleInfo | HapModuleInfo | readonly extensionAbilityInfo: Array\<ExtensionAbilityInfo>; | Added|
| hapModuleInfo | HapModuleInfo | readonly mainElementName: string; | Added|
| metadata | Metadata | resource: string; | Added|
| metadata | Metadata | value: string; | Added|
| metadata | Metadata | name: string; | Added|
| ohos.bundle | bundle | isModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void;<br>isModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>; | Added|
| ohos.bundle | bundle | setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>):void;<br>setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>; | Added|
| ohos.bundle | bundle | queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;<br>queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;<br>queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId?: number): Promise\<Array\<ExtensionAbilityInfo>>; | Added|
| ohos.bundle | UpgradeFlag | RELATION_UPGRADE = 2 | Added|
| ohos.bundle | UpgradeFlag | SINGLE_UPGRADE = 1 | Added|
| ohos.bundle | UpgradeFlag | NOT_UPGRADE = 0 | Added|
| ohos.bundle | ExtensionAbilityType | UNSPECIFIED = 20 | Added|
| ohos.bundle | ExtensionAbilityType | WINDOW = 10 | Added|
| ohos.bundle | ExtensionAbilityType | BACKUP = 9 | Added|
| ohos.bundle | ExtensionAbilityType | WALLPAPER = 8 | Added|
| ohos.bundle | ExtensionAbilityType | STATIC_SUBSCRIBER = 7 | Added|
| ohos.bundle | ExtensionAbilityType | FILE_SHARE = 6 | Added|
| ohos.bundle | ExtensionAbilityType | DATA_SHARE = 5 | Added|
| ohos.bundle | ExtensionAbilityType | ACCESSIBILITY = 4 | Added|
| ohos.bundle | ExtensionAbilityType | SERVICE = 3 | Added|
| ohos.bundle | ExtensionAbilityType | INPUT_METHOD = 2 | Added|
| ohos.bundle | ExtensionAbilityType | WORK_SCHEDULER = 1 | Added|
| ohos.bundle | ExtensionAbilityType | FORM = 0 | Added|
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_METADATA = 0x00000020 | Added|
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_APPLICATION = 0x00000004 | Added|
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_PERMISSION = 0x00000002 | Added|
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_DEFAULT = 0x00000000 | Added|
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_EXTENSION_ABILITY = 0x00000020 | Added|
