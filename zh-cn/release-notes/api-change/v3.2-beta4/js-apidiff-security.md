| 操作 | 新版本 | 旧版本 | d.ts文件 | 所属子系统 |
| ---- | ------ | ------ | -------- | ---------- |
|新增||模块名：ohos.abilityAccessCtrl<br>类名:AtManager<br>方法名 or 属性名:verifyAccessToken|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：verifyAccessTokenSync<br>函数：verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||模块名：ohos.abilityAccessCtrl<br>类名:AtManager<br>方法名 or 属性名:checkAccessToken|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：grantUserGrantedPermission<br>函数：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;<br>grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：revokeUserGrantedPermission<br>函数：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;<br>revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：getPermissionFlags<br>函数：getPermissionFlags(tokenID: number, permissionName: Permissions): Promise<number>;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：on_permissionStateChange<br>函数：on(type: 'permissionStateChange', tokenIDList: Array<number>, permissionNameList: Array<Permissions>, callback: Callback<PermissionStateChangeInfo>): void;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：off_permissionStateChange<br>函数：off(type: 'permissionStateChange', tokenIDList: Array<number>, permissionNameList: Array<Permissions>, callback?: Callback<PermissionStateChangeInfo>): void;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：permissionName<br>函数：permissionName: Permissions;|@ohos.abilityAccessCtrl.d.ts|安全基础能力|
|新增||方法名 or 属性名：addPermissionUsedRecord<br>函数：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise<void>;<br>function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：startUsingPermission<br>函数：function startUsingPermission(tokenID: number, permissionName: Permissions): Promise<void>;<br>function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：stopUsingPermission<br>函数：function stopUsingPermission(tokenID: number, permissionName: Permissions): Promise<void>;<br>function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：on_activeStateChange<br>函数：function on(type: 'activeStateChange', permissionNameList: Array<Permissions>, callback: Callback<ActiveChangeResponse>): void;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：off_activeStateChange<br>函数：function off(type: 'activeStateChange', permissionNameList: Array<Permissions>, callback?: Callback<ActiveChangeResponse>): void;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：permissionName<br>函数：permissionName: Permissions;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：permissionNames<br>函数：permissionNames: Array<Permissions>;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||方法名 or 属性名：permissionName<br>函数：permissionName: Permissions;|@ohos.privacyManager.d.ts|安全基础能力|
|新增||模块名：ohos.security.cryptoFramework<br>类名:Result<br>方法名 or 属性名:ERR_RUNTIME_ERROR|@ohos.security.cryptoFramework.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:generateKey|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:generateKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:deleteKey|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:deleteKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importKey|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importWrappedKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:exportKey|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:exportKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:getKeyProperties|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:getKeyItemProperties|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:isKeyExist|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:isKeyItemExist|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:init|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:initSession|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:update|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:updateSession|@ohos.security.huks.d.ts|安全基础能力|
|新增||方法名 or 属性名：finish<br>函数：function finish(handle: number, options: HuksOptions, callback: AsyncCallback<HuksResult>) : void;<br>function finish(handle: number, options: HuksOptions) : Promise<HuksResult>;|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:finishSession|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:abort|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:abortSession|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:attestKeyItem|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksHandle|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksHandle<br>方法名 or 属性名:errorCode|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksHandle<br>方法名 or 属性名:handle|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksHandle<br>方法名 or 属性名:token|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksSessionHandle|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksSessionHandle<br>方法名 or 属性名：handle|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksSessionHandle<br>方法名 or 属性名：challenge|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksResult|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksResult<br>方法名 or 属性名:errorCode|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksResult<br>方法名 or 属性名:outData|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksResult<br>方法名 or 属性名:properties|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksResult<br>方法名 or 属性名:certChains|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksReturnResult|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：outData|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：properties|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksReturnResult<br>方法名 or 属性名：certChains|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_SUCCESS|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_FAILURE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_BAD_STATE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_ARGUMENT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_NOT_SUPPORTED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_NO_PERMISSION|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INSUFFICIENT_DATA|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_BUFFER_TOO_SMALL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INSUFFICIENT_MEMORY|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_COMMUNICATION_FAILURE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_STORAGE_FAILURE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_HARDWARE_FAILURE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_ALREADY_EXISTS|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_NOT_EXIST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_NULL_POINTER|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_FILE_SIZE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_READ_FILE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_PUBLIC_KEY|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_PRIVATE_KEY|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_KEY_INFO|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_HASH_NOT_EQUAL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_MALLOC_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_WRITE_FILE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_REMOVE_FILE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_OPEN_FILE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CLOSE_FILE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_MAKE_DIR_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_KEY_FILE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_IPC_MSG_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_REQUEST_OVERFLOWS|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_PARAM_NOT_EXIST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CRYPTO_ENGINE_ERROR|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_COMMUNICATION_TIMEOUT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_IPC_INIT_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_IPC_DLOPEN_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_EFUSE_READ_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_VERIFICATION_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_GET_USERIAM_SECINFO_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_GET_USERIAM_AUTHINFO_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_USER_AUTH_TYPE_NOT_SUPPORT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_KEY_AUTH_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_DEVICE_NO_CREDENTIAL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_ALG_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_PADDING_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_PURPOSE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_DIGEST_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_MODE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_NONCE_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_AAD_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_IV_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_AE_TAG_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_SALT_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_CHECK_GET_ITERATION_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_ALGORITHM|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_KEY_SIZE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_PADDING|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_PURPOSE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_MODE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_DIGEST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_SIGNATURE_SIZE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_IV|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_AAD|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_NONCE|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_AE_TAG|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_SALT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_ITERATION|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_OPERATION|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_WRAPPED_FORMAT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INVALID_USAGE_OF_KEY|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_INTERNAL_ERROR|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：ohos.security.huks<br>类名:HuksErrorCode<br>方法名 or 属性名:HUKS_ERROR_UNKNOWN_ERROR|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_PERMISSION_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_ILLEGAL_ARGUMENT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_NOT_SUPPORTED_API|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_FILE_OPERATION_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_COMMUNICATION_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CRYPTO_FAIL|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_KEY_AUTH_TIME_OUT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_SESSION_LIMIT|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_ITEM_NOT_EXIST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_EXTERNAL_ERROR|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_INSUFFICIENT_MEMORY|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名: ohos.security.huks<br>类名: HuksExceptionErrCode<br>方法名 or 属性名：HUKS_ERR_CODE_CALL_SERVICE_FAILED|@ohos.security.huks.d.ts|安全基础能力|
|新增||模块名：system.cipher<br>类名:Cipher|@system.cipher.d.ts|安全基础能力|
|新增||模块名：system.cipher<br>类名:Cipher<br>方法名 or 属性名:rsa|@system.cipher.d.ts|安全基础能力|
|新增||模块名：system.cipher<br>类名:Cipher<br>方法名 or 属性名:aes|@system.cipher.d.ts|安全基础能力|
|删除|模块名：ohos.security.cryptoFramework<br>类名:Result<br>方法名 or 属性名:ERR_EXTERNAL_ERROR||@ohos.security.cryptoFramework.d.ts|安全基础能力|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:importWrappedKey||@ohos.security.huks.d.ts|安全基础能力|
|删除|模块名：ohos.security.huks<br>类名:huks<br>方法名 or 属性名:attestKey||@ohos.security.huks.d.ts|安全基础能力|
|废弃版本有变化|方法名 or 属性名：finish<br>废弃版本：|方法名 or 属性名：finish<br><br>废弃版本：9<br>代替接口ohos.security.huks.finishSession     |@ohos.security.huks.d.ts|安全基础能力|
