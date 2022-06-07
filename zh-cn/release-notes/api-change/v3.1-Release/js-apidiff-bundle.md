# 包管理子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，包管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| shortcutInfo | ShortcutInfo | readonly labelId: number; | 新增 |
| shortcutInfo | ShortcutInfo | readonly iconId: number; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly installTime : number; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly userId: number; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly iconId: number; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly labelId: number; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly elementName : ElementName; | 新增 |
| launcherAbilityInfo | LauncherAbilityInfo | readonly applicationInfo: ApplicationInfo; | 新增 |
| bundleInfo | BundleInfo | readonly reqPermissionStates: Array\<number>; | 新增 |
| bundleInfo | BundleInfo | readonly hapModuleInfos: Array\<HapModuleInfo>; | 新增 |
| bundleInfo | BundleInfo | readonly abilityInfos: Array\<AbilityInfo>; | 新增 |
| abilityInfo | AbilityInfo | readonly enabled: boolean; | 新增 |
| abilityInfo | AbilityInfo | readonly metaData: Array\<CustomizeData>; | 新增 |
| ohos.zlib | zlib | unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>; | 新增 |
| ohos.zlib | zlib | zipFile(inFile:string, outFile:string, options: Options): Promise\<void>; | 新增 |
| ohos.zlib | Options | strategy?: CompressStrategy; | 新增 |
| ohos.zlib | Options | memLevel?: MemLevel; | 新增 |
| ohos.zlib | Options | level?: CompressLevel; | 新增 |
| ohos.zlib | MemLevel | MEM_LEVEL_DEFAULT = 8 | 新增 |
| ohos.zlib | MemLevel | MEM_LEVEL_MAX = 9 | 新增 |
| ohos.zlib | MemLevel | MEM_LEVEL_MIN = 1 | 新增 |
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_FIXED = 4 | 新增 |
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_RLE = 3 | 新增 |
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_HUFFMAN_ONLY = 2 | 新增 |
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_FILTERED = 1 | 新增 |
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0 | 新增 |
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1 | 新增 |
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_BEST_COMPRESSION = 9 | 新增 |
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_BEST_SPEED = 1 | 新增 |
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_NO_COMPRESSION = 0 | 新增 |
| ohos.zlib | ErrorCode | ERROR_CODE_ERRNO = -1 | 新增 |
| ohos.zlib | ErrorCode | ERROR_CODE_OK = 0 | 新增 |
| ohos.bundle | bundle | isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>isApplicationEnabled(bundleName: string): Promise\<boolean>; | 新增 |
| ohos.bundle | bundle | isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void;<br>isAbilityEnabled(info: AbilityInfo): Promise\<boolean>; | 新增 |
| ohos.bundle | bundle | getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;<br>getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>; | 新增 |
| ohos.bundle | bundle | getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback\<string>): void;<br>getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>; | 新增 |
| ohos.bundle | bundle | getNameForUid(uid: number, callback: AsyncCallback\<string>) : void<br>getNameForUid(uid: number) : Promise\<string>; | 新增 |
| ohos.bundle | bundle | getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;<br>getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>; | 新增 |
| ohos.bundle | InstallErrorCode | STATUS_UNINSTALL_PERMISSION_DENIED = 0x45 | 新增 |
| ohos.bundle | InstallErrorCode | STATUS_INSTALL_PERMISSION_DENIED = 0x44 | 新增 |
| ohos.bundle | InstallErrorCode | STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43 | 新增 |
| ohos.bundle | InstallErrorCode | STATUS_FAILED_NO_SPACE_LEFT = 0x42 | 新增 |
| ohos.bundle | InstallErrorCode | STATUS_RECOVER_FAILURE_INVALID = 0x0D | 新增 |
| ohos.bundle | BundleOptions | userId?: number; | 新增 |
| ohos.bundle | ColorMode | LIGHT_MODE = 1 | 新增 |
| ohos.bundle | ColorMode | DARK_MODE = 0 | 新增 |
| ohos.bundle | ColorMode | AUTO_MODE = -1 | 新增 |
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_DISABLE = 0x00000200 | 新增 |
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_DISABLE = 0x00000100 | 新增 |
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_SYSTEMAPP_ONLY = 0x00000080 | 新增 |
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_METADATA = 0x00000040 | 新增 |
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_METADATA = 0x00000020 | 新增 |
| ohos.bundle | BundleFlag | GET_ALL_APPLICATION_INFO = 0xFFFF0000 | 新增 |
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010 | 新增 |
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004 | 新增 |
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002 | 新增 |
