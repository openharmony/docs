| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Method or attribute name: verifyAccessToken<br>Function name: verifyAccessToken(tokenID: number, permissionName: Permissions): Promise<GrantStatus>;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: verifyAccessTokenSync<br>Function name: verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: grantUserGrantedPermission<br>Function name: grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: grantUserGrantedPermission<br>Function name: grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: revokeUserGrantedPermission<br>Function name: revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: revokeUserGrantedPermission<br>Function name: revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: getPermissionFlags<br>Function name: getPermissionFlags(tokenID: number, permissionName: Permissions): Promise<number>;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeType|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeType<br>Method or attribute name: PERMISSION_REVOKED_OPER|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeType<br>Method or attribute name: PERMISSION_GRANTED_OPER|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeInfo|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeInfo<br>Method or attribute name: change|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeInfo<br>Method or attribute name: tokenID|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Module name: ohos.abilityAccessCtrl<br>Class name: PermissionStateChangeInfo<br>Method or attribute name: permissionName|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Method or attribute name: addPermissionUsedRecord<br>Function name: function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise<void>;|@ohos.privacyManager.d.ts|
|Added|NA|Method or attribute name: addPermissionUsedRecord<br>Function name: function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: PermissionActiveStatus|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: PermissionActiveStatus<br>Method or attribute name: PERM_INACTIVE|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: PermissionActiveStatus<br>Method or attribute name: PERM_ACTIVE_IN_FOREGROUND|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: PermissionActiveStatus<br>Method or attribute name: PERM_ACTIVE_IN_BACKGROUND|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: ActiveChangeResponse|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: ActiveChangeResponse<br>Method or attribute name: tokenId|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: ActiveChangeResponse<br>Method or attribute name: permissionName|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: ActiveChangeResponse<br>Method or attribute name: deviceId|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.privacyManager<br>Class name: ActiveChangeResponse<br>Method or attribute name: activeStatus|@ohos.privacyManager.d.ts|
|Added|NA|Method or attribute name: permissionNames<br>Function name: permissionNames: Array<Permissions>;|@ohos.privacyManager.d.ts|
|Added|NA|Method or attribute name: permissionName<br>Function name: permissionName: Permissions;|@ohos.privacyManager.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: INVALID_PARAMS|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: NOT_SUPPORT|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_OUT_OF_MEMORY|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_RUNTIME_ERROR|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_CRYPTO_OPERATION|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_CERT_SIGNATURE_FAILURE|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_CERT_NOT_YET_VALID|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_CERT_HAS_EXPIRED|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_KEYUSAGE_NO_CERTSIGN|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Result<br>Method or attribute name: ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: DataBlob|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: DataBlob<br>Method or attribute name: data|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: DataArray|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: DataArray<br>Method or attribute name: data|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingFormat|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingFormat<br>Method or attribute name: FORMAT_DER|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingFormat<br>Method or attribute name: FORMAT_PEM|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingBlob|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingBlob<br>Method or attribute name: data|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: EncodingBlob<br>Method or attribute name: encodingFormat|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainData|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainData<br>Method or attribute name: data|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainData<br>Method or attribute name: count|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainData<br>Method or attribute name: encodingFormat|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: ParamsSpec|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: ParamsSpec<br>Method or attribute name: algoName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: IvParamsSpec|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: IvParamsSpec<br>Method or attribute name: iv|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: GcmParamsSpec|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: GcmParamsSpec<br>Method or attribute name: iv|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: GcmParamsSpec<br>Method or attribute name: aad|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: GcmParamsSpec<br>Method or attribute name: authTag|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CcmParamsSpec|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CcmParamsSpec<br>Method or attribute name: iv|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CcmParamsSpec<br>Method or attribute name: aad|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CcmParamsSpec<br>Method or attribute name: authTag|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CryptoMode|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CryptoMode<br>Method or attribute name: ENCRYPT_MODE|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CryptoMode<br>Method or attribute name: DECRYPT_MODE|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Key|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Key<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Key<br>Method or attribute name: format|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Key<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKey<br>Method or attribute name: clearMem|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: PriKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: PriKey<br>Method or attribute name: clearMem|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: PubKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyPair|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyPair<br>Method or attribute name: priKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyPair<br>Method or attribute name: pubKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Random|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Random<br>Method or attribute name: generateRandom|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Random<br>Method or attribute name: generateRandom|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Random<br>Method or attribute name: setSeed|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Random<br>Method or attribute name: setSeed|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createRandom|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator<br>Method or attribute name: generateKeyPair|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator<br>Method or attribute name: generateKeyPair|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator<br>Method or attribute name: convertKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator<br>Method or attribute name: convertKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: AsyKeyGenerator<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator<br>Method or attribute name: generateSymKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator<br>Method or attribute name: generateSymKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator<br>Method or attribute name: convertKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator<br>Method or attribute name: convertKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: SymKeyGenerator<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createAsyKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createSymKeyGenerator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: doFinal|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: doFinal|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: getMacLength|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Mac<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createMac|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: digest|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: digest|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: getMdLength|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Md<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createMd|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: doFinal|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: doFinal|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Cipher<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createCipher|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: sign|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: sign|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Sign<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: init|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: update|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: Verify<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createSign|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createVerify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyAgreement|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyAgreement<br>Method or attribute name: generateSecret|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyAgreement<br>Method or attribute name: generateSecret|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: KeyAgreement<br>Method or attribute name: algName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createKeyAgreement|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getPublicKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getPublicKey|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: checkValidityWithDate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: checkValidityWithDate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getVersion|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSerialNumber|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getIssuerName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSubjectName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getNotBeforeTime|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getNotAfterTime|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSignature|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSignatureAlgName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSignatureAlgOid|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSignatureAlgParams|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getKeyUsage|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getExtKeyUsage|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getBasicConstraints|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getSubjectAltNames|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Cert<br>Method or attribute name: getIssuerAltNames|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createX509Cert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createX509Cert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getSerialNumber|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getCertIssuer|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getCertIssuer|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getRevocationDate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509CrlEntry<br>Method or attribute name: getRevocationDate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: isRevoked|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: isRevoked|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getType|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getEncoded|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: verify|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getVersion|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getIssuerName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getLastUpdate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getNextUpdate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCertWithCert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCertWithCert|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCerts|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getRevokedCerts|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getTbsInfo|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getTbsInfo|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getSignature|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getSignatureAlgName|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getSignatureAlgOid|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: X509Crl<br>Method or attribute name: getSignatureAlgParams|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createX509Crl|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createX509Crl|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainValidator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainValidator<br>Method or attribute name: validate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainValidator<br>Method or attribute name: validate|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: CertChainValidator<br>Method or attribute name: algorithm|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.cryptoFramework<br>Class name: cryptoFramework<br>Method or attribute name: createCertChainValidator|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksSessionHandle|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksSessionHandle<br>Method or attribute name: handle|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksSessionHandle<br>Method or attribute name: challenge|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksReturnResult|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksReturnResult<br>Method or attribute name: outData|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksReturnResult<br>Method or attribute name: properties|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksReturnResult<br>Method or attribute name: certChains|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_PERMISSION_FAIL|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_ILLEGAL_ARGUMENT|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_NOT_SUPPORTED_API|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_FILE_OPERATION_FAIL|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_COMMUNICATION_FAIL|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_CRYPTO_FAIL|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_KEY_AUTH_TIME_OUT|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_SESSION_LIMIT|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_ITEM_NOT_EXIST|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_EXTERNAL_ERROR|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_INSUFFICIENT_MEMORY|@ohos.security.huks.d.ts|
|Added|NA|Module name: ohos.security.huks<br>Class name: HuksExceptionErrCode<br>Method or attribute name: HUKS_ERR_CODE_CALL_SERVICE_FAILED|@ohos.security.huks.d.ts|
|Deleted|Module name: ohos.security.huks<br>Class name: huks<br>Method or attribute name: importWrappedKey|NA|@ohos.security.huks.d.ts|
|Deleted|Module name: ohos.security.huks<br>Class name: huks<br>Method or attribute name: importWrappedKey|NA|@ohos.security.huks.d.ts|
|Deleted|Module name: ohos.security.huks<br>Class name: huks<br>Method or attribute name: attestKey|NA|@ohos.security.huks.d.ts|
|Deleted|Module name: ohos.security.huks<br>Class name: huks<br>Method or attribute name: attestKey|NA|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: verifyAccessToken<br>Deprecated version: N/A|Method or attribute name: verifyAccessToken<br>Deprecated version: 9<br>Substitute API: ohos.abilityAccessCtrl.AtManager|@ohos.abilityAccessCtrl.d.ts|
|Deprecated version changed|Method or attribute name: generateKey<br>Deprecated version: N/A|Method or attribute name: generateKey<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.generateKeyItem     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: generateKey<br>Deprecated version: N/A|Method or attribute name: generateKey<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: deleteKey<br>Deprecated version: N/A|Method or attribute name: deleteKey<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.deleteKeyItem     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: deleteKey<br>Deprecated version: N/A|Method or attribute name: deleteKey<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: importKey<br>Deprecated version: N/A|Method or attribute name: importKey<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.importKeyItem     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: importKey<br>Deprecated version: N/A|Method or attribute name: importKey<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: exportKey<br>Deprecated version: N/A|Method or attribute name: exportKey<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.exportKeyItem     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: exportKey<br>Deprecated version: N/A|Method or attribute name: exportKey<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: getKeyProperties<br>Deprecated version: N/A|Method or attribute name: getKeyProperties<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.getKeyItemProperties     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: getKeyProperties<br>Deprecated version: N/A|Method or attribute name: getKeyProperties<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: isKeyExist<br>Deprecated version: N/A|Method or attribute name: isKeyExist<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.isKeyItemExist     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: isKeyExist<br>Deprecated version: N/A|Method or attribute name: isKeyExist<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: init<br>Deprecated version: N/A|Method or attribute name: init<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.initSession     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: init<br>Deprecated version: N/A|Method or attribute name: init<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: update<br>Deprecated version: N/A|Method or attribute name: update<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.updateSession     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: update<br>Deprecated version: N/A|Method or attribute name: update<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: update<br>Deprecated version: N/A|Method or attribute name: update<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: finish<br>Deprecated version: N/A|Method or attribute name: finish<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.finishSession     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: finish<br>Deprecated version: N/A|Method or attribute name: finish<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: abort<br>Deprecated version: N/A|Method or attribute name: abort<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.abortSession     |@ohos.security.huks.d.ts|
|Deprecated version changed|Method or attribute name: abort<br>Deprecated version: N/A|Method or attribute name: abort<br>Deprecated version: 9|@ohos.security.huks.d.ts|
|Deprecated version changed|Class name: HuksHandle<br>Deprecated version: N/A|Class name: HuksHandle<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.HuksSessionHandle     |@ohos.security.huks.d.ts|
|Deprecated version changed|Class name: HuksResult<br>Deprecated version: N/A|Class name: HuksResult<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.HuksReturnResult     |@ohos.security.huks.d.ts|
|Deprecated version changed|Class name: HuksErrorCode<br>Deprecated version: N/A|Class name: HuksErrorCode<br>Deprecated version: 9<br>Substitute API: ohos.security.huks.HuksExceptionErrCode     |@ohos.security.huks.d.ts|
|Deprecated version changed|Class name: Cipher<br>Deprecated version: N/A|Class name: Cipher<br>Deprecated version: 9<br>Substitute API: ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|Deprecated version changed|Method or attribute name: rsa<br>Deprecated version: N/A|Method or attribute name: rsa<br>Deprecated version: 9<br>Substitute API: ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|Deprecated version changed|Method or attribute name: aes<br>Deprecated version: N/A|Method or attribute name: aes<br>Deprecated version: 9<br>Substitute API: ohos.security.cryptoFramework.Cipher |@system.cipher.d.ts|
|Initial version changed|Method or attribute name: update<br>Initial version: 9|Method or attribute name: update<br>Initial version: 8|@ohos.security.huks.d.ts|
|Initial version changed|Method or attribute name: update<br>Initial version: 9|Method or attribute name: update<br>Initial version: 8|@ohos.security.huks.d.ts|
|Initial version changed|Method or attribute name: update<br>Initial version: 9|Method or attribute name: update<br>Initial version: 8|@ohos.security.huks.d.ts|
|Error code added|NA|Method or attribute name: getPermissionUsedRecords<br>Error code: 401, 201, 12100001, 12100002, 12100003, 12100007, 12100008|@ohos.privacyManager.d.ts|
