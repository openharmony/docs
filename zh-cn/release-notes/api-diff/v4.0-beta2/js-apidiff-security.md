| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createCertExtension(inStream: EncodingBlob, callback: AsyncCallback\<CertExtension>): void;|@ohos.security.cert.d.ts|
|新增|NA|类名：cert;<br>方法or属性：function createCertExtension(inStream: EncodingBlob): Promise\<CertExtension>;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertItemType;<br>方法or属性：CERT_ITEM_TYPE_TBS = 0|@ohos.security.cert.d.ts|
|新增|NA|类名：CertItemType;<br>方法or属性：CERT_ITEM_TYPE_PUBLIC_KEY = 1|@ohos.security.cert.d.ts|
|新增|NA|类名：CertItemType;<br>方法or属性：CERT_ITEM_TYPE_ISSUER_UNIQUE_ID = 2|@ohos.security.cert.d.ts|
|新增|NA|类名：CertItemType;<br>方法or属性：CERT_ITEM_TYPE_SUBJECT_UNIQUE_ID = 3|@ohos.security.cert.d.ts|
|新增|NA|类名：CertItemType;<br>方法or属性：CERT_ITEM_TYPE_EXTENSIONS = 4|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionOidType;<br>方法or属性：EXTENSION_OID_TYPE_ALL = 0|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionOidType;<br>方法or属性：EXTENSION_OID_TYPE_CRITICAL = 1|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionOidType;<br>方法or属性：EXTENSION_OID_TYPE_UNCRITICAL = 2|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionEntryType;<br>方法or属性：EXTENSION_ENTRY_TYPE_ENTRY = 0|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionEntryType;<br>方法or属性：EXTENSION_ENTRY_TYPE_ENTRY_CRITICAL = 1|@ohos.security.cert.d.ts|
|新增|NA|类名：ExtensionEntryType;<br>方法or属性：EXTENSION_ENTRY_TYPE_ENTRY_VALUE = 2|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getCertSerialNumber(): bigint;|@ohos.security.cert.d.ts|
|新增|NA|类名：X509Cert;<br>方法or属性：getItem(itemType: CertItemType): DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertExtension;<br>方法or属性：getEncoded(): EncodingBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertExtension;<br>方法or属性：getOidList(valueType: ExtensionOidType): DataArray;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertExtension;<br>方法or属性：getEntry(valueType: ExtensionEntryType, oid: DataBlob): DataBlob;|@ohos.security.cert.d.ts|
|新增|NA|类名：CertExtension;<br>方法or属性：checkCA(): number;|@ohos.security.cert.d.ts|
|新增|NA|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：PriKey;<br>方法or属性：getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：PubKey;<br>方法or属性：getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Random;<br>方法or属性：generateRandomSync(len: number): DataBlob;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Random;<br>方法or属性：readonly algName: string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：readonly algName: string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF1_PSRC_UINT8ARR = 103|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_SALT_LEN_NUM = 103|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_TRAILER_FIELD_NUM = 104|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：getCipherSpec(itemType: CipherSpecItem): string \| Uint8Array;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：setSignSpec(itemType: SignSpecItem, itemValue: number): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：getSignSpec(itemType: SignSpecItem): string \| number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：setVerifySpec(itemType: SignSpecItem, itemValue: number): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：getVerifySpec(itemType: SignSpecItem): string \| number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：DSA_P_BN = 101|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：DSA_Q_BN = 102|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：DSA_G_BN = 103|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：DSA_SK_BN = 104|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：DSA_PK_BN = 105|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_FP_P_BN = 201|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_A_BN = 202|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_B_BN = 203|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_G_X_BN = 204|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_G_Y_BN = 205|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_N_BN = 206|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_H_NUM = 207|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_SK_BN = 208|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_PK_X_BN = 209|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_PK_Y_BN = 210|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_FIELD_TYPE_STR = 211|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_FIELD_SIZE_NUM = 212|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：ECC_CURVE_NAME_STR = 213|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：RSA_N_BN = 301|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：RSA_SK_BN = 302|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecItem;<br>方法or属性：RSA_PK_BN = 303|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecType;<br>方法or属性：COMMON_PARAMS_SPEC = 0|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecType;<br>方法or属性：PRIVATE_KEY_SPEC = 1|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecType;<br>方法or属性：PUBLIC_KEY_SPEC = 2|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpecType;<br>方法or属性：KEY_PAIR_SPEC = 3|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpec;<br>方法or属性：algName: string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeySpec;<br>方法or属性：specType: AsyKeySpecType;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSACommonParamsSpec;<br>方法or属性：p: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECFieldFp;<br>方法or属性：p: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSACommonParamsSpec;<br>方法or属性：q: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSACommonParamsSpec;<br>方法or属性：g: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSAPubKeySpec;<br>方法or属性：params: DSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSAKeyPairSpec;<br>方法or属性：params: DSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSAPubKeySpec;<br>方法or属性：pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSAKeyPairSpec;<br>方法or属性：pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSAPubKeySpec;<br>方法or属性：pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSAKeyPairSpec;<br>方法or属性：pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：DSAKeyPairSpec;<br>方法or属性：sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCPriKeySpec;<br>方法or属性：sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCKeyPairSpec;<br>方法or属性：sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSAKeyPairSpec;<br>方法or属性：sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECField;<br>方法or属性：fieldType: string;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Point;<br>方法or属性：x: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Point;<br>方法or属性：y: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：field: ECField;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：a: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：b: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：g: Point;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：n: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSACommonParamsSpec;<br>方法or属性：n: bigint;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCCommonParamsSpec;<br>方法or属性：h: number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCPriKeySpec;<br>方法or属性：params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCPubKeySpec;<br>方法or属性：params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCKeyPairSpec;<br>方法or属性：params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCPubKeySpec;<br>方法or属性：pk: Point;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：ECCKeyPairSpec;<br>方法or属性：pk: Point;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSAPubKeySpec;<br>方法or属性：params: RSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：RSAKeyPairSpec;<br>方法or属性：params: RSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generatePriKey(callback: AsyncCallback\<PriKey>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generatePriKey(): Promise\<PriKey>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generatePubKey(callback: AsyncCallback\<PubKey>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generatePubKey(): Promise\<PubKey>;|@ohos.security.cryptoFramework.d.ts|
|废弃版本有变化|类名：X509Cert;<br>方法or属性：getSerialNumber(): number;<br>旧版本信息：|类名：X509Cert;<br>方法or属性：getSerialNumber(): number;<br>新版本信息：10<br>代替接口： ohos.security.cert.X509Cert.getCertSerialNumber|@ohos.security.cert.d.ts|
|新增(错误码)|类名：Key;<br>方法or属性：getEncoded(): DataBlob;<br>旧版本信息：|类名：Key;<br>方法or属性：getEncoded(): DataBlob;<br>新版本信息：801,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createCipher(transformation: string): Cipher;<br>旧版本信息：401,801|类名：cryptoFramework;<br>方法or属性：function createCipher(transformation: string): Cipher;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createSign(algName: string): Sign;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createSign(algName: string): Sign;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createVerify(algName: string): Verify;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createVerify(algName: string): Verify;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createKeyAgreement(algName: string): KeyAgreement;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createKeyAgreement(algName: string): KeyAgreement;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>旧版本信息：number|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>旧版本信息：boolean|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>新版本信息：?boolean|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>旧版本信息：string|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>新版本信息：?string|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>旧版本信息：string|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>旧版本信息：Array\<Permissions>|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>新版本信息：?Array\<Permissions>|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>旧版本信息：number|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>旧版本信息：number|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：tokenId: number;|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：isRemote: boolean;|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：deviceId: string;|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：bundleName: string;|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：permissionNames: Array\<Permissions>;|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：beginTime: number;|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：endTime: number;|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;|@ohos.privacyManager.d.ts|
