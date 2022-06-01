# 包管理子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，包管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| bundleInfo | BundleInfo | readonly extensionAbilityInfo: Array\<ExtensionAbilityInfo>; | 新增 |
| bundleInfo | ReqPermissionDetail | reasonId: number; | 新增 |
| hapModuleInfo | HapModuleInfo | readonly metadata: Array\<Metadata>; | 新增 |
| hapModuleInfo | HapModuleInfo | readonly extensionAbilityInfo: Array\<ExtensionAbilityInfo>; | 新增 |
| hapModuleInfo | HapModuleInfo | readonly mainElementName: string; | 新增 |
| metadata | Metadata | resource: string; | 新增 |
| metadata | Metadata | value: string; | 新增 |
| metadata | Metadata | name: string; | 新增 |
| ohos.bundle | bundle | isModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void;<br>isModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>; | 新增 |
| ohos.bundle | bundle | setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>):void;<br>setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>; | 新增 |
| ohos.bundle | bundle | queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;<br>queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, callback: AsyncCallback\<Array\<ExtensionAbilityInfo>>): void;<br>queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId?: number): Promise\<Array\<ExtensionAbilityInfo>>; | 新增 |
| ohos.bundle | UpgradeFlag | RELATION_UPGRADE = 2 | 新增 |
| ohos.bundle | UpgradeFlag | SINGLE_UPGRADE = 1 | 新增 |
| ohos.bundle | UpgradeFlag | NOT_UPGRADE = 0 | 新增 |
| ohos.bundle | ExtensionAbilityType | UNSPECIFIED = 20 | 新增 |
| ohos.bundle | ExtensionAbilityType | WINDOW = 10 | 新增 |
| ohos.bundle | ExtensionAbilityType | BACKUP = 9 | 新增 |
| ohos.bundle | ExtensionAbilityType | WALLPAPER = 8 | 新增 |
| ohos.bundle | ExtensionAbilityType | STATIC_SUBSCRIBER = 7 | 新增 |
| ohos.bundle | ExtensionAbilityType | FILE_SHARE = 6 | 新增 |
| ohos.bundle | ExtensionAbilityType | DATA_SHARE = 5 | 新增 |
| ohos.bundle | ExtensionAbilityType | ACCESSIBILITY = 4 | 新增 |
| ohos.bundle | ExtensionAbilityType | SERVICE = 3 | 新增 |
| ohos.bundle | ExtensionAbilityType | INPUT_METHOD = 2 | 新增 |
| ohos.bundle | ExtensionAbilityType | WORK_SCHEDULER = 1 | 新增 |
| ohos.bundle | ExtensionAbilityType | FORM = 0 | 新增 |
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_METADATA = 0x00000020 | 新增 |
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_APPLICATION = 0x00000004 | 新增 |
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_WITH_PERMISSION = 0x00000002 | 新增 |
| ohos.bundle | ExtensionFlag | GET_EXTENSION_INFO_DEFAULT = 0x00000000 | 新增 |
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_EXTENSION_ABILITY = 0x00000020 | 新增 |

