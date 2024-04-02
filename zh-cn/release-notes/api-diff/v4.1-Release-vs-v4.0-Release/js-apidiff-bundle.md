| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API跨平台权限变更|类名：zlib；<br>API声明： export enum CompressLevel<br>差异内容：NA|类名：zlib；<br>API声明： export enum CompressLevel<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明： export enum CompressStrategy<br>差异内容：NA|类名：zlib；<br>API声明： export enum CompressStrategy<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明： export enum MemLevel<br>差异内容：NA|类名：zlib；<br>API声明： export enum MemLevel<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明： interface Options<br>差异内容：NA|类名：zlib；<br>API声明： interface Options<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：NA|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：NA|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：NA|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明：function compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：zlib；<br>API声明：function compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明：function compressFile(inFile: string, outFile: string, options: Options): Promise\<void>;<br>差异内容：NA|类名：zlib；<br>API声明：function compressFile(inFile: string, outFile: string, options: Options): Promise\<void>;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, callback: AsyncCallback\<void>): void;<br>差异内容：NA|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, callback: AsyncCallback\<void>): void;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|API跨平台权限变更|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>;<br>差异内容：NA|类名：zlib；<br>API声明：function decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>;<br>差异内容：crossplatform|api/@ohos.zlib.d.ts|
|syscap变更|类名：BundleType；<br>API声明：ATOMIC_SERVICE = 1<br>差异内容：NA|类名：BundleType；<br>API声明：ATOMIC_SERVICE = 1<br>差异内容：SystemCapability.BundleManager.BundleFramework.Core|api/@ohos.bundle.bundleManager.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：NA|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：NA|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：NA|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：NA|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：NA|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：SystemCapability.BundleManager.BundleFramework|api/@ohos.bundle.d.ts|
|syscap变更|类名：global；<br>API声明： declare namespace zlib<br>差异内容：NA|类名：global；<br>API声明： declare namespace zlib<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：NA|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：NA|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|syscap变更|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：NA|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：SystemCapability.BundleManager.Zlib|api/@ohos.zlib.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：NA|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：NA|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：NA|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：NA|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：NA|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：9|api/@ohos.bundle.d.ts|
|API废弃版本变更|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：9|api/@ohos.zlib.d.ts|
|API废弃版本变更|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：9|api/@ohos.zlib.d.ts|
|新增API|NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_INFO_WITH_MENU = 0x00000100<br>差异内容：GET_BUNDLE_INFO_WITH_MENU = 0x00000100|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：ExtensionAbilityType；<br>API声明：ADS_SERVICE = 20<br>差异内容：ADS_SERVICE = 20|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：bundleManager；<br>API声明：function verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void>): void;<br>差异内容：function verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void>): void;|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：bundleManager；<br>API声明：function verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean): Promise\<void>;<br>差异内容：function verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean): Promise\<void>;|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：bundleManager；<br>API声明：function deleteAbc(abcPath: string): Promise\<void>;<br>差异内容：function deleteAbc(abcPath: string): Promise\<void>;|api/@ohos.bundle.bundleManager.d.ts|
|新增API|NA|类名：ApplicationInfo；<br>API声明：readonly dataUnclearable: boolean;<br>差异内容：readonly dataUnclearable: boolean;|api/bundleManager/ApplicationInfo.d.ts|
|新增API|NA|类名：SignatureInfo；<br>API声明：readonly appIdentifier: string;<br>差异内容：readonly appIdentifier: string;|api/bundleManager/BundleInfo.d.ts|
|新增API|NA|类名：ExtensionAbilityInfo；<br>API声明：readonly extensionAbilityTypeName: string;<br>差异内容：readonly extensionAbilityTypeName: string;|api/bundleManager/ExtensionAbilityInfo.d.ts|
|新增API|NA|类名：HapModuleInfo；<br>API声明：readonly fileContextMenuConfig: string;<br>差异内容：readonly fileContextMenuConfig: string;|api/bundleManager/HapModuleInfo.d.ts|
|起始版本有变化|类名：BundleType；<br>API声明：ATOMIC_SERVICE = 1<br>差异内容：NA|类名：BundleType；<br>API声明：ATOMIC_SERVICE = 1<br>差异内容：9|api/@ohos.bundle.bundleManager.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_DEFAULT = 0x00000000<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_ABILITIES = 0x00000001<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_PERMISSION = 0x00000002<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ABILITY_INFO_WITH_APPLICATION = 0x00000004<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_APPLICATION_INFO_WITH_PERMISSION = 0x00000008<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_BUNDLE_WITH_REQUESTED_PERMISSION = 0x00000010<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：NA|类名：BundleFlag；<br>API声明：GET_ALL_APPLICATION_INFO = 0xFFFF0000<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：NA|类名：ColorMode；<br>API声明：AUTO_MODE = -1<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：NA|类名：ColorMode；<br>API声明：DARK_MODE = 0<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：NA|类名：ColorMode；<br>API声明：LIGHT_MODE = 1<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_DENIED = -1<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：NA|类名：GrantStatus；<br>API声明：PERMISSION_GRANTED = 0<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：NA|类名：AbilitySubType；<br>API声明：UNSPECIFIED = 0<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：NA|类名：AbilitySubType；<br>API声明：CA = 1<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：SUCCESS = 0<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE = 1<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_ABORTED = 2<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INVALID = 3<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_CONFLICT = 4<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_STORAGE = 5<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE = 7<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：NA|类名：InstallErrorCode；<br>API声明：STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>差异内容：7|api/@ohos.bundle.d.ts|
|起始版本有变化|类名：global；<br>API声明： declare namespace zlib<br>差异内容：NA|类名：global；<br>API声明： declare namespace zlib<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_OK = 0<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：NA|类名：ErrorCode；<br>API声明：ERROR_CODE_ERRNO = -1<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_NO_COMPRESSION = 0<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_SPEED = 1<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_BEST_COMPRESSION = 9<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：NA|类名：CompressLevel；<br>API声明：COMPRESS_LEVEL_DEFAULT_COMPRESSION = -1<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_DEFAULT_STRATEGY = 0<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FILTERED = 1<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_HUFFMAN_ONLY = 2<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_RLE = 3<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：NA|类名：CompressStrategy；<br>API声明：COMPRESS_STRATEGY_FIXED = 4<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MIN = 1<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_MAX = 9<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：NA|类名：MemLevel；<br>API声明：MEM_LEVEL_DEFAULT = 8<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：NA|类名：Options；<br>API声明：level?: CompressLevel;<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：NA|类名：Options；<br>API声明：memLevel?: MemLevel;<br>差异内容：7|api/@ohos.zlib.d.ts|
|起始版本有变化|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：NA|类名：Options；<br>API声明：strategy?: CompressStrategy;<br>差异内容：7|api/@ohos.zlib.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.bundle.bundleManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.bundle.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.bundle.defaultAppManager.d.ts|
|kit变更|NA|AbilityKit|api/@ohos.bundle.overlay.d.ts|
|kit变更|NA|BasicServicesKit|api/@ohos.zlib.d.ts|
|kit变更|NA|AbilityKit|api/@system.package.d.ts|
