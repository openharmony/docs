# 安全子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，安全子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.privacyManager | UsedRecordDetail | accessDuration: number; | 新增 |
| ohos.privacyManager | UsedRecordDetail | timestamp: number; | 新增 |
| ohos.privacyManager | UsedRecordDetail | status: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | rejectRecords: Array\<UsedRecordDetail>; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | accessRecords: Array\<UsedRecordDetail>; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | lastAccessDuration: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | lastRejectTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | lastAccessTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | rejectCount: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | accessCount: number; | 新增 |
| ohos.privacyManager | PermissionUsedRecord | permissionName: string; | 新增 |
| ohos.privacyManager | BundleUsedRecord | permissionRecords: Array\<PermissionUsedRecord>; | 新增 |
| ohos.privacyManager | BundleUsedRecord | bundleName: string; | 新增 |
| ohos.privacyManager | BundleUsedRecord | deviceId: string; | 新增 |
| ohos.privacyManager | BundleUsedRecord | isRemote: boolean; | 新增 |
| ohos.privacyManager | BundleUsedRecord | tokenId: number; | 新增 |
| ohos.privacyManager | PermissionUsedResponse | bundleRecords: Array\<BundleUsedRecord>; | 新增 |
| ohos.privacyManager | PermissionUsedResponse | endTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedResponse | beginTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | flag: PermissionUsageFlag; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | endTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | beginTime: number; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | permissionNames: Array\<string>; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | bundleName: string; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | deviceId: string; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | isRemote: boolean; | 新增 |
| ohos.privacyManager | PermissionUsedRequest | tokenId: number; | 新增 |
| ohos.privacyManager | PermissionUsageFlag | FLAG_PERMISSION_USAGE_DETAIL = 1 | 新增 |
| ohos.privacyManager | PermissionUsageFlag | FLAG_PERMISSION_USAGE_SUMMARY = 0 | 新增 |
| ohos.privacyManager | privacyManager | getPermissionUsedRecords(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>;<br>getPermissionUsedRecords(request: PermissionUsedRequest, callback: AsyncCallback\<PermissionUsedResponse>): void; | 新增 |
| ohos.privacyManager | privacyManager | addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise\<number>;<br>addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback\<number>): void; | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_UNWRAP_ALGORITHM_SUITE = HuksTagType.HUKS_TAG_TYPE_UINT \| 26 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IMPORT_KEY_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 25 | 新增 |
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_KEY_PAIR = 2 | 新增 |
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_PRIVATE_KEY = 1 | 新增 |
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_PUBLIC_KEY = 0 | 新增 |
| ohos.security.huks | HuksUnwrapSuite | HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING = 2 | 新增 |
| ohos.security.huks | HuksUnwrapSuite | HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING = 1 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM4 = 152 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM3 = 151 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM2 = 150 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_SM4_KEY_SIZE_128 = 128 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_SM2_KEY_SIZE_256 = 256 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SM3 = 2 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_USAGE_OF_KEY = -127 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_WRAPPED_FORMAT = -126 | 新增 |
| ohos.security.huks | huks | importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |