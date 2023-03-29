| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|方法名 or 属性名：verifyAccessToken<br>函数：verifyAccessToken(tokenID: number, permissionName: Permissions): Promise<GrantStatus>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：verifyAccessTokenSync<br>函数：verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：grantUserGrantedPermission<br>函数：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：grantUserGrantedPermission<br>函数：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：revokeUserGrantedPermission<br>函数：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：revokeUserGrantedPermission<br>函数：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：getPermissionFlags<br>函数：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise<number>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeType|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeType<br>方法名 or 属性名：PERMISSION_REVOKED_OPER|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeType<br>方法名 or 属性名：PERMISSION_GRANTED_OPER|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeInfo|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeInfo<br>方法名 or 属性名：change|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeInfo<br>方法名 or 属性名：tokenID|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: PermissionStateChangeInfo<br>方法名 or 属性名：permissionName|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：addPermissionUsedRecord<br>函数：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise<void>;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：addPermissionUsedRecord<br>函数：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: PermissionActiveStatus|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: PermissionActiveStatus<br>方法名 or 属性名：PERM_INACTIVE|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: PermissionActiveStatus<br>方法名 or 属性名：PERM_ACTIVE_IN_FOREGROUND|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: PermissionActiveStatus<br>方法名 or 属性名：PERM_ACTIVE_IN_BACKGROUND|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: ActiveChangeResponse|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: ActiveChangeResponse<br>方法名 or 属性名：tokenId|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: ActiveChangeResponse<br>方法名 or 属性名：permissionName|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: ActiveChangeResponse<br>方法名 or 属性名：deviceId|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.privacyManager<br>类名: ActiveChangeResponse<br>方法名 or 属性名：activeStatus|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：permissionNames<br>函数：permissionNames: Array<Permissions>;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：permissionName<br>函数：permissionName: Permissions;|@ohos.privacyManager.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： INVALID_PARAMS|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： NOT_SUPPORT|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_OUT_OF_MEMORY|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_RUNTIME_ERROR|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_CRYPTO_OPERATION|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_CERT_SIGNATURE_FAILURE|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_CERT_NOT_YET_VALID|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_CERT_HAS_EXPIRED|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_KEYUSAGE_NO_CERTSIGN|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法名 or 属性名： ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: DataBlob|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: DataBlob<br>方法名 or 属性名： data|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: DataArray|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: DataArray<br>方法名 or 属性名： data|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat<br>方法名 or 属性名： FORMAT_DER|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat<br>方法名 or 属性名： FORMAT_PEM|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob<br>方法名 or 属性名： data|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob<br>方法名 or 属性名： encodingFormat|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainData|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法名 or 属性名： data|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法名 or 属性名： count|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法名 or 属性名： encodingFormat|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: ParamsSpec|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: ParamsSpec<br>方法名 or 属性名： algoName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: IvParamsSpec|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: IvParamsSpec<br>方法名 or 属性名： iv|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: GcmParamsSpec|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: GcmParamsSpec<br>方法名 or 属性名： iv|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: GcmParamsSpec<br>方法名 or 属性名： aad|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: GcmParamsSpec<br>方法名 or 属性名： authTag|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CcmParamsSpec|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CcmParamsSpec<br>方法名 or 属性名： iv|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CcmParamsSpec<br>方法名 or 属性名： aad|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CcmParamsSpec<br>方法名 or 属性名： authTag|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CryptoMode|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CryptoMode<br>方法名 or 属性名： ENCRYPT_MODE|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CryptoMode<br>方法名 or 属性名： DECRYPT_MODE|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Key|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Key<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Key<br>方法名 or 属性名： format|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Key<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKey<br>方法名 or 属性名： clearMem|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: PriKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: PriKey<br>方法名 or 属性名： clearMem|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: PubKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyPair|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyPair<br>方法名 or 属性名： priKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyPair<br>方法名 or 属性名： pubKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Random|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Random<br>方法名 or 属性名： generateRandom|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Random<br>方法名 or 属性名： generateRandom|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Random<br>方法名 or 属性名： setSeed|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Random<br>方法名 or 属性名： setSeed|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createRandom|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator<br>方法名 or 属性名： generateKeyPair|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator<br>方法名 or 属性名： generateKeyPair|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator<br>方法名 or 属性名： convertKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator<br>方法名 or 属性名： convertKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: AsyKeyGenerator<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator<br>方法名 or 属性名： generateSymKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator<br>方法名 or 属性名： generateSymKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator<br>方法名 or 属性名： convertKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator<br>方法名 or 属性名： convertKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: SymKeyGenerator<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createAsyKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createSymKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： doFinal|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： doFinal|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： getMacLength|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Mac<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createMac|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： digest|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： digest|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： getMdLength|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Md<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createMd|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： doFinal|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： doFinal|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Cipher<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createCipher|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： sign|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： sign|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Sign<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： init|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： update|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: Verify<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createSign|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createVerify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyAgreement|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyAgreement<br>方法名 or 属性名： generateSecret|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyAgreement<br>方法名 or 属性名： generateSecret|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: KeyAgreement<br>方法名 or 属性名： algName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createKeyAgreement|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getPublicKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getPublicKey|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： checkValidityWithDate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： checkValidityWithDate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getVersion|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSerialNumber|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getIssuerName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSubjectName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getNotBeforeTime|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getNotAfterTime|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSignature|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSignatureAlgName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSignatureAlgOid|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSignatureAlgParams|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getKeyUsage|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getExtKeyUsage|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getBasicConstraints|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getSubjectAltNames|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法名 or 属性名： getIssuerAltNames|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createX509Cert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createX509Cert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getSerialNumber|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getCertIssuer|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getCertIssuer|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getRevocationDate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法名 or 属性名： getRevocationDate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： isRevoked|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： isRevoked|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getType|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getEncoded|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： verify|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getVersion|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getIssuerName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getLastUpdate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getNextUpdate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCertWithCert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCertWithCert|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCerts|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getRevokedCerts|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getTbsInfo|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getTbsInfo|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getSignature|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getSignatureAlgName|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getSignatureAlgOid|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法名 or 属性名： getSignatureAlgParams|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createX509Crl|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createX509Crl|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法名 or 属性名： validate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法名 or 属性名： validate|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法名 or 属性名： algorithm|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.cryptoFramework<br>类名: cryptoFramework<br>方法名 or 属性名： createCertChainValidator|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksSessionHandle|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksSessionHandle<br>方法名 or 属性名：handle|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksSessionHandle<br>方法名 or 属性名：challenge|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksReturnResult|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：outData|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：properties|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：certChains|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_PERMISSION_FAIL|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_ILLEGAL_ARGUMENT|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_NOT_SUPPORTED_API|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_FILE_OPERATION_FAIL|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_COMMUNICATION_FAIL|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CRYPTO_FAIL|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_TIME_OUT|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_SESSION_LIMIT|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_ITEM_NOT_EXIST|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_EXTERNAL_ERROR|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_INSUFFICIENT_MEMORY|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CALL_SERVICE_FAILED|@ohos.security.huks.d.ts|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importWrappedKey|NA|@ohos.security.huks.d.ts|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importWrappedKey|NA|@ohos.security.huks.d.ts|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:attestKey|NA|@ohos.security.huks.d.ts|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:attestKey|NA|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：verifyAccessToken<br>废弃版本：N/A|方法名 or 属性名：verifyAccessToken<br>废弃版本：9<br>代替接口：ohos.abilityAccessCtrl.AtManager|@ohos.abilityAccessCtrl.d.ts|
|废弃版本有变化|方法名 or 属性名：generateKey<br>废弃版本：N/A|方法名 or 属性名：generateKey<br>废弃版本：9<br>代替接口：ohos.security.huks.generateKeyItem     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：generateKey<br>废弃版本：N/A|方法名 or 属性名：generateKey<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteKey<br>废弃版本：N/A|方法名 or 属性名：deleteKey<br>废弃版本：9<br>代替接口：ohos.security.huks.deleteKeyItem     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：deleteKey<br>废弃版本：N/A|方法名 or 属性名：deleteKey<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：importKey<br>废弃版本：N/A|方法名 or 属性名：importKey<br>废弃版本：9<br>代替接口：ohos.security.huks.importKeyItem     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：importKey<br>废弃版本：N/A|方法名 or 属性名：importKey<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：exportKey<br>废弃版本：N/A|方法名 or 属性名：exportKey<br>废弃版本：9<br>代替接口：ohos.security.huks.exportKeyItem     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：exportKey<br>废弃版本：N/A|方法名 or 属性名：exportKey<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：getKeyProperties<br>废弃版本：N/A|方法名 or 属性名：getKeyProperties<br>废弃版本：9<br>代替接口：ohos.security.huks.getKeyItemProperties     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：getKeyProperties<br>废弃版本：N/A|方法名 or 属性名：getKeyProperties<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：isKeyExist<br>废弃版本：N/A|方法名 or 属性名：isKeyExist<br>废弃版本：9<br>代替接口：ohos.security.huks.isKeyItemExist     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：isKeyExist<br>废弃版本：N/A|方法名 or 属性名：isKeyExist<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：init<br>废弃版本：N/A|方法名 or 属性名：init<br>废弃版本：9<br>代替接口：ohos.security.huks.initSession     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：init<br>废弃版本：N/A|方法名 or 属性名：init<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：update<br>废弃版本：N/A|方法名 or 属性名：update<br>废弃版本：9<br>代替接口：ohos.security.huks.updateSession     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：update<br>废弃版本：N/A|方法名 or 属性名：update<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：update<br>废弃版本：N/A|方法名 or 属性名：update<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：finish<br>废弃版本：N/A|方法名 or 属性名：finish<br>废弃版本：9<br>代替接口：ohos.security.huks.finishSession     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：finish<br>废弃版本：N/A|方法名 or 属性名：finish<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：abort<br>废弃版本：N/A|方法名 or 属性名：abort<br>废弃版本：9<br>代替接口：ohos.security.huks.abortSession     |@ohos.security.huks.d.ts|
|废弃版本有变化|方法名 or 属性名：abort<br>废弃版本：N/A|方法名 or 属性名：abort<br>废弃版本：9|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksHandle<br>废弃版本：N/A|类名：HuksHandle<br>废弃版本：9<br>代替接口：ohos.security.huks.HuksSessionHandle     |@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult<br>废弃版本：N/A|类名：HuksResult<br>废弃版本：9<br>代替接口：ohos.security.huks.HuksReturnResult     |@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode<br>废弃版本：N/A|类名：HuksErrorCode<br>废弃版本：9<br>代替接口：ohos.security.huks.HuksExceptionErrCode     |@ohos.security.huks.d.ts|
|废弃版本有变化|类名：Cipher<br>废弃版本：N/A|类名：Cipher<br>废弃版本：9<br>代替接口：ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|废弃版本有变化|方法名 or 属性名：rsa<br>废弃版本：N/A|方法名 or 属性名：rsa<br>废弃版本：9<br>代替接口：ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|废弃版本有变化|方法名 or 属性名：aes<br>废弃版本：N/A|方法名 or 属性名：aes<br>废弃版本：9<br>代替接口：ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|新增(错误码)|NA|方法名 or 属性名：getPermissionUsedRecords<br>错误码内容:401,201,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
