| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generateKeyPair(callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generateKeyPair(): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: cert;<br>Method or attribute name: function createCertExtension(inStream: EncodingBlob, callback: AsyncCallback\<CertExtension>): void;|@ohos.security.cert.d.ts|
|Added|NA|Class name: cert;<br>Method or attribute name: function createCertExtension(inStream: EncodingBlob): Promise\<CertExtension>;|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertItemType;<br>Method or attribute name: CERT_ITEM_TYPE_TBS = 0|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertItemType;<br>Method or attribute name: CERT_ITEM_TYPE_PUBLIC_KEY = 1|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertItemType;<br>Method or attribute name: CERT_ITEM_TYPE_ISSUER_UNIQUE_ID = 2|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertItemType;<br>Method or attribute name: CERT_ITEM_TYPE_SUBJECT_UNIQUE_ID = 3|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertItemType;<br>Method or attribute name: CERT_ITEM_TYPE_EXTENSIONS = 4|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionOidType;<br>Method or attribute name: EXTENSION_OID_TYPE_ALL = 0|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionOidType;<br>Method or attribute name: EXTENSION_OID_TYPE_CRITICAL = 1|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionOidType;<br>Method or attribute name: EXTENSION_OID_TYPE_UNCRITICAL = 2|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionEntryType;<br>Method or attribute name: EXTENSION_ENTRY_TYPE_ENTRY = 0|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionEntryType;<br>Method or attribute name: EXTENSION_ENTRY_TYPE_ENTRY_CRITICAL = 1|@ohos.security.cert.d.ts|
|Added|NA|Class name: ExtensionEntryType;<br>Method or attribute name: EXTENSION_ENTRY_TYPE_ENTRY_VALUE = 2|@ohos.security.cert.d.ts|
|Added|NA|Class name: X509Cert;<br>Method or attribute name: getCertSerialNumber(): bigint;|@ohos.security.cert.d.ts|
|Added|NA|Class name: X509Cert;<br>Method or attribute name: getItem(itemType: CertItemType): DataBlob;|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertExtension;<br>Method or attribute name: getEncoded(): EncodingBlob;|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertExtension;<br>Method or attribute name: getOidList(valueType: ExtensionOidType): DataArray;|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertExtension;<br>Method or attribute name: getEntry(valueType: ExtensionEntryType, oid: DataBlob): DataBlob;|@ohos.security.cert.d.ts|
|Added|NA|Class name: CertExtension;<br>Method or attribute name: checkCA(): number;|@ohos.security.cert.d.ts|
|Added|NA|Class name: cryptoFramework;<br>Method or attribute name: function createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: PriKey;<br>Method or attribute name: getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: PubKey;<br>Method or attribute name: getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Random;<br>Method or attribute name: generateRandomSync(len: number): DataBlob;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Random;<br>Method or attribute name: readonly algName: string;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: readonly algName: string;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: CipherSpecItem;<br>Method or attribute name: OAEP_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: CipherSpecItem;<br>Method or attribute name: OAEP_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: CipherSpecItem;<br>Method or attribute name: OAEP_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: CipherSpecItem;<br>Method or attribute name: OAEP_MGF1_PSRC_UINT8ARR = 103|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: SignSpecItem;<br>Method or attribute name: PSS_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: SignSpecItem;<br>Method or attribute name: PSS_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: SignSpecItem;<br>Method or attribute name: PSS_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: SignSpecItem;<br>Method or attribute name: PSS_SALT_LEN_NUM = 103|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: SignSpecItem;<br>Method or attribute name: PSS_TRAILER_FIELD_NUM = 104|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: getCipherSpec(itemType: CipherSpecItem): string \| Uint8Array;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Sign;<br>Method or attribute name: setSignSpec(itemType: SignSpecItem, itemValue: number): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Sign;<br>Method or attribute name: getSignSpec(itemType: SignSpecItem): string \| number;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Verify;<br>Method or attribute name: setVerifySpec(itemType: SignSpecItem, itemValue: number): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Verify;<br>Method or attribute name: getVerifySpec(itemType: SignSpecItem): string \| number;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: DSA_P_BN = 101|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: DSA_Q_BN = 102|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: DSA_G_BN = 103|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: DSA_SK_BN = 104|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: DSA_PK_BN = 105|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_FP_P_BN = 201|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_A_BN = 202|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_B_BN = 203|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_G_X_BN = 204|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_G_Y_BN = 205|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_N_BN = 206|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_H_NUM = 207|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_SK_BN = 208|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_PK_X_BN = 209|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_PK_Y_BN = 210|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_FIELD_TYPE_STR = 211|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_FIELD_SIZE_NUM = 212|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: ECC_CURVE_NAME_STR = 213|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: RSA_N_BN = 301|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: RSA_SK_BN = 302|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecItem;<br>Method or attribute name: RSA_PK_BN = 303|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecType;<br>Method or attribute name: COMMON_PARAMS_SPEC = 0|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecType;<br>Method or attribute name: PRIVATE_KEY_SPEC = 1|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecType;<br>Method or attribute name: PUBLIC_KEY_SPEC = 2|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpecType;<br>Method or attribute name: KEY_PAIR_SPEC = 3|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpec;<br>Method or attribute name: algName: string;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeySpec;<br>Method or attribute name: specType: AsyKeySpecType;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSACommonParamsSpec;<br>Method or attribute name: p: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECFieldFp;<br>Method or attribute name: p: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSACommonParamsSpec;<br>Method or attribute name: q: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSACommonParamsSpec;<br>Method or attribute name: g: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSAPubKeySpec;<br>Method or attribute name: params: DSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSAKeyPairSpec;<br>Method or attribute name: params: DSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSAPubKeySpec;<br>Method or attribute name: pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSAKeyPairSpec;<br>Method or attribute name: pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSAPubKeySpec;<br>Method or attribute name: pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSAKeyPairSpec;<br>Method or attribute name: pk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: DSAKeyPairSpec;<br>Method or attribute name: sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCPriKeySpec;<br>Method or attribute name: sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCKeyPairSpec;<br>Method or attribute name: sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSAKeyPairSpec;<br>Method or attribute name: sk: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECField;<br>Method or attribute name: fieldType: string;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: x: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: y: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: field: ECField;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: a: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: b: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: g: Point;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: n: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSACommonParamsSpec;<br>Method or attribute name: n: bigint;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCCommonParamsSpec;<br>Method or attribute name: h: number;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCPriKeySpec;<br>Method or attribute name: params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCPubKeySpec;<br>Method or attribute name: params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCKeyPairSpec;<br>Method or attribute name: params: ECCCommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCPubKeySpec;<br>Method or attribute name: pk: Point;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: ECCKeyPairSpec;<br>Method or attribute name: pk: Point;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSAPubKeySpec;<br>Method or attribute name: params: RSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: RSAKeyPairSpec;<br>Method or attribute name: params: RSACommonParamsSpec;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generatePriKey(callback: AsyncCallback\<PriKey>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generatePriKey(): Promise\<PriKey>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generatePubKey(callback: AsyncCallback\<PubKey>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGeneratorBySpec;<br>Method or attribute name: generatePubKey(): Promise\<PubKey>;|@ohos.security.cryptoFramework.d.ts|
|Deprecated version changed|Class name: X509Cert;<br>Method or attribute name: getSerialNumber(): number;<br>Old version information: |Class name: X509Cert;<br>Method or attribute name: getSerialNumber(): number;<br>New version information: 10<br>Substitute API: ohos.security.cert.X509Cert.getCertSerialNumber|@ohos.security.cert.d.ts|
|Error code added|Class name: Key;<br>Method or attribute name: getEncoded(): DataBlob;<br>Old version information: |Class name: Key;<br>Method or attribute name: getEncoded(): DataBlob;<br>New version information: 801,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: cryptoFramework;<br>Method or attribute name: function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>Old version information: 401|Class name: cryptoFramework;<br>Method or attribute name: function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>New version information: 401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: cryptoFramework;<br>Method or attribute name: function createCipher(transformation: string): Cipher;<br>Old version information: 401,801|Class name: cryptoFramework;<br>Method or attribute name: function createCipher(transformation: string): Cipher;<br>New version information: 401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: cryptoFramework;<br>Method or attribute name: function createSign(algName: string): Sign;<br>Old version information: 401|Class name: cryptoFramework;<br>Method or attribute name: function createSign(algName: string): Sign;<br>New version information: 401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: cryptoFramework;<br>Method or attribute name: function createVerify(algName: string): Verify;<br>Old version information: 401|Class name: cryptoFramework;<br>Method or attribute name: function createVerify(algName: string): Verify;<br>New version information: 401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: cryptoFramework;<br>Method or attribute name: function createKeyAgreement(algName: string): KeyAgreement;<br>Old version information: 401|Class name: cryptoFramework;<br>Method or attribute name: function createKeyAgreement(algName: string): KeyAgreement;<br>New version information: 401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: AsyKeyGenerator;<br>Method or attribute name: generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>Old version information: 401,17620001|Class name: AsyKeyGenerator;<br>Method or attribute name: generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>New version information: 401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: AsyKeyGenerator;<br>Method or attribute name: generateKeyPair(): Promise\<KeyPair>;<br>Old version information: 401,17620001|Class name: AsyKeyGenerator;<br>Method or attribute name: generateKeyPair(): Promise\<KeyPair>;<br>New version information: 401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>Old version information: 401,17620001|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>New version information: 401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|Error code changed|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>Old version information: 401,17620001|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>New version information: 401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: tokenId?: number;<br>Old version information: number|Class name: PermissionUsedRequest;<br>Method or attribute name: tokenId?: number;<br>New version information: ?number|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: isRemote?: boolean;<br>Old version information: boolean|Class name: PermissionUsedRequest;<br>Method or attribute name: isRemote?: boolean;<br>New version information: ?boolean|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: deviceId?: string;<br>Old version information: string|Class name: PermissionUsedRequest;<br>Method or attribute name: deviceId?: string;<br>New version information: ?string|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: bundleName?: string;<br>Old version information: string|Class name: PermissionUsedRequest;<br>Method or attribute name: bundleName?: string;<br>New version information: ?string|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: permissionNames?: Array\<Permissions>;<br>Old version information: Array\<Permissions>|Class name: PermissionUsedRequest;<br>Method or attribute name: permissionNames?: Array\<Permissions>;<br>New version information: ?Array\<Permissions>|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: beginTime?: number;<br>Old version information: number|Class name: PermissionUsedRequest;<br>Method or attribute name: beginTime?: number;<br>New version information: ?number|@ohos.privacyManager.d.ts|
|Type changed|Class name: PermissionUsedRequest;<br>Method or attribute name: endTime?: number;<br>Old version information: number|Class name: PermissionUsedRequest;<br>Method or attribute name: endTime?: number;<br>New version information: ?number|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: tokenId: number;|Class name: PermissionUsedRequest;<br>Method or attribute name: tokenId?: number;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: isRemote: boolean;|Class name: PermissionUsedRequest;<br>Method or attribute name: isRemote?: boolean;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: deviceId: string;|Class name: PermissionUsedRequest;<br>Method or attribute name: deviceId?: string;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: bundleName: string;|Class name: PermissionUsedRequest;<br>Method or attribute name: bundleName?: string;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: permissionNames: Array\<Permissions>;|Class name: PermissionUsedRequest;<br>Method or attribute name: permissionNames?: Array\<Permissions>;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: beginTime: number;|Class name: PermissionUsedRequest;<br>Method or attribute name: beginTime?: number;|@ohos.privacyManager.d.ts|
|Function changed|Class name: PermissionUsedRequest;<br>Method or attribute name: endTime: number;|Class name: PermissionUsedRequest;<br>Method or attribute name: endTime?: number;|@ohos.privacyManager.d.ts|
