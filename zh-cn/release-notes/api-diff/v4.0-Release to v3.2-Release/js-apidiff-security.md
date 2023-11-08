| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGeneratorBySpec;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AtManager;<br>方法or属性：checkAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function isDLPFile(fd: number): Promise\<boolean>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function isDLPFile(fd: number, callback: AsyncCallback\<boolean>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPPermissionInfo(): Promise\<DLPPermissionInfo>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPPermissionInfo(callback: AsyncCallback\<DLPPermissionInfo>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getOriginalFileName(fileName: string): string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPSuffix(): string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function on(type: 'openDLPFile', listener: Callback\<AccessedDLPFileInfo>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function on(type: 'uninstallDLPSandbox', listener: Callback\<DLPSandboxState>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function off(type: 'openDLPFile', listener?: Callback\<AccessedDLPFileInfo>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function off(type: 'uninstallDLPSandbox', listener?: Callback\<DLPSandboxState>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function isInSandbox(): Promise\<boolean>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function isInSandbox(callback: AsyncCallback\<boolean>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPSupportedFileTypes(): Promise\<Array\<string>>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPSupportedFileTypes(callback: AsyncCallback\<Array\<string>>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function setRetentionState(docUris: Array\<string>): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function setRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function cancelRetentionState(docUris: Array\<string>): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function cancelRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getRetentionSandboxList(bundleName?: string): Promise\<Array\<RetentionSandboxInfo>>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getRetentionSandboxList(bundleName: string, callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getRetentionSandboxList(callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPFileAccessRecords(): Promise\<Array\<AccessedDLPFileInfo>>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPFileAccessRecords(callback: AsyncCallback\<Array\<AccessedDLPFileInfo>>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPGatheringPolicy(): Promise\<GatheringPolicyType>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function getDLPGatheringPolicy(callback: AsyncCallback\<GatheringPolicyType>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function installDLPSandbox(<br>    bundleName: string,<br>    access: DLPFileAccess,<br>    userId: number,<br>    uri: string<br>  ): Promise\<DLPSandboxInfo>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function installDLPSandbox(<br>    bundleName: string,<br>    access: DLPFileAccess,<br>    userId: number,<br>    uri: string,<br>    callback: AsyncCallback\<DLPSandboxInfo><br>  ): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function uninstallDLPSandbox(<br>    bundleName: string,<br>    userId: number,<br>    appIndex: number,<br>    callback: AsyncCallback\<void><br>  ): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise\<DLPFile>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function generateDLPFile(<br>    plaintextFd: number,<br>    ciphertextFd: number,<br>    property: DLPProperty,<br>    callback: AsyncCallback\<DLPFile><br>  ): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function openDLPFile(ciphertextFd: number): Promise\<DLPFile>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：dlpPermission;<br>方法or属性：function openDLPFile(ciphertextFd: number, callback: AsyncCallback\<DLPFile>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_VIEW = 0x00000001|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_SAVE = 0x00000002|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_SAVE_AS = 0x00000004|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_EDIT = 0x00000008|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_SCREEN_CAPTURE = 0x00000010|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_SCREEN_SHARE = 0x00000020|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_SCREEN_RECORD = 0x00000040|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_COPY = 0x00000080|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_PRINT = 0x00000100|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_EXPORT = 0x00000200|@ohos.dlpPermission.d.ts|
|新增|NA|类名：ActionFlagType;<br>方法or属性：ACTION_PERMISSION_CHANGE = 0x00000400|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFileAccess;<br>方法or属性：NO_PERMISSION = 0|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFileAccess;<br>方法or属性：READ_ONLY = 1|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFileAccess;<br>方法or属性：CONTENT_EDIT = 2|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFileAccess;<br>方法or属性：FULL_CONTROL = 3|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPPermissionInfo;<br>方法or属性：dlpFileAccess: DLPFileAccess;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AuthUser;<br>方法or属性：dlpFileAccess: DLPFileAccess;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPPermissionInfo;<br>方法or属性：flags: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AccessedDLPFileInfo;<br>方法or属性：uri: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AccessedDLPFileInfo;<br>方法or属性：lastOpenTime: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：RetentionSandboxInfo;<br>方法or属性：appIndex: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPSandboxInfo;<br>方法or属性：appIndex: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPSandboxState;<br>方法or属性：appIndex: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：RetentionSandboxInfo;<br>方法or属性：bundleName: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPSandboxState;<br>方法or属性：bundleName: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：RetentionSandboxInfo;<br>方法or属性：docUris: Array\<string>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：GatheringPolicyType;<br>方法or属性：GATHERING = 1|@ohos.dlpPermission.d.ts|
|新增|NA|类名：GatheringPolicyType;<br>方法or属性：NON_GATHERING = 2|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPSandboxInfo;<br>方法or属性：tokenID: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AccountType;<br>方法or属性：CLOUD_ACCOUNT = 1|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AccountType;<br>方法or属性：DOMAIN_ACCOUNT = 2|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AuthUser;<br>方法or属性：authAccount: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AuthUser;<br>方法or属性：authAccountType: AccountType;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：AuthUser;<br>方法or属性：permExpiryTime: number;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：ownerAccount: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：ownerAccountID: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：ownerAccountType: AccountType;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：authUserList?: Array\<AuthUser>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：contactAccount: string;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：offlineAccess: boolean;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPProperty;<br>方法or属性：everyoneAccessList?: Array\<DLPFileAccess>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：dlpProperty: DLPProperty;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：addDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：addDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：stopFuseLink(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：stopFuseLink(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：resumeFuseLink(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：resumeFuseLink(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：replaceDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：deleteDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：recoverDLPFile(plaintextFd: number): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：recoverDLPFile(plaintextFd: number, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：closeDLPFile(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|新增|NA|类名：DLPFile;<br>方法or属性：closeDLPFile(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
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
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null, callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：CipherSpecItem;<br>方法or属性：OAEP_MGF1_PSRC_UINT8ARR = 103|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MD_NAME_STR = 100|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MGF_NAME_STR = 101|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_MGF1_MD_STR = 102|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_SALT_LEN_NUM = 103|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：SignSpecItem;<br>方法or属性：PSS_TRAILER_FIELD_NUM = 104|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null, callback: AsyncCallback\<void>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null): Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：getCipherSpec(itemType: CipherSpecItem): string \| Uint8Array;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：setSignSpec(itemType: SignSpecItem, itemValue: number): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：getSignSpec(itemType: SignSpecItem): string \| number;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data: DataBlob \| null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data: DataBlob \| null, signatureData: DataBlob): Promise\<boolean>;|@ohos.security.cryptoFramework.d.ts|
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
|新增|NA|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_ONLY_USED_IN_HUKS = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_KEY_EXPORT_ALLOWED = 3|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksRsaPssSaltLenType;<br>方法or属性：HUKS_RSA_PSS_SALT_LEN_DIGEST = 0|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksRsaPssSaltLenType;<br>方法or属性：HUKS_RSA_PSS_SALT_LEN_MAX = 1|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 29|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_RSA_PSS_SALT_LEN_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 30|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksTag;<br>方法or属性：HUKS_TAG_KEY_AUTH_PURPOSE = HuksTagType.HUKS_TAG_TYPE_UINT \| 311|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：X509Cert;<br>方法or属性：getSerialNumber(): number;<br>旧版本信息：|类名：X509Cert;<br>方法or属性：getSerialNumber(): number;<br>新版本信息：10<br>代替接口： ohos.security.cert.X509Cert.getCertSerialNumber|@ohos.security.cert.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function generateKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.generateKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function deleteKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.deleteKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function importKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.importKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function exportKey(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.exportKeyItem|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function getKeyProperties(keyAlias: string, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.getKeyItemProperties|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions): Promise\<boolean>;<br>旧版本信息：|类名：huks;<br>方法or属性：function isKeyExist(keyAlias: string, options: HuksOptions): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.security.huks.isKeyItemExist|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions): Promise\<HuksHandle>;<br>旧版本信息：|类名：huks;<br>方法or属性：function init(keyAlias: string, options: HuksOptions): Promise\<HuksHandle>;<br>新版本信息：9<br>代替接口： ohos.security.huks.initSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function update(handle: number, token?: Uint8Array, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.updateSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function finish(handle: number, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.finishSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions): Promise\<HuksResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function abort(handle: number, options: HuksOptions): Promise\<HuksResult>;<br>新版本信息：9<br>代替接口： ohos.security.huks.abortSession|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_TEMP = 0<br>旧版本信息：|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_TEMP = 0<br>新版本信息：10<br>代替接口：|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_PERSISTENT = 1<br>旧版本信息：|类名：HuksKeyStorageType;<br>方法or属性：HUKS_STORAGE_PERSISTENT = 1<br>新版本信息：10<br>代替接口：|@ohos.security.huks.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>新版本信息：401,12100001|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：AtManager;<br>方法or属性：getVersion(): Promise\<number>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：getVersion(): Promise\<number>;<br>新版本信息：202|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|类名：Key;<br>方法or属性：getEncoded(): DataBlob;<br>旧版本信息：|类名：Key;<br>方法or属性：getEncoded(): DataBlob;<br>新版本信息：801,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Random;<br>方法or属性：generateRandom(len: number): Promise\<DataBlob>;<br>旧版本信息：|类名：Random;<br>方法or属性：generateRandom(len: number): Promise\<DataBlob>;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Mac;<br>方法or属性：init(key: SymKey): Promise\<void>;<br>旧版本信息：|类名：Mac;<br>方法or属性：init(key: SymKey): Promise\<void>;<br>新版本信息：401,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Mac;<br>方法or属性：update(input: DataBlob): Promise\<void>;<br>旧版本信息：|类名：Mac;<br>方法or属性：update(input: DataBlob): Promise\<void>;<br>新版本信息：401,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Md;<br>方法or属性：update(input: DataBlob): Promise\<void>;<br>旧版本信息：|类名：Md;<br>方法or属性：update(input: DataBlob): Promise\<void>;<br>新版本信息：401,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Mac;<br>方法or属性：doFinal(): Promise\<DataBlob>;<br>旧版本信息：|类名：Mac;<br>方法or属性：doFinal(): Promise\<DataBlob>;<br>新版本信息：17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：Md;<br>方法or属性：digest(): Promise\<DataBlob>;<br>旧版本信息：|类名：Md;<br>方法or属性：digest(): Promise\<DataBlob>;<br>新版本信息：17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function generateKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>旧版本信息：|类名：huks;<br>方法or属性：function generateKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000012,12000013,12000014,12000015|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function deleteKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>旧版本信息：|类名：huks;<br>方法or属性：function deleteKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>新版本信息：401,801,12000004,12000005,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function importKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>旧版本信息：|类名：huks;<br>方法or属性：function importKeyItem(keyAlias: string, options: HuksOptions): Promise\<void>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000011,12000012,12000013,12000014,12000015|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions): Promise\<void>;<br>旧版本信息：|类名：huks;<br>方法or属性：function importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions): Promise\<void>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000011,12000012,12000013,12000014,12000015|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function exportKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function exportKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function getKeyItemProperties(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function getKeyItemProperties(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function isKeyItemExist(keyAlias: string, options: HuksOptions): Promise\<boolean>;<br>旧版本信息：|类名：huks;<br>方法or属性：function isKeyItemExist(keyAlias: string, options: HuksOptions): Promise\<boolean>;<br>新版本信息：401,801,12000002,12000003,12000004,12000005,12000006,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function initSession(keyAlias: string, options: HuksOptions): Promise\<HuksSessionHandle>;<br>旧版本信息：|类名：huks;<br>方法or属性：function initSession(keyAlias: string, options: HuksOptions): Promise\<HuksSessionHandle>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000010,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function updateSession(<br><br>    handle: number,<br><br>    options: HuksOptions,<br><br>    token: Uint8Array,<br><br>    callback: AsyncCallback\<HuksReturnResult><br><br>  ): void;<br>旧版本信息：|类名：huks;<br>方法or属性：function updateSession(<br><br>    handle: number,<br><br>    options: HuksOptions,<br><br>    token: Uint8Array,<br><br>    callback: AsyncCallback\<HuksReturnResult><br><br>  ): void;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000007,12000008,12000009,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function updateSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function updateSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000007,12000008,12000009,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function finishSession(<br><br>    handle: number,<br><br>    options: HuksOptions,<br><br>    token: Uint8Array,<br><br>    callback: AsyncCallback\<HuksReturnResult><br><br>  ): void;<br>旧版本信息：|类名：huks;<br>方法or属性：function finishSession(<br><br>    handle: number,<br><br>    options: HuksOptions,<br><br>    token: Uint8Array,<br><br>    callback: AsyncCallback\<HuksReturnResult><br><br>  ): void;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000007,12000008,12000009,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function finishSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function finishSession(handle: number, options: HuksOptions, token?: Uint8Array): Promise\<HuksReturnResult>;<br>新版本信息：401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000007,12000008,12000009,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function abortSession(handle: number, options: HuksOptions): Promise\<void>;<br>旧版本信息：|类名：huks;<br>方法or属性：function abortSession(handle: number, options: HuksOptions): Promise\<void>;<br>新版本信息：401,801,12000004,12000005,12000006,12000012,12000014|@ohos.security.huks.d.ts|
|新增(错误码)|类名：huks;<br>方法or属性：function attestKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>旧版本信息：|类名：huks;<br>方法or属性：function attestKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult>;<br>新版本信息：201,401,801,12000001,12000002,12000003,12000004,12000005,12000006,12000011,12000012,12000014|@ohos.security.huks.d.ts|
|错误码有变化|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100006,12100007|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|错误码有变化|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100006,12100007|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|错误码有变化|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100006,12100007|类名：AtManager;<br>方法or属性：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|错误码有变化|类名：AtManager;<br>方法or属性：on(<br>      type: 'permissionStateChange',<br>      tokenIDList: Array\<number>,<br>      permissionList: Array\<Permissions>,<br>      callback: Callback\<PermissionStateChangeInfo><br>    ): void;<br>旧版本信息：401,201,12100001,12100004,12100005,12100007,12100008|类名：AtManager;<br>方法or属性：on(<br>      type: 'permissionStateChange',<br>      tokenIDList: Array\<number>,<br>      permissionList: Array\<Permissions>,<br>      callback: Callback\<PermissionStateChangeInfo><br>    ): void;<br>新版本信息：401,201,202,12100001,12100004,12100005,12100007,12100008|@ohos.abilityAccessCtrl.d.ts|
|错误码有变化|类名：AtManager;<br>方法or属性：off(<br>      type: 'permissionStateChange',<br>      tokenIDList: Array\<number>,<br>      permissionList: Array\<Permissions>,<br>      callback?: Callback\<PermissionStateChangeInfo><br>    ): void;<br>旧版本信息：401,201,12100001,12100004,12100007,12100008|类名：AtManager;<br>方法or属性：off(<br>      type: 'permissionStateChange',<br>      tokenIDList: Array\<number>,<br>      permissionList: Array\<Permissions>,<br>      callback?: Callback\<PermissionStateChangeInfo><br>    ): void;<br>新版本信息：401,201,202,12100001,12100004,12100007,12100008|@ohos.abilityAccessCtrl.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number<br>  ): Promise\<void>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100007,12100008|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number<br>  ): Promise\<void>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100007,12100008|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100004,12100007,12100008|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;<br>旧版本信息：401,201,12100001,12100002,12100003,12100004,12100007,12100008|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>;<br>新版本信息：401,201,202,12100001,12100002,12100003,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function on(<br>    type: 'activeStateChange',<br>    permissionList: Array\<Permissions>,<br>    callback: Callback\<ActiveChangeResponse><br>  ): void;<br>旧版本信息：401,201,12100001,12100004,12100005,12100007,12100008|类名：privacyManager;<br>方法or属性：function on(<br>    type: 'activeStateChange',<br>    permissionList: Array\<Permissions>,<br>    callback: Callback\<ActiveChangeResponse><br>  ): void;<br>新版本信息：401,201,202,12100001,12100004,12100005,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：privacyManager;<br>方法or属性：function off(<br>    type: 'activeStateChange',<br>    permissionList: Array\<Permissions>,<br>    callback?: Callback\<ActiveChangeResponse><br>  ): void;<br>旧版本信息：401,201,12100001,12100004,12100007,12100008|类名：privacyManager;<br>方法or属性：function off(<br>    type: 'activeStateChange',<br>    permissionList: Array\<Permissions>,<br>    callback?: Callback\<ActiveChangeResponse><br>  ): void;<br>新版本信息：401,201,202,12100001,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createAsyKeyGenerator(algName: string): AsyKeyGenerator;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createCipher(transformation: string): Cipher;<br>旧版本信息：401,801|类名：cryptoFramework;<br>方法or属性：function createCipher(transformation: string): Cipher;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createSign(algName: string): Sign;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createSign(algName: string): Sign;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createVerify(algName: string): Verify;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createVerify(algName: string): Verify;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：cryptoFramework;<br>方法or属性：function createKeyAgreement(algName: string): KeyAgreement;<br>旧版本信息：401|类名：cryptoFramework;<br>方法or属性：function createKeyAgreement(algName: string): KeyAgreement;<br>新版本信息：401,801,17620001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(callback: AsyncCallback\<KeyPair>): void;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：generateKeyPair(): Promise\<KeyPair>;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair>): void;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|错误码有变化|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>旧版本信息：401,17620001|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair>;<br>新版本信息：401,17620001,17630001|@ohos.security.cryptoFramework.d.ts|
|访问级别有变化|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_REVOKED_OPER = 0<br>旧版本信息：|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_REVOKED_OPER = 0<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_GRANTED_OPER = 1<br>旧版本信息：|类名：PermissionStateChangeType;<br>方法or属性：PERMISSION_GRANTED_OPER = 1<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：PermissionStateChangeInfo;<br>方法or属性：change: PermissionStateChangeType;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：change: PermissionStateChangeType;<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：PermissionStateChangeInfo;<br>方法or属性：tokenID: number;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：tokenID: number;<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：PermissionStateChangeInfo;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：permissionName: Permissions;<br>新版本信息：systemapi|@ohos.abilityAccessCtrl.d.ts|
|访问级别有变化|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionActiveStatus;<br>方法or属性：PERM_INACTIVE = 0<br>旧版本信息：|类名：PermissionActiveStatus;<br>方法or属性：PERM_INACTIVE = 0<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_FOREGROUND = 1<br>旧版本信息：|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_FOREGROUND = 1<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_BACKGROUND = 2<br>旧版本信息：|类名：PermissionActiveStatus;<br>方法or属性：PERM_ACTIVE_IN_BACKGROUND = 2<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：ActiveChangeResponse;<br>方法or属性：tokenId: number;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：tokenId: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：BundleUsedRecord;<br>方法or属性：tokenId: number;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：tokenId: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：ActiveChangeResponse;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：permissionName: Permissions;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：permissionName: Permissions;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：ActiveChangeResponse;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：deviceId: string;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：BundleUsedRecord;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：deviceId: string;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：ActiveChangeResponse;<br>方法or属性：activeStatus: PermissionActiveStatus;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：activeStatus: PermissionActiveStatus;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_SUMMARY = 0<br>旧版本信息：|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_SUMMARY = 0<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_DETAIL = 1<br>旧版本信息：|类名：PermissionUsageFlag;<br>方法or属性：FLAG_PERMISSION_USAGE_DETAIL = 1<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：BundleUsedRecord;<br>方法or属性：isRemote: boolean;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：isRemote: boolean;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：BundleUsedRecord;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：bundleName: string;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedResponse;<br>方法or属性：beginTime: number;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：beginTime: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedResponse;<br>方法or属性：endTime: number;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：endTime: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRequest;<br>方法or属性：flag: PermissionUsageFlag;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：flag: PermissionUsageFlag;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedResponse;<br>方法or属性：bundleRecords: Array\<BundleUsedRecord>;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：bundleRecords: Array\<BundleUsedRecord>;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：BundleUsedRecord;<br>方法or属性：permissionRecords: Array\<PermissionUsedRecord>;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：permissionRecords: Array\<PermissionUsedRecord>;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：accessCount: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：accessCount: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：rejectCount: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：rejectCount: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：lastAccessTime: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastAccessTime: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：lastRejectTime: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastRejectTime: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：lastAccessDuration: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastAccessDuration: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：accessRecords: Array\<UsedRecordDetail>;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：accessRecords: Array\<UsedRecordDetail>;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：PermissionUsedRecord;<br>方法or属性：rejectRecords: Array\<UsedRecordDetail>;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：rejectRecords: Array\<UsedRecordDetail>;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：UsedRecordDetail;<br>方法or属性：status: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：status: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：UsedRecordDetail;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：timestamp: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|访问级别有变化|类名：UsedRecordDetail;<br>方法or属性：accessDuration: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：accessDuration: number;<br>新版本信息：systemapi|@ohos.privacyManager.d.ts|
|权限有变化|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：grantUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：ohos.permission.GRANT_SENSITIVE_PERMISSIONS|@ohos.abilityAccessCtrl.d.ts|
|权限有变化|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：revokeUserGrantedPermission(<br>      tokenID: number,<br>      permissionName: Permissions,<br>      permissionFlags: number,<br>      callback: AsyncCallback\<void><br>    ): void;<br>新版本信息：ohos.permission.REVOKE_SENSITIVE_PERMISSIONS|@ohos.abilityAccessCtrl.d.ts|
|权限有变化|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function addPermissionUsedRecord(<br>    tokenID: number,<br>    permissionName: Permissions,<br>    successCount: number,<br>    failCount: number,<br>    callback: AsyncCallback\<void><br>  ): void;<br>新版本信息：ohos.permission.PERMISSION_USED_STATS|@ohos.privacyManager.d.ts|
|权限有变化|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function getPermissionUsedRecord(<br>    request: PermissionUsedRequest,<br>    callback: AsyncCallback\<PermissionUsedResponse><br>  ): void;<br>新版本信息：ohos.permission.PERMISSION_USED_STATS|@ohos.privacyManager.d.ts|
|权限有变化|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.PERMISSION_USED_STATS|@ohos.privacyManager.d.ts|
|权限有变化|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：privacyManager;<br>方法or属性：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.PERMISSION_USED_STATS|@ohos.privacyManager.d.ts|
|model有变化|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>新版本信息：StageModelOnly|@ohos.abilityAccessCtrl.d.ts|
|type有变化|类名：PermissionStateChangeInfo;<br>方法or属性：change: PermissionStateChangeType;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：change: PermissionStateChangeType;<br>新版本信息：PermissionStateChangeType|@ohos.abilityAccessCtrl.d.ts|
|type有变化|类名：PermissionStateChangeInfo;<br>方法or属性：tokenID: number;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：tokenID: number;<br>新版本信息：number|@ohos.abilityAccessCtrl.d.ts|
|type有变化|类名：PermissionStateChangeInfo;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：PermissionStateChangeInfo;<br>方法or属性：permissionName: Permissions;<br>新版本信息：Permissions|@ohos.abilityAccessCtrl.d.ts|
|type有变化|类名：ActiveChangeResponse;<br>方法or属性：tokenId: number;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：tokenId: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：BundleUsedRecord;<br>方法or属性：tokenId: number;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：tokenId: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：ActiveChangeResponse;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：permissionName: Permissions;<br>新版本信息：Permissions|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：permissionName: Permissions;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：permissionName: Permissions;<br>新版本信息：Permissions|@ohos.privacyManager.d.ts|
|type有变化|类名：ActiveChangeResponse;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：deviceId: string;<br>新版本信息：string|@ohos.privacyManager.d.ts|
|type有变化|类名：BundleUsedRecord;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：deviceId: string;<br>新版本信息：string|@ohos.privacyManager.d.ts|
|type有变化|类名：ActiveChangeResponse;<br>方法or属性：activeStatus: PermissionActiveStatus;<br>旧版本信息：|类名：ActiveChangeResponse;<br>方法or属性：activeStatus: PermissionActiveStatus;<br>新版本信息：PermissionActiveStatus|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|type有变化|类名：BundleUsedRecord;<br>方法or属性：isRemote: boolean;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：isRemote: boolean;<br>新版本信息：boolean|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;<br>新版本信息：?boolean|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;<br>新版本信息：?string|@ohos.privacyManager.d.ts|
|type有变化|类名：BundleUsedRecord;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：bundleName: string;<br>新版本信息：string|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;<br>新版本信息：?Array\<Permissions>|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedResponse;<br>方法or属性：beginTime: number;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：beginTime: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedResponse;<br>方法or属性：endTime: number;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：endTime: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;<br>新版本信息：?number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRequest;<br>方法or属性：flag: PermissionUsageFlag;<br>旧版本信息：|类名：PermissionUsedRequest;<br>方法or属性：flag: PermissionUsageFlag;<br>新版本信息：PermissionUsageFlag|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedResponse;<br>方法or属性：bundleRecords: Array\<BundleUsedRecord>;<br>旧版本信息：|类名：PermissionUsedResponse;<br>方法or属性：bundleRecords: Array\<BundleUsedRecord>;<br>新版本信息：Array\<BundleUsedRecord>|@ohos.privacyManager.d.ts|
|type有变化|类名：BundleUsedRecord;<br>方法or属性：permissionRecords: Array\<PermissionUsedRecord>;<br>旧版本信息：|类名：BundleUsedRecord;<br>方法or属性：permissionRecords: Array\<PermissionUsedRecord>;<br>新版本信息：Array\<PermissionUsedRecord>|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：accessCount: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：accessCount: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：rejectCount: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：rejectCount: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：lastAccessTime: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastAccessTime: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：lastRejectTime: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastRejectTime: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：lastAccessDuration: number;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：lastAccessDuration: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：accessRecords: Array\<UsedRecordDetail>;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：accessRecords: Array\<UsedRecordDetail>;<br>新版本信息：Array\<UsedRecordDetail>|@ohos.privacyManager.d.ts|
|type有变化|类名：PermissionUsedRecord;<br>方法or属性：rejectRecords: Array\<UsedRecordDetail>;<br>旧版本信息：|类名：PermissionUsedRecord;<br>方法or属性：rejectRecords: Array\<UsedRecordDetail>;<br>新版本信息：Array\<UsedRecordDetail>|@ohos.privacyManager.d.ts|
|type有变化|类名：UsedRecordDetail;<br>方法or属性：status: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：status: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：UsedRecordDetail;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：timestamp: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：UsedRecordDetail;<br>方法or属性：accessDuration: number;<br>旧版本信息：|类名：UsedRecordDetail;<br>方法or属性：accessDuration: number;<br>新版本信息：number|@ohos.privacyManager.d.ts|
|type有变化|类名：DataBlob;<br>方法or属性：data: Uint8Array;<br>旧版本信息：|类名：DataBlob;<br>方法or属性：data: Uint8Array;<br>新版本信息：Uint8Array|@ohos.security.cert.d.ts|
|type有变化|类名：DataArray;<br>方法or属性：data: Array\<Uint8Array>;<br>旧版本信息：|类名：DataArray;<br>方法or属性：data: Array\<Uint8Array>;<br>新版本信息：Array\<Uint8Array>|@ohos.security.cert.d.ts|
|type有变化|类名：DataBlob;<br>方法or属性：data: Uint8Array;<br>旧版本信息：|类名：DataBlob;<br>方法or属性：data: Uint8Array;<br>新版本信息：Uint8Array|@ohos.security.cryptoFramework.d.ts|
|type有变化|类名：CipherResponse;<br>方法or属性：text: string;<br>旧版本信息：|类名：CipherResponse;<br>方法or属性：text: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：text: string;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：text: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：text: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：text: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：action: string;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：action: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：action: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：action: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：key: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：key: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：key: string;<br>新版本信息：string|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：transformation?: string;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：transformation?: string;<br>新版本信息：?string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：transformation?: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：transformation?: string;<br>新版本信息：?string|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：success: (data: CipherResponse) => void;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：success: (data: CipherResponse) => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：success: (data: CipherResponse) => void;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：success: (data: CipherResponse) => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：fail: (data: string, code: number) => void;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：fail: (data: string, code: number) => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：fail: (data: string, code: number) => void;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：fail: (data: string, code: number) => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherRsaOptions;<br>方法or属性：complete: () => void;<br>旧版本信息：|类名：CipherRsaOptions;<br>方法or属性：complete: () => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：complete: () => void;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：complete: () => void;<br>新版本信息：function|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：iv?: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：iv?: string;<br>新版本信息：?string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：ivOffset?: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：ivOffset?: string;<br>新版本信息：?string|@system.cipher.d.ts|
|type有变化|类名：CipherAesOptions;<br>方法or属性：ivLen?: string;<br>旧版本信息：|类名：CipherAesOptions;<br>方法or属性：ivLen?: string;<br>新版本信息：?string|@system.cipher.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：tokenId: number;|类名：PermissionUsedRequest;<br>方法or属性：tokenId?: number;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：deviceId: string;|类名：PermissionUsedRequest;<br>方法or属性：deviceId?: string;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：isRemote: boolean;|类名：PermissionUsedRequest;<br>方法or属性：isRemote?: boolean;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：bundleName: string;|类名：PermissionUsedRequest;<br>方法or属性：bundleName?: string;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：permissionNames: Array\<Permissions>;|类名：PermissionUsedRequest;<br>方法or属性：permissionNames?: Array\<Permissions>;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：beginTime: number;|类名：PermissionUsedRequest;<br>方法or属性：beginTime?: number;|@ohos.privacyManager.d.ts|
|函数有变化|类名：PermissionUsedRequest;<br>方法or属性：endTime: number;|类名：PermissionUsedRequest;<br>方法or属性：endTime?: number;|@ohos.privacyManager.d.ts|
|跨平台能力有变化|类名：abilityAccessCtrl;<br>方法or属性：function createAtManager(): AtManager;<br>旧版本信息：|类名：abilityAccessCtrl;<br>方法or属性：function createAtManager(): AtManager;<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：AtManager;<br>方法or属性：checkAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：checkAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>;<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(<br>      context: Context,<br>      permissionList: Array\<Permissions>,<br>      requestCallback: AsyncCallback\<PermissionRequestResult><br>    ): void;<br>旧版本信息：|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(<br>      context: Context,<br>      permissionList: Array\<Permissions>,<br>      requestCallback: AsyncCallback\<PermissionRequestResult><br>    ): void;<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>旧版本信息：|类名：AtManager;<br>方法or属性：requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>;<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：GrantStatus;<br>方法or属性：export enum GrantStatus<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：export enum GrantStatus<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：GrantStatus;<br>方法or属性：PERMISSION_DENIED = -1<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：PERMISSION_DENIED = -1<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：GrantStatus;<br>方法or属性：PERMISSION_GRANTED = 0<br>旧版本信息：|类名：GrantStatus;<br>方法or属性：PERMISSION_GRANTED = 0<br>新版本信息：crossplatform|@ohos.abilityAccessCtrl.d.ts|
|跨平台能力有变化|类名：PermissionRequestResult;<br>方法or属性：export default class PermissionRequestResult<br>旧版本信息：|类名：PermissionRequestResult;<br>方法or属性：export default class PermissionRequestResult<br>新版本信息：crossplatform|PermissionRequestResult.d.ts|
|跨平台能力有变化|类名：PermissionRequestResult;<br>方法or属性：permissions: Array\<string>;<br>旧版本信息：|类名：PermissionRequestResult;<br>方法or属性：permissions: Array\<string>;<br>新版本信息：crossplatform|PermissionRequestResult.d.ts|
|跨平台能力有变化|类名：PermissionRequestResult;<br>方法or属性：authResults: Array\<number>;<br>旧版本信息：|类名：PermissionRequestResult;<br>方法or属性：authResults: Array\<number>;<br>新版本信息：crossplatform|PermissionRequestResult.d.ts|
