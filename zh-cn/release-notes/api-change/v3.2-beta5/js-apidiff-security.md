| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: AtManager<br>方法 or 属性: requestPermissionsFromUser(context: Context, permissions: Array<Permissions>, requestCallback: AsyncCallback<PermissionRequestResult>) : void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.abilityAccessCtrl<br>类名: AtManager<br>方法 or 属性: requestPermissionsFromUser(context: Context, permissions: Array<Permissions>) : Promise<PermissionRequestResult>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: INVALID_PARAMS = 401|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: NOT_SUPPORT = 801|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_OUT_OF_MEMORY = 19020001|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_RUNTIME_ERROR = 19020002|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_CRYPTO_OPERATION = 19030001|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_CERT_SIGNATURE_FAILURE = 19030002|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_CERT_NOT_YET_VALID = 19030003|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_CERT_HAS_EXPIRED = 19030004|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY = 19030005|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_KEYUSAGE_NO_CERTSIGN = 19030006|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertResult<br>方法 or 属性: ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE = 19030007|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: DataBlob|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: DataBlob<br>方法 or 属性: data : Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: DataArray|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: DataArray<br>方法 or 属性: data : Array<Uint8Array>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingFormat|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingFormat<br>方法 or 属性: FORMAT_DER = 0|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingFormat<br>方法 or 属性: FORMAT_PEM = 1|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingBlob|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingBlob<br>方法 or 属性: data : Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: EncodingBlob<br>方法 or 属性: encodingFormat : EncodingFormat;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainData|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainData<br>方法 or 属性: data: Uint8Array;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainData<br>方法 or 属性: count : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainData<br>方法 or 属性: encodingFormat: EncodingFormat;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: verify(key : cryptoFramework.PubKey, callback : AsyncCallback<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: verify(key : cryptoFramework.PubKey) : Promise<void>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getEncoded() : Promise<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getPublicKey() : cryptoFramework.PubKey;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: checkValidityWithDate(date: string) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getVersion() : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSerialNumber() : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getIssuerName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSubjectName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getNotBeforeTime() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getNotAfterTime() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSignature() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSignatureAlgName() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSignatureAlgOid() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSignatureAlgParams() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getKeyUsage() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getExtKeyUsage() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getBasicConstraints() : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getSubjectAltNames() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Cert<br>方法 or 属性: getIssuerAltNames() : DataArray;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert<br>方法 or 属性: function createX509Cert(inStream : EncodingBlob, callback : AsyncCallback<X509Cert>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert<br>方法 or 属性: function createX509Cert(inStream : EncodingBlob) : Promise<X509Cert>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry<br>方法 or 属性: getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry<br>方法 or 属性: getEncoded() : Promise<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry<br>方法 or 属性: getSerialNumber() : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry<br>方法 or 属性: getCertIssuer() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509CrlEntry<br>方法 or 属性: getRevocationDate() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: isRevoked(cert : X509Cert) : boolean;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getType() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getEncoded() : Promise<EncodingBlob>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: verify(key : cryptoFramework.PubKey, callback : AsyncCallback<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: verify(key : cryptoFramework.PubKey) : Promise<void>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getVersion() : number;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getIssuerName() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getLastUpdate() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getNextUpdate() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getRevokedCert(serialNumber : number) : X509CrlEntry;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getRevokedCerts(callback : AsyncCallback<Array<X509CrlEntry>>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getRevokedCerts() : Promise<Array<X509CrlEntry>>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getTbsInfo() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getSignature() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getSignatureAlgName() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getSignatureAlgOid() : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: X509Crl<br>方法 or 属性: getSignatureAlgParams() : DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert<br>方法 or 属性: function createX509Crl(inStream : EncodingBlob, callback : AsyncCallback<X509Crl>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert<br>方法 or 属性: function createX509Crl(inStream : EncodingBlob) : Promise<X509Crl>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainValidator|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainValidator<br>方法 or 属性: validate(certChain : CertChainData, callback : AsyncCallback<void>) : void;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainValidator<br>方法 or 属性: validate(certChain : CertChainData) : Promise<void>;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: CertChainValidator<br>方法 or 属性: readonly algorithm : string;|@ohos.security.cert.d.ts|
|新增|NA|模块名: ohos.security.cert<br>类名: cert<br>方法 or 属性: function createCertChainValidator(algorithm :string) : CertChainValidator;|@ohos.security.cert.d.ts|
|新增|NA|类名：Random<br>方法or属性：setSeed(seed : DataBlob) : void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|模块名: PermissionRequestResult<br>类名: PermissionRequestResult|PermissionRequestResult.d.ts|
|新增|NA|模块名: PermissionRequestResult<br>类名: PermissionRequestResult<br>方法 or 属性: permissions: Array<string>;|PermissionRequestResult.d.ts|
|新增|NA|模块名: PermissionRequestResult<br>类名: PermissionRequestResult<br>方法 or 属性: authResults: Array<number>;|PermissionRequestResult.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_CERT_SIGNATURE_FAILURE = 17630002|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_CERT_NOT_YET_VALID = 17630003|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_CERT_HAS_EXPIRED = 17630004|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY = 17630005|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_KEYUSAGE_NO_CERTSIGN = 17630006|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: Result<br>方法 or 属性：ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE = 17630007|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: DataArray|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: DataArray<br>方法 or 属性：data : Array<Uint8Array>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat<br>方法 or 属性：FORMAT_DER = 0|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingFormat<br>方法 or 属性：FORMAT_PEM = 1|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob<br>方法 or 属性：data : Uint8Array;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: EncodingBlob<br>方法 or 属性：encodingFormat : EncodingFormat;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainData|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法 or 属性：data: Uint8Array;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法 or 属性：count : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainData<br>方法 or 属性：encodingFormat: EncodingFormat;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：verify(key : PubKey, callback : AsyncCallback<void>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：verify(key : PubKey) : Promise<void>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getEncoded() : Promise<EncodingBlob>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getPublicKey(callback : AsyncCallback<PubKey>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getPublicKey() : Promise<PubKey>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：checkValidityWithDate(date: string, callback : AsyncCallback<void>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：checkValidityWithDate(date: string) : Promise<void>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getVersion() : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSerialNumber() : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getIssuerName() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSubjectName() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getNotBeforeTime() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getNotAfterTime() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSignature() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSignatureAlgName() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSignatureAlgOid() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSignatureAlgParams() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getKeyUsage() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getExtKeyUsage() : DataArray;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getBasicConstraints() : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getSubjectAltNames() : DataArray;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Cert<br>方法 or 属性：getIssuerAltNames() : DataArray;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名：ohos.security.cryptoFramework<br>类名:cryptoFramework<br>方法 or 属性:function createX509Cert(inStream : EncodingBlob, callback : AsyncCallback<X509Cert>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名：ohos.security.cryptoFramework<br>类名:cryptoFramework<br>方法 or 属性:function createX509Cert(inStream : EncodingBlob) : Promise<X509Cert>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getEncoded() : Promise<EncodingBlob>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getSerialNumber() : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getCertIssuer(callback : AsyncCallback<DataBlob>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getCertIssuer() : Promise<DataBlob>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getRevocationDate(callback : AsyncCallback<string>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509CrlEntry<br>方法 or 属性：getRevocationDate() : Promise<string>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：isRevoked(cert : X509Cert, callback : AsyncCallback<boolean>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：isRevoked(cert : X509Cert) : Promise<boolean>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getType() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getEncoded(callback : AsyncCallback<EncodingBlob>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getEncoded() : Promise<EncodingBlob>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：verify(key : PubKey, callback : AsyncCallback<void>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：verify(key : PubKey) : Promise<void>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getVersion() : number;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getIssuerName() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getLastUpdate() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getNextUpdate() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCert(serialNumber : number, callback : AsyncCallback<X509CrlEntry>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCert(serialNumber : number) : Promise<X509CrlEntry>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback<X509CrlEntry>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCertWithCert(cert : X509Cert) : Promise<X509CrlEntry>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCerts(callback : AsyncCallback<Array<X509CrlEntry>>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getRevokedCerts() : Promise<Array<X509CrlEntry>>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getTbsInfo(callback : AsyncCallback<DataBlob>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getTbsInfo() : Promise<DataBlob>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getSignature() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getSignatureAlgName() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getSignatureAlgOid() : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: X509Crl<br>方法 or 属性：getSignatureAlgParams() : DataBlob;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名：ohos.security.cryptoFramework<br>类名:cryptoFramework<br>方法 or 属性:function createX509Crl(inStream : EncodingBlob, callback : AsyncCallback<X509Crl>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名：ohos.security.cryptoFramework<br>类名:cryptoFramework<br>方法 or 属性:function createX509Crl(inStream : EncodingBlob) : Promise<X509Crl>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法 or 属性：validate(certChain : CertChainData, callback : AsyncCallback<void>) : void;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法 or 属性：validate(certChain : CertChainData) : Promise<void>;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名: ohos.security.cryptoFramework<br>类名: CertChainValidator<br>方法 or 属性：readonly algorithm : string;|NA|@ohos.security.cryptoFramework.d.ts|
|删除|模块名：ohos.security.cryptoFramework<br>类名:cryptoFramework<br>方法 or 属性:function createCertChainValidator(algorithm :string) : CertChainValidator;|NA|@ohos.security.cryptoFramework.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>废弃版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>废弃版本：9<br>代替接口：N/A|@ohos.security.huks.d.ts|
|起始版本有变化|类名：SymKey<br>起始版本：N/A|类名：SymKey<br>起始版本：9|@ohos.security.cryptoFramework.d.ts|
|起始版本有变化|类名：SymKey<br>方法 or 属性：clearMem() : void;<br>起始版本：N/A|类名：SymKey<br>方法 or 属性：clearMem() : void;<br>起始版本：9|@ohos.security.cryptoFramework.d.ts|
|起始版本有变化|类名：Random<br>起始版本：N/A|类名：Random<br>起始版本：9|@ohos.security.cryptoFramework.d.ts|
|起始版本有变化|类名：Cipher<br>起始版本：N/A|类名：Cipher<br>起始版本：9|@ohos.security.cryptoFramework.d.ts|
|起始版本有变化|类名：KeyAgreement<br>起始版本：N/A|类名：KeyAgreement<br>起始版本：9|@ohos.security.cryptoFramework.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>起始版本：N/A|类名：HuksTag<br>方法 or 属性：HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102<br>起始版本：8|@ohos.security.huks.d.ts|
|新增(错误码)|NA|类名：AsyKeyGenerator<br>方法 or 属性：generateKeyPair() : Promise<KeyPair>;<br>错误码内容:401,17620001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：AsyKeyGenerator<br>方法 or 属性：convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise<KeyPair>;<br>错误码内容:401,17620001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Cipher<br>方法 or 属性：init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise<void>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Cipher<br>方法 or 属性：update(data : DataBlob) : Promise<DataBlob>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Cipher<br>方法 or 属性：doFinal(data : DataBlob) : Promise<DataBlob>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Sign<br>方法 or 属性：init(priKey : PriKey) : Promise<void>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Sign<br>方法 or 属性：update(data : DataBlob) : Promise<void>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Sign<br>方法 or 属性：sign(data : DataBlob) : Promise<DataBlob>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Verify<br>方法 or 属性：init(pubKey : PubKey) : Promise<void>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Verify<br>方法 or 属性：update(data : DataBlob) : Promise<void>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：Verify<br>方法 or 属性：verify(data : DataBlob, signatureData : DataBlob) : Promise<boolean>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|NA|类名：KeyAgreement<br>方法 or 属性：generateSecret(priKey : PriKey, pubKey : PubKey) : Promise<DataBlob>;<br>错误码内容:401,17620001,17620002,17630001|@ohos.security.cryptoFramework.d.ts|
|函数有变化|类名：huks<br>方法 or 属性：function update(handle: number, options: HuksOptions, callback: AsyncCallback<HuksResult>) : void;<br>|类名：huks<br>方法 or 属性：function update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback<HuksResult>) : void;<br>|@ohos.security.huks.d.ts|
|函数有变化|类名：huks<br>方法 or 属性：function update(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback<HuksResult>) : void;<br>|类名：huks<br>方法 or 属性：function update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback<HuksResult>) : void;<br>|@ohos.security.huks.d.ts|
|函数有变化|类名：huks<br>方法 or 属性：function update(handle: number, options: HuksOptions, token?: Uint8Array) : Promise<HuksResult>;<br>|类名：huks<br>方法 or 属性：function update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise<HuksResult>;<br>|@ohos.security.huks.d.ts|
