| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sourcefile;<br>方法or属性：export type PermissionRequestResult = _PermissionRequestResult;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：sourcefile;<br>方法or属性：export type Context = _Context;|@ohos.abilityAccessCtrl.d.ts|
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
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null, callback: AsyncCallback\<KeyPair>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：AsyKeyGenerator;<br>方法or属性：convertKey(pubKey: DataBlob \| null, priKey: DataBlob \| null): Promise\<KeyPair>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null, callback: AsyncCallback\<void>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：init(opMode: CryptoMode, key: Key, params: ParamsSpec \| null): Promise\<void>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Cipher;<br>方法or属性：doFinal(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data: DataBlob \| null, callback: AsyncCallback\<DataBlob>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Sign;<br>方法or属性：sign(data: DataBlob \| null): Promise\<DataBlob>;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data: DataBlob \| null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void;|@ohos.security.cryptoFramework.d.ts|
|新增|NA|类名：Verify;<br>方法or属性：verify(data: DataBlob \| null, signatureData: DataBlob): Promise\<boolean>;|@ohos.security.cryptoFramework.d.ts|
