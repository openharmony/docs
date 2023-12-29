| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: sourcefile;<br>Method or attribute name: export type PermissionRequestResult = _PermissionRequestResult;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Class name: sourcefile;<br>Method or attribute name: export type Context = _Context;|@ohos.abilityAccessCtrl.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function isDLPFile(fd: number): Promise\<boolean>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function isDLPFile(fd: number, callback: AsyncCallback\<boolean>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPPermissionInfo(): Promise\<DLPPermissionInfo>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPPermissionInfo(callback: AsyncCallback\<DLPPermissionInfo>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getOriginalFileName(fileName: string): string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPSuffix(): string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function on(type: 'openDLPFile', listener: Callback\<AccessedDLPFileInfo>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function on(type: 'uninstallDLPSandbox', listener: Callback\<DLPSandboxState>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function off(type: 'openDLPFile', listener?: Callback\<AccessedDLPFileInfo>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function off(type: 'uninstallDLPSandbox', listener?: Callback\<DLPSandboxState>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function isInSandbox(): Promise\<boolean>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function isInSandbox(callback: AsyncCallback\<boolean>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPSupportedFileTypes(): Promise\<Array\<string>>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPSupportedFileTypes(callback: AsyncCallback\<Array\<string>>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function setRetentionState(docUris: Array\<string>): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function setRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function cancelRetentionState(docUris: Array\<string>): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function cancelRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getRetentionSandboxList(bundleName?: string): Promise\<Array\<RetentionSandboxInfo>>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getRetentionSandboxList(bundleName: string, callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getRetentionSandboxList(callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPFileAccessRecords(): Promise\<Array\<AccessedDLPFileInfo>>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPFileAccessRecords(callback: AsyncCallback\<Array\<AccessedDLPFileInfo>>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPGatheringPolicy(): Promise\<GatheringPolicyType>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function getDLPGatheringPolicy(callback: AsyncCallback\<GatheringPolicyType>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function installDLPSandbox(<br>    bundleName: string,<br>    access: DLPFileAccess,<br>    userId: number,<br>    uri: string<br>  ): Promise\<DLPSandboxInfo>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function installDLPSandbox(<br>    bundleName: string,<br>    access: DLPFileAccess,<br>    userId: number,<br>    uri: string,<br>    callback: AsyncCallback\<DLPSandboxInfo><br>  ): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function uninstallDLPSandbox(<br>    bundleName: string,<br>    userId: number,<br>    appIndex: number,<br>    callback: AsyncCallback\<void><br>  ): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise\<DLPFile>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function generateDLPFile(<br>    plaintextFd: number,<br>    ciphertextFd: number,<br>    property: DLPProperty,<br>    callback: AsyncCallback\<DLPFile><br>  ): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function openDLPFile(ciphertextFd: number): Promise\<DLPFile>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: dlpPermission;<br>Method or attribute name: function openDLPFile(ciphertextFd: number, callback: AsyncCallback\<DLPFile>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_VIEW = 0x00000001|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_SAVE = 0x00000002|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_SAVE_AS = 0x00000004|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_EDIT = 0x00000008|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_SCREEN_CAPTURE = 0x00000010|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_SCREEN_SHARE = 0x00000020|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_SCREEN_RECORD = 0x00000040|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_COPY = 0x00000080|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_PRINT = 0x00000100|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_EXPORT = 0x00000200|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: ActionFlagType;<br>Method or attribute name: ACTION_PERMISSION_CHANGE = 0x00000400|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFileAccess;<br>Method or attribute name: NO_PERMISSION = 0|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFileAccess;<br>Method or attribute name: READ_ONLY = 1|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFileAccess;<br>Method or attribute name: CONTENT_EDIT = 2|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFileAccess;<br>Method or attribute name: FULL_CONTROL = 3|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPPermissionInfo;<br>Method or attribute name: dlpFileAccess: DLPFileAccess;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AuthUser;<br>Method or attribute name: dlpFileAccess: DLPFileAccess;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPPermissionInfo;<br>Method or attribute name: flags: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AccessedDLPFileInfo;<br>Method or attribute name: uri: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AccessedDLPFileInfo;<br>Method or attribute name: lastOpenTime: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: RetentionSandboxInfo;<br>Method or attribute name: appIndex: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPSandboxInfo;<br>Method or attribute name: appIndex: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPSandboxState;<br>Method or attribute name: appIndex: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: RetentionSandboxInfo;<br>Method or attribute name: bundleName: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPSandboxState;<br>Method or attribute name: bundleName: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: RetentionSandboxInfo;<br>Method or attribute name: docUris: Array\<string>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: GatheringPolicyType;<br>Method or attribute name: GATHERING = 1|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: GatheringPolicyType;<br>Method or attribute name: NON_GATHERING = 2|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPSandboxInfo;<br>Method or attribute name: tokenID: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AccountType;<br>Method or attribute name: CLOUD_ACCOUNT = 1|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AccountType;<br>Method or attribute name: DOMAIN_ACCOUNT = 2|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AuthUser;<br>Method or attribute name: authAccount: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AuthUser;<br>Method or attribute name: authAccountType: AccountType;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AuthUser;<br>Method or attribute name: permExpiryTime: number;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: ownerAccount: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: ownerAccountID: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: ownerAccountType: AccountType;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: authUserList?: Array\<AuthUser>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: contactAccount: string;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: offlineAccess: boolean;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPProperty;<br>Method or attribute name: everyoneAccessList?: Array\<DLPFileAccess>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: dlpProperty: DLPProperty;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: addDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: addDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: stopFuseLink(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: stopFuseLink(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: resumeFuseLink(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: resumeFuseLink(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: replaceDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: deleteDLPLinkFile(linkFileName: string): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: recoverDLPFile(plaintextFd: number): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: recoverDLPFile(plaintextFd: number, callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: closeDLPFile(): Promise\<void>;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: DLPFile;<br>Method or attribute name: closeDLPFile(callback: AsyncCallback\<void>): void;|@ohos.dlpPermission.d.ts|
|Added|NA|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null, callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: AsyKeyGenerator;<br>Method or attribute name: convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null, callback: AsyncCallback\<void>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null): Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: doFinal(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Cipher;<br>Method or attribute name: doFinal(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Sign;<br>Method or attribute name: sign(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Sign;<br>Method or attribute name: sign(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Verify;<br>Method or attribute name: verify(data: DataBlob \| null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void;|@ohos.security.cryptoFramework.d.ts|
|Added|NA|Class name: Verify;<br>Method or attribute name: verify(data: DataBlob \| null, signatureData: DataBlob): Promise\<boolean>;|@ohos.security.cryptoFramework.d.ts|
