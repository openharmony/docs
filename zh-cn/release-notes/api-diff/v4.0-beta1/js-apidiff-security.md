| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：AtManager<br>方法or属性：checkAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus;|@ohos.abilityAccessCtrl.d.ts|
|新增|NA|类名：HuksKeyStorageType<br>方法or属性：HUKS_STORAGE_ONLY_USED_IN_HUKS = 2|@ohos.security.huks.d.ts|
|新增|NA|类名：HuksKeyStorageType<br>方法or属性：HUKS_STORAGE_KEY_EXPORT_ALLOWED = 3|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksRsaPssSaltLenType|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksRsaPssSaltLenType<br>方法 or 属性：HUKS_RSA_PSS_SALT_LEN_DIGEST = 0|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksRsaPssSaltLenType<br>方法 or 属性：HUKS_RSA_PSS_SALT_LEN_MAX = 1|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksTag<br>方法 or 属性：HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 29|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksTag<br>方法 or 属性：HUKS_TAG_RSA_PSS_SALT_LEN_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 30|@ohos.security.huks.d.ts|
|新增|NA|模块名: ohos.security.huks<br>类名: HuksTag<br>方法 or 属性：HUKS_TAG_KEY_AUTH_PURPOSE = HuksTagType.HUKS_TAG_TYPE_UINT \| 311|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksKeyStorageType<br>方法 or 属性：HUKS_STORAGE_TEMP = 0<br>废弃版本：N/A|类名：HuksKeyStorageType<br>方法 or 属性：HUKS_STORAGE_TEMP = 0<br>废弃版本：10<br>代替接口：N/A|@ohos.security.huks.d.ts|
|废弃版本有变化|类名：HuksKeyStorageType<br>方法 or 属性：HUKS_STORAGE_PERSISTENT = 1<br>废弃版本：N/A|类名：HuksKeyStorageType<br>方法 or 属性：HUKS_STORAGE_PERSISTENT = 1<br>废弃版本：10<br>代替接口：N/A|@ohos.security.huks.d.ts|
|新增(错误码)|NA|类名：AtManager<br>方法 or 属性：getVersion(): Promise\<number>;<br>错误码内容: 202|@ohos.abilityAccessCtrl.d.ts|
