| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|方法名 or 属性名：grantUserGrantedPermission<br>函数：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：grantUserGrantedPermission<br>函数：grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：revokeUserGrantedPermission<br>函数：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise<void>;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：revokeUserGrantedPermission<br>函数：revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback<void>): void;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：permissionName<br>函数：permissionName: Permissions;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|方法名 or 属性名：addPermissionUsedRecord<br>函数：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise<void>;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：addPermissionUsedRecord<br>函数：function addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：startUsingPermission<br>函数：function startUsingPermission(tokenID: number, permissionName: Permissions): Promise<void>;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：startUsingPermission<br>函数：function startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：stopUsingPermission<br>函数：function stopUsingPermission(tokenID: number, permissionName: Permissions): Promise<void>;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：stopUsingPermission<br>函数：function stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback<void>): void;|@ohos.privacyManager.d.ts|
|新增|NA|方法名 or 属性名：permissionNames<br>函数：permissionNames: Array<Permissions>;|@ohos.privacyManager.d.ts|
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
|删除|模块名：ohos.security.cryptoFramework<br>类名:Result<br>方法名 or 属性名:ERR_EXTERNAL_ERROR|NA|@ohos.security.cryptoFramework.d.ts|
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
|起始版本有变化|方法名 or 属性名：getPermissionFlags<br>起始版本：9|方法名 or 属性名：getPermissionFlags<br>起始版本：8|@ohos.abilityAccessCtrl.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|起始版本有变化|方法名 or 属性名：update<br>起始版本：9|方法名 or 属性名：update<br>起始版本：8|@ohos.security.huks.d.ts|
|新增(错误码)|NA|方法名 or 属性名：verifyAccessTokenSync<br>错误码内容:401,12100001|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|NA|方法名 or 属性名：getPermissionFlags<br>错误码内容:401,201,12100001,12100002,12100003,12100006,12100007|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|NA|方法名 or 属性名：on_permissionStateChange<br>错误码内容:401,201,12100001,12100004,12100005,12100007,12100008|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|NA|方法名 or 属性名：off_permissionStateChange<br>错误码内容:401,201,12100001,12100004,12100007,12100008|@ohos.abilityAccessCtrl.d.ts|
|新增(错误码)|NA|方法名 or 属性名：getPermissionUsedRecords<br>错误码内容:401,201,12100001,12100002,12100003,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|NA|方法名 or 属性名：on_activeStateChange<br>错误码内容:401,201,12100001,12100004,12100005,12100007,12100008|@ohos.privacyManager.d.ts|
|新增(错误码)|NA|方法名 or 属性名：off_activeStateChange<br>错误码内容:401,201,12100001,12100004,12100007,12100008|@ohos.privacyManager.d.ts|
