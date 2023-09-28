| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：HuksSessionHandle;<br>方法or属性：handle: number;|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksReturnResult;<br>方法or属性：outData?: Uint8Array;|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksReturnResult;<br>方法or属性：properties?: Array\<HuksParam>;|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksReturnResult;<br>方法or属性：certChains?: Array\<string>;|@ohos.security.huks.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：verifyAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：checkAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>, requestCallback: AsyncCallback\<PermissionRequestResult>) : void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>) : Promise\<PermissionRequestResult>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：getVersion(): Promise\<number>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：on(type: 'permissionStateChange', tokenIDList: Array\<number>, permissionList: Array\<Permissions>, callback: Callback\<PermissionStateChangeInfo>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：off(type: 'permissionStateChange', tokenIDList: Array\<number>, permissionList: Array\<Permissions>, callback?: Callback\<PermissionStateChangeInfo>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_REVOKED_OPER = 0|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_GRANTED_OPER = 1|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：PermissionStateChangeInfo;<br>方法or属性：change: PermissionStateChangeType;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：PermissionStateChangeInfo;<br>方法or属性：tokenID: number;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：PermissionStateChangeInfo;<br>方法or属性：permissionName: Permissions;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise\<void>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback\<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(request: PermissionUsedRequest, callback: AsyncCallback\<PermissionUsedResponse>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function on(type: 'activeStateChange', permissionList: Array\<Permissions>, callback: Callback\<ActiveChangeResponse>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：privacyManager;<br>方法or属性：function off(type: 'activeStateChange', permissionList: Array\<Permissions>, callback?: Callback\<ActiveChangeResponse>): void;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionActiveStatus;<br>方法or属性：PERM_INACTIVE = 0|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_FOREGROUND = 1|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_BACKGROUND = 2|@ohos.privacyManager.d.ts|
|新增|NA|类名：ActiveChangeResponse;<br>方法or属性：tokenId: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：tokenId: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：BundleUsedRecord;<br>方法or属性：tokenId: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：ActiveChangeResponse;<br>方法or属性：permissionName: Permissions;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：permissionName: Permissions;|@ohos.privacyManager.d.ts|
|新增|NA|类名：ActiveChangeResponse;<br>方法or属性：deviceId: string;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：deviceId: string;|@ohos.privacyManager.d.ts|
|新增|NA|类名：BundleUsedRecord;<br>方法or属性：deviceId: string;|@ohos.privacyManager.d.ts|
|新增|NA|类名：ActiveChangeResponse;<br>方法or属性：activeStatus: PermissionActiveStatus;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_SUMMARY = 0|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_DETAIL = 1|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：isRemote: boolean;|@ohos.privacyManager.d.ts|
|新增|NA|类名：BundleUsedRecord;<br>方法or属性：isRemote: boolean;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：bundleName: string;|@ohos.privacyManager.d.ts|
|新增|NA|类名：BundleUsedRecord;<br>方法or属性：bundleName: string;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：permissionNames: Array\<Permissions>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：beginTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedResponse;<br>方法or属性：beginTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：endTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedResponse;<br>方法or属性：endTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRequest;<br>方法or属性：flag: PermissionUsageFlag;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedResponse;<br>方法or属性：bundleRecords: Array\<BundleUsedRecord>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：BundleUsedRecord;<br>方法or属性：permissionRecords: Array\<PermissionUsedRecord>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：accessCount: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：rejectCount: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：lastAccessTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：lastRejectTime: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：lastAccessDuration: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：accessRecords: Array\<UsedRecordDetail>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：PermissionUsedRecord;<br>方法or属性：rejectRecords: Array\<UsedRecordDetail>;|@ohos.privacyManager.d.ts|
|新增|NA|类名：UsedRecordDetail;<br>方法or属性：status: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：UsedRecordDetail;<br>方法or属性：timestamp: number;|@ohos.privacyManager.d.ts|
|新增|NA|类名：UsedRecordDetail;<br>方法or属性：accessDuration: number;|@ohos.privacyManager.d.ts|
| 新增 | NA   | 类名：CertResult; <br>方法or属性：ERR_CERT_SIGNATURE_FAILURE = 19030002 | @ohos.security.cert.d.ts |
| 新增 | NA   | 类名：CertResult; <br/>方法or属性：ERR_CERT_NOT_YET_VALID = 19030003 | @ohos.security.cert.d.ts |
| 新增 | NA   | 类名：CertResult; <br/>方法or属性：ERR_CERT_HAS_EXPIRED = 19030004 | @ohos.security.cert.d.ts |
| 新增 | NA   | 类名：CertResult; <br/>方法or属性：ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY = 19030005 | @ohos.security.cert.d.ts |
| 新增 | NA   | 类名：CertResult; <br/>方法or属性：ERR_KEYUSAGE_NO_CERTSIGN = 19030006 | @ohos.security.cert.d.ts |
| 新增 | NA   | 类名：CertResult; <br/>方法or属性：ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE = 19030007 | @ohos.security.cert.d.ts |
|新增|NA|类名：cert;<br>方法or属性：function createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>;|@ohos.security.cert.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>;|@ohos.security.cert.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createCertChainValidator(algorithm :string) : CertChainValidator;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertResult;<br>方法or属性：INVALID_PARAMS = 401|@ohos.security.cert.d.ts|
|新增|NA|类名：CertResult;<br>方法or属性：NOT_SUPPORT = 801|@ohos.security.cert.d.ts|
|新增|NA|类名：CertResult;<br>方法or属性：ERR_OUT_OF_MEMORY = 19020001|@ohos.security.cert.d.ts|
|新增|NA|类名：CertResult;<br>方法or属性：ERR_RUNTIME_ERROR = 19020002|@ohos.security.cert.d.ts|
|新增|NA|类名：CertResult;<br>方法or属性：ERR_CRYPTO_OPERATION = 19030001|@ohos.security.cert.d.ts|
|新增|NA|类名：DataBlob;<br>方法or属性：data : Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|类名：EncodingBlob;<br>方法or属性：data : Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainData;<br>方法or属性：data: Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|类名：DataArray;<br>方法or属性：data : Array\<Uint8Array>;|@ohos.security.cert.d.ts|
|新增|NA|类名：EncodingFormat;<br>方法or属性：FORMAT_DER = 0|@ohos.security.cert.d.ts|
|新增|NA|类名：EncodingFormat;<br>方法or属性：FORMAT_PEM = 1|@ohos.security.cert.d.ts|
|新增|NA|类名：EncodingBlob;<br>方法or属性：encodingFormat : EncodingFormat;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainData;<br>方法or属性：encodingFormat: EncodingFormat;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainData;<br>方法or属性：count : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：verify(key : cryptoFramework.PubKey) : Promise\<void>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：verify(key : cryptoFramework.PubKey) : Promise\<void>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getEncoded(callback : AsyncCallback\<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509CrlEntry;<br>方法or属性：getEncoded(callback : AsyncCallback\<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getEncoded(callback : AsyncCallback\<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getEncoded() : Promise\<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509CrlEntry;<br>方法or属性：getEncoded() : Promise\<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getEncoded() : Promise\<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getPublicKey() : cryptoFramework.PubKey;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：checkValidityWithDate(date: string) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getVersion() : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getVersion() : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSerialNumber() : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509CrlEntry;<br>方法or属性：getSerialNumber() : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getIssuerName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getIssuerName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSubjectName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getNotBeforeTime() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getNotAfterTime() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSignature() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getSignature() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSignatureAlgName() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getSignatureAlgName() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSignatureAlgOid() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getSignatureAlgOid() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSignatureAlgParams() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getSignatureAlgParams() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getKeyUsage() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getExtKeyUsage() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getBasicConstraints() : number;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getSubjectAltNames() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getIssuerAltNames() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509CrlEntry;<br>方法or属性：getCertIssuer() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509CrlEntry;<br>方法or属性：getRevocationDate() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：isRevoked(cert : X509Cert) : boolean;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getType() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getLastUpdate() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getNextUpdate() : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getRevokedCert(serialNumber : number) : X509CrlEntry;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getRevokedCerts(callback : AsyncCallback\<Array\<X509CrlEntry>>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getRevokedCerts() : Promise\<Array\<X509CrlEntry>>;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Crl;<br>方法or属性：getTbsInfo() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainValidator;<br>方法or属性：validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainValidator;<br>方法or属性：validate(certChain : CertChainData) : Promise\<void>;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertChainValidator;<br>方法or属性：readonly algorithm : string;|@ohos.security.cert.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createRandom() : Random;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGenerator(algName : string) : AsyKeyGenerator;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createSymKeyGenerator(algName : string) : SymKeyGenerator;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createMac(algName : string) : Mac;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createMd(algName : string) : Md;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createCipher(transformation : string) : Cipher;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createSign(algName : string) : Sign;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createVerify(algName : string) : Verify;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createKeyAgreement(algName : string) : KeyAgreement;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Result;<br>方法or属性：INVALID_PARAMS = 401|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Result;<br>方法or属性：NOT_SUPPORT = 801|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Result;<br>方法or属性：ERR_OUT_OF_MEMORY = 17620001|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Result;<br>方法or属性：ERR_RUNTIME_ERROR = 17620002|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Result;<br>方法or属性：ERR_CRYPTO_OPERATION = 17630001|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DataBlob;<br>方法or属性：data : Uint8Array;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ParamsSpec;<br>方法or属性：algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：IvParamsSpec;<br>方法or属性：iv : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：GcmParamsSpec;<br>方法or属性：iv : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CcmParamsSpec;<br>方法or属性：iv : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：GcmParamsSpec;<br>方法or属性：aad : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CcmParamsSpec;<br>方法or属性：aad : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：GcmParamsSpec;<br>方法or属性：authTag : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CcmParamsSpec;<br>方法or属性：authTag : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CryptoMode;<br>方法or属性：ENCRYPT_MODE = 0|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CryptoMode;<br>方法or属性：DECRYPT_MODE = 1|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Key;<br>方法or属性：getEncoded() : DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Key;<br>方法or属性：readonly format : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Key;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKeyGenerator;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：KeyAgreement;<br>方法or属性：readonly algName : string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKey;<br>方法or属性：clearMem() : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：PriKey;<br>方法or属性：clearMem() : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：KeyPair;<br>方法or属性：readonly priKey : PriKey;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：KeyPair;<br>方法or属性：readonly pubKey : PubKey;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Random;<br>方法or属性：generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Random;<br>方法or属性：generateRandom(len : number) : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Random;<br>方法or属性：setSeed(seed : DataBlob) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(callback : AsyncCallback\<KeyPair>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair() : Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey : DataBlob, priKey : DataBlob, callback : AsyncCallback\<KeyPair>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKeyGenerator;<br>方法or属性：generateSymKey(callback : AsyncCallback\<SymKey>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKeyGenerator;<br>方法or属性：generateSymKey() : Promise\<SymKey>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKeyGenerator;<br>方法or属性：convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SymKeyGenerator;<br>方法or属性：convertKey(key : DataBlob) : Promise\<SymKey>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：init(key : SymKey, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：init(key : SymKey) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：update(input : DataBlob, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：update(input : DataBlob, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：update(input : DataBlob) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：update(input : DataBlob) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：doFinal(callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：doFinal() : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Mac;<br>方法or属性：getMacLength() : number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：digest(callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：digest() : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Md;<br>方法or属性：getMdLength() : number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：update(data : DataBlob) : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data : DataBlob) : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：init(priKey : PriKey, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：init(priKey : PriKey) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：update(data : DataBlob, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：update(data : DataBlob, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：update(data : DataBlob) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：update(data : DataBlob) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data : DataBlob) : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：init(pubKey : PubKey, callback : AsyncCallback\<void>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：init(pubKey : PubKey) : Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：KeyAgreement;<br>方法or属性：generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：KeyAgreement;<br>方法or属性：generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function generateKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function generateKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function deleteKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function deleteKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function importKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function importKeyItem(keyAlias: string, options: HuksOptions) : Promise\<void>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions) : Promise\<void>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function exportKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function exportKeyItem(keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function getKeyItemProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function getKeyItemProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function isKeyItemExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function isKeyItemExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function initSession(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksSessionHandle>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function initSession(keyAlias: string, options: HuksOptions) : Promise\<HuksSessionHandle>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function updateSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function updateSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function updateSession(handle: number, options: HuksOptions, token?: Uint8Array) : Promise\<HuksReturnResult>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function finishSession(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function finishSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function finishSession(handle: number, options: HuksOptions, token?: Uint8Array) : Promise\<HuksReturnResult>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function abortSession(handle: number, options: HuksOptions, callback: AsyncCallback\<void>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function abortSession(handle: number, options: HuksOptions) : Promise\<void>;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void;|@ohos.security.huks.d.ts|
|新增|NA|类名：huks;<br>方法or属性：function attestKeyItem(keyAlias: string, options: HuksOptions) : Promise\<HuksReturnResult>;|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksSessionHandle;<br>方法or属性：challenge?: Uint8Array;|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_PERMISSION_FAIL = 201|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_NOT_SUPPORTED_API = 801|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_CRYPTO_FAIL = 12000006|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED = 12000007|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED = 12000008|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_KEY_AUTH_TIME_OUT = 12000009|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_SESSION_LIMIT = 12000010|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_EXTERNAL_ERROR = 12000012|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST = 12000013|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksExceptionErrCode;<br>方法or属性：HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyDigest;<br>方法or属性：HUKS_DIGEST_SM3 = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeySize;<br>方法or属性：HUKS_SM2_KEY_SIZE_256 = 256|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeySize;<br>方法or属性：HUKS_SM4_KEY_SIZE_128 = 128|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyAlg;<br>方法or属性：HUKS_ALG_SM2 = 150|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyAlg;<br>方法or属性：HUKS_ALG_SM3 = 151|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyAlg;<br>方法or属性：HUKS_ALG_SM4 = 152|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksUnwrapSuite;<br>方法or属性：HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING = 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksUnwrapSuite;<br>方法or属性：HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksImportKeyType;<br>方法or属性：HUKS_KEY_TYPE_PUBLIC_KEY = 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksImportKeyType;<br>方法or属性：HUKS_KEY_TYPE_PRIVATE_KEY = 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksImportKeyType;<br>方法or属性：HUKS_KEY_TYPE_KEY_PAIR = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksUserAuthType;<br>方法or属性：HUKS_USER_AUTH_TYPE_FINGERPRINT = 1 \<\< 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksUserAuthType;<br>方法or属性：HUKS_USER_AUTH_TYPE_FACE = 1 \<\< 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksUserAuthType;<br>方法or属性：HUKS_USER_AUTH_TYPE_PIN = 1 \<\< 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksAuthAccessType;<br>方法or属性：HUKS_AUTH_ACCESS_INVALID_CLEAR_PASSWORD = 1 \<\< 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksAuthAccessType;<br>方法or属性：HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL = 1 \<\< 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengeType;<br>方法or属性：HUKS_CHALLENGE_TYPE_NORMAL = 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengeType;<br>方法or属性：HUKS_CHALLENGE_TYPE_CUSTOM = 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengeType;<br>方法or属性：HUKS_CHALLENGE_TYPE_NONE = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengePosition;<br>方法or属性：HUKS_CHALLENGE_POS_0 = 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengePosition;<br>方法or属性：HUKS_CHALLENGE_POS_1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengePosition;<br>方法or属性：HUKS_CHALLENGE_POS_2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksChallengePosition;<br>方法or属性：HUKS_CHALLENGE_POS_3|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksSecureSignType;<br>方法or属性：HUKS_SECURE_SIGN_WITH_AUTHINFO = 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_IMPORT_KEY_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 25|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_UNWRAP_ALGORITHM_SUITE = HuksTagType.HUKS_TAG_TYPE_UINT \| 26|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_KEY_AUTH_ACCESS_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 307|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_KEY_SECURE_SIGN_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 308|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_CHALLENGE_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 309|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_CHALLENGE_POS = HuksTagType.HUKS_TAG_TYPE_UINT \| 310|@ohos.security.huks.d.ts|
|新增|NA|类名：PermissionRequestResult;<br>方法or属性：permissions: Array\<string>;|PermissionRequestResult.d.ts|
|新增|NA|类名：PermissionRequestResult;<br>方法or属性：authResults: Array\<number>;|PermissionRequestResult.d.ts|
|废弃版本有变化|类名：AtManager;<br>方法or属性：verifyAccessToken(tokenID: number, permissionName: string): Promise\<GrantStatus>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：verifyAccessToken(tokenID: number, permissionName: string): Promise\<GrantStatus>;<br>新版本信息：9<br>代替接口： ohos.abilityAccessCtrl.AtManager#checkAccessToken|@ohos.abilityAccessCtrl.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.generateKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.generateKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.deleteKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.deleteKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.importKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.importKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.exportKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.exportKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.getKeyItemProperties|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.getKeyItemProperties|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.isKeyItemExist|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>;<br>旧版本信息：|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.security.huks.isKeyItemExist|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.initSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>;<br>旧版本信息：|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>;<br>新版本信息：9<br>代替接口： ohos.security.huks.initSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.updateSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.updateSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.finishSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.finishSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>旧版本信息：|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>新版本信息：9<br>代替接口： ohos.security.huks.abortSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions) : Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions) : Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.abortSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksHandle;<br>方法or属性：export interface HuksHandle<br>旧版本信息：|类名：HuksHandle;<br>方法or属性：export interface HuksHandle<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksSessionHandle|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksHandle;<br>方法or属性：errorCode: number;<br>旧版本信息：|类名：HuksHandle;<br>方法or属性：errorCode: number;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksSessionHandle|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult;<br>方法or属性：errorCode: number;<br>旧版本信息：|类名：HuksResult;<br>方法or属性：errorCode: number;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksReturnResult|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksHandle;<br>方法or属性：handle: number;<br>旧版本信息：|类名：HuksHandle;<br>方法or属性：handle: number;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksSessionHandle|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksHandle;<br>方法or属性：token?: Uint8Array;<br>旧版本信息：|类名：HuksHandle;<br>方法or属性：token?: Uint8Array;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksSessionHandle|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult;<br>方法or属性：export interface HuksResult<br>旧版本信息：|类名：HuksResult;<br>方法or属性：export interface HuksResult<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksReturnResult|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult;<br>方法or属性：outData?: Uint8Array;<br>旧版本信息：|类名：HuksResult;<br>方法or属性：outData?: Uint8Array;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksReturnResult|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult;<br>方法or属性：properties?: Array\<HuksParam>;<br>旧版本信息：|类名：HuksResult;<br>方法or属性：properties?: Array\<HuksParam>;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksReturnResult|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksResult;<br>方法or属性：certChains?: Array\<string>;<br>旧版本信息：|类名：HuksResult;<br>方法or属性：certChains?: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksReturnResult|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：export enum HuksErrorCode<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：export enum HuksErrorCode<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_SUCCESS = 0<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_SUCCESS = 0<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_FAILURE = -1<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_FAILURE = -1<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_BAD_STATE = -2<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_BAD_STATE = -2<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ARGUMENT = -3<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ARGUMENT = -3<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NOT_SUPPORTED = -4<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NOT_SUPPORTED = -4<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NO_PERMISSION = -5<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NO_PERMISSION = -5<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INSUFFICIENT_DATA = -6<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INSUFFICIENT_DATA = -6<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_BUFFER_TOO_SMALL = -7<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_BUFFER_TOO_SMALL = -7<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INSUFFICIENT_MEMORY = -8<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INSUFFICIENT_MEMORY = -8<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_COMMUNICATION_FAILURE = -9<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_COMMUNICATION_FAILURE = -9<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_STORAGE_FAILURE = -10<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_STORAGE_FAILURE = -10<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_HARDWARE_FAILURE = -11<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_HARDWARE_FAILURE = -11<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_ALREADY_EXISTS = -12<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_ALREADY_EXISTS = -12<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NOT_EXIST = -13<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NOT_EXIST = -13<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NULL_POINTER = -14<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NULL_POINTER = -14<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_FILE_SIZE_FAIL = -15<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_FILE_SIZE_FAIL = -15<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_READ_FILE_FAIL = -16<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_READ_FILE_FAIL = -16<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PUBLIC_KEY = -17<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PUBLIC_KEY = -17<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PRIVATE_KEY = -18<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PRIVATE_KEY = -18<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_INFO = -19<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_INFO = -19<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_HASH_NOT_EQUAL = -20<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_HASH_NOT_EQUAL = -20<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_MALLOC_FAIL = -21<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_MALLOC_FAIL = -21<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_WRITE_FILE_FAIL = -22<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_WRITE_FILE_FAIL = -22<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_REMOVE_FILE_FAIL = -23<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_REMOVE_FILE_FAIL = -23<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_OPEN_FILE_FAIL = -24<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_OPEN_FILE_FAIL = -24<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CLOSE_FILE_FAIL = -25<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CLOSE_FILE_FAIL = -25<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_MAKE_DIR_FAIL = -26<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_MAKE_DIR_FAIL = -26<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_FILE = -27<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_FILE = -27<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_MSG_FAIL = -28<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_MSG_FAIL = -28<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_REQUEST_OVERFLOWS = -29<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_REQUEST_OVERFLOWS = -29<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_PARAM_NOT_EXIST = -30<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_PARAM_NOT_EXIST = -30<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CRYPTO_ENGINE_ERROR = -31<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CRYPTO_ENGINE_ERROR = -31<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_COMMUNICATION_TIMEOUT = -32<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_COMMUNICATION_TIMEOUT = -32<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_INIT_FAIL = -33<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_INIT_FAIL = -33<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_DLOPEN_FAIL = -34<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_IPC_DLOPEN_FAIL = -34<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_EFUSE_READ_FAIL = -35<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_EFUSE_READ_FAIL = -35<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST = -36<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST = -36<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL = -37<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL = -37<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_VERIFICATION_FAILED = -38<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_VERIFICATION_FAILED = -38<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_ALG_FAIL = -100<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_ALG_FAIL = -100<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL = -101<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL = -101<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_PADDING_FAIL = -102<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_PADDING_FAIL = -102<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_PURPOSE_FAIL = -103<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_PURPOSE_FAIL = -103<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_DIGEST_FAIL =  -104<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_DIGEST_FAIL =  -104<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_MODE_FAIL = -105<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_MODE_FAIL = -105<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_NONCE_FAIL = -106<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_NONCE_FAIL = -106<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_AAD_FAIL = -107<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_AAD_FAIL = -107<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_IV_FAIL = -108<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_IV_FAIL = -108<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_AE_TAG_FAIL = -109<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_AE_TAG_FAIL = -109<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_SALT_FAIL = -110<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_SALT_FAIL = -110<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_ITERATION_FAIL = -111<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_CHECK_GET_ITERATION_FAIL = -111<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ALGORITHM = -112<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ALGORITHM = -112<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_SIZE = -113<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_KEY_SIZE = -113<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PADDING = -114<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PADDING = -114<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PURPOSE = -115<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_PURPOSE = -115<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_MODE = -116<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_MODE = -116<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_DIGEST =  -117<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_DIGEST =  -117<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_SIGNATURE_SIZE = -118<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_SIGNATURE_SIZE = -118<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_IV = -119<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_IV = -119<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_AAD = -120<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_AAD = -120<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_NONCE = -121<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_NONCE = -121<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_AE_TAG = -122<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_AE_TAG = -122<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_SALT = -123<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_SALT = -123<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ITERATION = -124<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_ITERATION = -124<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_OPERATION = -125<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INVALID_OPERATION = -125<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INTERNAL_ERROR = -999<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_INTERNAL_ERROR = -999<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_UNKNOWN_ERROR = -1000<br>旧版本信息：|类名：HuksErrorCode;<br>方法or属性：HUKS_ERROR_UNKNOWN_ERROR = -1000<br>新版本信息：9<br>代替接口： ohos.security.huks.HuksExceptionErrCode|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag;<br>方法or属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>旧版本信息：|类名：HuksTag;<br>方法or属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>新版本信息：9<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：Cipher;<br>方法or属性：export default class Cipher<br>旧版本信息：|类名：Cipher;<br>方法or属性：export default class Cipher<br>新版本信息：9<br>代替接口： ohos.security.cryptoFramework.Cipher|@system.cipher.d.ts|
|废弃版本有变化|类名：Cipher;<br>方法or属性：static rsa(options: CipherRsaOptions): void;<br>旧版本信息：|类名：Cipher;<br>方法or属性：static rsa(options: CipherRsaOptions): void;<br>新版本信息：9<br>代替接口： ohos.security.cryptoFramework.Cipher|@system.cipher.d.ts|
|废弃版本有变化|类名：Cipher;<br>方法or属性：static aes(options: CipherAesOptions): void;<br>旧版本信息：|类名：Cipher;<br>方法or属性：static aes(options: CipherAesOptions): void;<br>新版本信息：9<br>代替接口： ohos.security.cryptoFramework.Cipher|@system.cipher.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>新版本信息：401,201,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>新版本信息：401,201,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>;<br>新版本信息：401,201,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|函数有变化|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number): Promise\<number>;|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;|@ohos.abilityAccessCtrl.d.ts|
|函数有变化|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number, callback: AsyncCallback\<number>): void;|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback\<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|函数有变化|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number): Promise\<number>;|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;|@ohos.abilityAccessCtrl.d.ts|
|函数有变化|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number, callback: AsyncCallback\<number>): void;|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback\<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|函数有变化|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: string): Promise\<number>;|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>;|@ohos.abilityAccessCtrl.d.ts|
