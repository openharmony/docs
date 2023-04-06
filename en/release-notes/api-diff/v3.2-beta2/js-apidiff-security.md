# JS API Changes of the Security Subsystem

The table below lists the APIs changes of the security subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.privacyManager | UsedRecordDetail | accessDuration: number; | Added|
| ohos.privacyManager | UsedRecordDetail | timestamp: number; | Added|
| ohos.privacyManager | UsedRecordDetail | status: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | rejectRecords: Array\<UsedRecordDetail>; | Added|
| ohos.privacyManager | PermissionUsedRecord | accessRecords: Array\<UsedRecordDetail>; | Added|
| ohos.privacyManager | PermissionUsedRecord | lastAccessDuration: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | lastRejectTime: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | lastAccessTime: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | rejectCount: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | accessCount: number; | Added|
| ohos.privacyManager | PermissionUsedRecord | permissionName: string; | Added|
| ohos.privacyManager | BundleUsedRecord | permissionRecords: Array\<PermissionUsedRecord>; | Added|
| ohos.privacyManager | BundleUsedRecord | bundleName: string; | Added|
| ohos.privacyManager | BundleUsedRecord | deviceId: string; | Added|
| ohos.privacyManager | BundleUsedRecord | isRemote: boolean; | Added|
| ohos.privacyManager | BundleUsedRecord | tokenId: number; | Added|
| ohos.privacyManager | PermissionUsedResponse | bundleRecords: Array\<BundleUsedRecord>; | Added|
| ohos.privacyManager | PermissionUsedResponse | endTime: number; | Added|
| ohos.privacyManager | PermissionUsedResponse | beginTime: number; | Added|
| ohos.privacyManager | PermissionUsedRequest | flag: PermissionUsageFlag; | Added|
| ohos.privacyManager | PermissionUsedRequest | endTime: number; | Added|
| ohos.privacyManager | PermissionUsedRequest | beginTime: number; | Added|
| ohos.privacyManager | PermissionUsedRequest | permissionNames: Array\<string>; | Added|
| ohos.privacyManager | PermissionUsedRequest | bundleName: string; | Added|
| ohos.privacyManager | PermissionUsedRequest | deviceId: string; | Added|
| ohos.privacyManager | PermissionUsedRequest | isRemote: boolean; | Added|
| ohos.privacyManager | PermissionUsedRequest | tokenId: number; | Added|
| ohos.privacyManager | PermissionUsageFlag | FLAG_PERMISSION_USAGE_DETAIL = 1 | Added|
| ohos.privacyManager | PermissionUsageFlag | FLAG_PERMISSION_USAGE_SUMMARY = 0 | Added|
| ohos.privacyManager | privacyManager | getPermissionUsedRecords(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>;<br>getPermissionUsedRecords(request: PermissionUsedRequest, callback: AsyncCallback\<PermissionUsedResponse>): void; | Added|
| ohos.privacyManager | privacyManager | addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise\<number>;<br>addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback\<number>): void; | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_UNWRAP_ALGORITHM_SUITE = HuksTagType.HUKS_TAG_TYPE_UINT \| 26 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IMPORT_KEY_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 25 | Added|
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_KEY_PAIR = 2 | Added|
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_PRIVATE_KEY = 1 | Added|
| ohos.security.huks | HuksImportKeyType | HUKS_KEY_TYPE_PUBLIC_KEY = 0 | Added|
| ohos.security.huks | HuksUnwrapSuite | HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING = 2 | Added|
| ohos.security.huks | HuksUnwrapSuite | HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING = 1 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM4 = 152 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM3 = 151 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_SM2 = 150 | Added|
| ohos.security.huks | HuksKeySize | HUKS_SM4_KEY_SIZE_128 = 128 | Added|
| ohos.security.huks | HuksKeySize | HUKS_SM2_KEY_SIZE_256 = 256 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SM3 = 2 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_USAGE_OF_KEY = -127 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_WRAPPED_FORMAT = -126 | Added|
| ohos.security.huks | huks | importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
