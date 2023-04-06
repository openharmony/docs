# JS API Changes of the Bundle Management Framework

The table below lists the APIs changes of the bundle management framework in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| shortcutInfo | ShortcutInfo | readonly labelId: number; | Added|
| shortcutInfo | ShortcutInfo | readonly iconId: number; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly installTime : number; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly userId: number; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly iconId: number; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly labelId: number; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly elementName : ElementName; | Added|
| launcherAbilityInfo | LauncherAbilityInfo | readonly applicationInfo: ApplicationInfo; | Added|
| bundleInfo | BundleInfo | readonly reqPermissionStates: Array\<number>; | Added|
| bundleInfo | BundleInfo | readonly hapModuleInfos: Array\<HapModuleInfo>; | Added|
| bundleInfo | BundleInfo | readonly abilityInfos: Array\<AbilityInfo>; | Added|
| abilityInfo | AbilityInfo | readonly enabled: boolean; | Added|
| abilityInfo | AbilityInfo | readonly metaData: Array\<CustomizeData>; | Added|
| ohos.zlib | zlib | unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>; | Added|
| ohos.zlib | zlib | zipFile(inFile:string, outFile:string, options: Options): Promise\<void>; | Added|
| ohos.zlib | Options | strategy?: CompressStrategy; | Added|
| ohos.zlib | Options | memLevel?: MemLevel; | Added|
| ohos.zlib | Options | level?: CompressLevel; | Added|
| ohos.zlib | MemLevel | MEM_LEVEL_DEFAULT = 8 | Added|
| ohos.zlib | MemLevel | MEM_LEVEL_MAX = 9 | Added|
| ohos.zlib | MemLevel | MEM_LEVEL_MIN = 1 | Added|
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_FIXED = 4 | Added|
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_RLE = 3 | Added|
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_HUFFMAN_ONLY = 2 | Added|
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_FILTERED = 1 | Added|
| ohos.zlib | CompressStrategy | COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0 | Added|
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1 | Added|
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_BEST_COMPRESSION = 9 | Added|
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_BEST_SPEED = 1 | Added|
| ohos.zlib | CompressLevel | COMPRESS_LEVEL_NO_COMPRESSION = 0 | Added|
| ohos.zlib | ErrorCode | ERROR_CODE_ERRNO = -1 | Added|
| ohos.zlib | ErrorCode | ERROR_CODE_OK = 0 | Added|
| ohos.bundle | bundle | isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>isApplicationEnabled(bundleName: string): Promise\<boolean>; | Added|
| ohos.bundle | bundle | isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void;<br>isAbilityEnabled(info: AbilityInfo): Promise\<boolean>; | Added|
| ohos.bundle | bundle | getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;<br>getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>; | Added|
| ohos.bundle | bundle | getAbilityLabel(bundleName: string, abilityName: string, callback: AsyncCallback\<string>): void;<br>getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>; | Added|
| ohos.bundle | bundle | getNameForUid(uid: number, callback: AsyncCallback\<string>) : void<br>getNameForUid(uid: number) : Promise\<string>; | Added|
| ohos.bundle | bundle | getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;<br>getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>; | Added|
| ohos.bundle | InstallErrorCode | STATUS_UNINSTALL_PERMISSION_DENIED = 0x45 | Added|
| ohos.bundle | InstallErrorCode | STATUS_INSTALL_PERMISSION_DENIED = 0x44 | Added|
| ohos.bundle | InstallErrorCode | STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43 | Added|
| ohos.bundle | InstallErrorCode | STATUS_FAILED_NO_SPACE_LEFT = 0x42 | Added|
| ohos.bundle | InstallErrorCode | STATUS_RECOVER_FAILURE_INVALID = 0x0D | Added|
| ohos.bundle | BundleOptions | userId?: number; | Added|
| ohos.bundle | ColorMode | LIGHT_MODE = 1 | Added|
| ohos.bundle | ColorMode | DARK_MODE = 0 | Added|
| ohos.bundle | ColorMode | AUTO_MODE = -1 | Added|
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_DISABLE = 0x00000200 | Added|
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_DISABLE = 0x00000100 | Added|
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_SYSTEMAPP_ONLY = 0x00000080 | Added|
| ohos.bundle | BundleFlag | GET_APPLICATION_INFO_WITH_METADATA = 0x00000040 | Added|
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_METADATA = 0x00000020 | Added|
| ohos.bundle | BundleFlag | GET_ALL_APPLICATION_INFO = 0xFFFF0000 | Added|
| ohos.bundle | BundleFlag | GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010 | Added|
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004 | Added|
| ohos.bundle | BundleFlag | GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002 | Added|
